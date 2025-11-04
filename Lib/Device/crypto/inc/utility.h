/**
* @file        utility.h
* @brief       This file contains all the functions prototypes for the utility firmware library. 
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


#ifndef __UTILITY_H__
#define __UTILITY_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include <stdint.h> 


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup UTILITY
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup UTILITY_Exported_Types Utility Exported Types
  * @{
  */

/**
  * @}
  */


/** @defgroup UTILITY_Exported_Constants Utility Exported Constants
  * @{
  */

#define GET_MAX_LEN(a,b)         (((a)>(b))?(a):(b))
#define GET_MIN_LEN(a,b)         (((a)>(b))?(b):(a))
#define GET_WORD_LEN(bitLen)     (((bitLen)+31)/32)
#define GET_BYTE_LEN(bitLen)     (((bitLen)+7)/8)
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup UTILITY_Exported_Functions Utility Exported Functions
  * @{
  */

#define PKE_PRINT_BUF
#ifdef PKE_PRINT_BUF
extern void print_buf_U8(uint8_t buf[], uint32_t byteLen, char name[]);
extern void print_buf_U32(uint32_t buf[], uint32_t wordLen, char name[]);
extern void print_BN_buf_U32(uint32_t buf[], uint32_t wordLen, char name[]);
#endif

void memcpy_(void *dst, void *src, uint32_t size);

void memset_(void *dst, uint8_t value, uint32_t size);

int8_t memcmp_(void *m1, void *m2, uint32_t size);

/**
  * @brief  set uint32 buffer
  * @param  a: output, output word buffer
  * @param  value: input, input word value
  * @param  wordLen: input, word length of buffer a
  * @return none
 */
void uint32_set(uint32_t *a, uint32_t value, uint32_t wordLen);

/**
  * @brief  copy uint32 buffer
  * @param  dst: output, output word buffer 
  * @param  src: input, input word buffer
  * @param  wordLen: input, word length of buffer dst or src
  * @return none
 */
void uint32_copy(uint32_t *dst, uint32_t *src, uint32_t wordLen);

/**
  * @brief  clear uint32 buffer
  * @param  a: input&output, word buffer a
  * @param  aWordLen: input, word length of buffer a
  * @return none
 */
void uint32_clear(uint32_t *a, uint32_t wordLen);

/**
  * @brief  sleep for a while
  * @param  count: input, count  
  * @return none 
 */
void uint32_sleep(uint32_t count, uint8_t rand);

/**
  * @brief  convert 0x1122334455667788 to 0x4433221188776655
  * @param  in: source address
  * @param  out: destination address
  * @param  wordLen: word length of in/out
  * @return none
*/
void uint32_endian_reverse(uint8_t *in, uint8_t *out, uint32_t wordLen);

/**
  * @brief  reverse byte array
  * @param  in: input, input buffer
  * @param  out: output, output buffer
  * @param  byteLen: input, byte length of in or out
  * @note   In and out could point the same buffer
  * @return none
 */
void reverse_byte_array(uint8_t *in, uint8_t *out, uint32_t byteLen);

//void reverse_word(uint8_t *in, uint8_t *out, uint32_t bytelen);

//void dma_reverse_word_array(uint32_t *in, uint32_t *out, uint32_t wordlen, uint32_t reverse_word);

/**
  * @brief  C = A XOR B
  * @param  A: input, byte buffer a
  * @param  B: input, byte buffer b
  * @param  C: output, C = A XOR B
  * @param  byteLen: input, byte length of A,B,C
  * @return none
 */
void uint8_xor(uint8_t *A, uint8_t *B, uint8_t *C, uint32_t byteLen);

/**
  * @brief  C = A XOR B
  * @param  A: input, word buffer a
  * @param  B: input, word buffer b
  * @param  C: output, C = A XOR B
  * @param  wordLen: input, word length of A,B,C
  * @return none
 */
void uint32_xor(uint32_t *A, uint32_t *B, uint32_t *C, uint32_t wordLen);

/**
  * @brief  get real bit length of big number a of wordLen words
  * @param  a: input, big integer a
  * @param  wordLen: input, word length of a
  * @return real word length of big number a
 */
uint32_t get_valid_bits(const uint32_t *a, uint32_t wordLen);

/**
  * @brief  get real word lenth of big number a of max_words words
  * @param  a: input, big integer a
  * @param  max_words: input, max word length of a
  * @return real word length of big number a
 */
uint32_t get_valid_words(uint32_t *a, uint32_t max_words);

/**
  * @brief  check whether big number or uint8_t buffer a is all zero or not
  * @param  a: input, byte buffer a
  * @param  aByteLen: input, byte length of a
  * @return 0(a is not zero),1(a is all zero)
 */
uint8_t uint8_bignum_check_zero(uint8_t a[], uint32_t aByteLen);

/**
  * @brief  check whether big number or uint32_t buffer a is all zero or not
  * @param  a: input, big integer or word buffer a
  * @param  aWordLen: input, word length of a
  * @return 0(a is not zero), 1(a is all zero)
 */
uint32_t uint32_bignum_check_zero(uint32_t a[], uint32_t aWordLen);

/**
  * @brief  compare big integer a and b
  * @param  a: input, big integer a
  * @param  aWordLen: input, word length of a
  * @param  b: input, big integer b
  * @param  bWordLen: input, word length of b
  * @return 0:a=b,   1:a>b,   1: a<b
 */
int32_t uint32_bignum_cmp(uint32_t *a, uint32_t aWordLen, uint32_t *b, uint32_t bWordLen);

/**
  * @brief  for a = b*2^t, b is odd, get t
  * @param  a: big integer a
  * @note   make sure a != 0
  * @return number of multiple by 2, for a
 */
uint32_t get_multiple2_number(uint32_t a[]);

/**
  * @brief  a = a/(2^n)
  * @param  a: big integer a
  * @param  aWordLen: word length of a
  * @param  n: exponent of 2^n
  * @note   1. make sure aWordLen is real word length of a
  *         2. to make sure aWordLen1 is available, so data type of aWordLen is int32_t, not uint32_t
  *         3. please make sure aWordLen*32 is not less than n
  * @return word length of a = a/(2^n)
 */
uint32_t big_div2n(uint32_t a[], int32_t aWordLen, uint32_t n);

/**
  * @brief  check whether a is equal to 1 or not
  * @param  a: pointer to uint32_t big integer a
  * @param  aWordLen: word length of big integer a
  * @return 1(a is 1), 0(a is not 1)
 */
uint8_t bigint_check_1(uint32_t a[], uint32_t aWordLen);

/**
  * @brief  check whether a is equal to p1 or not
  * @param  a: pointer to uint32_t big integer a
  * @param  p: pointer to uint32_t big integer p, p must be odd
  * @param  wordLen: word length of a and p
  * @note   Make sure p is odd
  * @return 1(a is p1), 0(a is not p1)
 */
uint8_t bigint_check_p_1(uint32_t a[], uint32_t p[], uint32_t wordLen);

/**
  * @brief  check whether integer k is in [1, n1]
  * @param  k: input, big number k
  * @param  n: input, big number n
  * @param  wordLen: input, word length of k and n
  * @return ret_zero: k is zero
  *         ret_big: k is greater/bigger than or equal to n
  *         ret_success: k is in [1, n1]
 */
uint32_t uint32_integer_check(uint32_t *k, uint32_t *n, uint32_t wordLen, uint32_t ret_zero, uint32_t ret_big,
		uint32_t ret_success);

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* utility.h */


/**
  * @}
  */

/**
  * @}
  */
