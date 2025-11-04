/**
* @file        utility_sec.h
* @brief       This file contains all the functions prototypes for the utility sec firmware library. 
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


#ifndef __UTILITY_SEC_H__
#define __UTILITY_SEC_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include <stdint.h> 

#include "utility.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup UTILITY_SEC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup UTILITY_SEC_Exported_Types utility sec Exported Types
  * @{
  */

/**
  * @}
  */


/** @defgroup UTILITY_SEC_Exported_Constants utility sec Exported Constants
  * @{
  */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup UTILITY_SEC_Exported_Functions utility sec Exported Functions
  * @{
  */
/**
  * @brief  crc16 calculation, update crc value
  * @param  in: input, data for crc calculate
  * @param  bytelen: input, bytetlen of in
  * @param  crc : input, current crc value
  * @note   1. in should not be null
  * @return updated crc value
 */
uint16_t crc16_calc(uint8_t *in, uint32_t bytelen, uint16_t crc);

/**
  * @brief  get random big number a, a occupies aBitLen bits, and MSB of a is 0
  * @param  a: output, uint32_t big integer a
  * @param  aBitLen : input, the bit length that a occupies
  * @return 0(success), other(error)
 */
uint32_t uint32_get_rand_big_number_msb_0(uint32_t *a, uint32_t aBitLen);

/**
  * @brief  check whether big number or uint8_t buffer a is all zero or not
  * @param  a: input, byte buffer a
  * @param  aByteLen: input, byte length of a
  * @return 0(a is not zero),1(a is all zero)
 */
uint8_t uint8_bignum_check_zero_sec(uint8_t a[], uint32_t aByteLen);

/**
  * @brief  check whether big number or uint32_t buffer a is all zero or not
  * @param  a: input, big integer or word buffer a
  * @param  aWordLen: input, word length of a
  * @return 0(a is not zero), 1(a is all zero)
 */
uint32_t uint32_bignum_check_zero_sec(uint32_t a[], uint32_t aWordLen);

/**
  * @brief  compare big integer a and b
  * @param  a: input, big integer a
  * @param  aWordLen: input, word length of a
  * @param  b: input, big integer b
  * @param  bWordLen: input, word length of b
  * @return 0:a=b,   1:a>b,   1: a<b
 */
int32_t uint32_bignum_cmp_sec(uint32_t *a, uint32_t aWordLen, uint32_t *b, uint32_t bWordLen);

/**
  * @brief  securely compare big integer a and b
  * @param  a: input, big integer a
  * @param  b: input, big integer b
  * @param  wordLen: input, word length of a and b
  * @return 0(a=b), other(a!=b)
 */
uint32_t uint32_cmp_sec(uint32_t *a, uint32_t *b, uint32_t wordLen, uint8_t rand);

/**
  * @brief  check whether integer k is in [1, n1]. secure version
  * @param  k: input, big number k
  * @param  n: input, big number n
  * @param  wordLen: input, word length of k and n
  * @return ret_zero: k is zero
  *         ret_big: k is greater/bigger than or equal to n
  *         ret_success: k is in [1, n1]
 */
uint32_t uint32_integer_check_sec(uint32_t *k, uint32_t *n, uint32_t wordLen, uint32_t ret_zero, uint32_t ret_big,
		uint32_t ret_success);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* utility_sec.h */


/**
  * @}
  */

/**
  * @}
  */
