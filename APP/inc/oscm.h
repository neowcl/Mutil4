#ifndef __OSCM_H__
#define __OSCM_H__

#include "main.h"
extern uint16_t OSCM_CaliTime;

typedef struct
{
    uint16_t OSCM_SUP        :1;//Overnight charge mode support status
	uint16_t OSCM_En         :1;//Overnight charge mode enable status
	uint16_t OSCM_sync       :2; //Night charging mode time sync up
	uint16_t OSCM_modesta    :3;//Overnight charge mode status
	uint16_t Sys_ACstatus    :1;//System Write Status(AC-Out and AC-in status)
	uint16_t ACstatus        :1;//AC Status
	uint16_t Reserved        :7;
}OSCM_CHGSTUTAS;
typedef union
{
  uint16_t data;
  OSCM_CHGSTUTAS OSCM_ChgStatus;
}OSCM_CHGSTU;         
extern OSCM_CHGSTU OSCM_ChgSta;
//#define t_com27           OSCM_ChgSta.data//0x50
#define f_oscm_support    OSCM_ChgSta.OSCM_ChgStatus.OSCM_SUP//Overnight charge mode support status   
#define f_oscm_en         OSCM_ChgSta.OSCM_ChgStatus.OSCM_En//Overnight charge mode enable status
#define f_oscm_sync       OSCM_ChgSta.OSCM_ChgStatus.OSCM_sync //Night charging mode time sync up
#define f_oscm_modesta    OSCM_ChgSta.OSCM_ChgStatus.OSCM_modesta    //Overnight charge mode status
#define f_oscm_Sys_ACsta  OSCM_ChgSta.OSCM_ChgStatus.Sys_ACstatus    //System Write Status(AC-Out and AC-in status)

typedef struct
{
    uint16_t OSCM_80TOFull        :8;//Night charging mode time to full from 80%
	uint16_t OSCM_EnterTime         :4;//Night charging mode enter time
	uint16_t OSCM_ExitTime       :4; //Night charging mode exit time
}OSCM_MODE_TIME;
typedef union
{
  uint16_t data;
  OSCM_MODE_TIME OSCM_mode_time;
}OSCM_TIME;
extern OSCM_TIME OSCMtime;
//#define t_com28 OSCMtime.data //0x51
#define OSCM_Time80TOFull OSCMtime.OSCM_mode_time.OSCM_80TOFull//night charging optimization phase3 time T3 evaluation (min, charge time from 80% to full).
#define OSCM_EnterTime OSCMtime.OSCM_mode_time.OSCM_EnterTime
#define OSCM_ExitTime OSCMtime.OSCM_mode_time.OSCM_ExitTime

typedef struct
{
    uint8_t RTC_Minutes;
	uint8_t RTC_Hour;
}RTC_TIME_DATA;// Current time of date as known by BMU
typedef union
{
  uint16_t data;
  RTC_TIME_DATA RTC_Time_Data;
}RTC_TIME;
extern RTC_TIME RTC_Time;
#define t_com29 RTC_Time.data //0x52
#define G_RTC_Minutes RTC_Time.RTC_Time_Data.RTC_Minutes
#define G_RTC_Hour RTC_Time.RTC_Time_Data.RTC_Hour

typedef struct
{
	uint8_t OSCM_EntertimeDay1;
	uint8_t OSCM_EntertimeDay2;
    uint8_t OSCM_EntertimeDay3;
	uint8_t OSCM_EntertimeDay4;
    uint8_t OSCM_EntertimeDay5;
    uint8_t OSCM_EntertimeDay6;
	uint8_t OSCM_EntertimeDay7;
    uint8_t OSCM_ExittimeDay1;
	uint8_t OSCM_ExittimeDay2;
    uint8_t OSCM_ExittimeDay3;
	uint8_t OSCM_ExittimeDay4;
    uint8_t OSCM_ExittimeDay5;
    uint8_t OSCM_ExittimeDay6;
	uint8_t OSCM_ExittimeDay7;  	
}OSCM_ENTEREXITDATATIME;
#define OSCM_DATASIZE      sizeof(OSCM_ENTEREXITDATATIME)
typedef union
{
  uint8_t data[OSCM_DATASIZE];
  OSCM_ENTEREXITDATATIME OSCM_EnterExitDataTime;
}OSCM_EEDATATIME;
extern OSCM_EEDATATIME OSCM_EEDataTime;
#define OSCM_EE_DAYTIME      OSCM_EEDataTime.data
	
extern uint16_t OSCM_flag;
#define f_oscmstart_t      DEF_BIT0(&OSCM_flag)
#define f_ACinEarly        DEF_BIT1(&OSCM_flag)
#define f_ACoutEarly       DEF_BIT2(&OSCM_flag)
// #define f_ACinRecord       DEF_BIT3(&OSCM_flag)
// #define f_ACoutRecord      DEF_BIT4(&OSCM_flag)
#define f_calitime         DEF_BIT5(&OSCM_flag)
#define f_ACinstart        DEF_BIT6(&OSCM_flag)
#define f_ACoutstart       DEF_BIT7(&OSCM_flag)
#define f_oscmstart        DEF_BIT8(&OSCM_flag)
#define f_oscmchange       DEF_BIT9(&OSCM_flag)
#define f_oscm_soc80       DEF_BIT10(&OSCM_flag)
#define f_oscm_t3          DEF_BIT11(&OSCM_flag)
#define f_oscmsoc80        DEF_BIT12(&OSCM_flag)
#define f_daytimeread      DEF_BIT13(&OSCM_flag)
// #define f_AC_Wflash      DEF_BIT13(&OSCM_flag)

#define M_ACIN         0x00
#define M_ACIN_FNF     0x01//ACin finish
#define M_ACOUT        0x02
#define M_IDEL         0x03

uint8_t chioce_ExitTime(uint8_t*ExitTime);
uint8_t chioce_EnterTime(uint8_t*EnterTime);

#endif