/**
* @file        hash_basic.h
* @brief       This file contains all the functions prototypes for the Hash baisc firmware library. 
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


#ifndef __HASH_BASIC_H__
#define __HASH_BASIC_H__


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

/** @addtogroup HASH_BAISC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/

/** @defgroup HASH_BAISC_Exported_Constants HASH Basic Exported Constants
  * @{
  */

#define SUPPORT_HASH_SM3
#define SUPPORT_HASH_SHA256
#define SUPPORT_HASH_SHA224

//#define HMAC_SECURE_PORT_FUNCTION
#ifdef HMAC_SECURE_PORT_FUNCTION
#define HMAC_MAX_KEY_IDX                             (8)   /*!< if key is from secure port, the max key index(or the number of keys) */
#define HMAC_MAX_SP_KEY_SIZE                         (64)  /*!< for secure port key, max bytes of one key */
#endif

/**
  * @brief some register offset
*/
#define HASH_LAST_OFFSET                             (24)
#define HASH_DMA_OFFSET                              (17)
#define HASH_INTERRUPTION_OFFSET                     (16)

/**
  * @brief HASH max length
*/

#define HASH_DIGEST_MAX_WORD_LEN       (8)
#define HASH_BLOCK_MAX_WORD_LEN        (16)
#define HASH_TOTAL_LEN_MAX_WORD_LEN    (2)

#define HASH_ITERATOR_MAX_WORD_LEN     HASH_DIGEST_MAX_WORD_LEN
#define HASH_BLOCK_MAX_BYTE_LEN        (HASH_BLOCK_MAX_WORD_LEN<<2)
/**
  * @}
  */

/** @defgroup HASH_BAISC_Exported_Types HASH Basic Exported Types
  * @{
  */

/**
  * @brief HASH register struct
*/
typedef struct {
	uint32_t HASH_CTRL;						/*!< Offset: 0x000 (W1S)  Control register */
	uint32_t HASH_CFG;						/*!< Offset: 0x004 (R/W)  Config register */
	uint32_t HASH_SR1;						/*!< Offset: 0x008 (R)    Status register 1 */
	uint32_t HASH_SR2;						/*!< Offset: 0x00C (W1C)  Status register 2 */
	uint32_t REV_1[4];
	uint32_t HASH_PCR_LEN[4];				/*!< Offset: 0x020 (R/W)  message length register */
	uint32_t HASH_OUT[16];					/*!< Offset: 0x030 (R)    Output register */
	uint32_t HASH_IN[16];					/*!< Offset: 0x070 (W)    Hash iterator Input register */
	uint32_t HASH_VERSION;					/*!< Offset: 0x0B0 (R)    Version register */
	uint32_t REV_2[19];
	uint32_t HASH_M_DIN[32];				/*!< Offset: 0x100 (R/W)  Hash message Input register */
	uint32_t DMA_SA;						/*!< Offset: 0x180 (R/W)  DMA Source Address register */
	uint32_t DMA_DA;						/*!< Offset: 0x184 (R/W)  DMA Destination Address register */
	uint32_t DMA_RLEN;						/*!< Offset: 0x188 (R/W)  DMA Input Length register */
	uint32_t DMA_WLEN;						/*!< Offset: 0x18C (R/W)  DMA Output Length register */
} hash_reg_t;

/**
  * @brief HASH algorithm definition
*/
typedef enum {
#ifdef SUPPORT_HASH_SM3
	HASH_SM3                      = 0,
#endif

#ifdef SUPPORT_HASH_SHA256
	HASH_SHA256                   = 2,
#endif

#ifdef SUPPORT_HASH_SHA224
	HASH_SHA224                   = 6,
#endif
} hash_alg_t;

/**
  * @brief HASH return code
*/
typedef enum
{
	HASH_SUCCESS = 0,
	HASH_BUFFER_NULL,
	HASH_CONFIG_INVALID,
	HASH_INPUT_INVALID,
	HASH_LEN_OVERFLOW,
	HASH_ERROR,
}hash_ret_code_t;

/**
  * @}
  */





