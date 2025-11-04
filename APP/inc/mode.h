#ifndef __MODE_H__
#define __MODE_H__

#include "main.h"



void pi_blance_enable(void);
void pi_blance_disable(void);
void TFMode_Check(void);
void PFMode_Check(void);
void AlarmWarning_Check(void);
void QMax_Calc(void);
void FUSE_Contrl(void);
void FET_Contrl(void);
void FullCharge_Chk(void);
void CellBalance_Chk(void);
void Calc_ATTF(void);
void Calc_ATTE(void);
void afe_cb_control(uint8_t status);
void RSOC_HOLD(void);
extern uint8_t f_rsoc_hold;
extern uint8_t old_rsoc;
extern int32_t IntTemp;//Internal Temperature
extern uint16_t IntTempK;
extern uint16_t acb_w;// Cell balance select flag

extern int16_t   g_QamxPack;
extern uint16_t hwd_delay;     // HWD delay
extern volatile uint32_t COFF_delay;
extern uint16_t QmaxControl;
#define f_Qmax_start   DEF_BIT0(&QmaxControl) // Qmax start SOC
#define f_Qmax_end     DEF_BIT1(&QmaxControl) // Qmax end SOC
#define f_QmaxUpFsh     DEF_BIT1(&QmaxControl) // Qmax Update Finish

extern  uint16_t        CBstatus;
#define f_cb_cell1          DEF_BIT0(&CBstatus)      // cph flag
#define f_cb_cell2          DEF_BIT1(&CBstatus)      // cpl flag
#define f_cb_cell3			DEF_BIT2(&CBstatus)	    // Capacity correction point flag	1=detect, 0=not detect
#define f_cb_cell4     	    DEF_BIT3(&CBstatus)      // relax                flag 

#endif


