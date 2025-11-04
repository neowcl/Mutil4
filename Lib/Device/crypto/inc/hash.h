/**
* @file        hash.h
* @brief       This file contains all the functions prototypes for the HASH firmware library. 
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


#ifndef __HASH_H__
#define __HASH_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "hash_basic.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup HASH
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup HASH_Exported_Types HASH Exported Types
  * @{
  */

/**
  * @brief HASH status
*/
typedef struct {
    uint32_t busy             : 1;        /*!< calculate busy flag */
} hash_status_t;

/**
  * @brief HASH context
*/
typedef struct
{
	hash_alg_t hash_alg;                                /*!< current hash algorithm */
	uint8_t block_byte_len;
	uint8_t iterator_word_len;
	uint8_t digest_byte_len;
	hash_status_t status;                             /*!< hash update status, .busy=1 means doing閿涳拷=0 means idle */
	uint8_t first_update_flag;                        /*!< whether first time to update message(1:yes, 0:no) */
	uint8_t finish_flag;                              /*!< whether the whole message has been inputted(1:yes, 0:no) */
	uint8_t hash_buffer[HASH_BLOCK_MAX_BYTE_LEN];     /*!< block buffer */
	uint32_t total[HASH_TOTAL_LEN_MAX_WORD_LEN];      /*!< total byte length of the whole message */

#ifdef CONFIG_HASH_SUPPORT_MUL_THREAD
	uint32_t iterator[HASH_ITERATOR_MAX_WORD_LEN];    /*!< keep current hash iterator value for multiple thread */
#endif
} hash_ctx_t;



#ifdef HASH_DMA_FUNCTION
/**
  * @brief HASH DMA context
*/
typedef struct
{
	hash_alg_t hash_alg;                                /*!< current hash algorithm */
	uint32_t total[HASH_TOTAL_LEN_MAX_WORD_LEN];        /*!< total byte length of the whole message */
	uint8_t block_word_len;
	HASH_CALLBACK callback;
} hash_dma_ctx_t;
#endif

/**
  * @}
  */


/** @defgroup HASH_Exported_Constants HASH Exported Constants
  * @{
  */

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup HASH_Exported_Functions HASH Exported Functions
  * @{
  */

/**
  * @brief  get hash block word length.
  * @param  hash_alg: input, specific hash algorithm, please make sure hash_alg is valid.
  * @return hash block word length.
  */
uint32_t hash_get_block_word_len(hash_alg_t hash_alg);

/**
  * @brief  get hash digest word length.
  * @param  hash_alg: input, specific hash algorithm, please make sure hash_alg is valid.
  * @return hash digest word length.
  */
uint32_t hash_get_digest_word_len(hash_alg_t hash_alg);

/**
  * @brief  get hash iterator word length.
  * @param  hash_alg: input, specific hash algorithm, please make sure hash_alg is valid.
  * @return hash iterator word length.
  */
uint32_t hash_get_iterator_word_len(hash_alg_t hash_alg);

/**
  * @brief  init HASH.
  * @param  ctx: input, hash_ctx_t context pointer.
  * @param  hash_alg: input, specific hash algorithm, please make sure hash_alg is valid.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_init(hash_ctx_t *ctx, hash_alg_t hash_alg);

/**
  * @brief  hash update message
  * @param  ctx: input, hash_ctx_t context pointer.
  * @param  msg: input, message.
  * @param  msg_bytes: input, byte length of the input message.
  * @note   Please make sure the three parameters are valid, and ctx is initialized.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_update(hash_ctx_t *ctx, const uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  message update done, get the digest.
  * @param  ctx: input, hash_ctx_t context pointer, please make sure the ctx is valid and initialized.
  * @param  digest: output, hash digest, please make sure the digest buffer is sufficient.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_final(hash_ctx_t *ctx, uint8_t *digest);

/**
  * @brief  input whole message and get its digest.
  * @param  hash_alg: input, specific hash algorithm.
  * @param  msg: input, message.
  * @param  msg_bytes: input, byte length of the input message, it could be 0.
  * @param  digest: output, hash digest, please make sure the digest buffer is sufficient.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash(hash_alg_t hash_alg, uint8_t *msg, uint32_t msg_bytes, uint8_t *digest);

#ifdef HASH_DMA_FUNCTION
/**
  * @brief  init dma hash.
  * @param  ctx: input, hash_dma_ctx_t context pointer.
  * @param  hash_alg: input, specific hash algorithm.
  * @param  callback: callback function pointer.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_dma_init(hash_dma_ctx_t *ctx, hash_alg_t hash_alg, HASH_CALLBACK callback);

/**
  * @brief  dma hash update some message blocks.
  * @param  ctx: input, hash_dma_ctx_t context pointer.
  * @param  msg: input, message blocks.
  * @param  msg_words: input, word length of the input message, must be a multiple of hash block word length.
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_dma_update_blocks(hash_dma_ctx_t *ctx, uint32_t *msg, uint32_t msg_words);

/**
  * @brief  dma hash final(input the remainder message and get the digest).
  * @param  ctx: input, hash_dma_ctx_t context pointer.
  * @param  remainder_msg: input, remainder message.
  * @param  remainder_bytes: input, byte length of the remainder message, must be in [0, BLOCK_BYTE_LEN-1],
  *                          here BLOCK_BYTE_LEN is block byte length of HASH
  * @param  digest: output, hash digest.
  * @note   please make sure the four parameters are valid, and ctx is initialized
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_dma_final(hash_dma_ctx_t *ctx, uint32_t *remainder_msg, uint32_t remainder_bytes, uint32_t *digest);

/**
  * @brief  dma hash digest calculate.
  * @param  hash_alg: input, specific hash algorithm.
  * @param  msg: input, message.
  * @param  msg_bytes: input, byte length of the message, it could be 0.
  * @param  digest: output, hash digest.
  * @param  callback锛歝allback function pointer. 
  * @return HASH_SUCCESS(success), other(error).
  */
uint32_t hash_dma(hash_alg_t hash_alg, uint32_t *msg, uint32_t msg_bytes, uint32_t *digest,
		HASH_CALLBACK callback);
#endif

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* hash.h */


/**
  * @}
  */

/**
  * @}
  */
