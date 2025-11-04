#ifndef __SOFT_TIMER_H__
#define __SOFT_TIMER_H__

#include"main.h"

#ifdef __cplusplus
extern "C"
{
#endif

enum timer_mode
{
	SINGLE_MODE=0,
    CONTINUOUS_MODE=1,
};

//定时器ID
enum soft_timer_id
{
    SOFT_TIMER_IIC_ID,
    SOFT_TIMER_APP_INIT_ID,
    SOFT_TIMER_RESET_ID,
    SOFT_TIMER_FC_ID,
    SOFT_TIMER_FUSE_LOW_ID,
    SOFT_TIMER_TM_SHUTDOWN_ID,
    SOFT_TIMER_APP_MAC_BLCOK_ID,//mac和blockml命令处理
    SOFT_TIMER_SHUTDOWN_ENTER_DELAY,//延迟一段时间进shutdown
    SOFT_TIMER_IO_SHUTDOWN_DELAY,//按键检测定时器
    SOFT_TIMER_Unintended_Wakeup_ID,//意外唤醒单次定时器
    SOFT_TIMER_UNSEAL_ID,//解锁单次定时器
    SOFT_TIMER_PRES_ID,//按键延时定时器
    SOFT_TIMER_IATA_ID,//IATA显示延时定时器
    SOFT_TIMER_MAX_ID, /* enum max! */
};

#define TMR_COUNT   SOFT_TIMER_MAX_ID//软件定时器的最大数量

typedef struct
{
	volatile uint8_t Mode;
	volatile uint32_t Count;
	volatile uint32_t PreLoad;
	void (*CallBack)(void);
}SOFT_TMR;
extern SOFT_TMR s_tTmr[TMR_COUNT];

void StartSoftTimer(uint8_t _id, uint8_t mode, uint32_t _period,void *CallBack);
void IncSoftTimer(uint8_t _id,uint32_t _period);
void StopSoftTimer(uint8_t _id);
void InitSoftTimer(void);
void SoftTimerDec(void);
uint8_t getSoftTimerStatus(uint8_t _id);

#ifdef __cplusplus
}
#endif

#endif