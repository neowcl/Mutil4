/**
* @file        cbm858x_afe_vadc.h
* @brief       This file contains all the functions prototypes for the AFE VADC firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.10.30
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.10.30    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858x_AFE_VADC_H__
#define __CBM858x_AFE_VADC_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858x_afe_transimit.h"

/** @addtogroup AFE_StdPeriph_Driver
  * @{
  */

/** @addtogroup AFE_VADC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_VADC_Types AFE_VADC Types
  * @{
  */


/**
  * @brief The VADC configuration structure definition
  */
typedef struct
{
    uint16_t vadc_conversion_num;       /*!< VADC limited cycle conversion number configuration */ 
    uint16_t vadc_conversion_mode;      /*!< VADC conversion mode configuration */ 
    uint16_t vadc_pack_check_en;        /*!< VADC PACK+ short circuit detection enable signal */
    uint16_t vadc_timer_inter_en;       /*!< Timer interrupt triggers VADC enable */
    uint16_t vadc_fs_frequency;         /*!< VADC sampling frequency FS selection */
    uint16_t vadc_chopper_frequency;    /*!< VADC chopper frequency selection */
    uint16_t vadc_chopper_en;           /*!< VADC chopper enable */
    uint16_t vadc_vcm_voltage;          /*!< VADC VCM voltage selection */
    uint16_t vadc_vc4_select;        /*!< VCC-VC4 voltage detection MOS impedance */  
    uint16_t vadc_ibt_current;          /*!< VADC OP_STG1 test bias current */
}vadc_config_t;

/**
* @brief The vadc channel configuration
*/
typedef struct
{
    uint16_t vadc_vadchs;               /*!< VADC channel input selection configuration */
    uint16_t vadc_gain;                 /*!< VADC gain select */
}vadc_channel_config_t;

/**
  * @}
  */


/** @defgroup AFE_VADC_Constants AFE_VADC Constants
  * @{
  */  

/* VADC channel number definition */
#define VADC_CHANNEL_NUM_0          (uint8_t)0x00      /*!< VADC channel number 0 */ 
#define VADC_CHANNEL_NUM_1          (uint8_t)0x01      /*!< VADC channel number 1 */
#define VADC_CHANNEL_NUM_2          (uint8_t)0x02      /*!< VADC channel number 2 */
#define VADC_CHANNEL_NUM_3          (uint8_t)0x03      /*!< VADC channel number 3 */
#define VADC_CHANNEL_NUM_4          (uint8_t)0x04      /*!< VADC channel number 4 */ 
#define VADC_CHANNEL_NUM_5          (uint8_t)0x05      /*!< VADC channel number 5 */
#define VADC_CHANNEL_NUM_6          (uint8_t)0x06      /*!< VADC channel number 6 */
#define VADC_CHANNEL_NUM_7          (uint8_t)0x07      /*!< VADC channel number 7 */
#define VADC_CHANNEL_NUM_8          (uint8_t)0x08      /*!< VADC channel number 8 */ 
#define VADC_CHANNEL_NUM_9          (uint8_t)0x09      /*!< VADC channel number 9 */
#define VADC_CHANNEL_NUM_10         (uint8_t)0x0A      /*!< VADC channel number 10 */

/* VADC channel bit definition */
#define VADC_CHANNEL_0              (uint16_t)0x0001   /*!< VADC channel 0 */ 
#define VADC_CHANNEL_1              (uint16_t)0x0002   /*!< VADC channel 1 */
#define VADC_CHANNEL_2              (uint16_t)0x0004   /*!< VADC channel 2 */
#define VADC_CHANNEL_3              (uint16_t)0x0008   /*!< VADC channel 3 */
#define VADC_CHANNEL_4              (uint16_t)0x0010   /*!< VADC channel 4 */ 
#define VADC_CHANNEL_5              (uint16_t)0x0020   /*!< VADC channel 5 */
#define VADC_CHANNEL_6              (uint16_t)0x0040   /*!< VADC channel 6 */
#define VADC_CHANNEL_7              (uint16_t)0x0080   /*!< VADC channel 7 */
#define VADC_CHANNEL_8              (uint16_t)0x0100   /*!< VADC channel 8 */ 
#define VADC_CHANNEL_9              (uint16_t)0x0200   /*!< VADC channel 9 */
#define VADC_CHANNEL_10             (uint16_t)0x0400   /*!< VADC channel 10 */
#define VADC_CHANNEL_ALL            (uint16_t)0x07FF   /*!< VADC channel bits [0:10] */

