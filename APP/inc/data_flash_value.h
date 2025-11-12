#ifndef __DATA_FLASH_VALUE_H__
#define __DATA_FLASH_VALUE_H__

#include "main.h"

#ifdef __cplusplus
extern "C"{
#endif

#pragma pack(push,1)

typedef union{
		uint16_t value;
	struct { 
		uint16_t CRATE                         	:1;
		uint16_t CCC                           	:1;
		uint16_t SOC_CHARGE                    	:1;
		uint16_t CS_CV                         	:1;
		uint16_t COMP_IR                       	:1;
		uint16_t DEGRADE_CC                    	:1;
		uint16_t SOH_DEGRADE                   	:1;
		uint16_t CYCLE_DEGRADE                 	:1;
		uint16_t RUNTIME_DEGRADE               	:1;
		uint16_t RTORFCC                       	:1;
		uint16_t TAPER_VOLT                    	:1;
		uint16_t HIBAT_CHG                     	:1;
		uint16_t HT_INIHIB_DIS                 	:1;
		uint16_t                               	:3;
	}bits;
}Charging_Config;
#define D_Charging_Config_CRATE                           	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.CRATE
#define D_Charging_Config_CCC                             	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.CCC
#define D_Charging_Config_SOC_CHARGE                      	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.SOC_CHARGE
#define D_Charging_Config_CS_CV                           	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.CS_CV
#define D_Charging_Config_COMP_IR                         	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.COMP_IR
#define D_Charging_Config_DEGRADE_CC                      	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.DEGRADE_CC
#define D_Charging_Config_SOH_DEGRADE                     	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.SOH_DEGRADE
#define D_Charging_Config_CYCLE_DEGRADE                   	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.CYCLE_DEGRADE
#define D_Charging_Config_RUNTIME_DEGRADE                 	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.RUNTIME_DEGRADE
#define D_Charging_Config_RTORFCC                         	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.RTORFCC
#define D_Charging_Config_TAPER_VOLT                      	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.TAPER_VOLT
#define D_Charging_Config_HIBAT_CHG                       	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.HIBAT_CHG
#define D_Charging_Config_HT_INIHIB_DIS                   	flashdata.b_Setting.s_Configuration.m_Charging_Config.bits.HT_INIHIB_DIS
#define D_Charging_Config                                 	flashdata.b_Setting.s_Configuration.m_Charging_Config.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t PCHG_COMM                     	:1;
		uint8_t                               	:1;
		uint8_t OTFET                         	:1;
		uint8_t CHGSU                         	:1;
		uint8_t CHGIN                         	:1;
		uint8_t CHGFET                        	:1;
		uint8_t SLEEPCHG                      	:1;
		uint8_t PACK_FUSE                     	:1;
	}bits;
}FETOptions;
#define D_FETOptions_PCHG_COMM                            	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.PCHG_COMM
#define D_FETOptions_OTFET                                	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.OTFET
#define D_FETOptions_CHGSU                                	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.CHGSU
#define D_FETOptions_CHGIN                                	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.CHGIN
#define D_FETOptions_CHGFET                               	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.CHGFET
#define D_FETOptions_SLEEPCHG                             	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.SLEEPCHG
#define D_FETOptions_PACK_FUSE                            	flashdata.b_Setting.s_Configuration.m_FETOptions.bits.PACK_FUSE
#define D_FETOptions                                      	flashdata.b_Setting.s_Configuration.m_FETOptions.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t RSOCL                         	:1;
		uint8_t RSOC_HOLD                     	:1;
		uint8_t LOCK0                         	:1;
		uint8_t RSOC_RND_OFF                  	:1;
		uint8_t _1PERCENT_HOLD                	:1;
		uint8_t                               	:3;
	}bits;
}SBS_Gauging_Configuration;
#define D_SBS_Gauging_Configuration_RSOCL                 	flashdata.b_Setting.s_Configuration.m_SBS_Gauging_Configuration.bits.RSOCL
#define D_SBS_Gauging_Configuration_RSOC_HOLD             	flashdata.b_Setting.s_Configuration.m_SBS_Gauging_Configuration.bits.RSOC_HOLD
#define D_SBS_Gauging_Configuration_LOCK0                 	flashdata.b_Setting.s_Configuration.m_SBS_Gauging_Configuration.bits.LOCK0
#define D_SBS_Gauging_Configuration_RSOC_RND_OFF          	flashdata.b_Setting.s_Configuration.m_SBS_Gauging_Configuration.bits.RSOC_RND_OFF
#define D_SBS_Gauging_Configuration_1PERCENT_HOLD         	flashdata.b_Setting.s_Configuration.m_SBS_Gauging_Configuration.bits._1PERCENT_HOLD
#define D_SBS_Gauging_Configuration                       	flashdata.b_Setting.s_Configuration.m_SBS_Gauging_Configuration.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t BCAST                         	:1;
		uint8_t CPE                           	:1;
		uint8_t HPE                           	:1;
		uint8_t XL                            	:1;
		uint8_t BLT0                          	:1;
		uint8_t BLT1                          	:1;
		uint8_t                               	:2;
	}bits;
}SBS_Configuration;
#define D_SBS_Configuration_BCAST                         	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.bits.BCAST
#define D_SBS_Configuration_CPE                           	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.bits.CPE
#define D_SBS_Configuration_HPE                           	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.bits.HPE
#define D_SBS_Configuration_XL                            	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.bits.XL
#define D_SBS_Configuration_BLT0                          	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.bits.BLT0
#define D_SBS_Configuration_BLT1                          	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.bits.BLT1
#define D_SBS_Configuration                               	flashdata.b_Setting.s_Configuration.m_SBS_Configuration.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t                               	:2;
		uint8_t SHA1_SECURE                   	:1;
		uint8_t DF_READ_EN                    	:1;
		uint8_t                               	:4;
	}bits;
}Auth_Config;
#define D_Auth_Config_SHA1_SECURE                         	flashdata.b_Setting.s_Configuration.m_Auth_Config.bits.SHA1_SECURE
#define D_Auth_Config_DF_READ_EN                          	flashdata.b_Setting.s_Configuration.m_Auth_Config.bits.DF_READ_EN
#define D_Auth_Config                                     	flashdata.b_Setting.s_Configuration.m_Auth_Config.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t AUTO_SHIP_EN                  	:1;
		uint16_t PWR_SAVE_VSHUT                	:1;
		uint16_t EMSHUT_EXIT_VPACK             	:1;
		uint16_t EMSHUT_EXIT_COMM              	:1;
		uint16_t CHECK_WAKE                    	:1;
		uint16_t CHECK_WAKE_FET                	:1;
		uint16_t MFC_CLR_CMD                   	:1;
		uint16_t SHIP_MODE_EN                  	:1;
		uint16_t SLP_ACCUM                     	:1;
		uint16_t SLEEPWKCHG                    	:1;
		uint16_t IO_SHUT                       	:1;
		uint16_t IO_POL                        	:1;
		uint16_t IO_PUL                        	:1;
		uint16_t                               	:3;
	}bits;
}Power_Config;
#define D_Power_Config_AUTO_SHIP_EN                       	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.AUTO_SHIP_EN
#define D_Power_Config_PWR_SAVE_VSHUT                     	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.PWR_SAVE_VSHUT
#define D_Power_Config_EMSHUT_EXIT_VPACK                  	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.EMSHUT_EXIT_VPACK
#define D_Power_Config_EMSHUT_EXIT_COMM                   	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.EMSHUT_EXIT_COMM
#define D_Power_Config_CHECK_WAKE                         	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.CHECK_WAKE
#define D_Power_Config_CHECK_WAKE_FET                     	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.CHECK_WAKE_FET
#define D_Power_Config_MFC_CLR_CMD                        	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.MFC_CLR_CMD
#define D_Power_Config_SHIP_MODE_EN                       	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.SHIP_MODE_EN
#define D_Power_Config_SLP_ACCUM                          	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.SLP_ACCUM
#define D_Power_Config_SLEEPWKCHG                         	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.SLEEPWKCHG
#define D_Power_Config_IO_SHUT                            	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.IO_SHUT
#define D_Power_Config_IO_POL                             	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.IO_POL
#define D_Power_Config_IO_PUL                             	flashdata.b_Setting.s_Configuration.m_Power_Config.bits.IO_PUL
#define D_Power_Config                                    	flashdata.b_Setting.s_Configuration.m_Power_Config.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t BTP_EN                        	:1;
		uint8_t BTP_POL                       	:1;
		uint8_t BTP_MODE                      	:1;
		uint8_t GPIO_EN                       	:1;
		uint8_t GPIO_PF                       	:1;
		uint8_t                               	:3;
	}bits;
}IO_Config;
#define D_IO_Config_BTP_EN                                	flashdata.b_Setting.s_Configuration.m_IO_Config.bits.BTP_EN
#define D_IO_Config_BTP_POL                               	flashdata.b_Setting.s_Configuration.m_IO_Config.bits.BTP_POL
#define D_IO_Config_BTP_MODE                              	flashdata.b_Setting.s_Configuration.m_IO_Config.bits.BTP_MODE
#define D_IO_Config_GPIO_EN                               	flashdata.b_Setting.s_Configuration.m_IO_Config.bits.GPIO_EN
#define D_IO_Config_GPIO_PF                               	flashdata.b_Setting.s_Configuration.m_IO_Config.bits.GPIO_PF
#define D_IO_Config                                       	flashdata.b_Setting.s_Configuration.m_IO_Config.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t DISP_PIN17                    	:1;
		uint16_t LEDCNTLA_PIN20                	:1;
		uint16_t LEDCNTLB_PIN21                	:1;
		uint16_t LEDCNTLC_PIN22                	:1;
		uint16_t                               	:12;
	}bits;
}GPIO_Sealed_Access_Config;
#define D_GPIO_Sealed_Access_Config_DISP_PIN17            	flashdata.b_Setting.s_Configuration.m_GPIO_Sealed_Access_Config.bits.DISP_PIN17
#define D_GPIO_Sealed_Access_Config_LEDCNTLA_PIN20        	flashdata.b_Setting.s_Configuration.m_GPIO_Sealed_Access_Config.bits.LEDCNTLA_PIN20
#define D_GPIO_Sealed_Access_Config_LEDCNTLB_PIN21        	flashdata.b_Setting.s_Configuration.m_GPIO_Sealed_Access_Config.bits.LEDCNTLB_PIN21
#define D_GPIO_Sealed_Access_Config_LEDCNTLC_PIN22        	flashdata.b_Setting.s_Configuration.m_GPIO_Sealed_Access_Config.bits.LEDCNTLC_PIN22
#define D_GPIO_Sealed_Access_Config                       	flashdata.b_Setting.s_Configuration.m_GPIO_Sealed_Access_Config.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t FLAG_REG0                     	:1;
		uint16_t FLAG_REG1                     	:1;
		uint16_t FLAG_REG2                     	:1;
		uint16_t FLAG_REG3                     	:1;
		uint16_t FLAG_BIT0                     	:1;
		uint16_t FLAG_BIT1                     	:1;
		uint16_t FLAG_BIT2                     	:1;
		uint16_t FLAG_BIT3                     	:1;
		uint16_t FLAG_POL                      	:1;
		uint16_t FLAG_GPIO0                    	:1;
		uint16_t FLAG_GPIO1                    	:1;
		uint16_t                               	:1;
		uint16_t FLAG_OR                       	:1;
		uint16_t FLAG_OD                       	:1;
		uint16_t                               	:1;
		uint16_t FLAG_EN                       	:1;
	}bits;
}Flag_Map_Set_Up_1;
#define D_Flag_Map_Set_Up_1_FLAG_REG0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_REG0
#define D_Flag_Map_Set_Up_1_FLAG_REG1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_REG1
#define D_Flag_Map_Set_Up_1_FLAG_REG2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_REG2
#define D_Flag_Map_Set_Up_1_FLAG_REG3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_REG3
#define D_Flag_Map_Set_Up_1_FLAG_BIT0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_BIT0
#define D_Flag_Map_Set_Up_1_FLAG_BIT1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_BIT1
#define D_Flag_Map_Set_Up_1_FLAG_BIT2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_BIT2
#define D_Flag_Map_Set_Up_1_FLAG_BIT3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_BIT3
#define D_Flag_Map_Set_Up_1_FLAG_POL                      	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_POL
#define D_Flag_Map_Set_Up_1_FLAG_GPIO0                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_GPIO0
#define D_Flag_Map_Set_Up_1_FLAG_GPIO1                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_GPIO1
#define D_Flag_Map_Set_Up_1_FLAG_OR                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_OR
#define D_Flag_Map_Set_Up_1_FLAG_OD                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_OD
#define D_Flag_Map_Set_Up_1_FLAG_EN                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.bits.FLAG_EN
#define D_Flag_Map_Set_Up_1                               	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_1.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t FLAG_REG0                     	:1;
		uint16_t FLAG_REG1                     	:1;
		uint16_t FLAG_REG2                     	:1;
		uint16_t FLAG_REG3                     	:1;
		uint16_t FLAG_BIT0                     	:1;
		uint16_t FLAG_BIT1                     	:1;
		uint16_t FLAG_BIT2                     	:1;
		uint16_t FLAG_BIT3                     	:1;
		uint16_t FLAG_POL                      	:1;
		uint16_t FLAG_GPIO0                    	:1;
		uint16_t FLAG_GPIO1                    	:1;
		uint16_t                               	:1;
		uint16_t FLAG_OR                       	:1;
		uint16_t FLAG_OD                       	:1;
		uint16_t                               	:1;
		uint16_t FLAG_EN                       	:1;
	}bits;
}Flag_Map_Set_Up_2;
#define D_Flag_Map_Set_Up_2_FLAG_REG0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_REG0
#define D_Flag_Map_Set_Up_2_FLAG_REG1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_REG1
#define D_Flag_Map_Set_Up_2_FLAG_REG2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_REG2
#define D_Flag_Map_Set_Up_2_FLAG_REG3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_REG3
#define D_Flag_Map_Set_Up_2_FLAG_BIT0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_BIT0
#define D_Flag_Map_Set_Up_2_FLAG_BIT1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_BIT1
#define D_Flag_Map_Set_Up_2_FLAG_BIT2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_BIT2
#define D_Flag_Map_Set_Up_2_FLAG_BIT3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_BIT3
#define D_Flag_Map_Set_Up_2_FLAG_POL                      	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_POL
#define D_Flag_Map_Set_Up_2_FLAG_GPIO0                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_GPIO0
#define D_Flag_Map_Set_Up_2_FLAG_GPIO1                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_GPIO1
#define D_Flag_Map_Set_Up_2_FLAG_OR                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_OR
#define D_Flag_Map_Set_Up_2_FLAG_OD                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_OD
#define D_Flag_Map_Set_Up_2_FLAG_EN                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.bits.FLAG_EN
#define D_Flag_Map_Set_Up_2                               	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_2.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t FLAG_REG0                     	:1;
		uint16_t FLAG_REG1                     	:1;
		uint16_t FLAG_REG2                     	:1;
		uint16_t FLAG_REG3                     	:1;
		uint16_t FLAG_BIT0                     	:1;
		uint16_t FLAG_BIT1                     	:1;
		uint16_t FLAG_BIT2                     	:1;
		uint16_t FLAG_BIT3                     	:1;
		uint16_t FLAG_POL                      	:1;
		uint16_t FLAG_GPIO0                    	:1;
		uint16_t FLAG_GPIO1                    	:1;
		uint16_t                               	:1;
		uint16_t FLAG_OR                       	:1;
		uint16_t FLAG_OD                       	:1;
		uint16_t                               	:1;
		uint16_t FLAG_EN                       	:1;
	}bits;
}Flag_Map_Set_Up_3;
#define D_Flag_Map_Set_Up_3_FLAG_REG0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_REG0
#define D_Flag_Map_Set_Up_3_FLAG_REG1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_REG1
#define D_Flag_Map_Set_Up_3_FLAG_REG2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_REG2
#define D_Flag_Map_Set_Up_3_FLAG_REG3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_REG3
#define D_Flag_Map_Set_Up_3_FLAG_BIT0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_BIT0
#define D_Flag_Map_Set_Up_3_FLAG_BIT1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_BIT1
#define D_Flag_Map_Set_Up_3_FLAG_BIT2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_BIT2
#define D_Flag_Map_Set_Up_3_FLAG_BIT3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_BIT3
#define D_Flag_Map_Set_Up_3_FLAG_POL                      	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_POL
#define D_Flag_Map_Set_Up_3_FLAG_GPIO0                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_GPIO0
#define D_Flag_Map_Set_Up_3_FLAG_GPIO1                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_GPIO1
#define D_Flag_Map_Set_Up_3_FLAG_OR                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_OR
#define D_Flag_Map_Set_Up_3_FLAG_OD                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_OD
#define D_Flag_Map_Set_Up_3_FLAG_EN                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.bits.FLAG_EN
#define D_Flag_Map_Set_Up_3                               	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_3.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t FLAG_REG0                     	:1;
		uint16_t FLAG_REG1                     	:1;
		uint16_t FLAG_REG2                     	:1;
		uint16_t FLAG_REG3                     	:1;
		uint16_t FLAG_BIT0                     	:1;
		uint16_t FLAG_BIT1                     	:1;
		uint16_t FLAG_BIT2                     	:1;
		uint16_t FLAG_BIT3                     	:1;
		uint16_t FLAG_POL                      	:1;
		uint16_t FLAG_GPIO0                    	:1;
		uint16_t FLAG_GPIO1                    	:1;
		uint16_t                               	:1;
		uint16_t FLAG_OR                       	:1;
		uint16_t FLAG_OD                       	:1;
		uint16_t                               	:1;
		uint16_t FLAG_EN                       	:1;
	}bits;
}Flag_Map_Set_Up_4;
#define D_Flag_Map_Set_Up_4_FLAG_REG0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_REG0
#define D_Flag_Map_Set_Up_4_FLAG_REG1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_REG1
#define D_Flag_Map_Set_Up_4_FLAG_REG2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_REG2
#define D_Flag_Map_Set_Up_4_FLAG_REG3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_REG3
#define D_Flag_Map_Set_Up_4_FLAG_BIT0                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_BIT0
#define D_Flag_Map_Set_Up_4_FLAG_BIT1                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_BIT1
#define D_Flag_Map_Set_Up_4_FLAG_BIT2                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_BIT2
#define D_Flag_Map_Set_Up_4_FLAG_BIT3                     	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_BIT3
#define D_Flag_Map_Set_Up_4_FLAG_POL                      	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_POL
#define D_Flag_Map_Set_Up_4_FLAG_GPIO0                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_GPIO0
#define D_Flag_Map_Set_Up_4_FLAG_GPIO1                    	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_GPIO1
#define D_Flag_Map_Set_Up_4_FLAG_OR                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_OR
#define D_Flag_Map_Set_Up_4_FLAG_OD                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_OD
#define D_Flag_Map_Set_Up_4_FLAG_EN                       	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.bits.FLAG_EN
#define D_Flag_Map_Set_Up_4                               	flashdata.b_Setting.s_Configuration.m_Flag_Map_Set_Up_4.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t LEDR                          	:1;
		uint16_t LEDRCA                        	:1;
		uint16_t LEDCHG                        	:1;
		uint16_t LEDMODE                       	:1;
		uint16_t LEDPF0                        	:1;
		uint16_t LEDPF1                        	:1;
		uint16_t LEDC0                         	:1;
		uint16_t LEDC1                         	:1;
		uint16_t LEDPFON                       	:1;
		uint16_t LEDIFCUV                      	:1;
		uint16_t BLINKMIDPT                    	:1;
		uint16_t LEDONFC                       	:1;
		uint16_t                               	:4;
	}bits;
}LED_Configuration;
#define D_LED_Configuration_LEDR                          	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDR
#define D_LED_Configuration_LEDRCA                        	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDRCA
#define D_LED_Configuration_LEDCHG                        	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDCHG
#define D_LED_Configuration_LEDMODE                       	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDMODE
#define D_LED_Configuration_LEDPF0                        	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDPF0
#define D_LED_Configuration_LEDPF1                        	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDPF1
#define D_LED_Configuration_LEDC0                         	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDC0
#define D_LED_Configuration_LEDC1                         	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDC1
#define D_LED_Configuration_LEDPFON                       	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDPFON
#define D_LED_Configuration_LEDIFCUV                      	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDIFCUV
#define D_LED_Configuration_BLINKMIDPT                    	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.BLINKMIDPT
#define D_LED_Configuration_LEDONFC                       	flashdata.b_Setting.s_Configuration.m_LED_Configuration.bits.LEDONFC
#define D_LED_Configuration                               	flashdata.b_Setting.s_Configuration.m_LED_Configuration.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t TSint                         	:1;
		uint8_t TS1                           	:1;
		uint8_t TS2                           	:1;
		uint8_t TS3                           	:1;
		uint8_t TS4                           	:1;
		uint8_t                               	:3;
	}bits;
}Temperature_Enable;
#define D_Temperature_Enable_TSint                        	flashdata.b_Setting.s_Configuration.m_Temperature_Enable.bits.TSint
#define D_Temperature_Enable_TS1                          	flashdata.b_Setting.s_Configuration.m_Temperature_Enable.bits.TS1
#define D_Temperature_Enable_TS2                          	flashdata.b_Setting.s_Configuration.m_Temperature_Enable.bits.TS2
#define D_Temperature_Enable_TS3                          	flashdata.b_Setting.s_Configuration.m_Temperature_Enable.bits.TS3
#define D_Temperature_Enable_TS4                          	flashdata.b_Setting.s_Configuration.m_Temperature_Enable.bits.TS4
#define D_Temperature_Enable                              	flashdata.b_Setting.s_Configuration.m_Temperature_Enable.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t TSint_Mode                    	:1;
		uint8_t TS1_Mode                      	:1;
		uint8_t TS2_Mode                      	:1;
		uint8_t TS3_Mode                      	:1;
		uint8_t TS4_Mode                      	:1;
		uint8_t                               	:3;
	}bits;
}Temperature_Mode;
#define D_Temperature_Mode_TSint_Mode                     	flashdata.b_Setting.s_Configuration.m_Temperature_Mode.bits.TSint_Mode
#define D_Temperature_Mode_TS1_Mode                       	flashdata.b_Setting.s_Configuration.m_Temperature_Mode.bits.TS1_Mode
#define D_Temperature_Mode_TS2_Mode                       	flashdata.b_Setting.s_Configuration.m_Temperature_Mode.bits.TS2_Mode
#define D_Temperature_Mode_TS3_Mode                       	flashdata.b_Setting.s_Configuration.m_Temperature_Mode.bits.TS3_Mode
#define D_Temperature_Mode_TS4_Mode                       	flashdata.b_Setting.s_Configuration.m_Temperature_Mode.bits.TS4_Mode
#define D_Temperature_Mode                                	flashdata.b_Setting.s_Configuration.m_Temperature_Mode.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t CC0                           	:1;
		uint16_t CC1                           	:1;
		uint16_t NR                            	:1;
		uint16_t IN_SYSTEM_SLEEP               	:1;
		uint16_t SLEEP                         	:1;
		uint16_t EMSHUT_EN                     	:1;
		uint16_t DISCONN_EN                    	:1;
		uint16_t FTEMP                         	:1;
		uint16_t EMSHUT_PEXIT_DIS              	:1;
		uint16_t Sampling_Rate                 	:1;
		uint16_t PI_EN             				:1;
		uint16_t                               	:5;
	}bits;
}DA_Configuration;
#define D_DA_Configuration_CC0                            	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.CC0
#define D_DA_Configuration_CC1                            	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.CC1
#define D_DA_Configuration_NR                             	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.NR
#define D_DA_Configuration_IN_SYSTEM_SLEEP                	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.IN_SYSTEM_SLEEP
#define D_DA_Configuration_SLEEP                          	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.SLEEP
#define D_DA_Configuration_EMSHUT_EN                      	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.EMSHUT_EN
#define D_DA_Configuration_DISCONN_EN                     	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.DISCONN_EN
#define D_DA_Configuration_FTEMP                          	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.FTEMP
#define D_DA_Configuration_EMSHUT_PEXIT_DIS               	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.EMSHUT_PEXIT_DIS
#define D_DA_Configuration_Sampling_Rate                  	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.Sampling_Rate
#define D_DA_Configuration_PI_EN                          	flashdata.b_Setting.s_Configuration.m_DA_Configuration.bits.PI_EN
#define D_DA_Configuration                                	flashdata.b_Setting.s_Configuration.m_DA_Configuration.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t TDSETV                        	:1;
		uint16_t TDCLEARV                      	:1;
		uint16_t TDSETRSOC                     	:1;
		uint16_t TDCLEARRSOC                   	:1;
		uint16_t TCSETV                        	:1;
		uint16_t TCCLEARV                      	:1;
		uint16_t TCSETRSOC                     	:1;
		uint16_t TCCLEARRSOC                   	:1;
		uint16_t                               	:2;
		uint16_t FCSETVCT                      	:1;
		uint16_t TCSETVCT                      	:1;
		uint16_t                               	:4;
	}bits;
}SOC_Flag_Config_A;
#define D_SOC_Flag_Config_A_TDSETV                        	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TDSETV
#define D_SOC_Flag_Config_A_TDCLEARV                      	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TDCLEARV
#define D_SOC_Flag_Config_A_TDSETRSOC                     	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TDSETRSOC
#define D_SOC_Flag_Config_A_TDCLEARRSOC                   	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TDCLEARRSOC
#define D_SOC_Flag_Config_A_TCSETV                        	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TCSETV
#define D_SOC_Flag_Config_A_TCCLEARV                      	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TCCLEARV
#define D_SOC_Flag_Config_A_TCSETRSOC                     	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TCSETRSOC
#define D_SOC_Flag_Config_A_TCCLEARRSOC                   	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TCCLEARRSOC
#define D_SOC_Flag_Config_A_FCSETVCT                      	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.FCSETVCT
#define D_SOC_Flag_Config_A_TCSETVCT                      	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.bits.TCSETVCT
#define D_SOC_Flag_Config_A                               	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_A.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t FDSETV                        	:1;
		uint8_t FDCLEARV                      	:1;
		uint8_t FDSETRSOC                     	:1;
		uint8_t FDCLEARRSOC                   	:1;
		uint8_t FCSETV                        	:1;
		uint8_t FCCLEARV                      	:1;
		uint8_t FCSETRSOC                     	:1;
		uint8_t FCCLEARRSOC                   	:1;
	}bits;
}SOC_Flag_Config_B;
#define D_SOC_Flag_Config_B_FDSETV                        	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FDSETV
#define D_SOC_Flag_Config_B_FDCLEARV                      	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FDCLEARV
#define D_SOC_Flag_Config_B_FDSETRSOC                     	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FDSETRSOC
#define D_SOC_Flag_Config_B_FDCLEARRSOC                   	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FDCLEARRSOC
#define D_SOC_Flag_Config_B_FCSETV                        	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FCSETV
#define D_SOC_Flag_Config_B_FCCLEARV                      	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FCCLEARV
#define D_SOC_Flag_Config_B_FCSETRSOC                     	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FCSETRSOC
#define D_SOC_Flag_Config_B_FCCLEARRSOC                   	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.bits.FCCLEARRSOC
#define D_SOC_Flag_Config_B                               	flashdata.b_Setting.s_Configuration.m_SOC_Flag_Config_B.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CB                            	:1;
		uint8_t CBM                           	:1;
		uint8_t CBR                           	:1;
		uint8_t CB_CHG_DOD0EW                 	:1;
		uint8_t CB_RLX_DOD0EW                 	:1;
		uint8_t CBS                           	:1;
		uint8_t CBV                           	:1;
		uint8_t                               	:1;
	}bits;
}Balancing_Configuration;
#define D_Balancing_Configuration_CB                      	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CB
#define D_Balancing_Configuration_CBM                     	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CBM
#define D_Balancing_Configuration_CBR                     	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CBR
#define D_Balancing_Configuration_CB_CHG_DOD0EW           	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CB_CHG_DOD0EW
#define D_Balancing_Configuration_CB_RLX_DOD0EW           	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CB_RLX_DOD0EW
#define D_Balancing_Configuration_CBS                     	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CBS
#define D_Balancing_Configuration_CBV                     	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.bits.CBV
#define D_Balancing_Configuration                         	flashdata.b_Setting.s_Configuration.m_Balancing_Configuration.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t CCT                           	:1;
		uint16_t CSYNC                         	:1;
		uint16_t RFACTSTEP                     	:1;
		uint16_t OCVFR                         	:1;
		uint16_t DOD0EW                        	:1;
		uint16_t LFP_RELAX                     	:1;
		uint16_t RSOC_CONV                     	:1;
		uint16_t FAST_QMAX_LRN                 	:1;
		uint16_t FAST_QMAX_FLD                 	:1;
		uint16_t CELL_TERM                     	:1;
		uint16_t DELAY_DROP_TO_0               	:1;
		uint16_t RELAX_JUMP_OK                 	:1;
		uint16_t SMOOTH                        	:1;
		uint16_t TDELTAV                       	:1;
		uint16_t RELAX_SMOOTH_OK               	:1;
		uint16_t DOD_RSCALE_EN                 	:1;
	}bits;
}IT_Gauging_Configuration;
#define D_IT_Gauging_Configuration_CCT                    	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.CCT
#define D_IT_Gauging_Configuration_CSYNC                  	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.CSYNC
#define D_IT_Gauging_Configuration_RFACTSTEP              	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.RFACTSTEP
#define D_IT_Gauging_Configuration_OCVFR                  	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.OCVFR
#define D_IT_Gauging_Configuration_DOD0EW                 	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.DOD0EW
#define D_IT_Gauging_Configuration_LFP_RELAX              	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.LFP_RELAX
#define D_IT_Gauging_Configuration_RSOC_CONV              	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.RSOC_CONV
#define D_IT_Gauging_Configuration_FAST_QMAX_LRN          	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.FAST_QMAX_LRN
#define D_IT_Gauging_Configuration_FAST_QMAX_FLD          	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.FAST_QMAX_FLD
#define D_IT_Gauging_Configuration_CELL_TERM              	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.CELL_TERM
#define D_IT_Gauging_Configuration_DELAY_DROP_TO_0        	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.DELAY_DROP_TO_0
#define D_IT_Gauging_Configuration_RELAX_JUMP_OK          	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.RELAX_JUMP_OK
#define D_IT_Gauging_Configuration_SMOOTH                 	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.SMOOTH
#define D_IT_Gauging_Configuration_TDELTAV                	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.TDELTAV
#define D_IT_Gauging_Configuration_RELAX_SMOOTH_OK        	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.RELAX_SMOOTH_OK
#define D_IT_Gauging_Configuration_DOD_RSCALE_EN          	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.bits.DOD_RSCALE_EN
#define D_IT_Gauging_Configuration                        	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Configuration.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t DSG_0_SMOOTH_OK               	:1;
		uint8_t CHG_100_SMOOTH_OK             	:1;
		uint8_t AMB_PRED                      	:1;
		uint8_t THERM_IV                      	:1;
		uint8_t THERM_SAT                     	:1;
		uint8_t TS0                           	:1;
		uint8_t TS1                           	:1;
		uint8_t                               	:1;
	}bits;
}IT_Gauging_Ext;
#define D_IT_Gauging_Ext_DSG_0_SMOOTH_OK                  	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.DSG_0_SMOOTH_OK
#define D_IT_Gauging_Ext_CHG_100_SMOOTH_OK                	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.CHG_100_SMOOTH_OK
#define D_IT_Gauging_Ext_AMB_PRED                         	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.AMB_PRED
#define D_IT_Gauging_Ext_THERM_IV                         	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.THERM_IV
#define D_IT_Gauging_Ext_THERM_SAT                        	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.THERM_SAT
#define D_IT_Gauging_Ext_TS0                              	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.TS0
#define D_IT_Gauging_Ext_TS1                              	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.bits.TS1
#define D_IT_Gauging_Ext                                  	flashdata.b_Setting.s_Configuration.m_IT_Gauging_Ext.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t ERM_TIME                      	:1;
		uint8_t ERM_MODE                      	:1;
		uint8_t ERETM_TIME                    	:1;
		uint8_t ERETM_MODE                    	:1;
		uint8_t ERETM_MAX_T                   	:1;
		uint8_t                               	:3;
	}bits;
}Elevate_Degrad_Configuratio;
#define D_Elevate_Degrad_Configuratio_ERM_TIME            	flashdata.b_Setting.s_Configuration.m_Elevate_Degrad_Configuratio.bits.ERM_TIME
#define D_Elevate_Degrad_Configuratio_ERM_MODE            	flashdata.b_Setting.s_Configuration.m_Elevate_Degrad_Configuratio.bits.ERM_MODE
#define D_Elevate_Degrad_Configuratio_ERETM_TIME          	flashdata.b_Setting.s_Configuration.m_Elevate_Degrad_Configuratio.bits.ERETM_TIME
#define D_Elevate_Degrad_Configuratio_ERETM_MODE          	flashdata.b_Setting.s_Configuration.m_Elevate_Degrad_Configuratio.bits.ERETM_MODE
#define D_Elevate_Degrad_Configuratio_ERETM_MAX_T         	flashdata.b_Setting.s_Configuration.m_Elevate_Degrad_Configuratio.bits.ERETM_MAX_T
#define D_Elevate_Degrad_Configuratio                     	flashdata.b_Setting.s_Configuration.m_Elevate_Degrad_Configuratio.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t SUV                           	:1;
		uint8_t SOV                           	:1;
		uint8_t SOCC                          	:1;
		uint8_t SOCD                          	:1;
		uint8_t SOT                           	:1;
		uint8_t                               	:1;
		uint8_t SOTF                          	:1;
		uint8_t QIM                           	:1;
	}bits;
}Permanent_Fail_Fuse_A;
#define D_Permanent_Fail_Fuse_A_SUV                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.SUV
#define D_Permanent_Fail_Fuse_A_SOV                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.SOV
#define D_Permanent_Fail_Fuse_A_SOCC                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.SOCC
#define D_Permanent_Fail_Fuse_A_SOCD                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.SOCD
#define D_Permanent_Fail_Fuse_A_SOT                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.SOT
#define D_Permanent_Fail_Fuse_A_SOTF                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.SOTF
#define D_Permanent_Fail_Fuse_A_QIM                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.bits.QIM
#define D_Permanent_Fail_Fuse_A                           	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_A.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CB                            	:1;
		uint8_t IMP                           	:1;
		uint8_t CD                            	:1;
		uint8_t VIMR                          	:1;
		uint8_t VIMA                          	:1;
		uint8_t                               	:3;
	}bits;
}Permanent_Fail_Fuse_B;
#define D_Permanent_Fail_Fuse_B_CB                        	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_B.bits.CB
#define D_Permanent_Fail_Fuse_B_IMP                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_B.bits.IMP
#define D_Permanent_Fail_Fuse_B_CD                        	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_B.bits.CD
#define D_Permanent_Fail_Fuse_B_VIMR                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_B.bits.VIMR
#define D_Permanent_Fail_Fuse_B_VIMA                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_B.bits.VIMA
#define D_Permanent_Fail_Fuse_B                           	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_B.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CFETF                         	:1;
		uint8_t DFETF                         	:1;
		uint8_t                               	:1;
		uint8_t FUSE                          	:1;
		uint8_t AFER                          	:1;
		uint8_t AFEC                          	:1;
		uint8_t _2LVL                         	:1;
		uint8_t PTC                           	:1;
	}bits;
}Permanent_Fail_Fuse_C;
#define D_Permanent_Fail_Fuse_C_CFETF                     	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits.CFETF
#define D_Permanent_Fail_Fuse_C_DFETF                     	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits.DFETF
#define D_Permanent_Fail_Fuse_C_FUSE                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits.FUSE
#define D_Permanent_Fail_Fuse_C_AFER                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits.AFER
#define D_Permanent_Fail_Fuse_C_AFEC                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits.AFEC
#define D_Permanent_Fail_Fuse_C_2LVL                      	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits._2LVL
#define D_Permanent_Fail_Fuse_C_PTC                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.bits.PTC
#define D_Permanent_Fail_Fuse_C                           	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_C.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t IFC                           	:1;
		uint8_t FORCE                         	:1;
		uint8_t TCO                           	:1;
		uint8_t                               	:1;
		uint8_t TS1                           	:1;
		uint8_t TS2                           	:1;
		uint8_t TS3                           	:1;
		uint8_t TS4                           	:1;
	}bits;
}Permanent_Fail_Fuse_D;
#define D_Permanent_Fail_Fuse_D_IFC                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.IFC
#define D_Permanent_Fail_Fuse_D_FORCE                     	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.FORCE
#define D_Permanent_Fail_Fuse_D_TCO                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.TCO
#define D_Permanent_Fail_Fuse_D_TS1                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.TS1
#define D_Permanent_Fail_Fuse_D_TS2                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.TS2
#define D_Permanent_Fail_Fuse_D_TS3                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.TS3
#define D_Permanent_Fail_Fuse_D_TS4                       	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.bits.TS4
#define D_Permanent_Fail_Fuse_D                           	flashdata.b_Setting.s_Fuse.m_Permanent_Fail_Fuse_D.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t SUV_MODE                      	:1;
		uint8_t CUV_RECOV_CHG                 	:1;
		uint8_t CUDEP_REQ_CHG                 	:1;
		uint8_t                               	:5;
	}bits;
}Protection_Configuration;
#define D_Protection_Configuration_SUV_MODE               	flashdata.b_Setting.s_Protection.m_Protection_Configuration.bits.SUV_MODE
#define D_Protection_Configuration_CUV_RECOV_CHG          	flashdata.b_Setting.s_Protection.m_Protection_Configuration.bits.CUV_RECOV_CHG
#define D_Protection_Configuration_CUDEP_REQ_CHG          	flashdata.b_Setting.s_Protection.m_Protection_Configuration.bits.CUDEP_REQ_CHG
#define D_Protection_Configuration                        	flashdata.b_Setting.s_Protection.m_Protection_Configuration.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CUV                           	:1;
		uint8_t COV                           	:1;
		uint8_t OCC1                          	:1;
		uint8_t OCC2                          	:1;
		uint8_t OCD1                          	:1;
		uint8_t OCD2                          	:1;
		uint8_t AOLD                          	:1;
		uint8_t AOLDL                         	:1;
	}bits;
}Enabled_Protections_A;
#define D_Enabled_Protections_A_CUV                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.CUV
#define D_Enabled_Protections_A_COV                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.COV
#define D_Enabled_Protections_A_OCC1                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.OCC1
#define D_Enabled_Protections_A_OCC2                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.OCC2
#define D_Enabled_Protections_A_OCD1                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.OCD1
#define D_Enabled_Protections_A_OCD2                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.OCD2
#define D_Enabled_Protections_A_AOLD                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.AOLD
#define D_Enabled_Protections_A_AOLDL                     	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.bits.AOLDL
#define D_Enabled_Protections_A                           	flashdata.b_Setting.s_Protection.m_Enabled_Protections_A.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t ASCC                          	:1;
		uint8_t ASCCL                         	:1;
		uint8_t ASCD                          	:1;
		uint8_t ASCDL                         	:1;
		uint8_t OTC                           	:1;
		uint8_t OTD                           	:1;
		uint8_t CUVC                          	:1;
		uint8_t                               	:1;
	}bits;
}Enabled_Protections_B;
#define D_Enabled_Protections_B_ASCC                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.ASCC
#define D_Enabled_Protections_B_ASCCL                     	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.ASCCL
#define D_Enabled_Protections_B_ASCD                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.ASCD
#define D_Enabled_Protections_B_ASCDL                     	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.ASCDL
#define D_Enabled_Protections_B_OTC                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.OTC
#define D_Enabled_Protections_B_OTD                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.OTD
#define D_Enabled_Protections_B_CUVC                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.bits.CUVC
#define D_Enabled_Protections_B                           	flashdata.b_Setting.s_Protection.m_Enabled_Protections_B.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t OTF                           	:1;
		uint8_t HWDF                          	:1;
		uint8_t PTO                           	:1;
		uint8_t                               	:1;
		uint8_t CTO                           	:1;
		uint8_t                               	:1;
		uint8_t OC                            	:1;
		uint8_t CHGC                          	:1;
	}bits;
}Enabled_Protections_C;
#define D_Enabled_Protections_C_OTF                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.bits.OTF
#define D_Enabled_Protections_C_HWDF                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.bits.HWDF
#define D_Enabled_Protections_C_PTO                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.bits.PTO
#define D_Enabled_Protections_C_CTO                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.bits.CTO
#define D_Enabled_Protections_C_OC                        	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.bits.OC
#define D_Enabled_Protections_C_CHGC                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.bits.CHGC
#define D_Enabled_Protections_C                           	flashdata.b_Setting.s_Protection.m_Enabled_Protections_C.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CHGV                          	:1;
		uint8_t PCHGC                         	:1;
		uint8_t UTC                           	:1;
		uint8_t UTD                           	:1;
		uint8_t COVL                          	:1;
		uint8_t OCDL                          	:1;
		uint8_t                               	:1;
	}bits;
}Enabled_Protections_D;
#define D_Enabled_Protections_D_CHGV                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.bits.CHGV
#define D_Enabled_Protections_D_PCHGC                     	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.bits.PCHGC
#define D_Enabled_Protections_D_UTC                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.bits.UTC
#define D_Enabled_Protections_D_UTD                       	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.bits.UTD
#define D_Enabled_Protections_D_COVL                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.bits.COVL
#define D_Enabled_Protections_D_OCDL                      	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.bits.OCDL
#define D_Enabled_Protections_D                           	flashdata.b_Setting.s_Protection.m_Enabled_Protections_D.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t SUV                           	:1;
		uint8_t SOV                           	:1;
		uint8_t SOCC                          	:1;
		uint8_t SOCD                          	:1;
		uint8_t SOT                           	:1;
		uint8_t COVL                          	:1;
		uint8_t SOTF                          	:1;
		uint8_t QIM                           	:1;
	}bits;
}Enabled_PF_A;
#define D_Enabled_PF_A_SUV                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.SUV
#define D_Enabled_PF_A_SOV                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.SOV
#define D_Enabled_PF_A_SOCC                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.SOCC
#define D_Enabled_PF_A_SOCD                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.SOCD
#define D_Enabled_PF_A_SOT                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.SOT
#define D_Enabled_PF_A_COVL                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.COVL
#define D_Enabled_PF_A_SOTF                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.SOTF
#define D_Enabled_PF_A_QIM                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.bits.QIM
#define D_Enabled_PF_A                                    	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_A.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CB                            	:1;
		uint8_t IMP                           	:1;
		uint8_t CD                            	:1;
		uint8_t VIMR                          	:1;
		uint8_t VIMA                          	:1;
		uint8_t AOLDL                         	:1;
		uint8_t ASCCL                         	:1;
		uint8_t ASCDL                         	:1;
	}bits;
}Enabled_PF_B;
#define D_Enabled_PF_B_CB                                 	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.CB
#define D_Enabled_PF_B_IMP                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.IMP
#define D_Enabled_PF_B_CD                                 	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.CD
#define D_Enabled_PF_B_VIMR                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.VIMR
#define D_Enabled_PF_B_VIMA                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.VIMA
#define D_Enabled_PF_B_AOLDL                              	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.AOLDL
#define D_Enabled_PF_B_ASCCL                              	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.ASCCL
#define D_Enabled_PF_B_ASCDL                              	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.bits.ASCDL
#define D_Enabled_PF_B                                    	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_B.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CFETF                         	:1;
		uint8_t DFETF                         	:1;
		uint8_t OCDL                          	:1;
		uint8_t FUSE                          	:1;
		uint8_t AFER                          	:1;
		uint8_t AFEC                          	:1;
		uint8_t _2LVL                         	:1;
		uint8_t PTC                           	:1;
	}bits;
}Enabled_PF_C;
#define D_Enabled_PF_C_CFETF                              	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.CFETF
#define D_Enabled_PF_C_DFETF                              	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.DFETF
#define D_Enabled_PF_C_OCDL                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.OCDL
#define D_Enabled_PF_C_FUSE                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.FUSE
#define D_Enabled_PF_C_AFER                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.AFER
#define D_Enabled_PF_C_AFEC                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.AFEC
#define D_Enabled_PF_C_2LVL                               	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits._2LVL
#define D_Enabled_PF_C_PTC                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.bits.PTC
#define D_Enabled_PF_C                                    	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_C.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t VSP                           	:1;
		uint8_t FORCE                         	:1;
		uint8_t TCO                             :1;
		uint8_t                               	:1;
		uint8_t TS1                           	:1;
		uint8_t TS2                           	:1;
		uint8_t TS3                           	:1;
		uint8_t TS4                           	:1;
	}bits;
}Enabled_PF_D;
#define D_Enabled_PF_D_VSP                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.VSP
#define D_Enabled_PF_D_FORCE                              	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.FORCE
#define D_Enabled_PF_D_TCO                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.TCO
#define D_Enabled_PF_D_TS1                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.TS1
#define D_Enabled_PF_D_TS2                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.TS2
#define D_Enabled_PF_D_TS3                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.TS3
#define D_Enabled_PF_D_TS4                                	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.bits.TS4
#define D_Enabled_PF_D                                    	flashdata.b_Setting.s_Permanent_Failure.m_Enabled_PF_D.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t RSNS                          	:1;
		uint8_t SCDDx2                        	:1;
		uint8_t                               	:6;
	}bits;
}AFE_Protection_Control;
#define D_AFE_Protection_Control_RSNS                     	flashdata.b_Setting.s_AFE.m_AFE_Protection_Control.bits.RSNS
#define D_AFE_Protection_Control_SCDDx2                   	flashdata.b_Setting.s_AFE.m_AFE_Protection_Control.bits.SCDDx2
#define D_AFE_Protection_Control                          	flashdata.b_Setting.s_AFE.m_AFE_Protection_Control.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t                               	:2;
		uint16_t LDO_EN                         :1;
		uint16_t GAUGE_EN                      	:1;
		uint16_t FET_EN                        	:1;
		uint16_t LF_EN                         	:1;
		uint16_t PF_EN                         	:1;
		uint16_t BBR_EN                        	:1;
		uint16_t FUSE_EN                       	:1;
		uint16_t LED_EN                        	:1;
		uint16_t ACDSG_EN                      	:1;
		uint16_t ACCHG_EN                      	:1;
		uint16_t FFC_EN                      	:1;
		uint16_t                               	:3;
	}bits;
}Manufacturing_Status_Init;

