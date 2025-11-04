#ifndef __DEFINEFILE_H__
#define __DEFINEFILE_H__

#define FDSIZE 	sizeof(FlashData)

#define Ptr8i(value) ((int8_t*)&(value))
#define Ptr8u(value) ((uint8_t*)&(value))
#define Ptr16i(value) ((int16_t*)&(value))
#define Ptr16u(value) ((uint16_t*)&(value))

#define BIT(reg, bit) (reg.bits.bit)
#define REG(reg) (reg.value)

#define OCV_SOC     Ptr16u(flashdata.b_OCV_SOC_table.s_OCV_table)
#define SOC_R1     Ptr16u(flashdata.b_OCV_SOC_table.s_SOC_R1_table)
#define SOC_R2     Ptr16u(flashdata.b_OCV_SOC_table.s_SOC_R2_table)
#define INREG_CYCLE Ptr16u(D_CEDV_Internal_impedance_cycle1)
#define INREG_TBL   Ptr8u(D_CEDV_Internal_impedance_table1)
#define D_CRATE_TBL Ptr8u(D_CP_table_C_rate_1)
#define D_TRATE_TBL Ptr8i(D_CP_table_T_rate_1)
#define CPH_TBL     Ptr16u(D_CPH_voltage_table_C1_T1)
#define CPL_TBL     Ptr16u(D_CPL_voltage_table_C1_T1)
#define QCAP_TBL    Ptr16u(D_QCap_Capcity_table_C1_T1)


#define bitMfgStatusInit_GAUGE_EN   (1<<3)
#define bitMfgStatusInit_FET_EN     (1<<4)
#define bitMfgStatusInit_LF_EN      (1<<5)
#define bitMfgStatusInit_PF_EN      (1<<6)
#define bitMfgStatusInit_BBR_EN     (1<<7)
#define bitMfgStatusInit_FUSE_EN    (1<<8)
#define bitMfgStatusInit_LED_EN     (1<<9)
#define bitMfgStatusInit_ACDSG_EN   (1<<10)
#define bitMfgStatusInit_ACCHG_EN   (1<<11)

#define NUMBER_SERIES   ((D_DA_Configuration_CC1 << 1) + D_DA_Configuration_CC0 + 1)

#endif