/* VADC limited cycle conversion number definition */ 
#define VADC_CONVERSION_NUM_1       (uint16_t)0x0000    /*!< VADC limited cycle conversion once */    
#define VADC_CONVERSION_NUM_2       (uint16_t)0x0080    /*!< VADC limited cycle conversion twice */
#define VADC_CONVERSION_NUM_4       (uint16_t)0x0100    /*!< VADC limited cycle conversion 4 times */
#define VADC_CONVERSION_NUM_8       (uint16_t)0x0180    /*!< VADC limited cycle conversion 8 times */
#define VADC_CONVERSION_NUM_16      (uint16_t)0x0200    /*!< VADC limited cycle conversion 16 times */
#define VADC_CONVERSION_NUM_32      (uint16_t)0x0280    /*!< VADC limited cycle conversion 32 times */
#define VADC_CONVERSION_NUM_64      (uint16_t)0x0300    /*!< VADC limited cycle conversion 64 times */

/* VADC conversion mode definition */ 
#define VADC_CONVER_SINGLE_MODE     (uint16_t)0x0000    /*!< VADC conversion single mode */
#define VADC_CONVER_1CYCLE_MODE     (uint16_t)0x0400    /*!< VADC conversion one cycle mode */
#define VADC_CONVER_FINITE_MODE     (uint16_t)0x0800    /*!< VADC conversion finite cycle mode */

/* VADC PACK+ short circuit detection enable signal */
#define VADC_PACKST_DISABLE         (uint16_t)0x0000    /*!< VADC PACK+ short circuit detection disable */
#define VADC_PACKST_ENABLE          (uint16_t)0x1000    /*!< VADC PACK+ short circuit detection enable */

/* Timer interrupt triggers VADC enable */
#define VADC_TIM_TRIGGER_DISABLE    (uint16_t)0x0000    /*!< Timer interrupt disable triggers VADC */
#define VADC_TIM_TRIGGER_ENABLE     (uint16_t)0x2000    /*!< Timer interrupt enable triggers VADC */

/* VADC sampling frequency FS selection */
#define VADC_FS_512KHZ              (uint16_t)0x0400    /*!< VADC sampling frequency FS 512KHz */

/* VADC chopper frequency selection */
#define VADC_CHOPPER_1_48_FFS       (uint16_t)0x0000    /*!< VADC chopper frequency (1/48)*fFS */
#define VADC_CHOPPER_1_96_FFS       (uint16_t)0x0010    /*!< VADC chopper frequency (1/96)*fFS */
#define VADC_CHOPPER_1_12_FFS       (uint16_t)0x0020    /*!< VADC chopper frequency (1/12)*fFS */
#define VADC_CHOPPER_1_24_FFS       (uint16_t)0x0030    /*!< VADC chopper frequency (1/24)*fFS */

/* VADC chopper enable */
#define VADC_CHOPPER_DISABLE        (uint16_t)0x0000    /*!< VADC chopper disable */
#define VADC_CHOPPER_ENABLE         (uint16_t)0x0004    /*!< VADC chopper enable */

/* VADC VCM voltage selection */
#define VADC_VCM_1_2_VLDO1P8V       (uint16_t)0x0000    /*!< VADC VCM voltage (1/2)*VLDO1P8V */
#define VADC_VCM_3_8_VLDO1P8V       (uint16_t)0x0001    /*!< VADC VCM voltage (3/8)*VLDO1P8V */

#ifdef CBM8581
/* VCC-VC5 voltage detection MOS impedance */
#define VADC_VCC_VC5                (uint16_t)0x0001    /*!< VADC VCC-VC5 voltage detection MOS impedance */
#endif
/* VCC-VC4 voltage detection MOS impedance */
#define VADC_VCC_VC4                (uint16_t)0x0000    /*!< VADC VCC-VC4 voltage detection MOS impedance */

