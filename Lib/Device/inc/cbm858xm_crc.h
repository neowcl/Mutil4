/**
* @file        cbm858xm_crc.h
* @brief       This file contains all the functions prototypes for the CRC firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.12
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.12    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_CRC_H__
#define __CBM858xM_CRC_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup CRC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/

/** @defgroup CRC_Exported_Constants CRC Exported Constants
  * @{
  */

/** @defgroup CRC_reverse_input_data CRC reverse input data
  * @{
  */

#define CRC_REVERSE_INPUT_DATA_NO               ((uint32_t)0x00000000)      /*!< No reverse operation of input data. */
#define CRC_REVERSE_INPUT_DATA_8BITS            (CRC_CTR_DINREVMOD_0)       /*!< Reverse input data on 8 bits. */
#define CRC_REVERSE_INPUT_DATA_16BITS           (CRC_CTR_DINREVMOD_1)       /*!< Reverse input data on 16 bits. */
#define CRC_REVERSE_INPUT_DATA_32BITS           (CRC_CTR_DINREVMOD)         /*!< Reverse input data on 32 bits. */
/**
  * @}
  */

/*! Checks CRC reverse input data. */
#define CRC_REVERSE_INPUT_DATA_CHECK(value)     (((value) == CRC_REVERSE_INPUT_DATA_NO)    || \
                                                ((value) == CRC_REVERSE_INPUT_DATA_8BITS)  || \
                                                ((value) == CRC_REVERSE_INPUT_DATA_16BITS) || \
                                                ((value) == CRC_REVERSE_INPUT_DATA_32BITS))
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup CRC_Exported_Functions CRC Exported Functions
  * @{
  */

/**
  * @brief  Deinitializes CRC peripheral registers to their default reset values.
  * @param  None.
  * @return None.
  */
#define __CRC_DEF_INIT()                    	crc_def_init()

/**
  * @brief  Returns the current CRC value.
  * @param  None.
  * @return 32-bit CRC.
  */
#define __CRC_VALUE_GET()                   	(CRC->DATA)

/**
  * @brief  Set an 8-bit data in Free Data register (FREDATA).
  * @param  VALUE: Set 8-bit value in the FREDATA register.
  * @return None.
  */
#define __CRC_FREDATA_REG_SET(VALUE)        	(CRC->FREDATA = (uint8_t)(VALUE))

/**
  * @brief  Get the 8-bit data stored in Free Data register (FREDATA).
  * @param  None.
  * @return 8-bit value of the FREDATA register.
  */
#define __CRC_FREDATA_REG_GET()             	((uint8_t)CRC->FREDATA)

/**
  * @brief  Resets the CRC calculation unit and sets INITCFG register content to DATA register.
  * @param  None.
  * @return None.
  */
#define __CRC_RESET()                       	(CRC->CTR |= CRC_CTR_RST)

/**
  * @brief  Enables the reverse operation on output data.
  * @param  None.
  * @note   The reverse operation on output data is performed on 32-bit.
  * @return None.
  */
#define __CRC_OUTPUT_DATA_REVERSE_ENABLE()  	(CRC->CTR |= CRC_CTR_DOREVEN)

/**
  * @brief  Disables the reverse operation on output data.
  * @note   The reverse operation on output data is performed on 32-bit.
  * @param  None.
  * @return None.
  */
#define __CRC_OUTPUT_DATA_REVERSE_DISABLE() 	(CRC->CTR &= ~(CRC_CTR_DOREVEN))

/**
  * @brief  Set the initial value of crc calculation to INITCFG register.
  * @note   The initial value will be loaded to DATA register, after resetting CRC calculation unit.
  * @param  VALUE: Programmable initial CRC value.
  * @return None.
  */
#define __CRC_INIT_VALUE_SET(VALUE)         	(CRC->INITCFG = (VALUE))

/**
  * @brief  Returns the CRC polynomial.
  * @param  None.
  * @return 32-bit polynomial.
  */
#define __CRC_POLYNOMIAL_GET()              	(CRC->POL)

/**
  * @brief  Deinitializes CRC peripheral registers to their default reset values.
  * @param  None.
  * @return None.
  */
void crc_def_init(void);

/**
  * @brief  Selects the reverse operation to be performed on input data.
  * @param  value: Specifies the reverse operation on input data.
  *         It can be one of the following values:
  *          @arg CRC_REVERSE_INPUT_DATA_NO: No reverse operation is performed.
  *          @arg CRC_REVERSE_INPUT_DATA_8BITS: Reverse operation performed on 8 bits.
  *          @arg CRC_REVERSE_INPUT_DATA_16BITS: Reverse operation performed on 16 bits.
  *          @arg CRC_REVERSE_INPUT_DATA_32BITS: Reverse operation performed on 32 bits.
  * @return None.
  */
void crc_input_data_reverse(uint32_t value);

/**
  * @brief  Computes the 32-bit CRC of a given data word(32-bit).
  * @param  value: Data word(32-bit) to compute its CRC.
  * @return 32-bit CRC.
  */
uint32_t crc_crc32_calc(uint32_t value);

/**
  * @brief  Computes the 16-bit CRC of a given 16-bit data.
  * @param  value: Data half-word(16-bit) to compute its CRC.
  * @return 16-bit CRC.
  */
uint32_t crc_crc16_calc(uint16_t value);

/**
  * @brief  Computes the 8-bit CRC of a given 8-bit data.
  * @param  value: 8-bit data to compute its CRC.
  * @return 8-bit CRC.
  */
uint32_t crc_crc8_calc(uint8_t value);

/**
  * @brief  Computes the 32-bit CRC of a given buffer of data word(32-bit).
  * @param  buf: Pointer to the buffer containing the data to be computed.
  * @param  length: Length of the buffer to be computed.
  * @return 32-bit CRC.
  */
uint32_t crc_data_buffer_calc(uint32_t buf[], uint32_t length);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_crc.h */


/**
  * @}
  */

/**
  * @}
  */
