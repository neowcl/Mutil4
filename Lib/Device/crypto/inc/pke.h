/**
* @file        pke.h
* @brief       This file contains all the functions prototypes for the PKE firmware library. 
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


#ifndef __PKE_H__
#define __PKE_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "crypto_reg.h"
#include "pke_common.h"
#include "eccp_curve.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup PKE
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup PKE_Exported_Types PKE Exported Types
  * @{
  */

/**
  * @brief PKE return code 
*/
typedef enum 
{
	PKE_SUCCESS = 0,
	PKE_STOP,
	PKE_NO_MODINV,
	PKE_NOT_ON_CURVE,
	PKE_INVALID_MC,
	PKE_ZERO_ALL,                   /*!< for ECCP input check */
	PKE_INTEGER_TOO_BIG,            /*!< for ECCP input check */
	PKE_INVALID_INPUT,
	PKE_ERROR,
}pke_return_code_t;

/**
  * @}
  */


/** @defgroup PKE_Exported_Constants PKE Exported Constants
  * @{
  */

#define SUPPORT_SM2
//#define SUPPORT_C25519

#ifdef SUPPORT_SM2
extern const eccp_curve_t sm2_curve[1];
#endif

#ifdef SUPPORT_C25519
extern const edward_curve_t ed25519[1];
#endif

#define PKE_RAM_GUARD

/**
  * @brief PKE register 
*/
#define PKE_CTRL           (*((volatile uint32_t *)(PKE_BASE)))
#define PKE_CFG            (*((volatile uint32_t *)(PKE_BASE+0x04)))
#define PKE_MC_PTR         (*((volatile uint32_t *)(PKE_BASE+0x08)))
#define PKE_RISR           (*((volatile uint32_t *)(PKE_BASE+0x0C)))
#define PKE_IMCR           (*((volatile uint32_t *)(PKE_BASE+0x10)))
#define PKE_MISR           (*((volatile uint32_t *)(PKE_BASE+0x14)))
#define PKE_RT_CODE        (*((volatile uint32_t *)(PKE_BASE+0x24)))
#define PKE_RAND_SEED      (*((volatile uint32_t *)(PKE_BASE+0x40)))
#define PKE_EXE_CONF       (*((volatile uint32_t *)(PKE_BASE+0x50)))
#define PKE_RC_EN          (*((volatile uint32_t *)(PKE_BASE+0x60)))
#define PKE_RC_KEY         (*((volatile uint32_t *)(PKE_BASE+0x64)))
#define PKE_RC_D_NONCE     (*((volatile uint32_t *)(PKE_BASE+0x68)))
#define PKE_RC_A_NONCE     (*((volatile uint32_t *)(PKE_BASE+0x6C)))
#define PKE_VERSION        (*((volatile uint32_t *)(PKE_BASE+0xFC)))
#define PKE_A(a, step)     ((volatile uint32_t *)(PKE_BASE+0x0400+(a)*(step)))
#define PKE_B(a, step)     ((volatile uint32_t *)(PKE_BASE+0x1000+(a)*(step)))

/**
  * @brief PKE register action offset
*/
#define PKE_START_CALC                        (1)

#define PKE_EXE_OUTPUT_AFFINE                 (0x10)
#define PKE_EXE_R1_MONT_R0_AFFINE             (0x09)
#define PKE_EXE_R1_MONT_R0_MONT               (0x0A)
#define PKE_EXE_R1_AFFINE_R0_AFFINE           (0x05)
#define PKE_EXE_R1_AFFINE_R0_MONT             (0x06)
#define PKE_EXE_ECCP_POINT_MUL                (PKE_EXE_OUTPUT_AFFINE + PKE_EXE_R1_AFFINE_R0_MONT)
#define PKE_EXE_ECCP_POINT_ADD                (PKE_EXE_OUTPUT_AFFINE + PKE_EXE_R1_AFFINE_R0_AFFINE)
#define PKE_EXE_ECCP_POINT_DBL                (PKE_EXE_OUTPUT_AFFINE + PKE_EXE_R1_MONT_R0_AFFINE)
#define PKE_EXE_ECCP_POINT_VER                (PKE_EXE_OUTPUT_AFFINE + PKE_EXE_R1_AFFINE_R0_MONT)