#define D_Manufacturing_Status_Init_LDO_EN               	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.LDO_EN
#define D_Manufacturing_Status_Init_GAUGE_EN              	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.GAUGE_EN
#define D_Manufacturing_Status_Init_FET_EN                	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.FET_EN
#define D_Manufacturing_Status_Init_LF_EN                 	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.LF_EN
#define D_Manufacturing_Status_Init_PF_EN                 	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.PF_EN
#define D_Manufacturing_Status_Init_BBR_EN                	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.BBR_EN
#define D_Manufacturing_Status_Init_FUSE_EN               	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.FUSE_EN
#define D_Manufacturing_Status_Init_LED_EN                	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.LED_EN
#define D_Manufacturing_Status_Init_ACDSG_EN              	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.ACDSG_EN
#define D_Manufacturing_Status_Init_ACCHG_EN              	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.ACCHG_EN
#define D_Manufacturing_Status_Init_FFC_EN                	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.bits.FFC_EN
#define D_Manufacturing_Status_Init                       	flashdata.b_Setting.s_AFE.m_Manufacturing_Status_Init.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t                               	:2;
		uint8_t WK0                           	:1;
		uint8_t WK1                           	:1;
		uint8_t                               	:4;
	}bits;
}Wake_Comparator;
#define D_Wake_Comparator_WK0                             	flashdata.b_Power.s_Sleep.m_Wake_Comparator.bits.WK0
#define D_Wake_Comparator_WK1                             	flashdata.b_Power.s_Sleep.m_Wake_Comparator.bits.WK1
#define D_Wake_Comparator                                 	flashdata.b_Power.s_Sleep.m_Wake_Comparator.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t Update0                       	:1;
		uint8_t Update1                       	:1;
		uint8_t Enable                        	:1;
		uint8_t QMax                          	:1;
		uint8_t                               	:4;
	}bits;
}Update_Status;
#define D_Update_Status_Update0                           	flashdata.b_Gas_Gauging.s_State.m_Update_Status.bits.Update0
#define D_Update_Status_Update1                           	flashdata.b_Gas_Gauging.s_State.m_Update_Status.bits.Update1
#define D_Update_Status_Enable                            	flashdata.b_Gas_Gauging.s_State.m_Update_Status.bits.Enable
#define D_Update_Status_QMax                              	flashdata.b_Gas_Gauging.s_State.m_Update_Status.bits.QMax
#define D_Update_Status                                   	flashdata.b_Gas_Gauging.s_State.m_Update_Status.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t RSOC_USE_DF                   	:1;
		uint16_t                               	:5;
		uint16_t FCC_Update_delaying           	:1;
		uint16_t Correct_RCL                   	:1;
		uint16_t Qmax_update_DSG               	:1;
		uint16_t Qmax_update_CHG               	:1;
		uint16_t                               	:3;
		uint16_t Discharge_relearning_point    	:1;
		uint16_t DIS_CHG_Releaning             	:1;
		uint16_t DIS_DSG_Releaning             	:1;
	}bits;
}Control_flag_1;

#define D_Control_flag_1_RSOC_USE_DF                      	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.RSOC_USE_DF
#define D_Control_flag_1_FCC_Update_delaying              	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.FCC_Update_delaying
#define D_Control_flag_1_Correct_RCL                      	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.Correct_RCL
#define D_Control_flag_1_Qmax_update_DSG                  	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.Qmax_update_DSG
#define D_Control_flag_1_Qmax_update_CHG                  	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.Qmax_update_CHG
#define D_Control_flag_1_Discharge_relearning_point       	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.Discharge_relearning_point
#define D_Control_flag_1_DIS_CHG_Releaning                	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.DIS_CHG_Releaning
#define D_Control_flag_1_DIS_DSG_Releaning                	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.bits.DIS_DSG_Releaning
#define D_Control_flag_1                                  	flashdata.b_Control_flag.s_Control_flag.m_Control_flag_1.value


typedef union{
		uint16_t value;
	struct { 
		uint16_t                               	:15;
		uint16_t CAPM                          	:1;
	}bits;
}Initial_Battery_Mode;
#define D_Initial_Battery_Mode_CAPM                       	flashdata.b_SBS_Configuration.s_Data.m_Initial_Battery_Mode.bits.CAPM
#define D_Initial_Battery_Mode                            	flashdata.b_SBS_Configuration.s_Data.m_Initial_Battery_Mode.value

typedef union{
		uint16_t value;
	struct { 
		uint16_t DUAL_MODE_EN                  	:1;
		uint16_t FU_DIS                        	:1;
		uint16_t MFC_DIS                       	:1;
		uint16_t MFC_CLR_CMD                   	:1;
		uint16_t ErrRst_EN                     	:1;
		uint16_t JEITA_EN                      	:1;
		uint16_t POLY_EN                       	:1;
		uint16_t POLY_STEP_DWN                 	:1;
		uint16_t PSE_CHG_EN                    	:1;
		uint16_t                               	:1;
		uint16_t _3ENR_EN                      	:1;
		uint16_t C13_SPEC                      	:1;
		uint16_t DMCHG_ADJ                     	:1;
		uint16_t ATTF_EN                       	:1;
		uint16_t TCMD_DIS                      	:1;
		uint16_t RSOC_RND_99                   	:1;
	}bits;
}Configuration_Register;
#define D_Configuration_Register_DUAL_MODE_EN             	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.DUAL_MODE_EN
#define D_Configuration_Register_FU_DIS                   	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.FU_DIS
#define D_Configuration_Register_MFC_DIS                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.MFC_DIS
#define D_Configuration_Register_MFC_CLR_CMD              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.MFC_CLR_CMD
#define D_Configuration_Register_ErrRst_EN                	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.ErrRst_EN
#define D_Configuration_Register_JEITA_EN                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.JEITA_EN
#define D_Configuration_Register_POLY_EN                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.POLY_EN
#define D_Configuration_Register_POLY_STEP_DWN            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.POLY_STEP_DWN
#define D_Configuration_Register_PSE_CHG_EN               	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.PSE_CHG_EN
#define D_Configuration_Register_3ENR_EN                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits._3ENR_EN
#define D_Configuration_Register_C13_SPEC                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.C13_SPEC
#define D_Configuration_Register_DMCHG_ADJ                	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.DMCHG_ADJ
#define D_Configuration_Register_ATTF_EN                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.ATTF_EN
#define D_Configuration_Register_TCMD_DIS                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.TCMD_DIS
#define D_Configuration_Register_RSOC_RND_99              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.bits.RSOC_RND_99
#define D_Configuration_Register                          	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t EDV_SOC_EN                    	:1;
		uint8_t ALT_LS2_TRIGGER               	:1;
		uint8_t SYS_PRES_EN                   	:1;
		uint8_t RELAX_RSOC_DROP               	:1;
		uint8_t USE_FCC_SoH                   	:1;
		uint8_t SMART_CHG                     	:1;
		uint8_t SMART_CHG_STP_DWN             	:1;
		uint8_t                               	:1;
	}bits;
}Configuration_2_Register;
#define D_Configuration_2_Register_EDV_SOC_EN             	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.EDV_SOC_EN
#define D_Configuration_2_Register_ALT_LS2_TRIGGER        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.ALT_LS2_TRIGGER
#define D_Configuration_2_Register_SYS_PRES_EN            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.SYS_PRES_EN
#define D_Configuration_2_Register_RELAX_RSOC_DROP        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.RELAX_RSOC_DROP
#define D_Configuration_2_Register_USE_FCC_SoH            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.USE_FCC_SoH
#define D_Configuration_2_Register_SMART_CHG              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.SMART_CHG
#define D_Configuration_2_Register_SMART_CHG_STP_DWN      	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.bits.SMART_CHG_STP_DWN
#define D_Configuration_2_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_2_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CS20_SPEC                     	:1;
		uint8_t RSOC_RND_DWN                  	:1;
		uint8_t DIS_Exit_RemCap               	:1;
		uint8_t Dis_Max_Exit_RemCap           	:1;
		uint8_t                               	:1;
		uint8_t FCC_VDQ_EN                    	:1;
		uint8_t NO_LO_TEMP_FCC_UPDATE         	:1;
		uint8_t CP_CTRL                       	:1;
	}bits;
}Configuration_3_Register;
#define D_Configuration_3_Register_CS20_SPEC              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.CS20_SPEC
#define D_Configuration_3_Register_RSOC_RND_DWN           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.RSOC_RND_DWN
#define D_Configuration_3_Register_DIS_Exit_RemCap        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.DIS_Exit_RemCap
#define D_Configuration_3_Register_Dis_Max_Exit_RemCap    	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.Dis_Max_Exit_RemCap
#define D_Configuration_3_Register_FCC_VDQ_EN             	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.FCC_VDQ_EN
#define D_Configuration_3_Register_NO_LO_TEMP_FCC_UPDATE  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.NO_LO_TEMP_FCC_UPDATE
#define D_Configuration_3_Register_CP_CTRL                	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.bits.CP_CTRL
#define D_Configuration_3_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_3_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t SHP_FCSET                     	:1;
		uint8_t AUTH0                         	:1;
		uint8_t AUTH1                         	:1;
		uint8_t FCC_CAL                       	:1;
		uint8_t SHA1_AUTH_EN                  	:1;
		uint8_t SHA1_KEY0                     	:1;
		uint8_t SHA1_KEY1                     	:1;
		uint8_t GB_SOV_RECOV                  	:1;
	}bits;
}Configuration_4_Register;
#define D_Configuration_4_Register_SHP_FCSET              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.SHP_FCSET
#define D_Configuration_4_Register_AUTH0                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.AUTH0
#define D_Configuration_4_Register_AUTH1                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.AUTH1
#define D_Configuration_4_Register_FCC_CAL                	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.FCC_CAL
#define D_Configuration_4_Register_SHA1_AUTH_EN           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.SHA1_AUTH_EN
#define D_Configuration_4_Register_SHA1_KEY0              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.SHA1_KEY0
#define D_Configuration_4_Register_SHA1_KEY1              	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.SHA1_KEY1
#define D_Configuration_4_Register_GB_SOV_RECOV           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.bits.GB_SOV_RECOV
#define D_Configuration_4_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_4_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t CMND26                        	:1;
		uint8_t                               	:7;
	}bits;
}Configuration_5_Register;
#define D_Configuration_5_Register_CMND26                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_5_Register.bits.CMND26
#define D_Configuration_5_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_5_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t AIDM_EN                       	:1;
		uint8_t                               	:1;
		uint8_t AIDM_SYNCH_FCC                	:1;
		uint8_t PI_EN                         	:1;
		uint8_t PI_ENTER_CHG                  	:1;
		uint8_t PI_RELAX_JUMP_OK              	:1;
		uint8_t PI_RELAX_SMOOTH_OK            	:1;
		uint8_t DLS_EXIT_EN                   	:1;
	}bits;
}Configuration_6_Register;
#define D_Configuration_6_Register_AIDM_EN                	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.AIDM_EN
#define D_Configuration_6_Register_AIDM_SYNCH_FCC         	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.AIDM_SYNCH_FCC
#define D_Configuration_6_Register_PI_EN                  	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.PI_EN
#define D_Configuration_6_Register_PI_ENTER_CHG           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.PI_ENTER_CHG
#define D_Configuration_6_Register_PI_RELAX_JUMP_OK       	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.PI_RELAX_JUMP_OK
#define D_Configuration_6_Register_PI_RELAX_SMOOTH_OK     	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.PI_RELAX_SMOOTH_OK
#define D_Configuration_6_Register_DLS_EXIT_EN            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.bits.DLS_EXIT_EN
#define D_Configuration_6_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_6_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t DLS_CHGTERM                   	:1;
		uint8_t FCC_PI_SYNC                   	:1;
		uint8_t RSC_TAPER_EN                  	:1;
		uint8_t SM_3_0                        	:1;
		uint8_t OSCM_ACT                      	:1;
		uint8_t OSCM_ACIN_RESTORE             	:1;
		uint8_t SM_3_5                        	:1;
		uint8_t SM_4_0                        	:1;
	}bits;
}Configuration_7_Register;
#define D_Configuration_7_Register_DLS_CHGTERM            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.DLS_CHGTERM
#define D_Configuration_7_Register_FCC_PI_SYNC            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.FCC_PI_SYNC
#define D_Configuration_7_Register_RSC_TAPER_EN           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.RSC_TAPER_EN
#define D_Configuration_7_Register_SM_3_0                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.SM_3_0
#define D_Configuration_7_Register_OSCM_ACT               	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.OSCM_ACT
#define D_Configuration_7_Register_OSCM_ACIN_RESTORE      	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.OSCM_ACIN_RESTORE
#define D_Configuration_7_Register_SM_3_5                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.SM_3_5
#define D_Configuration_7_Register_SM_4_0                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.bits.SM_4_0
#define D_Configuration_7_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_7_Register.value

