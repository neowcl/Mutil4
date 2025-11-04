#ifndef __ADVANCEDCHARGEALGORITHM_H__
#define __ADVANCEDCHARGEALGORITHM_H__

#include "main.h"
#ifdef __cplusplus
extern "C"
{
#endif

#define CV_PV	    0x10
#define	CV_LV  		0x80
#define	CV_MV  		0x40
#define	CV_HV  		0x20
#define	CV_CVRALL	0xF0

#define	TR_UT   0x01		
#define	TR_LT   0x02
#define	TR_STL  0x04
#define	TR_RT   0x08
#define	TR_STH  0x10
#define	TR_HT   0x20
#define	TR_OT   0x40

#define f_JEITA_CHG          DEF_BIT0(&CHG_Algorithm)      //use JEITA flag
#define f_POLY_CHG           DEF_BIT1(&CHG_Algorithm)      //use JEITA flag

extern uint16_t smartchgcrl;
#define f_IN_CFET    	DEF_BIT0(&smartchgcrl)
#define f_SU_CFET   DEF_BIT1(&smartchgcrl)

extern uint8_t CellVoltRange;
extern uint16_t CHG_Algorithm;

extern uint16_t t_POLY_CC;
extern uint16_t t_SmartChargeCC;
extern uint16_t t_SmartChargeCV;

void VoltageRangeJudge(void);
void TemperatureRangeJudge(void);
void Charging_CV_Fun(void);
void Poly_CC_Calc(void);
void AdvanceChargeAlgorithm_Fun(void);
void Smart_Charge(void);
void Init_ChgSupport(void);
void FFC_Charge(void);

#ifdef __cplusplus
}
#endif

#endif // !1