#include"Power_Modes.h"

// Shutdown
volatile uint32_t SDV_CNT;
volatile uint32_t SDM_CNT;
volatile uint8_t SDM_CMD_CNT;
volatile uint32_t timeshutdown_timer = 0;
uint16_t ship_timer = 0;
volatile uint8_t timebaseflag = 0;
void Power_Modes_Fun()
{
    SleepMode_Check(); // judge normal mode or sleep mode
    ship_mode();       // ship mode
    ShutdownMode();
	SmbusTimeout_Chk(); 
	if (UF_BackupREG & 0x1)
	{
		DeepSleep_Enter();
	}
}
void DeepSleep_Enter(void)
{
	
	if (!DFUpdate.FLAG && write_flag != 1)
	{
		//printf("DeepSleep_Enter!\n");
		NVIC->ISER[0] = 0x800;
		__EXTI_INTR_ENABLE(EXTI_LINE_11);

		pmu_deep_sleep_mode_enter(PMU_LDO_LOW_POWER, PMU_DSM_ENTRY_WFI);
	}
}
uint8_t shutdown_enter(void)
{
	uint8_t ret;

	// printf("enter shutdown mode!\r\npackv = %d\n",PackVoltage());
	UF_BackupREG = 0xFFFFFFFD;
	afe_cddrv_charge_enable_ctrl(0);
	afe_cddrv_discharge_enable_ctrl(0);
	Write_UpFlash();
	DFDataSave();
    DF_Write();
	delay_ms(1000);
	// shutdown_enter();
	__disable_irq();	// 关总中断
						// if (UF_BackupREG != 0xFFFFFFFD)
						// {
						// 	UF_BackupREG = 0xFFFFFFFE;
						// 	Write_UpFlash();
						// 	Soft_Reset();
						// }
						// else
						// {
	__RCU_FLAG_CLEAR(); // 清除RCU所有的复位标志

	if (1 == afe_enter_shutdown()) // afe进shutdown
	{
		pmu_power_down_enter(); // MCU配置为掉电模式
	}
	else
	{
		// logInfo("afe_enter_shutdown fail, Vpack is connect charger!\r\n");
		UF_BackupREG = 0xFFFFFFFF;
		Write_UpFlash();
		f_sdm = OFF;
	}
	//}
	__enable_irq(); // 开总中断
	// #endif
	return 1;
}