/* VADC OP_STG1 test bias current */
#define VADC_IBT_NO_CURRENT         (uint16_t)0x0000    /*!< VADC do not increase bias current */
#define VADC_IBT_100nA              (uint16_t)0x0040    /*!< VADC increase bias current 100nA */
#define VADC_IBT_200nA              (uint16_t)0x0080    /*!< VADC increase bias current 200nA */
#define VADC_IBT_300nA              (uint16_t)0x00C0    /*!< VADC increase bias current 300nA */

/* VADC channel input mode */
#define VADC_INSIDE_SHORT_AGND      (uint16_t)0x0000    /*!< VADC inside short to AGND, measure VADC offset voltage in mass production */
#define VADC_VTEMPP_INT             (uint16_t)0x0001    /*!< VADC internal temperature sensor */            
#define VADC_V_ETS1                 (uint16_t)0x0003    /*!< VADC external  temperature sensor 1 */
#define VADC_V_ETS2                 (uint16_t)0x0004    /*!< VADC external  temperature sensor 2 */
#define VADC_V_ETS3                 (uint16_t)0x0005    /*!< VADC external  temperature sensor 3 */
#define VADC_V_ETS4                 (uint16_t)0x0006    /*!< VADC external  temperature sensor 4 */
#define VADC_VC4_DIV                (uint16_t)0x0008    /*!< ADC mass production 15mV self-test */
#ifdef CBM8581
#define VADC_VC5_DIV                (uint16_t)0x000C    /*!< Measure 1/20 voltage of VC5  */
#endif
#define VADC_PACK_DIV               (uint16_t)0x0009    /*!< Measure 1/20 voltage of PACK */
#define VADC_PACK_TEST              (uint16_t)0x000D    /*!< Measure PACK+, this need enable vadc_pack_check_en */
#define VADC_VC1_0                  (uint16_t)0x0010    /*!< Measure the battery voltage of section 1 */
#define VADC_VC2_VC1                (uint16_t)0x0011    /*!< Measure the battery voltage of section 2 */
#define VADC_VC3_VC2                (uint16_t)0x0012    /*!< Measure the battery voltage of section 3 */
#define VADC_VC4_VC3                (uint16_t)0x0013    /*!< Measure the battery voltage of section 4 */
#ifdef CBM8581
#define VADC_VC5_VC4                (uint16_t)0x0014    /*!< Measure the battery voltage of section 5 */
#endif
#define VADC_VCC_PACK               (uint16_t)0x0015    /*!< Measure the impedance of the discharge MOS */
#define VADC_VC4_VCC                (uint16_t)0x0016    /*!< Measure the impedance of the charging  MOS */

/* VADC status flag */
#define VADC_FLAG_BUSY              (uint16_t)0x0002    /*!< VADC busy */  
#define VADC_FLAG_VADDR0_VALID      (uint16_t)0x0020    /*!< VADC channel 0 data valid */
#define VADC_FLAG_VADDR1_VALID      (uint16_t)0x0040    /*!< VADC channel 1 data valid */ 
#define VADC_FLAG_VADDR2_VALID      (uint16_t)0x0080    /*!< VADC channel 2 data valid */  
#define VADC_FLAG_VADDR3_VALID      (uint16_t)0x0100    /*!< VADC channel 3 data valid */
#define VADC_FLAG_VADDR4_VALID      (uint16_t)0x0200    /*!< VADC channel 4 data valid */
#define VADC_FLAG_VADDR5_VALID      (uint16_t)0x0400    /*!< VADC channel 5 data valid */
#define VADC_FLAG_VADDR6_VALID      (uint16_t)0x0800    /*!< VADC channel 6 data valid */
#define VADC_FLAG_VADDR7_VALID      (uint16_t)0x1000    /*!< VADC channel 7 data valid */
#define VADC_FLAG_VADDR8_VALID      (uint16_t)0x2000    /*!< VADC channel 8 data valid */
#define VADC_FLAG_VADDR9_VALID      (uint16_t)0x4000    /*!< VADC channel 9 data valid */
#define VADC_FLAG_VADDR10_VALID     (uint16_t)0x8000    /*!< VADC channel 10 data valid */

