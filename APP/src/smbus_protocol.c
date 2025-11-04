#include "smbus_protocol.h"
#include "comm_protocol.h"
#include "modules_sha1.h"
#include "utility_sec.h"
uint16_t acomflg = 0;
volatile uint8_t aslvto_cnt = 0;
volatile uint16_t no_com_cnt = 0;
volatile uint8_t anosmb_ms = 0;
volatile uint16_t lowBus_cnt = 0;
// volatile uint16_t I2C_TimeOut_Count = 0;

volatile need_change_sha1_pwd=0;
_BMS_MAC eMac;
uint8_t g_RecvCnt = 0;
uint8_t tx_count = 0;
uint8_t rx_buffer[BUFFER_LEN] = {0};
uint8_t tx_buffer[BUFFER_LEN] = {0};
uint8_t pReg;

uint8_t cmd_last;

uint16_t Charge_Term=0;

uint8_t nReadLen = 0;
uint16_t nWriteLen = 0;
uint8_t MACDataLength = 0;

SC_Flag_T SC_Flag;
uint16_t DataFlash_W1;
uint16_t DataFlash_W2;
uint16_t blk_read_case_last;
volatile uint8_t apec = 0; // PEC

//uint16_t t_com57_1;

uint8_t NoLoadRemCap[2];   // No Load Rem Cap  0x005A No Load Rem Cap
uint8_t NoofPartialResets; // No. of Partial Resets
uint8_t NoofFullResets;    // No.of Full Resets
uint8_t NoofWDTResets;     // No.of WDT Resets
uint32_t TotalFWRuntime;   // Total FW Runtime

uint16_t State_of_HealthFCC;            // State-of-Health FCC FCC_SOH
uint16_t StateofHealthenergy;           // State-of-Health energy
uint16_t FilteredremainingcapacitymAh;  // State-of-Health FCC mAh
uint16_t FilteredfullchargecapacitymAh; // State-of-Health energy mAh

uint32_t AccumulatedTime;   // Accumulated Time
uint16_t AccumulatedCharge; // Accumulated Charge


uint16_t t_com1d_out ;
uint16_t t_com1e_out ;
uint16_t t_com1f_out ;


uint16_t t_com41_out ;
uint16_t t_com42_out ;
uint16_t t_com43_out ;



uint16_t t_com31_out ;
uint16_t t_com32_out ;
uint16_t t_com33_out ;

uint16_t t_com39_out ;
uint16_t t_com3a_out ;

uint16_t t_com8b_out ;
uint16_t t_com8c_out ;
uint16_t t_com8d_out ;
uint16_t t_com8e_out ;
uint16_t t_com8f_out ;

uint16_t t_com90_out ;
uint16_t t_com91_out ;
uint16_t t_com92_out ;

uint16_t t_com93_out ;
uint16_t t_com94_out ;
uint16_t t_com95_out ;


uint16_t t_com96_out ;


uint16_t t_coma0;
uint16_t t_coma1;