uint8_t get_i2c_pin_status(void)
{
    uint8_t scl = __GPIO_INPUT_PIN_GET(GPIOA, GPIO_PIN_10);
    uint8_t sda = __GPIO_INPUT_PIN_GET(GPIOA, GPIO_PIN_11);
    uint8_t ret = scl + (sda<<1); 
    return ret;
}
void SleepMode_Check(void)
{
	volatile uint16_t status = 0;

	uint8_t f_high_smbus = get_i2c_pin_status();
//	printf("f_high_smbus = %d\n\r",f_high_smbus);
	if(f_high_smbus)
	{
		f_lowBus_timout = OFF;
		lowBus_cnt = 0;
	}

	// Condition to exit Sleep Mode
	DEF_BIT0(&status) = !!(_PFAlert.value & 0xFFFFFC7F);//PF Alert
	DEF_BIT1(&status) = !!(_SafetyAlert.value & 0xFF83FFFF);//Safety Alert
	DEF_BIT2(&status) = !!_PFStatus.value;//PF status
	DEF_BIT3(&status) = !!(_SafetyStatus.value & 0x00000FC0);// Safety Status
	DEF_BIT4(&status) = f_sdm;
	DEF_BIT5(&status) = (D_DA_Configuration_NR == 0) && f_pres && (D_DA_Configuration_IN_SYSTEM_SLEEP == 0);	// IN SYSTEM SLEEP MODE
	DEF_BIT6(&status) = (D_Sleep_Voltage_Time == 0);
	DEF_BIT7(&status) = I_abs > D_Sleep_Current;

	if (f_sleep)
	{
		WakeUp_Ctrl(ENABLE);
		lptim_timer_reload(SleepPeriod);

		if (f_sleepm)
		{
			if (((D_DA_Configuration_NR == 0) && f_pres) || (I_abs > D_Sleep_Current) || f_wakeup_int || _SafetyAlert.value || _PFAlert.value)
			{
				f_sleepm = OFF;
				f_sleep = OFF;
				//printf("Instruction Exit Sleep Mode!\n");
			}
		}
		else if (D_DA_Configuration_SLEEP)
		{
			if (status																									 /***/
				|| (!f_no_smbus && ((D_DA_Configuration_IN_SYSTEM_SLEEP /*&& (D_Sleep_Bus_TimeOut == 0)*/))) /***(4)***/
				|| (f_high_smbus && (D_DA_Configuration_IN_SYSTEM_SLEEP == 0))											 /***/
				|| f_wakeup_int)																						 /***(5)***/
			{
				f_sleep = OFF;
				
			}
		}
	}
	else
	{

		if (f_relax)
		{
			lptim_timer_reload(1000);
		}
		else
		{
		lptim_timer_reload(NormalPeriod);
		}
		f_sleepPCFET = ON;
		f_sleepCFET = ON;
		f_sleepDFET = ON;

		if (f_sleepm) // 指令进入Sleep
		{
			if (D_DA_Configuration_NR)
			{
				if (I_abs <= D_Sleep_Current)
				{
					f_sleepPCFET = OFF;
					if (D_FETOptions_SLEEPCHG == OFF)
					{
						f_sleepCFET = OFF;
					}
					f_sleep = ON;
					//printf("Instruction Enter Sleep Mode!\n");
				}
			}
			else
			{
				if ((f_pres == 0) && I_abs <= D_Sleep_Current)
				{
					f_sleepPCFET = OFF;
					f_sleepCFET = OFF;
					f_sleepDFET = OFF;
				}
				f_sleep = ON;
				//printf("Instruction Enter Sleep Mode non-remove pack!\n");
			}
		}
		else if (D_DA_Configuration_SLEEP)
		{
			if (!status)
			{
				if (D_DA_Configuration_IN_SYSTEM_SLEEP)
				{
					if (f_no_smbus) /***(1)***/
					{
						if (D_FETOptions_SLEEPCHG == 0) // Activate Action
						{
							f_sleepPCFET = OFF;
							f_sleepCFET = OFF;
						}
						f_sleep = ON;
						//printf("Enter Sleep Mode IN SYSTEM SLEEP!\n");
					}
				}
				else
				{
					if (f_lowBus_timout) /***(1)***/
					{
						if (D_FETOptions_SLEEPCHG == 0) // Activate Action
						{
							f_sleepPCFET = OFF;
							f_sleepCFET = OFF;
						}
						f_sleep = ON;
						//printf("Enter Sleep Mode Not IN SYSTEM SLEEP!\n");
						//					rtc_time_show();
					}
				}
			}
		}
	}

	if (f_curr_en)
	{
		f_curr_en = OFF;
		if (!(D_Manufacturing_Status_Init_LDO_EN && D_DA_Configuration_NR))
		{
			PresInit();
		}
		Enable_CVT();
		if(f_sleep)
		{
			f_slpad = ON;
			f_slpcc = ON;
		}
		else
		{
			f_slpad = OFF;
			f_slpcc = OFF;
		}
	}
}

void ship_mode(void)
{
	if (D_Power_Config_SHIP_MODE_EN)
	{
		if (f_sleep)
		{
			if (f_relax && t_com0d < D_Ship_FET_Off_Min_RSOC)
			{
				if (!f_ship)
				{
					f_count_toship = ON;
					if (ship_timer >= D_Ship_FET_Off_Storage_Time)
					{
						ship_timer = 0;
						f_count_toship = OFF;
						f_ship = ON;
						_EntryShipModeCount++;
						_EntryExitShipCondition = _EntryExitShipCondition & 0xFF + (0x02 << 8);
						_FETCtrl = 0x0100;
						//("Enter Ship Mode RSOC!\n");
					}
				}
			}
			else
			{
				f_count_toship = OFF;
				ship_timer = 0;
			}

			if (!BatteryStatus(FC))
			{
				if (f_enterShip == ON) //
				{
					f_enterShip = OFF;
					f_ship = ON;
					_EntryShipModeCount += (1 << 8);
					_EntryExitShipCondition = _EntryExitShipCondition & 0xFF + (0x01 << 8);
					_FETCtrl = 0x0100;
					//printf("Enter Ship Mode CMD\n");
				}
			}
		}

		if (f_ExitShip) // command to exit ship mode
		{
			if (f_ship)
			{
				f_ExitShip = OFF;
				f_ship = OFF;
				_FETCtrl = 0x0000;
				_EntryExitShipCondition = _EntryExitShipCondition & 0xFF00 + 0x01;
				//printf("Exit Ship Mode CMD\n");
			}
		}

		if (D_Power_Config_MFC_CLR_CMD) // Communication exits ship mode
		{
			if (f_ship && !f_no_smbus)
			{
				_FETCtrl = 0x0000;
				_EntryExitShipCondition = _EntryExitShipCondition & 0xFF00 + 0x04;
				f_ship = OFF;
				f_enterShip = OFF; // Data is wrong
				f_ReadyShip = OFF;
				f_enterShipTo = OFF;
				f_ExitShipTo = OFF;
				f_ExitShip = OFF; // Data is wrong
				f_ReadyExitShip = OFF;
				//printf("Exit Ship Mode MFC\n");
			}
		}
	}

	if (!f_ship && !f_ReadyShip && !f_ReadyExitShip)
	{
		_FETCtrl = 0x0000;
	}
}

