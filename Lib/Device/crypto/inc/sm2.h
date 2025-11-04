/**
* @file        sm2.h
* @brief       This file contains all the functions prototypes for the SM2 firmware library. 
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


#ifndef __SM2_H__
#define __SM2_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "pke.h"
#include "hash.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup SM2
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SM2_Exported_Types SM2 Exported Types
  * @{
  */

/**
  * @brief SM2 error code
*/
typedef enum
{
	SM2_SUCCESS = 0,
	SM2_BUFFER_NULL = PKE_SUCCESS+0x40,
	SM2_NOT_ON_CURVE,
	SM2_EXCHANGE_ROLE_INVALID,
	SM2_INPUT_INVALID,
	SM2_ZERO_ALL,
	SM2_INTEGER_TOO_BIG,
	SM2_VERIFY_FAILED,
	SM2_DECRYPT_VERIFY_FAILED
}sm2_ret_code;

/**
  * @brief SM2 key exchange role
*/
typedef enum {
	SM2_Role_Sponsor = 0,
	SM2_Role_Responsor
} sm2_exchange_role_e;

/**
  * @brief SM2 ciphertext order
*/
typedef enum {
	SM2_C1C3C2   = 0,
	SM2_C1C2C3,
} sm2_cipher_order_e;

#ifdef PKE_SEC

#define SM2_SEC
#ifdef SM2_SEC

typedef enum
{
	SM2_SUCCESS_S   = 0x3E2FDB1A,
	SM2_ERROR_S     = 0xCBAD735E
}sm2_ret_code_s;

#endif
#endif

/**
  * @}
  */


/** @defgroup SM2_Exported_Constants SM2 Exported Constants
  * @{
  */

//#define SM2_HIGH_SPEED        //only available for PKE_HP

