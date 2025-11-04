/**
* @file        cbm858x_afe_cc.h
* @brief       This file contains all the functions prototypes for the CC firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.11.02
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.11.02    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858x_AFE_CC_H__
#define __CBM858x_AFE_CC_H__


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

/** @addtogroup AFE_CC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_CC_Types AFE CC Types
  * @{
  */

/**
  * @brief The CC general configuration struct definition. 
  */
typedef struct
{
    uint16_t cc_fs_sel;         /*!< CC ADC sampling frequency FS selection */
    uint16_t cc_signal;         /*!< CC ADC input signal selection */     
    uint16_t cc_echop;          /*!< CC ADC ECHOP frequency selection */
    uint16_t cc_ichop;          /*!< CC ADC ICHOP frequency selection */
    uint16_t cc_vcmsel;         /*!< VCM voltage selection of CC ADC */
    uint16_t cc_buf_drvn;       /*!< CC ADC buffer driver is not enabled */
    uint16_t cc_ibt;            /*!< CC ADC OP_STG1 test bias current set */
    uint16_t cc_gtc;            /*!< CC ADC temperature compensation register set,
                                    basic temperature coefficient * correction multiple of temperature coefficient */
}cc_general_config_t;

/**
  * @brief The CC normal mode configuration struct definition. 
  */
typedef struct
{
    uint16_t cc_gain;           /*!< CC ADC gain selection */
    uint16_t cc_maxosr;         /*!< CC ADC normal mode down sampling rate frequency multiplication configuration */
    uint16_t cc_ccosr;          /*!< CC ADC downsampling rate configuration */
}cc_normal_mode_config_t;   

/**
  * @brief The CC TURBO mode configuration struct definition. 
  */
typedef struct
{
    uint16_t cc_turbo_gain;     /*!< CC ADC TURBO mode gain selection */
    uint16_t cc_turboosr;       /*!< CC ADC TURBO mode downsampling rate configuration */
}cc_turbo_mode_config_t;   

/**
  * @}
  */


/** @defgroup AFE_CC_Constants AFE_CC Constants
  * @{
  */

/* CC ADC sampling frequency selection */ 
#define CC_ADC_FS_512KHZ            0x0000          /*!< CC ADC sampling frequency selection 512KHz */
#define CC_ADC_FS_256KHZ            0x4000          /*!< CC ADC sampling frequency selection 256KHz */
#define CC_ADC_FS_128KHZ            0x8000          /*!< CC ADC sampling frequency selection 128KHz */
#define CC_ADC_FS_64KHZ             0xC000          /*!< CC ADC sampling frequency selection 64KHz */

/* CC ADC TURBO mode gain selection */
#define CC_ADC_TURBO_GAIN_10        0x0000          /*!< CC ADC TURBO mode gain selection 10 */    
#define CC_ADC_TURBO_GAIN_15        0x1000          /*!< CC ADC TURBO mode gain selection 15 */
#define CC_ADC_TURBO_GAIN_20        0x2000          /*!< CC ADC TURBO mode gain selection 20 */

/* CC ADC gain selection */
#define CC_ADC_GAIN_10              0x0000          /*!< CC ADC gain selection 10 */    
#define CC_ADC_GAIN_15              0x0400          /*!< CC ADC gain selection 15 */
#define CC_ADC_GAIN_20              0x0800          /*!< CC ADC gain selection 20 */

/* CC ADC input signal selection */
#define CC_ADC_SRP_SRN              0x0000          /*!< CC ADC input signal selection SRP-SRN */
#define CC_ADC_INSIDE_SHORT         0x0100          /*!< CC ADC input signal selection inside short */

/*!< CC ADC ECHOP frequency selection */
#define CC_ADC_ECHOP_1_4            0x0000          /*!< Modulator CHOP frequency is 1/4 of ICHOP frequency */
#define CC_ADC_ECHOP_1_8            0x0020          /*!< Modulator CHOP frequency is 1/8 of ICHOP frequency */
#define CC_ADC_ECHOP_1_16           0x0040          /*!< Modulator CHOP frequency is 1/16 of ICHOP frequency */
#define CC_ADC_ECHOP_1_32           0x0060          /*!< Modulator CHOP frequency is 1/32 of ICHOP frequency */