/* Valid flag of VADC last pdm code value sampled by digital filter */
#define VADC_FLAG_VADDN0_VALID      (uint16_t)0x0020    /*!< VADC channel 0 last pdm code value valid */
#define VADC_FLAG_VADDN1_VALID      (uint16_t)0x0040    /*!< VADC channel 1 last pdm code value valid */ 
#define VADC_FLAG_VADDN2_VALID      (uint16_t)0x0080    /*!< VADC channel 2 last pdm code value valid */  
#define VADC_FLAG_VADDN3_VALID      (uint16_t)0x0100    /*!< VADC channel 3 last pdm code value valid */
#define VADC_FLAG_VADDN4_VALID      (uint16_t)0x0200    /*!< VADC channel 4 last pdm code value valid */
#define VADC_FLAG_VADDN5_VALID      (uint16_t)0x0400    /*!< VADC channel 5 last pdm code value valid */
#define VADC_FLAG_VADDN6_VALID      (uint16_t)0x0800    /*!< VADC channel 6 last pdm code value valid */
#define VADC_FLAG_VADDN7_VALID      (uint16_t)0x1000    /*!< VADC channel 7 last pdm code value valid */
#define VADC_FLAG_VADDN8_VALID      (uint16_t)0x2000    /*!< VADC channel 8 last pdm code value valid */
#define VADC_FLAG_VADDN9_VALID      (uint16_t)0x4000    /*!< VADC channel 9 last pdm code value valid */
#define VADC_FLAG_VADDN10_VALID     (uint16_t)0x8000    /*!< VADC channel 10 last pdm code value valid */

/* VADC channel PGA gain */
#define VADC_CHANNEL_GAIN_1_2       (uint8_t)0x00       /*!< VADC channel PGA gain 1/2 */
#define VADC_CHANNEL_GAIN_1         (uint8_t)0x01       /*!< VADC channel PGA gain 1 */

/* VADC PACK threshold selection signal */
#define PACK_FIXED_2_6V             (uint16_t)0x0000    /*!< The threshold of PACK is fixed at 2.6V */
#define PACK_PACKTH_SEL             (uint16_t)0x0100    /*!< The threshold of PACK can be determined through packth_sel */

