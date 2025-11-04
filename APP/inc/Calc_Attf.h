#ifndef __CALC_ATTF_H__
#define __CALC_ATTF_H__

#include "main.h"
void ATTF_SetFCC(unsigned short fcc);
void ATTF_SetChgFlag(unsigned char fchg);
void ATTF_SetRC(unsigned short rc);
void ATTF_SetTEM( char tem);
void ATTF_SetFCFlag( unsigned char f_fc );
unsigned short Calc_ATTF1(short current);
void ATTF_clear(void);
extern uint32_t  usAttfLast;  //��¼��һ�ε�attf�� ���û��ɾ��?
extern int16_t cap_fccjudge[3] ;// current in every 10s .
#endif