#include "main.h"
#include "smbus_protocol.h"
#include "stdio.h"

//const volatile uint8_t App_SeqNum[32] __attribute__((used)) __attribute__((section(".ARM.__at_0x08002A00"))) = {0xAA};
//static const unsigned int CONFIG0 __attribute__((used)) __attribute__((section(".ARM.__at_0x1FFFF800"))) = 0x00FF03FC;//从应用启动
const uint32_t FW_REVS[6] __attribute__((used)) __attribute__((section(".ARM.__at_0x08000150"))) = {0xA55AC33C,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF};
const uint32_t FW_BIN_VER __attribute__((used)) __attribute__((section(".ARM.__at_0x08000610"))) = FW_VERSION + (FW_TYPE<<16);
const uint32_t DEVICE_TYPE __attribute__((used)) __attribute__((section(".ARM.__at_0x08000620"))) = 0x58353858;
uint16_t Periodtime = 250;
volatile uint8_t fallingcnt = 0;
uint16_t ff=0;
int main(void)
{	
	
	McuDrvInit();
	FlashDataHandle();
	bi2cs_dataCmd_init();
	
	while (1)
	{
		if(UF_BackupREG & 0x1)
		{			
			MCU_FWDG_Feed();
			FWDG_LPT_modeCheck();
		}

		if (f_wakeup_int)
		{
			f_no_smbus = OFF;
			lptim_timer_reload(NormalPeriod);
			f_sleep = OFF;
			f_sleepm = OFF;
			f_wakeup_int = OFF;
		}
		
		
		EXTI_Proc();
		if (f_CC_int && f_VADC_int)
		{
			// if(f_sleep)rtc_time_show();
			f_CC_int = OFF;
			f_VADC_int = OFF;
			
			Get_CVT();

			Judgment_Temp_Change();
			AdvanceChargeAlgorithm_Fun();
			Calc_CC();	
			Calc_RC();
			Calc_RSOC();
			//RSOC_HOLD();
			Calc_iRSOC();
			Calc_ATTF(); // ATTF
			Calc_ATTE(); // ATTE
			QMax_Calc();
             
			DBPT_test();
			Call_ProtectionFun();
			Call_PermanentFailFun();
			
			AlarmWarning_Check();
			
			FullCharge_Chk();
			LifeTime();
			if (!(D_Manufacturing_Status_Init_LDO_EN && D_DA_Configuration_NR))
			{
				PresToggle();
			}
			CellBalance_Chk();
			plugged_IN();

			//delay_ms(100);
		}
		
		SmbusTimeout_Chk(); // Check IIC communication Timeout

		DFUdata_Chk();
		SmbusMACWriteInstruction();
		Power_Modes_Fun();
		FUSE_Contrl();
		FET_Contrl();
	}
}
