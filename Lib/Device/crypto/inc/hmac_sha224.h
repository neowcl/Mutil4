/**
* @file        hmac_sha224.h
* @brief       This file contains all the functions prototypes for the HMAC SHA224 firmware library. 
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


#ifndef __HMAC_SHA224_H__
#define __HMAC_SHA224_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "hmac.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup HMAC_SHA224
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup HMAC_SHA224_Exported_Types HMAC SHA224 Exported Types
  * @{
  */

#ifdef SUPPORT_HASH_SHA224

typedef hmac_ctx_t HMAC_SHA224_CTX;

#ifdef HASH_DMA_FUNCTION
typedef hmac_dma_ctx_t HMAC_SHA224_DMA_CTX;
#endif

#endif

/**
  * @}
  */


/** @defgroup HMAC_SHA224_Exported_Constants HMAC SHA224 Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup HMAC_SHA224_Exported_Functions HMAC SHA224 Exported Functions
  * @{
  */

#ifdef SUPPORT_HASH_SHA224
/**
  * @brief  init hmac-sha224.
  * @param  ctx: input, HMAC_SHA224_CTX context pointer.
  * @param  key: input, key.
  * @param  sp_key_idx: input, index of secure port key.
  * @param  key_bytes: input, byte length of key, it could be 0.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_init(HMAC_SHA224_CTX *ctx, uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes);

/**
  * @brief  hmac-sha224 update message.
  * @param  ctx: input, HMAC_SHA224_CTX context pointer.
  * @param  msg: input, message.
  * @param  msg_bytes: input, byte length of the input message.
  * @note   Please make sure the three parameters are valid, and ctx is initialized.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_update(HMAC_SHA224_CTX *ctx, const uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  message update done, get the hmac.
  * @param  ctx: input, HMAC_SHA224_CTX context pointer.
  * @param  mac: output, hmac.
  * @note   1. please make sure the ctx is valid and initialized.
  *         2. please make sure the mac buffer is sufficient.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_final(HMAC_SHA224_CTX *ctx, uint8_t *mac);

/**
  * @brief  input key and whole message, get the hmac.
  * @param  key: input, key.
  * @param  sp_key_idx: input, index of secure port key.
  * @param  key_bytes: input, byte length of the key
  * @param  msg: input, message.
  * @param  msg_bytes: input, byte length of the input message.
  * @param  mac: output, hmac.
  * @note   Please make sure the mac buffer is sufficient.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224(uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes, uint8_t *msg, uint32_t msg_bytes, uint8_t *mac);

#ifdef HASH_DMA_FUNCTION
/**
  * @brief  init dma hmac-sha224.
  * @param  ctx: input, HMAC_SHA224_DMA_CTX context pointer.
  * @param  key: input, key.
  * @param  sp_key_idx: input, index of secure port key.
  * @param  key_bytes: input, message.
  * @param  callback: callback function pointer.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_dma_init(HMAC_SHA224_DMA_CTX *ctx, const uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes,
		HASH_CALLBACK callback);

/**
  * @brief  dma hmac-sha224 update message.
  * @param  ctx: input, HMAC_SHA224_DMA_CTX context pointer.
  * @param  msg: input, message.
  * @param  msg_words: input, word length of the input message, must be a multiple of block word length of SHA224(16).
  * @note   please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_dma_update_blocks(HMAC_SHA224_DMA_CTX *ctx, uint32_t *msg, uint32_t msg_words);

/**
  * @brief  dma hmac-sha224 message update done, get the hmac.
  * @param  ctx: input, HMAC_SHA224_DMA_CTX context pointer.
  * @param  remainder_msg: input, message.
  * @param  remainder_bytes: input, byte length of the last message, must be in [0, BLOCK_BYTE_LEN-1],
  *                          here BLOCK_BYTE_LEN is block byte length of SHA224(64).
  * @param  mac: output, hmac.
  * @note   please make sure the three parameters are valid, and ctx is initialized.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_dma_final(HMAC_SHA224_DMA_CTX *ctx, uint32_t *remainder_msg, uint32_t remainder_bytes,
		uint32_t *mac);

/**
  * @brief  dma hmac-sha224 input key and message, get the hmac.
  * @param  key: input, key.
  * @param  sp_key_idx: input, index of secure port key.
  * @param  key_bytes: input, key byte length.
  * @param  msg: input, message.
  * @param  msg_bytes: input, byte length of the input message.
  * @param  mac: output, hmac.
  * @param  callback: callback function pointer.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hmac_sha224_dma(uint8_t *key, uint16_t sp_key_idx, uint32_t key_bytes, uint32_t *msg, uint32_t msg_bytes,
		uint32_t *mac, HASH_CALLBACK callback);
#endif

#endif
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* hmac_sha224.h */


/**
  * @}
  */

/**
  * @}
  */
