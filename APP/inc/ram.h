#ifndef __RAM_H__
#define __RAM_H__

#include "main.h"

typedef struct
{
	uint32_t PRES		          : 1;
	uint32_t DSG		          : 1;     
	uint32_t CHG		          : 1;     
	uint32_t PCHG		          : 1;
    uint32_t ACTHR            	  : 1;
    uint32_t FUSE                 : 1;
    uint32_t EMSHUT               : 1;     
    uint32_t BTP_INT	    	  : 1;
	uint32_t SEC0		          : 1;
	uint32_t SEC1		          : 1;     
	uint32_t SDV		          : 1;     
	uint32_t SS		              : 1;
    uint32_t PF            	      : 1;
    uint32_t XDSG                 : 1;
    uint32_t XCHG              	  : 1;     
    uint32_t SLEEP		  		  : 1; 
	uint32_t SDM		          : 1;
	uint32_t LED		          : 1;     
	uint32_t AUTH		          : 1;     
	uint32_t AUTOCALM		      : 1;
    uint32_t CAL            	  : 1;
    uint32_t CAL_OFFSET           : 1;
    uint32_t XL              	  : 1;     
    uint32_t SLEEPM		  		  : 1;
	uint32_t IMIT		          : 1;
	uint32_t SMBLCAL	          : 1;          
	uint32_t SLPAD		          : 1;
    uint32_t SLPCC            	  : 1;
    uint32_t CB                   : 1;
    uint32_t DISCONN           	  : 1;     
    uint32_t PSSHUT		  		  : 1;
	uint32_t IOSHUT  	  		  : 1;
} OPERATION_STATUS;//OperationStatus 0X0054

typedef union
{
  uint8_t data[4];
  uint32_t data32;
  OPERATION_STATUS OperationStatus_f;
}OperationStatus;
extern OperationStatus nOperationStatus;
#define f_pres          nOperationStatus.OperationStatus_f.PRES
#define f_dsg          nOperationStatus.OperationStatus_f.DSG
#define f_chg          nOperationStatus.OperationStatus_f.CHG
#define f_pchg          nOperationStatus.OperationStatus_f.PCHG
#define f_acthr          nOperationStatus.OperationStatus_f.ACTHR
#define f_fuse_out     nOperationStatus.OperationStatus_f.FUSE
#define f_emshut          nOperationStatus.OperationStatus_f.EMSHUT
#define f_bpt_int          nOperationStatus.OperationStatus_f.BTP_INT
#define f_sec0          nOperationStatus.OperationStatus_f.SEC0
#define f_sec1          nOperationStatus.OperationStatus_f.SEC1
#define f_sdv          nOperationStatus.OperationStatus_f.SDV
#define f_ss          nOperationStatus.OperationStatus_f.SS
#define f_pf          nOperationStatus.OperationStatus_f.PF
#define f_xdsg          nOperationStatus.OperationStatus_f.XDSG
#define f_xchg          nOperationStatus.OperationStatus_f.XCHG
#define f_sleep          nOperationStatus.OperationStatus_f.SLEEP
#define f_sdm          nOperationStatus.OperationStatus_f.SDM
#define f_led          nOperationStatus.OperationStatus_f.LED
#define f_auth          nOperationStatus.OperationStatus_f.AUTH
#define f_autocalm          nOperationStatus.OperationStatus_f.AUTOCALM
#define f_cal          nOperationStatus.OperationStatus_f.CAL
#define f_cal_offset          nOperationStatus.OperationStatus_f.CAL_OFFSET
#define f_xl          nOperationStatus.OperationStatus_f.XL
#define f_sleepm          nOperationStatus.OperationStatus_f.SLEEPM
#define f_imit          nOperationStatus.OperationStatus_f.IMIT
#define f_smblcal          nOperationStatus.OperationStatus_f.SMBLCAL
#define f_slpad          nOperationStatus.OperationStatus_f.SLPAD
#define f_slpcc          nOperationStatus.OperationStatus_f.SLPCC
#define f_cb          nOperationStatus.OperationStatus_f.CB
#define f_disconn          nOperationStatus.OperationStatus_f.DISCONN
#define f_psshut          nOperationStatus.OperationStatus_f.PSSHUT
#define f_ioshut          nOperationStatus.OperationStatus_f.IOSHUT

