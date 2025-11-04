/**
* @file        cbm858xm_sdma.c
* @brief       This file provides all the basic SDMA firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.20
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.20    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_sdma.h"

/***************************************************************************************************
 * @definitions
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup SDMA SDMA
  * @brief    SDMA driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @function
***************************************************************************************************/

/**
 * @brief       Deinitializes the SDMA  registers to their default reset values.
 * @param       ptr_sdma: Pointer to sdma_reg_t containing the SDMA registers.
 * @return      None.        
 */
void sdma_def_init(sdma_reg_t * ptr_sdma)
{
    /* Reset SDMA register value. */
    ptr_sdma->CFG  = (uint32_t)0x00000000;
    ptr_sdma->CR   = (uint32_t)0x00000000;
    ptr_sdma->SRC  = (uint32_t)0x1F000000;
    ptr_sdma->PKEA = (uint32_t)0x00000400;
}

/**
 * @brief       Deinitializes the SDMA  registers according to the specified parameters in the ptr_config_struct.
 * @param       ptr_sdma: Pointer to sdma_reg_t containing the SDMA registers.This parameter can be SDMA.
 * @param       ptr_config_struct: Pointer to a sdma_config_t structure containing the configuration.
 * @return      None.        
 */
void sdma_init(sdma_reg_t * ptr_sdma,sdma_config_t * ptr_config_struct)
{
    uint32_t reg = 0;
    
//    ASSERT(SDMA_CHECK(ptr_sdma));
//    ASSERT(SDMA_SIZE_CHECK(ptr_config_struct->buf_size));
//    ASSERT(SDMA_SRC_ADDR_CHECK(ptr_config_struct->src_addr));
//    ASSERT(SDMA_DST_TARGET_CHECK(ptr_config_struct->dst_addr));

    /* Configure SDMA_CFG SIZE */
    reg |= (ptr_config_struct->buf_size) << 16;

    /* Configure SDMA_CFG DST */
    reg |= ptr_config_struct->dst_addr;

    ptr_sdma->CFG = reg;

    /* Configure SDMA_SRC */
    ptr_sdma->SRC = ptr_config_struct->src_addr;

    return;      
}

/**
 * @brief  Use the SDMA transmission data.
 * @param  src_addr: source address
 * @param  src_addr: destination address
 * @param  size: SDMA transmission bytes size.
 * @return None
 */
void sdma_transmit_data(uint32_t src_addr,uint32_t dis_addr, uint32_t size)
{
    sdma_config_t  ptr_config;
    
    *(uint32_t*)0x40021014 |= 0x00000002;  // SDMA clock enable 

    ptr_config.src_addr = src_addr;
    ptr_config.dst_addr = 0;
    ptr_config.buf_size = size;
    sdma_init(SDMA,&ptr_config);

    __SDMA_PKE_ADDR_SET(dis_addr);
    __SDMA_ENABLE();
    __SDMA_START_ENABLE();

    while(__SDMA_FLAG_STATUS_GET() != 1);
    __SDMA_DISABLE();
    
    *(uint32_t*)0x40021014 &= 0xFFFFFFFD;  // SDMA clock disable 
}
///@endcond

/**
  * @}
  */

/**
  * @}
  */