/* VADC PACK threshold configuration */
#define PACK_TH_SEL_2_6V            (uint16_t)0x0000    /*!< PACK threshold voltage 2.6V */
#define PACK_TH_SEL_6V              (uint16_t)0x0040    /*!< PACK threshold voltage 6V */
#define PACK_TH_SEL_9V              (uint16_t)0x0080    /*!< PACK threshold voltage 9V */
#define PACK_TH_SEL_12V             (uint16_t)0x00C0    /*!< PACK threshold voltage 12V */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_VADC_Functions AFE_VADC Functions
  * @{
  */

/**
  * @brief  Initialization VADC configuration.
  * @param  ptr_config: Pointer to a vadc_config_t structure that contains the  
  *                     configuration information for the specified VADC peripheral.
  *         The structure members are configured as follows:
  * @param  vadc_conversion_num (VADC limited cycle conversion number configuration), it can be one of the following values:
  *          @arg VADC_CONVERSION_NUM_1 (VADC limited cycle conversion once, the default configuration) 
  *          @arg VADC_CONVERSION_NUM_2 (VADC limited cycle conversion twice)
  *          @arg VADC_CONVERSION_NUM_4 (VADC limited cycle conversion 4 times)
  *          @arg VADC_CONVERSION_NUM_8 (VADC limited cycle conversion 8 times)
  *          @arg VADC_CONVERSION_NUM_16 (VADC limited cycle conversion 16 times)
  *          @arg VADC_CONVERSION_NUM_32 (VADC limited cycle conversion 32 times)
  *          @arg VADC_CONVERSION_NUM_64 (VADC limited cycle conversion 64 times)
  * @param  vadc_conversion_mode (VADC conversion mode configuration), it can be one of the following values:
  *          @arg VADC_CONVER_SINGLE_MODE (VADC conversion single mode, the default configuration) 
  *          @arg VADC_CONVER_1CYCLE_MODE (VADC conversion one cycle mode)
  *          @arg VADC_CONVER_FINITE_MODE (VADC conversion finite cycle mode)
  * @param  vadc_pack_check_en (VADC PACK+ short circuit detection enable signal), it can be one of the following values:
  *          @arg VADC_PACKST_DISABLE (VADC PACK+ short circuit detection disable, the default configuration) 
  *          @arg VADC_PACKST_ENABLE (VADC PACK+ short circuit detection enable)
  * @param  vadc_timer_inter_en (Timer interrupt triggers VADC enable), it can be one of the following values:
  *          @arg VADC_TIM_TRIGGER_DISABLE (Timer interrupt disable triggers VADC, the default configuration) 
  *          @arg VADC_TIM_TRIGGER_ENABLE (Timer interrupt enable triggers VADC)
  * @param  vadc_fs_frequency (VADC sampling frequency FS selection), it can be one of the following values:
  *          @arg VADC_FS_512KHZ (VADC sampling frequency FS 512KHz)
  * @param  vadc_chopper_frequency (VADC chopper frequency selection), it can be one of the following values:
  *          @arg VADC_CHOPPER_1_48_FFS (VADC chopper frequency (1/48)*fFS, the default configuration) 
  *          @arg VADC_CHOPPER_1_96_FFS (VADC chopper frequency (1/96)*fFS)
  *          @arg VADC_CHOPPER_1_12_FFS (VADC chopper frequency (1/12)*fFS)
  *          @arg VADC_CHOPPER_1_24_FFS (VADC chopper frequency (1/24)*fFS)
  * @param  vadc_chopper_en (VADC chopper enable), it can be one of the following values:
  *          @arg VADC_CHOPPER_DISABLE (VADC chopper disable, the default configuration) 
  *          @arg VADC_CHOPPER_ENABLE (VADC chopper enable)
  * @param  vadc_vcm_voltage (VADC VCM voltage selection), it can be one of the following values:
  *          @arg VADC_VCM_1_2_VLDO1P8V (VADC VCM voltage (1/2)*VLDO1P8V, the default configuration) 
  *          @arg VADC_VCM_3_8_VLDO1P8V (VADC VCM voltage (3/8)*VLDO1P8V)
  * @param  vadc_vc4_select (VCC-VC4 voltage detection MOS impedance), it can be one of the following values:
  *          @arg VADC_VCC_VC4 (VADC VCC-VC4 voltage detection MOS impedance, the default configuration) 
  *          @arg VADC_VCC_VC5 (VADC VCC-VC5 voltage detection MOS impedance, only for CBM8581) 
  * @param  vadc_ibt_current (VADC OP_STG1 test bias current), it can be one of the following values:
  *          @arg VADC_IBT_NO_CURRENT (VADC do not increase bias current, the default configuration) 
  *          @arg VADC_IBT_100nA ( VADC increase bias current 100nA)
  *          @arg VADC_IBT_200nA ( VADC increase bias current 200nA)
  *          @arg VADC_IBT_300nA ( VADC increase bias current 300nA)
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t  afe_vadc_init(vadc_config_t* ptr_config);

/**
  * @brief  Get the vadc second integral vaule.
  * @param  channel: VADC channel select.It can be one of the following values:
  *          @arg VADC_CHANNEL_NUM_0 (VADC channel number 0)
  *          @arg VADC_CHANNEL_NUM_1 (VADC channel number 1)
  *          @arg VADC_CHANNEL_NUM_2 (VADC channel number 2)
  *          @arg VADC_CHANNEL_NUM_3 (VADC channel number 3)
  *          @arg VADC_CHANNEL_NUM_4 (VADC channel number 4)
  *          @arg VADC_CHANNEL_NUM_5 (VADC channel number 5)
  *          @arg VADC_CHANNEL_NUM_6 (VADC channel number 6)
  *          @arg VADC_CHANNEL_NUM_7 (VADC channel number 7)
  *          @arg VADC_CHANNEL_NUM_8 (VADC channel number 8)
  *          @arg VADC_CHANNEL_NUM_9 (VADC channel number 9)
  *          @arg VADC_CHANNEL_NUM_10(VADC channel number 10)
  * @param  vadc_value: Vadc second integral value.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_second_integral_value_get(uint8_t channel, uint32_t* vadc_value);

/**
  * @brief  Get the vadc first integral vaule.
  * @param  vadc_value: Vadc first integral value.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_first_integral_value_get(uint16_t* vadc_value);

/**
  * @brief  Enables or disables the specified VADC peripheral.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   VADC can not simultaneous enabling with VADC TURBO3.0.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables the specified VADC TURBO3.0.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   VADC TURBO3.0 can not simultaneous enabling with VADC.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables the VADC PACK+ short circuit check enable control.
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_pack_short_check_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables the VADC channel.
  * @param  channel: This is channel bit.It can be one of the following values: 
  *          @arg VADC_CHANNEL_0 (VADC channel bit 0)
  *          @arg VADC_CHANNEL_1 (VADC channel bit 1)
  *          @arg VADC_CHANNEL_2 (VADC channel bit 2)
  *          @arg VADC_CHANNEL_3 (VADC channel bit 3)
  *          @arg VADC_CHANNEL_4 (VADC channel bit 4)
  *          @arg VADC_CHANNEL_5 (VADC channel bit 5)
  *          @arg VADC_CHANNEL_6 (VADC channel bit 6)
  *          @arg VADC_CHANNEL_7 (VADC channel bit 7)
  *          @arg VADC_CHANNEL_8 (VADC channel bit 8)
  *          @arg VADC_CHANNEL_9 (VADC channel bit 9)
  *          @arg VADC_CHANNEL_10(VADC channel bit 10) 
  *          @arg VADC_CHANNEL_ALL(VADC channel bits [0:10])   
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   None..
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel_enable_ctrl(uint16_t channel, uint8_t enable_flag);

/**
  * @brief  Enables or disables the VADC TURBO3.0 channel.
  * @param  channel: This is channel bit.It can be one of the following values: 
  *          @arg VADC_CHANNEL_0 (VADC channel bit 0)
  *          @arg VADC_CHANNEL_1 (VADC channel bit 1)
  *          @arg VADC_CHANNEL_2 (VADC channel bit 2)
  *          @arg VADC_CHANNEL_3 (VADC channel bit 3)
  *          @arg VADC_CHANNEL_4 (VADC channel bit 4)
  *          @arg VADC_CHANNEL_5 (VADC channel bit 5)
  *          @arg VADC_CHANNEL_6 (VADC channel bit 6)
  *          @arg VADC_CHANNEL_7 (VADC channel bit 7)
  *          @arg VADC_CHANNEL_8 (VADC channel bit 8)
  *          @arg VADC_CHANNEL_9 (VADC channel bit 9)
  *          @arg VADC_CHANNEL_10(VADC channel bit 10) 
  *          @arg VADC_CHANNEL_ALL(VADC channel bits [0:10])   
  * @param  enable_flag: It can be ENABLE or DISABLE.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel_enable_ctrl(uint16_t channel, uint8_t enable_flag);

/**
  * @brief  Configuration the channel 0 vadc input mode.
  * @param  vadc_vadchs: The channel 0 vadc input mode, it can be one of the following values:
  *          @arg VADC_INSIDE_SHORT_AGND (VADC inside short to AGND, measure VADC offset voltage in mass production ) 
  *          @arg VADC_VTEMPP_INT (VADC internal temperature sensor)           
  *          @arg VADC_V_ETS1 (VADC external  temperature sensor 1) 
  *          @arg VADC_V_ETS2 (VADC external  temperature sensor 2) 
  *          @arg VADC_V_ETS3 (VADC external  temperature sensor 3) 
  *          @arg VADC_V_ETS4 (VADC external  temperature sensor 4) 
  *          @arg VADC_VC4_DIV (ADC mass production 15mV self-test) 
  *          @arg VADC_VC5_DIV (Measure 1/20 voltage of VC5, only for CBM8581)  
  *          @arg VADC_PACK_DIV (Measure 1/20 voltage of PACK) 
  *          @arg VADC_PACK_TEST (Measure PACK+, this need enable vadc_pack_check_en) 
  *          @arg VADC_VC1_0 (Measure the battery voltage of section 1) 
  *          @arg VADC_VC2_VC1 (Measure the battery voltage of section 2) 
  *          @arg VADC_VC3_VC2 (Measure the battery voltage of section 3) 
  *          @arg VADC_VC4_VC3 (Measure the battery voltage of section 4)  
  *          @arg VADC_VC5_VC4 (Measure the battery voltage of section 5, only for CBM8581)  
  *          @arg VADC_VCC_PACK (Measure the impedance of the discharge MOS) 
  *          @arg VADC_VC4_VCC (Measure the impedance of the charging  MOS)     
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel0_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 1 vadc mode.
  * @param  vadc_vadchs: The channel 1 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel1_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 2 vadc mode.
  * @param  vadc_vadchs: The channel 2 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel2_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 3 vadc mode.
  * @param  vadc_vadchs: The channel 3 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel3_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 4 vadc mode.
  * @param  vadc_vadchs: The channel 4 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel4_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 5 vadc mode.
  * @param  vadc_vadchs: The channel 5 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel5_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 6 vadc mode.
  * @param  vadc_vadchs: The channel 6 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel6_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 7 vadc mode.
  * @param  vadc_vadchs: The channel 7 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel7_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 8 vadc mode.
  * @param  vadc_vadchs: The channel 8 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel8_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 9 vadc mode.
  * @param  vadc_vadchs: The channel 9 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel9_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 10 vadc mode.
  * @param  vadc_vadchs: The channel 10 vadc input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel10_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 0 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 0 vadc TURBO3.0 input mode, it can be one of the following values:
  *          @arg VADC_INSIDE_SHORT_AGND (VADC inside short to AGND, measure VADC offset voltage in mass production ) 
  *          @arg VADC_VTEMPP_INT (VADC internal temperature sensor)           
  *          @arg VADC_V_ETS1 (VADC external  temperature sensor 1) 
  *          @arg VADC_V_ETS2 (VADC external  temperature sensor 2) 
  *          @arg VADC_V_ETS3 (VADC external  temperature sensor 3) 
  *          @arg VADC_V_ETS4 (VADC external  temperature sensor 4) 
  *          @arg VADC_VC4_DIV (ADC mass production 15mV self-test) 
  *          @arg VADC_VC5_DIV (Measure 1/20 voltage of VC5, only for CBM8581)
  *          @arg VADC_PACK_DIV (Measure 1/20 voltage of PACK) 
  *          @arg VADC_PACK_TEST (Measure PACK+, this need enable vadc_pack_check_en) 
  *          @arg VADC_VC1_0 (Measure the battery voltage of section 1) 
  *          @arg VADC_VC2_VC1 (Measure the battery voltage of section 2) 
  *          @arg VADC_VC3_VC2 (Measure the battery voltage of section 3) 
  *          @arg VADC_VC4_VC3 (Measure the battery voltage of section 4)
  *          @arg VADC_VC5_VC4 (Measure the battery voltage of section 5, only for CBM8581)   
  *          @arg VADC_VCC_PACK (Measure the impedance of the discharge MOS) 
  *          @arg VADC_VC4_VCC (Measure the impedance of the charging  MOS)        
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel0_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 1 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 1 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel1_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 2 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 2 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel2_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 3 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 3 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel3_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 4 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 4 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel4_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 5 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 5 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel5_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 6 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 6 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel6_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 7 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 7 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel7_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 8 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 8 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel8_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 9 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 9 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel9_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Configuration the channel 10 vadc TURBO3.0 input mode.
  * @param  vadc_vadchs: The channel 10 vadc TURBO3.0 input mode, configuration options are the same as channel 0.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_channel10_mode_config(uint16_t vadc_vadchs);

/**
  * @brief  Initializes the VADC channel according to the specified parameters in the ptr_config structure.
  * @param  channel: 
  * @param  vadc_gain: 
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_channel_gain_config(uint16_t channel, uint8_t vadc_gain);

/**
  * @brief  Vadc down sampling rate set.
  * @param  value: Vadc down sampling, it can be set 128~65535, the default value is 65535.
  * @note   This configuration will work on 11 scan channels simultaneously.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_down_sampling_rate_set(uint16_t value);

/**
  * @brief  Get the vadc down sampling rate.
  * @param  down_sampling_rate: Vadc down sampling  vaule
  * @note   This configuration will work on 11 scan channels simultaneously.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_down_sampling_rate_get(uint16_t* down_sampling_rate);

/**
  * @brief  Vadc TURBO3.0 down sampling rate set.
  * @param  value: Vadc TURBO3.0 down sampling, it can be set 128~65535, the default value is 65535.
  * @note   This configuration will work on 11 scan channels simultaneously.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_turbo30_down_sampling_rate_set(uint16_t value);

/**
  * @brief  Checks whether the specified VADC flag is set or not.
  * @param  flag: Specifies flag to check, it can be one of the following values:
  *          @arg VADC_FLAG_BUSY (VADC busy)          
  *          @arg VADC_FLAG_VADDR0_VALID (VADC channel 0 data valid) 
  *          @arg VADC_FLAG_VADDR1_VALID (VADC channel 1 data valid) 
  *          @arg VADC_FLAG_VADDR2_VALID (VADC channel 2 data valid) 
  *          @arg VADC_FLAG_VADDR3_VALID (VADC channel 3 data valid) 
  *          @arg VADC_FLAG_VADDR4_VALID (VADC channel 4 data valid) 
  *          @arg VADC_FLAG_VADDR5_VALID (VADC channel 5 data valid) 
  *          @arg VADC_FLAG_VADDR6_VALID (VADC channel 6 data valid) 
  *          @arg VADC_FLAG_VADDR7_VALID (VADC channel 7 data valid) 
  *          @arg VADC_FLAG_VADDR8_VALID (VADC channel 8 data valid) 
  *          @arg VADC_FLAG_VADDR9_VALID (VADC channel 9 data valid) 
  *          @arg VADC_FLAG_VADDR10_VALID(VADC channel 10 data valid)        
  * @param  status: Get the flag status,1:SET, 0:RESET.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_flag_status_get(uint16_t flag, uint8_t* status);

/**
  * @brief  Valid flag of VADC last pdm code value sampled by digital filter.
  * @param  flag: Specifies flag to check, it can be one of the following values:
  *          @arg VADC_FLAG_BUSY (VADC busy)          
  *          @arg VADC_FLAG_VADDN0_VALID (VADC channel 0 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN1_VALID (VADC channel 1 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN2_VALID (VADC channel 2 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN3_VALID (VADC channel 3 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN4_VALID (VADC channel 4 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN5_VALID (VADC channel 5 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN6_VALID (VADC channel 6 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN7_VALID (VADC channel 7 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN8_VALID (VADC channel 8 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN9_VALID (VADC channel 9 last pdm code value valid) 
  *          @arg VADC_FLAG_VADDN10_VALID(VADC channel 10 last pdm code value valid)        
  * @param  value: The last pdm code value ,1:valid, 0: invalid.
  * @note   The code value error compensation is not applicable to the limited period conversion mode.
  *         When VADC channel data is valid,then the last pdm code value is valid.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_last_pdm_code_valid_get(uint16_t flag, uint8_t* status);

/**
  * @brief  VADC original code value is converted to actual voltage value.
  * @param  original_code: this is vadc origianl code.
  * @param  down_sampling_rate: VADC down sampling rate.
  * @param  vadc_gain: vadc gain.
  * @param  vadc_verf: vadc reference voltage.
  * @note   None.
  * @return VADC actual voltage value. 
  */ 
float afe_vadc_conver_data(uint32_t original_code, uint16_t down_sampling_rate, float vadc_gain, float vadc_verf);


/**
  * @brief  VADC original code value is converted to actual voltage value.
  * @param  original_code: this is vadc origianl code.
  * @param  down_sampling_rate: VADC down sampling rate.
  * @param  vadc_gain: vadc gain, reciprocal of actual value.
  * @param  vadc_verf: vadc reference voltage,unit is mV.
  * @note   None.
  * @return VADC actual voltage value,unit is uV. 
  */ 
int32_t afe_vadc_conver_data_calc(uint32_t original_code, uint16_t down_sampling_rate, int32_t vadc_gain, int32_t vadc_verf);

/**
  * @brief	VADC PACK threshold configuration.
  * @param	signal_sel: PACK threshold selection signal, it can be one of the following values:
  *          @arg PACK_FIXED_2_6V (The threshold of PACK is fixed at 2.6V)
  *          @arg PACK_PACKTH_SEL (The threshold of PACK can be determined through packth_sel)
  * @param  packth_sel: PACK threshold configuration, it can be one of the following values:
  *          @arg PACK_TH_SEL_2_6V (PACK threshold voltage 2.6V)
  *          @arg PACK_TH_SEL_6V (PACK threshold voltage 6V)
  *          @arg PACK_TH_SEL_9V (PACK threshold voltage 9V)
  *          @arg PACK_TH_SEL_12V (PACK threshold voltage 12V)
  * @note	  None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_vadc_pack_threshold_config(uint16_t signal_sel, uint16_t packth_sel);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_vadc.h */


/**
  * @}
  */

/**
  * @}
  */