void Instruct_EntryExit_Ship(void)
{
	switch (_FETCtrl)
	{
	case 0x0000:
	{
		f_ReadyShip = ON;
		f_ReadyExitShip = OFF;
		//printf("0x0000 Receive!\n");
		break;
	}
	case 0x1000:
	{
		//printf("0x1000 Receive!\n");
		if (f_ReadyShip)
		{
			f_ReadyShip = OFF;
			if (!f_enterShipTo)
			{
				f_enterShip = ON; // into ship mode function flag
			}
		}
		break;
	}
	case 0x2000:
	{
		f_ReadyExitShip = ON;
		f_ReadyShip = OFF;
		break;
	}
	case 0x4000:
	{
		if (f_ReadyExitShip)
		{
			f_ReadyExitShip = OFF;
			if (!f_ExitShipTo)
			{
				f_ExitShip = ON;
			}
		}
		break;
	}

	default:
	{
		f_ReadyShip = OFF;
		f_ReadyExitShip = OFF;
		break;
	}
	}
	// if (f_ReadyShip == ON) // Comment into ship mode flag = ON ?
	// {
	// 	f_ReadyShip = OFF;
	// 	if (_FETCtrl == 0x1000 && !f_enterShipTo) // Data is correct ?
	// 	{
	// 		f_fcShip = ON;	  //	into ship
	// 		f_enterShip = ON; // into ship mode function flag
	// 	}
	// 	else
	// 	{
	// 		f_enterShipTo = OFF;
	// 		f_enterShip = OFF; // Data is wrong
	// 	}
	// }
	// else
	// {
	// 	if (_FETCtrl == 0x0000) // ship mode req command ?
	// 	{
	// 		f_ReadyShip = ON; // into ship mode flag
	// 	}
	// }
	// if (f_ReadyExitShip == ON) // Comment into ship mode flag = ON ?
	// {
	// 	f_ReadyExitShip = OFF;
	// 	if (_FETCtrl == 0x4000 && !f_ExitShipTo) // Data is correct ?
	// 	{
	// 		f_ExitShip = ON; // into ship mode function flag
	// 	}
	// 	else
	// 	{
	// 		f_ExitShipTo = OFF;
	// 		f_ExitShip = OFF;	   // Data is wrong
	// 	}
	// }
	// else
	// {						   // into ship mode flag = OFF
	// 	if (_FETCtrl == 0x2000) // ship mode req. command ?
	// 	{
	// 		f_ReadyExitShip = ON; // into ship mode flag
	// 	}
	// }
}

void EntryExitShip_TimeOutChk(void)
{
	static uint16_t enter_timout = 0;
	static uint16_t exit_timout = 0;
	if (f_ReadyShip) // Receive the instruction to enter ship
	{
		if (!f_enterShipTo)
		{
			enter_timout += Periodtime;
			//printf("Ship Cnt = %d\n",enter_timout);
			if (enter_timout >= 5000) // 5s timeout between two instructions
			{
				enter_timout = 0;
				f_enterShipTo = ON;
			}
		}
	}
	else
	{
		f_enterShipTo = OFF;
		enter_timout = 0;
	}

	if (f_ReadyExitShip) // Receive the instruction to exit ship
	{
		if (!f_ExitShipTo)
		{
			exit_timout += Periodtime;
			if (exit_timout >= 5000) // 5s timeout between two instructions
			{
				exit_timout = 0;
				f_ExitShipTo = ON;
			}
		}
	}
	else
	{
		f_ExitShipTo = OFF;
		exit_timout = 0;
	}

	if (f_count_toship)
	{

		ship_timer += Periodtime / 250;
	}
	else
	{
		ship_timer = 0;
	}
}