_ST_SMB ssmbdata;
const _ST_SMB scom_no_tbl[] =
    {
        {0x02, (uint8_t *)nOperationStatus.data},                         // 0x00
        {0x02, (uint8_t *)&_RemainingCapacityAlarm},         // 0x01 _RemainingCapacityAlarm()
        {0x02, (uint8_t *)&D_Data_Remaining_Time_Alarm},     // 0x02 RemainingTimeAlarm()
        {0x02, (uint8_t *)&_BatteryMode},                    // 0x03 BatteryMode()
        {0x02, (uint8_t *)&_AtRate},                         // 0x04 AtRate()
        {0x02, (uint8_t *)&_AtRateTimeToFull},               // 0x05 AtRateTimeToFull()
        {0x02, (uint8_t *)&_AtRateTimeToEmpty},              // 0x06 AtRateTimeToEmpty()
        {0x02, (uint8_t *)&_AtRateOK},                       // 0x07 AtRateOK()
        {0x02, (uint8_t *)&(_DAStatus2.CellTemperature)},    // 0x08 Temperature()
        {0x02, (uint8_t *)&Voltage()},                       // 0x09 Voltage()
        {0x02, (uint8_t *)&Current()},                       // 0x0a Current()
        {0x02, (uint8_t *)&_AverageCurrent},                 // 0x0b AverageCurrent()
        {0x02, (uint8_t *)&t_com0c},                         // 0x0c MaxError()
        {0x02, (uint8_t *)&t_com0d},                         // 0x0d RelativeStateOfCharge()
        {0x02, (uint8_t *)&t_com0e},                         // 0x0e AbsoluteStateOfCharge()
        {0x02, (uint8_t *)&t_com0fCap},                      // 0x0f RemainingCapacity()
        {0x02, (uint8_t *)&t_com10Cap},                      // 0x10 FullChargeCapacity()
        {0x02, (uint8_t *)&_RunTimeToEmpty},                 // 0x11 RunTimeToEmpty()
        {0x02, (uint8_t *)&_AverageTimeToEmpty},             // 0x12 AverageTimeToEmpty()
        {0x02, (uint8_t *)&_AverageTimeToFull},              // 0x13 AverageTimeToFull()
        {0x02, (uint8_t *)&_ChargingCurrent},                // 0x14 ChargingCurrent()
        {0x02, (uint8_t *)&_ChargingVoltage},                // 0x15 ChargingVoltage()
        {0x02, (uint8_t *)&_BatteryStatus},                  // 0x16 BatteryStatus()
        {0x02, (uint8_t *)&_CycleCount},                     // 0x17 CycleCount()
        {0x02, (uint8_t *)&_DesignCapacity},                 // 0x18 DesignCapacity()
        {0x02, (uint8_t *)&_DesignVoltage},                  // 0x19 DesignVoltage()
        {0x02, (uint8_t *)&_SpecificationInfo},              // 0x1a SpecificationInfo()
        {0x02, (uint8_t *)&D_Data_Manufacturer_Date},        // 0x1b ManufacturerDate()
        {0x02, (uint8_t *)&D_Data_Serial_Number},            // 0x1c SerialNumber()
        {0x02, (uint8_t *)&t_com1d_out},                             // 0x1d
        {0x02, (uint8_t *)&t_com1e_out},                             // 0x1e
        {0x02, (uint8_t *)&t_com1f_out},                             // 0x1f
        {0x15, (uint8_t *)&D_Data_Manufacturer_Name[1]},         // 0x20 ManufacturerName()
        {0x15, (uint8_t *)&D_Data_Device_Name[1]},               // 0x21 DeviceName()
        {0x05, (uint8_t *)&D_Data_Device_Chemistry[1]},          // 0x22 DeviceChemistry()
        {0x21, (uint8_t *)&_ManufacturerData},               // 0x23 ManufacturerData()
        {0x02, (uint8_t *)&t_com24},                         // 0x24
        {0x02, (uint8_t *)&t_com25},                         // 0x25
        {0x02, (uint8_t *)&t_com26},                         // 0x26
        {0x20, (uint8_t *)_AuthCahllenge},                   // 0x27
        {0x20, (uint8_t *)_AuthResponse},                    // 0x28
        {0x02, (uint8_t *)&UF_BackupREG},                             // 0x29
        {0x0C, (uint8_t *)0x08013FF0},                       // 0x2a
        {0x02, (uint8_t *)&t_com2b},                         // 0x2b
        {0x02, (uint8_t *)&t_com2c},                         // 0x2c
        {0x02, (uint8_t *)&lrcdr_w},                         // 0x2d
        {0x02, (uint8_t *)NULL},                             // 0x2e
        {0x14, (uint8_t *)_sha1_reslut},                     // 0x2f OptCommand5()
        {0x0B, (uint8_t *)NULL},                          // 0x30
        {0x02, (uint8_t *)&t_com31_out},                          // 0x31
        {0x02, (uint8_t *)&t_com32_out},                             // 0x32
        {0x02, (uint8_t *)&t_com33_out},                          // 0x33
        {0x02, (uint8_t *)&_FETCtrl},                        // 0x34  shipmode
        {0x02, (uint8_t *)NULL},                             // 0x35
        {0x08, (uint8_t *)NULL},                             // 0x36
        {0x08, (uint8_t *)_ReadBatteryInfo},                 // 0x37
        {0x11, (uint8_t *)_WarrantyPeriod},                  // 0x38
        {0x02, (uint8_t *)&t_com39_out},                             // 0x39
        {0x02, (uint8_t *)&t_com3a_out},                             // 0x3a
        {0x02, (uint8_t *)&FETTemperature()},                // 0x3b
        {0x02, (uint8_t *)&(_DAStatus1.CellVoltage4)},       // 0x3c
        {0x02, (uint8_t *)&(_DAStatus1.CellVoltage3)},       // 0x3d
        {0x02, (uint8_t *)&(_DAStatus1.CellVoltage2)},       // 0x3e
        {0x02, (uint8_t *)&(_DAStatus1.CellVoltage1)},       // 0x3f
        {0x02, (uint8_t *)&_OptCommand2},                       // 0x40 CellVoltage1()
        {0x02, (uint8_t *)&t_com41_out},                             // 0x41 CellVoltage2()
        {0x02, (uint8_t *)&t_com42_out},                             // 0x42 CellVoltage3()
        {0x02, (uint8_t *)&t_com43_out},                             // 0x43 CellVoltage4()
        {0x35, (uint8_t *)t_com44.data},                     // 0x44
        {0x20, (uint8_t *)NULL},                             // 0x45
        {0x02, (uint8_t *)NULL},                             // 0x46
        {0x02, (uint8_t *)&(_DAStatus1.PackVoltage)},        // 0x47
        {0x02, (uint8_t *)&t_com48},                         // 0x48 GPIORead()
        {0x02, (uint8_t *)&t_com49},                         // 0x49 GPIOWrite()
        {0x02, (uint8_t *)&t_com4a},                         // 0x4a BTPDischargeSet()
        {0x02, (uint8_t *)&_GaugeStatus3.QMax0},                             // 0x4b BTPChargeSet()
        {0x02, (uint8_t *)&_GaugeStatus3.QMax1},                             // 0x4c
        {0x02, (uint8_t *)&_GaugeStatus3.QMax2},                             // 0x4d
        {0x02, (uint8_t *)&_GaugeStatus3.QMax3},                             // 0x4e
        {0x02, (uint8_t *)&_SoH},                            // 0x4f StateofHealth()
        {0x04, (uint8_t *)&_SafetyAlert},                // 0x50 SafetyAlert()
        {0x04, (uint8_t *)&_SafetyStatus},               // 0x51 SafetyStatus()
        {0x04, (uint8_t *)&_PFAlert},                    // 0x52 PFAlert()
        {0x04, (uint8_t *)&_PFStatus},                   // 0x53 PFStatus
        {0x04, (uint8_t *)nOperationStatus.data},            // 0x54 OperationStatus()
        {0x04, (uint8_t *)nChargingStatus.data},             // 0x55 ChargingStatus()
        {0x04, (uint8_t *)nGaugingStatus.data},              // 0x56 GaugingStatus()
        {0x04, (uint8_t *)&t_com57},                         // 0x57 ManufacturingStatus()
        {0x15, (uint8_t *)t_com58},                          // 0x58 AFERegister()
        {0x02, (uint8_t *)&t_DBPT.MaxPeakPower},                         // 0x59 MaxTurboPwr()
        {0x02, (uint8_t *)&t_DBPT.SusPeakPower},                         // 0x5a SusTurboPwr()
        {0x02, (uint8_t *)&t_DBPT.PackResistance},                         // 0x5b TurboPackR()
        {0x02, (uint8_t *)&t_DBPT.SystemResistance},                         // 0x5c TurboSysR()
        {0x02, (uint8_t *)&t_DBPT.MinSysVoltage},                         // 0x5d TurboEdv()
        {0x02, (uint8_t *)&t_DBPT.MPPCurrent},                         // 0x5e MaxTurboCurr()
        {0x02, (uint8_t *)&t_DBPT.SPPCurrent},                         // 0x5f SusTurboCurr()
        {0x02, (uint8_t *)&t_com60},                         // 0x60 Available Continuous Discharge Power
        {0x02, (uint8_t *)&t_com61},                         // 0x61
        {0x02, (uint8_t *)&t_com62},                         // 0x62
        {0x20, (uint8_t *)t_com63t},                         // 0x63 LifetimeDataBlock4()
        {0x20, (uint8_t *)t_com64t},                         // 0x64 LifetimeDataBlock5()
        {0x20, (uint8_t *)t_com65t},                         // 0x65 LifetimeDataBlock6()
        {0x20, (uint8_t *)t_com66t},                         // 0x66 LifetimeDataBlock7()
        {0x20, (uint8_t *)t_com67t},                         // 0x67 LifetimeDataBlock8()
        {0x02, (uint8_t *)&t_com68},                         // 0x68 TurboRhfEffective()
        {0x02, (uint8_t *)&t_com69},                         // 0x69 TurboVload()
        {0x02, (uint8_t *)&t_com6a},                         // 0x6a
        {0x02, (uint8_t *)&t_com6b},                         // 0x6b
        {0x02, (uint8_t *)&t_com6c},                         // 0x6c
        {0x02, (uint8_t *)NULL},                             // 0x6d
        {0x02, (uint8_t *)NULL},                             // 0x6e
        {0x02, (uint8_t *)NULL},                             // 0x6f
        {0x20, (uint8_t *)&D_Manufacturer_Info_B01}, // 0x70 ManufacturerInfo()
        {sizeof(_DAStatus1), (uint8_t *)&_DAStatus1},        // 0x71 DAStatus1()
        {sizeof(_DAStatus2), (uint8_t *)&_DAStatus2},        // 0x72 DAStatus2()
        {sizeof(_GaugeStatus1), (uint8_t *)&_GaugeStatus1},  // 0x73 GaugeStatus1()
        {sizeof(_GaugeStatus2), (uint8_t *)&_GaugeStatus2},  // 0x74 GaugeStatus2()
        {sizeof(_GaugeStatus3), (uint8_t *)&_GaugeStatus3},  // 0x75 GaugeStatus3()
        {sizeof(_CBStatus), (uint8_t *)&_CBStatus},          // 0x76 CBStatus()
        {0x13, (uint8_t *)&_SoH},                            // 0x77 ()  real is t_c0m4f
        {0x04, (uint8_t *)t_com78},                          // 0x78 FilteredCapacity()
        {0x02, (uint8_t *)&t_com79},                         // 0x79 ()
        {0x20, (uint8_t *)&D_Manufacturer_Info_C01},             // 0x7a ()
        {0x02, (uint8_t *)&D_Manufacturer_ManufacturerInfo},             // 0x7b ()
        {0x02, (uint8_t *)&_GaugeStatus3.QMax2},             // 0x7c ()
        {0x02, (uint8_t *)&_GaugeStatus3.QMax3},             // 0x7d ()
        {0x02, (uint8_t *)&LifeTimes_Cell_3_Max_Voltage},    // 0x7e ()
        {0x02, (uint8_t *)&LifeTimes_Cell_4_Max_Voltage},    // 0x7f ()
        {0x02, (uint8_t *)&LifeTimes_Cell_1_Min_Voltage},    // 0x80 ()
        {0x02, (uint8_t *)&LifeTimes_Cell_2_Min_Voltage},    // 0x81 ()
        {0x02, (uint8_t *)&LifeTimes_Cell_3_Min_Voltage},    // 0x82 ()
        {0x02, (uint8_t *)&LifeTimes_Cell_4_Min_Voltage},    // 0x83 ()
        {0x02, (uint8_t *)&LifeTimes_Max_Charge_Current},    // 0x84 ()
        {0x02, (uint8_t *)&LifeTimes_Max_Discharge_Current}, // 0x85 ()
        {0x02, (uint8_t *)&LifeTimes_Max_Temp_Cell},         // 0x86 ()
        {0x02, (uint8_t *)&LifeTimes_Min_Temp_Cell},         // 0x87 ()
        {0x02, (uint8_t *)&t_com88},                         // 0x88 () DF_IRC
        {0x02, (uint8_t *)&t_com89},                         // 0x89 ()  DF_IFCC
        {0x02, (uint8_t *)&t_com8a},                         // 0x8a ()  IRsoc
        {0x02, (uint8_t *)&t_com8b_out},                             // 0x8b ()
        {0x02, (uint8_t *)&t_com8c_out},                             // 0x8c ()
        {0x02, (uint8_t *)&t_com8d_out},                             // 0x8d ()
        {0x02, (uint8_t *)&t_com8e_out},                             // 0x8e ()
        {0x02, (uint8_t *)NULL},                             // 0x8f ()
        {0x02, (uint8_t *)&t_com90_out},                             // 0x90 ()
        {0x02, (uint8_t *)&t_com91_out},                             // 0x91 ()
        {0x02, (uint8_t *)&t_com92_out},                             // 0x92 ()
        {0x02, (uint8_t *)&t_com93_out},                             // 0x93 ()
        {0x02, (uint8_t *)&t_com94_out},                             // 0x94 ()
        {0x02, (uint8_t *)&t_com95_out},                             // 0x95 ()
        {0x02, (uint8_t *)&t_com96_out},                             // 0x96 ()
        {0x02, (uint8_t *)NULL},                             // 0x97 ()
        {0x02, (uint8_t *)NULL},                             // 0x98 ()
        {0x02, (uint8_t *)NULL},                             // 0x99 ()
        {0x02, (uint8_t *)NULL},                             // 0x9a ()
        {0x02, (uint8_t *)NULL},                             // 0x9b ()
        {0x02, (uint8_t *)NULL},                             // 0x9c ()
        {0x02, (uint8_t *)NULL},                             // 0x9d ()
        {0x02, (uint8_t *)NULL},                             // 0x9e ()
        {0x02, (uint8_t *)NULL},                             // 0x9f ()
        {0x02, (uint8_t *)&t_coma0},                             // 0xa0 ()
        {0x02, (uint8_t *)&t_coma1},                             // 0xa1 ()
        {0x02, (uint8_t *)NULL},                             // 0xa2 ()
        {0x02, (uint8_t *)NULL},                             // 0xa3 ()
        {0x02, (uint8_t *)&_EntryShipModeCount},             // 0xa4 ()
        {0x02, (uint8_t *)&_EntryExitShipCondition},         // 0xa5 ()
        {0x02, (uint8_t *)&_ShipModeTimer},                  // 0xa6 ()
};

// - CRC8 table -
const unsigned char CRC8TBL[] = {
    0x00, 0x07, 0x0E, 0x09, 0x1C, 0x1B, 0x12, 0x15,
    0x38, 0x3F, 0x36, 0x31, 0x24, 0x23, 0x2A, 0x2D,
    0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
    0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
    0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
    0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
    0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
    0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
    0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
    0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
    0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
    0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
    0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
    0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
    0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
    0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
    0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
    0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
    0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
    0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
    0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
    0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
    0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
    0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
    0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
    0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
    0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
    0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
    0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
    0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
    0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
    0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3};

void CRC8_Calc(uint8_t a)
{
  apec = CRC8TBL[a ^ apec]; // PEC calculation macro
}

void I2C_ResetBuff(void)
{
  tx_count = 0;
  g_RecvCnt = 0;
}

