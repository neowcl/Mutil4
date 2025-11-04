/**
* @file        ecdsa.h
* @brief       This file contains all the functions prototypes for the ECDSA firmware library. 
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


#ifndef __ECDSA_H__
#define __ECDSA_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "pke.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup ECDSA
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup ECDSA_Exported_Types ECDSA Exported Types
  * @{
  */

/**
  * @brief ECDSA return code
*/
typedef enum
{
	ECDSA_SUCCESS = PKE_SUCCESS,
	ECDSA_POINTOR_NULL = PKE_SUCCESS+0x50,
	ECDSA_INVALID_INPUT,
	ECDSA_ZERO_ALL,
	ECDSA_INTEGER_TOO_BIG,
	ECDSA_VERIFY_FAILED,
}ecdsa_ret_code;

/**
  * @brief ECDSA return code
*/
typedef enum
{
	ECDSA_SUCCESS_S = 0x7D5FEB14,
	ECDSA_ERROR_S = 0xB4C0BC5A
}ecdsa_ret_code_s;

/**
  * @}
  */


/** @defgroup ECDSA_Exported_Constants ECDSA Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup ECDSA_Exported_Functions ECDSA Exported Functions
  * @{
  */
/**
  * @brief  Generate ECDSA Signature in byte string style
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  E: input, hash value, big-endian.
  * @param  EByteLen: input, byte length of E.
  * @param  rand_k: input, random big integer k in signing, big-endian.
  * @param  priKey: input, private key, big-endian.
  * @param  signature: output, signature r and s, big-endian.
  * @note   The method of getting big integer e from hash value E is based on SEC1 V2.
  * @return ECDSA_SUCCESS_S(success); other(error).
  */
uint32_t ecdsa_sign(eccp_curve_t *curve, uint8_t *E, uint32_t EByteLen, uint8_t *rand_k, uint8_t *priKey,
		uint8_t *signature);

/**
  * @brief  Verify ECDSA Signature in byte string style
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  E: input, hash value, big-endian.
  * @param  EByteLen: input, byte length of E.
  * @param  pubKey: input, public key, big-endian.
  * @param  signature: input, signature r and s, big-endian.
  * @note   The method of getting big integer e from hash value E is based on SEC1 V2.
  * @return ECDSA_SUCCESS_S(success); other(error).
  */
uint32_t ecdsa_verify(eccp_curve_t *curve, uint8_t *E, uint32_t EByteLen, uint8_t *pubKey, uint8_t *signature);

#ifdef PKE_SEC

#define ECDSA_SEC
#ifdef ECDSA_SEC
/**
  * @brief  Generate ECDSA Signature in byte string style
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  E: input, hash value, big-endian.
  * @param  EByteLen: input, byte length of E.
  * @param  rand_k: input, random big integer k in signing, big-endian.
  * @param  priKey: input, private key, big-endian.
  * @param  signature: output, signature r and s, big-endian.
  * @note   The method of getting big integer e from hash value E is based on SEC1 V2.
  * @return ECDSA_SUCCESS_S(success); other(error).
  */
uint32_t ecdsa_sign_s(eccp_curve_t *curve, uint8_t *E, uint32_t EByteLen, uint8_t *rand_k, uint8_t *priKey,
		uint8_t *signature);

/**
  * @brief  Generate ECDSA Signature in byte string style
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  E: input, hash value, big-endian.
  * @param  EByteLen: input, byte length of E.
  * @param  rand_k: input, random big integer k in signing, big-endian.
  * @param  priKey_addr: input, private key address use for SDMA transmission.
  * @param  signature: output, signature r and s, big-endian.
  * @note   The method of getting big integer e from hash value E is based on SEC1 V2.
  * @return ECDSA_SUCCESS_S(success); other(error).
  */
uint32_t ecdsa_sdma_sign_s(eccp_curve_t *curve, uint8_t *E, uint32_t EByteLen, uint8_t *rand_k, uint32_t priKey_addr,
		uint8_t *signature);

/**
  * @brief  Verify ECDSA Signature in byte string style
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  E: input, hash value, big-endian.
  * @param  EByteLen: input, byte length of E.
  * @param  pubKey: input, public key, big-endian.
  * @param  signature: input, signature r and s, big-endian.
  * @note   The method of getting big integer e from hash value E is based on SEC1 V2.
  * @return ECDSA_SUCCESS_S(success); other(error).
  */	
uint32_t ecdsa_verify_s(eccp_curve_t *curve, uint8_t *E, uint32_t EByteLen, uint8_t *pubKey, uint8_t *signature);

#endif
#endif
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* ecdsa.h */


/**
  * @}
  */

/**
  * @}
  */