/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup HASH_BAISC_Exported_Functions HASH Basic Exported Functions
  * @{
  */

/**
  * @brief hash callback function type
*/
typedef void (*HASH_CALLBACK)(void);

/**
  * @brief  get HFE IP version
  * @param  none
  * @return HFE IP version.
  */
uint32_t hash_get_version(void);

/**
  * @brief  set hash to be CPU mode
  * @param  none.
  * @return none.
  */
void hash_set_cpu_mode(void);

/**
  * @brief  set hash to be DMA mode
  * @param  none.
  * @return none.
  */
void hash_set_dma_mode(void);

/**
  * @brief  set the specific hash algorithm
  * @param  hash_alg: input, specific hash algorithm, please make sure hash_alg is valid.
  * @return none.
  */
void hash_set_alg(hash_alg_t hash_alg);

/**
  * @brief  enable hash interruption in CPU mode or DMA mode.
  * @param  none.
  * @return none.
  */
void hash_enable_interruption(void);

/**
  * @brief  disable hash interruption in CPU mode or DMA mode.
  * @param  none.
  * @return none.
  */
void hash_disable_interruption(void);

/**
  * @brief  set the tag whether current block is the last message block or not.
  * @param  tag: input, 0(no), other(yes) .
  * @note   if it is the last block, please config hash_reg->HASH_MSG_LEN,
  *         then the hardware will do the padding and post-processing.
  * @return none.
  */
void hash_set_last_block(uint32_t tag);

/**
  * @brief  get current HASH iterator value.
  * @param  iterator: output, current hash iterator.
  * @param  hash_iterator_words: input, iterator word length.
  * @return none.
  */
void hash_get_iterator(uint8_t *iterator, uint32_t hash_iterator_words);

/**
  * @brief  input current iterator value.
  * @param  iterator: input, hash iterator value, it must be word aligned.
  * @param  hash_iterator_words: input, iterator word length.
  * @return none.
  */
void hash_set_iterator(uint32_t *iterator, uint32_t hash_iterator_words);

/**
  * @brief  clear HASH_PCR_LEN.
  * @param  none.
  * @return none.
  */
void hash_clear_msg_len(void);

/**
  * @brief  set the total byte length of the whole message.
  * @param  msg_total_bytes: input, total byte length of the whole message.
  * @param  words: input, word length of array msg_total_bytes.
  * @return none.
  */
void hash_set_msg_total_byte_len(uint32_t *msg_total_bytes, uint32_t words);

/**
  * @brief  start HASH iteration calc.
  * @param  none.
  * @return none.
  */
void hash_start(void);

/**
  * @brief  wait till done.
  * @param  none.
  * @return none.
  */
void hash_wait_till_done(void);

/**
  * @brief  set dma output bytes length.
  * @param  bytes: input,  byte length of the written data for hash hardware.
  * @return none.
  */
void hash_set_dma_output_len(uint32_t bytes);

/**
  * @brief  DMA wait till done.
  * @param  msg: input, message.
  * @param  msg_words: input, word length of msg. 
  * @note   If msg does not contain the last block, please make sure msg_words is a multiple of 
  *         the hash block word length.
  * @return none.
  */
void hash_input_msg(uint8_t *msg, uint32_t msg_words);

#ifdef HASH_DMA_FUNCTION
/**
  * @brief  basic HASH DMA operation.
  * @param  in: input, message of some blocks, or message including the last byte(last block).
  * @param  out: output, hash digest or hmac.
  * @param  inByteLen: input, actual byte length of input msg.
  * @param  callback: callback function pointer.
  * @note   1. for DMA operation, the unit of input and output is 4 words, so, please make sure the buffer
  *            out is sufficient.
  *         2. if just to input message, not to get digest or hmac, please set para out to be NULL and WLEN to be 0.
  *            if to get the digest or hmac, para out can not be NULL, and please set WLEN to be digest length.
  * @return none.
  */
void hash_dma_operate(uint32_t *in, uint32_t *out, uint32_t inByteLen, HASH_CALLBACK callback);
#endif
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* hash_basic.h */


/**
  * @}
  */

/**
  * @}
  */