typedef union{
		uint8_t value;
	struct { 
		uint8_t EXTD_STORAGE                  	:1;
		uint8_t OSCM_EN                       	:1;
		uint8_t OSCM_T3TIME                   	:1;
		uint8_t RSC_EN                        	:1;
		uint8_t ISD_RECHECK                   	:1;
		uint8_t CID_RECHECK                   	:1;
		uint8_t OSCM_CALTime                  	:1;
		uint8_t                               	:1;
	}bits;
}Configuration_8_Register;
#define D_Configuration_8_Register_EXTD_STORAGE           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.EXTD_STORAGE
#define D_Configuration_8_Register_OSCM_EN                	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.OSCM_EN
#define D_Configuration_8_Register_OSCM_T3TIME            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.OSCM_T3TIME
#define D_Configuration_8_Register_RSC_EN                 	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.RSC_EN
#define D_Configuration_8_Register_ISD_RECHECK            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.ISD_RECHECK
#define D_Configuration_8_Register_CID_RECHECK            	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.CID_RECHECK
#define D_Configuration_8_Register_OSCM_CALTime           	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.bits.OSCM_CALTime
#define D_Configuration_8_Register                        	flashdata.b_Lenovo_Data.s_ConfigurationEx.m_Configuration_8_Register.value

typedef struct{
	uint16_t                          	m_Cell1_vol_Gain;                  	/*说明:*/
	uint16_t                          	m_Cell2_vol_Gain;                  	/*说明:*/
	uint16_t                          	m_Cell3_vol_Gain;                  	/*说明:*/
	uint16_t                          	m_Cell4_vol_Gain;                  	/*说明:*/
	uint16_t                          	m_Pack_Gain;                       	/*说明:*/
	uint16_t                          	m_Bat_Gain;                        	/*说明:*/
	uint16_t                          	m_Current_Gain;                    	/*说明:*/
	int16_t                           	m_CC_Offset;                       	/*说明:*/
	uint16_t                          	m_Dead_Band;                       	/*说明:*/
	int16_t                           	m_InterTOffset;                    	/*说明:*/
	int16_t                           	m_TS1Offset;                       	/*说明:*/
	int16_t                           	m_TS2Offset;                       	/*说明:*/
	int16_t                           	m_TS3Offset;                       	/*说明:*/
	int16_t                           	m_TS4Offset;                       	/*说明:*/
}S_Calibdata;
#define D_Calibdata_Cell1_vol_Gain                        	flashdata.b_Calib.s_Calibdata.m_Cell1_vol_Gain
#define D_Calibdata_Cell2_vol_Gain                        	flashdata.b_Calib.s_Calibdata.m_Cell2_vol_Gain
#define D_Calibdata_Cell3_vol_Gain                        	flashdata.b_Calib.s_Calibdata.m_Cell3_vol_Gain
#define D_Calibdata_Cell4_vol_Gain                        	flashdata.b_Calib.s_Calibdata.m_Cell4_vol_Gain
#define D_Calibdata_Pack_Gain                             	flashdata.b_Calib.s_Calibdata.m_Pack_Gain
#define D_Calibdata_Bat_Gain                              	flashdata.b_Calib.s_Calibdata.m_Bat_Gain
#define D_Calibdata_Current_Gain                          	flashdata.b_Calib.s_Calibdata.m_Current_Gain
#define D_Calibdata_CC_Offset                             	flashdata.b_Calib.s_Calibdata.m_CC_Offset
#define D_Calibdata_Dead_Band                             	flashdata.b_Calib.s_Calibdata.m_Dead_Band
#define D_Calibdata_InterTOffset                          	flashdata.b_Calib.s_Calibdata.m_InterTOffset
#define D_Calibdata_TS1Offset                             	flashdata.b_Calib.s_Calibdata.m_TS1Offset
#define D_Calibdata_TS2Offset                             	flashdata.b_Calib.s_Calibdata.m_TS2Offset
#define D_Calibdata_TS3Offset                             	flashdata.b_Calib.s_Calibdata.m_TS3Offset
#define D_Calibdata_TS4Offset                             	flashdata.b_Calib.s_Calibdata.m_TS4Offset

typedef struct{
	uint16_t                          	m_SOC_OCV_Table_0;                 	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_5;                 	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_10;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_15;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_20;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_25;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_30;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_35;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_40;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_45;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_50;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_55;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_60;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_65;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_70;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_75;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_80;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_85;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_90;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_95;                	/*说明:*/
	uint16_t                          	m_SOC_OCV_Table_100;               	/*说明:*/
}S_OCV_table;
#define D_OCV_SOC_OCV_Table_0                             	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_0
#define D_OCV_SOC_OCV_Table_5                             	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_5
#define D_OCV_SOC_OCV_Table_10                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_10
#define D_OCV_SOC_OCV_Table_15                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_15
#define D_OCV_SOC_OCV_Table_20                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_20
#define D_OCV_SOC_OCV_Table_25                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_25
#define D_OCV_SOC_OCV_Table_30                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_30
#define D_OCV_SOC_OCV_Table_35                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_35
#define D_OCV_SOC_OCV_Table_40                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_40
#define D_OCV_SOC_OCV_Table_45                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_45
#define D_OCV_SOC_OCV_Table_50                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_50
#define D_OCV_SOC_OCV_Table_55                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_55
#define D_OCV_SOC_OCV_Table_60                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_60
#define D_OCV_SOC_OCV_Table_65                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_65
#define D_OCV_SOC_OCV_Table_70                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_70
#define D_OCV_SOC_OCV_Table_75                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_75
#define D_OCV_SOC_OCV_Table_80                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_80
#define D_OCV_SOC_OCV_Table_85                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_85
#define D_OCV_SOC_OCV_Table_90                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_90
#define D_OCV_SOC_OCV_Table_95                            	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_95
#define D_OCV_SOC_OCV_Table_100                           	flashdata.b_OCV_SOC_table.s_OCV_table.m_SOC_OCV_Table_100








typedef struct{
	uint16_t                          	m_SOC_R1_Table_0;                 	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_5;                 	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_10;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_15;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_20;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_25;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_30;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_35;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_40;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_45;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_50;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_55;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_60;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_65;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_70;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_75;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_80;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_85;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_90;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_95;                	/*说明:*/
	uint16_t                          	m_SOC_R1_Table_100;               	/*说明:*/
}S_SOC_R1_table;


typedef struct{
	uint16_t                          	m_SOC_R2_Table_0;                 	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_5;                 	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_10;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_15;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_20;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_25;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_30;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_35;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_40;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_45;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_50;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_55;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_60;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_65;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_70;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_75;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_80;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_85;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_90;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_95;                	/*说明:*/
	uint16_t                          	m_SOC_R2_Table_100;               	/*说明:*/
}S_SOC_R2_table;


typedef struct{
	uint8_t                           	m_CP_Delay;                        	/*说明:*/
	uint8_t                           	m_CP_H;                            	/*说明:*/
	uint8_t                           	m_CP_L;                            	/*说明:*/
	uint8_t                           	m_CPH_Coefficcient;                	/*说明:*/
	uint8_t                           	m_CPL_Coefficcient;                	/*说明:*/
	uint8_t                           	m_FCC_Coefficcient;                	/*说明:*/
}S_CP_Para;
#define D_CP_Delay                                        	flashdata.b_CP_Correction.s_CP_Para.m_CP_Delay
#define D_CP_H                                            	flashdata.b_CP_Correction.s_CP_Para.m_CP_H
#define D_CP_L                                            	flashdata.b_CP_Correction.s_CP_Para.m_CP_L
#define D_CP_CPH_Coefficcient                             	flashdata.b_CP_Correction.s_CP_Para.m_CPH_Coefficcient
#define D_CP_CPL_Coefficcient                             	flashdata.b_CP_Correction.s_CP_Para.m_CPL_Coefficcient
#define D_CP_FCC_Coefficcient                             	flashdata.b_CP_Correction.s_CP_Para.m_FCC_Coefficcient

typedef struct{
	uint8_t                           	m_CP_table_C_rate_1;               	/*说明:*/
	uint8_t                           	m_CP_table_C_rate_2;               	/*说明:*/
	uint8_t                           	m_CP_table_C_rate_3;               	/*说明:*/
	uint8_t                           	m_CP_table_C_rate_4;               	/*说明:*/
	int8_t                            	m_CP_table_T_rate_1;               	/*说明:*/
	int8_t                            	m_CP_table_T_rate_2;               	/*说明:*/
	int8_t                            	m_CP_table_T_rate_3;               	/*说明:*/
	int8_t                            	m_CP_table_T_rate_4;               	/*说明:*/
	int8_t                            	m_CP_table_T_rate_5;               	/*说明:*/
}S_CP_Para_table;
#define D_CP_table_C_rate_1                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_C_rate_1
#define D_CP_table_C_rate_2                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_C_rate_2
#define D_CP_table_C_rate_3                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_C_rate_3
#define D_CP_table_C_rate_4                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_C_rate_4
#define D_CP_table_T_rate_1                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_T_rate_1
#define D_CP_table_T_rate_2                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_T_rate_2
#define D_CP_table_T_rate_3                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_T_rate_3
#define D_CP_table_T_rate_4                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_T_rate_4
#define D_CP_table_T_rate_5                               	flashdata.b_CP_Correction.s_CP_Para_table.m_CP_table_T_rate_5

typedef struct{
	uint16_t                          	m_CPH_voltage_table_C1_T1;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C1_T2;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C1_T3;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C1_T4;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C1_T5;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C2_T1;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C2_T2;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C2_T3;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C2_T4;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C2_T5;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C3_T1;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C3_T2;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C3_T3;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C3_T4;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C3_T5;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C4_T1;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C4_T2;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C4_T3;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C4_T4;         	/*说明:*/
	uint16_t                          	m_CPH_voltage_table_C4_T5;         	/*说明:*/
}S_CPH_Table;
#define D_CPH_voltage_table_C1_T1                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C1_T1
#define D_CPH_voltage_table_C1_T2                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C1_T2
#define D_CPH_voltage_table_C1_T3                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C1_T3
#define D_CPH_voltage_table_C1_T4                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C1_T4
#define D_CPH_voltage_table_C1_T5                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C1_T5
#define D_CPH_voltage_table_C2_T1                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C2_T1
#define D_CPH_voltage_table_C2_T2                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C2_T2
#define D_CPH_voltage_table_C2_T3                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C2_T3
#define D_CPH_voltage_table_C2_T4                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C2_T4
#define D_CPH_voltage_table_C2_T5                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C2_T5
#define D_CPH_voltage_table_C3_T1                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C3_T1
#define D_CPH_voltage_table_C3_T2                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C3_T2
#define D_CPH_voltage_table_C3_T3                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C3_T3
#define D_CPH_voltage_table_C3_T4                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C3_T4
#define D_CPH_voltage_table_C3_T5                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C3_T5
#define D_CPH_voltage_table_C4_T1                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C4_T1
#define D_CPH_voltage_table_C4_T2                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C4_T2
#define D_CPH_voltage_table_C4_T3                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C4_T3
#define D_CPH_voltage_table_C4_T4                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C4_T4
#define D_CPH_voltage_table_C4_T5                         	flashdata.b_CP_Correction.s_CPH_Table.m_CPH_voltage_table_C4_T5

typedef struct{
	uint16_t                          	m_CPL_voltage_table_C1_T1;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C1_T2;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C1_T3;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C1_T4;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C1_T5;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C2_T1;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C2_T2;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C2_T3;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C2_T4;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C2_T5;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C3_T1;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C3_T2;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C3_T3;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C3_T4;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C3_T5;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C4_T1;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C4_T2;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C4_T3;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C4_T4;         	/*说明:*/
	uint16_t                          	m_CPL_voltage_table_C4_T5;         	/*说明:*/
}S_CPL_Table;
#define D_CPL_voltage_table_C1_T1                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C1_T1
#define D_CPL_voltage_table_C1_T2                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C1_T2
#define D_CPL_voltage_table_C1_T3                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C1_T3
#define D_CPL_voltage_table_C1_T4                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C1_T4
#define D_CPL_voltage_table_C1_T5                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C1_T5
#define D_CPL_voltage_table_C2_T1                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C2_T1
#define D_CPL_voltage_table_C2_T2                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C2_T2
#define D_CPL_voltage_table_C2_T3                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C2_T3
#define D_CPL_voltage_table_C2_T4                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C2_T4
#define D_CPL_voltage_table_C2_T5                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C2_T5
#define D_CPL_voltage_table_C3_T1                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C3_T1
#define D_CPL_voltage_table_C3_T2                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C3_T2
#define D_CPL_voltage_table_C3_T3                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C3_T3
#define D_CPL_voltage_table_C3_T4                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C3_T4
#define D_CPL_voltage_table_C3_T5                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C3_T5
#define D_CPL_voltage_table_C4_T1                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C4_T1
#define D_CPL_voltage_table_C4_T2                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C4_T2
#define D_CPL_voltage_table_C4_T3                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C4_T3
#define D_CPL_voltage_table_C4_T4                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C4_T4
#define D_CPL_voltage_table_C4_T5                         	flashdata.b_CP_Correction.s_CPL_Table.m_CPL_voltage_table_C4_T5

typedef struct{
	uint16_t                          	m_QCap_Capcity_table_C1_T1;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C1_T2;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C1_T3;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C1_T4;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C1_T5;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C2_T1;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C2_T2;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C2_T3;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C2_T4;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C2_T5;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C3_T1;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C3_T2;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C3_T3;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C3_T4;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C3_T5;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C4_T1;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C4_T2;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C4_T3;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C4_T4;        	/*说明:*/
	uint16_t                          	m_QCap_Capcity_table_C4_T5;        	/*说明:*/
}S_QCap_Table;
#define D_QCap_Capcity_table_C1_T1                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C1_T1
#define D_QCap_Capcity_table_C1_T2                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C1_T2
#define D_QCap_Capcity_table_C1_T3                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C1_T3
#define D_QCap_Capcity_table_C1_T4                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C1_T4
#define D_QCap_Capcity_table_C1_T5                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C1_T5
#define D_QCap_Capcity_table_C2_T1                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C2_T1
#define D_QCap_Capcity_table_C2_T2                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C2_T2
#define D_QCap_Capcity_table_C2_T3                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C2_T3
#define D_QCap_Capcity_table_C2_T4                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C2_T4
#define D_QCap_Capcity_table_C2_T5                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C2_T5
#define D_QCap_Capcity_table_C3_T1                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C3_T1
#define D_QCap_Capcity_table_C3_T2                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C3_T2
#define D_QCap_Capcity_table_C3_T3                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C3_T3
#define D_QCap_Capcity_table_C3_T4                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C3_T4
#define D_QCap_Capcity_table_C3_T5                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C3_T5
#define D_QCap_Capcity_table_C4_T1                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C4_T1
#define D_QCap_Capcity_table_C4_T2                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C4_T2
#define D_QCap_Capcity_table_C4_T3                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C4_T3
#define D_QCap_Capcity_table_C4_T4                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C4_T4
#define D_QCap_Capcity_table_C4_T5                        	flashdata.b_CP_Correction.s_QCap_Table.m_QCap_Capcity_table_C4_T5

typedef struct{
	uint16_t                          	m_Internal_impedance_cycle1;       	/*说明:*/
	uint16_t                          	m_Internal_impedance_cycle2;       	/*说明:*/
	uint16_t                          	m_Internal_impedance_cycle3;       	/*说明:*/
	uint16_t                          	m_Internal_impedance_cycle4;       	/*说明:*/
	uint16_t                          	m_Internal_impedance_cycle5;       	/*说明:*/
	uint16_t                          	m_Internal_impedance_cycle6;       	/*说明:*/
	uint8_t                           	m_Internal_impedance_table1;       	/*说明:*/
	uint8_t                           	m_Internal_impedance_table2;       	/*说明:*/
	uint8_t                           	m_Internal_impedance_table3;       	/*说明:*/
	uint8_t                           	m_Internal_impedance_table4;       	/*说明:*/
	uint8_t                           	m_Internal_impedance_table5;       	/*说明:*/
	uint8_t                           	m_Internal_impedance_table6;       	/*说明:*/
	uint16_t                          	m_Internal_FCC_table1;             	/*说明:*/
	uint16_t                          	m_Internal_FCC_table2;             	/*说明:*/
	uint16_t                          	m_Internal_FCC_table3;             	/*说明:*/
	uint16_t                          	m_Internal_FCC_table4;             	/*说明:*/
	uint16_t                          	m_Internal_FCC_table5;             	/*说明:*/
	uint16_t                          	m_Internal_FCC_table6;             	/*说明:*/
}S_CEDV_Cycle_Compensate;
#define D_CEDV_Internal_impedance_cycle1                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_cycle1
#define D_CEDV_Internal_impedance_cycle2                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_cycle2
#define D_CEDV_Internal_impedance_cycle3                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_cycle3
#define D_CEDV_Internal_impedance_cycle4                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_cycle4
#define D_CEDV_Internal_impedance_cycle5                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_cycle5
#define D_CEDV_Internal_impedance_cycle6                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_cycle6
#define D_CEDV_Internal_impedance_table1                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_table1
#define D_CEDV_Internal_impedance_table2                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_table2
#define D_CEDV_Internal_impedance_table3                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_table3
#define D_CEDV_Internal_impedance_table4                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_table4
#define D_CEDV_Internal_impedance_table5                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_table5
#define D_CEDV_Internal_impedance_table6                  	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_impedance_table6
#define D_CEDV_Internal_FCC_table1                        	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_FCC_table1
#define D_CEDV_Internal_FCC_table2                        	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_FCC_table2
#define D_CEDV_Internal_FCC_table3                        	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_FCC_table3
#define D_CEDV_Internal_FCC_table4                        	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_FCC_table4
#define D_CEDV_Internal_FCC_table5                        	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_FCC_table5
#define D_CEDV_Internal_FCC_table6                        	flashdata.b_Gas_Gauging.s_CEDV_Cycle_Compensate.m_Internal_FCC_table6

typedef struct{
	uint16_t                          	m_Relearn_stop_time;               	/*说明:*/
	uint8_t                           	m_Min_current_of_cap_calc;         	/*说明:*/
	uint8_t                           	m_Consum_current_of_discharge;     	/*说明:*/
	uint8_t                           	m_Deterioration_capacity;          	/*说明:*/
	uint16_t                          	m_FCC_variance;                    	/*说明:*/
	int8_t                            	m_relearn_temp_limit;              	/*说明:*/
}S_FCC;
#define D_FCC_Relearn_stop_time                           	flashdata.b_Gas_Gauging.s_FCC.m_Relearn_stop_time
#define D_FCC_Min_current_of_cap_calc                     	flashdata.b_Gas_Gauging.s_FCC.m_Min_current_of_cap_calc
#define D_FCC_Consum_current_of_discharge                 	flashdata.b_Gas_Gauging.s_FCC.m_Consum_current_of_discharge
#define D_FCC_Deterioration_capacity                      	flashdata.b_Gas_Gauging.s_FCC.m_Deterioration_capacity
#define D_FCC_variance                                    	flashdata.b_Gas_Gauging.s_FCC.m_FCC_variance
#define D_FCC_relearn_temp_limit                          	flashdata.b_Gas_Gauging.s_FCC.m_relearn_temp_limit

typedef struct{
	uint8_t                           	m_Qmax_update_min_delta_SOC;       	/*说明:*/
	uint8_t                           	m_Temp_Low_limit;                  	/*说明:*/
	uint8_t                           	m_Temp_High_limit;                 	/*说明:*/
	uint8_t                           	m_C_rate_low_limit;                	/*说明:*/
	uint8_t                           	m_C_rate_high_limit;               	/*说明:*/
	uint8_t                           	m_SOC_low_limit;                   	/*说明:*/
	uint8_t                           	m_SOC_high_limit;                  	/*说明:*/
	uint8_t                           	m_Cycle_limit;                     	/*说明:*/
}S_Qmax;
#define D_Qmax_update_min_delta_SOC                       	flashdata.b_Gas_Gauging.s_Qmax.m_Qmax_update_min_delta_SOC
#define D_Qmax_Temp_Low_limit                             	flashdata.b_Gas_Gauging.s_Qmax.m_Temp_Low_limit
#define D_Qmax_Temp_High_limit                            	flashdata.b_Gas_Gauging.s_Qmax.m_Temp_High_limit
#define D_Qmax_C_rate_low_limit                           	flashdata.b_Gas_Gauging.s_Qmax.m_C_rate_low_limit
#define D_Qmax_C_rate_high_limit                          	flashdata.b_Gas_Gauging.s_Qmax.m_C_rate_high_limit
#define D_Qmax_SOC_low_limit                              	flashdata.b_Gas_Gauging.s_Qmax.m_SOC_low_limit
#define D_Qmax_SOC_high_limit                             	flashdata.b_Gas_Gauging.s_Qmax.m_SOC_high_limit
#define D_Qmax_Cycle_limit                                	flashdata.b_Gas_Gauging.s_Qmax.m_Cycle_limit

typedef struct{
	uint16_t                          	m_0_voltage;                       	/*说明:*/
	uint8_t                           	m_0_voltage_Delay;                 	/*说明:*/
}S_Discharge_termination;
#define D_Discharge_0_voltage                             	flashdata.b_Gas_Gauging.s_Discharge_termination.m_0_voltage
#define D_Discharge_0_voltage_Delay                       	flashdata.b_Gas_Gauging.s_Discharge_termination.m_0_voltage_Delay

typedef struct{
	uint16_t                          	m_Cell_balancing_ON_voltage;       	/*说明:*/
	uint16_t                          	m_Cell_balancing_OFF_voltage;      	/*说明:*/
	uint16_t                          	m_Enable_voltage_upper_limit;      	/*说明:*/
	uint16_t                          	m_Enable_voltage_lower_limit;      	/*说明:*/
}S_Cell_Balances;
#define D_Cell_balancing_ON_voltage                       	flashdata.b_Gas_Gauging.s_Cell_Balances.m_Cell_balancing_ON_voltage
#define D_Cell_balancing_OFF_voltage                      	flashdata.b_Gas_Gauging.s_Cell_Balances.m_Cell_balancing_OFF_voltage
#define D_Cell_Enable_voltage_upper_limit                 	flashdata.b_Gas_Gauging.s_Cell_Balances.m_Enable_voltage_upper_limit
#define D_Cell_Enable_voltage_lower_limit                 	flashdata.b_Gas_Gauging.s_Cell_Balances.m_Enable_voltage_lower_limit

typedef struct{
	int16_t                           	m_Dsg_Current_Threshold;           	/*说明:*/
	int16_t                           	m_Chg_Current_Threshold;           	/*说明:*/
	int16_t                           	m_Quit_Current;                    	/*说明:*/
	uint8_t                           	m_Dsg_Relax_Time;                  	/*说明:*/
	uint8_t                           	m_Chg_Relax_Time;                  	/*说明:*/
}S_Current_Thresholds;
#define D_Current_Dsg_Current_Threshold                   	flashdata.b_Gas_Gauging.s_Current_Thresholds.m_Dsg_Current_Threshold
#define D_Current_Chg_Current_Threshold                   	flashdata.b_Gas_Gauging.s_Current_Thresholds.m_Chg_Current_Threshold
#define D_Current_Quit_Current                            	flashdata.b_Gas_Gauging.s_Current_Thresholds.m_Quit_Current
#define D_Current_Dsg_Relax_Time                          	flashdata.b_Gas_Gauging.s_Current_Thresholds.m_Dsg_Relax_Time
#define D_Current_Chg_Relax_Time                          	flashdata.b_Gas_Gauging.s_Current_Thresholds.m_Chg_Relax_Time

