/**
* @file        cbm858x_afe_transimit.h
* @brief       This file contains all the functions prototypes for the AFE transimit firmware library. 
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


#ifndef __CBM858x_AFE_TRANSIMIT_H__
#define __CBM858x_AFE_TRANSIMIT_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include <stdint.h>   
   
/** @addtogroup AFE_StdPeriph_Driver
  * @{
  */

/** @addtogroup AFE_TRANSIMIT
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup AFE_TRANSIMIT_Types AFE_TRANSIMIT Types
  * @{
  */

//Fill the content
/**
  * @}
  */


/** @defgroup AFE_TRANSIMIT_Constants AFE_TRANSIMIT Constants
  * @{
  */


#define AFE_FUN_EXECUTE_RESULT_CHECK(ret)                               \
                                            do{                         \
                                                    if(ret == 0)        \
                                                    {                   \
                                                        return ret;     \
                                                    }                   \
                                            }while(0)

#define     TRANS_MODE_SPI_I2C              1       /*!< 1: use SPI transimition; 0: use I2C transimition */

#define     TRANS_CHECK_LEVEL               0       /*!< 0:  no check; 1: checksum check; 2: CRC8 check*/

#define     NO_VERIFY_WRITE_SINGLE          0x05    /*!< Single write without verification */
#define     NO_VERIFY_READ_SINGLE           0x03    /*!< Single read without verification */

#define     TRANSIMIT_TIMEOUT_MAX           20000   /*!< Transimition maximum timeout count value */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup AFE_TRANSIMIT_Functions AFE_TRANSIMIT Functions
  * @{
  */

/**
  * @brief  Write data to afe chip. 
  * @param  reg_addr: The afe register address.
  * @param  data: Configure the register data.
  * @note   None.
  * @return None.
  */
uint8_t afe_write_data(uint16_t reg_addr, uint16_t data);

/**
  * @brief  Read data from afe chip. 
  * @param  reg_addr: The afe register address.
  * @param  data: Read the register data.
  * @note   None.
  * @return None.
  */
uint8_t afe_read_data( uint16_t reg_addr,uint16_t* data);

/**
 * @brief  Configures the SPI Peripheral.
 * @param  None
 * @return None
 */
void spi1_master_config(void);


/**
  * @brief  CRC8 check function.
  * @param  data: CRC8 calculate data.
  * @param  len: CRC8 data len.
  * @note   None.
  * @return CRC8 value.
  */
uint8_t boot_crc8_check(unsigned char *data,unsigned char len);

/**
  * @brief  Enter shuntdown mode
  * @param  None.
  * @note   If PACK voltage is greater than 2.25V, unable to enter shutdown.
  * @return Function execution result, 0:ERROR, 1:SUCCESS, 2: PACK voltage is greater than 2.25V.
  */
uint8_t afe_enter_shutdown(void);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858x_afe_transimit.h */


/**
  * @}
  */

/**
  * @}
  */
