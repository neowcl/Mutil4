#include "mcu.h"

volatile uint8_t Fet_Ctrl = 0xFF; // FET setting
volatile uint8_t task_init;

void Set_FET(void)
{
	// uint8_t status;
	static uint8_t last_status = 0;
	if (last_status != Fet_Ctrl)
	{
		last_status = Fet_Ctrl;
		if (f_PCFET != f_pchg)
		{
			// f_pchg = f_PCFET;
		}
		if (f_CFET != f_chg)
		{
			f_chg = f_CFET;
		}
		if (f_DFET != f_dsg)
		{
			f_dsg = f_DFET;
		}
		f_xchg = !f_chg;
		f_xdsg = !f_dsg;
		// afe_cddrv_precharge_enable_ctrl(f_pchg);
		afe_cddrv_charge_enable_ctrl(f_chg);
		afe_cddrv_discharge_enable_ctrl(f_dsg);
		//printf("CMOS = %d , DMOS = %d\n",f_chg,f_dsg);
		
	}
	// afe_cddrv_charge_enable_status_get(&status);
	// if(!!status != f_chg)
	// {
	// 	afe_cddrv_charge_enable_ctrl(f_chg);
	// }
	// afe_cddrv_discharge_enable_status_get(&status);
	// if(!!status != f_dsg)
	// {
	// 	afe_cddrv_charge_enable_ctrl(f_dsg);
	// }
	  Fet_Ctrl = 0xFF;
}

void mcu_gpio_config(void)
{
	nvic_config_t nvic_config_struct;
	__RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);    /* Clock Config. */
    gpio_mode_set(GPIOA, GPIO_PIN_8 | GPIO_PIN_9, GPIO_MODE_ANALOG);

	
	// gpio_mode_set(GPIOA, GPIO_PIN_5, GPIO_MODE_IN_PD);
	// /* Connect EXTI13 Line to PA13 pin. */
    // syscfg_exti_line_config(SYSCFG_EXTI_PORT_PA, SYSCFG_EXTI_PIN_5); 
    // /* Configure EXTI13 line. */
    // __EXTI_INTR_ENABLE(EXTI_LINE_5);
    // __EXTI_EDGE_ENABLE(EXTI_EDGE_FALLING, EXTI_LINE_5);

    // /* Enable and set EXTI4_15 interrupt. */
    // nvic_config_struct.IRQn = IRQn_EXTI4_15;
    // nvic_config_struct.priority = 0x02;
    // nvic_config_struct.enable_flag = ENABLE;
    // nvic_init(&nvic_config_struct);

	//if(UF_BackupREG & 0x1)
	if(0)
	{
	 	gpio_mode_set(GPIOA, GPIO_PIN_0 | GPIO_PIN_1, GPIO_MODE_ANALOG);
	}
	else
	{
		gpio_mode_set(GPIOA, GPIO_PIN_0 | GPIO_PIN_1, GPIO_MODE_MF_PP(GPIO_SPEED_MEDIUM)); // for swd debug，will increase power consume
	}

    gpio_mode_set(GPIOA, GPIO_PIN_2|GPIO_PIN_3, GPIO_MODE_ANALOG);
}

void Afe_Init()
{
	__enable_irq();
	delay_ms(2000);
	__disable_irq();

    mcu_gpio_config();
    CVT_Init();
	afe_pmu_pack_pull_down_enable_ctrl(DISABLE); // 关闭pack下拉
	afe_int_periph_int_enable_ctrl(INT_IE1_PACKH2P25V_INT, ENABLE);
	afe_pmu_shutdown_dds_config(PMU_PMUDDS_DELAY_210US);//afe进掉电模式的延时，默认最大 
	afe_pmu_sw_awaken_enable_ctrl(ENABLE); // sw
    WakeCp_init(); // discurrent Wackup init
	Mos_init();
    Hdp_Init();

	if (D_Manufacturing_Status_Init_LDO_EN && D_DA_Configuration_NR)
	{
		PresInit();
	}
	FUSE_Init();
	task_init = 1;
    __enable_irq();
}