typedef struct
{
  uint32_t UT : 1;  //0
  uint32_t LT : 1;  // 1 
  uint32_t STL : 1;  // 2 
  uint32_t RT : 1;   // 3
  uint32_t STH : 1;  // 4
  uint32_t HT : 1;   // 5
  uint32_t OT : 1;   // 6
  uint32_t RSVD : 1;   // 7
  uint32_t PV : 1;    //   8
  uint32_t LV : 1;     // 9 
  uint32_t MV : 1;    // 10
  uint32_t HV : 1;    //  11 
  uint32_t IN : 1;    //  12 
  uint32_t SU : 1;    //   13
  uint32_t MCHG : 1;
  uint32_t VCT : 1;
  uint32_t CCR : 1;
  uint32_t CVR : 1;
  uint32_t CCC : 1;
  uint32_t NCT : 1;
  uint32_t ERM : 1;
  uint32_t ERETM : 1;
  uint32_t RSVD1 : 10;
} CHARGING_STATUS; // ChargingStatus 0X0055

typedef union
{
  uint8_t data[4];
  uint32_t data32;
  CHARGING_STATUS ChargingStatus_f;
}ChargingStatus;

extern ChargingStatus nChargingStatus;
#define f_UT nChargingStatus.ChargingStatus_f.UT
#define f_LT nChargingStatus.ChargingStatus_f.LT
#define f_STL nChargingStatus.ChargingStatus_f.STL
#define f_RT nChargingStatus.ChargingStatus_f.RT
#define f_STH nChargingStatus.ChargingStatus_f.STH
#define f_HT nChargingStatus.ChargingStatus_f.HT
#define f_OT nChargingStatus.ChargingStatus_f.OT
#define f_PV nChargingStatus.ChargingStatus_f.PV
#define f_LV nChargingStatus.ChargingStatus_f.LV
#define f_MV nChargingStatus.ChargingStatus_f.MV
#define f_HV nChargingStatus.ChargingStatus_f.HV
#define f_IN nChargingStatus.ChargingStatus_f.IN
#define f_SU nChargingStatus.ChargingStatus_f.SU
#define f_MCHG nChargingStatus.ChargingStatus_f.MCHG
#define f_VCT nChargingStatus.ChargingStatus_f.VCT
#define f_CCR nChargingStatus.ChargingStatus_f.CCR
#define f_CVR nChargingStatus.ChargingStatus_f.CVR
#define f_CCC nChargingStatus.ChargingStatus_f.CCC
#define f_NCT nChargingStatus.ChargingStatus_f.NCT
#define f_ERM nChargingStatus.ChargingStatus_f.ERM
#define f_ERETM nChargingStatus.ChargingStatus_f.ERETM

typedef struct
{
	uint32_t FD		          : 1;
	uint32_t FC		          : 1;     
	uint32_t TD		          : 1;     
	uint32_t TC		          : 1;
    uint32_t BAL_EN           : 1;
    uint32_t EDV              : 1;
    uint32_t DSG         	  : 1;     
    uint32_t CF		  		  : 1;
	uint32_t REST	          : 1;
	uint32_t RSVD	          : 1;     
	uint32_t R_DIS	          : 1;     
	uint32_t VOK		      : 1;
    uint32_t QEN          	  : 1;
    uint32_t SLPQMax          : 1;
    uint32_t RSVD1            : 1;     
    uint32_t NSFM	     	  : 1; 
	uint32_t VDQ              : 1;
	uint32_t QMax	          : 1;     
	uint32_t RX		          : 1;     
	uint32_t LDMD             : 1;
    uint32_t OCVFR       	  : 1;
    uint32_t RSVD2            : 11;
} GAUGING_STATUS;//GaugingStatus 0X0056