typedef struct{
	uint16_t                          	m_Design_Capacity_mAh;             	/*说明:*/
	uint16_t                          	m_Design_Capacity_in_cWh;          	/*说明:*/
	uint16_t                          	m_Design_Voltage;                  	/*说明:*/
	uint16_t                            m_Initial_FCC;
}S_Design;
#define D_Design_Capacity_mAh                             	flashdata.b_Gas_Gauging.s_Design.m_Design_Capacity_mAh
#define D_Design_Capacity_in_cWh                          	flashdata.b_Gas_Gauging.s_Design.m_Design_Capacity_in_cWh
#define D_Design_Voltage                                  	flashdata.b_Gas_Gauging.s_Design.m_Design_Voltage
#define D_INITIAL_FCC                                       flashdata.b_Gas_Gauging.s_Design.m_Initial_FCC

typedef struct{
	int8_t                            	m_Cycle_Count_Percentage;          	/*说明:*/
}S_Cycle;
#define D_Cycle_Count_Percentage                          	flashdata.b_Gas_Gauging.s_Cycle.m_Cycle_Count_Percentage

typedef struct{
	uint16_t                          	m_Set_Voltage_Threshold;           	/*说明:*/
	uint16_t                          	m_Clear_Voltage_Threshold;         	/*说明:*/
	uint8_t                           	m_Set_RSOC_Threshold;              	/*说明:*/
	uint8_t                           	m_Clear_RSOC_Threshold;            	/*说明:*/
}S_FD;
#define D_FD_Set_Voltage_Threshold                        	flashdata.b_Gas_Gauging.s_FD.m_Set_Voltage_Threshold
#define D_FD_Clear_Voltage_Threshold                      	flashdata.b_Gas_Gauging.s_FD.m_Clear_Voltage_Threshold
#define D_FD_Set_RSOC_Threshold                           	flashdata.b_Gas_Gauging.s_FD.m_Set_RSOC_Threshold
#define D_FD_Clear_RSOC_Threshold                         	flashdata.b_Gas_Gauging.s_FD.m_Clear_RSOC_Threshold

typedef struct{
	uint16_t                          	m_Set_Voltage_Threshold;           	/*说明:*/
	uint16_t                          	m_Clear_Voltage_Threshold;         	/*说明:*/
	uint8_t                           	m_Set_RSOC_Threshold;              	/*说明:*/
	uint8_t                           	m_Clear_RSOC_Threshold;            	/*说明:*/
}S_FC;
#define D_FC_Set_Voltage_Threshold                        	flashdata.b_Gas_Gauging.s_FC.m_Set_Voltage_Threshold
#define D_FC_Clear_Voltage_Threshold                      	flashdata.b_Gas_Gauging.s_FC.m_Clear_Voltage_Threshold
#define D_FC_Set_RSOC_Threshold                           	flashdata.b_Gas_Gauging.s_FC.m_Set_RSOC_Threshold
#define D_FC_Clear_RSOC_Threshold                         	flashdata.b_Gas_Gauging.s_FC.m_Clear_RSOC_Threshold

typedef struct{
	uint16_t                          	m_Set_Voltage_Threshold;           	/*说明:*/
	uint16_t                          	m_Clear_Voltage_Threshold;         	/*说明:*/
	uint8_t                           	m_Set_RSOC_Threshold;              	/*说明:*/
	uint8_t                           	m_Clear_RSOC_Threshold;            	/*说明:*/
}S_TD;
#define D_TD_Set_Voltage_Threshold                        	flashdata.b_Gas_Gauging.s_TD.m_Set_Voltage_Threshold
#define D_TD_Clear_Voltage_Threshold                      	flashdata.b_Gas_Gauging.s_TD.m_Clear_Voltage_Threshold
#define D_TD_Set_RSOC_Threshold                           	flashdata.b_Gas_Gauging.s_TD.m_Set_RSOC_Threshold
#define D_TD_Clear_RSOC_Threshold                         	flashdata.b_Gas_Gauging.s_TD.m_Clear_RSOC_Threshold

typedef struct{
	uint16_t                          	m_Set_Voltage_Threshold;           	/*说明:*/
	uint16_t                          	m_Clear_Voltage_Threshold;         	/*说明:*/
	uint8_t                           	m_Set_RSOC_Threshold;              	/*说明:*/
	uint8_t                           	m_Clear_RSOC_Threshold;            	/*说明:*/
}S_TC;
#define D_TC_Set_Voltage_Threshold                        	flashdata.b_Gas_Gauging.s_TC.m_Set_Voltage_Threshold
#define D_TC_Clear_Voltage_Threshold                      	flashdata.b_Gas_Gauging.s_TC.m_Clear_Voltage_Threshold
#define D_TC_Set_RSOC_Threshold                           	flashdata.b_Gas_Gauging.s_TC.m_Set_RSOC_Threshold
#define D_TC_Clear_RSOC_Threshold                         	flashdata.b_Gas_Gauging.s_TC.m_Clear_RSOC_Threshold

typedef struct{
	uint16_t                          	m_Cycle_Count;                     	/*说明:*/
	uint16_t                          	m_QmaxCell1;                       	/*说明:*/
	uint16_t                          	m_QmaxCell2;                       	/*说明:*/
	uint16_t                          	m_QmaxCell3;                       	/*说明:*/
	uint16_t                          	m_QmaxCell4;                       	/*说明:*/
	uint16_t                          	m_QmaxPack;                        	/*说明:*/
	uint16_t                          	m_QmaxCycleCount;                  	/*说明:*/
	uint8_t                           	m_Update_Status;                   	/*说明:*/
}S_State;
#define D_State_Cycle_Count                               	flashdata.b_Gas_Gauging.s_State.m_Cycle_Count
#define D_State_QmaxCell1                                 	flashdata.b_Gas_Gauging.s_State.m_QmaxCell1
#define D_State_QmaxCell2                                 	flashdata.b_Gas_Gauging.s_State.m_QmaxCell2
#define D_State_QmaxCell3                                 	flashdata.b_Gas_Gauging.s_State.m_QmaxCell3
#define D_State_QmaxCell4                                 	flashdata.b_Gas_Gauging.s_State.m_QmaxCell4
#define D_State_QmaxPack                                  	flashdata.b_Gas_Gauging.s_State.m_QmaxPack
#define D_State_QmaxCycleCount                            	flashdata.b_Gas_Gauging.s_State.m_QmaxCycleCount
#define D_State_Update_Status                             	flashdata.b_Gas_Gauging.s_State.m_Update_Status

typedef struct{
	uint16_t                          	m_FW_Version;                      	/*说明:*/
	uint16_t                          	m_DF_Version;                      	/*说明:*/
}S_Version;
#define D_Version_FW_Version                              	flashdata.b_Gas_Gauging.s_Version.m_FW_Version
#define D_Version_DF_Version                              	flashdata.b_Gas_Gauging.s_Version.m_DF_Version

typedef struct{
	int16_t                          	m_MPPCurrent_Max;             	/*说明:*/
	int16_t                          	m_SPPCurrent_Max;          	/*说明:*/
	uint16_t                          	m_MinSysVoltage;                  	/*说明:*/
	uint16_t                           	m_MinSysVoltage_delta;              	/*说明:*/
	uint16_t                          	m_FC_Diode_voltage;        
	int8_t                          	m_DBPT_min_temp;
	int8_t                          	m_DBPT_max_temp;
	uint16_t                            m_PackResistance;			   	/*说明:*/
	uint16_t                            m_SystemResistance;			   	/*说明:*/
}S_DBPT_Values;

#define D_DBPT_MPPCurrent_Max                            	flashdata.b_Gas_Gauging.s_DBPT_Values.m_MPPCurrent_Max
#define D_DBPT_SPPCurrent_Max                            	flashdata.b_Gas_Gauging.s_DBPT_Values.m_SPPCurrent_Max
#define D_DBPT_MinSysVoltage                             	flashdata.b_Gas_Gauging.s_DBPT_Values.m_MinSysVoltage
#define D_DBPT_MinSysVoltage_delta                       	flashdata.b_Gas_Gauging.s_DBPT_Values.m_MinSysVoltage_delta
#define D_DBPT_FC_Diode_voltage                          	flashdata.b_Gas_Gauging.s_DBPT_Values.m_FC_Diode_voltage
#define D_DBPT_DBPT_min_temp                            	flashdata.b_Gas_Gauging.s_DBPT_Values.m_DBPT_min_temp
#define D_DBPT_DBPT_max_temp                            	flashdata.b_Gas_Gauging.s_DBPT_Values.m_DBPT_max_temp
#define D_DBPT_PackResistance                            	flashdata.b_Gas_Gauging.s_DBPT_Values.m_PackResistance
#define D_DBPT_SystemResistance                          	flashdata.b_Gas_Gauging.s_DBPT_Values.m_SystemResistance

typedef struct{
    uint8_t m_PI_RSOC_Threshold;
	int8_t m_PI_HI_Temp_Threshold;
	uint16_t m_Dsg_to_Voltage;
	uint16_t m_PI_Delte_Voltage;
	uint16_t m_PI_Time_Window;
	uint16_t m_PI_HT_Temp_Threshold;
	uint16_t m_PI_HT_Temp_Time;
}S_PI_MODE;

#define D_PI_MODE_PI_RSOC_Threshold                	flashdata.b_Gas_Gauging.s_PI_Mode.m_PI_RSOC_Threshold
#define D_PI_MODE_PI_HI_Temp_Threshold                	flashdata.b_Gas_Gauging.s_PI_Mode.m_PI_HI_Temp_Threshold
#define D_PI_MODE_Dsg_to_Voltage                	flashdata.b_Gas_Gauging.s_PI_Mode.m_Dsg_to_Voltage
#define D_PI_MODE_PI_Delte_Voltage                	flashdata.b_Gas_Gauging.s_PI_Mode.m_PI_Delte_Voltage
#define D_PI_MODE_PI_Time_Window                	flashdata.b_Gas_Gauging.s_PI_Mode.m_PI_Time_Window
#define D_PI_MODE_PI_HT_Temp_Threshold                	flashdata.b_Gas_Gauging.s_PI_Mode.m_PI_HT_Temp_Threshold
#define D_PI_MODE_PI_HT_Temp_Time                	flashdata.b_Gas_Gauging.s_PI_Mode.m_PI_HT_Temp_Time

typedef struct{
	Charging_Config                   	m_Charging_Config;                 	/*说明:*/
	FETOptions                        	m_FETOptions;                      	/*说明:*/
	SBS_Gauging_Configuration         	m_SBS_Gauging_Configuration;       	/*说明:*/
	SBS_Configuration                 	m_SBS_Configuration;               	/*说明:*/
	Auth_Config                       	m_Auth_Config;                     	/*说明:*/
	Power_Config                      	m_Power_Config;                    	/*说明:*/
	IO_Config                         	m_IO_Config;                       	/*说明:*/
	GPIO_Sealed_Access_Config         	m_GPIO_Sealed_Access_Config;       	/*说明:*/
	Flag_Map_Set_Up_1                 	m_Flag_Map_Set_Up_1;               	/*说明:*/
	Flag_Map_Set_Up_2                 	m_Flag_Map_Set_Up_2;               	/*说明:*/
	Flag_Map_Set_Up_3                 	m_Flag_Map_Set_Up_3;               	/*说明:*/
	Flag_Map_Set_Up_4                 	m_Flag_Map_Set_Up_4;               	/*说明:*/
	LED_Configuration                 	m_LED_Configuration;               	/*说明:*/
	Temperature_Enable                	m_Temperature_Enable;              	/*说明:*/
	Temperature_Mode                  	m_Temperature_Mode;                	/*说明:*/
	DA_Configuration                  	m_DA_Configuration;                	/*说明:*/
	SOC_Flag_Config_A                 	m_SOC_Flag_Config_A;               	/*说明:*/
	SOC_Flag_Config_B                 	m_SOC_Flag_Config_B;               	/*说明:*/
	Balancing_Configuration           	m_Balancing_Configuration;         	/*说明:*/
	IT_Gauging_Configuration          	m_IT_Gauging_Configuration;        	/*说明:*/
	IT_Gauging_Ext                    	m_IT_Gauging_Ext;                  	/*说明:*/
	Elevate_Degrad_Configuratio       	m_Elevate_Degrad_Configuratio;     	/*说明:*/
}S_Configuration;

typedef struct{
	Permanent_Fail_Fuse_A             	m_Permanent_Fail_Fuse_A;           	/*说明:*/
	Permanent_Fail_Fuse_B             	m_Permanent_Fail_Fuse_B;           	/*说明:*/
	Permanent_Fail_Fuse_C             	m_Permanent_Fail_Fuse_C;           	/*说明:*/
	Permanent_Fail_Fuse_D             	m_Permanent_Fail_Fuse_D;           	/*说明:*/
	uint16_t                          	m_Min_Blow_Fuse_Voltage;           	/*说明:*/
	uint8_t                           	m_Fuse_Blow_Timeout;               	/*说明:*/
}S_Fuse;
#define D_Fuse_Min_Blow_Fuse_Voltage                      	flashdata.b_Setting.s_Fuse.m_Min_Blow_Fuse_Voltage
#define D_Fuse_Blow_Timeout                               	flashdata.b_Setting.s_Fuse.m_Fuse_Blow_Timeout

typedef struct{
	Protection_Configuration          	m_Protection_Configuration;        	/*说明:*/
	Enabled_Protections_A             	m_Enabled_Protections_A;           	/*说明:*/
	Enabled_Protections_B             	m_Enabled_Protections_B;           	/*说明:*/
	Enabled_Protections_C             	m_Enabled_Protections_C;           	/*说明:*/
	Enabled_Protections_D             	m_Enabled_Protections_D;           	/*说明:*/
}S_Protection;

typedef struct{
	Enabled_PF_A                      	m_Enabled_PF_A;                    	/*说明:*/
	Enabled_PF_B                      	m_Enabled_PF_B;                    	/*说明:*/
	Enabled_PF_C                      	m_Enabled_PF_C;                    	/*说明:*/
	Enabled_PF_D                      	m_Enabled_PF_D;                    	/*说明:*/
}S_Permanent_Failure;

typedef struct{
	AFE_Protection_Control            	m_AFE_Protection_Control;          	/*说明:*/
	Manufacturing_Status_Init         	m_Manufacturing_Status_Init;       	/*说明:*/
}S_AFE;

typedef struct{
	int16_t                           	m_Accumulate_Charg_Measuremen;     	/*说明:*/
	uint16_t                          	m_Accum_Charge_Threshold;          	/*说明:*/
}S_Accumulate_Charg_Measuremen;
#define D_Accumulate_Charg_Measuremen                     	flashdata.b_Setting.s_Accumulate_Charg_Measuremen.m_Accumulate_Charg_Measuremen
#define D_Accumulate_Accum_Charge_Threshold               	flashdata.b_Setting.s_Accumulate_Charg_Measuremen.m_Accum_Charge_Threshold

typedef struct{
	uint8_t                           	m_TimeRSOCThresholdA;              	/*说明:*/
	uint8_t                           	m_TimeRSOCThresholdB;              	/*说明:*/
	uint8_t                           	m_TimeRSOCThresholdC;              	/*说明:*/
	uint8_t                           	m_TimeRSOCThresholdD;              	/*说明:*/
	uint8_t                           	m_TimeRSOCThresholdE;              	/*说明:*/
	uint8_t                           	m_TimeRSOCThresholdF;              	/*说明:*/
	uint8_t                           	m_TimeRSOCThresholdG;              	/*说明:*/
}S_Lifetime_Setting;
#define D_Lifetime_TimeRSOCThresholdA                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdA
#define D_Lifetime_TimeRSOCThresholdB                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdB
#define D_Lifetime_TimeRSOCThresholdC                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdC
#define D_Lifetime_TimeRSOCThresholdD                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdD
#define D_Lifetime_TimeRSOCThresholdE                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdE
#define D_Lifetime_TimeRSOCThresholdF                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdF
#define D_Lifetime_TimeRSOCThresholdG                     	flashdata.b_Setting.s_Lifetime_Setting.m_TimeRSOCThresholdG

typedef struct{
	uint16_t                          	m_Precharge_Start_Voltage;         	/*说明:*/
	uint16_t                          	m_Charging_Voltage_Low;            	/*说明:*/
	uint16_t                          	m_Charging_Voltage_Med;            	/*说明:*/
	uint16_t                          	m_Charging_Voltage_High;           	/*说明:*/
	uint8_t                           	m_Charging_Voltage_Hysteresis;     	/*说明:*/
}S_Voltage_Range;
#define D_Voltage_Precharge_Start_Voltage                 	flashdata.b_Charging_algorithm.s_Voltage_Range.m_Precharge_Start_Voltage
#define D_Voltage_Charging_Voltage_Low                    	flashdata.b_Charging_algorithm.s_Voltage_Range.m_Charging_Voltage_Low
#define D_Voltage_Charging_Voltage_Med                    	flashdata.b_Charging_algorithm.s_Voltage_Range.m_Charging_Voltage_Med
#define D_Voltage_Charging_Voltage_High                   	flashdata.b_Charging_algorithm.s_Voltage_Range.m_Charging_Voltage_High
#define D_Voltage_Charging_Voltage_Hysteresis             	flashdata.b_Charging_algorithm.s_Voltage_Range.m_Charging_Voltage_Hysteresis

typedef struct{
	int16_t                           	m_T1_Temp;                         	/*说明:*/
	int16_t                           	m_T2_Temp;                         	/*说明:*/
	int16_t                           	m_T5_Temp;                         	/*说明:*/
	int16_t                           	m_T6_Temp;                         	/*说明:*/
	int16_t                           	m_T3_Temp;                         	/*说明:*/
	int16_t                           	m_T4_Temp;                         	/*说明:*/
	int16_t                           	m_Hysteresis_Temp;                 	/*说明:*/
}S_Temp_ranges;
#define D_Temp_T1_Temp                                    	flashdata.b_Charging_algorithm.s_Temp_ranges.m_T1_Temp
#define D_Temp_T2_Temp                                    	flashdata.b_Charging_algorithm.s_Temp_ranges.m_T2_Temp
#define D_Temp_T5_Temp                                    	flashdata.b_Charging_algorithm.s_Temp_ranges.m_T5_Temp
#define D_Temp_T6_Temp                                    	flashdata.b_Charging_algorithm.s_Temp_ranges.m_T6_Temp
#define D_Temp_T3_Temp                                    	flashdata.b_Charging_algorithm.s_Temp_ranges.m_T3_Temp
#define D_Temp_T4_Temp                                    	flashdata.b_Charging_algorithm.s_Temp_ranges.m_T4_Temp
#define D_Temp_Hysteresis_Temp                            	flashdata.b_Charging_algorithm.s_Temp_ranges.m_Hysteresis_Temp

typedef struct{
	uint16_t                          	m_LT_CV;                           	/*说明:*/
	uint16_t                          	m_LT_CCL;                          	/*说明:*/
	uint16_t                          	m_LT_CCM;                          	/*说明:*/
	uint16_t                          	m_LT_CCH;                          	/*说明:*/
}S_Low_temp;
#define D_Low_LT_CV                                       	flashdata.b_Charging_algorithm.s_Low_temp.m_LT_CV
#define D_Low_LT_CCL                                      	flashdata.b_Charging_algorithm.s_Low_temp.m_LT_CCL
#define D_Low_LT_CCM                                      	flashdata.b_Charging_algorithm.s_Low_temp.m_LT_CCM
#define D_Low_LT_CCH                                      	flashdata.b_Charging_algorithm.s_Low_temp.m_LT_CCH

typedef struct{
	uint16_t                          	m_STL_CV;                          	/*说明:*/
	uint16_t                          	m_STL_CCL;                         	/*说明:*/
	uint16_t                          	m_STL_CCM;                         	/*说明:*/
	uint16_t                          	m_STL_CCH;                         	/*说明:*/
}S_Standard_Low_temp;
#define D_Standard_STL_CV                                 	flashdata.b_Charging_algorithm.s_Standard_Low_temp.m_STL_CV
#define D_Standard_STL_CCL                                	flashdata.b_Charging_algorithm.s_Standard_Low_temp.m_STL_CCL
#define D_Standard_STL_CCM                                	flashdata.b_Charging_algorithm.s_Standard_Low_temp.m_STL_CCM
#define D_Standard_STL_CCH                                	flashdata.b_Charging_algorithm.s_Standard_Low_temp.m_STL_CCH

typedef struct{
	uint16_t                          	m_STH_CV;                          	/*说明:*/
	uint16_t                          	m_STH_CCL;                         	/*说明:*/
	uint16_t                          	m_STH_CCM;                         	/*说明:*/
	uint16_t                          	m_STH_CCH;                         	/*说明:*/
}S_Standard_High_temp;
#define D_Standard_STH_CV                                 	flashdata.b_Charging_algorithm.s_Standard_High_temp.m_STH_CV
#define D_Standard_STH_CCL                                	flashdata.b_Charging_algorithm.s_Standard_High_temp.m_STH_CCL
#define D_Standard_STH_CCM                                	flashdata.b_Charging_algorithm.s_Standard_High_temp.m_STH_CCM
#define D_Standard_STH_CCH                                	flashdata.b_Charging_algorithm.s_Standard_High_temp.m_STH_CCH

typedef struct{
	uint16_t                          	m_HT_CV;                           	/*说明:*/
	uint16_t                          	m_HT_CCL;                          	/*说明:*/
	uint16_t                          	m_HT_CCM;                          	/*说明:*/
	uint16_t                          	m_HT_CCH;                          	/*说明:*/
}S_High_temp;
#define D_High_HT_CV                                      	flashdata.b_Charging_algorithm.s_High_temp.m_HT_CV
#define D_High_HT_CCL                                     	flashdata.b_Charging_algorithm.s_High_temp.m_HT_CCL
#define D_High_HT_CCM                                     	flashdata.b_Charging_algorithm.s_High_temp.m_HT_CCM
#define D_High_HT_CCH                                     	flashdata.b_Charging_algorithm.s_High_temp.m_HT_CCH

typedef struct{
	uint16_t                          	m_RT_CV;                           	/*说明:*/
	uint16_t                          	m_RT_CCL;                          	/*说明:*/
	uint16_t                          	m_RT_CCM;                          	/*说明:*/
	uint16_t                          	m_RT_CCH;                          	/*说明:*/
}S_Rec_Temp_Charging;
#define D_Rec_RT_CV                                       	flashdata.b_Charging_algorithm.s_Rec_Temp_Charging.m_RT_CV
#define D_Rec_RT_CCL                                      	flashdata.b_Charging_algorithm.s_Rec_Temp_Charging.m_RT_CCL
#define D_Rec_RT_CCM                                      	flashdata.b_Charging_algorithm.s_Rec_Temp_Charging.m_RT_CCM
#define D_Rec_RT_CCH                                      	flashdata.b_Charging_algorithm.s_Rec_Temp_Charging.m_RT_CCH

typedef struct{
	int16_t                           	m_Poly_T1;                         	/*说明:*/
	uint16_t                          	m_Poly_T1A;                        	/*说明:*/
	uint16_t                          	m_Poly_T2;                         	/*说明:*/
	uint16_t                          	m_Poly_T2A;                        	/*说明:*/
	uint16_t                          	m_Poly_T3;                         	/*说明:*/
	uint16_t                          	m_Poly_T3A;                        	/*说明:*/
	uint16_t                          	m_Poly_T3B;                        	/*说明:*/
	uint16_t                          	m_Poly_T3C;                        	/*说明:*/
	uint16_t                          	m_Poly_T4;                         	/*说明:*/
	uint16_t                          	m_Poly_T5;                         	/*说明:*/
	uint16_t                          	m_I1;                              	/*说明:*/
	uint16_t                          	m_I2;                              	/*说明:*/
	uint16_t                          	m_I3;                              	/*说明:*/
	uint16_t                          	m_I4;                              	/*说明:*/
	uint16_t                          	m_I5;                              	/*说明:*/
	uint16_t                          	m_I6;                              	/*说明:*/
	uint16_t                          	m_I7;                              	/*说明:*/
	uint16_t                          	m_I8;                              	/*说明:*/
	uint16_t                          	m_I9;                              	/*说明:*/
	uint16_t                          	m_I10;                             	/*说明:*/
	uint16_t                          	m_I11;                             	/*说明:*/
	uint16_t                          	m_Poly_V1;                         	/*说明:*/
	uint16_t                          	m_Poly_V2;                         	/*说明:*/
	uint16_t                          	m_Poly_V3;                         	/*说明:*/
	uint16_t                          	m_Poly_V4;                         	/*说明:*/
	uint16_t                          	m_Poly_V5;                         	/*说明:*/
	uint16_t                          	m_Poly_hys_Jt;                     	/*说明:*/
	uint16_t                          	m_Poly_Code_Tapper_Current;        	/*说明:*/
	uint16_t                          	m_Poly_Step_Current_Delta;         	/*说明:*/
	uint16_t                          	m_Poly_Step_Current_Time;          	/*说明:*/
	uint16_t                          	m_Poly_Voltage_Delta;              	/*说明:*/
	uint16_t                          	m_Poly_Reset_Temperature;          	/*说明:*/
	uint16_t                          	m_Poly_Reset_voltage;              	/*说明:*/
}S_Poly;
#define D_Poly_T1                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T1
#define D_Poly_T1A                                        	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T1A
#define D_Poly_T2                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T2
#define D_Poly_T2A                                        	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T2A
#define D_Poly_T3                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T3
#define D_Poly_T3A                                        	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T3A
#define D_Poly_T3B                                        	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T3B
#define D_Poly_T3C                                        	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T3C
#define D_Poly_T4                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T4
#define D_Poly_T5                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_T5
#define D_Poly_I1                                         	flashdata.b_Charging_algorithm.s_Poly.m_I1
#define D_Poly_I2                                         	flashdata.b_Charging_algorithm.s_Poly.m_I2
#define D_Poly_I3                                         	flashdata.b_Charging_algorithm.s_Poly.m_I3
#define D_Poly_I4                                         	flashdata.b_Charging_algorithm.s_Poly.m_I4
#define D_Poly_I5                                         	flashdata.b_Charging_algorithm.s_Poly.m_I5
#define D_Poly_I6                                         	flashdata.b_Charging_algorithm.s_Poly.m_I6
#define D_Poly_I7                                         	flashdata.b_Charging_algorithm.s_Poly.m_I7
#define D_Poly_I8                                         	flashdata.b_Charging_algorithm.s_Poly.m_I8
#define D_Poly_I9                                         	flashdata.b_Charging_algorithm.s_Poly.m_I9
#define D_Poly_I10                                        	flashdata.b_Charging_algorithm.s_Poly.m_I10
#define D_Poly_I11                                        	flashdata.b_Charging_algorithm.s_Poly.m_I11
#define D_Poly_V1                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_V1
#define D_Poly_V2                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_V2
#define D_Poly_V3                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_V3
#define D_Poly_V4                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_V4
#define D_Poly_V5                                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_V5
#define D_Poly_hys_Jt                                     	flashdata.b_Charging_algorithm.s_Poly.m_Poly_hys_Jt
#define D_Poly_Code_Tapper_Current                        	flashdata.b_Charging_algorithm.s_Poly.m_Poly_Code_Tapper_Current
#define D_Poly_Step_Current_Delta                         	flashdata.b_Charging_algorithm.s_Poly.m_Poly_Step_Current_Delta
#define D_Poly_Step_Current_Time                          	flashdata.b_Charging_algorithm.s_Poly.m_Poly_Step_Current_Time
#define D_Poly_Voltage_Delta                              	flashdata.b_Charging_algorithm.s_Poly.m_Poly_Voltage_Delta
#define D_Poly_Reset_Temperature                          	flashdata.b_Charging_algorithm.s_Poly.m_Poly_Reset_Temperature
#define D_Poly_Reset_voltage                              	flashdata.b_Charging_algorithm.s_Poly.m_Poly_Reset_voltage

