#ifndef __UPFLASH_H__
#define __UPFLASH_H__

#include "stdint.h"

typedef struct
{
    uint32_t  UF_Flag;       // 升级标志位
    uint32_t  UF_FileLen;    // 文件长度
    uint32_t  UF_FileCrc;    // 升级文件 CRC
    uint32_t  UF_BLVersion;  // BootLoader版本
    uint32_t  UF_BackupREG;
    uint8_t   SHA256_Key[0x20];
    uint16_t  UF_Seal_Count;

    

}_UPFLASH;

#define UFTSIZE    sizeof(_UPFLASH)

typedef union
{
	_UPFLASH	  sufdat;								// Flexible data
	uint8_t	      uc[UFTSIZE];							// Byte alignment
}_UF;

extern volatile  _UF     UF_Msg;

#define aufdat       UF_Msg.uc
#define UF_FLAG      UF_Msg.sufdat.UF_Flag
#define UF_FILELEN   UF_Msg.sufdat.UF_FileLen
#define UF_FILECRC   UF_Msg.sufdat.UF_FileCrc
#define UF_BLVERSION UF_Msg.sufdat.UF_BLVersion
#define UF_BackupREG UF_Msg.sufdat.UF_BackupREG
#define SHA256_KEY   UF_Msg.sufdat.SHA256_Key
#define UF_SEAL_COUNT   UF_Msg.sufdat.UF_Seal_Count


#define UF_START_ADDR    0x801FC00

void Read_UpFlash(void);
void Write_UpFlash(void);
void SHA256_Key_Init(void);



#endif