/* CC ADC ICHOP frequency selection */
#define CC_ADC_ICHOP_1_16           0x0000          /*!< Integrator OP CHOP frequency is 1/16 of FS frequency */
#define CC_ADC_ICHOP_1_64           0x0008          /*!< Integrator OP CHOP frequency is 1/64 of FS frequency */
#define CC_ADC_ICHOP_1_128          0x0010          /*!< Integrator OP CHOP frequency is 1/128 of FS frequency */
#define CC_ADC_ICHOP_1_256          0x0018          /*!< Integrator OP CHOP frequency is 1/256 of FS frequency */

/* VCM voltage selection of CC ADC */
#define CC_ADC_VCM_1_2              0x0000          /*!< The VCM voltage of CC ADC is (1/2)*VLDO1P8V */
#define CC_ADC_VCM_3_8              0x0001          /*!< The VCM voltage of CC ADC is (3/8)*VLDO1P8V */

/* CC ADC buffer driver is not enabled */
#define CC_ADC_BUFF_DISABLE         0x0000          /*!< CC ADC do not add 6uA Buffer driver */ 
#define CC_ADC_BUFF_ENABLE          0x0100          /*!< CC ADC add 6uA Buffer driver */

/* CC ADC OP_STG1 test bias current set */
#define CC_IBT_NORMAL               0x0000          /*!< Normal operating current without increasing bias current */
#define CC_IBT_ADD_200NA            0x0040          /*!< CC ADC bias current increased by 200nA */
#define CC_IBT_ADD_400NA            0x0080          /*!< CC ADC bias current increased by 400nA */
#define CC_IBT_ADD_600NA            0x00C0          /*!< CC ADC bias current increased by 600nA */

/* CC ADC temperature compensation register set */
/* basic temperature coefficient */
#define CC_ADC_GTC_N15PPM           0x0007          /*!< CC ADC foundation temperature coefficient of -15 ppm */   
#define CC_ADC_GTC_N10PPM           0x0006          /*!< CC ADC foundation temperature coefficient of -10 ppm */
#define CC_ADC_GTC_N5PPM            0x0005          /*!< CC ADC foundation temperature coefficient of -5 ppm */
#define CC_ADC_GTC_0PPM             0x0000          /*!< CC ADC foundation temperature coefficient of 0 ppm */
#define CC_ADC_GTC_P5PPM            0x0001          /*!< CC ADC foundation temperature coefficient of 5 ppm */
#define CC_ADC_GTC_P10PPM           0x0002          /*!< CC ADC foundation temperature coefficient of 10 ppm */
#define CC_ADC_GTC_P15PPM           0x0003          /*!< CC ADC foundation temperature coefficient of 15 ppm */
/* Temperature coefficient correction multiple */
#define CC_ADC_GTC_0MUL             0x0000          /*!< Temperature coefficient correction 0 times */ 
#define CC_ADC_GTC_1MUL             0x0008          /*!< Temperature coefficient correction 1 times */
#define CC_ADC_GTC_2MUL             0x0010          /*!< Temperature coefficient correction 2 times */
#define CC_ADC_GTC_3MUL             0x0018          /*!< Temperature coefficient correction 3 times */
#define CC_ADC_GTC_4MUL             0x0020          /*!< Temperature coefficient correction 4 times */
#define CC_ADC_GTC_5MUL             0x0028          /*!< Temperature coefficient correction 5 times */
#define CC_ADC_GTC_6MUL             0x0030          /*!< Temperature coefficient correction 6 times */
#define CC_ADC_GTC_7MUL             0x0038          /*!< Temperature coefficient correction 7 times */

/* CC ADC normal mode down sampling rate frequency multiplication configuration */
#define CC_ADC_CCOSR_1              0x0000          /*!< CC ADC normal mode down sampling rate frequency 1 */
#define CC_ADC_CCOSR_2              0x0001          /*!< CC ADC normal mode down sampling rate frequency 2 */
#define CC_ADC_CCOSR_4              0x0002          /*!< CC ADC normal mode down sampling rate frequency 4 */
#define CC_ADC_CCOSR_8              0x0003          /*!< CC ADC normal mode down sampling rate frequency 8 */

/* CC ADC status flag*/
#define CC_ADC_DATA_VALID           0x8000          /*!< CC ADC data valid, first and second stage integrator data valid */
#define SAR_ADC_BENGIN_VALID        0x0200          /*!< Data valid flag at the beginning of SAR ADC acquisition */
#define SAR_ADC_END_VALID           0x0100          /*!< Data valid flag at the end of SAR ADC acquisition */
#define CC_ADC_BUSY                 0x0002          /*!< CC ADC busy */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_CC_Functions AFE_CC Functions
  * @{
  */

/**
  * @brief  Initialization CC ADC general configuration.
  * @param  ptr_config: Pointer to a cc_config_t structure that contains the general 
  *                     configuration information for the specified CC VADC peripheral.
  *         The structure members are configured as follows:
  * @param  cc_fs_sel (CC ADC sampling frequency FS selection), it can be one of the following values:
  *          @arg CC_ADC_FS_512KHZ(CC ADC sampling frequency selection 512KHz, the default configuration)
  *          @arg CC_ADC_FS_256KHZ(CC ADC sampling frequency selection 256KHz)
  *          @arg CC_ADC_FS_128KHZ(CC ADC sampling frequency selection 128KHz) 
  *          @arg CC_ADC_FS_64KHZ(CC ADC sampling frequency selection 64KHz) 
  * @param  cc_signal (CC ADC input signal selection), it can be one of the following values:
  *          @arg CC_ADC_SRP_SRN(CC ADC input signal selection SRP-SRN, the default configuration)
  *          @arg CC_ADC_INSIDE_SHORT(CC ADC input signal selection inside short)
  * @param  cc_echop (CC ADC ECHOP frequency selection), it can be one of the following values:
  *          @arg CC_ADC_ECHOP_1_4(Modulator CHOP frequency is 1/4 of ICHOP frequency) 
  *          @arg CC_ADC_ECHOP_1_8(Modulator CHOP frequency is 1/8 of ICHOP frequency, the default configuration) 
  *          @arg CC_ADC_ECHOP_1_16(Modulator CHOP frequency is 1/16 of ICHOP frequency) 
  *          @arg CC_ADC_ECHOP_1_32(Modulator CHOP frequency is 1/32 of ICHOP frequency)
  * @param  cc_ichop (CC ADC ICHOP frequency selection), it can be one of the following values:
  *          @arg CC_ADC_ICHOP_1_16(Integrator OP CHOP frequency is 1/16 of FS frequency) 
  *          @arg CC_ADC_ICHOP_1_64(Integrator OP CHOP frequency is 1/64 of FS frequency) 
  *          @arg CC_ADC_ICHOP_1_128(Integrator OP CHOP frequency is 1/128 of FS frequency) 
  *          @arg CC_ADC_ICHOP_1_256(Integrator OP CHOP frequency is 1/256 of FS frequency, the default configuration) 
  * @param  cc_vcmsel (VCM voltage selection of CC ADC), it can be one of the following values:
  *          @arg CC_ADC_VCM_1_2(The VCM voltage of CC ADC is (1/2)*VLDO1P8V, the default configuration)
  *          @arg CC_ADC_VCM_3_8(The VCM voltage of CC ADC is (3/8)*VLDO1P8V) 
  * @param  cc_buf_drvn (CC ADC buffer driver is not enabled), it can be one of the following values:
  *          @arg CC_ADC_BUFF_DISABLE(CC ADC do not add 6uA Buffer driver, the default configuration)
  *          @arg CC_ADC_BUFF_ENABLE(CC ADC add 6uA Buffer driver) 
  * @param  cc_ibt (CC ADC OP_STG1 test bias current set), it can be one of the following values:
  *          @arg CC_IBT_NORMAL(Normal operating current without increasing bias current) 
  *          @arg CC_IBT_ADD_200NA(CC ADC bias current increased by 200nA, the default configuration)       
  *          @arg CC_IBT_ADD_400NA(CC ADC bias current increased by 400nA)  
  *          @arg CC_IBT_ADD_600NA(CC ADC bias current increased by 600nA)
  * @param  cc_gtc (CC ADC temperature compensation register set, basic temperature coefficient * correction multiple of temperature coefficient). 
  *         The basic temperature coefficient can be one of the following values:
  *          @arg CC_ADC_GTC_N15PPM(CC ADC foundation temperature coefficient of -15 ppm, the default configuration)     
  *          @arg CC_ADC_GTC_N10PPM(CC ADC foundation temperature coefficient of -10 ppm)     
  *          @arg CC_ADC_GTC_N5PPM(CC ADC foundation temperature coefficient of -5 ppm)      
  *          @arg CC_ADC_GTC_0PPM (CC ADC foundation temperature coefficient of 0 ppm)      
  *          @arg CC_ADC_GTC_P5PPM(CC ADC foundation temperature coefficient of 5 ppm)      
  *          @arg CC_ADC_GTC_P10PPM(CC ADC foundation temperature coefficient of 10 ppm)     
  *          @arg CC_ADC_GTC_P15PPM(CC ADC foundation temperature coefficient of 15 ppm)  
  *         The correction multiple of temperature coefficient can be one of the following values:   
  *          @arg CC_ADC_GTC_0MUL(Temperature coefficient correction 0 times, the default configuration)
  *          @arg CC_ADC_GTC_1MUL(Temperature coefficient correction 1 times)
  *          @arg CC_ADC_GTC_2MUL(Temperature coefficient correction 2 times)
  *          @arg CC_ADC_GTC_3MUL(Temperature coefficient correction 3 times)
  *          @arg CC_ADC_GTC_4MUL(Temperature coefficient correction 4 times)
  *          @arg CC_ADC_GTC_5MUL(Temperature coefficient correction 5 times)
  *          @arg CC_ADC_GTC_6MUL(Temperature coefficient correction 6 times)
  *          @arg CC_ADC_GTC_7MUL(Temperature coefficient correction 7 times)
*/
uint8_t afe_cc_general_init(cc_general_config_t* ptr_config);

/**
  * @brief  Enables or disables the CC chop.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_chop_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables CC ADC internal integrator OPchop. 
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_ichop_enable_ctrl(uint8_t enable_flag);
/**
  * @brief  Initialization CC ADC normal configuration.
  * @param  ptr_config: Pointer to a cc_config_t structure that contains the normal 
  *                     configuration information for the specified CC VADC peripheral.
  * @param  cc_gain (CC ADC gain selection), it can be one of the following values:
  *          @arg CC_ADC_GAIN_10(CC ADC gain selection 10, the default configuration)
  *          @arg CC_ADC_GAIN_15(CC ADC gain selection 15) 
  *          @arg CC_ADC_GAIN_20(CC ADC gain selection 20)
  * @param  cc_maxosr (CC ADC normal mode down sampling rate frequency), it can be one of the following values:
  *          @arg CC_ADC_CCOSR_1(CC ADC normal mode down sampling rate frequency 1)
  *          @arg CC_ADC_CCOSR_2(CC ADC normal mode down sampling rate frequency 2)
  *          @arg CC_ADC_CCOSR_4(CC ADC normal mode down sampling rate frequency 4)  
  *          @arg CC_ADC_CCOSR_8(CC ADC normal mode down sampling rate frequency 8)
  *         cc_ccosr(CC ADC downsampling rate configuration),it can be configure as 1024~65535, the default value is 65535,
  *          when the value less than 1024, hardware will auto configuration is 1024.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_normal_mode_init(cc_normal_mode_config_t* ptr_config);

/**
  * @brief  Enables or disables CC ADC. 
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables SAR ADC begin acquisition signal.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_sarbegin_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables SAR ADC end acquisition signal.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_sarend_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Initialization CC ADC TURBO mode configuration.
  * @param  ptr_config: Pointer to a cc_turbo_mode_config_t structure that contains the TURBO mode.
  * @param  cc_turbo_gain (CC ADC TURBO mode gain selection), it can be one of the following values:
  *          @arg CC_ADC_TURBO_GAIN_10(CC ADC TURBO mode gain selection 10, the default configuration)
  *          @arg CC_ADC_TURBO_GAIN_15(CC ADC TURBO mode gain selection 15)
  *          @arg CC_ADC_TURBO_GAIN_20(CC ADC TURBO mode gain selection 20)
  * @param  cc_turboosr (CC ADC TURBO mode downsampling rate configuration), it can be configure as 512~32767, the default value is 32767,
  *          when the value less than 1024, hardware will auto configuration is 512.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_turbo_mode_init(cc_turbo_mode_config_t* ptr_config);

/**
  * @brief  Enables or disables CC ADC TURBO mode.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_turbo_mode_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  Enables or disables timer interrupt triggers CC ADC.
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_timer_trig_enable_ctrl(uint8_t enable_flag);

/**
  * @brief  CC ADC first stage integrator data get.
  * @param  cc_value: CC ADC first stage integrator data.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_first_integ_data_get(uint32_t* cc_value);

/**
  * @brief  CC ADC second stage integrator data get.
  * @param  cc_value: CC ADC data.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_second_integ_data_get(uint32_t* cc_value);

/**
  * @brief  SAR ADC data collected at the end get.
  * @param  cc_value: SAR ADC data collected at the end, only 4bits code.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_sar_end_data_get(uint16_t* cc_value);

/**
  * @brief  CC ADC PDM code collected at the end on the normal or TURBO mode.
  * @param  cc_value: CC ADC PDM code collected at the end, only 1bit code.
  * @note   None
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
  */
uint8_t afe_cc_end_pdmcode_get(uint16_t* cc_value);

/**
  * @brief  Checks whether the specified CC flag is set or not.
  * @param  flag: Specifies flag to check, it can be one of the following values:
  *          @arg CC_ADC_DATA_VALID(CC ADC data valid, first and second stage integrator data valid)
  *          @arg SAR_ADC_BENGIN_VALID(Data valid flag at the beginning of SAR ADC acquisition)
  *          @arg SAR_ADC_END_VALID(Data valid flag at the end of SAR ADC acquisition)
  *          @arg CC_ADC_BUSY(CC ADC busy)   
  * @param  status: Get the flag status,1:SET, 0:RESET.
  * @note   None.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_cc_flag_status_get(uint16_t flag, uint8_t* status);

/**
  * @brief  CC ADC fisrt order conver data get.
  * @param  cc_gain: cc gian.
  * @param  verf: CC SADC voltage reference.
  * @param  actual_cc: CC ADC fisrt order actual value.
  * @note   This function can be executed after generating CCADC completion flag.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_cc_first_order_conver_data(float cc_gain, float verf, float* actual_cc);

/**
  * @brief  Get the CCADC fisrt order conver value.
  * @param  cc_gain: cc gian.
  * @param  verf: CC SADC voltage reference,the unit is mV.
  * @note   This function can be executed after generating CCADC completion flag.
  * @return Fisrt order conver value,the unit is uA.
*/
int32_t afe_cc_first_order_conver_data_calc(int32_t cc_gain, int32_t verf);
/**
  * @}
  */

/**
  * @brief  CC ADC turbo mode conver data get.
  * @param  cc_gain: cc gian.
  * @param  verf: CC SADC voltage reference.
  * @param  actual_cc: CC ADC turbo mode actual value.
  * @note   This function can be executed after generating CCADC turbo mode completion flag.
  * @return Function execution result, 0:ERROR, 1:SUCCESS.
*/
uint8_t afe_cc_turbo_conver_data(float cc_gain, float verf, float* actual_cc);

/**
  * @brief  Get the CCADC turbo mode conver value.
  * @param  cc_gain: cc gian.
  * @param  verf: CC SADC voltage reference,the unit is mV.
  * @note   This function can be executed after generating CCADC turbo mode completion flag.
  * @return Fisrt order conver value,the unit is uA.
*/
int32_t afe_cc_turbo_conver_data_calc(int32_t cc_gain, int32_t verf);
#ifdef __cplusplus
}
#endif

#endif /* cs.h */


/**
  * @}
  */

/**
  * @}
  */