void InstructShip_invalid(uint8_t shipcmd)
{
	if (f_ReadyShip == ON || f_ReadyExitShip == ON)
	{
		if (shipcmd != 0x34)
		{
			f_enterShip = OFF; // Data is wrong
			f_ReadyShip = OFF;
			f_enterShipTo = OFF;
			f_ExitShipTo = OFF;
			f_ExitShip = OFF; // Data is wrong
			f_ReadyExitShip = OFF;
		}
	}
}

static void VoltageShutdownMode(void) // VOLTAGE BASED SHUTDOWN
{
	if (V_min < (D_Shutdown_Voltage-Temp_Change) && f_gs_dsg)
	{
		f_sdv = ON;
		if (f_sdvDFET)
		{
			
			if (SDV_CNT / 1000 >= D_Shutdown_Time)
			{
				SDV_CNT = 0;
				f_sdvDFET = OFF;
			}
		}
		else
		{
			if (PackVoltage() < D_Shutdown_Charger_Present_Threshold)
			{
				
				f_sdv = OFF;
				shutdown_enter();
			}
		}
	}
	else
	{
		f_sdv = OFF;
		f_sdvDFET = ON;
		SDV_CNT = 0;
	}
}

static void ManufMACShutdown(void) // ManufacturerAccess() MAC Shutdown
{
	if (f_ShutDown)
	{
		f_ShutDown = OFF;
		SDM_CMD_CNT++;
	}

	if (f_us || f_fas)
	{
		if (SDM_CMD_CNT >= 2)
		{
			// afe_cddrv_charge_enable_ctrl(0);
			// afe_cddrv_discharge_enable_ctrl(0);
			// // f_sdmCFET = OFF;
			// // f_sdmDFET = OFF;
			// // if (PackVoltage() < D_Shutdown_Charger_Present_Threshold)
			// // {
			// // 	shutdown_enter();
			// // }
			// delay_ms(1000);
			f_sdm = OFF;
			shutdown_enter();
		}
		else if (SDM_CMD_CNT == 1)
		{
			f_sdm = ON;
		}
	}
	else
	{
		if (SDM_CMD_CNT >= 2)
		{
			f_sdm = ON;
		}
	}

	if (f_sdm)
	{
		if (SDM_CNT / 1000 >= D_Shutdown_MAC_FET_Off_Time)
		{
			f_sdmCFET = OFF;
			f_sdmDFET = OFF;
		}
		if (SDM_CNT / 1000 >= D_Shutdown_MAC_Shutdown_Delay)
		{
			if (PackVoltage() < D_Shutdown_Charger_Present_Threshold)
			{
				f_sdm = OFF;
				shutdown_enter();
			}
		}
	}
}

static void TimeBasedShutdown(void) // Time-Based Shutdown
{
	if (D_Power_Config_AUTO_SHIP_EN && f_sleep && f_no_smbus)
	{
		// if (getSoftTimerStatus(SOFT_TIMER_TM_SHUTDOWN_ID) == 0)
		// {
		// 	StartSoftTimer(SOFT_TIMER_TM_SHUTDOWN_ID, SINGLE_MODE, D_Shutdown_Auto_Ship_time * 60 * 1000, shutdown_enter);
		// }
		timebaseflag = 1;
		if(timeshutdown_timer >= D_Shutdown_Auto_Ship_time * 60 * 1000)
		{
			timeshutdown_timer = 0;
			//printf("timebase shutdown!\n");
			// afe_cddrv_charge_enable_ctrl(0);
			// afe_cddrv_discharge_enable_ctrl(0);
			// delay_ms(1000);
			shutdown_enter();
		}
	}
	else
	{
		timeshutdown_timer = 0;
		timebaseflag = 0;
		// StopSoftTimer(SOFT_TIMER_TM_SHUTDOWN_ID);
	}
}

static void PowerSaveShutdown(void) // 5.4.4 Power Save Shutdown
{
	// if (D_Power_Config_PWR_SAVE_VSHUT && V_min < D_Shutdown_Voltage)
	// {
	// 	f_psshut = ON;
	// }
}

static void IOBasedShutdown(void) // 5.4.5 IO Based Shutdown
{
}

void ShutdownMode(void)
{
	VoltageShutdownMode();
	ManufMACShutdown();
	TimeBasedShutdown();
	PowerSaveShutdown();
	// IOBasedShutdown();
}