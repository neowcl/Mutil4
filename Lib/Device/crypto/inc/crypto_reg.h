/**
* @file        crypto.h
* @brief       This file contains all the functions prototypes for the ECDH firmware library. 
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


#ifndef __CRYPTO_REG_H__
#define __CRYPTO_REG_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "stdint.h"
/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup CRYPTO_REG
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
#define PKE_BASE				(0x40020000  + 0x00004000)     /*!< PKE register base address */
#define HASH_BASE				(0x40020000  + 0x00007400)     /*!< HASH register base address */
#define TRNG_BASE				(0x40020000  + 0x00007800)     /*!< TRNG register base address */

#define DMA_RAM_BASE		    (0x20000000UL)   			   /*!< just for temporary use */

/***************************************************************************************************
 * @functions
***************************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* crypto_reg.h */


/**
  * @}
  */

/**
  * @}
  */
