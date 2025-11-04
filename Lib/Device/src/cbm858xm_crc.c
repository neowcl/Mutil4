/**
* @file        cbm858xm_crc.c
* @brief       This file provides all the basic CRC firmware functions.
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


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_crc.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup CRC CRC
  * @brief    CRC driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/**
  * @brief  Deinitializes CRC peripheral registers to their default reset values.
  * @param  None.
  * @return None.
  */
void crc_def_init(void)
{
    /* Set DATA register to reset value */
    CRC->DATA = 0xFFFFFFFF;

    /* Reset FREDATA register */
    CRC->FREDATA = 0x00000000;

    /* Set INITCFG register to reset value */
    CRC->INITCFG = 0xFFFFFFFF;

    /* Reset the CRC calculation unit */
    CRC->CTR = 0x00000000;

    /* Reset the CRC initial value unit */
    CRC->CTR = CRC_CTR_RST;
}


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
void crc_input_data_reverse(uint32_t value)
{
    ASSERT(CRC_REVERSE_INPUT_DATA_CHECK(value));

    /* Set the reverse operation. */
    MODIFY_REG(CRC->CTR, CRC_CTR_DINREVMOD, value);
}


/**
  * @brief  Computes the 32-bit CRC of a given data word(32-bit).
  * @param  value: Data word(32-bit) to compute its CRC.
  * @return 32-bit CRC.
  */
uint32_t crc_crc32_calc(uint32_t value)
{
    CRC->DATA = value;

    return (CRC->DATA);
}


/**
  * @brief  Computes the 16-bit CRC of a given 16-bit data.
  * @param  value: Data half-word(16-bit) to compute its CRC.
  * @return 16-bit CRC.
  */
uint32_t crc_crc16_calc(uint16_t value)
{
    *(__IO uint16_t *)(CRC_BASE) = value;

    return (CRC->DATA);
}


/**
  * @brief  Computes the 8-bit CRC of a given 8-bit data.
  * @param  value: 8-bit data to compute its CRC.
  * @return 8-bit CRC.
  */
uint32_t crc_crc8_calc(uint8_t value)
{
    *(__IO uint8_t *)(CRC_BASE) = value;

    return (CRC->DATA);
}


/**
  * @brief  Computes the 32-bit CRC of a given buffer of data word(32-bit).
  * @param  buf: Pointer to the buffer containing the data to be computed.
  * @param  length: Length of the buffer to be computed.
  * @return 32-bit CRC.
  */
uint32_t crc_data_buffer_calc(uint32_t buf[], uint32_t length)
{
    uint32_t index = 0;

    for(index = 0; index < length; index++)
    {
        CRC->DATA = buf[index];
    }

    return (CRC->DATA);
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */
