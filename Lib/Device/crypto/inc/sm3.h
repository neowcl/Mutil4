/**
* @file        sm3.h
* @brief       This file contains all the functions prototypes for the SM3 firmware library. 
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


#ifndef __SM3_H__
#define __SM3_H__


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

/** @addtogroup SM3
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SM3_Exported_Types SM3 Exported Types
  * @{
  */

#ifdef SUPPORT_HASH_SM3

typedef hash_ctx_t SM3_CTX;

#endif
/**
  * @}
  */


/** @defgroup SM3_Exported_Constants SM3 Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SM3_Exported_Functions SM3 Exported Functions
  * @{
  */
#ifdef SUPPORT_HASH_SM3
/**
  * @brief  init sm3
  * @param  ctx: input, SM3_CTX context pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_init(SM3_CTX *ctx);

/**
  * @brief  sm3 update message
  * @param  ctx: input, SM3_CTX context pointer
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @note   Please make sure the three parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_update(SM3_CTX *ctx, const uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  message update done, get the sm3 digest
  * @param  digest: output, sm3 digest, 32 bytes
  * @note   Please make sure the digest buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_final(SM3_CTX *ctx, uint8_t *digest);

/**
  * @brief  input whole message and get its sm3 digest
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message, it could be 0
  * @param  digest: output, sm3 digest, 32 bytes
  * @note   Please make sure the digest buffer is sufficient
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3(uint8_t *msg, uint32_t msg_bytes, uint8_t *digest);

#ifdef HASH_DMA_FUNCTION
/**
  * @brief  init dma sm3
  * @param  ctx: input, SM3_DMA_CTX context pointer
  * @param  callback: callback function pointer
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_dma_init(SM3_DMA_CTX *ctx, HASH_CALLBACK callback);

/**
  * @brief  dma sm3 update some message blocks
  * @param  ctx: input, SM3_DMA_CTX context pointer
  * @param  msg: input, message blocks
  * @param  msg_words: input, word length of the input message, must be a multiple of sm3 block word length(16)
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_dma_update_blocks(SM3_DMA_CTX *ctx, uint32_t *msg, uint32_t msg_words);

/**
  * @brief  dma sm3 final(input the remainder message and get the digest)
  * @param  ctx: input, SM3_DMA_CTX context pointer
  * @param  remainder_msg: input, remainder message
  * @param  remainder_bytes: input, byte length of the remainder message, must be in [0, BLOCK_BYTE_LEN1],
  *                          here BLOCK_BYTE_LEN is block byte length of sm3, it is 64.
  * @param  digest: output, sm3 digest, 32 bytes
  * @note   Please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_dma_final(SM3_DMA_CTX *ctx, uint32_t *remainder_msg, uint32_t remainder_bytes, uint32_t *digest);

/**
  * @brief  dma sm3 digest calculate
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the message, it could be 0
  * @param  digest: output, sm3 digest, 32 bytes
  * @param  callback: callback function pointer
  * @note   Please make sure the four parameters are valid
  * @return HASH_SUCCESS(success), other(error)
 */
uint32_t sm3_dma(uint32_t *msg, uint32_t msg_bytes, uint32_t *digest, HASH_CALLBACK callback);
#endif

#endif

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* sm3.h */


/**
  * @}
  */

/**
  * @}
  */