typedef struct{
	uint16_t                          	m_Smart_Chg_CV_Step1_Voltage;      	/*说明:*/
	uint16_t                          	m_Smart_Chg_CV_Step2_Voltage;      	/*说明:*/
	uint16_t                          	m_Smart_Chg_Max_Cell_Voltage;      	/*说明:*/
	uint16_t                          	m_Smart_Chg_Volt_Reset;            	/*说明:*/
	uint16_t                          	m_Smart_Chg_Min_CC;                	/*说明:*/
	uint16_t                          	m_Smart_Chg_Step_Current_Step;     	/*说明:*/
	uint16_t                          	m_Smar_Ch_Norma_Charg_Curren;      	/*说明:*/
	uint16_t                          	m_Smart_Chg_judgement_time;        	/*说明:*/
}S_Smart_charge;
#define D_Smart_Chg_CV_Step1_Voltage                      	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_CV_Step1_Voltage
#define D_Smart_Chg_CV_Step2_Voltage                      	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_CV_Step2_Voltage
#define D_Smart_Chg_Max_Cell_Voltage                      	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_Max_Cell_Voltage
#define D_Smart_Chg_Volt_Reset                            	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_Volt_Reset
#define D_Smart_Chg_Min_CC                                	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_Min_CC
#define D_Smart_Chg_Step_Current_Step                     	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_Step_Current_Step
#define D_Smart_Smar_Ch_Norma_Charg_Curren                	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smar_Ch_Norma_Charg_Curren
#define D_Smart_Chg_judgement_time                        	flashdata.b_Charging_algorithm.s_Smart_charge.m_Smart_Chg_judgement_time

typedef struct{
	uint16_t                          	m_Charge_Term_Voltage;             	/*说明:*/
	uint16_t                          	m_Charge_Term_Taper_Current;       	/*说明:*/
	uint16_t                          	m_Fullcharge_judgement_time;       	/*说明:*/
	uint16_t                          	m_Charge_Term_Taper_Capacity;      	/*说明:*/
}S_Termination_Config;
#define D_Termination_Charge_Term_Voltage                 	flashdata.b_Charging_algorithm.s_Termination_Config.m_Charge_Term_Voltage
#define D_Termination_Charge_Term_Taper_Current           	flashdata.b_Charging_algorithm.s_Termination_Config.m_Charge_Term_Taper_Current
#define D_Termination_Fullcharge_judgement_time           	flashdata.b_Charging_algorithm.s_Termination_Config.m_Fullcharge_judgement_time
#define D_Termination_Charge_Term_Taper_Capacity          	flashdata.b_Charging_algorithm.s_Termination_Config.m_Charge_Term_Taper_Capacity

typedef struct{
	uint16_t                          	m_Current;                         	/*说明:*/
}S_PreCharging;
#define D_PreCharging_Current                             	flashdata.b_Charging_algorithm.s_PreCharging.m_Current

typedef struct{
	int16_t                           	m_Maintenance_ChargingCurrent;     	/*说明:*/
}S_Maintenance_Charging;
#define D_Maintenance_ChargingCurrent                     	flashdata.b_Charging_algorithm.s_Maintenance_Charging.m_Maintenance_ChargingCurrent

typedef struct{
	int16_t                           	m_Charge_Inhibit_Current;          	/*说明:*/
}S_Charge_Inhibit;
#define D_Charge_Inhibit_Current                          	flashdata.b_Charging_algorithm.s_Charge_Inhibit.m_Charge_Inhibit_Current

typedef struct{
	uint8_t                           	m_ERETM_Status;                    	/*说明:*/
}S_Elevated_Degrade;
#define D_Elevated_ERETM_Status                           	flashdata.b_Charging_algorithm.s_Elevated_Degrade.m_ERETM_Status
typedef struct{
	uint16_t                          	m_TemperatureTbl0;                  	/*说明:*/
	uint16_t                          	m_TemperatureTbl1;               	/*说明:*/
	uint16_t                          	m_TemperatureTbl2;            	/*说明:*/
	uint16_t                          	m_TemperatureTbl3;         	/*说明:*/
	int16_t                             m_ChargeTaperCurrentTbl0;	/*说明:*/
	int16_t                             m_ChargeTaperCurrentTbl1;	/*说明:*/
	int16_t                             m_ChargeTaperCurrentTbl2;	/*说明:*/	
	uint16_t                            m_ChargeCellVoltageOffsetTbl0;	/*说明:*/
	uint16_t                            m_ChargeCellVoltageOffsetTbl1;	/*说明:*/
	uint16_t                            m_ChargeCellVoltageOffsetTbl2;
	uint16_t                            m_CellimbalanceVoltage;

}S_FFC_CHARGE;

#define D_FFC_CHARGE_TemperatureTbl0                       	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_TemperatureTbl0
#define D_FFC_CHARGE_TemperatureTbl1                       	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_TemperatureTbl1
#define D_FFC_CHARGE_TemperatureTbl2                       	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_TemperatureTbl2
#define D_FFC_CHARGE_TemperatureTbl3                       	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_TemperatureTbl3
#define D_FFC_CHARGE_ChargeTaperCurrentTbl0                	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_ChargeTaperCurrentTbl0
#define D_FFC_CHARGE_ChargeTaperCurrentTbl1                	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_ChargeTaperCurrentTbl1
#define D_FFC_CHARGE_ChargeTaperCurrentTbl2                	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_ChargeTaperCurrentTbl2
#define D_FFC_CHARGE_ChargeCellVoltageOffsetTbl0           	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_ChargeCellVoltageOffsetTbl0
#define D_FFC_CHARGE_ChargeCellVoltageOffsetTbl1           	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_ChargeCellVoltageOffsetTbl1
#define D_FFC_CHARGE_ChargeCellVoltageOffsetTbl2           	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_ChargeCellVoltageOffsetTbl2
#define D_FFC_CHARGE_CellimbalanceVoltage                 	flashdata.b_Charging_algorithm.s_FFC_CHARGE.m_CellimbalanceVoltage



typedef struct{
	uint16_t                          	m_Shutdown_Voltage;                	/*说明:*/
	uint16_t                          	m_Shutdown_Time;                   	/*说明:*/
	uint8_t                           	m_IO_Shutdown_Delay;               	/*说明:*/
	uint8_t                           	m_IO_Shutdown_Timeout;             	/*说明:*/
	uint16_t                          	m_Charger_Present_Threshold;       	/*说明:*/
	uint8_t                           	m_MAC_FET_Off_Time;                	/*说明:*/
	uint8_t                           	m_MAC_Shutdown_Delay;              	/*说明:*/
	uint16_t                          	m_Auto_Ship_time;                  	/*说明:*/
}S_Shutdown;
#define D_Shutdown_Voltage                                	flashdata.b_Power.s_Shutdown.m_Shutdown_Voltage
#define D_Shutdown_Time                                   	flashdata.b_Power.s_Shutdown.m_Shutdown_Time
#define D_Shutdown_IO_Shutdown_Delay                      	flashdata.b_Power.s_Shutdown.m_IO_Shutdown_Delay
#define D_Shutdown_IO_Shutdown_Timeout                    	flashdata.b_Power.s_Shutdown.m_IO_Shutdown_Timeout
#define D_Shutdown_Charger_Present_Threshold              	flashdata.b_Power.s_Shutdown.m_Charger_Present_Threshold
#define D_Shutdown_MAC_FET_Off_Time                       	flashdata.b_Power.s_Shutdown.m_MAC_FET_Off_Time
#define D_Shutdown_MAC_Shutdown_Delay                     	flashdata.b_Power.s_Shutdown.m_MAC_Shutdown_Delay
#define D_Shutdown_Auto_Ship_time                         	flashdata.b_Power.s_Shutdown.m_Auto_Ship_time

typedef struct{
	int16_t                           	m_Sleep_Current;                   	/*说明:*/
	uint8_t                           	m_Bus_TimeOut;                     	/*说明:*/
	uint8_t                           	m_Voltage_Time;                    	/*说明:*/
	uint8_t                           	m_Current_Time;                    	/*说明:*/
	Wake_Comparator                   	m_Wake_Comparator;                 	/*说明:*/
}S_Sleep;
#define D_Sleep_Current                                   	flashdata.b_Power.s_Sleep.m_Sleep_Current
#define D_Sleep_Bus_TimeOut                               	flashdata.b_Power.s_Sleep.m_Bus_TimeOut
#define D_Sleep_Voltage_Time                              	flashdata.b_Power.s_Sleep.m_Voltage_Time
#define D_Sleep_Current_Time                              	flashdata.b_Power.s_Sleep.m_Current_Time

typedef struct{
	uint8_t                           	m_FET_Off_Storage_Time;            	/*说明:*/
	uint8_t                           	m_FET_Off_Min_RSOC;                	/*说明:*/
}S_Ship_Mode;
#define D_Ship_FET_Off_Storage_Time                       	flashdata.b_Power.s_Ship_Mode.m_FET_Off_Storage_Time
#define D_Ship_FET_Off_Min_RSOC                           	flashdata.b_Power.s_Ship_Mode.m_FET_Off_Min_RSOC

typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	uint16_t                          	m_Recovery;                        	/*说明:*/
	uint16_t                          	m_CUV_Charge_Presen_Threshol;      	/*说明:*/
}S_CUV_Cell_Undervoltage;
#define D_CUV_Threshold                                   	flashdata.b_Protections.s_CUV_Cell_Undervoltage.m_Threshold
#define D_CUV_Delay                                       	flashdata.b_Protections.s_CUV_Cell_Undervoltage.m_Delay
#define D_CUV_Recovery                                    	flashdata.b_Protections.s_CUV_Cell_Undervoltage.m_Recovery
#define D_CUV_Charge_Presen_Threshol                      	flashdata.b_Protections.s_CUV_Cell_Undervoltage.m_CUV_Charge_Presen_Threshol

typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	uint16_t                          	m_Recovery;                        	/*说明:*/
	uint8_t                           	m_CellResistance;                  	/*说明:*/
	uint16_t                          	m_CUV_Charge_Presen_Threshol;      	/*说明:*/
}S_CUVC;
#define D_CUVC_Threshold                                  	flashdata.b_Protections.s_CUVC.m_Threshold
#define D_CUVC_Delay                                      	flashdata.b_Protections.s_CUVC.m_Delay
#define D_CUVC_Recovery                                   	flashdata.b_Protections.s_CUVC.m_Recovery
#define D_CUVC_CellResistance                             	flashdata.b_Protections.s_CUVC.m_CellResistance
#define D_CUVC_CUV_Charge_Presen_Threshol                 	flashdata.b_Protections.s_CUVC.m_CUV_Charge_Presen_Threshol

typedef struct{
	uint16_t                          	m_Threshold_Low_Temp;              	/*说明:*/
	uint16_t                          	m_Threshold_Standard_Temp_Low;     	/*说明:*/
	uint16_t                          	m_Threshold_Standard_Temp_High;    	/*说明:*/
	uint16_t                          	m_Threshold_High_Temp;             	/*说明:*/
	uint16_t                          	m_Threshold_Rec_Temp;              	/*说明:*/
	uint8_t                           	m_COV_Delay;                       	/*说明:*/
	uint16_t                          	m_Recovery_Low_Temp;               	/*说明:*/
	uint16_t                          	m_Recovery_Standard_Temp_Low;      	/*说明:*/
	uint16_t                          	m_Recovery_Standard_Temp_High;     	/*说明:*/
	uint16_t                          	m_Recovery_High_Temp;              	/*说明:*/
	uint16_t                          	m_Recovery_Rec_Temp;               	/*说明:*/
	uint8_t                           	m_Cell_Overvoltage_Latch_Limit;    	/*说明:*/
	uint8_t                           	m_Cel_Overvolt_Coun_Decrem_Del;    	/*说明:*/
	uint8_t                           	m_Reset;                           	/*说明:*/
}S_COV_Cell_Overvoltage;
#define D_COV_Threshold_Low_Temp                          	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Threshold_Low_Temp
#define D_COV_Threshold_Standard_Temp_Low                 	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Threshold_Standard_Temp_Low
#define D_COV_Threshold_Standard_Temp_High                	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Threshold_Standard_Temp_High
#define D_COV_Threshold_High_Temp                         	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Threshold_High_Temp
#define D_COV_Threshold_Rec_Temp                          	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Threshold_Rec_Temp
#define D_COV_Delay                                       	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_COV_Delay
#define D_COV_Recovery_Low_Temp                           	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Recovery_Low_Temp
#define D_COV_Recovery_Standard_Temp_Low                  	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Recovery_Standard_Temp_Low
#define D_COV_Recovery_Standard_Temp_High                 	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Recovery_Standard_Temp_High
#define D_COV_Recovery_High_Temp                          	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Recovery_High_Temp
#define D_COV_Recovery_Rec_Temp                           	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Recovery_Rec_Temp
#define D_COV_Cell_Overvoltage_Latch_Limit                	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Cell_Overvoltage_Latch_Limit
#define D_COV_Cel_Overvolt_Coun_Decrem_Del                	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Cel_Overvolt_Coun_Decrem_Del
#define D_COV_Reset                                       	flashdata.b_Protections.s_COV_Cell_Overvoltage.m_Reset

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_OCC1_Overcurren_In_Charg_1;
#define D_OCC1_Threshold                                  	flashdata.b_Protections.s_OCC1_Overcurren_In_Charg_1.m_Threshold
#define D_OCC1_Delay                                      	flashdata.b_Protections.s_OCC1_Overcurren_In_Charg_1.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_OCC2_Overcurren_In_Charg_2;
#define D_OCC2_Threshold                                  	flashdata.b_Protections.s_OCC2_Overcurren_In_Charg_2.m_Threshold
#define D_OCC2_Delay                                      	flashdata.b_Protections.s_OCC2_Overcurren_In_Charg_2.m_Delay

typedef struct{
	int16_t                           	m_Recovery_Threshold;              	/*说明:*/
	uint8_t                           	m_Recovery_Delay;                  	/*说明:*/
}S_OCC_Overcurr_In_Cha_Recov;
#define D_OCC_Recovery_Threshold                          	flashdata.b_Protections.s_OCC_Overcurr_In_Cha_Recov.m_Recovery_Threshold
#define D_OCC_Recovery_Delay                              	flashdata.b_Protections.s_OCC_Overcurr_In_Cha_Recov.m_Recovery_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_OCD1_Overcurr_In_Discha_1;
#define D_OCD1_Threshold                                  	flashdata.b_Protections.s_OCD1_Overcurr_In_Discha_1.m_Threshold
#define D_OCD1_Delay                                      	flashdata.b_Protections.s_OCD1_Overcurr_In_Discha_1.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_OCD2_Overcurr_In_Discha_2;
#define D_OCD2_Threshold                                  	flashdata.b_Protections.s_OCD2_Overcurr_In_Discha_2.m_Threshold
#define D_OCD2_Delay                                      	flashdata.b_Protections.s_OCD2_Overcurr_In_Discha_2.m_Delay

typedef struct{
	int16_t                           	m_Recovery_Threshold;              	/*说明:*/
	uint8_t                           	m_Recovery_Delay;                  	/*说明:*/
}S_OCD_Overcurren_In_Discharg;
#define D_OCD_Recovery_Threshold                          	flashdata.b_Protections.s_OCD_Overcurren_In_Discharg.m_Recovery_Threshold
#define D_OCD_Recovery_Delay                              	flashdata.b_Protections.s_OCD_Overcurren_In_Discharg.m_Recovery_Delay

typedef struct{
	uint8_t                           	m_Latch_Limit;                     	/*说明:*/
	uint8_t                           	m_Counter_Dec_Delay;               	/*说明:*/
	uint8_t                           	m_Reset;                           	/*说明:*/
}S_OCD_Overcurr_In_Discha_Lat;
#define D_OCD_Latch_Limit                                 	flashdata.b_Protections.s_OCD_Overcurr_In_Discha_Lat.m_Latch_Limit
#define D_OCD_Counter_Dec_Delay                           	flashdata.b_Protections.s_OCD_Overcurr_In_Discha_Lat.m_Counter_Dec_Delay
#define D_OCD_Reset                                       	flashdata.b_Protections.s_OCD_Overcurr_In_Discha_Lat.m_Reset

typedef struct{
	uint8_t                           	m_Latch_Limit;                     	/*说明:*/
	uint8_t                           	m_Counter_Dec_Delay;               	/*说明:*/
	uint8_t                           	m_Recovery;                        	/*说明:*/
	uint8_t                           	m_Reset;                           	/*说明:*/
	uint8_t                           	m_Threshold;                       	/*说明:*/
}S_AOLD_Overload_in_Discharge;
#define D_AOLD_Latch_Limit                                	flashdata.b_Protections.s_AOLD_Overload_in_Discharge.m_Latch_Limit
#define D_AOLD_Counter_Dec_Delay                          	flashdata.b_Protections.s_AOLD_Overload_in_Discharge.m_Counter_Dec_Delay
#define D_AOLD_Recovery                                   	flashdata.b_Protections.s_AOLD_Overload_in_Discharge.m_Recovery
#define D_AOLD_Reset                                      	flashdata.b_Protections.s_AOLD_Overload_in_Discharge.m_Reset
#define D_AOLD_Threshold                                  	flashdata.b_Protections.s_AOLD_Overload_in_Discharge.m_Threshold

typedef struct{
	uint8_t                           	m_Latch_Limit;                     	/*说明:*/
	uint8_t                           	m_Counter_Dec_Delay;               	/*说明:*/
	uint8_t                           	m_Recovery;                        	/*说明:*/
	uint8_t                           	m_Reset;                           	/*说明:*/
	uint8_t                           	m_Threshold;                       	/*说明:*/
}S_ASCC_Shor_Circui_In_Charg;
#define D_ASCC_Latch_Limit                                	flashdata.b_Protections.s_ASCC_Shor_Circui_In_Charg.m_Latch_Limit
#define D_ASCC_Counter_Dec_Delay                          	flashdata.b_Protections.s_ASCC_Shor_Circui_In_Charg.m_Counter_Dec_Delay
#define D_ASCC_Recovery                                   	flashdata.b_Protections.s_ASCC_Shor_Circui_In_Charg.m_Recovery
#define D_ASCC_Reset                                      	flashdata.b_Protections.s_ASCC_Shor_Circui_In_Charg.m_Reset
#define D_ASCC_Threshold                                  	flashdata.b_Protections.s_ASCC_Shor_Circui_In_Charg.m_Threshold

typedef struct{
	uint8_t                           	m_Latch_Limit;                     	/*说明:*/
	uint8_t                           	m_Counter_Dec_Delay;               	/*说明:*/
	uint8_t                           	m_Recovery;                        	/*说明:*/
	uint8_t                           	m_Reset;                           	/*说明:*/
	uint8_t                           	m_Threshold1;                      	/*说明:*/
	uint8_t                           	m_Threshold2;                      	/*说明:*/
}S_ASCD_Sho_Circu_in_Dischar;
#define D_ASCD_Latch_Limit                                	flashdata.b_Protections.s_ASCD_Sho_Circu_in_Dischar.m_Latch_Limit
#define D_ASCD_Counter_Dec_Delay                          	flashdata.b_Protections.s_ASCD_Sho_Circu_in_Dischar.m_Counter_Dec_Delay
#define D_ASCD_Recovery                                   	flashdata.b_Protections.s_ASCD_Sho_Circu_in_Dischar.m_Recovery
#define D_ASCD_Reset                                      	flashdata.b_Protections.s_ASCD_Sho_Circu_in_Dischar.m_Reset
#define D_ASCD_Threshold1                                 	flashdata.b_Protections.s_ASCD_Sho_Circu_in_Dischar.m_Threshold1
#define D_ASCD_Threshold2                                 	flashdata.b_Protections.s_ASCD_Sho_Circu_in_Dischar.m_Threshold2

typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery;                        	/*说明:*/
}S_OTC_Overtemperatu_in_Char;
#define D_OTC_Threshold                                   	flashdata.b_Protections.s_OTC_Overtemperatu_in_Char.m_Threshold
#define D_OTC_Delay                                       	flashdata.b_Protections.s_OTC_Overtemperatu_in_Char.m_Delay
#define D_OTC_Recovery                                    	flashdata.b_Protections.s_OTC_Overtemperatu_in_Char.m_Recovery

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery;                        	/*说明:*/
}S_OTD_Overtemperat_in_Discha;
#define D_OTD_Threshold                                   	flashdata.b_Protections.s_OTD_Overtemperat_in_Discha.m_Threshold
#define D_OTD_Delay                                       	flashdata.b_Protections.s_OTD_Overtemperat_in_Discha.m_Delay
#define D_OTD_Recovery                                    	flashdata.b_Protections.s_OTD_Overtemperat_in_Discha.m_Recovery

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery;                        	/*说明:*/
}S_OTF_Overtemperature_FET;
#define D_OTF_Threshold                                   	flashdata.b_Protections.s_OTF_Overtemperature_FET.m_Threshold
#define D_OTF_Delay                                       	flashdata.b_Protections.s_OTF_Overtemperature_FET.m_Delay
#define D_OTF_Recovery                                    	flashdata.b_Protections.s_OTF_Overtemperature_FET.m_Recovery

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery;                        	/*说明:*/
}S_UTC_Undertemperatu_in_Char;
#define D_UTC_Threshold                                   	flashdata.b_Protections.s_UTC_Undertemperatu_in_Char.m_Threshold
#define D_UTC_Delay                                       	flashdata.b_Protections.s_UTC_Undertemperatu_in_Char.m_Delay
#define D_UTC_Recovery                                    	flashdata.b_Protections.s_UTC_Undertemperatu_in_Char.m_Recovery

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery;                        	/*说明:*/
}S_UTD_Undertempera_in_Disch;
#define D_UTD_Threshold                                   	flashdata.b_Protections.s_UTD_Undertempera_in_Disch.m_Threshold
#define D_UTD_Delay                                       	flashdata.b_Protections.s_UTD_Undertempera_in_Disch.m_Delay
#define D_UTD_Recovery                                    	flashdata.b_Protections.s_UTD_Undertempera_in_Disch.m_Recovery

typedef struct{
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_HWD_Host_Watchdog;
#define D_HWD_Delay                                       	flashdata.b_Protections.s_HWD_Host_Watchdog.m_Delay

typedef struct{
	int16_t                           	m_Charge_Threshold;                	/*说明:*/
	int16_t                           	m_Suspend_Threshold;               	/*说明:*/
	uint16_t                          	m_Delay;                           	/*说明:*/
	int16_t                           	m_Reset;                           	/*说明:*/
}S_PTO_PRECHARG_Mod_Tim_Out;
#define D_PTO_Charge_Threshold                            	flashdata.b_Protections.s_PTO_PRECHARG_Mod_Tim_Out.m_Charge_Threshold
#define D_PTO_Suspend_Threshold                           	flashdata.b_Protections.s_PTO_PRECHARG_Mod_Tim_Out.m_Suspend_Threshold
#define D_PTO_Delay                                       	flashdata.b_Protections.s_PTO_PRECHARG_Mod_Tim_Out.m_Delay
#define D_PTO_Reset                                       	flashdata.b_Protections.s_PTO_PRECHARG_Mod_Tim_Out.m_Reset

typedef struct{
	int16_t                           	m_Charge_Threshold;                	/*说明:*/
	int16_t                           	m_Suspend_Threshold;               	/*说明:*/
	uint16_t                          	m_Delay;                           	/*说明:*/
	int16_t                           	m_Reset;                           	/*说明:*/
}S_CTO_Fas_Charg_Mod_Tim_Out;
#define D_CTO_Charge_Threshold                            	flashdata.b_Protections.s_CTO_Fas_Charg_Mod_Tim_Out.m_Charge_Threshold
#define D_CTO_Suspend_Threshold                           	flashdata.b_Protections.s_CTO_Fas_Charg_Mod_Tim_Out.m_Suspend_Threshold
#define D_CTO_Delay                                       	flashdata.b_Protections.s_CTO_Fas_Charg_Mod_Tim_Out.m_Delay
#define D_CTO_Reset                                       	flashdata.b_Protections.s_CTO_Fas_Charg_Mod_Tim_Out.m_Reset

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	int16_t                           	m_Recovery;                        	/*说明:*/
	uint8_t                           	m_RSOC_Recovery;                   	/*说明:*/
}S_OC_Overcharge;
#define D_OC_Threshold                                    	flashdata.b_Protections.s_OC_Overcharge.m_Threshold
#define D_OC_Recovery                                     	flashdata.b_Protections.s_OC_Overcharge.m_Recovery
#define D_OC_RSOC_Recovery                                	flashdata.b_Protections.s_OC_Overcharge.m_RSOC_Recovery

typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	uint16_t                          	m_Recovery;                        	/*说明:*/
}S_CHGV_ChargingVoltage;
#define D_CHGV_Threshold                                  	flashdata.b_Protections.s_CHGV_ChargingVoltage.m_Threshold
#define D_CHGV_Delay                                      	flashdata.b_Protections.s_CHGV_ChargingVoltage.m_Delay
#define D_CHGV_Recovery                                   	flashdata.b_Protections.s_CHGV_ChargingVoltage.m_Recovery

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery_Threshold;              	/*说明:*/
	uint8_t                           	m_Recovery_Delay;                  	/*说明:*/
}S_CHGC_ChargingCurrent;
#define D_CHGC_Threshold                                  	flashdata.b_Protections.s_CHGC_ChargingCurrent.m_Threshold
#define D_CHGC_Delay                                      	flashdata.b_Protections.s_CHGC_ChargingCurrent.m_Delay
#define D_CHGC_Recovery_Threshold                         	flashdata.b_Protections.s_CHGC_ChargingCurrent.m_Recovery_Threshold
#define D_CHGC_Recovery_Delay                             	flashdata.b_Protections.s_CHGC_ChargingCurrent.m_Recovery_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	int16_t                           	m_Recovery_Threshold;              	/*说明:*/
	uint8_t                           	m_Recovery_Delay;                  	/*说明:*/
}S_PCHGC_Pre_ChargingCurrent;
#define D_PCHGC_Threshold                                 	flashdata.b_Protections.s_PCHGC_Pre_ChargingCurrent.m_Threshold
#define D_PCHGC_Delay                                     	flashdata.b_Protections.s_PCHGC_Pre_ChargingCurrent.m_Delay
#define D_PCHGC_Recovery_Threshold                        	flashdata.b_Protections.s_PCHGC_Pre_ChargingCurrent.m_Recovery_Threshold
#define D_PCHGC_Recovery_Delay                            	flashdata.b_Protections.s_PCHGC_Pre_ChargingCurrent.m_Recovery_Delay





typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_SUV_Safet_Cel_Undervoltag;
#define D_SUV_Threshold                                   	flashdata.b_Permanent_Fail.s_SUV_Safet_Cel_Undervoltag.m_Threshold
#define D_SUV_Delay                                       	flashdata.b_Permanent_Fail.s_SUV_Safet_Cel_Undervoltag.m_Delay

typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_SOV_Safet_Cel_Overvoltag;
#define D_SOV_Threshold                                   	flashdata.b_Permanent_Fail.s_SOV_Safet_Cel_Overvoltag.m_Threshold
#define D_SOV_Delay                                       	flashdata.b_Permanent_Fail.s_SOV_Safet_Cel_Overvoltag.m_Delay

