#include "ram.h"

float Ts_max;
float Ts_min;
float aveTemp;
int32_t  V_min = 0;
int32_t  V_max = 0;
uint16_t  I_abs = 0;
float FETTemp;// Current absolute value

uint16_t  t_com79;

uint8_t f_study_d1;
uint8_t f_study_d2;

uint16_t D_0PVOLT ; // D_FCCMINLIMIT


_COM com_data;
// _DF df_data;
_Mac t_com44; 

uint16_t t_com00;

// PFAlert nPFAlert;//t_com52;//PFAlert()
// PFStatus nPFStatus;//t_com53;//PFStatus()
OperationStatus nOperationStatus;
ChargingStatus nChargingStatus;//t_com55;//ChargingStatus()
GaugingStatus nGaugingStatus;//t_com56;//GaugingStatus()
ManufacturingStatus nManufacturingStatus;//t_com57;//ManufacturingStatus()
uint8_t nAFERegister[21];//t_com58;//AFERegister() 
uint8_t nLifeTimeDataBlock1[32];//t_com60t;//LifetimeDataBlock1() 
uint8_t nLifeTimeDataBlock2[20];//t_com61t;//LifetimeDataBlock2() 
uint8_t nLifeTimeDataBlock3[4];//t_com62t;//LifetimeDataBlock3() 
LIFETIMEDATABLOCK4 nLifeTimeDataBlock4;//t_com63t;//LifetimeDataBlock4() 
LIFETIMEDATABLOCK5 nLifeTimeDataBlock5;//t_com64t;//LifetimeDataBlock5() 
uint8_t nLifeTimeDataBlock6[32];//t_com65t;//LifetimeDataBlock6() 
uint8_t nLifeTimeDataBlock7[32];//t_com66t;//LifetimeDataBlock7() 
uint8_t nLifeTimeDataBlock8[32];//t_com67t;//LifetimeDataBlock8() 
uint8_t nLifeTimeDataBlock11[32];//t_com6at;//LifetimeDataBlock11() 
uint8_t nLifeTimeDataBlock12[32];//t_com6bt;//LifetimeDataBlock12() 

FILTEREDCAP nFilteredCapacity;//t_com78;//FilteredCapacity()






