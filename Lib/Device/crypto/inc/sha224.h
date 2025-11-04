/**
* @file        sha224.h
* @brief       This file contains all the functions prototypes for the SHA224 firmware library. 
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


#ifndef __SHA224_H__
#define __SHA224_H__


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

/** @addtogroup SHA224
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SHA224_Exported_Types SHA224 Exported Types
  * @{
  */

#ifdef SUPPORT_HASH_SHA224

typedef hash_ctx_t SHA224_CTX;

#ifdef HASH_DMA_FUNCTION
typedef hash_dma_ctx_t SHA224_DMA_CTX;
#endif

#endif
/**
  * @}
  */


/** @defgroup SHA224_Exported_Constants SHA224 Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SHA224_Exported_Functions SHA224 Exported Functions
  * @{
  */

#ifdef SUPPORT_HASH_SHA224
/**
  * @brief  init sha224
  * @param  ctx: input, SHA224_CTX context pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_init(SHA224_CTX *ctx);

/**
  * @brief  sha224 update message
  * @param  ctx: input, SHA224_CTX context pointer
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @note   Please make sure the three parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_update(SHA224_CTX *ctx, const uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  message update done, get the sha224 digest
  * @param  digest: output, sha224 digest, 28 bytes
  * @note   Please make sure the digest buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_final(SHA224_CTX *ctx, uint8_t *digest);

/**
  * @brief  input whole message and get its sha224 digest
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message, it could be 0
  * @param  digest: output, sha224 digest, 28 bytes
  * @note   Please make sure the digest buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224(uint8_t *msg, uint32_t msg_bytes, uint8_t *digest);

#ifdef HASH_DMA_FUNCTION
/**
  * @brief  init dma sha224
  * @param  ctx: input, SHA224_DMA_CTX context pointer
  * @param  callback: callback function pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_dma_init(SHA224_DMA_CTX *ctx, HASH_CALLBACK callback);

/**
  * @brief  dma sha224 update some message blocks
  * @param  ctx: input, SHA224_DMA_CTX context pointer
  * @param  msg: input, message blocks
  * @param  msg_words: input, word length of the input message, must be a multiple of sha224
  *                    block word length(16)
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_dma_update_blocks(SHA224_DMA_CTX *ctx, uint32_t *msg, uint32_t msg_words);

/**
  * @brief  dma sha224 final(input the remainder message and get the digest)
  * @param  ctx: input, SHA224_DMA_CTX context pointer
  * @param  remainder_msg: input, remainder message
  * @param  remainder_bytes: input, byte length of the remainder message, must be in [0, BLOCK_BYTE_LEN1],
  *                          here BLOCK_BYTE_LEN is block byte length of sha224, it is 64.
  * @param  digest: output, sha224 digest, 28 bytes
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_dma_final(SHA224_DMA_CTX *ctx, uint32_t *remainder_msg, uint32_t remainder_bytes, uint32_t *digest);

/**
  * @brief  dma sha224 digest calculate
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the message, it could be 0
  * @param  digest: output, sha224 digest, 28 bytes
  * @param  callback: callback function pointer
  * @note   Please make sure the four parameters are valid
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sha224_dma(uint32_t *msg, uint32_t msg_bytes, uint32_t *digest, HASH_CALLBACK callback);
#endif

#endif
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* sha224.h */


/**
  * @}
  */

/**
  * @}
  */
