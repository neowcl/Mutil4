/**
* @file        trng.h
* @brief       This file contains all the functions prototypes for the TRNG firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.06.06
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.06.06    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __TRNG_H__
#define __TRNG_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "crypto_reg.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup TRNG
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup TRNG_Exported_Types TRNG Exported Types
  * @{
  */

/**
  * @brief TRNG return code
*/
typedef enum 
{
    TRNG_SUCCESS = 0,             /*!< success */
    TRNG_BUFFER_NULL,             /*!< buffer is none */
    TRNG_INVALID_INPUT,           /*!< invalid input */
    TRNG_INVALID_CONFIG,          /*!< invalid config */
    TRNG_HT_ERROR,                /*!< health check error */
    TRNG_ERROR                    /*!< error */
}trng_ret_code;
/**
  * @}
  */


/** @defgroup TRNG_Exported_Constants TRNG Exported Constants
  * @{
  */

#define TRNG_ERROR_COUNTER_THRESHOLD             (100)

/**
  * @brief TRNG register address
*/
#define TRNG_CR             (*(volatile uint32_t *)(TRNG_BASE + 0x0000))                        /*!< Offset: 0x0000 (R/W) TRNG Control register */
#define TRNG_MSEL           (*(volatile uint32_t *)(TRNG_BASE + 0x0004))                        /*!< Offset: 0x0004 (R/W) TRNG Mode Select register */
#define TRNG_SR             (*(volatile uint32_t *)(TRNG_BASE + 0x0008))                        /*!< Offset: 0x0008 (W1C) TRNG Status Register */
#define TRNG_DR             (*(volatile uint32_t *)(TRNG_BASE + 0x000C))                        /*!< Offset: 0x000C (RO) TRNG Output register */
#define TRNG_VERSION        (*(volatile uint32_t *)(TRNG_BASE + 0x0010))                        /*!< Offset: 0x0010 (RO) TRNG Version register */
#define TRNG_RESEED         (*(volatile uint32_t *)(TRNG_BASE + 0x0040))                        /*!< Offset: 0x0040 (W1S) TRNG Reseed Operate register */
#define TRNG_HT_CR          (*(volatile uint32_t *)(TRNG_BASE + 0x0060))                        /*!< Offset: 0x0060 (R/W) TRNG Health Check Config register */
#define TRNG_HT_SR          (*(volatile uint32_t *)(TRNG_BASE + 0x0070))                        /*!< Offset: 0x0070 (RO) TRNG Health Check Status register */
#define RO_SRC_EN1          (*(volatile uint32_t *)(TRNG_BASE + 0x0080))                        /*!< Offset: 0x0080 (R/W) TRNG Entropy Enable register1 */
#define RO_SRC_EN2          (*(volatile uint32_t *)(TRNG_BASE + 0x0084))                        /*!< Offset: 0x0084 (R/W) TRNG Entropy Enable register2 */
#define SCLK_FREQ           (*(volatile uint32_t *)(TRNG_BASE + 0x0088))                        /*!< Offset: 0x0088 (R/W) TRNG Frequency register */

#define TERO_CR             (*(volatile uint32_t *)(TRNG_BASE + 0x00B0))                        /*!< Offset: 0x00B0 (R/W) TRNG Tero Config register */
#define TERO_THOLD          (*(volatile uint32_t *)(TRNG_BASE + 0x00B4))                        /*!< Offset: 0x00B4 (R/W) TRNG Tero Hold register */
#define TERO_CNT(i)         (*(volatile uint32_t *)(TRNG_BASE + 0x00C0 + 4*i))                  /*!< Offset: 0x00C0 (RO) TRNG Tero Counter register */
#define TERO_SR             (*(volatile uint32_t *)(TRNG_BASE + 0x00D0))                        /*!< Offset: 0x00D0 (RO) TRNG Tero Status register */
#define TERO_DR             (*(volatile uint32_t *)(TRNG_BASE + 0x00D4))                        /*!< Offset: 0x00D4 (RO) TRNG Tero Output register */
#define TERO_RCR(i)         (*(volatile uint32_t *)(TRNG_BASE + 0x00E0 + 4*i))                  /*!< Offset: 0x00E0 (RO) TRNG Tero Read Config register */

/**
  * @brief TRNG freq config
*/
#define TRNG_RO_FREQ_4                  (0)            /*!< Frequency div mode 0 */
#define TRNG_RO_FREQ_8                  (1)            /*!< Frequency div mode 1 */
#define TRNG_RO_FREQ_16                 (2)            /*!< Frequency div mode 2 */
#define TRNG_RO_FREQ_32                 (3)            /*!< default */

/**
  * @brief TRNG action offset
*/
#define TRNG_GLOBAL_INT_OFFSET          (24)           /*!< Offset: Global Interrupt Bit Offset in TRNG_CR */
#define TRNG_READ_EMPTY_INT_OFFSET      (17)           /*!< Offset: Read Empty Interrupt Bit Offset in TRNG_CR */
#define TRNG_DATA_INT_OFFSET            (16)           /*!< Offset: Data Interrupt Enable Bit Offset in TRNG_CR */
#define TRNG_RO_ENTROPY_OFFSET          (4)            /*!< Offset: Data Entropy Enable Bit Offset in TRNG_CR */
#define TRNG_TERO_THRESHOLD_OFFSET      (24)           /*!< Offset: TERO Hold Bit Offset in TERO_CR */
#define TRNG_TERO_ENTROPY_OFFSET        (8)            /*!< Offset: TERO Entropy Enable Bit Offset in TERO_CR */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup TRNG_Exported_Functions TRNG Exported Functions
  * @{
  */

/**
  * @brief  get trng IP version
  * @param  none
  * @return trng IP version
 */
uint32_t trng_get_version(void);

/**
  * @brief  TRNG global interruption enable
  * @param  none
  * @return none
 */
void trng_global_int_enable(void);

/**
  * @brief  TRNG global interruption disable
  * @param  none
  * @return none
 */
void trng_global_int_disable(void);

/**
  * @brief  TRNG emptyread interruption enable
  * @param  none
  * @return none
  * @note   Works when global interruption is enabled
 */
void trng_empty_read_int_enable(void);

/**
  * @brief  TRNG emptyread interruption disable
  * @param  none
  * @return none
 */
void trng_empty_read_int_disable(void);

/**
  * @brief  TRNG data interruption enable
  * @param  none
  * @return none
  * @note   Works when global interruption is enabled
 */
void trng_data_int_enable(void);

/**
  * @brief  TRNG data interruption disable
  * @param  none
  * @return none
 */
void trng_data_int_disable(void);

/**
  * @brief  TRNG enable
  * @param  none
  * @return none
 */
void trng_enable(void);

/**
  * @brief  TRNG disable
  * @param  none
  * @return none
 */
void trng_disable(void);

/**
  * @brief  set RO entropy config
  * @param  cfg: RO entropy config, only the low 4 bits are valid, every bit
  *              indicates one RO entropy, the MSB is RO 0, and LSB is RO 3
  * @note   1. only the low 4 bits of cfg are valid
  *         2. if the low 4 bits of cig is 0, that means to disable all RO entropy
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t trng_ro_entropy_config(uint8_t cfg);

/**
  * @brief  set sub RO entropy config
  * @param  sn: input, RO entropy source series number, must be in [0,3]
  * @param  value: input, the config value of RO sn
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t trng_ro_sub_entropy_config(uint8_t sn, uint16_t cfg);

/**
  * @brief  set TRNG mode
  * @param  with_post_processing: 0:no,  other:yes
  * @return none
 */
void trng_set_mode(uint8_t with_post_processing);

/**
  * @brief  reseed TRNG(works when DRBG is enabled)
  * @param  none
  * @return none
 */
void trng_reseed(void);

/**
  * @brief  TRNG set frequency
  * @param  freq: input, frequency config, must be in [0,3], and
  *                                0: 1/4 of input frequency,
  *                                1: 1/8 ...,
  *                                2: 1/16 ...,
  *                                3: 1/32 ...,
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t trng_set_freq(uint8_t freq);

/**
  * @brief  get rand(for internal test)
  * @param  rand: input, byte buffer rand
  * @param  bytes: input, byte length of rand
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t get_rand_internal(uint8_t *a, uint32_t bytes);
    
/**
  * @brief  get rand with fast speed(with entropy reducing, for such as clearing tmp buffer)
  * @param  rand: input, byte buffer rand
  * @param  bytes: input, byte length of rand
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t get_rand_fast(uint8_t *rand, uint32_t bytes);

/**
  * @brief  get rand(without entropy reducing)
  * @param  rand: input, byte buffer rand
  * @param  bytes: input, byte length of rand
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t get_rand(uint8_t *rand, uint32_t bytes);

/**
  * @brief  TERO RNG enable
  * @param  none
  * @return none
 */
void tero_enable(void);

/**
  * @brief  TERO RNG disable
  * @param  none
  * @return none
 */
void tero_disable(void);

/**
  * @brief  TERO RNG set the system cycle threshold of the TERO counter kept,
  * @param  threshold_value: input, threshold value
  * @return none
 */
uint32_t tero_set_stop_threshold(uint8_t threshold_value);

/**
  * @brief  set TERO entropy config
  * @param  cfg: RO entropy config, only the low 4 bits are valid, every bit
  *              indicates one RO entropy, the LSB is TERO 0, and MSB is RO 3
  * @note   1. only the low 4 bits of cfg are valid
  *         2. if the low 4 bits of cig is 0, that means to disable all TERO entropy
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t tero_entropy_config(uint8_t cfg);

/**
  * @brief  TERO RNG set output as rng
  * @param  none
  * @return none
 */
void tero_set_output_rng(void);

/**
  * @brief  TERO RNG set output as oscillation times
  * @param  none
  * @return none
 */
void tero_set_output_osc_times(void);

/**
  * @brief  select TREO 1&2 or TERO 3&4 when output is oscillation times
  * @param  cfg: input, 0:TREO 1&2, other:TREO 3&4
  * @return none
 */
void tero_set_osc_sel(uint8_t cfg);

/**
  * @brief  set lower limit of oscillation times
  * @param  value: input, lower limit value
  * @return none
 */
void tero_set_osc_times_lower_limit(uint16_t value);

/**
  * @brief  set upper limit of oscillation times
  * @param  value: input, upper limit value
  * @return none
 */
void tero_set_osc_times_upper_limit(uint16_t value);

/**
  * @brief  get tero rand
  * @param  a: input, byte buffer a
  * @param  bytes: input, byte length of rand
  * @return TRNG_SUCCESS(success), other(error)
 */
uint32_t get_tero_rand(uint8_t *a, uint32_t bytes);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* trng.h */


/**
  * @}
  */

/**
  * @}
  */
