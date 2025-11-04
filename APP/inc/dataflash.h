#ifndef __DATAFLASH_H__
#define __DATAFLASH_H__

#include "main.h"

#define TRUE	1
#define FALSE	0

#define	BLOCK_A		((uint32_t)0x0801E800)						// Block A Erase address
#define BLOCK_B   ((uint32_t)0x0801EC00)
#define BLOCK_A_ST	0x0801E840						// Block A Data start address
#define BLOCK_B_ST	0x0801EC40						// Block B Data start address
#define DF_ST_OFF	0x0040						// DataFlash data start offset
#define DFBLOCK		16							// DataFlash?g?p?G???A??												// Number of area of DataFlash
#define DF_LEN		240							// DataFlash?G???A?P??T?C?Y
//lifetime
#define  LTBLOCK              8
#define  LT_LEN               480
#define  LF_DATA_OFFSET	      0x0040						// DataFlash data start offset
#define  LF_BLOCK_A           0x0801F000
#define  LIFETIME_A_ST        0x0801F040 
#define  LF_BLOCK_B           0x0801F400
#define  LIFETIME_B_ST        0x0801F440 
#define USER_KEY_REGION       0x1F001A00
#define USER_KEY_LEN          16


#define W_OK		0xA0						// Write OK
#define W_NG		0x07						// Write NG
#define AREA_NG		0x08						// 

#define f_dfreq		DEF_BIT0(&adfflg)			// 
#define f_dfe		DEF_BIT1(&adfflg)			// 												// DataFlash erasing flag
#define f_ltreq     DEF_BIT2(&adfflg)			// DataFlash LifeTime
#define f_dfe_areq	DEF_BIT3(&adfflg)			// BlockA erase request											// BlockA erase request flag
#define f_dfe_breq	DEF_BIT4(&adfflg)			// BlockB erase request 
#define f_ltreqW	DEF_BIT5(&adfflg)           // LifeTime Write
#define f_lf_areq	DEF_BIT6(&adfflg)			// LF_BlockA erase request											// BlockA erase request flag
#define f_lf_breq	DEF_BIT7(&adfflg)			// LF_BlockB erase request



#define FLASH_PAGE_SIZE  ((uint32_t)0x00000400)        // FLASH Page Size
#define FLASH_START_ADDR ((uint32_t)0x08000000) // Start of user test Flash area
#define FLASH_END_ADDR   ((uint32_t)0x08030000)
#define   DF_FLASH_OFFSET  0x0801A000

#define  RECORD_OFFSET      0x4800
#define  LIFETIMES_OFFSET   0x5000

/* Forbid cipher RAM&ROM configure */
#define CIPHER_CONFIG_ADDR         0x1FFFFC5C
#define FORBID_CIPHER_RAM_ROM        0xAC53BC43

#define MAC_DATA_LEN        32

//DFUpdate
typedef struct 
{
    uint16_t FLAG         : 1;
	uint16_t DataFlash	  : 1;      // 
	uint16_t SecKeys      : 1;
	uint16_t AuthKey      : 1;//Authentication Key
    uint16_t AFICheck     : 1;
    uint16_t DCHECK       : 1;
    uint16_t AccCT        : 1;
    uint16_t AccDT        : 1;
    uint16_t CVOverride   : 1;
    uint16_t RSVD         : 8;
}DFUpdate_T;
extern DFUpdate_T DFUpdate;
extern uint16_t adfflg;

extern int8_t Flash_Erase(uint8_t index);
extern int8_t DataFlash_Write(uint32_t flash_addr, uint8_t *data,uint16_t length);
extern void flash_decode(void);
//extern void DF_Erase_A(void);
//extern void DF_Erase_B(void);
//extern void DF_Erase_LT(void);
extern int8_t Block_Erase(uint32_t Block_Addr);
extern void DF_IndexW(uint32_t adata);
extern void DFW_Index(void);
extern uint8_t DF_Write(void);
extern void DF_Read(void);
void DFUdata_Chk(void);
extern void  LifeTimeData_ReadDF(void);
extern uint8_t  LifeTimeData_WriteDF(void);
void DF_Erase_Para(void);
void lifetime_init(void);

uint8_t efuse_key_write(uint8_t *key);

void revision_stage(void);

void DF_Erase_Record(void);
uint8_t OSCM_EnterExit_Write(void);
uint8_t OSCM_EnterExit_Read(void);

#endif


