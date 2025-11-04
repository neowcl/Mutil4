#ifndef __POWER_MODES_H__
#define __POWER_MODES_H__
#include"main.h"
#ifdef __cplusplus
extern "C"
{
#endif

void SleepMode_Check(void);
void DeepSleep_Enter(void);
uint8_t shutdown_enter(void);
void ship_mode(void);
void ShutdownMode(void);

void Instruct_EntryExit_Ship(void);
void EntryExitShip_TimeOutChk(void);
void InstructShip_invalid(uint8_t shipcmd);

void Power_Modes_Fun();

extern uint16_t ship_timer;
extern volatile uint32_t SDV_CNT;
extern volatile uint32_t SDM_CNT;
extern volatile uint8_t SDM_CMD_CNT;
extern volatile uint32_t timeshutdown_timer;
extern volatile uint8_t timebaseflag;
#ifdef __cplusplus
}
#endif

#endif