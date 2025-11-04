/**
* @file        hmac.h
* @brief       This file contains all the functions prototypes for the HMAC firmware library. 
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


#ifndef __HMAC_H__
#define __HMAC_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "hash.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup HMAC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup HMAC_Exported_Types HMAC Exported Types
  * @{
  */

/**
  * @brief HMAC context
*/
typedef struct
{
	uint32_t K0[HASH_BLOCK_MAX_WORD_LEN];
	hash_alg_t hash_alg;
	hash_ctx_t hash_ctx[1];
} hmac_ctx_t;

/**
  * @brief HMAC DMA context
*/
#ifdef HASH_DMA_FUNCTION
typedef struct
{
	hmac_ctx_t hmac_ctx[1];
	hash_dma_ctx_t hash_dma_ctx[1];
} hmac_dma_ctx_t;
#endif

/**
  * @}
  */


/** @defgroup HMAC_Exported_Constants HMAC Exported Constants
  * @{
  */
#define HMAC_IPAD                 (0x36363636)
#define HMAC_OPAD                 (0x5c5c5c5c)
#define HMAC_IPAD_XOR_OPAD        (HMAC_IPAD ^ HMAC_OPAD)
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup HMAC_Exported_Functions HMAC Exported Functions
  * @{
  */

/**
  * @brief  init HMAC
  * @param  ctx: input, hmac_ctx_t context pointer
  * @param  hash_alg: input, specific hash algorithm
  * @param  key: input, key
  * @param  sp_key_idx: input, index of secure port key
  * @param  key_bytes: input, byte length of key, it could be 0
  * @note   Please make sure hash_alg is valid
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_init(hmac_ctx_t *ctx, hash_alg_t hash_alg, uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes);

/**
  * @brief  hmac update message
  * @param  ctx: input, hmac_ctx_t context pointer
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @note Please make sure the three parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_update(hmac_ctx_t *ctx, const uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  message update done, get the hmac
  * @param  ctx: input, hmac_ctx_t context pointer
  * @param  mac: output, hmac
  * @note   1. please make sure the ctx is valid and initialized
            2. please make sure the mac buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_final(hmac_ctx_t *ctx, uint8_t *mac);

/**
  * @brief  input key and whole message, get the hmac
  * @param  hash_alg: input, specific hash algorithm
  * @param  key: input, key
  * @param  sp_key_idx: input, index of secure port key
  * @param  key_bytes: input, byte length of the key
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @param  mac: output, hmac
  * @note   Please make sure the mac buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac(hash_alg_t hash_alg, uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes, uint8_t *msg, uint32_t msg_bytes,
		uint8_t *mac);


#ifdef HASH_DMA_FUNCTION
/**
  * @brief  init dma hmac
  * @param  ctx: input, hmac_dma_ctx_t context pointer
  * @param  hash_alg: input, specific hash algorithm
  * @param  key: input, key
  * @param  sp_key_idx: input, index of secure port key
  * @param  key_bytes: input, key byte length
  * @param  callback: callback function pointer
  * @note   1. please make sure hash_alg is valid
            2. here hmac is not for SHA3.
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_dma_init(hmac_dma_ctx_t *ctx, hash_alg_t hash_alg, const uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes,
		HASH_CALLBACK callback);

/**
  * @brief  dma hmac update message
  * @param  ctx: input, hmac_dma_ctx_t context pointer
  * @param  msg: input, message
  * @param  msg_words: input, word length of the input message, must be a multiple of block word length of HASH
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_dma_update_blocks(hmac_dma_ctx_t *ctx, uint32_t *msg, uint32_t msg_words);

/**
  * @brief  dma hmac message update done, get the hmac
  * @param  ctx: input, hmac_dma_ctx_t context pointer
  * @param  remainder_msg: input, message
  * @param  remainder_bytes: input, byte length of the last message, must be in [0, BLOCK_BYTE_LEN1],
                             here BLOCK_BYTE_LEN is block byte length of HASH
  * @param  mac: output, hmac
  * @note   Please make sure the three parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_dma_final(hmac_dma_ctx_t *ctx, uint32_t *remainder_msg, uint32_t remainder_bytes, uint32_t *mac);

/**
  * @brief  dma hmac input key and message, get the hmac
  * @param  hash_alg: input, specific hash algorithm, please make sure hash_alg is valid
  * @param  key: input, key
  * @param  sp_key_idx: input, index of secure port key
  * @param  key_bytes: input, key byte length
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @param  mac: output, hmac
  * @param  callback: callback function pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t hmac_dma(hash_alg_t hash_alg, uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes, uint32_t *msg, uint32_t msg_bytes,
		uint32_t *mac, HASH_CALLBACK callback);
#endif

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* hmac.h */


/**
  * @}
  */

/**
  * @}
  */
