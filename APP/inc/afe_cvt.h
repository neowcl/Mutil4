#ifndef __CALC_CVT_H__
#define __CALC_CVT_H__
#include "main.h"

#define  GET_TRIM_VALUE(falsh_addr)  (uint16_t)(((*(uint32_t *)falsh_addr) & 0x00FF0000) >>8) | (uint16_t)((* (uint32_t *)falsh_addr) & 0x000000FF) 
#define RT_TICK_PER_SECOND 1000

#define TIME_TO_HOUR (1000*3600)
#define SYS_CELL_NUM_MAX 5
#define CALIBRATION_AMP 16384
#define CURRENT_MAX_LIMIT (32*1000)
#define CURRENT_MIN_LIMIT (-32*1000)
#define CALI_TIMEOUT_MS (60*1000)
#define SYS_CELL_NUM_MAX         5//电池包支持的最大电芯数量
typedef enum  
{ 
	IN_TEMP=0,
	TS1, 
	TS2,
	TS3,
	TS4,
	VC4,
	V_PACK,
	CELL_1,
	CELL_2,
	CELL_3,
	CELL_4,
}VADC_TypeDef;

#pragma pack(push,1)
typedef struct
{
    int32_t pack_adc_current;/*!< 随着采样电阻增大，原始adc采样值转换成mA后还是会超出int16的范围 */
    //电流
    int16_t pack_current;
    //pack电压和电池电压
    uint16_t pack_voltage_val;
    int16_t bat_voltage_val;
    //电芯电压
    int16_t cell_vol_val[SYS_CELL_NUM_MAX];      //mv
    //内温和外温
    int16_t temprature_inner_val;            //0.1degc
    int16_t temprature_ex_val[SYS_CELL_NUM_MAX]; //0.1degc，用于上报，没有选择的温度默认为0
        
    uint8_t pack_temprature_valid[SYS_CELL_NUM_MAX];
} Afe_data;/*!< 存储用于上报的数据 */
#pragma pack(pop)
extern Afe_data afe_data;

uint8_t CVT_Init(void);
void FirstCVT_Converter(void);
void Get_CVT(void);
void Enable_CVT(void);
void DCR_Mode(void);
void start_cc_convert(void);


#endif

