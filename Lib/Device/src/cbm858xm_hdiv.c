/**
* @file        cbm858xm_hdiv.c
* @brief       This file provides all the basic HDIV firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.16
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.16    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_hdiv.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/
#define HDIV_DIVSTS_INVALID     ((uint32_t)0x00000006)      /*!< HDIV DIVSTS register bit mask definition. */


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup HDIV HDIV
  * @brief    HDIV driver modules
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
  * @brief  Reads the quotient result.
  * @param  dividend: Pointer to the dividend.
  * @param  divisor: Specifies the divisor.
  * @param  quotient: Output parameters, pointer to the quotient result.
  * @param  remainder: Output parameters, pointer to the remainder.
  * @return The validity of the calculation result (INVALID or VALID).
  */
result_valid_t hdiv_quotient_read(int32_t* dividend, int32_t divisor, int32_t* quotient, int32_t* remainder)
{
    uint32_t status;

    HDIV->DIVIDEND0 = (uint32_t)dividend[1];
    HDIV->DIVIDEND1 = (uint32_t)dividend[0];
    HDIV->DIVISOR   = (uint32_t)divisor;

    *quotient   = (int32_t)HDIV->DIVQUO0;
    *++quotient = (int32_t)HDIV->DIVQUO1;
    *remainder  = (int32_t)HDIV->DIVREM;
    status = HDIV->DIVSTS;

    if(status & HDIV_DIVSTS_INVALID)
    {
        return INVALID;
    }
    return VALID;
}


/**
  * @brief  Reads the int32 quotient result.
  * @param  dividend: Specifies the dividend.
  * @param  divisor: Specifies the divisor.
  * @note   If the dividend not 0, but the quotient is 0, calculate is invalid.
  * @return The quotient.
  */
int32_t hdiv_quotient_int(int32_t dividend, int32_t divisor)
{
    uint32_t status = 0;
    int32_t quotient = 0;
    
    HDIV->DIVIDEND0 = (uint32_t)dividend;
    if(((dividend>>31) && 0x00000001) == 1)
    {
        HDIV->DIVIDEND1 = 0xFFFFFFFF;
    }
    else
    {
        HDIV->DIVIDEND1 = 0;
    }
    HDIV->DIVISOR = (uint32_t)divisor;
    __NOP();
    __NOP();
    __NOP();
    quotient = (int32_t)HDIV->DIVQUO0;
    status = HDIV->DIVSTS;
    
    if(status & HDIV_DIVSTS_INVALID)
    {
        return 0;
    }
    return quotient;
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */
