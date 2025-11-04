/**
* @file        sha256.h
* @brief       This file contains all the functions prototypes for the SHA256 firmware library. 
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


#ifndef __SHA256_H__
#define __SHA256_H__


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

/** @addtogroup SHA256
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SHA256_Exported_Types SHA256 Exported Types
  * @{
  */

#ifdef SUPPORT_HASH_SHA256

typedef hash_ctx_t SHA256_CTX;

#ifdef HASH_DMA_FUNCTION
typedef hash_dma_ctx_t SHA256_DMA_CTX;
#endif

#endif
/**
  * @}
  */


/** @defgroup SHA256_Exported_Constants SHA256 Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SHA256_Exported_Functions SHA256 Exported Functions
  * @{
  */

#ifdef SUPPORT_HASH_SHA256
/**
  * @brief  init sha256
  * @param  ctx: input, SHA256_CTX context pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_init(SHA256_CTX *ctx);

/**
  * @brief  sha256 update message
  * @param  ctx: input, SHA256_CTX context pointer
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @note   Please make sure the three parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_update(SHA256_CTX *ctx, const uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  message update done, get the sha256 digest
  * @param  digest: output, sha256 digest, 32 bytes
  * @note   Please make sure the digest buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_final(SHA256_CTX *ctx, uint8_t *digest);

/**
  * @brief  input whole message and get its sha256 digest
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message, it could be 0
  * @param  digest: output, sha256 digest, 32 bytes
  * @note   Please make sure the digest buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256(uint8_t *msg, uint32_t msg_bytes, uint8_t *digest);

#ifdef HASH_DMA_FUNCTION
/**
  * @brief  init dma sha256
  * @param  ctx: input, SHA256_DMA_CTX context pointer
  * @param  callback: callback function pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_dma_init(SHA256_DMA_CTX *ctx, HASH_CALLBACK callback);

/**
  * @brief  dma sha256 update some message blocks
  * @param  ctx: input, SHA256_DMA_CTX context pointer
  * @param  msg: input, message blocks
  * @param  msg_words: input, word length of the input message, must be a multiple of sha256
  *                    block word length(16)
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_dma_update_blocks(SHA256_DMA_CTX *ctx, uint32_t *msg, uint32_t msg_words);

/**
  * @brief  dma sha256 final(input the remainder message and get the digest)
  * @param  ctx: input, SHA256_DMA_CTX context pointer
  * @param  remainder_msg: input, remainder message
  * @param  remainder_bytes: input, byte length of the remainder message, must be in [0, BLOCK_BYTE_LEN1],
  *                          here BLOCK_BYTE_LEN is block byte length of sha256, it is 64.
  * @param  digest: output, sha256 digest, 32 bytes
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_dma_final(SHA256_DMA_CTX *ctx, uint32_t *remainder_msg, uint32_t remainder_bytes, uint32_t *digest);

/**
  * @brief  dma sha256 digest calculate
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the message, it could be 0
  * @param  digest: output, sha256 digest, 32 bytes
  * @param  callback: callback function pointer
  * @note   Please make sure the four parameters are valid
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha256_dma(uint32_t *msg, uint32_t msg_bytes, uint32_t *digest, HASH_CALLBACK callback);
#endif

#endif

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* sha256.h */


/**
  * @}
  */

/**
  * @}
  */
 