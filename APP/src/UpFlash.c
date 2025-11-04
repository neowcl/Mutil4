#include "main.h"
#include "UpFlash.h"

volatile _UF UF_Msg;

void Read_UpFlash(void)
{
    uint8_t al1;
    uint8_t *apufadr;
    apufadr = (uint8_t*)UF_START_ADDR;
    for( al1=0; al1 < UFTSIZE; al1++,apufadr++ )
    {
        aufdat[al1] = *apufadr;
    }
}


void Write_UpFlash(void)
{
	DataFlash_Write((uint32_t)UF_START_ADDR,&aufdat[0],UFTSIZE);
    delay_ms(50);
}


void SHA256_Key_Init(void)
{
    uint8_t  key[0x20]={0x02,0xB3,0xA8,0x5E,0xA4,0xC1,0xA6,0xDB,0x6F,0xBD,0x1F,
                                  0xD5,0x76,0x7C,0x1A,0x42,0x31,0x4F,0x37,0xBA,0x7C,0x94,0x60,
                                    0xC9,0xED,0x79,0xA1,0x2B,0xB2,0xB5,0xD9,0x9C};
     memcpy(UF_Msg.sufdat.SHA256_Key,key,0x20);
}



