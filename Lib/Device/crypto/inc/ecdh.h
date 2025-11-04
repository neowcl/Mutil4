/**
* @file        ecdh.h
* @brief       This file contains all the functions prototypes for the ECDH firmware library. 
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


#ifndef __ECDH_H__
#define __ECDH_H__


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

/** @addtogroup ECDH
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup ECDH_Exported_Types ECDH Exported Types
  * @{
  */

/**
  * @brief ECDH return code
*/
typedef enum 
{
	ECDH_SUCCESS = PKE_SUCCESS,
	ECDH_POINTOR_NULL = PKE_SUCCESS+0x60,
	ECDH_INVALID_INPUT,
	ECDH_ZERO_ALL,
	ECDH_INTEGER_TOO_BIG,
}ecdh_ret_code;

#ifdef PKE_SEC

#define ECDH_SEC
#ifdef ECDH_SEC
/**
  * @brief ECDH return codes
*/
typedef enum 
{
	ECDH_SUCCESS_S = 0x8B9BC1E1,
	ECDH_ERROR_S = 0xCBC192A3
}ecdh_ret_code_s;
#endif
#endif

/**
  * @}
  */


/** @defgroup ECDH_Exported_Constants ECDH Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup ECDH_Exported_Functions ECDH Exported Functions
  * @{
  */

/**
  * @brief  ECDH compute key
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  local_prikey: input, local private key, big-endian.
  * @param  peer_pubkey: input, peer public key, big-endian.
  * @param  key: output, output key.
  * @param  keyByteLen: input, byte length of output key.
  * @param  kdf: input, KDF function to get key.
  * @return ECDH_SUCCESS_S(success); other(error).
  */
uint32_t ecdh_compute_key(eccp_curve_t *curve, uint8_t *local_prikey, uint8_t *peer_pubkey, uint8_t *key,
		uint32_t keyByteLen, KDF_FUNC kdf);

#ifdef PKE_SEC

#define ECDH_SEC
#ifdef ECDH_SEC

/**
  * @brief  ECDH compute key
  * @param  curve: eccp_curve struct pointer, curve should not be null.
  * @param  local_prikey: input, local private key, big-endian.
  * @param  peer_pubkey: input, peer public key, big-endian.
  * @param  key: output, output key.
  * @param  keyByteLen: input, byte length of output key.
  * @param  kdf: input, KDF function to get key.
  * @return ECDH_SUCCESS_S(success); other(error).
  */
uint32_t ecdh_compute_key_s(eccp_curve_t *curve, uint8_t *local_prikey, uint8_t *peer_pubkey, uint8_t *key,
		uint32_t keyByteLen, KDF_FUNC kdf);

#endif
#endif
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* ecdh.h */


/**
  * @}
  */

/**
  * @}
  */