/* 检查复位源 */
void FWDT_init(void)
{
    //logInfo("check reset source\n");
	//Read_UpFlash();
	UF_FLAG = OFF;

    // /* 检查rtc备份寄存器 */
    // uint32_t value_r = __RTC_AO_REGISTER_READ(RTC_AO_REGISTER0);
    // logInfo("value_r = %#X\n", value_r);
    /* 检查复位源 */
	//printf("BackupREG = %#x\n",UF_BackupREG);
	switch (UF_BackupREG)
	{
	// case 0xFFFFFFFC:
	// {
	// 	break;
	// }
	case 0xFFFFFFFD:
	{
		UF_BackupREG = 0xFFFFFFFF;
		MCU_FWDG_init();
		Write_UpFlash();
		shutdown_wake_flag = 1;
		LifeTimes_No_of_Shutdowns++;
		break;
		
	}
	// case 0xFFFFFFFE:
	// {
	// 	//logInfo("1111");
	// 	UF_BackupREG = 0xFFFFFFFD;
	// 	afe_cddrv_charge_enable_ctrl(0);
	// 	afe_cddrv_discharge_enable_ctrl(0);
	// 	Write_UpFlash();
	// 	delay_ms(1000);
	// 	shutdown_enter();
		
	// 	break;
	// }
	case 0xFFFFFFFF:
	{
		MCU_FWDG_init();
		break;
	}

	default:
		break;
	}
}

void McuDrvInit(void)
{
	__disable_irq();

	extern uint32_t SystemCoreClock;
	SysTick_Config(SystemCoreClock / 1000); /* delay ms. */

	I2C_init();
	SBS_init();
	//#ifndef DEBUG_MODE
	log_init();
	//#endif

	lptime_config(); // LPT timer init
	exti4_15_PA13_config();
	exti4_15_PA11_config();
	trng_disable();

	spi1_master_config();

	RTC_Init();

	InitSoftTimer();

	flash_decode();
	Read_UpFlash();

	Write_UpFlash();
    delay_ms(2000);
	Afe_Init();
	FWDT_init();
	// StartSoftTimer(SOFT_TIMER_APP_INIT_ID, SINGLE_MODE, 5000, Afe_Init);

	__enable_irq();
}
void FlashDataHandle(void)
{
	if (D_Control_flag_1_RSOC_USE_DF) // Initialize with Flexible data?
	{
		__disable_irq();
		DF_Read(); // Read DataFlash data
		__enable_irq();
		Record_ResetTimes++;
		DF_Write();
	}
	
	LifeTimeData_ReadDF();
}


void DFDataSave(void)
{
	//	Record_MAXLOADCUR =;//MaxLoadCurrent
	//  Record_MAXLOADTTE =;//MaxLoadTimeToEmpty
	Record_RSOC = t_com0d;
	Record_ASOC = t_com0e;
	Record_Remainingcapacity = t_com0f; // Remainingcapacity
	Record_FullChargeCapacity = t_com10;
	Record_CycleCount = _CycleCount; // CycleCount

	Record_IdealRC  = t_com88 ;
	Record_IdealFCC  = t_com89 ;
	Record_IRsoc  = t_com8a ;  // ideal rsoc 
	
   Record_QmaxCell0=_GaugeStatus3.QMax0;
   Record_QmaxCell1=_GaugeStatus3.QMax1;
   Record_QmaxCell2=_GaugeStatus3.QMax2;
   Record_QmaxCell3=_GaugeStatus3.QMax3;


	//  Record_QMAXUPCYCLE =;
//	Record_QMAX = QMAXPACK;
	Record_ChargingVoltage = _ChargingVoltage;
	Record_ChargingCurrent = _ChargingCurrent;
	Record_ChargeToFullTimes = _AverageTimeToFull;
	Record_MaxError = 100;
	// Record_MAXERROR = t_com0c;

	Record_BatteryMode = _BatteryMode.value;
	Record_BatteryStatus = _BatteryStatus.value;
	
	Record_ChargingStatus = t_com55;
	Record_GaugingStatus = t_com56;
	
	Record_OperationStatus = t_com54;
	Record_SafetyStatus = _SafetyStatus.value;
	Record_PFStatus = _PFStatus.value;
	
	Record_TempRange = (uint8_t)t_com55; // TempRange
	Record_ManufacturingStatus = t_com57;			 // ManufacturingStatus
									 //  Record_BALANCESTA =;//BalanceStatus
									 //  Record_SLEEPTIME =;//SleepTime
	Record_FlashWriteTimes++;					 // FlashWriteTimes
	//  Record_RSTT =;//ResetTimes
}