typedef union
{
  uint8_t data[4];
  uint32_t data32;
  GAUGING_STATUS GaugingStatus_f;
}GaugingStatus;
extern GaugingStatus nGaugingStatus;
#define f_gs_fd nGaugingStatus.GaugingStatus_f.FD
#define f_gs_fc   nGaugingStatus.GaugingStatus_f.FC
#define f_gs_td   nGaugingStatus.GaugingStatus_f.TD
#define f_gs_tc   nGaugingStatus.GaugingStatus_f.TC
#define f_gs_bal_en   nGaugingStatus.GaugingStatus_f.BAL_EN
#define f_gs_edv   nGaugingStatus.GaugingStatus_f.EDV
#define f_gs_dsg   nGaugingStatus.GaugingStatus_f.DSG
#define f_gs_cf   nGaugingStatus.GaugingStatus_f.CF
#define f_gs_rest   nGaugingStatus.GaugingStatus_f.REST	
#define f_gs_r_dis   nGaugingStatus.GaugingStatus_f.R_DIS
#define f_gs_vok   nGaugingStatus.GaugingStatus_f.VOK
#define f_gs_qen   nGaugingStatus.GaugingStatus_f.QEN
#define f_gs_slpqmax   nGaugingStatus.GaugingStatus_f.SLPQMax
#define f_gs_nsfm   nGaugingStatus.GaugingStatus_f.NSFM
#define f_gs_vdq   nGaugingStatus.GaugingStatus_f.VDQ
#define f_gs_qmax   nGaugingStatus.GaugingStatus_f.QMax
#define f_gs_rx   nGaugingStatus.GaugingStatus_f.RX
#define f_gs_ldmd   nGaugingStatus.GaugingStatus_f.LDMD
#define f_gs_ocvfr   nGaugingStatus.GaugingStatus_f.OCVFR

typedef struct
{
	uint16_t  PCHG_EN   :1;
	uint16_t  CHG_EN    :1;
	uint16_t  DSG_EN    :1;
	uint16_t  GAUGE_EN  :1;
	uint16_t  FET_EN    :1;
	uint16_t  LF_EN     :1;
	uint16_t  PF_EN     :1;
	uint16_t  BBR_EN    :1;
	uint16_t  FUSE_EN   :1;
	uint16_t  LED_EN    :1;
	uint16_t  RSVD      :4;
	uint16_t  LT_TEST   :1;
	uint16_t  CAL_EN    :1;
}MANUFACTURING_STATUS;//ManufacturingStatus 0X0057

typedef union
{
  uint16_t data;
  MANUFACTURING_STATUS ManufacturingStatus_f;
}ManufacturingStatus;
extern ManufacturingStatus nManufacturingStatus;
#define f_PCHG_EN nManufacturingStatus.ManufacturingStatus_f.PCHG_EN
#define f_CHG_EN nManufacturingStatus.ManufacturingStatus_f.CHG_EN
#define f_DSG_EN nManufacturingStatus.ManufacturingStatus_f.DSG_EN
#define f_GAUGE_EN nManufacturingStatus.ManufacturingStatus_f.GAUGE_EN
#define f_FET_EN nManufacturingStatus.ManufacturingStatus_f.FET_EN
#define f_LF_EN nManufacturingStatus.ManufacturingStatus_f.LF_EN
#define f_PF_EN nManufacturingStatus.ManufacturingStatus_f.PF_EN
#define f_BBR_EN nManufacturingStatus.ManufacturingStatus_f.BBR_EN
#define f_FUSE_EN nManufacturingStatus.ManufacturingStatus_f.FUSE_EN
#define f_LED_EN nManufacturingStatus.ManufacturingStatus_f.LED_EN
#define f_LT_TEST nManufacturingStatus.ManufacturingStatus_f.LT_TEST
#define f_CAL_EN nManufacturingStatus.ManufacturingStatus_f.CAL_EN

