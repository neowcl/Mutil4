#ifndef __HDP_H__
#define __HDP_H__
#include "main.h"

#pragma pack(push,1)
typedef struct{
    uint8_t enable_flag;
    uint8_t aold_threshold;
    uint8_t ascc_threshold;
    uint8_t ascd1_threshold;
    uint8_t ascd2_threshold;
}AFE_HDP_SETTING;
#pragma pack(pop)
#define hdp_RSNS    DEF_BIT0(&afe_hdp_setting)
#define hdp_SCDDx2  DEF_BIT1(&afe_hdp_setting)
#define hdp_aold_en DEF_BIT2(&afe_hdp_setting)
#define hdp_ascc_en DEF_BIT3(&afe_hdp_setting)
#define hdp_ascd_en DEF_BIT4(&afe_hdp_setting)
#define hdp_change  DEF_BIT5(&afe_hdp_setting)
#define hdp_aold_threshold  (afe_hdp_setting.aold_threshold)
#define hdp_ascc_threshold  (afe_hdp_setting.ascc_threshold)
#define hdp_ascd1_threshold (afe_hdp_setting.ascd1_threshold)
#define hdp_ascd2_threshold (afe_hdp_setting.ascd2_threshold)

extern uint16_t amodeflag;
#define f_sdmDFET   DEF_BIT0(&amodeflag)      //Intosleep Flag
#define f_sleepPCFET   DEF_BIT1(&amodeflag)			//  Turn DSG FET off(shutdown)
#define f_sleepCFET DEF_BIT2(&amodeflag)      //sleep CFET off
#define f_sleepDFET DEF_BIT3(&amodeflag)      //sleep CD FET off
#define f_Intoship    DEF_BIT4(&amodeflag)      //Intoship Flag
#define f_count_toship		DEF_BIT5(&amodeflag)		// 
#define f_ship		DEF_BIT6(&amodeflag)
#define f_ReadyShip   DEF_BIT7(&amodeflag)			// enter shipmode
#define f_enterShip  DEF_BIT8(&amodeflag)			// enter shipmode
#define f_ReadyExitShip   DEF_BIT9(&amodeflag)			// Exit shipmode
#define f_ExitShip  DEF_BIT10(&amodeflag)			// Exit shipmode
#define f_enterShipTo  DEF_BIT12(&amodeflag)			// enter Shipmode Timeout shipmode
#define f_ExitShipTo  DEF_BIT13(&amodeflag)			// Exit Shipmode Timeout shipmode
#define f_sdvDFET   DEF_BIT14(&amodeflag)			//  Turn DSG FET off(shutdown)
#define f_sdmCFET   DEF_BIT15(&amodeflag)			//  Turn DSG FET off(shutdown)

extern volatile uint32_t prehiegdelay;
extern volatile uint32_t prelowdelay;

void Hdp_Init(void);
void Hdp_ClearStatus(uint16_t flag);
void Mos_init();
void WakeUp_Ctrl(uint8_t status);
void WakeCp_init(void);               //CC WakeUp
void MCU_FWDG_init(void);               //FWDG_Init
void MCU_FWDG_Feed(void);
void MCU_FWDG_20S(void);
void FWDG_LPT_modeCheck(void);
void MCU_FWDG_4S(void);
void AFE_FWDG_Init(void);
void AFE_FWDG_Feed(void);
void FUSE_Init(void); //
void FUSE_OUT(uint8_t output);
uint8_t FUSE_Read();
void PresInit(void);
void PresToggle(void);


uint8_t sha256_hmac_calc(uint8_t* message, uint16_t msglen, uint8_t* key, uint16_t key_len, uint8_t* mac);
#endif