/**
 * @fn void i2c_com_init(void)
 * @brief  Initializes I2C using EEPROM.
 * @param  None
 * @return None
 */
static void i2c_gpio_init(void)
{
  __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);
  __RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_I2C1);

  // I2C Pin Config
  gpio_mf_config(GPIOA, GPIO_PIN_10, GPIO_MF_SEL0); // PA10--I2C_SCL
  gpio_mf_config(GPIOA, GPIO_PIN_11, GPIO_MF_SEL0); // PA11--I2C_SDA

  gpio_mode_set(GPIOA, GPIO_PIN_10 | GPIO_PIN_11, GPIO_MODE_MF_OD_PD(GPIO_SPEED_HIGH));
}

/**
 * @fn void cs_eval_salve_init(void)
 * @brief  I2C Set to slave mode.
 * @param  None
 * @return None
 */
static void i2c_salve_init(void)
{
  i2c_config_t i2c_config_struct;
  nvic_config_t nvic_config_struct;

  /* I2C configuration */
  i2c_config_struct.mode = I2C_BUS_MODE_SMBUS_DEVICE;
  i2c_config_struct.analog_flag = I2C_ANALOG_FILTER_ENABLE;
  i2c_config_struct.digital_value = 0x00;
  i2c_config_struct.slave_addr1 = OWN_ADDRESS;
  i2c_config_struct.ack_flag = I2C_ACK_ENABLE;
  i2c_config_struct.ack_addr = I2C_ACK_ADDR_7BITS;
  i2c_config_struct.tmr_value = I2C_TIMING;
  i2c_init(I2C1, &i2c_config_struct);

  // __I2C_FUNC_ENABLE(I2C1, CLK_DISSTRETCH);
  __I2C_FUNC_ENABLE(I2C1, WAKEUP);
  __I2C_ENABLE(I2C1);
  __I2C_INTR_ENABLE(I2C1, I2C_INTR_BUSERR | I2C_INTR_ARBLO | I2C_INTR_OVR | I2C_INTR_ADRM | I2C_INTR_CMP |
                              I2C_INTR_STOP | I2C_INTR_NACK | I2C_INTR_RXNE | I2C_INTR_TXINT);

    __I2C_ADDR_CONT_VALUE_SET(I2C1, 0x5DC0);//地址匹配超时，1ms
    __I2C_FUNC_ENABLE(I2C1, ADDR_CNT_EN);
    __I2C_BUSY_CLEAR_VALUE_SET(I2C1, 0x7FF);
    __I2C_FUNC_ENABLE(I2C1, BUSY_HCLR_EN);

  nvic_config_struct.IRQn = IRQn_I2C1;
  nvic_config_struct.priority = 0x00;
  nvic_config_struct.enable_flag = ENABLE;
  nvic_init(&nvic_config_struct);
}
void I2C_init(void)
{
  __RCU_PERI_RST_ENABLE(I2C1);
  __NOP();
  __RCU_PERI_RST_DISABLE(I2C1);
  __NOP();
  __RCU_APB1_CLK_ENABLE(RCU_APB1_PERI_PMU);
  i2c_gpio_init();
  i2c_salve_init();
}
/************************************************************
0x0001	Device Type						                  R
0x0002	FirmwareVersion				                  R
0x0003	HardwareVersion				                  R
0x0004	IFChecksum						                  R
0x0005	StaticDFSignature   			              R
0x0006	ChemID								                  R
0x0008	StaticChemDFSignature	                  R
0x0009	AllDFSignature                          R
0x0035  SecurityKeys                            R/W
0x0037  AuthenticationKey                       R/W
0x0050  SafetyAlert                             R
0x0051  SafetyStatus                            R
0x0052  PFAlert                                 R
0x0053  PFStatus                                R
0x0054	OperationStatus				                  R
0x0055	ChargingStatus				                  R
0x0056	GaugingStatus                           R
0x0057  ManufacturingStatus                     R
0x0058  AFERegister                             R
0x005A  NoLoadRemCap                            R
0x0060	LifetimeDataBlock1		                  R
0x0061	LifetimeDataBlock2		                  R
0x0062	LifetimeDataBlock3		                  R
0x0063	LifetimeDataBlock4		                  R
0x0064	LifetimeDataBlock5		                  R
0x0065	LifetimeDataBlock6		                  R
0x0066	LifetimeDataBlock7		                  R
0x0067	LifetimeDataBlock8		                  R
0x0068	LifetimeDataBlock9		                  R
0x0069	LifetimeDataBlock10		                  R
0x006A	LifetimeDataBlock11		                  R
0x006B	LifetimeDataBlock12		                  R
0x0070	ManufacturerInfo                        R
0x0071	DAStatus1							                  R
0x0072	DAStatus2                               R
0x0073	GaugeStatus1                            R
0x0074	GaugeStatus2                            R
0x0075	GaugeStatus3                            R
0x0076	CBStatus                                R
0x0077	StateofHealth                           R
0x0078	FilterCapacity                          R
0x007A	ManufacturerInfoB                       R
0x009D	AccumulationCharge Threshold            R/W
0x009E	AccumulationDisCharge Threshold         R/W
0x009F  AccumulatedTimeCharge                   R
0x00B0  ChargingVoltageOverride                 R/W
0xF080  ExitCalibrationOutput                   R/W
0xF081  OutputCCADCCal                          R/W
0xF082  OutputShortedCCADCCal                   R/W
************************************************************/
Block SubCmdReadData(uint16_t Command) // read data
{
  Block block;
  memset(&block,0,sizeof(Block));
  switch (Command)
  {
  case 0x0000:
  {
    blk_read_case_last = Command;
    block.m_block.length = 0x02;
    memcpy(block.m_block.data, &t_com54, block.m_block.length);
    break;
  }
  case 0x0001: // Device Type
  {
    blk_read_case_last = Command;
    block.m_block.length = 0x02;
    memcpy(block.m_block.data, &Device_Type, block.m_block.length);
    break;
  }
  case 0x0002: // FirmwareVersion
  {
    blk_read_case_last = Command;
    block.m_block.length = sizeof(FirmwareVersion);
    memcpy(block.m_block.data, &Firmware_Version, block.m_block.length);
    break;
  }
  case 0x0003: // HardwareVersion
  {
    blk_read_case_last = Command;
    block.m_block.length = 3;
    memcpy(block.m_block.data, Hardware_Version, block.m_block.length);
    break;
  }
  case 0x0005: // StaticDFSignature
  {
    blk_read_case_last = Command;
    block.m_block.length = 2;
    memcpy(block.m_block.data, &D_Integrity_Static_DF_Signature, block.m_block.length);
    break;
  }
  case 0x0008: // StaticChemDFSignature
  {
    blk_read_case_last = Command;
    block.m_block.length = 2;
    memcpy(block.m_block.data, &D_Integrity_Static_Chem_DF_Signature, block.m_block.length);
    break;
  }
  case 0x0009: // AllDFSignature
  {
    blk_read_case_last = Command;
    block.m_block.length = 2;
    memcpy(block.m_block.data, &D_Integrity_All_DF_Signature, block.m_block.length);
    break;
  }
  case 0x0035: // SecurityKeys
  {
    blk_read_case_last = Command;
    block.m_block.length = 8;
    memcpy(block.m_block.data, &D_US_KEY1, 4);
    memcpy(&block.m_block.data[4], &D_FA_KEY1, 4);
    break;
  }
  case 0x0050: // SafetyAlert
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &_SafetyAlert, block.m_block.length);
    break;
  }
  case 0x0051: // SafetyStatus
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &_SafetyStatus, block.m_block.length);
    break;
    break;
  }
  case 0x0052: // PFAlert
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &_PFAlert, block.m_block.length);
    break;
  }
  case 0x0053: // PFStatus
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &_PFStatus, block.m_block.length);
    break;
  }
  case 0x0054: // OperationStatus
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &t_com54, block.m_block.length);
    break;
  }
  case 0x0055: // ChargingStatus
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &t_com55, block.m_block.length);
    break;
  }

  case 0x0056: // GaugingStatus
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &t_com56, block.m_block.length);
    break;
  }
  case 0x0057: //?ManufacturingStatus
  {
    blk_read_case_last = Command;
    block.m_block.length = 4;
    memcpy(block.m_block.data, &t_com57, block.m_block.length);
    break;
  }
  case 0x0058: // AFERegister
  {
    block.m_block.length = 21;
    // block.m_block.data[0] = LifeTimes_AFE_Interrupt_Status;    // AFE Hardware interrupt status
    // block.m_block.data[1] = LifeTimes_AFE_FET_Status;          // AFE FET Status
    // block.m_block.data[2] = LifeTimes_AFE_RXIN;               //  AFE RXIN. AFE I/O port input status
    // block.m_block.data[3] = LifeTimes_AFE_Latch_Status;        // AFE Latch Status. AFE protection latch status
    // block.m_block.data[4] = LifeTimes_AFE_Interrupt_Enable;          // AFE Interrupt Enable . AFE interrupt control settings
    // block.m_block.data[5] = D_AFEFETCCTL;            // AFE Control enable setting.
    // block.m_block.data[6] = D_AFE_RXIEN;             // AFE I/O input enable settings
    // block.m_block.data[7] = D_AFE_RLOUT;             // AFE RLOUT. AFE I/O pins output status
    // block.m_block.data[8] = D_AFE_RHOUT;             // AFE I/O pins output status
    // block.m_block.data[9] = D_AFE_RHINT;             // AFE RHINT. AFE I/O pins interrupt status
    // block.m_block.data[10] = D_AFECELLBALANCE;       // AFE cell balancing enable settings and status
    // block.m_block.data[11] = D_AFECONTROL_AD_CC;     // AFE ADC/CC Control settings.AFE ADC/CC Control settings
    // block.m_block.data[12] = D_AFEMUXADC;            // AFE ADC channel selections.AFE ADC channel selections
    // block.m_block.data[13] = D_LEDOUTPUT;            // AFE LED Control.
    // block.m_block.data[14] = D_AFE_STATECONTROL;     // AFE control on various HW based features
    // block.m_block.data[15] = D_AFECONTROL_LEDWAKE;   // AFE comparator and timer control
    // block.m_block.data[16] = D_AFEPROTECTIONCONTROL; // AFE protection delay time control
    // block.m_block.data[17] = D_AFEOCD;               // AFE OCD settings
    // block.m_block.data[18] = D_AFESCC;               // AFE SCC settings
    // block.m_block.data[19] = D_AFESCD1;              // AFE SCD1 settings
    // block.m_block.data[20] = D_AFESCD2;              // AFE SCD2 settings
    blk_read_case_last = Command;
    break;
  }

  case 0x0060: // LifetimeDataBlock1
  {
    block.m_block.length = 32;
    block.m_block.data[0] = LifeTimes_Cell_1_Max_Voltage;                      // Cell 1 Max Voltage
    block.m_block.data[1] = (uint8_t)(LifeTimes_Cell_1_Max_Voltage) >> 8;      // Cell 1 Max Voltage
    block.m_block.data[2] = LifeTimes_Cell_2_Max_Voltage;                      // Cell 2 Max Voltage
    block.m_block.data[3] = (uint8_t)(LifeTimes_Cell_2_Max_Voltage) >> 8;      // Cell 2 Max Voltage
    block.m_block.data[4] = LifeTimes_Cell_3_Max_Voltage;                      // Cell 3 Max Voltage
    block.m_block.data[5] = (uint8_t)(LifeTimes_Cell_3_Max_Voltage) >> 8;      // Cell 3 Max Voltage
    block.m_block.data[6] = LifeTimes_Cell_4_Max_Voltage;                      // ell 4 Max Voltage
    block.m_block.data[7] = (uint8_t)(LifeTimes_Cell_4_Max_Voltage) >> 8;      // Cell 4 Max Voltage
    block.m_block.data[8] = LifeTimes_Cell_1_Min_Voltage;                      // Cell 1 Min Voltage
    block.m_block.data[9] = (uint8_t)(LifeTimes_Cell_1_Min_Voltage) >> 8;      // Cell 1 Min Voltage
    block.m_block.data[10] = LifeTimes_Cell_2_Min_Voltage;                     // Cell 2 Min Voltage
    block.m_block.data[11] = (uint8_t)(LifeTimes_Cell_2_Min_Voltage) >> 8;     // Cell 2 Min Voltage
    block.m_block.data[12] = LifeTimes_Cell_3_Min_Voltage;                     // Cell 3 Min Voltage
    block.m_block.data[13] = (uint8_t)(LifeTimes_Cell_3_Min_Voltage) >> 8;     // Cell 3 Min Voltage
    block.m_block.data[14] = LifeTimes_Cell_4_Min_Voltage;                     // Cell 4 Min Voltage
    block.m_block.data[15] = (uint8_t)(LifeTimes_Cell_4_Min_Voltage) >> 8;     // Cell 4 Min Voltage
    block.m_block.data[16] = LifeTimes_Max_Delta_Cell_Voltage;                 // Max Delta Cell Voltage
    block.m_block.data[17] = (uint8_t)(LifeTimes_Max_Delta_Cell_Voltage) >> 8; // Max Delta Cell Voltage
    block.m_block.data[18] = LifeTimes_Max_Charge_Current;                       // Max Charge Current
    block.m_block.data[19] = (uint8_t)(LifeTimes_Max_Charge_Current >> 8);       // Max Charge Current
    block.m_block.data[20] = LifeTimes_Max_Discharge_Current;                       // Max Discharge Current
    block.m_block.data[21] = (uint8_t)(LifeTimes_Max_Discharge_Current >> 8);       // Max Discharge Current
    block.m_block.data[22] = LifeTimes_Max_Avg_Dsg_Current;                    // Max Avg Dsg Current
    block.m_block.data[23] = (uint8_t)(LifeTimes_Max_Avg_Dsg_Current >> 8);    // Max Avg Dsg Current
    block.m_block.data[24] = LifeTimes_Max_Avg_Dsg_Power;                    // Max Avg Dsg Power
    block.m_block.data[25] = (uint8_t)(LifeTimes_Max_Avg_Dsg_Power >> 8);    // Max Avg Dsg Power
    block.m_block.data[26] = LifeTimes_Max_Temp_Cell;                     // Max Temp Cell
    block.m_block.data[27] = LifeTimes_Min_Temp_Cell;                     // Min Temp Cell
    block.m_block.data[28] = LifeTimes_Max_Delta_Cell_Temp;                // Max Delta Cell Temperature
    block.m_block.data[29] = LifeTimes_Max_Temp_Int_Sensor;                // Max Temp Int Sensor
    block.m_block.data[30] = LifeTimes_Min_Temp_Int_Sensor;                // MinTempIntSensor
    block.m_block.data[31] = LifeTimes_Max_Temp_Fet;                      // Max Temp FET
    blk_read_case_last = Command;
    break;
  }
  case 0x0061: // LifetimeDataBlock2
  {
    block.m_block.length = 20;
    block.m_block.data[0] = LifeTimes_No_of_Shutdowns;                  // No.of Shutdowns
    block.m_block.data[1] = NoofPartialResets;               // No. of Partial Resets
    block.m_block.data[2] = NoofFullResets;                  // No. of Full Resets
    block.m_block.data[3] = NoofWDTResets;                   // No. of WDT Resets
    block.m_block.data[4] = LifeTimes_CB_Time_Cell_1;                   // CB Time Cell 1
    block.m_block.data[5] = (uint8_t)(LifeTimes_CB_Time_Cell_1 >> 8);   // CB Time Cell 1
    block.m_block.data[6] = (uint8_t)(LifeTimes_CB_Time_Cell_1 >> 16);  // CB Time Cell 1
    block.m_block.data[7] = (uint8_t)(LifeTimes_CB_Time_Cell_1 >> 24);  // CB Time Cell 1
    block.m_block.data[8] = LifeTimes_CB_Time_Cell_2;                   // CB Time Cell 2
    block.m_block.data[9] = (uint8_t)(LifeTimes_CB_Time_Cell_2 >> 8);   // CB Time Cell 2
    block.m_block.data[10] = (uint8_t)(LifeTimes_CB_Time_Cell_2 >> 16); // CB Time Cell 2
    block.m_block.data[11] = (uint8_t)(LifeTimes_CB_Time_Cell_2 >> 24); // CB Time Cell 2
    block.m_block.data[12] = LifeTimes_CB_Time_Cell_3;                  // CB Time Cell 3
    block.m_block.data[12] = (uint8_t)(LifeTimes_CB_Time_Cell_3 >> 8);  // CB Time Cell 3
    block.m_block.data[14] = (uint8_t)(LifeTimes_CB_Time_Cell_3 >> 16); // CB Time Cell 3
    block.m_block.data[15] = (uint8_t)(LifeTimes_CB_Time_Cell_3 >> 24); // CB Time Cell 3
    block.m_block.data[16] = LifeTimes_CB_Time_Cell_4;                  // CB Time Cell 4
    block.m_block.data[17] = (uint8_t)(LifeTimes_CB_Time_Cell_4 >> 8);  // CB Time Cell 4
    block.m_block.data[18] = (uint8_t)(LifeTimes_CB_Time_Cell_4 >> 16); // CB Time Cell 4
    block.m_block.data[19] = (uint8_t)(LifeTimes_CB_Time_Cell_4 >> 24); // CB Time Cell 4
    blk_read_case_last = Command;
    break;
  }
  case 0x0062: // LifetimeDataBlock3
  {
    block.m_block.length = 4;
    block.m_block.data[0] = TotalFWRuntime;                  // Total FW Runtime
    block.m_block.data[1] = (uint8_t)(TotalFWRuntime >> 8);  // Total FW Runtime
    block.m_block.data[2] = (uint8_t)(TotalFWRuntime >> 16); // Total FW Runtime
    block.m_block.data[3] = (uint8_t)(TotalFWRuntime >> 24); // Total FW Runtime
    blk_read_case_last = Command;
    break;
  }
  case 0x0063: // LifetimeDataBlock4
  {
    block.m_block.length = 32;
    memcpy(block.m_block.data, nLifeTimeDataBlock4.data, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0064: // LifetimeDataBlock5
  {
    block.m_block.length = 32;
    memcpy(block.m_block.data, nLifeTimeDataBlock5.data, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }

  case 0x0070: // ManufacturerInfo
  {
    block.m_block.length = 32;
    memcpy(block.m_block.data, D_Manufacturer_ManufacturerInfo, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }

  case 0x0071: // DAStatus1
  {
    block.m_block.length = sizeof(DAStatus1);
    memcpy(block.m_block.data, &_DAStatus1, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0072: // DAStatus2
  {
    block.m_block.length = sizeof(DAStatus2);
    memcpy(block.m_block.data, &_DAStatus2, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0073: // GaugeStatus1
  {
    block.m_block.length = 32;
    memcpy(block.m_block.data, &_GaugeStatus1, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0074: // GaugeStatus2
  {
    block.m_block.length = 32;
    memcpy(block.m_block.data, &_GaugeStatus2, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0075: // GaugeStatus3
  {
    block.m_block.length = 32;
    memcpy(block.m_block.data, &_GaugeStatus3, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0076: // CBStatus
  {
    block.m_block.length = 19;
    memcpy(block.m_block.data, &_CBStatus, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x0077: // StateofHealth
  {
    block.m_block.length = 4;
    block.m_block.data[0] = (uint8_t)State_of_HealthFCC;         // State-of-Health FCC FCC_SOH
    block.m_block.data[1] = (uint8_t)(State_of_HealthFCC >> 8);  // State-of-Health FCC FCC_SOH
    block.m_block.data[2] = (uint8_t)StateofHealthenergy;        // Filtered Capacity
    block.m_block.data[3] = (uint8_t)(StateofHealthenergy >> 8); // Filtered Capacity
    blk_read_case_last = Command;
    break;
  }
  case 0x0078: // FilterCapacity
  {
    block.m_block.length = 8;
    memcpy(block.m_block.data, nFilteredCapacity.data, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }
  case 0x007A: // ManufacturerInfoB
  {
    block.m_block.length = 4;
    memcpy(block.m_block.data, &D_Manufacturer_Info_B01, block.m_block.length);
    blk_read_case_last = Command;
    break;
  }

  case 0x009F: // AccumulatedTimeCharge
  {
    block.m_block.length = 6;
    block.m_block.data[0] = (uint8_t)AccumulatedTime;          // Accumulated Time
    block.m_block.data[1] = (uint8_t)(AccumulatedTime >> 8);   // Accumulated Time
    block.m_block.data[2] = (uint8_t)(AccumulatedTime >> 16);  // Accumulated Time
    block.m_block.data[3] = (uint8_t)(AccumulatedTime >> 24);  // Accumulated Time
    block.m_block.data[4] = (uint8_t)AccumulatedCharge;        // Accumulated Charge
    block.m_block.data[5] = (uint8_t)(AccumulatedCharge >> 8); // Accumulated Charge
    blk_read_case_last = Command;
    break;
  }

  case 0xF080: // ExitCalibrationOutput
  {
    if (f_CAL_EN)
    {
      f_CAL_EN = OFF;
      f_cal = OFF;
      f_cal_offset = OFF;
    }
    blk_read_case_last = Command;
    break;
  }
  case 0xF081: // OutputCCADCCal
  {
    extern Afe_data afe_Calib;
    f_cal = ON;
    f_cal_offset = OFF;
    if (f_CAL_EN)
    {
      block.m_block.length = 32;
      memcpy(block.m_block.data, &afe_Calib, block.m_block.length);
      nReadLen = 32 + KEYLEN;
    }
    blk_read_case_last = Command;
    break;
  }
  default:
  {
    Command = blk_read_case_last;
    break;
  }
  }
  return block;
}
/*************************************************************
0x0035  SecurityKeys                              R/W
0x0037  AuthenticationKey                         R/W
0x009D	AccumulationCharge Threshold              R/W
0x009E	AccumulationDisCharge Threshold           R/W
0x00B0  ChargingVoltageOverride                   R/W
0x3008  WriteTemp                                  W
0xF080  ExitCalibrationOutput                     R/W
0xF081  OutputCCADCCal                            R/W
0xF082  OutputShortedCCADCCal                     R/W
 ************************************************************/
void SubWriteData(uint16_t Command) // write data
{
  switch (Command)
  {

  case 0x0035: // SecurityKeys
  {
    if (f_fas)
    {
      DFUpdate.FLAG = 1;
      DFUpdate.SecKeys = 1;
    }
    break;
  }
  case 0x009D: // AccumulationCharge Threshold
  {
    DFUpdate.FLAG = 1;
    DFUpdate.AccCT = 1;
    break;
  }
  case 0x009E: // AccumulationDisCharge Threshold
  {
    DFUpdate.FLAG = 1;
    DFUpdate.AccDT = 1;
    break;
  }
  case 0x00B0: // ChargingVoltageOverride
  {
    DFUpdate.FLAG = 1;
    DFUpdate.CVOverride = 1;
    break;
  }
  }
}
/*****************************************************************
0x0010  ShutdownMode                               W
0x0011  SleepMode                                  W
0x0013  AutoCCOfset                                W
0x001D  FuseToggle                                 W
0x001E  PrechargeFETToggle                         W
0x001F  ChargeFETToggle                            W
0x0020  DischargeFETToggle                         W
0x0021  Gauging                                    W
0x0022  FETControl                                 W
0x0023  LifetimeDataCollection                     W
0x0024  PermanentFailure                           W
0x0025  BlackBoxRecorder                           W
0x0026  Fuse                                       W
0x0027  LEDDisplayEnable                           W
0x0028  LifetimeDataReset                          W
0x0029  PermanentFailureDataReset                  W
0x002A  BlackBoxRecorderReset                      W
0x002B  LEDToggle                                  W
0x002C  LEDDisplayPress                            W
0x002D  CalibrationMode                            W
0x002E  LifetimeDataFlush                          W
0x002F  LifetimeDataSpeedUpMode                    W
0x0030  SealDevice                                 W

0x0041  DeviceReset                                W
0x0079  RSOCWrite                                  W
0x0098  AccumulationChargeEnable                   W
0x0099  AccumulationDischargeEnable                W
0x009A  AccumulationReset                          W
0x009B  AccumulationStop                           W
0x009C  AccumulationStart                          W
0x00F0  IATAShutdown                               W
0x00F1  IATARm                                     W
0x00F2  IATAFcc                                    W
0x0F00  ROMMode                                    W
 ****************************************************************/
void SubWriteCtrlCmd(uint16_t Command) // write commond
{
      uint16_t ref=0;
  switch (Command)
  {
  case 0x0010: // ShutdownMode
  {
    Record_ShutDown_Mode=0x0010;
    f_ShutDown = ON;
    break;
  }
  case 0x0011: // SleepMode
  {
    if (f_fas)
    {
     // printf("Receive Sleep Mode!\n");
      f_no_smbus = f_last_timeout_status;
      f_sleepm = ON;
    }
    break;
  }
  case 0x001D: // FuseToggle
  {
    if (f_fas)
    {
      f_fuse_out = ~f_fuse_out;
    }
    break;
  }
  case 0x001E: // PrechargeFETToggle
  {
    if (!f_FET_EN)
    {
      if (f_fas)
      {
        f_PCHG_EN = ~f_PCHG_EN;
      }
    }
    break;
  }
  case 0x001F: // ChargeFETToggle
  {
    if (!f_FET_EN)
    {
      if (f_fas)
      {
        f_CHG_EN = ~f_CHG_EN;
      }
    }
    break;
  }
  case 0x0020: // DischargeFETToggle
  {
    if (!f_FET_EN)
    {
      if (f_fas)
      {
        f_DSG_EN = ~f_DSG_EN;
      }
    }
    break;
  }
  case 0x0021: // Gauging
  {
    if (f_fas)
    {
      f_GAUGE_EN = ~f_GAUGE_EN;
       ref=(t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }
    break;
  }
  case 0x0022: // FETControl
  {
    if (f_fas)
    {
      f_FET_EN = ~f_FET_EN;
        ref=(t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }
    break;
  }
  case 0x0023: // LifetimeDataCollection
  {

    if (f_fas)
    {
      f_LF_EN = ~f_LF_EN;
      ref = (t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }

    break;
  }
  case 0x0024: // PermanentFailure
  {
    // if (f_us)
    if (f_fas)
    {
      f_PF_EN = ~f_PF_EN;
        ref=(t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }
    break;
  }
  case 0x0025: // BlackBoxRecorder
  {
    if (f_fas)
    // if (f_us)
    {
      f_BBR_EN = ~f_BBR_EN;
        ref=(t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }
    break;
  }
  case 0x0026: // Fuse
  {
    if (f_fas)
    {
      f_FUSE_EN = ~f_FUSE_EN;
        ref=(t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }
    break;
  }
  case 0x0027: // LEDDisplayEnable
  {
    if (f_fas) // if (f_us)
    {
      f_LED_EN = ~f_LED_EN;
        ref=(t_com57 & 0x03f8);
      DataFlash_Write((uint32_t)(&D_Manufacturing_Status_Init), (uint8_t *)&ref, 2);
    }
    break;
  }
  case 0x0028: // LifetimeDataReset
  {
    if (f_fas) // if (f_us)
    {
      f_lt_erase = ON;
    }
    break;
  }
  case 0x0029: // PermanentFailureDataReset
  {
    if (f_fas) // if (f_us)
    {
      f_pf_erase = ON;
    }
    break;
  }
  case 0x002A: // BlackBoxRecorderReset
  {
    if (f_fas) // if (f_us))
    {
      f_bbr_erase = 1;
    }
    break;
  }
  case 0x002B: // LEDToggle
  {
    if (f_fas) // if (f_us))
    {
      f_LEDTg = 1;
    }
    break;
  }
  case 0x002C: // LEDDisplayPress
  {
    if (f_fas) // if (f_us))
    {
      f_LEDDspPr = 1;
    }
    break;
  }
  case 0x002D: // CalibrationMode
  {
    if (f_fas) // if (f_us))
    {
      f_CAL_EN = ~f_CAL_EN;
    }
    break;
  }
  case 0x002E: // LifetimeDataFlush
  {
    if (f_fas) // if (f_us))
    {
      f_ltreqW = ON;
    }
    break;
  }
  case 0x002F: // LifetimeDataSpeedUpMode
  {
    if (f_fas) // if (f_us))
    {
      f_LT_TEST = ~f_LT_TEST;
      if (f_LT_TEST)
      {
        // LtW_CntW = 0;
      }
    }
    break;
  }
  case 0x0030: // SealDevice
  {
    f_Seal_trip = ON;
    break;
  }
    case 0x0036:
  {
     if (f_fas)
    {
      revision_stage();
      //f_reset_mcu = ON;
    }
    break;
  }

  case 0x0037: // AuthenticationKey
  {
   
    if (f_fas)
    {

      need_change_sha1_pwd=1;
    }
    break;
  }
  case 0x0038: 
  {
    if (f_fas)
    {
      f_pi_test= ~f_pi_test;
    }
    break;
  }
   
  
  case 0x0041: // DeviceReset
  {

    f_reset_mcu = ON;

    break;
  }
     case 0x0047:
     {
       if(f_us)
       {
         f_dfe_areq = ON;
         f_dfe_breq = ON;
       }
     }

  case 0x0079: // RSOCWrite
  {
    if (f_fas) // if (f_us))
    {
      f_RSOCWrite = ON;
    }
    break;
  }
  case 0x0098: // AccumulationChargeEnable
  {
    if (f_fas) // if (f_us))
    {
      f_AccChg = ON;
    }
    break;
  }
  case 0x0099: // AccumulationDischargeEnable
  {
    if (f_fas) // if (f_us))
    {
      f_AccDsg = ON;
    }
    break;
  }
  case 0x009A: // AccumulationReset
  {
    // if (f_us)
    // {
    //   f_reset_Acc = ON;
    // }
    f_reset_Acc = ON;
    break;
  }
  case 0x009B: // AccumulationStop
  {
    // if (f_us)
    // {
    //   f_AccStop = ON;
    // }
    f_AccStop = ON;
    break;
  }
  case 0x009C: // AccumulationStart
  {
    // if (f_us)
    // {
    //   f_AccStart = ON;
    // }
    f_AccStart = ON;
    break;
  }
  case 0x00F0: // IATAShutdown
  {

    Record_ShutDown_Mode = 0x00f0;
    f_ShutDown = ON;

    break;
  }
  case 0x00F1: // IATARm
  {
    if (f_fas) // if (f_us))
    {
      f_IATARm = ON;
    }
    break;
  }
  case 0x00F2: // IATAFcc
  {
    if (f_fas) // if (f_us))
    {
      f_IATAFcc = ON;
    }
    break;
  }
  case 0x0F00: // ROMMode
  {
    if (f_fas) // if (f_us))
    {
      f_updata_en = ON;
    }
    break;
  }
  case 0x9527:
  {
    f_debugMode = ON;
    UF_BackupREG ^= 0x3;
    // UF_BackupREG ^= 0x1;
    break;
  }
    // default:
    //   {

    //   }
  }
}

void write_processmsg(uint8_t*rx_buffer,uint8_t g_RecvCnt)
{
  uint8_t ccnt;

  if (g_RecvCnt > 1 && g_RecvCnt < BUFFER_LEN)
  {
    InstructShip_invalid(rx_buffer[0]);
    for (ccnt = 1; ccnt < (g_RecvCnt - 1); ccnt++)
    {
      CRC8_Calc(rx_buffer[ccnt]);
    }

    if (apec != rx_buffer[g_RecvCnt - 1])
    {
      return;
    }
    switch (rx_buffer[0])
    {
    case 0x00:
    {
      uint16_t _word = rx_buffer[2] << 8 | rx_buffer[1];
      
      if ((_word >= 0x2400 && _word < 0x2800) || (_word >= 0x4000 && _word <= 0x6000))
      {
        _ManufacturerData.m_block.length = 32;
        if (f_sec0 ^ f_sec1)
        {
          ReadFlashData(_ManufacturerData.m_block.data, _word);
        }
        else
        {
          memset(&_ManufacturerData, 0xFF, 33);
        }
      }
      else
      {
        Block block = SubCmdReadData(_word);
        if(block.m_block.length != 0xFF)
        {
          memcpy(&_ManufacturerData,&block,sizeof(Block));
        }
        SubWriteCtrlCmd(_word);
      }

      // SE->US
      if (f_sec0 && f_sec1)
      {
        if (SC_Flag.SE_US_STEP1)
        {
          if (_word == (D_US_KEY3 | D_US_KEY4 << 8))
          {
            f_sec0 = 0;
            f_sec1 = 1;
            SC_Flag.SE_US_STEP1 = 0;
          }
          else
          {
            SC_Flag.SE_US_STEP1 = 0;
          }
        }
        else
        {
          if (_word == (D_US_KEY1 | D_US_KEY2 << 8))
          {
            SC_Flag.SE_US_STEP1 = 1;
          }
        }
      }
      // US->FA
      if (!f_sec0 && f_sec1)
      {
        if (SC_Flag.US_FA_STEP1)
        {
          if (_word == (D_FA_KEY1 | D_FA_KEY2 << 8))
          {
            f_sec0 = 1;
            f_sec1 = 0;
            SC_Flag.US_FA_STEP1 = 0;
          }
          else
          {
            SC_Flag.US_FA_STEP1 = 0;
          }
        }
        else
        {
          if (_word == (D_FA_KEY3 | D_FA_KEY4 << 8))
          {
            SC_Flag.US_FA_STEP1 = 1;
          }
        }
      }
      break;
    }
    
    case 0x01:
    {
      _RemainingCapacityAlarm = rx_buffer[2] << 8 | rx_buffer[1];
      if (BatteryMode(CAPM))
      {
        DataFlash_Write((uint32_t) & (D_Data_Remaining_Wh_Capacity_Alarm), &rx_buffer[1], 2);
      }
      else
      {
        DataFlash_Write((uint32_t) & (D_Data_Remaining_Ah_Capacity_Alarm), &rx_buffer[1], 2);
      }
      break;
    }

    case 0x02:
    {
      DataFlash_Write((uint32_t) & (D_Data_Remaining_Time_Alarm), &rx_buffer[1], 2);
      break;
    }

    case 0x03:
    {
      _BatteryMode.value = rx_buffer[2] << 8 | rx_buffer[1];
      break;
    }

    case 0x04:
    {
      _AtRate = rx_buffer[2] << 8 | rx_buffer[1];
      break;
    }

    case 0x17:
    {
      if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
      {
        _CycleCount = rx_buffer[2] << 8 | rx_buffer[1];
      }
      break;
    }

    case 0x18:
    {
      if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
      {
        _DesignVoltage = rx_buffer[2] << 8 | rx_buffer[1];
        //   if (f_bm_CAPM == ON)
        //   {
        //     DataFlash_Write((uint32_t) & (D_Design_Capacity_in_cWh), &rx_buffer[1], 2);
        //   }
        //   else
        //   {
        //     DataFlash_Write((uint32_t) & (D_Design_Capacity_mAh), &rx_buffer[1], 2);
        //   }
      }
      break;
    }

    case 0x19:
    {
      if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
      {
        _DesignVoltage = rx_buffer[2] << 8 | rx_buffer[1];
      }
      break;
    }

    case 0x1A:
    {
      if (f_sec0 ^ f_sec1) // ACCESS(FA or US)  specificationInfo
      {
        _SpecificationInfo.value = rx_buffer[2] << 8 | rx_buffer[1];
      }
      break;
    }

    case 0x1B: // ManufactureaDate()
    {
      if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
      {
        DataFlash_Write((uint32_t) & (D_Data_Manufacturer_Date), &rx_buffer[1], 2);
      }
      break;
    }

    case 0x1C: // serial number
    {
      if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
      {
        DataFlash_Write((uint32_t) & (D_Data_Serial_Number), &rx_buffer[1], 2);
      }
      break;
    }

    case 0x27:
    {
      memcpy(_AuthCahllenge, &rx_buffer[2], rx_buffer[1]);
      handle_hmac(_AuthCahllenge,_AuthResponse);
      break;
    }
    case 0x29:
    {
      memcpy(SHA256_KEY,  &rx_buffer[2], rx_buffer[1]);
      f_AUTH=1;
      break;
    }
    case 0x2A:
    {
      memcpy(&_AIPIModeControl, &rx_buffer[1], 2);
      break;
    }

    case 0x2F: // 0x2F OptCommand5() Write
    {
      uint8_t key[16] = {0}; //{0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10 }; //16*8=128bit
      memcpy(key, (uint8_t *)USER_KEY_REGION, sizeof(key));
      if (need_change_sha1_pwd == 1)
      {
        // 下发的密码需要反序再参与计算
        for (int8_t j = rx_buffer[1] + 1, k = 0; j > 0; j--)
        {
          key[k++] = rx_buffer[j];
        }
        /* 写入密码 */
        uint8_t ret=efuse_key_write(key);
      }
      uint8_t sha1_random_data[BLOCK_CMD_Authenticate_SEND_LEN] = {0};
      memcpy(sha1_random_data, &rx_buffer[2], BLOCK_CMD_Authenticate_SEND_LEN);
      if (need_change_sha1_pwd == 1)
      {
        memset(sha1_random_data, 0, sizeof(sha1_random_data));
        need_change_sha1_pwd = 0; // 清除修改密码标志
      }
      sha1_authenticate(sha1_random_data, key);
      memcpy(_sha1_reslut, sha1_random_data, BLOCK_CMD_Authenticate_SEND_LEN);

      break;
    }

    case 0x34:
    {
      memcpy(&_FETCtrl, &rx_buffer[1], 2);
      break;
    }

    // case 0x3E:
    // {
    //   memcpy(&_OptCommand2, &rx_buffer[1], 2);
    //   break;
    // }

    case 0x3F:
    {
      memcpy(&_OptCommand1, &rx_buffer[1], 2);
      break;
    }

    case 0x44:
    {
       //printf("shoudao\n");
      MACDataLength = rx_buffer[1];
      eMac.MAC_T.nAltManufacturerAccess = (rx_buffer[3] << 8) | rx_buffer[2];
      if (MACDataLength <= 2) // Read
      {
        if ((eMac.MAC_T.nAltManufacturerAccess >= 0x2400 && eMac.MAC_T.nAltManufacturerAccess < 0x2800) || (eMac.MAC_T.nAltManufacturerAccess >= 0x4000 && eMac.MAC_T.nAltManufacturerAccess <= 0x6000))
        {
          t_com44._MAC_T.nMacLen = 0x22;
          t_com44._MAC_T.nAltManufacturerAccess = eMac.MAC_T.nAltManufacturerAccess;
          if (f_sec0 ^ f_sec1)
          {
            ReadFlashData(t_com44._MAC_T.nMACData, eMac.MAC_T.nAltManufacturerAccess);
          }
          else
          {
            memset(t_com44._MAC_T.nMACData, 0xFF, 32);
          }
        }
        else
        {
          Block block = SubCmdReadData(eMac.MAC_T.nAltManufacturerAccess);
          if (block.m_block.length != 0xFF)
          {
            t_com44._MAC_T.nMacLen = block.m_block.length + 2;
            t_com44._MAC_T.nAltManufacturerAccess = eMac.MAC_T.nAltManufacturerAccess;
            memcpy(t_com44._MAC_T.nMACData, block.m_block.data, sizeof(Block));
            nReadLen = block.m_block.length + 3;
          }
          SubWriteCtrlCmd(eMac.MAC_T.nAltManufacturerAccess);
        }
        // SE->US
        if (f_sec0 && f_sec1)
        {
          if (SC_Flag.SE_US_STEP1)
          {
            if (eMac.MAC_T.nAltManufacturerAccess == (D_US_KEY3 | D_US_KEY4 << 8))
            {
             // printf("UnSeal!\n");
              f_sec0 = 0;
              f_sec1 = 1;
              SC_Flag.SE_US_STEP1 = 0;
            }
            else
            {
              SC_Flag.SE_US_STEP1 = 0;
            }
          }
          else
          {
            if (eMac.MAC_T.nAltManufacturerAccess == (D_US_KEY1 | D_US_KEY2 << 8))
            {
              SC_Flag.SE_US_STEP1 = 1;
            }
          }
        }
        // US->FA
        if (!f_sec0 && f_sec1)
        {
          if (SC_Flag.US_FA_STEP1)
          {
            if (eMac.MAC_T.nAltManufacturerAccess == (D_FA_KEY1 | D_FA_KEY2 << 8))
            {
              //printf("FullAccess!\n");
              f_sec0 = 1;
              f_sec1 = 0;
              SC_Flag.US_FA_STEP1 = 0;
            }
            else
            {
              SC_Flag.US_FA_STEP1 = 0;
            }
          }
          else
          {
            if (eMac.MAC_T.nAltManufacturerAccess == (D_FA_KEY3 | D_FA_KEY4 << 8))
            {
              SC_Flag.US_FA_STEP1 = 1;
            }
          }
        }
      }
      else if (MACDataLength <= 0x22) // Write
      {
       
        for (nWriteLen = 0; nWriteLen < (MACDataLength - 2) && nWriteLen < FRAMELEN; nWriteLen++)
        {
          eMac.MAC_T.nMACData[nWriteLen] = rx_buffer[nWriteLen + 4];
        }
       
        SubWriteData(eMac.MAC_T.nAltManufacturerAccess);
        if (eMac.MAC_T.nAltManufacturerAccess >= 0x4000 && f_fas)
        {
          DFUpdate.DataFlash = ON;
          DFUpdate.FLAG = ON;
        }
      }
      break;
    }

   case 0x5b:
   {
    memcpy(&t_DBPT.PackResistance, &rx_buffer[1], 2);
    DataFlash_Write((uint32_t)(&D_DBPT_PackResistance), &rx_buffer[1], 2);
    
    break;
   }
   case 0x5c:
   {
    memcpy(&t_DBPT.SystemResistance, &rx_buffer[1], 2);
    DataFlash_Write((uint32_t)(&D_DBPT_SystemResistance), &rx_buffer[1], 2);
    break;
   }
   case 0x5d:
   {
    memcpy(&t_DBPT.MinSysVoltage, &rx_buffer[1], 2);
    DataFlash_Write((uint32_t)(&D_DBPT_MinSysVoltage), &rx_buffer[1], 2);
    break;
   }

   case 0x70:
   {
     if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
     {

       DataFlash_Write((uint32_t)(&D_Manufacturer_Info_B_Length), &rx_buffer[1], 33);
     }
     break;
   }
   case 0x7a:
   {
     if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
     {

       DataFlash_Write((uint32_t)(&D_Manufacturer_Info_C_Length), &rx_buffer[1], 33);
     }
     break;
   }
   case 0x7b:
   {
     if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
     {

       DataFlash_Write((uint32_t)(&D_Manufacturer_ManufacturerInfo), &rx_buffer[2], 32);
     }
     break;
   }

   case SYNC_CODE:
   {
     filled_connected_cmd(rx_buffer);
     break;
   }
    default:
      break;
    }
  }
}

void ReadFlashData(uint8_t *dst_buff, uint16_t Offset)
{
  if (Offset >= 0x2400 && Offset < 0x2800)
  {
    memcpy(dst_buff, FLASH_START_ADDR + Offset, MAC_DATA_LEN);
  }
  else
  {
	  
    if(Offset >= RECORD_OFFSET && Offset < RECORD_OFFSET + sizeof(Record))
    {
      extern volatile uint8_t *G_pFlashAddr;
      DFR_Index();
      if(G_pFlashAddr == NULL)
      {
        memset(dst_buff, 0, MAC_DATA_LEN);
      }
      else
      {
        memcpy(dst_buff, &G_pFlashAddr[Offset - RECORD_OFFSET], MAC_DATA_LEN);
      }
    }
    else if (Offset >= LIFETIMES_OFFSET && Offset <= LIFETIMES_OFFSET + sizeof(LifeTimes))
    {
      extern volatile uint8_t *G_pFlashAddr;
      LTR_Index();
      if(G_pFlashAddr == NULL)
      {
        memset(dst_buff, 0, MAC_DATA_LEN);
      }
      else
      {
        memcpy(dst_buff, &G_pFlashAddr[Offset - LIFETIMES_OFFSET], MAC_DATA_LEN);
      }

     // memcpy(dst_buff, Offset + DF_FLASH_OFFSET, MAC_DATA_LEN);
    }
    else
    {
      memcpy(dst_buff, Offset + DF_FLASH_OFFSET, MAC_DATA_LEN);
    }
  }
  nReadLen = MAC_DATA_LEN + KEYLEN;
}



void calc_DFSignature(void)
{
  uint16_t ret=0;
  //printf("ret=%d",ret);
  ret=crc16_calc((uint8_t*)&D_OCV_SOC_OCV_Table_0,(uint32_t)&D_Data_Manufacturer_Date-(uint32_t)&D_OCV_SOC_OCV_Table_0 , ret);

  ret=crc16_calc((uint8_t*)&D_Data_Manufacturer_Name[0],(uint32_t)&D_Manufacturer_ManufacturerInfo[0]-(uint32_t)&D_Data_Manufacturer_Name[0], ret);

  ret=crc16_calc((uint8_t*)&D_Integrity_Static_Chem_DF_Signature,(BLOCK_A-1)-(uint32_t)&D_Integrity_Static_Chem_DF_Signature, ret);
  
  DataFlash_Write((uint32_t)(&D_Integrity_Static_DF_Signature), (uint8_t *)&ret, 2);
}


void read_processmsg(uint8_t cmd)
{
  static uint32_t dataCnt=0;
  if (cmd > 0xA6)// 无效寄存器
  {
    nReadLen = 0;
    memset(tx_buffer, 0, BUFFER_LEN);
    return;
  }

  if (cmd != 0x44)
  {
    nReadLen = scom_no_tbl[cmd].acrem;
  }

  if (scom_no_tbl[cmd].aadr == NULL)
  {
    memset(tx_buffer, 0, BUFFER_LEN);
    return;
  }

  switch (cmd)
  {
  case 0x20:
  {
      tx_buffer[0] = D_Data_Manufacturer_Name[0];
      nReadLen = tx_buffer[0] + 1;
      memcpy(&tx_buffer[1], scom_no_tbl[cmd].aadr, nReadLen - 1);
    // }
    break;
  }
  case 0x21:
   {
      tx_buffer[0] = D_Data_Device_Name[0];
      nReadLen = tx_buffer[0] + 1;
      memcpy(&tx_buffer[1], scom_no_tbl[cmd].aadr, nReadLen - 1);
    // }
    break;
  }
  case 0x22:
  {
     {
      tx_buffer[0] = D_Data_Device_Chemistry[0];
      nReadLen = tx_buffer[0] + 1;
      memcpy(&tx_buffer[1], scom_no_tbl[cmd].aadr, nReadLen - 1);
    // }
    break;
  }
  }
  case 0x23:
  case 0x28:
  case 0x2A:
  case 0x2f:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
  case 0x76:
  case 0x77:
  case 0x78:
  case 0x7a:
  case 0x7b:
  {
    // if (f_sec0 ^ f_sec1) // ACCESS(FA or US)
    // {
      tx_buffer[0] = scom_no_tbl[cmd].acrem;
      nReadLen = tx_buffer[0] + 1;
      memcpy(&tx_buffer[1], scom_no_tbl[cmd].aadr, nReadLen - 1);
    // }
    break;
  }
  case 0x63:
  case 0x64:
  case 0x65:
  case 0x66:
  case 0x67:
    break;
  case 0x44:
  {
    if (nReadLen <= scom_no_tbl[cmd].acrem)
    {
      memcpy(tx_buffer, scom_no_tbl[cmd].aadr, nReadLen);
    }
    break;
  }
  case 0x2d:
  {
    volatile uint16_t rc_report;
    rc_report = lrcdr_w / 3600 / 4;
    memcpy(tx_buffer,&rc_report,2);
    break;
  }
  case 0xa0:
  {
    tx_buffer[0] =0x20;
    nReadLen = tx_buffer[0] + 1;
    memcpy(&tx_buffer[1], (uint32_t *)(0x08000000+dataCnt), nReadLen - 1);
    dataCnt+=0x20;
    break;
  }
  case 0xa1:
  {
    dataCnt=0;
    tx_buffer[0]=0x02;
     tx_buffer[1]=0x01;
      tx_buffer[2]=0x01;
    nReadLen = tx_buffer[0] + 1;
    break;
  }
  
  default: // read word
  {
    memcpy(tx_buffer, scom_no_tbl[cmd].aadr, nReadLen);
    break;
  }
  }
}

void SmbusTimeout_Chk(void) // IIC timeout
{
  // while (1)
  // {
  //   if (__I2C_FLAG_STATUS_GET(I2C1, BUSY) == SET)
  //   {
  //     f_slvto_req = ON;
  //     if (aslvto_cnt >= MAX_SMBUSTIME)
  //     {
  //       aslvto_cnt = 0;
  //       f_slvto_req = OFF;
  //       I2C_init();
  //       // i2c_gpio_init();
  //       // i2c_salve_init();
  //       break;
  //     }
  //   }
  //   else
  //   {
  //     aslvto_cnt = 0;
  //     f_slvto_req = OFF;
  //     break;
  //   }
  // }

  static uint16_t I2C_TimeOut_Count = 0;

    for(uint16_t i = 0; i < I2C_TIME_OUT_CNT; i++)
    {
        if(__I2C_FLAG_STATUS_GET(I2C1, BUSY) == SET)
        {
            I2C_TimeOut_Count++;
        }
        else
        {
            I2C_TimeOut_Count = 0;
            break;//非busy时跳出
        }
        delay_us(100);
    }

    if((I2C_TimeOut_Count == I2C_TIME_OUT_CNT) || (get_iic_arblo == 1) || (get_iic_buserr == 1))
    {
        //logInfo("I2C_TimeOut_Count = %d, get_iic_arblo = %d, get_iic_buserr = %d", I2C_TimeOut_Count, get_iic_arblo,
                //get_iic_buserr);
          I2C_init();
        I2C_TimeOut_Count = 0;
        get_iic_arblo = 0;
        get_iic_buserr = 0;
       
    }
}

void bi2cs_dataCmd_init(void)
{
  uint8_t all;
  	// delay_ms(5000);

  FirstCVT_Converter();
  if (Record_FullChargeCapacity == 0 || Record_FullChargeCapacity == 0xFFFF) // Set Initial FCC, RC, RSOC
  {

    t_com10 = D_INITIAL_FCC; // set initial FCC
    Record_SOH = 100;
    _SoH = Record_SOH;
    t_com89 = D_Design_Capacity_mAh;
    Record_Del_lrc = 0;
    Record_Chargefactor = 1000;
    Record_Dischargefactor = 1000;
    _GaugeStatus3.QMax0 = D_State_QmaxCell1;
    _GaugeStatus3.QMax1 = D_State_QmaxCell2;
    _GaugeStatus3.QMax2 = D_State_QmaxCell3;
    _GaugeStatus3.QMax3 = D_State_QmaxCell4;
    g_QamxPack = D_State_QmaxPack;
    SHA256_Key_Init();

    Init_Cap();
    
  }
  else
  {

    t_com10 = Record_FullChargeCapacity;
    _CycleCount =Record_CycleCount;
    t_com89 = Record_IdealFCC;
    t_com8a = Record_IRsoc;

    _GaugeStatus3.QMax0 = Record_QmaxCell0;
    _GaugeStatus3.QMax1 = Record_QmaxCell1;
    _GaugeStatus3.QMax2 = Record_QmaxCell2;
    _GaugeStatus3.QMax3 = Record_QmaxCell3;
    // if (_CycleCount < D_New_use_df_cycle)
    // {
     // Init_Cap();
    // }
    // else
    // {
    //   t_com0d = DF_RSOC;
    // }

    if (Record_ShutDown_Mode == 0x00f0)
    {
      t_com0d = Record_RSOC;
      Record_ShutDown_Mode = 0x0010;
      lrc_w_last = Record_lrc_w;

    
      CellTemp_last_time_update = CellTemp;
      t_com0dsoclast = t_com0d; // RelativeStateOfCharge// RelativeStateOfCharge=t_com0d; 20230409 updated part 1
    }
    else
    {
      Init_Cap();
    }
  }
  t_com2b = 10;
  _PFStatus.value = Record_PFStatus;
  t_com54 = Record_OperationStatus;
  _AtRate = D_Design_Capacity_mAh / 2;
  t_com00 = 0x0018;
  t_com0c = 1;
  t_com26 = 0x0003;
  

  Charge_Term=D_Termination_Charge_Term_Taper_Current;
  t_DBPT.SystemResistance=D_DBPT_SystemResistance;
  t_DBPT.PackResistance=D_DBPT_PackResistance;
  t_DBPT.MinSysVoltage=D_DBPT_MinSysVoltage;

  f_sdmCFET = ON;
  f_sdmDFET = ON;
  f_sdm = OFF;
  f_sleep = OFF;
  t_com57 = (t_com57 & 0xfc07) | (D_Manufacturing_Status_Init & 0x03f8);
  // if (D_DA_Configuration_NR == 0) // 5.16
  // {
  //   uint8_t presd;
  //   afe_gpio_input_data_bit_read(GPIO_PB0_PIN, &presd);
  //   if (presd)
  //   {
  //     f_pres = OFF;
  //   }
  //   else
  //   {
  //     f_pres = ON;
  //   }
  // }

  if (UF_SEAL_COUNT != 0 && UF_SEAL_COUNT != 0xFFFF)
  {
    f_sec0 = ON;
    f_sec1 = ON;
  }
  else
  {
    f_sec0 = ON;
  }
  Make_RC();
  Make_iRC();
  calc_DFSignature();
  tccup = (uint16_t)((long)t_com10 * ABS(D_Cycle_Count_Percentage) / 100);
  toldrc = t_com0f;
  f_rsoc_hold=D_SBS_Gauging_Configuration_RSOC_HOLD;
  old_rsoc=t_com0d;
}

void Soft_Reset()
{
  DFDataSave();
  DF_Write();
  delay_ms(50);
  __NVIC_SystemReset();
}

void SmbusMACWriteInstruction(void)
{
  uint16_t regMfg = 0;

  if (write_flag)
  {
    //write_processmsg(rx_buffer, iic_rx_cnt);
    write_flag = 0;
  }

  // regMfg = (D_Manufacturing_Status_Init & 0xfc07) | (t_com57 & 0x03f8);

  // if ( (regMfg ^ D_Manufacturing_Status_Init))
  // {
  //   DataFlash_Write(&D_Manufacturing_Status_Init, (uint8_t *)&regMfg, 2);
  // }

  // if(_OptCommand2.value != D_3E)
  //{
    // DataFlash_Write(&D_3E, (uint8_t *)&_OptCommand2, 2);
  //}
  if (f_reset_mcu)
  {
    Write_UpFlash();
    Soft_Reset();
    
  }
  if (f_Seal_trip)
  {
    f_Seal_trip = OFF;
    f_sec0 = ON;
    f_sec1 = ON;
    UF_SEAL_COUNT+=2;
    //printf("Seal Count = %d\n", UF_SEAL_COUNT);
    DFDataSave();
    DF_Write();
    //Write_UpFlash();
  }
  if (f_debugMode)
  {
    Write_UpFlash();
    Soft_Reset();
  }
  if (f_pf_erase)
  {
    f_pf_erase = OFF;
    _PFAlert.value = 0;
    _PFStatus.value = 0;
    f_pf = OFF;
  }
  if (f_updata_en)
  {
   
    f_updata_en = OFF;
    UF_FLAG = ON;
    Write_UpFlash();
    DF_Erase_Para();
    delay_ms(50);
    __NVIC_SystemReset();
  }
  if (f_bbr_erase)
  {
    uint8_t ret;
    // S_Record zeroArray;
    f_bbr_erase = 0;
    Write_UpFlash();
    // memset(&zeroArray,0,sizeof(S_Record));
    // DataFlash_Write((uint32_t)&(flashdata.b_Staging_Area.s_Record), &zeroArray, sizeof(S_Record));
    ret = Block_Erase(BLOCK_A) & Block_Erase(BLOCK_B);

    if (!ret)
    {
      f_dfe = OFF;
    }
    delay_ms(50);
    __NVIC_SystemReset();
  }
  if (f_lt_erase)
  {
    uint8_t ret;
    f_lt_erase = 0;

    ret = Block_Erase(LF_BLOCK_A) & Block_Erase(LF_BLOCK_B);
    lifetime_init();
    if (!ret)
    {
      f_dfe = OFF;
    }
  }
  if (!f_dfe) // DataFlash erasing ?
  {
    if (f_dfreq) // Is there DF update request ?
    {
      DFDataSave();
      if (DF_Write())
      {
        f_dfreq = OFF; // Clear DF update request
      }
    }
    if (f_ltreqW)
    {
      lt_banlance();
      lifetime_time_store();
      if (LifeTimeData_WriteDF())
      {
        f_ltreqW = OFF;
        lifetime_time_clear();
      }
    }
    if(f_AUTH)
    {
      f_AUTH =0;
        Write_UpFlash();
    }
  }
}
