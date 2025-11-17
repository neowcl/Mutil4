#ifndef __SBS_COMMANDS_H__
#define __SBS_COMMANDS_H__
#include "main.h"
#ifdef __cplusplus
extern "C"
{
#endif

// #define BatteryMode()       (_BatteryMode.value)        // 0x03
#define Temperature()       (_DAStatus2.CellTemperature)    // 0x08
#define Voltage()           (_DAStatus1.BatVoltage)         // 0x09
#define Current()           (_DAStatus1.CellCurrnet1)       // 0x0A
#define AverageCurrent()    ()                              // 0x0B
// #define BatteryStatus()     (_BatteryStatus.value)       // 0x16
// #define SpecificationInfo() (_SpecificationInfo.value)  // 0x1A
#define FETTemperature()    (_DAStatus2.FETTemperature)     // 0x3B
#define PackVoltage()       (_DAStatus1.PackVoltage)        // 0x47

#define FW_TYPE               0x02  //软件类型
<<<<<<< HEAD
#define FW_VERSION            0x0108 //软件版本号    //  log data cell voltage for dsg_upda
=======
#define FW_VERSION            0x0107 //软件版本号    //  log data cell voltage for dsg_upda
>>>>>>> 9ba71db85809110976611cd81ed0edd11df5e1e7

#pragma pack(push, 1)
    typedef struct
    {
        uint16_t DeviceNumber;           // Device Number
        uint16_t Version;               // Version  Firmware Version  ---0x0002
        uint8_t FirewareType;           // Fireware Type
        uint16_t BuildNumber;           // Build Number   ---0x0002
        uint16_t ImpedanceTrackVersion; // Impedance Track Version
    } FirmwareVersion;
#pragma pack(pop)


#pragma pack(push, 1)
    typedef struct
    {
        uint16_t CellVoltage1;
        uint16_t CellVoltage2;
        uint16_t CellVoltage3;
        uint16_t CellVoltage4;
        uint16_t BatVoltage;
        uint16_t PackVoltage;
        int16_t CellCurrnet1;
        int16_t CellCurrnet2;
        int16_t CellCurrnet3;
        int16_t CellCurrnet4;
        int16_t CellPower1;
        int16_t CellPower2;
        int16_t CellPower3;
        int16_t CellPower4;
        int16_t Power;
        int16_t AveragePower;
    } DAStatus1;
#pragma pack(pop)

#pragma pack(push, 1)
    typedef struct
    {
        uint16_t IntTemperature;
        uint16_t TS1Temperature;
        uint16_t TS2Temperature;
        uint16_t TS3Temperature;
        uint16_t TS4Temperature;
        uint16_t CellTemperature;
        uint16_t FETTemperature;
        // uint16_t GaugingTemperature;
    } DAStatus2;
#pragma pack(pop)

#pragma pack(push, 1)
    typedef struct
    {
        uint16_t TrueRemQ;
        uint16_t TrueRemE;
        uint16_t InitialQ;
        uint16_t InitialE;
        uint16_t TrueFCCQ;
        uint16_t TrueFCCE;
        uint16_t T_sim;
        uint16_t T_ambient;
        uint16_t CompRes0;
        uint16_t CompRes1;
        uint16_t CompRes2;
        uint16_t CompRes3;
    } GaugeStatus1;
#pragma pack(pop)

#pragma pack(push, 1)
    typedef struct
    {
        uint8_t PackGrid;     // Pack Grid
        uint8_t LStatus;      // Learned status of resistance table
        uint8_t CellGrid0;    // Cell Grid 0
        uint8_t CellGrid1;    // Cell Grid 1
        uint8_t CellGrid2;    // Cell Grid 2
        uint8_t CellGrid3;    // Cell Grid 3
        uint32_t StateTime;   // State Time
        uint16_t DOD0_0;      // DOD0_0. Depth of discharge for Cell 1
        uint16_t DOD0_1;      // DOD0_1. Depth of discharge for Cell 2
        uint16_t DOD0_2;      // DOD0_2. Depth of discharge for Cell 3
        uint16_t DOD0_3;      // DOD0_3. Depth of discharge for Cell 4
        uint16_t DOD0PassedQ; // DOD0 Passed Q. Passed capacity since the last DOD0 update
        uint16_t DOD0PassedE; // DOD0 Passed E. Passed energy since last DOD0 update
        uint16_t DOD0Time;    // DOD0 Time. Time passed since the last DOD0 update
        uint16_t DODEOC0;     // DODEOC 0. Depth of discharge at end of charge of Cell 1
        uint16_t DODEOC1;     // DODEOC 1. Depth of discharge at end of charge of Cell 2
        uint16_t DODEOC2;     // DODEOC 2. Depth of discharge at end of charge of Cell 3
        uint16_t DODEOC3;     // DODEOC 3. Depth of discharge at end of charge of Cell 4
    } GaugeStatus2;
#pragma pack(pop)

#pragma pack(push, 2)
    typedef struct
    {
        uint16_t QMax0;
        uint16_t QMax1;
        uint16_t QMax2;
        uint16_t QMax3;
    } GaugeStatus3;
#pragma pack(pop)

#pragma pack(push, 2)
    typedef struct
    {
        uint16_t Time0;
        uint16_t Time1;
        uint16_t Time2;
        uint16_t Time3;
    } CBStatus;
#pragma pack(pop)

#pragma pack(push, 4)
    typedef union
    {
        uint32_t value;
        struct
        {
            uint32_t CUV : 1;
            uint32_t COV : 1;
            uint32_t OCC1 : 1;
            uint32_t OCC2 : 1;
            uint32_t OCD1 : 1;
            uint32_t OCD2 : 1;
            uint32_t : 1;
            uint32_t AOLDL : 1;
            uint32_t : 1;
            uint32_t ASCCL : 1;
            uint32_t : 1;
            uint32_t ASCDL : 1;
            uint32_t OTC : 1;
            uint32_t OTD : 1;
            uint32_t CUVC : 1;
            uint32_t VSP : 1; // NEW
            uint32_t OTF : 1;
            uint32_t : 1;
            uint32_t PTO : 1;
            uint32_t PTOS : 1;
            uint32_t CTO : 1;
            uint32_t CTOS : 1;
            uint32_t OC : 1;
            uint32_t CHGC : 1;
            uint32_t CHGV : 1;
            uint32_t PCHGC : 1;
            uint32_t UTC : 1;
            uint32_t UTD : 1;
            uint32_t COVL : 1;
            uint32_t OCDL : 1;
            uint32_t : 2;
        } bits;
    } SafetyAlert; // 0X0050
#pragma pack(pop)
#define SafetyAlert(bit)    (_SafetyAlert.bits.bit)

#pragma pack(push, 4)
    typedef union
    {
        uint32_t value;
        struct
        {
            uint32_t CUV : 1;
            uint32_t COV : 1;
            uint32_t OCC1 : 1;
            uint32_t OCC2 : 1;
            uint32_t OCD1 : 1;
            uint32_t OCD2 : 1;
            uint32_t AOLD : 1;
            uint32_t AOLDL : 1;

            uint32_t ASCC : 1;
            uint32_t ASCCL : 1;
            uint32_t ASCD : 1;
            uint32_t ASCDL : 1;
            uint32_t OTC : 1;
            uint32_t OTD : 1;
            uint32_t CUVC : 1;
            uint32_t VSP : 1; // NEW

            uint32_t OTF : 1;
            uint32_t HWD : 1;
            uint32_t PTO : 1;
            uint32_t : 1;
            uint32_t CTO : 1;
            uint32_t : 1;
            uint32_t OC : 1;
            uint32_t CHGC : 1;
            
            uint32_t CHGV : 1;
            uint32_t PCHGC : 1;
            uint32_t UTC : 1;
            uint32_t UTD : 1;
            uint32_t COVL : 1;
            uint32_t OCDL : 1;
        
            uint32_t : 2;
        } bits;
    } SafetyStatus; // 0X0051
#pragma pack(pop)
#define SafetyStatus(bit)    (_SafetyStatus.bits.bit)

#pragma pack(push, 4)
    typedef union
    {
        uint32_t value;
        struct
        {
            uint32_t SUV : 1;
            uint32_t SOV : 1;
            uint32_t SOCC : 1;
            uint32_t SOCD : 1;
            uint32_t SOT : 1;
            uint32_t COVL : 1;
            uint32_t SOTF : 1;
            uint32_t QIM : 1;
            uint32_t CB : 1;
            uint32_t IMP : 1;
            uint32_t CD : 1;
            uint32_t VIMR : 1;
            uint32_t VIMA : 1;
            uint32_t AOLDL : 1;
            uint32_t ASCCL : 1;
            uint32_t ASCDL : 1;
            uint32_t CFETF : 1;
            uint32_t DFETF : 1;
            uint32_t OCDL : 1;
            uint32_t FUSE : 1;
            uint32_t AFER : 1;
            uint32_t AFEC : 1;
            uint32_t _2LVL : 1;
            uint32_t : 3;
            uint32_t TCO : 1;
            uint32_t VSP : 1; // NEW
            uint32_t TS1 : 1;
            uint32_t TS2 : 1;
            uint32_t TS3 : 1;
            uint32_t TS4 : 1;
        } bits;
    } PFAlert; // 0X0052
#pragma pack(pop)
#define PFAlert(bit) (_PFAlert.bits.bit)
#define f_pf_suv_a    _PFAlert.bits.SUV
#define f_pf_sov_a    _PFAlert.bits.SOV
#define f_pf_socc_a   _PFAlert.bits.SOCC
#define f_pf_socd_a   _PFAlert.bits.SOCD
#define f_pf_sot_a    _PFAlert.bits.SOT
#define f_pf_covl_a   _PFAlert.bits.COVL
#define f_pf_sotf_a   _PFAlert.bits.SOTF
#define f_pf_qim_a    _PFAlert.bits.QIM
#define f_pf_cb_a     _PFAlert.bits.CB
#define f_pf_imp_a    _PFAlert.bits.IMP
#define f_pf_cd_a     _PFAlert.bits.CD
#define f_pf_vimr_a   _PFAlert.bits.VIMR
#define f_pf_vima_a   _PFAlert.bits.VIMA
#define f_pf_aoldl_a  _PFAlert.bits.AOLDL
#define f_pf_asccl_a  _PFAlert.bits.ASCCL
#define f_pf_ascdl_a  _PFAlert.bits.ASCDL
#define f_pf_cfetf_a  _PFAlert.bits.CFETF
#define f_pf_dfetf_a  _PFAlert.bits.DFETF
#define f_pf_ocdl_a   _PFAlert.bits.OCDL
#define f_pf_fuse_a   _PFAlert.bits.FUSE
#define f_pf_afer_a   _PFAlert.bits.AFER
#define f_pf_afec_a   _PFAlert.bits.AFEC
#define f_pf_2lvl_a   _PFAlert.bits._2LVL
#define f_pf_tco_a    _PFAlert.bits.TCO
#define f_pf_vsp_a    _PFAlert.bits.VSP
#define f_pf_ts1_a    _PFAlert.bits.TS1
#define f_pf_ts2_a    _PFAlert.bits.TS2
#define f_pf_ts3_a    _PFAlert.bits.TS3
#define f_pf_ts4_a    _PFAlert.bits.TS4

#pragma pack(push, 4)
    typedef union
    {
        uint32_t value;
        struct
        {
            uint32_t SUV : 1;
            uint32_t SOV : 1;
            uint32_t SOCC : 1;
            uint32_t SOCD : 1;
            uint32_t SOT : 1;
            uint32_t COVL : 1;
            uint32_t SOTF : 1;
            uint32_t QIM : 1;
            uint32_t CB : 1;
            uint32_t IMP : 1;
            uint32_t CD : 1;
            uint32_t VIMR : 1;
            uint32_t VIMA : 1;
            uint32_t AOLDL : 1;
            uint32_t ASCCL : 1;
            uint32_t ASCDL : 1;
            uint32_t CFETF : 1;
            uint32_t DFETF : 1;
            uint32_t OCDL : 1;
            uint32_t FUSE : 1;
            uint32_t AFER : 1;
            uint32_t AFEC : 1;
            uint32_t _2LVL : 1;
            uint32_t PTC : 1;
            uint32_t IFC : 1;
            uint32_t FORCE : 1;
            uint32_t TCO : 1;
            uint32_t VSP : 1; // NEW
            uint32_t TS1 : 1;
            uint32_t TS2 : 1;
            uint32_t TS3 : 1;
            uint32_t TS4 : 1;
        } bits;
    } PFStatus; // 0X0053
#pragma pack(pop)
#define PFStatus(bit)   (_PFStatus.bits.bit)
#define f_pf_suv_p    _PFStatus.bits.SUV
#define f_pf_sov_p    _PFStatus.bits.SOV
#define f_pf_socc_p   _PFStatus.bits.SOCC
#define f_pf_socd_p   _PFStatus.bits.SOCD
#define f_pf_sot_p    _PFStatus.bits.SOT
#define f_pf_covl_p   _PFStatus.bits.COVL
#define f_pf_sotf_p   _PFStatus.bits.SOTF
#define f_pf_qim_p    _PFStatus.bits.QIM

#define f_pf_cb_p     _PFStatus.bits.CB
#define f_pf_imp_p    _PFStatus.bits.IMP
#define f_pf_cd_p     _PFStatus.bits.CD
#define f_pf_vimr_p   _PFStatus.bits.VIMR
#define f_pf_vima_p   _PFStatus.bits.VIMA
#define f_pf_aoldl_p  _PFStatus.bits.AOLDL
#define f_pf_asccl_p  _PFStatus.bits.ASCCL
#define f_pf_ascdl_p  _PFStatus.bits.ASCDL

#define f_pf_cfetf_p  _PFStatus.bits.CFETF
#define f_pf_dfetf_p  _PFStatus.bits.DFETF
#define f_pf_ocdl_p   _PFStatus.bits.OCDL
#define f_pf_fuse_p   _PFStatus.bits.FUSE
#define f_pf_afer_p   _PFStatus.bits.AFER
#define f_pf_afec_p   _PFStatus.bits.AFEC
#define f_pf_2lvl_p   _PFStatus.bits._2LVL

#define f_pf_tco_p    _PFStatus.bits.TCO
#define f_pf_vsp_p    _PFStatus.bits.VSP
#define f_pf_ts1_p    _PFStatus.bits.TS1
#define f_pf_ts2_p    _PFStatus.bits.TS2
#define f_pf_ts3_p    _PFStatus.bits.TS3
#define f_pf_ts4_p    _PFStatus.bits.TS4

#pragma pack(push, 2)
    typedef union
    {
        uint16_t value;
        struct
        {
            uint16_t ICC : 1;
            uint16_t PBS : 1;
            uint16_t GRN_BK : 1;
            uint16_t : 2;
            uint16_t WARR : 1;
            uint16_t : 1;
            uint16_t CF : 1;
            uint16_t CC : 1;
            uint16_t PB : 1;
            uint16_t : 3;
            uint16_t AM : 1;
            uint16_t CHGM : 1;
            uint16_t CAPM : 1;
        } bits;
    } BatteryMode;
#pragma pack(pop)
#define BatteryMode(bit) (_BatteryMode.bits.bit)

#pragma pack(push, 2)
    typedef union
    {
        uint16_t value;
        struct
        {
            uint16_t EC0 : 1;
            uint16_t EC1 : 1;
            uint16_t EC2 : 1;
            uint16_t EC3 : 1;
            uint16_t FD : 1;
            uint16_t FC : 1;
            uint16_t DSG : 1;
            uint16_t INIT : 1;
            uint16_t RTA : 1;
            uint16_t RCA : 1;
            uint16_t CIMA : 1;
            uint16_t TDA : 1;
            uint16_t OTA : 1;
            uint16_t : 1;
            uint16_t TCA : 1;
            uint16_t OCA : 1;
        } bits;
    } BatteryStatus;
#pragma pack(pop)
#define BatteryStatus(bit) (_BatteryStatus.bits.bit)

#pragma pack(push, 2)
    typedef union
    {
        uint16_t value;
        struct
        {
            uint16_t Revision : 4;
            uint16_t Version : 4;
            uint16_t VScale : 4;
            uint16_t IPScale : 4;
        } bits;
    } SpecificationInfo;
#pragma pack(pop)
#define SpecificationInfo(bit) (_SpecificationInfo.bits.bit)

#pragma pack(push, 1)
    typedef union
    {
        uint8_t data[33];
        struct
        {
            uint8_t length;
            uint8_t data[32];
        } m_block;
        struct
        {
            uint8_t SoftwareModel;
            uint8_t SoftwareVersion;
            uint8_t EEPROM_Type;
            uint8_t EEPROM_Version;
            uint8_t CellVoltage4MSB;
            uint8_t CellVoltage4LSB;
            uint8_t CellVoltage3MSB;
            uint8_t CellVoltage3LSB;
            uint8_t CellVoltage2MSB;
            uint8_t CellVoltage2LSB;
            uint8_t CellVoltage1MSB;
            uint8_t CellVoltage1LSB;
            uint8_t InterfaceSpecVersionMSB;
            uint8_t InterfaceSpecVersionLSB;
        } m_Lenovo_Data;

    } Block;
#pragma pack(pop)

#pragma pack(push, 1)
    typedef struct
    {
        uint16_t TotalCharged;
        uint16_t TotalFWRunTime;
        uint16_t HiVoltTime;
        uint16_t HiTempTime;
        uint16_t HiTempVoltTime;
    } BatteryCondition;
#pragma pack(pop)

#pragma pack(push, 1)
    typedef struct
    {
        uint16_t Time;
        uint16_t Cell4;
        uint16_t Cell3;
        uint16_t Cell2;
        uint16_t Cell1;
        int16_t Current;
        uint16_t Cell_Temp;
        uint16_t FET_Temp;
    } PFSnapShot;
#pragma pack(pop)





#pragma pack(push, 2)
    typedef union
    {
        uint16_t value;
        struct
        {
            uint16_t CAP_CORR : 1;
            uint16_t OPEN_SYS_USE1 : 1;
            uint16_t OPEN_SYS_USE2 : 1;
            uint16_t AUTH0 : 1;
            uint16_t AUTH1 : 1;
            uint16_t RSOC_ABOVE_LIMIT : 1;
            uint16_t FCC_AUTO_CAL : 1;
            uint16_t NR : 1;
            uint16_t DM_SUPP : 1;
            uint16_t DMSTA0 : 1;
            uint16_t DMSTA1 : 1;
            uint16_t DMSTA2 : 1;
            uint16_t CAP_DEG : 1;
            uint16_t SPEC0 : 1;
            uint16_t SPEC1 : 1;
            uint16_t SPEC2 : 1;
        } bits;
    } OptCommand2;
#pragma pack(pop)
#define OptCommand2(bit) (_OptCommand2.bits.bit)

    extern uint16_t Device_Type;
    extern FirmwareVersion Firmware_Version;
    extern uint8_t Hardware_Version[];

#pragma pack(push, 1)
    typedef struct
    {
        uint16_t MaxPeakPower;
        uint16_t SusPeakPower;
        uint16_t PackResistance;
        uint16_t SystemResistance;
        uint16_t MinSysVoltage;
       
        uint16_t MPPCurrent;
        uint16_t SPPCurrent;
    } DBPT_Value;
#pragma pack(pop)
    


extern DBPT_Value t_DBPT;
extern uint16_t _RemainingCapacityAlarm;           /*0x01*/
/*0x02*/
extern BatteryMode _BatteryMode;                   /*0x03*/
extern int16_t _AtRate;                            /*0x04*/
extern uint16_t _AtRateTimeToFull;                 /*0x05*/
extern uint16_t _AtRateTimeToEmpty;                /*0x06*/
extern uint16_t _AtRateOK;                         /*0x07*/
/*0x08*/
/*0x09*/
/*0x0A*/
extern int16_t _AverageCurrent;                    /*0x0B*/
/*0x0C*/
/*0x0D*/
/*0x0E*/
/*0x0F*/
/*0x10*/
extern uint16_t _RunTimeToEmpty;                   /*0x11*/
extern uint16_t _AverageTimeToEmpty;               /*0x12*/
extern uint16_t _AverageTimeToFull;                /*0x13*/
extern uint16_t _ChargingCurrent;                  /*0x14*/
extern uint16_t _ChargingVoltage;                  /*0x15*/
extern BatteryStatus _BatteryStatus;               /*0x16*/
extern uint16_t _CycleCount;                       /*0x17*/
extern uint16_t _DesignCapacity;                   /*0x18*/
extern uint16_t _DesignVoltage;                    /*0x19*/
extern SpecificationInfo _SpecificationInfo;       /*0x1A*/
/*0x1B*/
/*0x1C*/
/*0x20*/
/*0x21*/
/*0x22*/
extern Block _ManufacturerData;                    /*0x23*/
extern uint16_t _TrueRemCap;                       /*0x24*/
extern uint16_t _TrueFCC;                          /*0x25*/
extern uint8_t _AuthCahllenge[];                   /*0x27*/
extern uint8_t _AuthResponse[];                    /*0x28*/
extern uint16_t _AIPIModeControl;                  /*0x2A*/
extern uint8_t _sha1_reslut[];                     /*0x2F*/
extern BatteryCondition _BatteryCondition;         /*0x30*/
extern PFSnapShot _PFSnapShot;                     /*0x31*/      
extern uint8_t _BatteryLogData2[];                 /*0x32*/
extern uint16_t _FETCtrl;                          /*0x34*/
extern uint8_t _ReadBatteryInfo[];                 /*0x37*/
extern uint16_t _WarrantyPeriod[16];               /*0x38*/
extern OptCommand2 _OptCommand2;                   /*0x3E*/
extern uint16_t _OptCommand1;                      /*0x3F*/
extern uint16_t _SoH;                              /*0x4F*/
extern SafetyAlert _SafetyAlert;                   /*0x50*/
extern SafetyStatus _SafetyStatus;                 /*0x51*/
extern PFAlert _PFAlert;                           /*0x52*/
extern PFStatus _PFStatus;                         /*0x53*/
extern DAStatus1 _DAStatus1;                       /*0x71*/
extern DAStatus2 _DAStatus2;                       /*0x72*/
extern GaugeStatus1 _GaugeStatus1;                 /*0x73*/
extern GaugeStatus2 _GaugeStatus2;                 /*0x74*/
extern GaugeStatus3 _GaugeStatus3;                 /*0x75*/
extern CBStatus _CBStatus;                         /*0x76*/
extern uint16_t _SMBAddr;                          /*0xA2*/
extern uint16_t _EntryShipModeCount;               /*0xA4*/
extern uint16_t _EntryExitShipCondition;           /*0xA5*/
extern uint16_t _ShipModeTimer;                    /*0xA6*/






extern uint16_t t_com31_out ;
extern uint16_t t_com32_out ;
extern uint16_t t_com33_out ;

extern uint16_t t_com39_out ;
extern uint16_t t_com3a_out ;


// extern uint16_t t_com3c_out ;
// extern uint16_t t_com3d_out ;


extern uint16_t t_com1d_out ;
extern uint16_t t_com1e_out ;
extern uint16_t t_com1f_out ;


extern uint16_t t_com41_out ;
extern uint16_t t_com42_out ;
extern uint16_t t_com43_out ;


extern uint16_t t_com8b_out ;
extern uint16_t t_com8c_out ;
extern uint16_t t_com8d_out ;
extern uint16_t t_com8e_out ;
extern uint16_t t_com8f_out ;

extern uint16_t t_com90_out ;
extern uint16_t t_com91_out ;
extern uint16_t t_com92_out ;
extern uint16_t t_com93_out ;
extern uint16_t t_com94_out ;
extern uint16_t t_com95_out ;
extern uint16_t t_com96_out ;

    void SBS_init();


#ifdef __cplusplus
}
#endif

#endif // __SBS_COMMANDS_H__