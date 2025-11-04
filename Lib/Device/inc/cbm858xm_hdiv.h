/**
* @file        cbm858xm_hdiv.h
* @brief       This file contains all the functions prototypes for the HDIV firmware library. 
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


#ifndef __CBM858xM_HDIV_H__
#define __CBM858xM_HDIV_H__


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

/** @addtogroup HDIV
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup HDIV_Exported_Types HDIV Exported Types
  * @{
  */

/** @enum  result_valid_t
  * @brief The result valid or invalid definition.
  */
typedef enum
{
    INVALID = 0x00,         /*!< Invalid. */
    VALID   = !INVALID      /*!< Valid. */
}result_valid_t;
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup HDIV_Exported_Functions HDIV Exported Functions
  * @{
  */

/**
  * @brief  Reads the quotient result.
  * @param  dividend: Pointer to the dividend.
  * @param  divisor: Specifies the divisor.
  * @param  quotient: Output parameters, pointer to the quotient result.
  * @param  remainder: Output parameters, pointer to the remainder.
  * @return The validity of the calculation result (INVALID or VALID).
  */
result_valid_t hdiv_quotient_read(int32_t* dividend, int32_t divisor, int32_t* quotient, int32_t* remainder);


/**
  * @brief  Reads the int32 quotient result.
  * @param  dividend: Specifies the dividend.
  * @param  divisor: Specifies the divisor.
  * @note   If the dividend not 0, but the quotient is 0, calculate is invalid.
  * @return The quotient.
  */
int32_t hdiv_quotient_int(int32_t dividend, int32_t divisor);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_hdiv.h */


/**
  * @}
  */

/**
  * @}
  */