typedef struct
{
	uint16_t  DISP         :1;
	uint16_t  LEDCNTA      :1;
	uint16_t  LEDCNTLB     :1;
	uint16_t  LEDCNTLC     :1;
	uint16_t  RSVD         :12;
}GPIO_READ;//0x48 GPIORead()

typedef union
{
  uint16_t data;
  GPIO_READ GPIORead_f;
}GPIORead;

typedef struct
{
	uint16_t  DISP0         :1;
	uint16_t  DISP1         :1;
	uint16_t  LEDCNTLA0     :1;
	uint16_t  LEDCNTLA1     :1;
	uint16_t  LEDCNTLB0     :1;
	uint16_t  LEDCNTLB1     :1;
	uint16_t  LEDCNTLC0     :1;
	uint16_t  LEDCNTLC1     :1;
	uint16_t  RSVD          :8;
}GPIO_WRITE;//0x49 GPIOWrite()

typedef union
{
  uint16_t data;
  GPIO_WRITE GPIOWrite_f;
}GPIOWrite;


extern  uint16_t        t_com79;
#define f_cp_h          DEF_BIT0(&t_com79)      // cph flag
#define f_cp_l          DEF_BIT1(&t_com79)      // cpl flag
#define f_ccp			DEF_BIT2(&t_com79)	    // Capacity correction point flag	1=detect, 0=not detect
#define f_relax     	DEF_BIT3(&t_com79)      // relax                flag 
#define f_charge		DEF_BIT4(&t_com79)	    // Charging             flag
#define f_discharge	  	DEF_BIT5(&t_com79)	    // Discharging          flag
#define f_study_d       DEF_BIT6(&t_com79)	    // Discharging  study   flag
#define f_study_c       DEF_BIT7(&t_com79)	    // charging  study      flag
#define f_relearn       DEF_BIT8(&t_com79)      // study flag
#define f_rcsame        DEF_BIT9(&t_com79)      // RC same
#define f_fullchg       DEF_BIT10(&t_com79)      // Fullcharge
#define f_pto_start     DEF_BIT11(&t_com79)      // pto start flag
#define f_cto_start     DEF_BIT12(&t_com79)      // cto start flag
#define f_pi_mode       DEF_BIT13(&t_com79)
#define f_pi_test       DEF_BIT14(&t_com79)   
#define f_pi_mode_last      DEF_BIT15(&t_com79) 


