#ifndef __PROTECT_H__
#define __PROTECT_H__
#include"main.h"
#ifdef __cplusplus
extern "C"
{
#endif


#define CUR_BUF_SIZE 80
extern volatile uint16_t ascdl_counter;
extern volatile uint16_t asccl_counter;
extern volatile uint16_t aoldl_counter;
extern uint16_t Temp_Change;
extern uint8_t  f_pi_pinghua  ;

void Call_ProtectionFun();
void Call_PermanentFailFun();
void plugged_IN(void);
void Protect_CUV();

void Protect_CUVC();
void Protect_COV();
void Protect_OCC();
void Protect_OCD();
void Protect_HardWare_Base();
void Protect_OTC();
void Protect_OTD();
void Protect_OTF();
void Protect_UTC();
void Protect_UTD();
void Protect_HWD();


void Protect_PTO();
void Protect_CTO();
void Protect_OC();
void Protect_CHGV();
void Protect_CHGC();
void Protect_PCHGC();

void PF_SUV();
void PF_SOV();
void PF_SOCC();
void PF_SOCD();
void PF_SOT();
void PF_SOTF();
void PF_VIMR();
void PF_VIMA();

void PF_FUSE();
void PF_TCO();
void Judgment_Temp_Change();

extern volatile uint8_t trip_2lvl;
extern volatile uint8_t shutdown_wake_flag;
uint16_t Soc_OCV_Calibration(uint16_t Rsoc_now,uint16_t* buf);
void DBPT_test(void);





#ifdef __cplusplus
}
#endif

#endif