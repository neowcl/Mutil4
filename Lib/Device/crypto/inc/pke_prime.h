/**
* @file        pke_prime.h
* @brief       This file contains all the functions prototypes for the PKE PRIME firmware library. 
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


#ifndef __PKE_PRIME_H__
#define __PKE_PRIME_H__


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

/** @addtogroup PKE_PRIME
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup PKE_PRIME_Exported_Types PKE PRIME Exported Types
  * @{
  */

//1:use hardware;  2:use software
#define BIGINT_DIV_CHOICE     (2)

#if (BIGINT_DIV_CHOICE == 1)
typedef struct {
	uint32_t low;
	uint32_t high;
}double_uint32_t;
#elif (BIGINT_DIV_CHOICE == 2)
typedef uint32_t double_uint32_t;
//#define BIGINT_DIV_UINT32
#endif

/**
  * @}
  */


/** @defgroup PKE_PRIME_Exported_Constants PKE PRIME Exported Constants
  * @{
  */

/*!< 1:use Fermat primality test;  2:use Miller�CRabin primality test */
#define PRIMALITY_TEST_CHOICE (1)

#if (PRIMALITY_TEST_CHOICE == 1)
#define FERMAT_ROUND          (3)
#elif (PRIMALITY_TEST_CHOICE == 2)
#define MILLER_RABIN_ROUND    (3)
#endif

/**
  * @brief prime table level(total number of small prime numbers)
*/
#define PTL_MAX               (400)   /*!< the max PTL value */
#define PTL_512               (400)   /*!< the best PTL value for prime bit length 512 (RSA1024) */
#define PTL_1024              (400)   /*!< the best PTL value for prime bit length 1024 (RSA2048) */

#define NOT_PRIME             (0xFFFFFFFF)
#define MAYBE_PRIME           (0)

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup PKE_PRIME_Exported_Functions PKE PRIME Exported Functions
  * @{
  */

/**
  * @brief  get prime number of pBitLen
  * @param  p: pointer to uint32_t big prime number
  * @param  pBitLen: bit length of p
  * @return 0: success, p is prime number with high probability, other: error
  * @note   pBitLen must be bigger than 32, but less than 2048
 */
uint32_t get_prime(uint32_t p[], uint32_t pBitLen);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* pke_prime.h */


/**
  * @}
  */

/**
  * @}
  */