#define PKE_EXE_CFG_ALL_MONT                  (0x002A)
#define PKE_EXE_CFG_ALL_NON_MONT              (0x0000)
#define PKE_EXE_CFG_MODEXP_WITH_PUB           (0x0016)
#define PKE_EXE_CFG_MODEXP_WITHOUT_PUB        (0x0116)
#define PKE_EXE_CFG_MODEXP_MONT_LADDER        (0x0216)
#define PKE_EXE_CFG_MODEXP                    (0x0316)

/**
  * @brief PKE microcode 
*/
#define MICROCODE_PDBL                        (0x04)
#define MICROCODE_PADD                        (0x08)
#define MICROCODE_PVER                        (0x0C)
#define MICROCODE_PMUL                        (0x10)
#define MICROCODE_MODEXP                      (0x14)
#define MICROCODE_MODMUL                      (0x18)
#define MICROCODE_MODINV                      (0x1C)
#define MICROCODE_MODADD                      (0x20)
#define MICROCODE_MODSUB                      (0x24)
#define MICROCODE_MGMR_PRE                    (0x28)
#define MICROCODE_INTMUL                      (0x2C)
#define MICROCODE_Ed25519_PMUL                (0x30)
#define MICROCODE_Ed25519_PADD                (0x34)
#define MICROCODE_C25519_PMUL                 (0x38)

/**
  * @brief some PKE algorithm operand length
*/
#define OPERAND_MAX_BIT_LEN                   (4096)
#define OPERAND_MAX_WORD_LEN                  (GET_WORD_LEN(OPERAND_MAX_BIT_LEN))

#define ECCP_MAX_BIT_LEN                      (521)  /*!< ECC521 */
#define ECCP_MAX_BYTE_LEN                     (GET_BYTE_LEN(ECCP_MAX_BIT_LEN))
#define ECCP_MAX_WORD_LEN                     (GET_WORD_LEN(ECCP_MAX_BIT_LEN))

#define C25519_BYTE_LEN                       (256/8)
#define C25519_WORD_LEN                       (256/32)

#define Ed25519_BYTE_LEN                      C25519_BYTE_LEN
#define Ed25519_WORD_LEN                      C25519_WORD_LEN

#define MAX_RSA_WORD_LEN                      OPERAND_MAX_WORD_LEN
#define MAX_RSA_BIT_LEN                       (MAX_RSA_WORD_LEN<<5)
#define MIN_RSA_BIT_LEN                       (512)

/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup PKE_Exported_Functions PKE Exported Functions
  * @{
  */

/**
  * @brief  get pke IP version
  * @param none
  * @return pke IP version
 */
uint32_t pke_get_version(void);

/**
  * @brief  set operand width
  * @param  bitLen: input, bit length of operand
  * @note   Please make sure 0 < bitLen <= OPERAND_MAX_BIT_LEN
  * @return none
 */
void pke_set_operand_width(uint32_t bitLen);

/**
  * @brief  get current operand byte length
  * @param  none
  * @return current operand byte length
 */
uint32_t pke_get_operand_bytes(void);

/**
  * @brief  set exe config
  * @param  cfg: input, specific config value
  * @return none
 */
void pke_set_exe_cfg(uint32_t cfg);

/**
  * @brief  ainv = a^(1) mod modulus
  * @param  modulus: input, modulus
  * @param  a: input, integer a
  * @param  ainv: output, ainv = a^(1) mod modulus
  * @param  modWordLen: input, word length of modulus and ainv
  * @param  aWordLen: input, word length of a
  * @note   Please make sure aWordLen <= modWordLen <= OPERAND_MAX_WORD_LEN and a < modulus
  * @return PKE_SUCCESS(success), other(inverse not exists or error)
 */
uint32_t pke_modinv(const uint32_t *modulus, const uint32_t *a, uint32_t *ainv, uint32_t modWordLen,
		uint32_t aWordLen);

/**
  * @brief  out = (a+b) mod modulus
  * @param  modulus: input, modulus
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = a+b mod modulus
  * @param  wordLen: input, word length of modulus, a, b
  * @note   1. a,b must be less than modulus
  *         2. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modadd(const uint32_t *modulus, const uint32_t *a, const uint32_t *b,
		uint32_t *out, uint32_t wordLen);

/**
  * @brief  out = (ab) mod modulus
  * @param  modulus: input, modulus
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = ab mod modulus
  * @param  wordLen: input, word length of modulus, a, b
  * @note   1. a,b must be less than modulus
  *         2. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modsub(const uint32_t *modulus, const uint32_t *a, const uint32_t *b,
		uint32_t *out, uint32_t wordLen);

/**
  * @brief  out = (ab) mod modulus
  * @param  modulus: input, modulus
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = ab mod modulus
  * @param  wordLen: input, word length of modulus, a, b
  * @note   1. a,b must be less than modulus
  *         2. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modsub_ext(const uint32_t *modulus, const uint32_t *b,
		uint32_t *out, uint32_t wordLen);
/**
  * @brief  out = a+b
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = a+b
  * @param  wordLen: input, word length of a, b, out
  * @note   1. a+b may overflow
  *         2. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_add(const uint32_t *a, const uint32_t *b, uint32_t *out, uint32_t wordLen);

/**
  * @brief  out = ab
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = ab
  * @param  wordLen: input, word length of a, b, out
  * @note   1. please make sure a > b
  *         2. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_sub(const uint32_t *a, const uint32_t *b, uint32_t *out, uint32_t wordLen);

/**
  * @brief  out = a*b
  * @param  a: input, integer a
  * @param  a_wordLen: input, word length of a
  * @param  b: input, integer b
  * @param  b_wordLen: input, word length of b
  * @param  out: output, out = a*b
  * @param  out_wordLen input, word length of out
  * @note   1. please make sure out buffer word length is bigger than (2*max_bit_len(a,b)+0x1F)>>5
  *         2. please make sure a_wordLen/b_wordLen is not bigger than OPERAND_MAX_WORD_LEN/2
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_mul_internal(const uint32_t *a, const uint32_t *b, uint32_t *out, uint32_t a_wordLen, 
		uint32_t b_wordLen, uint32_t out_wordLen);

/**
  * @brief  out = a*b
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = a*b
  * @param  ab_wordLen: input, word length of a, b
  * @note   1. please make sure out buffer word length is bigger than (2*max_bit_len(a,b)+0x1F)>>5
  *         2. please make sure ab_wordLen is not bigger than OPERAND_MAX_WORD_LEN/2
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_mul(const uint32_t *a, const uint32_t *b, uint32_t *out, uint32_t ab_wordLen);

/**
  * @brief  calc H(R^2 mod modulus) and n0'(  modulus ^(1) mod 2^w ) for modMul,modExp, and pointMul. etc.
  *         here w is bit width of word, i,e. 32.
  * @param  modulus: input, modulus
  * @param  bitLen: input, bit length of modulus
  * @param  H: output, R^2 mod modulus
  * @param  n0: output,   modulus ^(1) mod 2^w, here w is 32 actually
  * @note   1. modulus must be odd
  *         2. please make sure word length of buffer H is equal to wordLen(word length of modulus),
  *            and n0 only need one word.
  *         3. bitLen must not be bigger than OPERAND_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_pre_calc_mont(const uint32_t *modulus, uint32_t bitLen, uint32_t *H, uint32_t *n0);

/**
  * @brief  like function pke_pre_calc_mont(), but this one is without output here
  * @param  modulus: input, modulus
  * @param  wordLen: input, word length of modulus
  * @note   1. modulus must be odd
  *         2. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_pre_calc_mont_no_output(const uint32_t *modulus, uint32_t wordLen);

/**
  * @brief  load modulus and precalculated mont parameters H(R^2 mod modulus) and n0'( modulus ^(1) mod 2^w) for hardware operation
  * @param  modulus: input, modulus
  * @param  modulus_h: input, R^2 mod modulus
  * @param  modulus_n0: input,  modulus ^(1) mod 2^w, here w is 32 actually
  * @param  bitLen: input, bit length of modulus
  * @note   1. modulus must be odd
  *         2. bitLen must not be bigger than OPERAND_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_load_modulus_and_pre_monts(uint32_t *modulus, uint32_t *modulus_h, uint32_t *modulus_n0, uint32_t bitLen);

/**
  * @brief  set modulus and precalculated mont parameters H(R^2 mod modulus) and n0'( modulus ^(1) mod 2^w) for hardware operation
  * @param  modulus: input, modulus
  * @param  modulus_h: input, R^2 mod modulus
  * @param  modulus_n0: input,  modulus ^(1) mod 2^w, here w is 32 actually
  * @param  bitLen: input, bit length of modulus
  * @note   1. modulus must be odd
  *         2. bitLen must not be bigger than OPERAND_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_set_modulus_and_pre_monts(uint32_t *modulus, uint32_t *modulus_h, uint32_t *modulus_n0, uint32_t bitLen);

/**
  * @brief  out = a*b (mod modulus)
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = a*b mod modulus
  * @param  wordLen: input, word length of modulus, a, b
  * @note   1. modulus must be odd
  *         2. a, b must less than modulus
  *         3. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  *         4. before calling this function, please make sure the modulus and the precalculated mont arguments
  *            of modulus are located in the right address.
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modmul_internal(const uint32_t *a, const uint32_t *b, uint32_t *out, uint32_t wordLen);

/**
  * @brief  out = a*b mod modulus
  * @param  modulus: input, modulus
  * @param  a: input, integer a
  * @param  b: input, integer b
  * @param  out: output, out = a*b mod modulus
  * @param  wordLen: input, word length of modulus, a, b
  * @note   1. modulus must be odd
  *         2. a, b must less than modulus
  *         3. wordLen must not be bigger than OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modmul(const uint32_t *modulus, const uint32_t *a, const uint32_t *b, uint32_t *out, uint32_t wordLen);

/**
  * @brief  mod exponent, this could be used for rsa encrypting,decrypting,signing,verifing.
  * @param  modulus: input, modulus
  * @param  exponent: input, exponent
  * @param  base: input, base number
  * @param  out: output, out = base^(exponent) mod modulus
  * @param  mod_wordLen: input, word length of modulus and base number
  * @param  exp_wordLen: input, word length of exponent
  * @note   1. before calling this function, please make sure the precalculated mont arguments of modulus are
  *           located in the right address
  *         2. modulus must be odd
  *         3. please make sure exp_wordLen <= mod_wordLen <= OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modexp(const uint32_t *modulus, const uint32_t *exponent, const uint32_t *base,
		uint32_t *out, uint32_t mod_wordLen, uint32_t exp_wordLen);

/**
  * @brief  c = a mod b
  * @param  a: input, integer a
  * @param  aWordLen: input, word length of integer
  * @param  b: input, integer b, modulus
  * @param  b_h: input, H parameter of b
  * @param  b_n0: input,  modulus ^(1) mod 2^w, here w is 32 actually
  * @param  bWordLen: input, word length of integer b and b_h
  * @param  c: output, c = a mod b
  * @note   1. b must be odd, and please make sure bWordLen is real word length of b
  *         2. real bit length of a can not be bigger than 2*(real bit length of b), so aWordLen can 
  *            not be bigger than 2*bWordLen
  *         3. pleae make sure aWordLen <= 2*OPERAND_MAX_WORD_LEN, bWordLen <= OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_mod(uint32_t *a, uint32_t aWordLen, uint32_t *b, uint32_t *b_h, uint32_t *b_n0, uint32_t bWordLen,
		uint32_t *c);

/**
  * @brief  ECCP curve point mul(random point), Q=[k]P
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  k: input, scalar
  * @param  Px: input, x coordinate of point P
  * @param  Py: input, y coordinate of point P
  * @param  Qx: output, x coordinate of point Q
  * @param  Qy: output, y coordinate of point Q
  * @note   1. please make sure k in [1,n1], n is order of ECCP curve
  *         2. please make sure input point P is on the curve
  *         3. please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  *         4. even if the input point P is valid, the output may be infinite point, in this case
  *            it will return error.
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t eccp_pointmul(eccp_curve_t *curve, uint32_t *k, uint32_t *Px, uint32_t *Py,
		uint32_t *Qx, uint32_t *Qy);

/**
  * @brief  ECCP curve point add, Q=P1+P2
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  P1x: input, x coordinate of point P1
  * @param  P1y: input, y coordinate of point P1
  * @param  P2x: input, x coordinate of point P2
  * @param  P2y: input, y coordinate of point P2
  * @param  Qx: output, x coordinate of point Q=P1+P2
  * @param  Qy: output, y coordinate of point Q=P1+P2
  * @note   1. please make sure input point P1 and P2 are both on the curve
  *         2. please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  *         3. even if the input point P1 and P2 are valid, the output may be infinite point,
  *            in this case it will return error.
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t eccp_pointadd(eccp_curve_t *curve, uint32_t *P1x, uint32_t *P1y, uint32_t *P2x, uint32_t *P2y,
		uint32_t *Qx, uint32_t *Qy);

//#define ECCP_POINT_DOUBLE   //not recommended to define
#ifdef ECCP_POINT_DOUBLE
uint32_t eccp_pointdouble(eccp_curve_t *curve, uint32_t *Px, uint32_t *Py, uint32_t *Qx, uint32_t *Qy);
#endif

/**
  * @brief  check whether the input point P is on ECCP curve or not
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  Px: input, x coordinate of point P
  * @param  Py: input, y coordinate of point P
  * @note   1. please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  *         2. after calculation, A1 and A2 will be changed!
  * @return PKE_SUCCESS(success, on the curve), other(error or not on the curve)
 */
uint32_t eccp_pointverify(eccp_curve_t *curve, uint32_t *Px, uint32_t *Py);

/**
  * @brief  get ECCP public key from private key(the key pair could be used in SM2/ECDSA/ECDH, etc.)
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  priKey: input, private key, bigendian
  * @param  pubKey: output, public key, bigendian
  * @note   Please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t eccp_get_pubkey_from_prikey(eccp_curve_t *curve, uint8_t *priKey, uint8_t *pubKey);

/**
  * @brief  get ECCP key pair(the key pair could be used in SM2/ECDSA/ECDH)
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  priKey: output, private key, bigendian
  * @param  pubKey: output, public key, bigendian
  * @note   Please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t eccp_getkey(eccp_curve_t *curve, uint8_t *priKey, uint8_t *pubKey);


#ifdef SUPPORT_C25519

/**
  * @brief  c25519 point mul(random point), Q=[k]P
  * @param  curve: input, c25519 curve struct pointer
  * @param  k: input, scalar
  * @param  Pu: input, u coordinate of point P
  * @param  Qu: output, u coordinate of point Q
  * @note   1. please make sure input point P is on the curve
  *         2. even if the input point P is valid, the output may be infinite point, in this case return error.
  *         3. please make sure the curve is c25519
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t x25519_pointmul(mont_curve_t *curve, uint32_t *k, uint32_t *Pu, uint32_t *Qu);

/**
  * @brief  edwards25519 curve point mul(random point), Q=[k]P
  * @param  curve: input, edwards25519 curve struct pointer
  * @param  k: input, scalar
  * @param  Px: input, x coordinate of point P
  * @param  Py: input, y coordinate of point P
  * @param  Qx: output, x coordinate of point Q
  * @param  Qy: output, y coordinate of point Q
  * @note   1. please make sure input point P is on the curve
  *         2. even if the input point P is valid, the output may be neutral point (0, 1), it is valid
  *         3. please make sure the curve is edwards25519
  *         4. k could not be zero now.
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t ed25519_pointmul(edward_curve_t *curve, uint32_t *k, uint32_t *Px, uint32_t *Py,
		uint32_t *Qx, uint32_t *Qy);

/**
  * @brief  edwards25519 point add, Q=P1+P2
  * @param  curve: input, edwards25519 curve struct pointer
  * @param  P1x: input, x coordinate of point P1
  * @param  P1y: input, y coordinate of point P1
  * @param  P2x: input, x coordinate of point P2
  * @param  P2y: input, y coordinate of point P2
  * @param  Qx: output, x coordinate of point Q=P1+P2
  * @param  Qy: output, y coordinate of point Q=P1+P2
  * @note   1. please make sure input point P1 and P2 are both on the curve
  *         2. the output point may be neutral point (0, 1), it is valid
  *         3. please make sure the curve is edwards25519
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t ed25519_pointadd(edward_curve_t *curve, uint32_t *P1x, uint32_t *P1y, uint32_t *P2x, uint32_t *P2y,
		uint32_t *Qx, uint32_t *Qy);

#endif

#ifdef PKE_SEC

/**
  * @brief  pke sec init
  * @param  none
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_sec_init(void);

/**
  * @brief  pke sec uninit
  * @param  none
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_sec_uninit(void);

/**
  * @brief  mod exponent, this could be used for rsa encrypting,decrypting,signing,verifing.
  * @param  modulus: input, modulus
  * @param  exponent: input, exponent
  * @param  base: input, base number
  * @param  out: output, out = base^(exponent) mod modulus
  * @param  mod_wordLen: input, word length of modulus and base number
  * @param  exp_wordLen: input, word length of exponent
  * @note   1. before calling this function, please make sure the precalculated mont arguments
  *            of modulus are located in the right address.
  *         2. modulus must be odd
  *         3. please make sure exp_wordLen <= mod_wordLen <= OPERAND_MAX_WORD_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modexp_ladder(const uint32_t *modulus, const uint32_t *exponent, const uint32_t *base,
		uint32_t *out, uint32_t mod_wordLen, uint32_t exp_wordLen);

/**
  * @brief  mod exponent with private key and public key, this could be used for rsa decrypting,signing.
  * @param  modulus: input, modulus
  * @param  exponent: input, exponent, actually private key d
  * @param  pub: input, public key e
  * @param  base: input, base number
  * @param  out: output, out = base^(exponent) mod modulus
  * @param  mod_wordLen: input, word length of modulus and base number
  * @param  exp_wordLen: input, word length of exponent
  * @param  pub_wordLen: input, word length of pub
  * @note   1. before calling this function, please make sure the precalculated mont arguments
  *            of modulus are located in the right address.
  *         2. modulus must be odd
  *         3. please make sure exp_wordLen <= mod_wordLen <= OPERAND_MAX_WORD_LEN
  *         4. please make sure pub_wordLen <= 2
  *         5. please make sure value of exponent should be bigger than 1
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modexp_with_pub(const uint32_t *modulus, const uint32_t *exponent, const uint32_t *pub, const uint32_t *base,
		uint32_t *out, uint32_t mod_wordLen, uint32_t exp_wordLen, uint32_t pub_wordLen);

/**
  * @brief  mod exponent, this could be used for rsa encrypting,decrypting,signing,verifing.
  * @param  modulus: input, modulus
  * @param  exponent: input, exponent, actually private key d
  * @param  base: input, base number
  * @param  out: output, out = base^(exponent) mod modulus
  * @param  mod_wordLen: input, word length of modulus and base number
  * @param  exp_wordLen: input, word length of exponent
  * @note   1. before calling this function, please make sure the precalculated mont arguments
  *            of modulus are located in the right address.
  *         2. modulus must be odd
  *         3. please make sure exp_wordLen <= mod_wordLen <= OPERAND_MAX_WORD_LEN
  *         4. please make sure value of exponent should be bigger than 1
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t pke_modexp_without_pub(const uint32_t *modulus, const uint32_t *exponent, const uint32_t *base,
		uint32_t *out, uint32_t mod_wordLen, uint32_t exp_wordLen);

/**
  * @brief  ECCP curve sec point mul, Q=[k]P, P is a random point on curve
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  k: input, scalar
  * @param  Px: input, x coordinate of point P
  * @param  Py: input, y coordinate of point P
  * @param  Qx: output, x coordinate of point Q
  * @param  Qy: output, y coordinate of point Q
  * @note   1. please make sure k in [1,n1], n is order of ECCP curve
  *         2. please make sure input point P is on the curve
  *         3. please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t eccp_pointmul_sec(eccp_curve_t *curve, uint32_t *k, uint32_t *Px, uint32_t *Py,
		uint32_t *Qx, uint32_t *Qy);


/**
  * @brief  ECCP curve sec point mul, Q=[k]P, P is a random point on curve
  * @param  curve: input, eccp_curve_t curve struct pointer
  * @param  k: input, scalar
  * @param  Px: input, x coordinate of point P
  * @param  Py: input, y coordinate of point P
  * @param  Qx: output, x coordinate of point Q
  * @param  Qy: output, y coordinate of point Q
  * @note   1. please make sure k in [1,n1], n is order of ECCP curve
  *         2. please make sure input point P is on the curve
  *         3. please make sure bit length of the curve is not bigger than ECCP_MAX_BIT_LEN
  * @return PKE_SUCCESS(success), other(error)
 */
uint32_t eccp_sdma_pointmul_sec(eccp_curve_t *curve, uint32_t *Px, uint32_t *Py,
		uint32_t *Qx, uint32_t *Qy);

#endif

/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* pke.h */


/**
  * @}
  */

/**
  * @}
  */
