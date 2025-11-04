#include"SBS_Commands.h"

uint16_t Device_Type = 450;
FirmwareVersion Firmware_Version = {0x0000, FW_VERSION,FW_TYPE,0x0904, 0x0005};
uint8_t Hardware_Version[] = "SFG";


/*0x01*/uint16_t _RemainingCapacityAlarm;
/*0x02*/
BatteryMode _BatteryMode;                   /*0x03*/
int16_t _AtRate;                            /*0x04*/
uint16_t _AtRateTimeToFull;                 /*0x05*/
uint16_t _AtRateTimeToEmpty;                /*0x06*/
uint16_t _AtRateOK;                         /*0x07*/
/*0x08*/
/*0x09*/
/*0x0A*/
int16_t _AverageCurrent;                    /*0x0B*/
/*0x0C*/
/*0x0D*/
/*0x0E*/
/*0x0F*/
/*0x10*/
uint16_t _RunTimeToEmpty;                   /*0x11*/
uint16_t _AverageTimeToEmpty;               /*0x12*/
uint16_t _AverageTimeToFull;                /*0x13*/
uint16_t _ChargingCurrent;                  /*0x14*/
uint16_t _ChargingVoltage;                  /*0x15*/
BatteryStatus _BatteryStatus;               /*0x16*/
uint16_t _CycleCount;                       /*0x17*/
uint16_t _DesignCapacity;                   /*0x18*/
uint16_t _DesignVoltage;                    /*0x19*/
SpecificationInfo _SpecificationInfo;       /*0x1A*/
/*0x1B*/
/*0x1C*/
/*0x20*/
/*0x21*/
/*0x22*/
Block _ManufacturerData;                    /*0x23*/
uint16_t _TrueRemCap;                       /*0x24*/
uint16_t _TrueFCC;                          /*0x25*/
uint8_t _AuthCahllenge[0x20];                 /*0x27*/
uint8_t _AuthResponse[0x20] ;                /*0x28*/
 
uint16_t _AIPIModeControl;                  /*0x2A*/
uint8_t _sha1_reslut[0x14] = {0};                   /*0x2F*/

BatteryCondition _BatteryCondition;         /*0x30*/
PFSnapShot _PFSnapShot;                     /*0x31*/
uint8_t _BatteryLogData2[16];               /*0x32*/
uint16_t _FETCtrl;                          /*0x34*/
/*0x35*/
/*0x36*/
uint8_t _ReadBatteryInfo[0x08]              /*0x37*/
 = {0x01, 0x00, 0x4D, 0x04, 0x30, 0x00, 0x04, 0x06};
uint16_t _WarrantyPeriod[16];               /*0x38*/
OptCommand2 _OptCommand2;                   /*0x3E*/
uint16_t _OptCommand1;                      /*0x3F*/
uint16_t _SoH;                              /*0x4F*/
SafetyAlert _SafetyAlert;                   /*0x50*/
SafetyStatus _SafetyStatus;                 /*0x51*/
PFAlert _PFAlert;                           /*0x52*/
PFStatus _PFStatus;                         /*0x53*/
/*0x54*/
/*0x55*/
/*0x56*/
/*0x57*/
/*0x58*/
DBPT_Value t_DBPT;
/*0x60*/
/*0x61*/
/*0x62*/
/*0x6A*/
/*0x6B*/
/*0x6C*/
/*0x70*/
DAStatus1 _DAStatus1;                       /*0x71*/
DAStatus2 _DAStatus2;                       /*0x72*/
GaugeStatus1 _GaugeStatus1;                 /*0x73*/
GaugeStatus2 _GaugeStatus2;                 /*0x74*/
GaugeStatus3 _GaugeStatus3;                 /*0x75*/
CBStatus _CBStatus;                         /*0x76*/
/*0x77*/
/*0x78*/
/*0x90*/
uint16_t _SMBAddr;                          /*0xA2*/
uint16_t _EntryShipModeCount;               /*0xA4*/
uint16_t _EntryExitShipCondition;           /*0xA5*/
uint16_t _ShipModeTimer;                    /*0xA6*/


void SBS_init()
{
    t_com00 = 0x0018;
    // t_com03 = 0xE020;
    _BatteryMode.value = D_Initial_Battery_Mode;
    // Temperature() = 2980;
    // Voltage() = 15200;
    _RunTimeToEmpty = 0x0A9B;
    _AverageTimeToEmpty = 0x0b61;
    _AverageTimeToFull = 0xFFFF;
    _BatteryStatus.value = 0x00C0;
   // _CycleCount = D_State_Cycle_Count;//0x0118;
    _ChargingCurrent = 128;
    _ChargingVoltage = 17600;
    _DesignCapacity =  D_Design_Capacity_mAh;//BatteryMode(CAPM) ? D_Design_Capacity_in_cWh : D_Design_Capacity_mAh;
    _DesignVoltage = D_Design_Voltage;
    //memcpy(_OptCommand5,&D_Lenovo_Data_Bar_Code,0x0B);
    
    _OptCommand2.value = 0x0860;
    

    _SoH = 100;
    // t_com4b = 0x4220;
    
    
    
    
}