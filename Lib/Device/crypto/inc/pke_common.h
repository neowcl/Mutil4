/**
* @file        pke_common.h
* @brief       This file contains all the functions prototypes for the PKE common firmware library. 
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


#ifndef __PKE_COMMON_H__
#define __PKE_COMMON_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include <stdint.h>

/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup PKE_COMMON
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup PKE_COMMON_Exported_Types PKE common Exported Types
  * @{
  */

/*!< define available PKE IP */
#define PKE_SECURE

/**
  * @}
  */


/** @defgroup PKE_COMMON_Exported_Constants PKE common Exported Constants
  * @{
  */

/*!< define secure version(hardware & software driver) */
#define PKE_SEC

#define POINT_NOT_COMPRESSED      (0x04)
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup PKE_COMMON_Exported_Functions PKE common Exported Functions
  * @{
  */

typedef void *(*KDF_FUNC)(const void *input, uint32_t byteLen, uint8_t *key, uint32_t keyByteLen);

/**
  * @brief  load input operand to baseaddr
  * @param  baseaddr: output, destination data
  * @param  data: input, source data
  * @param  wordLen: input, word length of data
  * @return none
 */
void pke_load_operand(uint32_t *baseaddr, uint32_t *data, uint32_t wordLen);

/**
  * @brief  get result operand from baseaddr
  * @param  baseaddr: input, source data
  * @param  data: output, destination data
  * @param  wordLen: input, word length of data
  * @return none
 */
void pke_read_operand(uint32_t *baseaddr, uint32_t *data, uint32_t wordLen);

/**
  * @brief  set operand with an uint32_t value
  * @param  a: output, operand a
  * @param  wordLen: input, word length of operand a, it can not be 0
  * @param  b: input, uint32_t value b
  * @return none
 */
void pke_set_operand_uint32_value(uint32_t *a, uint32_t aWordLen, uint32_t b);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* pke_common.h */


/**
  * @}
  */

/**
  * @}
  */
