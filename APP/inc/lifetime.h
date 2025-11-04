#ifndef __LIFETIME_H__
#define __LIFETIME_H__

#include "afe_cvt.h"
#include "main.h"
#include"Power_Modes.h"

typedef enum  
{ 
	LT_COV=0,
	LT_CUV, 
	LT_OCD1,
	LT_OCD2,
	LT_OCC1,
	LT_OCC2,
	LT_AOLD,
	LT_ASCD,
	LT_ASCC,
	LT_OTC,
	LT_OTD,
    LT_OTF
}e_lifetime_Protect;


typedef struct {
	uint32_t cb_time_cell[5];
	uint32_t _TotalFwRuntime;
	uint32_t _TimeSpentInUTRSOCA;
	uint32_t _TimeSpentInUTRSOCB;
	uint32_t _TimeSpentInUTRSOCC;
	uint32_t _TimeSpentInUTRSOCD;
	uint32_t _TimeSpentInUTRSOCE;
	uint32_t _TimeSpentInUTRSOCF;
	uint32_t _TimeSpentInUTRSOCG;
	uint32_t _TimeSpentInLTRSOCA;
	uint32_t _TimeSpentInLTRSOCB;
	uint32_t _TimeSpentInLTRSOCC;
	uint32_t _TimeSpentInLTRSOCD;
	uint32_t _TimeSpentInLTRSOCE;
	uint32_t _TimeSpentInLTRSOCF;
	uint32_t _TimeSpentInLTRSOCG;
	uint32_t _TimeSpentInSTLRSOCA;
	uint32_t _TimeSpentInSTLRSOCB;
	uint32_t _TimeSpentInSTLRSOCC;
	uint32_t _TimeSpentInSTLRSOCD;
	uint32_t _TimeSpentInSTLRSOCE;
	uint32_t _TimeSpentInSTLRSOCF;
	uint32_t _TimeSpentInSTLRSOCG;
	uint32_t _TimeSpentInRTRSOCA;
	uint32_t _TimeSpentInRTRSOCB;
	uint32_t _TimeSpentInRTRSOCC;
	uint32_t _TimeSpentInRTRSOCD;
	uint32_t _TimeSpentInRTRSOCE;
	uint32_t _TimeSpentInRTRSOCF;
	uint32_t _TimeSpentInRTRSOCG;
	uint32_t _TimeSpentInSTHRSOCA;
	uint32_t _TimeSpentInSTHRSOCB;
	uint32_t _TimeSpentInSTHRSOCC;
	uint32_t _TimeSpentInSTHRSOCD;
	uint32_t _TimeSpentInSTHRSOCE;
	uint32_t _TimeSpentInSTHRSOCF;
	uint32_t _TimeSpentInSTHRSOCG;
	uint32_t _TimeSpentInHTRSOCA;
	uint32_t _TimeSpentInHTRSOCB;
	uint32_t _TimeSpentInHTRSOCC;
	uint32_t _TimeSpentInHTRSOCD;
	uint32_t _TimeSpentInHTRSOCE;
	uint32_t _TimeSpentInHTRSOCF;
	uint32_t _TimeSpentInHTRSOCG;
	uint32_t _TimeSpentInOTRSOCA;
	uint32_t _TimeSpentInOTRSOCB;
	uint32_t _TimeSpentInOTRSOCC;
	uint32_t _TimeSpentInOTRSOCD;
	uint32_t _TimeSpentInOTRSOCE;
	uint32_t _TimeSpentInOTRSOCF;
	uint32_t _TimeSpentInOTRSOCG;

	
} LifeTime_t;

extern  LifeTime_t lifetime_ram;

