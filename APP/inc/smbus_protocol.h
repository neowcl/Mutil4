#ifndef __BI2CS_INTERFACE_H__
#define __BI2CS_INTERFACE_H__
#include "main.h"

#pragma _align(1)

#define KEYLEN 3
#define FRAMELEN 0x20
#define BUFFER_LEN  38
#define  BLOCK_CMD_Authenticate_SEND_LEN 0x14
#define I2C_TIME_OUT_CNT        1000

typedef struct									// smbus function data
{
	uint8_t	acrem;								// read data num
	uint8_t *aadr;								// access address
} _ST_SMB;

#define f_us	(!f_sec0 && f_sec1)
#define f_fas	(f_sec0 && !f_sec1)

extern  uint16_t acomflg;						// Flags for SMBus
#define f_slvto_req		DEF_BIT0(&acomflg)		// Slave communication timeout check request flag
#define f_slv_busy		DEF_BIT1(&acomflg)		// Slave timeout flag
#define f_no_smbus		DEF_BIT2(&acomflg)		// No Smbus communication flag
#define f_lowBus_timout   DEF_BIT3(&acomflg)
#define f_last_timeout_status		DEF_BIT4(&acomflg)		// 
// #define f_fas	DEF_BIT5(&acomflg)		// 
#define f_preslhl		DEF_BIT6(&acomflg)		// pres  Low-high-low
#define f_pres_h		DEF_BIT7(&acomflg)		// pres  Low-high-low
#define f_pres_l		DEF_BIT8(&acomflg)		// pres  Low-high-low

extern uint16_t DataFlash_W1;
#define	f_ShutDown		DEF_BIT0(&DataFlash_W1)
//#define	f_FuseTg		  DEF_BIT3(&DataFlash_W1)
#define	f_pf_erase		DEF_BIT4(&DataFlash_W1)
#define	f_bbr_erase		DEF_BIT5(&DataFlash_W1)
#define	f_LEDTg			  DEF_BIT6(&DataFlash_W1)
#define	f_LEDDspPr		DEF_BIT7(&DataFlash_W1)
#define f_RSOCWrite DEF_BIT8(&DataFlash_W1)
#define f_AccChg DEF_BIT9(&DataFlash_W1)
#define f_Seal_trip DEF_BIT10(&DataFlash_W1)

extern uint16_t DataFlash_W2;
#define	f_IATAFcc		DEF_BIT0(&DataFlash_W2)
#define	f_AccDsg		DEF_BIT1(&DataFlash_W2)
#define	f_reset_Acc		DEF_BIT2(&DataFlash_W2)
#define	f_AccStop		DEF_BIT3(&DataFlash_W2)
#define	f_AccStart		DEF_BIT4(&DataFlash_W2)
#define	f_IATAShutD		DEF_BIT5(&DataFlash_W2)
#define	f_IATARm		DEF_BIT6(&DataFlash_W2)

extern  volatile uint8_t  		aslvto_cnt;			    // Slave timeout counter
extern  volatile uint16_t      no_com_cnt;				// Clear no comm time counter
extern  volatile uint8_t      anosmb_ms;
extern  volatile uint16_t lowBus_cnt;
#define MAX_SMBUSTIME   100   //ms

extern int32_t lrc_w_last ;
extern uint16_t  t_com0dsoclast ; 
extern int8_t CellTemp_last_time_update ; 

extern uint8_t tx_count;
extern uint8_t g_RecvCnt;
extern uint8_t rx_buffer[BUFFER_LEN];
extern uint8_t tx_buffer[BUFFER_LEN];
extern uint8_t pReg;

extern volatile uint8_t	apec;					// PEC
extern uint8_t  nReadLen;

extern _ST_SMB ssmbdata;						// SMBus communication information



/*         to solve when chazhe chondianqi  100% 99% 98% 97% 96%                             */ 
	


/*         to solve when chazhe chondianqi  100% 99% 98% 97% 96%                             */ 


///***********************************************************************
//	Constant definitions
//***********************************************************************/

typedef union
{
	uint8_t data[34];
	struct
	{
		uint16_t nAltManufacturerAccess; 
		uint8_t  nMACData[32];
	}MAC_T;
	
}_BMS_MAC;
extern _BMS_MAC eMac; 

//Security Flag
typedef struct
{
    uint8_t SE_US_STEP1     : 1;    // 
    uint8_t US_FA_STEP1     : 1;    //
    uint8_t HMAC_STEP1      : 1;    //
    uint8_t HMAC_STEP2      : 1;    //
    uint8_t rsvd            : 4;
} SC_Flag_T;
extern SC_Flag_T SC_Flag;

extern uint16_t Charge_Term;

extern uint8_t  MACDataLength;

extern uint8_t NoLoadRemCap[2];// No Load Rem Cap  0x005A No Load Rem Cap
extern uint8_t NoofPartialResets ; //No. of Partial Resets
extern uint8_t NoofFullResets; // No.of Full Resets
extern uint8_t NoofWDTResets ; // No.of WDT Resets
void calc_DFSignature(void);
extern uint32_t TotalFWRuntime ; // Total FW Runtime

extern uint16_t State_of_HealthFCC ;    // State-of-Health FCC FCC_SOH
extern uint16_t StateofHealthenergy;//State-of-Health energy
extern uint16_t FilteredremainingcapacitymAh ;    // State-of-Health FCC mAh

extern uint32_t AccumulatedTime ;     // Accumulated Time
extern uint16_t AccumulatedCharge ; // Accumulated Charge 

void CRC8_Calc(uint8_t a);
void I2C_ResetBuff(void);
void write_processmsg(uint8_t*buff,uint8_t len);
void read_processmsg(uint8_t cmd);
void ReadFlashData(uint8_t *dst_buff, uint16_t Offset);
void SmbusMACWriteInstruction(void);
void I2C_init(void);
void SmbusTimeout_Chk(void);
void bi2cs_dataCmd_init(void);
void SubWriteData(uint16_t Command);//write data
//Block SubCmdReadData(uint16_t Command);//read data
void SubWriteCtrlCmd(uint16_t Command);
void Soft_Reset();
#endif