typedef struct{
	uint16_t                          	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_SOCC_Saf_Overcurr_in_Cha;
#define D_SOCC_Threshold                                  	flashdata.b_Permanent_Fail.s_SOCC_Saf_Overcurr_in_Cha.m_Threshold
#define D_SOCC_Delay                                      	flashdata.b_Permanent_Fail.s_SOCC_Saf_Overcurr_in_Cha.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_SOCD_Sa_Overcur_in_Disch;
#define D_SOCD_Threshold                                  	flashdata.b_Permanent_Fail.s_SOCD_Sa_Overcur_in_Disch.m_Threshold
#define D_SOCD_Delay                                      	flashdata.b_Permanent_Fail.s_SOCD_Sa_Overcur_in_Disch.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_SOT_Overtemperature_Cell;
#define D_SOT_Threshold                                   	flashdata.b_Permanent_Fail.s_SOT_Overtemperature_Cell.m_Threshold
#define D_SOT_Delay                                       	flashdata.b_Permanent_Fail.s_SOT_Overtemperature_Cell.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_SOTF_Overtemperature_FET;
#define D_SOTF_Threshold                                  	flashdata.b_Permanent_Fail.s_SOTF_Overtemperature_FET.m_Threshold
#define D_SOTF_Delay                                      	flashdata.b_Permanent_Fail.s_SOTF_Overtemperature_FET.m_Delay

typedef struct{
	uint16_t                          	m_Check_Voltage;                   	/*说明:*/
	int16_t                           	m_Check_Current;                   	/*说明:*/
	int16_t                           	m_Delta_Threshold;                 	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	uint16_t                          	m_Duration;                        	/*说明:*/
}S_VIMR_Volta_Imbalan_At_Res;
#define D_VIMR_Check_Voltage                              	flashdata.b_Permanent_Fail.s_VIMR_Volta_Imbalan_At_Res.m_Check_Voltage
#define D_VIMR_Check_Current                              	flashdata.b_Permanent_Fail.s_VIMR_Volta_Imbalan_At_Res.m_Check_Current
#define D_VIMR_Delta_Threshold                            	flashdata.b_Permanent_Fail.s_VIMR_Volta_Imbalan_At_Res.m_Delta_Threshold
#define D_VIMR_Delay                                      	flashdata.b_Permanent_Fail.s_VIMR_Volta_Imbalan_At_Res.m_Delay
#define D_VIMR_Duration                                   	flashdata.b_Permanent_Fail.s_VIMR_Volta_Imbalan_At_Res.m_Duration

typedef struct{
	uint16_t                          	m_Check_Voltage;                   	/*说明:*/
	int16_t                           	m_Check_Current;                   	/*说明:*/
	uint16_t                          	m_Delta_Threshold;                 	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_VIMA_Voltag_Imbalanc_Activ;
#define D_VIMA_Check_Voltage                              	flashdata.b_Permanent_Fail.s_VIMA_Voltag_Imbalanc_Activ.m_Check_Voltage
#define D_VIMA_Check_Current                              	flashdata.b_Permanent_Fail.s_VIMA_Voltag_Imbalanc_Activ.m_Check_Current
#define D_VIMA_Delta_Threshold                            	flashdata.b_Permanent_Fail.s_VIMA_Voltag_Imbalanc_Activ.m_Delta_Threshold
#define D_VIMA_Delay                                      	flashdata.b_Permanent_Fail.s_VIMA_Voltag_Imbalanc_Activ.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	uint16_t                          	m_VoltageDifference;               	/*说明:*/
	uint16_t                          	m_Temperature_difference;          	/*说明:*/
}S_CFET_CHG_FET_Failure;
#define D_CFET_Threshold                                  	flashdata.b_Permanent_Fail.s_CFET_CHG_FET_Failure.m_Threshold
#define D_CFET_Delay                                      	flashdata.b_Permanent_Fail.s_CFET_CHG_FET_Failure.m_Delay
#define D_CFET_VoltageDifference                          	flashdata.b_Permanent_Fail.s_CFET_CHG_FET_Failure.m_VoltageDifference
#define D_CFET_Temperature_difference                     	flashdata.b_Permanent_Fail.s_CFET_CHG_FET_Failure.m_Temperature_difference

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_DFET_DFET_Failure;
#define D_DFET_Threshold                                  	flashdata.b_Permanent_Fail.s_DFET_DFET_Failure.m_Threshold
#define D_DFET_Delay                                      	flashdata.b_Permanent_Fail.s_DFET_DFET_Failure.m_Delay

typedef struct{
	int16_t                           	m_Threshold;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
}S_FUSE_FUSE_Failure;
#define D_FUSE_Threshold                                  	flashdata.b_Permanent_Fail.s_FUSE_FUSE_Failure.m_Threshold
#define D_FUSE_Delay                                      	flashdata.b_Permanent_Fail.s_FUSE_FUSE_Failure.m_Delay

typedef struct{
	uint8_t                           	m_2LVL;                            	/*说明:*/
}S_2LVL_2nd_Level_OV;
#define D_2LVL                                            	flashdata.b_Permanent_Fail.s_2LVL_2nd_Level_OV.m_2LVL

typedef struct{
	uint16_t                           	m_Change_Voltage;                       	/*说明:*/
	uint16_t                           	m_Min_Voltage;                       	/*说明:*/
	int16_t                           	m_Max_Temperature;                       	/*说明:*/
	uint8_t                           	m_Delay;                           	/*说明:*/
	uint16_t                           	m_Cell_Impedance;              	/*说明:*/
	uint16_t                           	m_K;                  	/*说明:*/
}S_TCO;
#define D_TCO_Change_Voltage                           	flashdata.b_Permanent_Fail.s_TCO.m_Change_Voltage
#define D_TCO_Min_Voltage                               	flashdata.b_Permanent_Fail.s_TCO.m_Min_Voltage
#define D_TCO_Max_Temperature                           	flashdata.b_Permanent_Fail.s_TCO.m_Max_Temperature
#define D_TCO_Delay                                       	flashdata.b_Permanent_Fail.s_TCO.m_Delay
#define D_TCO_Cell_Impedance                              	flashdata.b_Permanent_Fail.s_TCO.m_Cell_Impedance
#define D_TCO_K                                           	flashdata.b_Permanent_Fail.s_TCO.m_K


typedef struct{
	uint16_t                          	m_Manufacturer_Date;               	/*说明:*/
	uint16_t                          	m_Serial_Number;                   	/*说明:*/
	uint8_t                           	m_Manufacturer_Name[21];           	/*说明:*/
	uint8_t                           	m_Device_Name[21];                 	/*说明:*/
	uint8_t                           	m_Device_Chemistry[5];             	/*说明:*/
	uint16_t                          	m_Remaining_Ah_Capacity_Alarm;     	/*说明:*/
	uint16_t                          	m_Remaining_Wh_Capacity_Alarm;     	/*说明:*/
	uint16_t                          	m_Remaining_Time_Alarm;            	/*说明:*/
	Initial_Battery_Mode              	m_Initial_Battery_Mode;            	/*说明:*/
}S_Data;
#define D_Data_Manufacturer_Date                          	flashdata.b_SBS_Configuration.s_Data.m_Manufacturer_Date
#define D_Data_Serial_Number                              	flashdata.b_SBS_Configuration.s_Data.m_Serial_Number
#define D_Data_Manufacturer_Name                          	flashdata.b_SBS_Configuration.s_Data.m_Manufacturer_Name
#define D_Data_Device_Name                                	flashdata.b_SBS_Configuration.s_Data.m_Device_Name
#define D_Data_Device_Chemistry                           	flashdata.b_SBS_Configuration.s_Data.m_Device_Chemistry
#define D_Data_Remaining_Ah_Capacity_Alarm                	flashdata.b_SBS_Configuration.s_Data.m_Remaining_Ah_Capacity_Alarm
#define D_Data_Remaining_Wh_Capacity_Alarm                	flashdata.b_SBS_Configuration.s_Data.m_Remaining_Wh_Capacity_Alarm
#define D_Data_Remaining_Time_Alarm                       	flashdata.b_SBS_Configuration.s_Data.m_Remaining_Time_Alarm

typedef struct{
	Configuration_Register            	m_Configuration_Register;          	/*说明:*/
	Configuration_2_Register          	m_Configuration_2_Register;        	/*说明:*/
	Configuration_3_Register          	m_Configuration_3_Register;        	/*说明:*/
	Configuration_4_Register          	m_Configuration_4_Register;        	/*说明:*/
	Configuration_5_Register          	m_Configuration_5_Register;        	/*说明:*/
	Configuration_6_Register          	m_Configuration_6_Register;        	/*说明:*/
	Configuration_7_Register          	m_Configuration_7_Register;        	/*说明:*/
	Configuration_8_Register          	m_Configuration_8_Register;        	/*说明:*/
}S_ConfigurationEx;

typedef struct{
	int16_t                           	m_Charging_Voltage;                	/*说明:*/
	int16_t                           	m_Fast_Charging_Current;           	/*说明:*/
}S_Normal_Charging;
#define D_Normal_Charging_Voltage                         	flashdata.b_Lenovo_Data.s_Normal_Charging.m_Charging_Voltage
#define D_Normal_Fast_Charging_Current                    	flashdata.b_Lenovo_Data.s_Normal_Charging.m_Fast_Charging_Current

typedef struct{
	int16_t                           	m_CCCV_Charging_Voltage;           	/*说明:*/
	int16_t                           	m_CCCV_Charging_Current;           	/*说明:*/
	int16_t                           	m_CCCV_Curr_Taper_Threshold;       	/*说明:*/
	int16_t                           	m_CCCV_Curr_Taper_Voltage;         	/*说明:*/
	uint8_t                           	m_CCCV_Curr_Taper_Window;          	/*说明:*/
}S_CCCV_Charging;
#define D_CCCV_Charging_Voltage                           	flashdata.b_Lenovo_Data.s_CCCV_Charging.m_CCCV_Charging_Voltage
#define D_CCCV_Charging_Current                           	flashdata.b_Lenovo_Data.s_CCCV_Charging.m_CCCV_Charging_Current
#define D_CCCV_Curr_Taper_Threshold                       	flashdata.b_Lenovo_Data.s_CCCV_Charging.m_CCCV_Curr_Taper_Threshold
#define D_CCCV_Curr_Taper_Voltage                         	flashdata.b_Lenovo_Data.s_CCCV_Charging.m_CCCV_Curr_Taper_Voltage
#define D_CCCV_Curr_Taper_Window                          	flashdata.b_Lenovo_Data.s_CCCV_Charging.m_CCCV_Curr_Taper_Window

typedef struct{
	uint8_t                           	m_FCC_Deg_Current_Adjust_Cycle;    	/*说明:*/
	int16_t                           	m_FCC_Deg_Minimum_Current;         	/*说明:*/
}S_FCC_Degrade_Chg_Current;
#define D_FCC_Deg_Current_Adjust_Cycle                    	flashdata.b_Lenovo_Data.s_FCC_Degrade_Chg_Current.m_FCC_Deg_Current_Adjust_Cycle
#define D_FCC_Deg_Minimum_Current                         	flashdata.b_Lenovo_Data.s_FCC_Degrade_Chg_Current.m_FCC_Deg_Minimum_Current

typedef struct{
	int16_t                           	m_RT_CCV_Max_Cell;                 	/*说明:*/
	int16_t                           	m_LS1_CCV_Max_Cell;                	/*说明:*/
	int16_t                           	m_LS1_CCV_Max_Cell_Drop;           	/*说明:*/
	int16_t                           	m_LS2_CCV_Max_Cell;                	/*说明:*/
	int16_t                           	m_CCV_Min_Current;                 	/*说明:*/
	int16_t                           	m_RT_CCV_Max_Current_Step;         	/*说明:*/
	int16_t                           	m_LS1_CCV_Max_Current_Step;        	/*说明:*/
	int16_t                           	m_LS2_CCV_Max_Current_Step;        	/*说明:*/
	uint8_t                           	m_CCV_Max_Time_Hysteresis;         	/*说明:*/
}S_CCV_Step_Down_Charging;
#define D_CCV_RT_CCV_Max_Cell                             	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_RT_CCV_Max_Cell
#define D_CCV_LS1_CCV_Max_Cell                            	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_LS1_CCV_Max_Cell
#define D_CCV_LS1_CCV_Max_Cell_Drop                       	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_LS1_CCV_Max_Cell_Drop
#define D_CCV_LS2_CCV_Max_Cell                            	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_LS2_CCV_Max_Cell
#define D_CCV_Min_Current                                 	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_CCV_Min_Current
#define D_CCV_RT_CCV_Max_Current_Step                     	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_RT_CCV_Max_Current_Step
#define D_CCV_LS1_CCV_Max_Current_Step                    	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_LS1_CCV_Max_Current_Step
#define D_CCV_LS2_CCV_Max_Current_Step                    	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_LS2_CCV_Max_Current_Step
#define D_CCV_Max_Time_Hysteresis                         	flashdata.b_Lenovo_Data.s_CCV_Step_Down_Charging.m_CCV_Max_Time_Hysteresis

typedef struct{
	int16_t                           	m_Smart_Chg_Voltage_Sw_Over;       	/*说明:*/
	int16_t                           	m_Smart_Chg_Voltage;               	/*说明:*/
	int16_t                           	m_Smart_Chg_Max_Cell;              	/*说明:*/
	int16_t                           	m_Smart_Chg_stp_Reset;             	/*说明:*/
	int16_t                           	m_Smart_Chg_Max_Current_Step;      	/*说明:*/
	int16_t                           	m_Smart_Chg_Normal_Current;        	/*说明:*/
	uint8_t                           	m_Smar_Ch_Ma_Tim_Hysteresi;        	/*说明:*/
}S_Smart_Charge;
#define D_Smart_Chg_Voltage_Sw_Over                       	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smart_Chg_Voltage_Sw_Over
#define D_Smart_Chg_Voltage                               	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smart_Chg_Voltage
#define D_Smart_Chg_Max_Cell                              	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smart_Chg_Max_Cell
#define D_Smart_Chg_stp_Reset                             	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smart_Chg_stp_Reset
#define D_Smart_Chg_Max_Current_Step                      	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smart_Chg_Max_Current_Step
#define D_Smart_Chg_Normal_Current                        	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smart_Chg_Normal_Current
#define D_Smart_Smar_Ch_Ma_Tim_Hysteresi                  	flashdata.b_Lenovo_Data.s_Smart_Charge.m_Smar_Ch_Ma_Tim_Hysteresi

typedef struct{
	int16_t                           	m_Cell_Over_Current;               	/*说明:*/
	uint8_t                           	m_Cell_Delay_Time;                 	/*说明:*/
	uint8_t                           	m_Cell_Recovery_Time;              	/*说明:*/
	uint8_t                           	m_Cell_Alarm_Hold_Time;            	/*说明:*/
	int16_t                           	m_Cell_Alarm_Delta_Current;        	/*说明:*/
	int16_t                           	m_Cell_Alarm_Recovery_Current;     	/*说明:*/
	uint8_t                           	m_Cell_Alarm_Delay_Time;           	/*说明:*/
	uint8_t                           	m_Cell_Alarm_Recovery_Time;        	/*说明:*/
	int16_t                           	m_Cell_Knee_Temperature;           	/*说明:*/
	int16_t                           	m_Cell_Final_Current;              	/*说明:*/
	int16_t                           	m_FET_Over_Current;                	/*说明:*/
	uint8_t                           	m_FET_Delay_Time;                  	/*说明:*/
	uint8_t                           	m_FET_Recovery_Time;               	/*说明:*/
	uint8_t                           	m_FET_Alarm_Hold_Time;             	/*说明:*/
	int16_t                           	m_FET_Alarm_Delta_Current;         	/*说明:*/
	int16_t                           	m_FET_Alarm_Recovery_Current;      	/*说明:*/
	uint8_t                           	m_FET_Alarm_Delay_Time;            	/*说明:*/
	uint8_t                           	m_FET_Alarm_Recovery_Time;         	/*说明:*/
	int16_t                           	m_FET_Knee_Temperature;            	/*说明:*/
	int16_t                           	m_FET_Final_Current;               	/*说明:*/
}S_Fast_OverCurrent_Protection;
#define D_Fast_Cell_Over_Current                          	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Over_Current
#define D_Fast_Cell_Delay_Time                            	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Delay_Time
#define D_Fast_Cell_Recovery_Time                         	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Recovery_Time
#define D_Fast_Cell_Alarm_Hold_Time                       	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Alarm_Hold_Time
#define D_Fast_Cell_Alarm_Delta_Current                   	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Alarm_Delta_Current
#define D_Fast_Cell_Alarm_Recovery_Current                	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Alarm_Recovery_Current
#define D_Fast_Cell_Alarm_Delay_Time                      	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Alarm_Delay_Time
#define D_Fast_Cell_Alarm_Recovery_Time                   	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Alarm_Recovery_Time
#define D_Fast_Cell_Knee_Temperature                      	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Knee_Temperature
#define D_Fast_Cell_Final_Current                         	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_Cell_Final_Current
#define D_Fast_FET_Over_Current                           	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Over_Current
#define D_Fast_FET_Delay_Time                             	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Delay_Time
#define D_Fast_FET_Recovery_Time                          	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Recovery_Time
#define D_Fast_FET_Alarm_Hold_Time                        	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Alarm_Hold_Time
#define D_Fast_FET_Alarm_Delta_Current                    	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Alarm_Delta_Current
#define D_Fast_FET_Alarm_Recovery_Current                 	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Alarm_Recovery_Current
#define D_Fast_FET_Alarm_Delay_Time                       	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Alarm_Delay_Time
#define D_Fast_FET_Alarm_Recovery_Time                    	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Alarm_Recovery_Time
#define D_Fast_FET_Knee_Temperature                       	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Knee_Temperature
#define D_Fast_FET_Final_Current                          	flashdata.b_Lenovo_Data.s_Fast_OverCurrent_Protection.m_FET_Final_Current

typedef struct{
	uint16_t                          	m_Total_Charged;                   	/*说明:*/
	uint16_t                          	m_Total_Time;                      	/*说明:*/
	uint16_t                          	m_HiVolt_Time;                     	/*说明:*/
	uint16_t                          	m_HiTemp_Time;                     	/*说明:*/
	uint16_t                          	m_HiTempVolt_Time;                 	/*说明:*/
	int16_t                           	m_Storage_High_Temp;               	/*说明:*/
	int16_t                           	m_Storage_High_Volt;               	/*说明:*/
}S_Lifetime_Storage_Data;
#define D_Lifetime_Total_Charged                          	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_Total_Charged
#define D_Lifetime_Total_Time                             	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_Total_Time
#define D_Lifetime_HiVolt_Time                            	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_HiVolt_Time
#define D_Lifetime_HiTemp_Time                            	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_HiTemp_Time
#define D_Lifetime_HiTempVolt_Time                        	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_HiTempVolt_Time
#define D_Lifetime_Storage_High_Temp                      	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_Storage_High_Temp
#define D_Lifetime_Storage_High_Volt                      	flashdata.b_Lenovo_Data.s_Lifetime_Storage_Data.m_Storage_High_Volt

typedef struct{
	uint8_t                           	m_Dual_mode_Status;                	/*说明:*/
	uint16_t                          	m_LS1_Start_Cycle_Count;           	/*说明:*/
	uint16_t                          	m_LS1_Start_Time;                  	/*说明:*/
	uint16_t                          	m_LS1_Delta_Time;                  	/*说明:*/
	int16_t                           	m_LS1_First_Volt_Drop;             	/*说明:*/
	int16_t                           	m_LS2_Second_Volt_Drop;            	/*说明:*/
	uint16_t                          	m_LS2_Start_Cycle_Count;           	/*说明:*/
	uint16_t                          	m_LS2_Star_Hi_Vol_Storag_Tim;      	/*说明:*/
	uint16_t                          	m_Age_Per_Month;                   	/*说明:*/
	int16_t                           	m_LS2_Second_Drop_FCC_Max;         	/*说明:*/
	uint16_t                          	m_LS1_Delta_Cycle_Count_2;         	/*说明:*/
	uint16_t                          	m_LS1_Delta_Cycle_Count_3;         	/*说明:*/
	uint16_t                          	m_LS1_Delta_Cycle_Count_4;         	/*说明:*/
	uint16_t                          	m_LS1_Delta_Cycle_Count_5;         	/*说明:*/
}S_Dual_Mode;
#define D_Dual_mode_Status                                	flashdata.b_Lenovo_Data.s_Dual_Mode.m_Dual_mode_Status
#define D_Dual_LS1_Start_Cycle_Count                      	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Start_Cycle_Count
#define D_Dual_LS1_Start_Time                             	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Start_Time
#define D_Dual_LS1_Delta_Time                             	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Delta_Time
#define D_Dual_LS1_First_Volt_Drop                        	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_First_Volt_Drop
#define D_Dual_LS2_Second_Volt_Drop                       	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS2_Second_Volt_Drop
#define D_Dual_LS2_Start_Cycle_Count                      	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS2_Start_Cycle_Count
#define D_Dual_LS2_Star_Hi_Vol_Storag_Tim                 	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS2_Star_Hi_Vol_Storag_Tim
#define D_Dual_Age_Per_Month                              	flashdata.b_Lenovo_Data.s_Dual_Mode.m_Age_Per_Month
#define D_Dual_LS2_Second_Drop_FCC_Max                    	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS2_Second_Drop_FCC_Max
#define D_Dual_LS1_Delta_Cycle_Count_2                    	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Delta_Cycle_Count_2
#define D_Dual_LS1_Delta_Cycle_Count_3                    	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Delta_Cycle_Count_3
#define D_Dual_LS1_Delta_Cycle_Count_4                    	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Delta_Cycle_Count_4
#define D_Dual_LS1_Delta_Cycle_Count_5                    	flashdata.b_Lenovo_Data.s_Dual_Mode.m_LS1_Delta_Cycle_Count_5

typedef struct{
	uint8_t                           	m_Cycle_Count;                     	/*说明:*/
}S_Set_FCC_Design_Capacity;
#define D_Set_Cycle_Count                                 	flashdata.b_Lenovo_Data.s_Set_FCC_Design_Capacity.m_Cycle_Count

typedef struct{
	uint16_t                          	m_HiVolt_Time_Threshold;           	/*说明:*/
}S_FCC_Report_DesCap_Threshold;
#define D_FCC_HiVolt_Time_Threshold                       	flashdata.b_Lenovo_Data.s_FCC_Report_DesCap_Threshold.m_HiVolt_Time_Threshold

typedef struct{
	uint8_t                           	m_TSF_Min;                         	/*说明:*/
	uint16_t                          	m_TSF_Max;                         	/*说明:*/
}S_Dual_Mode_TempVolt_Modifier;
#define D_Dual_TSF_Min                                    	flashdata.b_Lenovo_Data.s_Dual_Mode_TempVolt_Modifier.m_TSF_Min
#define D_Dual_TSF_Max                                    	flashdata.b_Lenovo_Data.s_Dual_Mode_TempVolt_Modifier.m_TSF_Max

typedef struct{
	uint16_t                          	m_Time_Spent_in_RT;                	/*说明:*/
	uint16_t                          	m_Time_Spent_In_LS1_1;             	/*说明:*/
	uint16_t                          	m_Time_Spent_In_LS1_2;             	/*说明:*/
	uint16_t                          	m_Time_Spent_In_LS1_3;             	/*说明:*/
	uint16_t                          	m_Time_Spent_In_LS1_4;             	/*说明:*/
	uint16_t                          	m_Time_Spent_In_LS1_5;             	/*说明:*/
	uint16_t                          	m_Time_Spent_in_LS2;               	/*说明:*/
	uint16_t                          	m_Adjusted_HiVolt_Time;            	/*说明:*/
}S_Lifetime_Timers;
#define D_Lifetime_Time_Spent_in_RT                       	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_in_RT
#define D_Lifetime_Time_Spent_In_LS1_1                    	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_In_LS1_1
#define D_Lifetime_Time_Spent_In_LS1_2                    	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_In_LS1_2
#define D_Lifetime_Time_Spent_In_LS1_3                    	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_In_LS1_3
#define D_Lifetime_Time_Spent_In_LS1_4                    	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_In_LS1_4
#define D_Lifetime_Time_Spent_In_LS1_5                    	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_In_LS1_5
#define D_Lifetime_Time_Spent_in_LS2                      	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Time_Spent_in_LS2
#define D_Lifetime_Adjusted_HiVolt_Time                   	flashdata.b_Lenovo_Data.s_Lifetime_Timers.m_Adjusted_HiVolt_Time

typedef struct{
	uint8_t                           	m_VSF_High;                        	/*说明:*/
	uint8_t                           	m_VSF_Med;                         	/*说明:*/
	uint8_t                           	m_VSF_Low;                         	/*说明:*/
	uint8_t                           	m_VSF_Default;                     	/*说明:*/
}S_LifeSpan_Volt_Modifier;
#define D_LifeSpan_VSF_High                               	flashdata.b_Lenovo_Data.s_LifeSpan_Volt_Modifier.m_VSF_High
#define D_LifeSpan_VSF_Med                                	flashdata.b_Lenovo_Data.s_LifeSpan_Volt_Modifier.m_VSF_Med
#define D_LifeSpan_VSF_Low                                	flashdata.b_Lenovo_Data.s_LifeSpan_Volt_Modifier.m_VSF_Low
#define D_LifeSpan_VSF_Default                            	flashdata.b_Lenovo_Data.s_LifeSpan_Volt_Modifier.m_VSF_Default

typedef struct{
	uint8_t                           	m_ManufacturerInfo[32];            	/*说明:*/
}S_Manufacturer_Data;
#define D_Manufacturer_ManufacturerInfo                   	flashdata.b_System_Data.s_Manufacturer_Data.m_ManufacturerInfo

typedef struct{
	uint8_t                           	m_Manufacturer_Info_B_Length;      	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B01;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B02;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B03;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B04;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B05;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B06;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B07;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B08;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B09;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B10;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B11;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B12;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B13;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B14;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B15;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B16;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B17;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B18;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B19;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B20;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B21;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B22;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B23;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B24;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B25;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B26;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B27;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B28;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B29;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B30;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B31;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_B32;           	/*说明:*/
}S_Manufacturer_Info_B;
#define D_Manufacturer_Info_B_Length                      	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B_Length
#define D_Manufacturer_Info_B01                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B01
#define D_Manufacturer_Info_B02                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B02
#define D_Manufacturer_Info_B03                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B03
#define D_Manufacturer_Info_B04                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B04
#define D_Manufacturer_Info_B05                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B05
#define D_Manufacturer_Info_B06                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B06
#define D_Manufacturer_Info_B07                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B07
#define D_Manufacturer_Info_B08                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B08
#define D_Manufacturer_Info_B09                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B09
#define D_Manufacturer_Info_B10                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B10
#define D_Manufacturer_Info_B11                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B11
#define D_Manufacturer_Info_B12                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B12
#define D_Manufacturer_Info_B13                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B13
#define D_Manufacturer_Info_B14                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B14
#define D_Manufacturer_Info_B15                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B15
#define D_Manufacturer_Info_B16                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B16
#define D_Manufacturer_Info_B17                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B17
#define D_Manufacturer_Info_B18                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B18
#define D_Manufacturer_Info_B19                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B19
#define D_Manufacturer_Info_B20                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B20
#define D_Manufacturer_Info_B21                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B21
#define D_Manufacturer_Info_B22                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B22
#define D_Manufacturer_Info_B23                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B23
#define D_Manufacturer_Info_B24                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B24
#define D_Manufacturer_Info_B25                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B25
#define D_Manufacturer_Info_B26                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B26
#define D_Manufacturer_Info_B27                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B27
#define D_Manufacturer_Info_B28                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B28
#define D_Manufacturer_Info_B29                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B29
#define D_Manufacturer_Info_B30                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B30
#define D_Manufacturer_Info_B31                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B31
#define D_Manufacturer_Info_B32                           	flashdata.b_System_Data.s_Manufacturer_Info_B.m_Manufacturer_Info_B32

typedef struct{
	uint8_t                           	m_Manufacturer_Info_C_Length;      	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C01;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C02;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C03;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C04;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C05;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C06;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C07;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C08;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C09;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C10;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C11;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C12;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C13;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C14;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C15;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C16;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C17;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C18;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C19;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C20;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C21;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C22;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C23;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C24;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C25;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C26;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C27;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C28;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C29;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C30;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C31;           	/*说明:*/
	uint8_t                           	m_Manufacturer_Info_C32;           	/*说明:*/
}S_Manufacturer_Info_C;
#define D_Manufacturer_Info_C_Length                      	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C_Length
#define D_Manufacturer_Info_C01                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C01
#define D_Manufacturer_Info_C02                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C02
#define D_Manufacturer_Info_C03                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C03
#define D_Manufacturer_Info_C04                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C04
#define D_Manufacturer_Info_C05                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C05
#define D_Manufacturer_Info_C06                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C06
#define D_Manufacturer_Info_C07                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C07
#define D_Manufacturer_Info_C08                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C08
#define D_Manufacturer_Info_C09                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C09
#define D_Manufacturer_Info_C10                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C10
#define D_Manufacturer_Info_C11                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C11
#define D_Manufacturer_Info_C12                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C12
#define D_Manufacturer_Info_C13                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C13
#define D_Manufacturer_Info_C14                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C14
#define D_Manufacturer_Info_C15                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C15
#define D_Manufacturer_Info_C16                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C16
#define D_Manufacturer_Info_C17                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C17
#define D_Manufacturer_Info_C18                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C18
#define D_Manufacturer_Info_C19                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C19
#define D_Manufacturer_Info_C20                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C20
#define D_Manufacturer_Info_C21                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C21
#define D_Manufacturer_Info_C22                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C22
#define D_Manufacturer_Info_C23                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C23
#define D_Manufacturer_Info_C24                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C24
#define D_Manufacturer_Info_C25                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C25
#define D_Manufacturer_Info_C26                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C26
#define D_Manufacturer_Info_C27                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C27
#define D_Manufacturer_Info_C28                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C28
#define D_Manufacturer_Info_C29                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C29
#define D_Manufacturer_Info_C30                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C30
#define D_Manufacturer_Info_C31                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C31
#define D_Manufacturer_Info_C32                           	flashdata.b_System_Data.s_Manufacturer_Info_C.m_Manufacturer_Info_C32

typedef struct{
	uint16_t                          	m_Static_DF_Signature;             	/*说明:*/
	uint16_t                          	m_Static_Chem_DF_Signature;        	/*说明:*/
	uint16_t                          	m_All_DF_Signature;                	/*说明:*/
}S_Integrity;
#define D_Integrity_Static_DF_Signature                   	flashdata.b_System_Data.s_Integrity.m_Static_DF_Signature
#define D_Integrity_Static_Chem_DF_Signature              	flashdata.b_System_Data.s_Integrity.m_Static_Chem_DF_Signature
#define D_Integrity_All_DF_Signature                      	flashdata.b_System_Data.s_Integrity.m_All_DF_Signature

typedef struct{
	uint8_t                           	m_US_KEY1;                         	/*说明:*/
	uint8_t                           	m_US_KEY2;                         	/*说明:*/
	uint8_t                           	m_US_KEY3;                         	/*说明:*/
	uint8_t                           	m_US_KEY4;                         	/*说明:*/
}S_US;
#define D_US_KEY1                                         	flashdata.b_UNSeal.s_US.m_US_KEY1
#define D_US_KEY2                                         	flashdata.b_UNSeal.s_US.m_US_KEY2
#define D_US_KEY3                                         	flashdata.b_UNSeal.s_US.m_US_KEY3
#define D_US_KEY4                                         	flashdata.b_UNSeal.s_US.m_US_KEY4

typedef struct{
	uint8_t                           	m_FA_KEY1;                         	/*说明:*/
	uint8_t                           	m_FA_KEY2;                         	/*说明:*/
	uint8_t                           	m_FA_KEY3;                         	/*说明:*/
	uint8_t                           	m_FA_KEY4;                         	/*说明:*/
}S_FA;
#define D_FA_KEY1                                         	flashdata.b_UNSeal.s_FA.m_FA_KEY1
#define D_FA_KEY2                                         	flashdata.b_UNSeal.s_FA.m_FA_KEY2
#define D_FA_KEY3                                         	flashdata.b_UNSeal.s_FA.m_FA_KEY3
#define D_FA_KEY4                                         	flashdata.b_UNSeal.s_FA.m_FA_KEY4

typedef struct{
	Control_flag_1                    	m_Control_flag_1;                  	/*说明:*/
}S_Control_flag;


typedef struct{
	uint16_t                   	m_FCC_max_limit ;                  	/*说明:*/
	uint16_t                   	m_FCC_min_limit ;                  	/*说明:*/
}S_FCC_limit;
#define D_FCCMAXLIMIT                                       	flashdata.b_Algorithm_limit.s_FCC_limit.m_FCC_max_limit
#define D_FCCMINLIMIT                                       	flashdata.b_Algorithm_limit.s_FCC_limit.m_FCC_min_limit

typedef struct{
	uint16_t                   	m_5_10_limit ;                  	/*说明:*/
	uint16_t                   	m_5_limit ;                  	/*说明:*/
}S_Voltage_limit;
#define D_5_10_LIMIT                                       	flashdata.b_Algorithm_limit.s_Voltage_limit.m_5_10_limit
#define D_5_LIMIT                                       	flashdata.b_Algorithm_limit.s_Voltage_limit.m_5_limit

typedef struct{
	int8_t  temper_limit_t1 ;
	int8_t  temper_limit_t2 ;
	uint16_t  temper_limit_cap1 ;
	uint16_t  temper_limit_cap2 ;
}S_Temper_Cap_limit ;



// typedef struct{
// 	int8_t  temper_limit_t1 ;
// 	int8_t  temper_limit_t2 ;
// 	uint16_t  temper_limit_cap1 ;
// 	uint16_t  temper_limit_cap2 ;
// }B_Temper_Cap_limit ;

// #define 		TEMPER_LIMIT_T1       flashdata.b_Temper_limit.temper_limit_t1                   //
// #define 		TEMPER_LIMIT_T2       flashdata.b_Temper_limit.temper_limit_t2                  //
// #define 		TEMPER_LIMIT_CAP1       flashdata.b_Temper_limit.temper_limit_cap1                   //
// #define 		TEMPER_LIMIT_CAP2      flashdata.b_Temper_limit.temper_limit_cap2                  //

typedef struct{
	uint32_t                          	m_FlashWriteTimes;                 	/*说明:*/
	uint16_t                          	m_MaxLoadCurrent;                  	/*说明:*/
	uint16_t                          	m_MaxLoadTimeToEmpty;              	/*说明:*/
	uint16_t                          	m_RSOC;                            	/*说明:*/
	uint16_t                          	m_ASOC;                            	/*说明:*/
	uint16_t                          	m_Remainingcapacity;               	/*说明:*/
	uint16_t                          	m_FullChargeCapacity;              	/*说明:*/
	uint16_t                          	m_SOH;                             	/*说明:*/
	uint16_t                          	m_CycleCount;                      	/*说明:*/
	uint16_t                          	m_QmaxUpdateCycle;                 	/*说明:*/
	uint16_t                          	m_Qmax;                            	/*说明:*/
    uint16_t                          	m_QmaxCell0;                            	/*说明:*/
    uint16_t                          	m_QmaxCell1;                            	/*说明:*/
	uint16_t                          	m_QmaxCell2;                            	/*说明:*/
    uint16_t                          	m_QmaxCell3;                            	/*说明:*/
	uint16_t                          	m_ChargingVoltage;                 	/*说明:*/
	uint16_t                          	m_ChargingCurrent;                 	/*说明:*/
	uint16_t                          	m_ChargeToFullTimes;               	/*说明:*/
	uint16_t                          	m_MaxError;                        	/*说明:*/
	uint16_t                          	m_BatteryMode;                     	/*说明:*/
	uint16_t                          	m_BatteryStatus;                   	/*说明:*/
	uint32_t                          	m_ChargingStatus;                  	/*说明:*/
	uint32_t                          	m_GaugingStatus;                   	/*说明:*/
	uint32_t                          	m_OperationStatus;                 	/*说明:*/
	uint32_t                          	m_SafetyStatus;                    	/*说明:*/
	uint32_t                          	m_PFStatus;                        	/*说明:*/
	uint16_t                          	m_TempRange;                       	/*说明:*/
	uint16_t                          	m_ManufacturingStatus;             	/*说明:*/
	uint16_t                          	m_BalanceStatus;                   	/*说明:*/
	uint16_t                          	m_SleepTime;                       	/*说明:*/
	uint16_t                          	m_ResetTimes;                      	/*说明:*/
	int32_t                           	m_lrc_w;                           	/*说明:*/
	uint16_t                          	m_tcc_cnt;                         	/*说明:*/
	uint16_t                          	m_trek_cnt;                        	/*说明:*/
	int32_t                           	m_Del_lrc;                         	/*说明:*/
	int32_t                           	m_Ilrc_w;                          	/*说明:*/
	uint16_t                          	m_IdealFCC;                        	/*说明:*/
	uint16_t                          	m_IdealRC;                         	/*说明:*/
	uint16_t                          	m_IRsoc;                           	/*说明:*/
	uint16_t                          	m_Chargefactor;                    	/*说明:*/
	uint16_t                          	m_Dischargefactor;                 	/*说明:*/
	uint16_t                          	m_Seal_count;                      	/*说明:*/
	uint16_t                          	m_ShutDown_Mode;                    	/*说明:*/
}Record;
#define Record_FlashWriteTimes                          	t_record.m_FlashWriteTimes
#define Record_MaxLoadCurrent                           	t_record.m_MaxLoadCurrent
#define Record_MaxLoadTimeToEmpty                       	t_record.m_MaxLoadTimeToEmpty
#define Record_RSOC                                     	t_record.m_RSOC
#define Record_ASOC                                     	t_record.m_ASOC
#define Record_Remainingcapacity                        	t_record.m_Remainingcapacity
#define Record_FullChargeCapacity                       	t_record.m_FullChargeCapacity
#define Record_SOH                                      	t_record.m_SOH
#define Record_CycleCount                               	t_record.m_CycleCount
#define Record_QmaxUpdateCycle                          	t_record.m_QmaxUpdateCycle
#define Record_Qmax                                     	t_record.m_Qmax
#define Record_QmaxCell0                                 	t_record.m_QmaxCell0
#define Record_QmaxCell1                                 	t_record.m_QmaxCell1
#define Record_QmaxCell2                                 	t_record.m_QmaxCell2
#define Record_QmaxCell3                                 	t_record.m_QmaxCell3
#define Record_ChargingVoltage                          	t_record.m_ChargingVoltage
#define Record_ChargingCurrent                          	t_record.m_ChargingCurrent
#define Record_ChargeToFullTimes                        	t_record.m_ChargeToFullTimes
#define Record_MaxError                                 	t_record.m_MaxError
#define Record_BatteryMode                              	t_record.m_BatteryMode
#define Record_BatteryStatus                            	t_record.m_BatteryStatus
#define Record_ChargingStatus                           	t_record.m_ChargingStatus
#define Record_GaugingStatus                            	t_record.m_GaugingStatus
#define Record_OperationStatus                          	t_record.m_OperationStatus
#define Record_SafetyStatus                             	t_record.m_SafetyStatus
#define Record_PFStatus                                 	t_record.m_PFStatus
#define Record_TempRange                                	t_record.m_TempRange
#define Record_ManufacturingStatus                      	t_record.m_ManufacturingStatus
#define Record_BalanceStatus                            	t_record.m_BalanceStatus
#define Record_SleepTime                                	t_record.m_SleepTime
#define Record_ResetTimes                               	t_record.m_ResetTimes
#define Record_lrc_w                                    	t_record.m_lrc_w
#define Record_tcc_cnt                                  	t_record.m_tcc_cnt
#define Record_trek_cnt                                 	t_record.m_trek_cnt
#define Record_Del_lrc                                  	t_record.m_Del_lrc
#define Record_Ilrc_w                                   	t_record.m_Ilrc_w
#define Record_IdealFCC                                 	t_record.m_IdealFCC
#define Record_IdealRC                                  	t_record.m_IdealRC
#define Record_IRsoc                                    	t_record.m_IRsoc
#define Record_Chargefactor                             	t_record.m_Chargefactor
#define Record_Dischargefactor                          	t_record.m_Dischargefactor
#define Record_Seal_count                               	t_record.m_Seal_count
#define Record_ShutDown_Mode                            	t_record.m_ShutDown_Mode

typedef struct{
	uint16_t                          	m_Cell_1_Max_Voltage;              	/*说明:*/
	uint16_t                          	m_Cell_2_Max_Voltage;              	/*说明:*/
	int16_t                           	m_Cell_3_Max_Voltage;              	/*说明:*/
	int16_t                           	m_Cell_4_Max_Voltage;              	/*说明:*/
	int16_t                           	m_Cell_1_Min_Voltage;              	/*说明:*/
	int16_t                           	m_Cell_2_Min_Voltage;              	/*说明:*/
	int16_t                           	m_Cell_3_Min_Voltage;              	/*说明:*/
	uint16_t                          	m_Cell_4_Min_Voltage;              	/*说明:*/
	uint16_t                          	m_Max_Delta_Cell_Voltage;          	/*说明:*/
	int16_t                           	m_Max_Charge_Current;              	/*说明:*/
	int16_t                           	m_Max_Discharge_Current;           	/*说明:*/
	int16_t                           	m_Max_Avg_Dsg_Current;             	/*说明:*/
	int16_t                           	m_Max_Avg_Dsg_Power;               	/*说明:*/
	int8_t                            	m_Max_Temp_Cell;                   	/*说明:*/
	int8_t                           	m_Min_Temp_Cell;                   	/*说明:*/
	int8_t                            	m_Max_Temp_MOS;                    	/*说明:*/
	int8_t                            	m_Min_Temp_MOS;                    	/*说明:*/
	uint8_t                           	m_Max_Delta_Cell_Temp;             	/*说明:*/
	int8_t                           	m_Max_Temp_Int_Sensor;             	/*说明:*/
	int8_t                           	m_Min_Temp_Int_Sensor;             	/*说明:*/
	int8_t                           	m_Max_Temp_Fet;                    	/*说明:*/
	uint16_t                          	m_No_Of_COV_Events;                	/*说明:*/
	uint16_t                          	m_Last_COV_Event;                  	/*说明:*/
	uint16_t                          	m_No_Of_CUV_Events;                	/*说明:*/
	uint16_t                          	m_Last_CUV_Event;                  	/*说明:*/
	uint16_t                          	m_No_Of_OCD1_Events;               	/*说明:*/
	uint16_t                          	m_Last_OCD1_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_OCD2_Events;               	/*说明:*/
	uint16_t                          	m_Last_OCD2_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_OCC1_Events;               	/*说明:*/
	uint16_t                          	m_Last_OCC1_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_OCC2_Events;               	/*说明:*/
	uint16_t                          	m_Last_OCC2_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_AOLD_Events;               	/*说明:*/
	uint16_t                          	m_Last_AOLD_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_ASCD_Events;               	/*说明:*/
	uint16_t                          	m_Last_ASCD_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_ASCC_Events;               	/*说明:*/
	uint16_t                          	m_Last_ASCC_Event;                 	/*说明:*/
	uint16_t                          	m_No_Of_OTC_Events;                	/*说明:*/
	uint16_t                          	m_Last_OTC_Event;                  	/*说明:*/
	uint16_t                          	m_No_Of_OTD_Events;                	/*说明:*/
	uint16_t                          	m_Last_OTD_Event;                  	/*说明:*/
	uint16_t                          	m_No_Of_OTF_Events;                	/*说明:*/
	uint16_t                          	m_Last_OTF_Event;                  	/*说明:*/
	uint16_t                          	m_No_Valid_Charge_Term;            	/*说明:*/
	uint16_t                          	m_Last_Valid_Charge_Term;          	/*说明:*/
	uint16_t                          	m_No_Of_Qmax_Updates;              	/*说明:*/
	uint16_t                          	m_Last_Qmax_Update;                	/*说明:*/
	uint16_t                          	m_No_Of_Ra_Updates;                	/*说明:*/
	uint16_t                          	m_Last_Ra_Update;                  	/*说明:*/
	uint16_t                          	m_No_Of_Ra_Disable;                	/*说明:*/
	uint16_t                          	m_Last_Ra_Disable;                 	/*说明:*/
	uint8_t                           	m_No_of_Shutdowns;                 	/*说明:*/
	uint32_t                          	m_CB_Time_Cell_1;                  	/*说明:*/
	uint32_t                          	m_CB_Time_Cell_2;                  	/*说明:*/
	uint32_t                          	m_CB_Time_Cell_3;                  	/*说明:*/
	uint32_t                          	m_CB_Time_Cell_4;                  	/*说明:*/
	uint32_t                          	m_Total_Firmware_Runtime;          	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_A;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_B;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_C;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_D;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_E;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_F;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_UT_RSOC_G;         	/*说明:*/

	uint32_t                          	m_Time_Spent_in_LT_RSOC_A;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_LT_RSOC_B;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_LT_RSOC_C;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_LT_RSOC_D;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_LT_RSOC_E;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_LT_RSOC_F;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_LT_RSOC_G;         	/*说明:*/
	
	uint32_t                          	m_Time_Spent_in_STL_RSOC_A;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STL_RSOC_B;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STL_RSOC_C;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STL_RSOC_D;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STL_RSOC_E;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STL_RSOC_F;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STL_RSOC_G;        	/*说明:*/

	uint32_t                          	m_Time_Spent_in_RT_RSOC_A;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_RT_RSOC_B;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_RT_RSOC_C;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_RT_RSOC_D;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_RT_RSOC_E;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_RT_RSOC_F;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_RT_RSOC_G;         	/*说明:*/

	uint32_t                          	m_Time_Spent_in_STH_RSOC_A;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STH_RSOC_B;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STH_RSOC_C;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STH_RSOC_D;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STH_RSOC_E;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STH_RSOC_F;        	/*说明:*/
	uint32_t                          	m_Time_Spent_in_STH_RSOC_G;        	/*说明:*/

	uint32_t                          	m_Time_Spent_in_HT_RSOC_A;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_HT_RSOC_B;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_HT_RSOC_C;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_HT_RSOC_D;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_HT_RSOC_E;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_HT_RSOC_F;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_HT_RSOC_G;         	/*说明:*/

	uint32_t                          	m_Time_Spent_in_OT_RSOC_A;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_OT_RSOC_B;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_OT_RSOC_C;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_OT_RSOC_D;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_OT_RSOC_E;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_OT_RSOC_F;         	/*说明:*/
	uint32_t                          	m_Time_Spent_in_OT_RSOC_G;         	/*说明:*/
	
	uint8_t                           	m_Safety_Alert_A;                  	/*说明:*/
	uint8_t                           	m_Safety_Status_A;                 	/*说明:*/
	uint8_t                           	m_Safety_Alert_B;                  	/*说明:*/
	uint8_t                           	m_Safety_Status_B;                 	/*说明:*/
	uint8_t                           	m_Safety_Alert_C;                  	/*说明:*/
	uint8_t                           	m_Safety_Status_C;                 	/*说明:*/
	uint8_t                           	m_Safety_Alert_D;                  	/*说明:*/
	uint8_t                           	m_Safety_Status_D;                 	/*说明:*/
	uint8_t                           	m_PF_Alert_A;                      	/*说明:*/
	uint8_t                           	m_PF_Status_A;                     	/*说明:*/
	uint8_t                           	m_PF_Alert_B;                      	/*说明:*/
	uint8_t                           	m_PF_Status_B;                     	/*说明:*/
	uint8_t                           	m_PF_Alert_C;                      	/*说明:*/
	uint8_t                           	m_PF_Status_C;                     	/*说明:*/
	uint8_t                           	m_PF_Alert_D;                      	/*说明:*/
	uint8_t                           	m_PF_Status_D;                     	/*说明:*/
	//uint16_t                          	m_Fuse_Flag;                       	/*说明:*/
	uint16_t                          	m_Operation_Status_A;              	/*说明:*/
	uint16_t                          	m_Operation_Status_B;              	/*说明:*/
	uint8_t                           	m_Temp_Range;                      	/*说明:*/
	uint8_t                           	m_Charging_Status_A;               	/*说明:*/
	uint8_t                           	m_Charging_Status_B;               	/*说明:*/
	uint8_t                           	m_Gauging_Status;                  	/*说明:*/
	uint16_t                          	m_IT_Status;                       	/*说明:*/
	uint16_t                          	m_Cell_1_Voltage;                  	/*说明:*/
	uint16_t                          	m_Cell_2_Voltage;                  	/*说明:*/
	uint16_t                          	m_Cell_3_Voltage;                  	/*说明:*/
	uint16_t                          	m_Cell_4_Voltage;                  	/*说明:*/
	uint16_t                          	m_Battery_Direct_Voltage;          	/*说明:*/
	uint16_t                          	m_Pack_Voltage;                    	/*说明:*/
	uint16_t                          	m_Current;                         	/*说明:*/
	uint16_t                          	m_Internal_Temperature;            	/*说明:*/
	uint16_t                          	m_External_1_Temperature;          	/*说明:*/
	uint16_t                          	m_External_2_Temperature;          	/*说明:*/
	uint16_t                          	m_External_3_Temperature;          	/*说明:*/
	uint16_t                          	m_External_4_Temperature;          	/*说明:*/
	uint8_t                           	m_1st_Status_Status_A;             	/*说明:*/
	uint8_t                           	m_1st_Status_Status_B;             	/*说明:*/
	uint8_t                           	m_1st_Status_Status_C;             	/*说明:*/
	uint8_t                           	m_1st_Status_Status_D;             	/*说明:*/
	uint32_t                           	m_1st_Time_to_Next_Event;          	/*说明:*/
	uint8_t                           	m_2st_Status_Status_A;             	/*说明:*/
	uint8_t                           	m_2st_Status_Status_B;             	/*说明:*/
	uint8_t                           	m_2st_Status_Status_C;             	/*说明:*/
	uint8_t                           	m_2st_Status_Status_D;             	/*说明:*/
	uint32_t                           	m_2st_Time_to_Next_Event;          	/*说明:*/
	uint8_t                           	m_3st_Status_Status_A;             	/*说明:*/
	uint8_t                           	m_3st_Status_Status_B;             	/*说明:*/
	uint8_t                           	m_3st_Status_Status_C;             	/*说明:*/
	uint8_t                           	m_3st_Status_Status_D;             	/*说明:*/
	uint32_t                           	m_3st_Time_to_Next_Event;          	/*说明:*/
	uint8_t                           	m_1st_PF_Status_A;                 	/*说明:*/
	uint8_t                           	m_1st_PF_Status_B;                 	/*说明:*/
	uint8_t                           	m_1st_PF_Status_C;                 	/*说明:*/
	uint8_t                           	m_1st_PF_Status_D;                 	/*说明:*/
	uint8_t                           	m_2st_PF_Status_A;                 	/*说明:*/
	uint8_t                           	m_2st_PF_Status_B;                 	/*说明:*/
	uint8_t                           	m_2st_PF_Status_C;                 	/*说明:*/
	uint8_t                           	m_2st_PF_Status_D;                 	/*说明:*/
	uint8_t                           	m_3st_PF_Status_A;                 	/*说明:*/
	uint8_t                           	m_3st_PF_Status_B;                 	/*说明:*/
	uint8_t                           	m_3st_PF_Status_C;                 	/*说明:*/
	uint8_t                           	m_3st_PF_Status_D;                 	/*说明:*/
	uint16_t                            m_Pi_Mode_Count;
}LifeTimes;
#define LifeTimes_Cell_1_Max_Voltage                    	l_lifetimes.m_Cell_1_Max_Voltage
#define LifeTimes_Cell_2_Max_Voltage                    	l_lifetimes.m_Cell_2_Max_Voltage
#define LifeTimes_Cell_3_Max_Voltage                    	l_lifetimes.m_Cell_3_Max_Voltage
#define LifeTimes_Cell_4_Max_Voltage                    	l_lifetimes.m_Cell_4_Max_Voltage
#define LifeTimes_Cell_1_Min_Voltage                    	l_lifetimes.m_Cell_1_Min_Voltage
#define LifeTimes_Cell_2_Min_Voltage                    	l_lifetimes.m_Cell_2_Min_Voltage
#define LifeTimes_Cell_3_Min_Voltage                    	l_lifetimes.m_Cell_3_Min_Voltage
#define LifeTimes_Cell_4_Min_Voltage                    	l_lifetimes.m_Cell_4_Min_Voltage
#define LifeTimes_Max_Delta_Cell_Voltage                	l_lifetimes.m_Max_Delta_Cell_Voltage
#define LifeTimes_Max_Charge_Current                    	l_lifetimes.m_Max_Charge_Current
#define LifeTimes_Max_Discharge_Current                 	l_lifetimes.m_Max_Discharge_Current
#define LifeTimes_Max_Avg_Dsg_Current                   	l_lifetimes.m_Max_Avg_Dsg_Current
#define LifeTimes_Max_Avg_Dsg_Power                     	l_lifetimes.m_Max_Avg_Dsg_Power
#define LifeTimes_Max_Temp_Cell                         	l_lifetimes.m_Max_Temp_Cell
#define LifeTimes_Min_Temp_Cell                         	l_lifetimes.m_Min_Temp_Cell
#define LifeTimes_Max_Temp_MOS                          	l_lifetimes.m_Max_Temp_MOS
#define LifeTimes_Min_Temp_MOS                          	l_lifetimes.m_Min_Temp_MOS
#define LifeTimes_Max_Delta_Cell_Temp                   	l_lifetimes.m_Max_Delta_Cell_Temp
#define LifeTimes_Max_Temp_Int_Sensor                   	l_lifetimes.m_Max_Temp_Int_Sensor
#define LifeTimes_Min_Temp_Int_Sensor                   	l_lifetimes.m_Min_Temp_Int_Sensor
#define LifeTimes_Max_Temp_Fet                          	l_lifetimes.m_Max_Temp_Fet
#define LifeTimes_No_Of_COV_Events                      	l_lifetimes.m_No_Of_COV_Events
#define LifeTimes_Last_COV_Event                        	l_lifetimes.m_Last_COV_Event
#define LifeTimes_No_Of_CUV_Events                      	l_lifetimes.m_No_Of_CUV_Events
#define LifeTimes_Last_CUV_Event                        	l_lifetimes.m_Last_CUV_Event
#define LifeTimes_No_Of_OCD1_Events                     	l_lifetimes.m_No_Of_OCD1_Events
#define LifeTimes_Last_OCD1_Event                       	l_lifetimes.m_Last_OCD1_Event
#define LifeTimes_No_Of_OCD2_Events                     	l_lifetimes.m_No_Of_OCD2_Events
#define LifeTimes_Last_OCD2_Event                       	l_lifetimes.m_Last_OCD2_Event
#define LifeTimes_No_Of_OCC1_Events                     	l_lifetimes.m_No_Of_OCC1_Events
#define LifeTimes_Last_OCC1_Event                       	l_lifetimes.m_Last_OCC1_Event
#define LifeTimes_No_Of_OCC2_Events                     	l_lifetimes.m_No_Of_OCC2_Events
#define LifeTimes_Last_OCC2_Event                       	l_lifetimes.m_Last_OCC2_Event
#define LifeTimes_No_Of_AOLD_Events                     	l_lifetimes.m_No_Of_AOLD_Events
#define LifeTimes_Last_AOLD_Event                       	l_lifetimes.m_Last_AOLD_Event
#define LifeTimes_No_Of_ASCD_Events                     	l_lifetimes.m_No_Of_ASCD_Events
#define LifeTimes_Last_ASCD_Event                       	l_lifetimes.m_Last_ASCD_Event
#define LifeTimes_No_Of_ASCC_Events                     	l_lifetimes.m_No_Of_ASCC_Events
#define LifeTimes_Last_ASCC_Event                       	l_lifetimes.m_Last_ASCC_Event
#define LifeTimes_No_Of_OTC_Events                      	l_lifetimes.m_No_Of_OTC_Events
#define LifeTimes_Last_OTC_Event                        	l_lifetimes.m_Last_OTC_Event
#define LifeTimes_No_Of_OTD_Events                      	l_lifetimes.m_No_Of_OTD_Events
#define LifeTimes_Last_OTD_Event                        	l_lifetimes.m_Last_OTD_Event
#define LifeTimes_No_Of_OTF_Events                      	l_lifetimes.m_No_Of_OTF_Events
#define LifeTimes_Last_OTF_Event                        	l_lifetimes.m_Last_OTF_Event
#define LifeTimes_No_Valid_Charge_Term                  	l_lifetimes.m_No_Valid_Charge_Term
#define LifeTimes_Last_Valid_Charge_Term                	l_lifetimes.m_Last_Valid_Charge_Term
#define LifeTimes_No_Of_Qmax_Updates                    	l_lifetimes.m_No_Of_Qmax_Updates
#define LifeTimes_Last_Qmax_Update                      	l_lifetimes.m_Last_Qmax_Update
#define LifeTimes_No_Of_Ra_Updates                      	l_lifetimes.m_No_Of_Ra_Updates
#define LifeTimes_Last_Ra_Update                        	l_lifetimes.m_Last_Ra_Update
#define LifeTimes_No_Of_Ra_Disable                      	l_lifetimes.m_No_Of_Ra_Disable
#define LifeTimes_Last_Ra_Disable                       	l_lifetimes.m_Last_Ra_Disable
#define LifeTimes_No_of_Shutdowns                       	l_lifetimes.m_No_of_Shutdowns
#define LifeTimes_CB_Time_Cell_1                        	l_lifetimes.m_CB_Time_Cell_1
#define LifeTimes_CB_Time_Cell_2                        	l_lifetimes.m_CB_Time_Cell_2
#define LifeTimes_CB_Time_Cell_3                        	l_lifetimes.m_CB_Time_Cell_3
#define LifeTimes_CB_Time_Cell_4                        	l_lifetimes.m_CB_Time_Cell_4
#define LifeTimes_Total_Firmware_Runtime                	l_lifetimes.m_Total_Firmware_Runtime
#define LifeTimes_Time_Spent_in_UT_RSOC_A               	l_lifetimes.m_Time_Spent_in_UT_RSOC_A
#define LifeTimes_Time_Spent_in_UT_RSOC_B               	l_lifetimes.m_Time_Spent_in_UT_RSOC_B
#define LifeTimes_Time_Spent_in_UT_RSOC_C               	l_lifetimes.m_Time_Spent_in_UT_RSOC_C
#define LifeTimes_Time_Spent_in_UT_RSOC_D               	l_lifetimes.m_Time_Spent_in_UT_RSOC_D
#define LifeTimes_Time_Spent_in_UT_RSOC_E               	l_lifetimes.m_Time_Spent_in_UT_RSOC_E
#define LifeTimes_Time_Spent_in_UT_RSOC_F               	l_lifetimes.m_Time_Spent_in_UT_RSOC_F
#define LifeTimes_Time_Spent_in_UT_RSOC_G               	l_lifetimes.m_Time_Spent_in_UT_RSOC_G

#define LifeTimes_Time_Spent_in_LT_RSOC_A               	l_lifetimes.m_Time_Spent_in_LT_RSOC_A
#define LifeTimes_Time_Spent_in_LT_RSOC_B               	l_lifetimes.m_Time_Spent_in_LT_RSOC_B
#define LifeTimes_Time_Spent_in_LT_RSOC_C               	l_lifetimes.m_Time_Spent_in_LT_RSOC_C
#define LifeTimes_Time_Spent_in_LT_RSOC_D               	l_lifetimes.m_Time_Spent_in_LT_RSOC_D
#define LifeTimes_Time_Spent_in_LT_RSOC_E               	l_lifetimes.m_Time_Spent_in_LT_RSOC_E
#define LifeTimes_Time_Spent_in_LT_RSOC_F               	l_lifetimes.m_Time_Spent_in_LT_RSOC_F
#define LifeTimes_Time_Spent_in_LT_RSOC_G               	l_lifetimes.m_Time_Spent_in_LT_RSOC_G

#define LifeTimes_Time_Spent_in_STL_RSOC_A              	l_lifetimes.m_Time_Spent_in_STL_RSOC_A
#define LifeTimes_Time_Spent_in_STL_RSOC_B              	l_lifetimes.m_Time_Spent_in_STL_RSOC_B
#define LifeTimes_Time_Spent_in_STL_RSOC_C              	l_lifetimes.m_Time_Spent_in_STL_RSOC_C
#define LifeTimes_Time_Spent_in_STL_RSOC_D              	l_lifetimes.m_Time_Spent_in_STL_RSOC_D
#define LifeTimes_Time_Spent_in_STL_RSOC_E              	l_lifetimes.m_Time_Spent_in_STL_RSOC_E
#define LifeTimes_Time_Spent_in_STL_RSOC_F              	l_lifetimes.m_Time_Spent_in_STL_RSOC_F
#define LifeTimes_Time_Spent_in_STL_RSOC_G              	l_lifetimes.m_Time_Spent_in_STL_RSOC_G

#define LifeTimes_Time_Spent_in_RT_RSOC_A               	l_lifetimes.m_Time_Spent_in_RT_RSOC_A
#define LifeTimes_Time_Spent_in_RT_RSOC_B               	l_lifetimes.m_Time_Spent_in_RT_RSOC_B
#define LifeTimes_Time_Spent_in_RT_RSOC_C               	l_lifetimes.m_Time_Spent_in_RT_RSOC_C
#define LifeTimes_Time_Spent_in_RT_RSOC_D               	l_lifetimes.m_Time_Spent_in_RT_RSOC_D
#define LifeTimes_Time_Spent_in_RT_RSOC_E               	l_lifetimes.m_Time_Spent_in_RT_RSOC_E
#define LifeTimes_Time_Spent_in_RT_RSOC_F               	l_lifetimes.m_Time_Spent_in_RT_RSOC_F
#define LifeTimes_Time_Spent_in_RT_RSOC_G               	l_lifetimes.m_Time_Spent_in_RT_RSOC_G

#define LifeTimes_Time_Spent_in_STH_RSOC_A              	l_lifetimes.m_Time_Spent_in_STH_RSOC_A
#define LifeTimes_Time_Spent_in_STH_RSOC_B              	l_lifetimes.m_Time_Spent_in_STH_RSOC_B
#define LifeTimes_Time_Spent_in_STH_RSOC_C              	l_lifetimes.m_Time_Spent_in_STH_RSOC_C
#define LifeTimes_Time_Spent_in_STH_RSOC_D              	l_lifetimes.m_Time_Spent_in_STH_RSOC_D
#define LifeTimes_Time_Spent_in_STH_RSOC_E              	l_lifetimes.m_Time_Spent_in_STH_RSOC_E
#define LifeTimes_Time_Spent_in_STH_RSOC_F              	l_lifetimes.m_Time_Spent_in_STH_RSOC_F
#define LifeTimes_Time_Spent_in_STH_RSOC_G              	l_lifetimes.m_Time_Spent_in_STH_RSOC_G

#define LifeTimes_Time_Spent_in_HT_RSOC_A               	l_lifetimes.m_Time_Spent_in_HT_RSOC_A
#define LifeTimes_Time_Spent_in_HT_RSOC_B               	l_lifetimes.m_Time_Spent_in_HT_RSOC_B
#define LifeTimes_Time_Spent_in_HT_RSOC_C               	l_lifetimes.m_Time_Spent_in_HT_RSOC_C
#define LifeTimes_Time_Spent_in_HT_RSOC_D               	l_lifetimes.m_Time_Spent_in_HT_RSOC_D
#define LifeTimes_Time_Spent_in_HT_RSOC_E               	l_lifetimes.m_Time_Spent_in_HT_RSOC_E
#define LifeTimes_Time_Spent_in_HT_RSOC_F               	l_lifetimes.m_Time_Spent_in_HT_RSOC_F
#define LifeTimes_Time_Spent_in_HT_RSOC_G               	l_lifetimes.m_Time_Spent_in_HT_RSOC_G

#define LifeTimes_Time_Spent_in_OT_RSOC_A               	l_lifetimes.m_Time_Spent_in_OT_RSOC_A
#define LifeTimes_Time_Spent_in_OT_RSOC_B               	l_lifetimes.m_Time_Spent_in_OT_RSOC_B
#define LifeTimes_Time_Spent_in_OT_RSOC_C               	l_lifetimes.m_Time_Spent_in_OT_RSOC_C
#define LifeTimes_Time_Spent_in_OT_RSOC_D               	l_lifetimes.m_Time_Spent_in_OT_RSOC_D
#define LifeTimes_Time_Spent_in_OT_RSOC_E               	l_lifetimes.m_Time_Spent_in_OT_RSOC_E
#define LifeTimes_Time_Spent_in_OT_RSOC_F               	l_lifetimes.m_Time_Spent_in_OT_RSOC_F
#define LifeTimes_Time_Spent_in_OT_RSOC_G               	l_lifetimes.m_Time_Spent_in_OT_RSOC_G
#define LifeTimes_Safety_Alert_A                        	l_lifetimes.m_Safety_Alert_A
#define LifeTimes_Safety_Status_A                       	l_lifetimes.m_Safety_Status_A
#define LifeTimes_Safety_Alert_B                        	l_lifetimes.m_Safety_Alert_B
#define LifeTimes_Safety_Status_B                       	l_lifetimes.m_Safety_Status_B
#define LifeTimes_Safety_Alert_C                        	l_lifetimes.m_Safety_Alert_C
#define LifeTimes_Safety_Status_C                       	l_lifetimes.m_Safety_Status_C
#define LifeTimes_Safety_Alert_D                        	l_lifetimes.m_Safety_Alert_D
#define LifeTimes_Safety_Status_D                       	l_lifetimes.m_Safety_Status_D
#define LifeTimes_PF_Alert_A                            	l_lifetimes.m_PF_Alert_A
#define LifeTimes_PF_Status_A                           	l_lifetimes.m_PF_Status_A
#define LifeTimes_PF_Alert_B                            	l_lifetimes.m_PF_Alert_B
#define LifeTimes_PF_Status_B                           	l_lifetimes.m_PF_Status_B
#define LifeTimes_PF_Alert_C                            	l_lifetimes.m_PF_Alert_C
#define LifeTimes_PF_Status_C                           	l_lifetimes.m_PF_Status_C
#define LifeTimes_PF_Alert_D                            	l_lifetimes.m_PF_Alert_D
#define LifeTimes_PF_Status_D                           	l_lifetimes.m_PF_Status_D
//#define LifeTimes_Fuse_Flag                             	l_lifetimes.m_Fuse_Flag
#define LifeTimes_Operation_Status_A                    	l_lifetimes.m_Operation_Status_A
#define LifeTimes_Operation_Status_B                    	l_lifetimes.m_Operation_Status_B
#define LifeTimes_Temp_Range                            	l_lifetimes.m_Temp_Range
#define LifeTimes_Charging_Status_A                     	l_lifetimes.m_Charging_Status_A
#define LifeTimes_Charging_Status_B                     	l_lifetimes.m_Charging_Status_B
#define LifeTimes_Gauging_Status                        	l_lifetimes.m_Gauging_Status
#define LifeTimes_IT_Status                             	l_lifetimes.m_IT_Status
#define LifeTimes_Cell_1_Voltage                        	l_lifetimes.m_Cell_1_Voltage
#define LifeTimes_Cell_2_Voltage                        	l_lifetimes.m_Cell_2_Voltage
#define LifeTimes_Cell_3_Voltage                        	l_lifetimes.m_Cell_3_Voltage
#define LifeTimes_Cell_4_Voltage                        	l_lifetimes.m_Cell_4_Voltage
#define LifeTimes_Battery_Direct_Voltage                	l_lifetimes.m_Battery_Direct_Voltage
#define LifeTimes_Pack_Voltage                          	l_lifetimes.m_Pack_Voltage
#define LifeTimes_Current                               	l_lifetimes.m_Current
#define LifeTimes_Internal_Temperature                  	l_lifetimes.m_Internal_Temperature
#define LifeTimes_External_1_Temperature                	l_lifetimes.m_External_1_Temperature
#define LifeTimes_External_2_Temperature                	l_lifetimes.m_External_2_Temperature
#define LifeTimes_External_3_Temperature                	l_lifetimes.m_External_3_Temperature
#define LifeTimes_External_4_Temperature                	l_lifetimes.m_External_4_Temperature

#define LifeTimes_1st_Status_Status_A                   	l_lifetimes.m_1st_Status_Status_A
#define LifeTimes_1st_Status_Status_B                   	l_lifetimes.m_1st_Status_Status_B
#define LifeTimes_1st_Status_Status_C                   	l_lifetimes.m_1st_Status_Status_C
#define LifeTimes_1st_Status_Status_D                   	l_lifetimes.m_1st_Status_Status_D
#define LifeTimes_1st_Time_to_Next_Event                	l_lifetimes.m_1st_Time_to_Next_Event
#define LifeTimes_2st_Status_Status_A                   	l_lifetimes.m_2st_Status_Status_A
#define LifeTimes_2st_Status_Status_B                   	l_lifetimes.m_2st_Status_Status_B
#define LifeTimes_2st_Status_Status_C                   	l_lifetimes.m_2st_Status_Status_C
#define LifeTimes_2st_Status_Status_D                   	l_lifetimes.m_2st_Status_Status_D
#define LifeTimes_2st_Time_to_Next_Event                	l_lifetimes.m_2st_Time_to_Next_Event
#define LifeTimes_3st_Status_Status_A                   	l_lifetimes.m_3st_Status_Status_A
#define LifeTimes_3st_Status_Status_B                   	l_lifetimes.m_3st_Status_Status_B
#define LifeTimes_3st_Status_Status_C                   	l_lifetimes.m_3st_Status_Status_C
#define LifeTimes_3st_Status_Status_D                   	l_lifetimes.m_3st_Status_Status_D
#define LifeTimes_3st_Time_to_Next_Event                	l_lifetimes.m_3st_Time_to_Next_Event
#define LifeTimes_1st_PF_Status_A                       	l_lifetimes.m_1st_PF_Status_A
#define LifeTimes_1st_PF_Status_B                       	l_lifetimes.m_1st_PF_Status_B
#define LifeTimes_1st_PF_Status_C                       	l_lifetimes.m_1st_PF_Status_C
#define LifeTimes_1st_PF_Status_D                       	l_lifetimes.m_1st_PF_Status_D
#define LifeTimes_2st_PF_Status_A                       	l_lifetimes.m_2st_PF_Status_A
#define LifeTimes_2st_PF_Status_B                       	l_lifetimes.m_2st_PF_Status_B
#define LifeTimes_2st_PF_Status_C                       	l_lifetimes.m_2st_PF_Status_C
#define LifeTimes_2st_PF_Status_D                       	l_lifetimes.m_2st_PF_Status_D
#define LifeTimes_3st_PF_Status_A                       	l_lifetimes.m_3st_PF_Status_A
#define LifeTimes_3st_PF_Status_B                       	l_lifetimes.m_3st_PF_Status_B
#define LifeTimes_3st_PF_Status_C                       	l_lifetimes.m_3st_PF_Status_C
#define LifeTimes_3st_PF_Status_D                       	l_lifetimes.m_3st_PF_Status_D
#define LifeTimes_Pi_Mode_Count                             l_lifetimes.m_Pi_Mode_Count 

typedef struct{
	S_Calibdata                        	s_Calibdata;
}B_Calib;

typedef struct{
	S_OCV_table                        	s_OCV_table;
	S_SOC_R1_table                     s_SOC_R1_table ;
	S_SOC_R2_table                     s_SOC_R2_table ;
}B_OCV_SOC_table;

typedef struct{
	S_CP_Para                          	s_CP_Para;
	S_CP_Para_table                    	s_CP_Para_table;
	S_CPH_Table                        	s_CPH_Table;
	S_CPL_Table                        	s_CPL_Table;
	S_QCap_Table                       	s_QCap_Table;
}B_CP_Correction;

typedef struct{
	S_CEDV_Cycle_Compensate            	s_CEDV_Cycle_Compensate;
	S_FCC                              	s_FCC;
	S_Qmax                             	s_Qmax;
	S_Discharge_termination            	s_Discharge_termination;
	S_Cell_Balances                    	s_Cell_Balances;
	S_Current_Thresholds               	s_Current_Thresholds;
	S_Design                           	s_Design;
	S_Cycle                            	s_Cycle;
	S_FD                               	s_FD;
	S_FC                               	s_FC;
	S_TD                               	s_TD;
	S_TC                               	s_TC;
	S_State                            	s_State;
	S_Version                          	s_Version;
	S_DBPT_Values                     	s_DBPT_Values;
	S_PI_MODE                           s_PI_Mode;
}B_Gas_Gauging;

typedef struct{
	S_Configuration                    	s_Configuration;
	S_Fuse                             	s_Fuse;
	S_Protection                       	s_Protection;
	S_Permanent_Failure                	s_Permanent_Failure;
	S_AFE                              	s_AFE;
	S_Accumulate_Charg_Measuremen      	s_Accumulate_Charg_Measuremen;
	S_Lifetime_Setting                 	s_Lifetime_Setting;
}B_Setting;

typedef struct{
	S_Voltage_Range                    	s_Voltage_Range;
	S_Temp_ranges                      	s_Temp_ranges;
	S_Low_temp                         	s_Low_temp;
	S_Standard_Low_temp                	s_Standard_Low_temp;
	S_Standard_High_temp               	s_Standard_High_temp;
	S_High_temp                        	s_High_temp;
	S_Rec_Temp_Charging                	s_Rec_Temp_Charging;
	S_Poly                             	s_Poly;
	S_Smart_charge                     	s_Smart_charge;
	S_Termination_Config               	s_Termination_Config;
	S_PreCharging                      	s_PreCharging;
	S_Maintenance_Charging             	s_Maintenance_Charging;
	S_Charge_Inhibit                   	s_Charge_Inhibit;
	S_Elevated_Degrade                 	s_Elevated_Degrade;
	S_FFC_CHARGE						s_FFC_CHARGE;
}B_Charging_algorithm;

typedef struct{
	S_Shutdown                         	s_Shutdown;
	S_Sleep                            	s_Sleep;
	S_Ship_Mode                        	s_Ship_Mode;
}B_Power;

typedef struct{
	S_CUV_Cell_Undervoltage            	s_CUV_Cell_Undervoltage;
	S_CUVC                             	s_CUVC;
	S_COV_Cell_Overvoltage             	s_COV_Cell_Overvoltage;
	S_OCC1_Overcurren_In_Charg_1       	s_OCC1_Overcurren_In_Charg_1;
	S_OCC2_Overcurren_In_Charg_2       	s_OCC2_Overcurren_In_Charg_2;
	S_OCC_Overcurr_In_Cha_Recov        	s_OCC_Overcurr_In_Cha_Recov;
	S_OCD1_Overcurr_In_Discha_1        	s_OCD1_Overcurr_In_Discha_1;
	S_OCD2_Overcurr_In_Discha_2        	s_OCD2_Overcurr_In_Discha_2;
	S_OCD_Overcurren_In_Discharg       	s_OCD_Overcurren_In_Discharg;
	S_OCD_Overcurr_In_Discha_Lat       	s_OCD_Overcurr_In_Discha_Lat;
	S_AOLD_Overload_in_Discharge       	s_AOLD_Overload_in_Discharge;
	S_ASCC_Shor_Circui_In_Charg        	s_ASCC_Shor_Circui_In_Charg;
	S_ASCD_Sho_Circu_in_Dischar        	s_ASCD_Sho_Circu_in_Dischar;
	S_OTC_Overtemperatu_in_Char        	s_OTC_Overtemperatu_in_Char;
	S_OTD_Overtemperat_in_Discha       	s_OTD_Overtemperat_in_Discha;
	S_OTF_Overtemperature_FET          	s_OTF_Overtemperature_FET;
	S_UTC_Undertemperatu_in_Char       	s_UTC_Undertemperatu_in_Char;
	S_UTD_Undertempera_in_Disch        	s_UTD_Undertempera_in_Disch;
	S_HWD_Host_Watchdog                	s_HWD_Host_Watchdog;
	S_PTO_PRECHARG_Mod_Tim_Out         	s_PTO_PRECHARG_Mod_Tim_Out;
	S_CTO_Fas_Charg_Mod_Tim_Out        	s_CTO_Fas_Charg_Mod_Tim_Out;
	S_OC_Overcharge                    	s_OC_Overcharge;
	S_CHGV_ChargingVoltage             	s_CHGV_ChargingVoltage;
	S_CHGC_ChargingCurrent             	s_CHGC_ChargingCurrent;
	S_PCHGC_Pre_ChargingCurrent        	s_PCHGC_Pre_ChargingCurrent;
	
}B_Protections;

typedef struct{
	S_SUV_Safet_Cel_Undervoltag        	s_SUV_Safet_Cel_Undervoltag;
	S_SOV_Safet_Cel_Overvoltag         	s_SOV_Safet_Cel_Overvoltag;
	S_SOCC_Saf_Overcurr_in_Cha         	s_SOCC_Saf_Overcurr_in_Cha;
	S_SOCD_Sa_Overcur_in_Disch         	s_SOCD_Sa_Overcur_in_Disch;
	S_SOT_Overtemperature_Cell         	s_SOT_Overtemperature_Cell;
	S_SOTF_Overtemperature_FET         	s_SOTF_Overtemperature_FET;
	S_VIMR_Volta_Imbalan_At_Res        	s_VIMR_Volta_Imbalan_At_Res;
	S_VIMA_Voltag_Imbalanc_Activ       	s_VIMA_Voltag_Imbalanc_Activ;
	S_CFET_CHG_FET_Failure             	s_CFET_CHG_FET_Failure;
	S_DFET_DFET_Failure                	s_DFET_DFET_Failure;
	S_FUSE_FUSE_Failure                	s_FUSE_FUSE_Failure;
	S_2LVL_2nd_Level_OV                	s_2LVL_2nd_Level_OV;
	S_TCO                                 	s_TCO;
}B_Permanent_Fail;

typedef struct{
	S_Data                             	s_Data;
}B_SBS_Configuration;

typedef struct{
	S_ConfigurationEx                  	s_ConfigurationEx;
	S_Normal_Charging                  	s_Normal_Charging;
	S_CCCV_Charging                    	s_CCCV_Charging;
	S_FCC_Degrade_Chg_Current          	s_FCC_Degrade_Chg_Current;
	S_CCV_Step_Down_Charging           	s_CCV_Step_Down_Charging;
	S_Smart_Charge                     	s_Smart_Charge;
	S_Fast_OverCurrent_Protection      	s_Fast_OverCurrent_Protection;
	S_Lifetime_Storage_Data            	s_Lifetime_Storage_Data;
	S_Dual_Mode                        	s_Dual_Mode;
	S_Set_FCC_Design_Capacity          	s_Set_FCC_Design_Capacity;
	S_FCC_Report_DesCap_Threshold      	s_FCC_Report_DesCap_Threshold;
	S_Dual_Mode_TempVolt_Modifier      	s_Dual_Mode_TempVolt_Modifier;
	S_Lifetime_Timers                  	s_Lifetime_Timers;
	S_LifeSpan_Volt_Modifier           	s_LifeSpan_Volt_Modifier;
}B_Lenovo_Data;

typedef struct{
	S_Manufacturer_Data                	s_Manufacturer_Data;
	S_Manufacturer_Info_B              	s_Manufacturer_Info_B;
	S_Manufacturer_Info_C              	s_Manufacturer_Info_C;
	S_Integrity                        	s_Integrity;
}B_System_Data;

typedef struct{
	S_US                               	s_US;
	S_FA                               	s_FA;
}B_UNSeal;

typedef struct{
	S_Control_flag                     	s_Control_flag;
}B_Control_flag;




typedef struct{
	S_FCC_limit                 s_FCC_limit;
	S_Voltage_limit			   	s_Voltage_limit;
	S_Temper_Cap_limit          s_Temper_limit  ;
}B_Algorithm_limit;




#define 		TEMPER_LIMIT_T1       flashdata.b_Algorithm_limit.s_Temper_limit.temper_limit_t1                   //
#define 		TEMPER_LIMIT_T2       flashdata.b_Algorithm_limit.s_Temper_limit.temper_limit_t2                  //
#define 		TEMPER_LIMIT_CAP1      flashdata.b_Algorithm_limit.s_Temper_limit.temper_limit_cap1                   //
#define 		TEMPER_LIMIT_CAP2      flashdata.b_Algorithm_limit.s_Temper_limit.temper_limit_cap2                  //





typedef struct{
	uint16_t chg_pinghua_chgvol_thresh;
	uint16_t chg_pinghua_chgcur_low;
	uint16_t chg_pinghua_chgcur_high;
	uint16_t chg_pinghua_time;
	uint16_t chg_pinghua_cur_range;
	uint16_t chg_pinghua_cap;
}B_Chg_smooth;


#define D_PINGHUA_CHGVOL_THRESH 	flashdata.b_Chg_smooth.chg_pinghua_chgvol_thresh    // 100
#define D_PINGHUA_CHGCUR_LOW        flashdata.b_Chg_smooth.chg_pinghua_chgcur_low       // 230
#define D_PINGHUA_CHGCUR_HIGH       flashdata.b_Chg_smooth.chg_pinghua_chgcur_high      // 350 
#define D_PINGHUA_TIME	            flashdata.b_Chg_smooth.chg_pinghua_time             // 40
#define D_PINGHUA_CUR_RANGE         flashdata.b_Chg_smooth.chg_pinghua_cur_range        // 3
#define D_PINGHUA_CAP               flashdata.b_Chg_smooth.chg_pinghua_cap              // 30  *3600/100/1400


typedef struct{
	uint16_t  dsg_smooth_mul ;
	uint16_t    dsg_smooth_div ;
}B_Dsg_smooth;



#define DSG_SMOOTH_MUL          flashdata.b_Dsg_smooth.dsg_smooth_mul                     //  
#define DSG_SMOOTH_DIV          flashdata.b_Dsg_smooth.dsg_smooth_div                   //

typedef struct{
	uint8_t  b_k_update_fac ;
}B_K_Update_Fac ;

#define K_UPDATE_FAC         flashdata.b_K_Update_Fac.b_k_update_fac                   //




typedef struct{
	B_Calib                            	b_Calib;
	B_OCV_SOC_table                    	b_OCV_SOC_table;
	B_CP_Correction                    	b_CP_Correction;
	B_Gas_Gauging                      	b_Gas_Gauging;
	B_Setting                          	b_Setting;
	B_Charging_algorithm               	b_Charging_algorithm;
	B_Power                            	b_Power;
	B_Protections                      	b_Protections;
	B_Permanent_Fail                	b_Permanent_Fail;
	B_SBS_Configuration                	b_SBS_Configuration;
	B_Lenovo_Data                      	b_Lenovo_Data;
	B_System_Data                      	b_System_Data;
	B_UNSeal                           	b_UNSeal;
	B_Control_flag                     	b_Control_flag;
	B_Algorithm_limit 				    b_Algorithm_limit ;
	B_Chg_smooth 					    b_Chg_smooth ;
	B_Dsg_smooth 					    b_Dsg_smooth ;
	B_K_Update_Fac                      b_K_Update_Fac;

}FlashData;



extern const volatile FlashData flashdata;
extern volatile Record t_record;
extern volatile LifeTimes l_lifetimes;


// 

#pragma pack(pop)

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __DATA_FLASH_VALUE_H__