#define bitPFStatus_SUV													0x00000001
#define bitPFStatus_SOV													0x00000002
#define bitPFStatus_SOCC													0x00000004
#define bitPFStatus_SOCD													0x00000008
#define bitPFStatus_SOT													0x00000010
#define bitPFStatus_COVL													0x00000020
#define bitPFStatus_SOTF													0x00000040
#define bitPFStatus_QIM													0x00000080
#define bitPFStatus_CB													0x00000100
#define bitPFStatus_IMP													0x00000200
#define bitPFStatus_CD													0x00000400
#define bitPFStatus_VIMR													0x00000800
#define bitPFStatus_VIMA													0x00001000
#define bitPFStatus_AOLDL												0x00002000
#define bitPFStatus_ASCCL												0x00004000
#define bitPFStatus_ASCDL												0x00008000
#define bitPFStatus_CFETF												0x00010000
#define bitPFStatus_DFETF												0x00020000
#define bitPFStatus_OCDL													0x00040000
#define bitPFStatus_FUSE													0x00080000
#define bitPFStatus_AFER													0x00100000
#define bitPFStatus_AFEC													0x00200000
#define bitPFStatus_2LVL													0x00400000
#define bitPFStatus_PTC                                                  0x00800000
#define bitPFStatus_IFC                                                  0x01000000
#define bitPFStatus_FORCE                                                0x02000000
#define bitPFStatus_TCO                                                  0x04000000
#define bitPFStatus_VSP                                                  0x08000000
#define bitPFStatus_TS1													0x10000000
#define bitPFStatus_TS2													0x20000000
#define bitPFStatus_TS3													0x40000000
#define bitPFStatus_TS4													0x80000000


#define bitSafetyStatus_CUV												0x00000001
#define bitSafetyStatus_COV												0x00000002
#define bitSafetyStatus_OCC1											0x00000004
#define bitSafetyStatus_OCC2											0x00000008
#define bitSafetyStatus_OCD1											0x00000010
#define bitSafetyStatus_OCD2											0x00000020
#define bitSafetyStatus_AOLD											0x00000040
#define bitSafetyStatus_AOLDL											0x00000080

#define bitSafetyStatus_ASCC											0x00000100
#define bitSafetyStatus_ASCCL											0x00000200
#define bitSafetyStatus_ASCD											0x00000400
#define bitSafetyStatus_ASCDL											0x00000800
#define bitSafetyStatus_OTC												0x00001000
#define bitSafetyStatus_OTD												0x00002000
#define bitSafetyStatus_CUCV											0x00004000

#define bitSafetyStatus_OTF												0x00010000
#define bitSafetyStatus_HWDF											0x00020000
#define bitSafetyStatus_PTO												0x00040000
#define bitSafetyStatus_CTO												0x00100000
#define bitSafetyStatus_OC												0x00400000
#define bitSafetyStatus_CHGC											0x00800000

#define bitSafetyStatus_CHGV											0x01000000
#define bitSafetyStatus_PCHGC											0x02000000
#define bitSafetyStatus_UTC												0x04000000
#define bitSafetyStatus_UTD												0x08000000
#define bitSafetyStatus_COVL											0x10000000
#define bitSafetyStatus_OCDL											0x20000000

#define UT_RSOC               (&(LifeTimes_Time_Spent_in_UT_RSOC_A))
#define LT_RSOC               (&(LifeTimes_Time_Spent_in_LT_RSOC_A))
#define STL_RSOC              (&(LifeTimes_Time_Spent_in_STL_RSOC_A))
#define RT_RSOC               (&(LifeTimes_Time_Spent_in_RT_RSOC_A))
#define STH_RSOC              (&(LifeTimes_Time_Spent_in_STH_RSOC_A))
#define HT_RSOC               (&(LifeTimes_Time_Spent_in_HT_RSOC_A))
#define OT_RSOC               (&(LifeTimes_Time_Spent_in_OT_RSOC_A))

extern uint16_t altflg;								// Flags for DataFlash		
#define f_lt_W        DEF_BIT1(&altflg)
// #define f_lt_areq	    DEF_BIT2(&altflg)			
// #define f_lt_breq	    DEF_BIT3(&altflg)			
#define f_lt_erase  	DEF_BIT4(&altflg)	        
#define f_reset_mcu   DEF_BIT5(&altflg)		    
#define f_updata_en   DEF_BIT6(&altflg)
#define f_debugMode   DEF_BIT7(&altflg)
#define f_AUTH         DEF_BIT8(&altflg)
// #define f_df_erase    DEF_BIT7(&altflg)
void life_Time_Protect_Event(uint8_t  type);
void lifetime_time_period(void);
void lifetime_time_clear(void);
void lt_banlance(void);
void lifetime_time_store(void);
void LifeTime(void);
uint8_t lifetime_Writer();


#endif


