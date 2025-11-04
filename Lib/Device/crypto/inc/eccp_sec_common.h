/**
* @file        eccp_sec_common.h
* @brief       This file contains all the functions prototypes for the ECCP firmware library. 
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


#ifndef __ECCP_SEC_COMMON_H__
#define __ECCP_SEC_COMMON_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "eccp_curve.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup ECCP
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup ECCP_Exported_Types ECCP Exported Types
  * @{
  */

/**
  * @}
  */


/** @defgroup ECCP_Exported_Constants ECCP Exported Constants
  * @{
  */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup ECCP_Exported_Functions ECCP Exported Functions
  * @{
  */

/**
  * @brief  check whether eccp curve defined internal
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @return 1(yes), 0(no).
  */
uint32_t is_eccp_curve_defined_internal(const eccp_curve_t *curve);

/**
  * @brief  calculate eccp curve crc16
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @return crc value.
  */
uint16_t calc_eccp_curve_crc16(const eccp_curve_t *curve);

/**
  * @brief  calculate eccp curve crc16
  * @param  curve: input eccp_curve struct pointer, curve should not be null.
  * @param  curve_crc16: input expected crc16.
  * @return 0(success), 1(error).
  */
uint32_t ecc_crc16_check(const eccp_curve_t *curve, uint16_t curve_crc16);

/**
  * @brief  init internal sec eccp curve struct g_secp_curve
  * @param  curve: input eccp_curve struct pointer, curve should not be null.
  * @return g_secp_curve pointer(success), NULL(error).
  */
eccp_curve_t * eccp_curve_init(const eccp_curve_t *curve);

/**
  * @brief  uninit eccp curve struct
  * @param  none.
  * @return none.
  */
void eccp_curve_uninit(void);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* eccp_sec_common.h */


/**
  * @}
  */

/**
  * @}
  */