#pragma pack(1)
typedef struct
{ 
  //  uint16_t                   com__RemainingCapacityAlarm;        //t_com01;//_RemainingCapacityAlarm()
  //  uint16_t                   com_RemainingTimeAlarm;            //t_com02;//RemainingTimeAlarm()
  //  BatteryMode                com_BatteryMode;                   //t_com03;//BatteryMode()
  //  int16_t                    com_AtRate;                        //t_com04;//AtRate()
  //  uint16_t                   com_AtRateTimeToFull;              //t_com05;//AtRateTimeToFull()
  //  uint16_t                   com_AtRateTimeToEmpty;             //_AtRateTimeToEmpty;//AtRateTimeToEmpty()
  //  uint16_t                   com_AtRateOK;                      //t_com07;//AtRateOK()
  //  uint16_t                   com_Voltage;                       //t_com09;//Voltage()
  //  int16_t                    com_Current;                       //t_com0a;//Current()
  //  int16_t                    com_AverageCurrent;                //t_com0b;//AverageCurrent()
   uint16_t                   com_MaxError;                      //t_com0c;//MaxError()
   uint16_t                   com_RelativeStateOfCharge;         //t_com0d;//RelativeStateOfCharge()
   uint16_t                   com_AbsoluteStateOfCharge;         //t_com0e;//AbsoluteStateOfCharge()
   uint16_t                   com_RemainingCapacity;             //t_com0f;//RemainingCapacity()
   uint16_t                   com_FullChargeCapacity;            //t_com10;//FullChargeCapacity()
  //  uint16_t                   com_RunTimeToEmpty;                //t_com11;//RunTimeToEmpty()
   uint16_t                   com_AverageTimeToEmpty;            //t_com12;//AverageTimeToEmpty()
   uint16_t                   com_AverageTimeToFull;             //t_com13;//AverageTimeToFull()
   uint16_t                   com_ChargingCurrent;               //t_com14;//ChargingCurrent()
   uint16_t                   com_ChargingVoltage;               //t_com15;//ChargingVoltage()
  //  BatteryStatus              com_BatteryStatus;                 //t_com16;//BatteryStatus()
   uint16_t                   com_CycleCount;                    //t_com17;//CycleCount()
   uint16_t                   com_DesignCapacity;                //t_com18;//DesignCapacity()
   uint16_t                   com_DesignVoltage;                 //t_com19;//DesignVoltage()
  //  Specification_Info         com_SpecificationInfo;             //t_com1a;//SpecificationInfo()
   uint16_t                   com_ManufacturerDate;              //t_com1b;//ManufacturerDate()
   uint16_t                   com_SerialNumber;                  //t_com1c;//SerialNumber()
   uint16_t                   com_TrueRemCap;                    //t_com24
   uint16_t                   com_TrueFcc;                       //t_com25
   uint16_t                   com_AIPIModeControl;               //t_com2a;
   uint16_t                   com_currbei;
   int16_t                    com_InTemp;                        //t_com2c
   uint16_t                   com_FETCtrl;                       //t_com34
   uint16_t                   com_FUStatus;                      //t_com35;//FUStatus()
  //  uint16_t                   com_FETTemperature;                 //t_com3b;fet Temperature
  //  OptCommand2                com_OptCommand2;                   //t_com3e;//OptCommand2()
  //  uint16_t                   com_OptCommand1;                   //t_com3f
   uint16_t                   com_CellVoltage1;                  //t_com40;//CellVoltage1()
   uint16_t                   com_CellVoltage2;                  //t_com41;//CellVoltage2()
   uint16_t                   com_CellVoltage3;                  //t_com42;//CellVoltage3()
   uint16_t                   com_CellVoltage4;                  //t_com43;//CellVoltage4()
   uint16_t                   com_PackVoltage;                   //Pack Voltage
   GPIORead                   com_GPIORead;                      //t_com48;//GPIORead()
   GPIOWrite                  com_GPIOWrite;                     //t_com49;//GPIOWrite()
   int16_t                    com_BTPDischargeSet;               //t_com4a;//BTPDischargeSet()
   uint16_t                    com_BTPChargeSet;                  //t_com4b;//BTPChargeSet()
  //  uint16_t                   com_SoH;                           //t_com4f
   int16_t                     com_MaxTurboPwr;                  //t_com59;//MaxTurboPwr()
   int16_t                     com_SusTurboPwr;                  //t_com5a;//SusTurboPwr()
   int16_t                     com_TurboPackR;                   //t_com5b;//TurboPackR()
   int16_t                     com_TurboSysR;                    //t_com5c;//TurboSysR()
   int16_t                     com_TurboEdv;                     //t_com5d;//TurboEdv()
   int16_t                     com_MPPCurrent;                 //t_com5e;//MaxTurboCurr()
   int16_t                     com_SPPCurrent;                 //t_com5f;//SusTurboCurr()
   int16_t                     com_ACDP;                         //t_com60
   int16_t                     com_ADP12S;                       //t_com61
   int16_t                     com_ADP10m;                       //t_com62
   int16_t                     com_TurboRhfEffective;            //t_com68;//TurboRhfEffective()
   int16_t                     com_TurboVload;                   //t_com69;//TurboVload()
   uint16_t                    com_BatteryHealthState;           //t_com6a
   uint16_t                    com_BatteryLifeCycle;             //t_com6b
   uint16_t                    com_BatteryLifeSpan;              //t_com6c
   uint16_t                    com_DF_IRC;                         //t_com88; 0xA4 EntryShipModeCount()
   uint16_t                    com_DF_IFCC;                         //t_com89; 0xA5 EntryExitShipCondition()
   uint16_t                    com_DF_IRSoc;                          //t_com8a; 0xA6 ShipModeTimer()

}CMD_DATA; 
#pragma pack()
#define COMSIZE	sizeof(CMD_DATA)					// comData size
	typedef union
{
	 CMD_DATA	comdat;								// Flexible data
	 uint8_t	uc[COMSIZE];							// Byte alignment
}_COM;

#define ucomdata		com_data.uc
extern _COM com_data;



#define t_com08           _DAStatus2.CellTemperature
#define CellTemp          ((_DAStatus2.CellTemperature-2731)/10)
#define t_com2b           com_data.comdat.com_currbei

#define t_com0c           com_data.comdat.com_MaxError//
#define t_com0d           com_data.comdat.com_RelativeStateOfCharge//
#define t_com0e           com_data.comdat.com_AbsoluteStateOfCharge//
#define t_com0f           com_data.comdat.com_RemainingCapacity//
#define t_com10           com_data.comdat.com_FullChargeCapacity
// #define t_com11           com_data.comdat.com_RunTimeToEmpty//
#define t_com12           com_data.comdat.com_AverageTimeToEmpty//
#define t_com13           com_data.comdat.com_AverageTimeToFull//
#define t_com14           com_data.comdat.com_ChargingCurrent//
#define t_com15           com_data.comdat.com_ChargingVoltage//
// #define t_com16           com_data.comdat.com_BatteryStatus.data//
#define t_com17           com_data.comdat.com_CycleCount//
#define t_com18           com_data.comdat.com_DesignCapacity//
#define t_com19           com_data.comdat.com_DesignVoltage//
// #define t_com1a           com_data.comdat.com_SpecificationInfo.data//
#define t_com1b           com_data.comdat.com_ManufacturerDate//
#define t_com1c           com_data.comdat.com_SerialNumber//

#define t_com24           com_data.comdat.com_TrueRemCap
#define t_com25           com_data.comdat.com_TrueFcc
#define t_com26           smartchgcrl
#define t_com2a           com_data.comdat.com_AIPIModeControl
#define t_com2c           com_data.comdat.com_InTemp

#define t_com34           com_data.comdat.com_FETCtrl
#define t_com35           com_data.comdat.com_FUStatus

#define t_com42           com_data.comdat.com_CellVoltage3//
#define t_com43           com_data.comdat.com_CellVoltage4//

#define t_com47           com_data.comdat.com_PackVoltage//
#define t_com48           com_data.comdat.com_GPIORead.data//
#define t_com49           com_data.comdat.com_GPIOWrite.data//
#define t_com4a           com_data.comdat.com_BTPDischargeSet//
#define t_com4b           com_data.comdat.com_BTPChargeSet//

//#define t_com52           nPFAlert.data32
//#define t_com53           nPFStatus.data32
#define t_com54           nOperationStatus.data32
#define t_com55           nChargingStatus.data32//4byte
#define t_com56           nGaugingStatus.data32
#define t_com57           nManufacturingStatus.data
#define t_com58           nAFERegister
#define t_com59           com_data.comdat.com_MaxTurboPwr//
#define t_com5a           com_data.comdat.com_SusTurboPwr//
#define t_com5b           com_data.comdat.com_TurboPackR//
#define t_com5c           com_data.comdat.com_TurboSysR//
#define t_com5d           com_data.comdat.com_TurboEdv//
#define t_com5e           com_data.comdat.com_MPPCurrent//
#define t_com5f           com_data.comdat.com_SPPCurrent//
#define t_com60           com_data.comdat.com_ACDP
#define t_com61           com_data.comdat.com_ADP12S
#define t_com62           com_data.comdat.com_ADP10m
#define t_com68           com_data.comdat.com_TurboRhfEffective//
#define t_com69           com_data.comdat.com_TurboVload//
#define t_com6a           com_data.comdat.com_BatteryHealthState
#define t_com6b           com_data.comdat.com_BatteryLifeCycle
#define t_com6c           com_data.comdat.com_BatteryLifeSpan

#define t_com78           nFilteredCapacity.data

#define t_com88           com_data.comdat.com_DF_IRC          //t_com88; ideal rc 
#define t_com89           com_data.comdat.com_DF_IFCC         //t_com89; ideal fcc 
#define t_com8a           com_data.comdat.com_DF_IRSoc       //t_com8a;  ideal rsoc 

#define t_com60t           nLifeTimeDataBlock1//LifetimeDataBlock1() 
#define t_com61t           nLifeTimeDataBlock2//LifetimeDataBlock2() 
#define t_com62t           nLifeTimeDataBlock3//LifetimeDataBlock3() 
#define t_com63t           nLifeTimeDataBlock4.data//LifetimeDataBlock4() 
#define t_com64t           nLifeTimeDataBlock5.data//LifetimeDataBlock5() 
#define t_com65t           nLifeTimeDataBlock6//LifetimeDataBlock6() 
#define t_com66t           nLifeTimeDataBlock7//LifetimeDataBlock7() 
#define t_com67t           nLifeTimeDataBlock8//LifetimeDataBlock8() 
#define t_com6at           nLifeTimeDataBlock11//LifetimeDataBlock11() 
#define t_com6bt           nLifeTimeDataBlock12//LifetimeDataBlock12() 


extern uint16_t t_com00;

//extern PFStatus nPFStatus;//t_com53;//PFStatus()
extern ChargingStatus nChargingStatus;//t_com55;//ChargingStatus()
extern GaugingStatus nGaugingStatus;//t_com56;//GaugingStatus()

extern    uint8_t nAFERegister[21];         //t_com58;//AFERegister() 
extern    uint8_t nLifeTimeDataBlock1[32];  //t_com60t;//LifetimeDataBlock1() 
extern    uint8_t nLifeTimeDataBlock2[20];  //t_com61t;//LifetimeDataBlock2() 
extern    uint8_t nLifeTimeDataBlock3[4];   //t_com62t;//LifetimeDataBlock3() 
typedef struct
{
  uint16_t NoofCOVEvents ; //No. of COV Events
  uint16_t LastCOVEvent ;  //Last COV Event
  uint16_t NoofCUVEvents ; //No. of CUV Events
  uint16_t LastCUVEvent ;  //Last CUV Event
  uint16_t NoofOCD1Events ;//No. of OCD1 Events
  uint16_t LastOCD1Event ;// Last OCD1 Event
  uint16_t NoofOCD2Events;//No. of OCD2 Events
  uint16_t LastOCD2Event ; //Last OCD2 Event
  uint16_t NoofOCC1Events; //No. of OCC1 Events
  uint16_t LastOCC1Event; //Last OCC1 Event
  uint16_t NoofOCC2Events;//No. of OCC2 Events
  uint16_t LastOCC2Event;//Last OCC2 Event
  uint16_t NoofAOLDEvents;//No. of AOLD Events
  uint16_t LastAOLDEvent;//Last AOLD Event
  uint16_t NoofASCDEvents;//No. of ASCD Events
  uint16_t LastASCDEvent;//Last ASCD Event
}LIFETIME_DATA_BLOCK4;
typedef union 
{
  LIFETIME_DATA_BLOCK4 LifeTimeDataBlock4;
  uint8_t data[sizeof(LIFETIME_DATA_BLOCK4)];
}LIFETIMEDATABLOCK4;
extern LIFETIMEDATABLOCK4 nLifeTimeDataBlock4;
typedef struct
{
  uint16_t NoofASCCEvents; // No. of ASCC Events
  uint16_t LastASCCEvent; // Last ASCC Event
  uint16_t NoofOTCEvents; //No. of OTC Events
  uint16_t LastOTCEvent; //Last OTC Event
  uint16_t NoofOTDEvents; // No. of OTD Events
  uint16_t LastOTDEvent; // Last OTD Event
  uint16_t NoofOTFEvents; //No. of OTF Events
  uint16_t LastOTFEvent; //Last OTF Event
  uint16_t NoValidChargeTerm; //No. Valid Charge Term
  uint16_t LastValidChargeTerm; //Last Valid Charge Term
  uint16_t NoofQmaxUpdates;//No. of Qmax Updates
  uint16_t LastQmaxUpdate;//LastQmaxUpdate
  uint16_t NoofRaUpdates;//No. of Ra Updates
  uint16_t LastRaUpdate;//Last Ra Update
  uint16_t NoofRaDisable;//No. of Ra Disable
  uint16_t LastRaDisable;//Last Ra Disable
}LIFETIME_DATA_BLOCK5;
typedef union 
{
  LIFETIME_DATA_BLOCK5 LifeTimeDataBlock5;
  uint8_t data[sizeof(LIFETIME_DATA_BLOCK5)];
}LIFETIMEDATABLOCK5;
extern LIFETIMEDATABLOCK5 nLifeTimeDataBlock5;

extern    uint8_t nLifeTimeDataBlock6[32];  //t_com65t;//LifetimeDataBlock6() 
extern    uint8_t nLifeTimeDataBlock7[32];  //t_com66t;//LifetimeDataBlock7() 
extern    uint8_t nLifeTimeDataBlock8[32];  //t_com67t;//LifetimeDataBlock8() 
extern    uint8_t nLifeTimeDataBlock11[32]; //t_com6at;//LifetimeDataBlock11() 
extern    uint8_t nLifeTimeDataBlock12[32]; //t_com6bt;//LifetimeDataBlock12() 

typedef struct
{
  uint16_t Filt_remain_cap;//Filtered remaining capacity
  uint16_t Filt_remain_egy;//Filtered remaining energy 
  uint16_t Fil_fullChg_cap;//Filtered full charge capacity
  uint16_t Fil_fullChg_egy;//Filtered full charge energy 
}FILTERED_CAP;
typedef union 
{
  FILTERED_CAP FilteredCapacity;
  uint8_t data[sizeof(FILTERED_CAP)];
}FILTEREDCAP;
extern    FILTEREDCAP nFilteredCapacity;     //t_com78;//FilteredCapacity()

typedef struct
{
  uint8_t RollingCounter;//Rolling 8-bit counter, increments when values are refreshed.
  uint8_t CalibrationStatus;//Status, 1 when ManufacturerAccess() = 0xF081, 2 when ManufacturerAccess() = 0xF082
  uint16_t CurrentCounter;//Current (coulomb counter)
  uint16_t RAWCellVoltage1;//Cell Voltage 1 
	uint16_t RAWCellVoltage2;//Cell Voltage 2 
	uint16_t RAWCellVoltage3;//Cell Voltage 3 
	uint16_t RAWCellVoltage4;//Cell Voltage 4 
	uint16_t RAWPACKVoltage;//PACK Voltage
	uint16_t RAWBATVoltage;//BAT Voltage
	int16_t RAWCellCurrent1;//Cell Current 1
	int16_t RAWCellCurrent2;//Cell Current 2
	int16_t RAWCellCurrent3;//Cell Current 3
	int16_t RAWCellCurrent4;//Cell Current 4
}RAWCALIBRATION;
typedef union 
{
  RAWCALIBRATION RawCalibration;
  uint8_t data[sizeof(RAWCALIBRATION)];
}RAWCAL;


#pragma pack(1)
typedef union
{
	uint8_t data[35];
	struct
	{
    uint8_t  nMacLen;
		uint16_t nAltManufacturerAccess; 
		uint8_t  nMACData[32];
	}_MAC_T;
	
}_Mac;
#pragma pack()

extern _Mac  t_com44;
extern float Ts_max;
extern float Ts_min;
extern float aveTemp;
extern float FETTemp;
extern int32_t  V_min;
extern int32_t  V_max;
extern uint16_t  I_abs;
extern uint16_t  tmin;
extern uint8_t f_study_d1;
extern uint8_t f_study_d2;
extern uint16_t D_0PVOLT ;

#endif