/**
  * @brief some sm2 length
*/
#define SM2_BIT_LEN               (256)
#define SM2_BYTE_LEN              (32)
#define SM2_WORD_LEN              (8)
#define SM3_DIGEST_BYTE_LEN       SM2_BYTE_LEN
#define SM2_MAX_ID_BYTE_LEN       (1<<13)

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SM2_Exported_Functions SM2 Exported Functions
  * @{
  */

/**
  * @brief  get SM2 Z value = SM3(bitLenofID||ID||a||b||Gx||Gy||Px||Py)
  * @param  ID: input, User ID
  * @param  byteLenofID: input, byte length of ID, must be less than 2^13
  * @param  pubKey: input, public key(0x04 + x + y), 65 bytes, bigendian
  * @param  Z: output, Z value, SM3 digest, 32 bytes
  * @note   1. bit length of ID must be less than 2^16, thus byte length must be less than 2^13
  *         2. if ID is NULL, then replace it with sm2 default ID
  *         3. please make sure the pubKey is valid
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_get_z(uint8_t *ID, uint32_t byteLenofID, uint8_t pubKey[65], uint8_t Z[32]);

/**
  * @brief  get SM2 E value = SM3(Z||M) (oneoff style)
  * @param  M     : input, Message
  * @param  byteLen: input, byte length of M
  * @param  Z     : input, Z value, 32 bytes
  * @param  E     : output, E value, 32 bytes
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_get_e(uint8_t *M, uint32_t byteLen, uint8_t Z[32], uint8_t E[32]);

//#define SM2_GETE_BY_STEPS
#ifdef SM2_GETE_BY_STEPS
/**
  * @brief  step 1 of getting SM2 E value(stepwise style), init
  * @param  ctx: input, hash_ctx_t context pointer
  * @param  Z: input, Z value, 32 bytes
  * @return SM2_SUCCESS(success), other(error)
 */
uint32_t sm2_get_e_init(hash_ctx_t *ctx, uint8_t Z[32]);

/**
  * @brief  step 2 of getting SM2 E value(stepwise style), update message
  * @param  ctx: input, hash_ctx_t context pointer
  * @param  msg: input, message
  * @param  msg_bytes: input, byte length of the input message
  * @note   Please make sure the three parameters are valid, and ctx is initialized
  * @return SM2_SUCCESS(success), other(error)
 */
uint32_t sm2_get_e_update(hash_ctx_t *ctx, uint8_t *msg, uint32_t msg_bytes);

/**
  * @brief  step 3 of getting SM2 E value(stepwise style), message update done, get the digest(SM2 E value)
  * @param  ctx: input, hash_ctx_t context pointer
  * @param  E: output, hash digest, SM2 E value
  * @note   1. please make sure the ctx is valid and initialized
  *         2. please make sure the digest buffer E is sufficient
  * @return SM2_SUCCESS(success), other(error)
 */
uint32_t sm2_get_e_final(hash_ctx_t *ctx, uint8_t E[32]);
#endif

/**
  * @brief  Generate SM2 public key from private key
  * @param  priKey: input, private key, 32 bytes, bigendian
  * @param  pubKey: output, public key(0x04 + x + y), 65 bytes, bigendian
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_get_pubkey_from_prikey(uint8_t priKey[32], uint8_t pubKey[65]);

/**
  * @brief  Generate SM2 random Key pair
  * @param  priKey: output, private key, 32 bytes, bigendian
  * @param  pubKey: output, public key(0x04 + x + y), 65 bytes, bigendian
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_getkey(uint8_t priKey[32], uint8_t pubKey[65]);

/**
  * @brief  Generate SM2 Signature
  * @param  E[32]: input, E value, 32 bytes, bigendian
  * @param  rand_k[32]: input, random big integer k in signing, 32 bytes, bigendian,
  *                     if you do not have this integer, please set this parameter to be NULL, it will be generated inside.
  * @param  priKey[32]: input, private key, 32 bytes, bigendian
  * @param  signature[64]: output, Signature r and s, 64 bytes, bigendian
  * @note   1. if you do not have rand_k, please set the parameter to be NULL, it will be generated inside.
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_sign(uint8_t E[32], uint8_t rand_k[32], uint8_t priKey[32], uint8_t signature[64]);

/**
  * @brief  Verify SM2 Signature
  * @param  E[32]: input, E value, 32 bytes, bigendian
  * @param  pubKey[65]: input, public key(0x04 + x + y), 65 bytes, bigendian
  * @param  signature[64]: input, Signature r and s, 64 bytes, bigendian
  * @return SM2_SUCCESS(success, the signature is valid); other(error or the signature is invalid)
 */
uint32_t sm2_verify(uint8_t E[32], uint8_t pubKey[65], uint8_t signature[64]);

/**
  * @brief  SM2 Encryption
  * @param  M: input, plaintext, MByteLen bytes, bigendian
  * @param  MByteLen: input, byte length of M
  * @param  rand_k[32]: input, random big integer k in encrypting, 32 bytes, bigendian,
  *                     if you do not have this integer, please set this parameter to be NULL, it will be generated inside.
  * @param  pubKey[65]: input, public key, 65 bytes, bigendian
  * @param  order: input, either SM2_C1C3C2 or SM2_C1C2C3
  * @param  C: output, ciphertext, CByteLen bytes, bigendian
  * @param  CByteLen: output, byte length of C, should be MByteLen+97 if success
  * @note   1. M and C can be the same buffer
  *         2. if you do not have rand_k, please set the parameter to be NULL, it will be generated inside.
  *         3. please make sure pubKey is valid
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_encrypt(uint8_t *M, uint32_t MByteLen, uint8_t rand_k[32], uint8_t pubKey[65],
		sm2_cipher_order_e order, uint8_t *C, uint32_t *CByteLen);

/**
  * @brief  SM2 Decryption
  * @param  C: input, ciphertext, CByteLen bytes, bigendian
  * @param  CByteLen: input, byte length of C, make sure MByteLen>97
  * @param  priKey[32]: input, private key, 32 bytes, bigendian
  * @param  M: output, plaintext, MByteLen bytes, bigendian
  * @param  MByteLen: output, byte length of M, should be CByteLen97 if success
  * @note   1. M and C can be the same buffer
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_decrypt(uint8_t *C, uint32_t CByteLen, uint8_t priKey[32],
		sm2_cipher_order_e order, uint8_t *M, uint32_t *MByteLen);

/**
  * @brief  SM2 Key Exchange
  * @param  role: input, SM2_Role_Sponsor  sponsor, SM2_Role_Responsor  responsor
  * @param  dA[32]: input, local's permanent private key
  * @param  PB[65]: input, peer's permanent public key
  * @param  rA[32]: input, local's temporary private key
  * @param  RA[65]: input, local's temporary public key
  * @param  RB[65]: input, peer's temporary public key
  * @param  ZA[32]: input, local's Z value
  * @param  ZB[32]: input, peer's Z value
  * @param  kByteLen: input, byte length of output key, should be less than (2^32  1)bit
  * @param  KA[kByteLen]: output, output key
  * @param  S1[32]: output, sponsor's S1, or responsor's S2, this is optional
  * @param  SA[32]: output, sponsor's SA, or responsor's SB, this is optional
  * @note   1. please make sure the inputs are valid
  *         2. S1 and SA are optional, if you don't need, please set S1 and SA as NULL
  *         3. in case that S1(S2) and SA(SB) exist, if S1=SB,S2=SA, then exchange success.
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_exchangekey(sm2_exchange_role_e role,
						uint8_t *dA, uint8_t *PB,
						uint8_t *rA, uint8_t *RA,
						uint8_t *RB,
						uint8_t *ZA, uint8_t *ZB,
						uint32_t kByteLen,
						uint8_t *KA, uint8_t *S1, uint8_t *SA);


#ifdef PKE_SEC

#define SM2_SEC
#ifdef SM2_SEC


/**
  * @brief  Generate SM2 Signature
  * @param  E[32]: input, E value, 32 bytes, bigendian
  * @param  rand_k[32]: input, random big integer k in signing, 32 bytes, bigendian,
  *                     if you do not have this integer, please set this parameter to be NULL, it will be generated inside.             
  * @param  priKey_addr: input, private key address use for SDMA transmission.
  * @param  signature[64]: output, Signature r and s, 64 bytes, bigendian
  * @note   If you do not have rand_k, please set the parameter to be NULL, it will be generated inside.
  * @return SM2_SUCCESS_S(success); other(error)
 */
uint32_t sm2_sdma_sign_s(uint8_t E[32], uint8_t rand_k[32], uint32_t priKey_addr, uint8_t signature[64]);

/**
  * @brief  Generate SM2 Signature
  * @param  E[32]: input, E value, 32 bytes, bigendian
  * @param  rand_k[32]: input, random big integer k in signing, 32 bytes, bigendian,
  *                     if you do not have this integer, please set this parameter to be NULL, it will be generated inside.             
  * @param  priKey[32]: input, private key, 32 bytes, bigendian
  * @param  signature[64]: output, Signature r and s, 64 bytes, bigendian
  * @note   If you do not have rand_k, please set the parameter to be NULL, it will be generated inside.
  * @return SM2_SUCCESS_S(success); other(error)
 */
uint32_t sm2_sign_s(uint8_t E[32], uint8_t rand_k[32], uint8_t priKey[32], uint8_t signature[64]);

/**
  * @brief  Verify SM2 Signature
  * @param  E[32]: input, E value, 32 bytes, bigendian
  * @param  pubKey[65]: input, public key(0x04 + x + y), 65 bytes, bigendian
  * @param  signature[64]: input, Signature r and s, 64 bytes, bigendian
  * @return SM2_SUCCESS_S(success, the signature is valid); other(error or the signature is invalid)
 */
uint32_t sm2_verify_s(uint8_t E[32], uint8_t pubKey[65], uint8_t signature[64]);

/**
  * @brief  SM2 Encryption
  * @param  M: input, plaintext, MByteLen bytes, bigendian
  * @param  MByteLen: input, byte length of M
  * @param  rand_k[32]: input, random big integer k in encrypting, 32 bytes, bigendian,
  *                     if you do not have this integer, please set this parameter to be NULL, it will be generated inside.
  * @param  pubKey[65]: input, public key, 65 bytes, bigendian
  * @param  order: input, either SM2_C1C3C2 or SM2_C1C2C3
  * @param  C: output, ciphertext, CByteLen bytes, bigendian
  * @param  CByteLen: output, byte length of C, should be MByteLen+97 if success
  * @note   1. M and C can be the same buffer
  *         2. if you do not have rand_k, please set the parameter to be NULL, it will be generated inside.
  *         3. please make sure pubKey is valid
  * @return SM2_SUCCESS_S(success); other(error)
 */
uint32_t sm2_encrypt_s(uint8_t *M, uint32_t MByteLen, uint8_t rand_k[32], uint8_t pubKey[65],
		sm2_cipher_order_e order, uint8_t *C, uint32_t *CByteLen);

/**
  * @brief  SM2 Decryption
  * @param  C: input, ciphertext, CByteLen bytes, bigendian
  * @param  CByteLen: input, byte length of C, make sure MByteLen>97
  * @param  priKey[32]: input, private key, 32 bytes, bigendian
  * @param  M: output, plaintext, MByteLen bytes, bigendian
  * @param  MByteLen: output, byte length of M, should be CByteLen97 if success
  * @note   M and C can be the same buffer
  * @return SM2_SUCCESS_S(success); other(error)
 */
uint32_t sm2_decrypt_s(uint8_t *C, uint32_t CByteLen, uint8_t priKey[32],
		sm2_cipher_order_e order, uint8_t *M, uint32_t *MByteLen);

/**
  * @brief  SM2 Decryption
  * @param  C: input, ciphertext, CByteLen bytes, bigendian
  * @param  CByteLen: input, byte length of C, make sure MByteLen>97
  * @param  priKey_addr: input, private key address use for SDMA transmission.
  * @param  M: output, plaintext, MByteLen bytes, bigendian
  * @param  MByteLen: output, byte length of M, should be CByteLen97 if success
  * @note   M and C can be the same buffer
  * @return SM2_SUCCESS_S(success); other(error)
 */
uint32_t sm2_sdma_decrypt_s(uint8_t *C, uint32_t CByteLen, uint32_t priKey_addr,
		sm2_cipher_order_e order, uint8_t *M, uint32_t *MByteLen);

/**
  * @brief  SM2 Key Exchange
  * @param  role: input, SM2_Role_Sponsor  sponsor, SM2_Role_Responsor  responsor
  * @param  dA[32]: input, local's permanent private key
  * @param  PB[65]: input, peer's permanent public key
  * @param  rA[32]: input, local's temporary private key
  * @param  RA[65]: input, local's temporary public key
  * @param  RB[65]: input, peer's temporary public key
  * @param  ZA[32]: input, local's Z value
  * @param  ZB[32]: input, peer's Z value
  * @param  kByteLen: input, byte length of output key, should be less than (2^32  1)bit
  * @param  KA[kByteLen]: output, output key
  * @param  S1[32]: output, sponsor's S1, or responsor's S2, this is optional
  * @param  SA[32]: output, sponsor's SA, or responsor's SB, this is optional
  * @note   1. please make sure the inputs are valid
  *         2. S1 and SA are optional, if you don't need, please set S1 and SA as NULL
  *         3. in case that S1(S2) and SA(SB) exist, if S1=SB,S2=SA, then exchange success.
  * @return SM2_SUCCESS_S(success); other(error)
 */
uint32_t sm2_exchangekey_s(sm2_exchange_role_e role,
						uint8_t *dA, uint8_t *PB,
						uint8_t *rA, uint8_t *RA,
						uint8_t *RB,
						uint8_t *ZA, uint8_t *ZB,
						uint32_t kByteLen,
						uint8_t *KA, uint8_t *S1, uint8_t *SA);

#endif
#endif
#ifdef SUPPORT_SM2
/**
  * @brief  a=a+1 (for 1+dA in SM2 signing)
  * @param  a: input, destination data
  * @param  wordLen: input, word length of data
  * @note   If a of wordLen words can not hold the carry, then the carry will be discarded,
  *         actually this is used in sm2 signing(1+dA)
  * @return none
 */
void uint32_BigNum_Add_One(uint32_t *a, uint32_t wordLen);

/**
  * @brief  SM2 kdf (for SM2 encrypting, decrypting and key exchange)
  * @param  in: input, sm2 kdf input
  * @param  inByteLen: input, byte length of in
  * @param  m: input, message, if no message, please set this para as NULL
  * @param  k: output, k = kdf(in) if m is NULL, or k = (kdf(in) XOR m) if m is available
  * @param  kByteLen: input, byte length of input m and output k
  * @return SM2_SUCCESS(success); other(error)
 */
uint32_t sm2_kdf_with_xor(uint8_t *in , uint32_t inByteLen, uint8_t *m, uint8_t *k, uint32_t kByteLen);


#endif
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* sm2.h */


/**
  * @}
  */

/**
  * @}
  */
