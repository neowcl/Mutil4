/**
* @file        cbm858xm_sdma.h
* @brief       This file contains all the functions prototypes for the SDMA firmware library. 
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


#ifndef __CBM858xM_SDMA_H__
#define __CBM858xM_SDMA_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
//#include "cbm858xm.h"
#include "stdint.h"

/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup SDMA
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SDMA_Exported_Types SDMA Exported Types
  * @{
  */

/** @struct sdma_reg_t
  * @brief SDMA Registers structure definition
  */
typedef struct 
{
    volatile    uint32_t CFG;               /*!< SDMA configuration register */
    volatile    uint32_t SRC;               /*!< SDMA source data register */
    volatile    uint32_t CR;                /*!< SDMA control register */
    volatile    uint32_t PKEA;              /*!< SDMA destination address register */
}sdma_reg_t;


/** 
  * @brief SDMA configuration structures definition.
  */
typedef struct
{
    uint32_t        src_addr;       /*!< Specifies SDMA source data address to be transferred from. This address
                                         must between the EFUSE address. */
    uint32_t        dst_addr;       /*!< Specifies SDMA destination data address. */
    uint32_t        buf_size;       /*!< The number of data transferred by the specifies SDMA. 
                                         When dst_addr is for SWDT,buf_size can be a value between 0 and 32; 
                                         When dst_addr is for PKE or SKE,buf_size can be a 10-bit value that 
                                         the last two bits should be 0. */
}sdma_config_t;
/**
  * @}
  */


/** @defgroup SDMA_Exported_Constants SDMA Exported Constants
  * @{
  */

#define SDMA_BASE                       (0x40020000  + 0x00003C00)     /*!< SDMA register base address */

#define SDMA                            ((sdma_reg_t *)         SDMA_BASE)     /*!< SDMA module base address. */ 


/*----------------------------------------------------------------------------*/
/*                 Security DMA Controller(SDMA)                              */
/*----------------------------------------------------------------------------*/
/**
  * @brief SDMA_CFG register Bit definition
  */
#define SDMA_CFG_START                        ((uint16_t)0x00000001)       /*!< SDMA transfer enable */
#define SDMA_CFG_EOF                          ((uint16_t)0x00000002)       /*!< SDMA transfer over flag */

#define SDMA_CR_EN                            ((uint16_t)0x00000001)       /*!< SDMA enable control */
#define SDMA_CR_ICE                           ((uint16_t)0x00000002)       /*!< SDMA interrupt enable */


#define SDMA_DST_PKE                    ((uint32_t)0x00000000)      /*!< Transfer to PKE. */

/*!< SDMA check. */
#define SDMA_CHECK(sdma)                (((sdma) == SDMA))
/*!< SDMA SIZE check. */
#define SDMA_SIZE_CHECK(size)           (((size) <= 0xFFC) && ((size) >= 0))
/*!< SDMA SRC address check. */
#define SDMA_SRC_ADDR_CHECK(addr)       (((addr) <= 0x1F000FFF) && ((addr) >= 0x1F000000))
/*!< SDMA dst target check. */
#define SDMA_DST_TARGET_CHECK(target)   ((target) == SDMA_DST_PKE)



/**
  * @}
  */

/** @defgroup SDMA_Macro_function SDMA Macro function definition
  * @{
  */

/**
  * @brief  Enables transfer the SDMA, if the SDMA disable or transmit size is 0, this configuration is invalid .
  * @param  None.
  * @return None.
  */
#define __SDMA_START_ENABLE()                   (SDMA->CFG |= SDMA_CFG_START) 

/**
  * @brief  Disable transfer the SDMA.
  * @param  None.
  * @return None.
  */
#define __SDMA_START_DISABLE()                  (SDMA->CFG &= ~SDMA_CFG_START) 

/**
  * @brief  Enables the SDMA peripheral.
  * @param  None.
  * @return None.
  */
#define __SDMA_ENABLE()                         (SDMA->CR |= SDMA_CR_EN) 

/**
  * @brief  Disable the SDMA peripheral.
  * @param  None.
  * @return None.
  */
#define __SDMA_DISABLE()                        (SDMA->CR &= ~SDMA_CR_EN) 

/**
  * @brief  Enables the SDMA interrupt.
  * @param  None.
  * @return None.
  */
#define __SDMA_INTR_ENABLE()                    (SDMA->CR |= SDMA_CR_ICE) 

/**
  * @brief  Disable the SDMA interrupt.
  * @param  None.
  * @return None.
  */
#define __SDMA_INTR_DISABLE()                   (SDMA->CR &= ~SDMA_CR_ICE) 

/**
  * @brief  Enables the SDMA interrupt.
  * @param  None.
  * @return None.
  */
#define __SDMA_FLAG_STATUS_GET()                (((SDMA->CFG) & (SDMA_CFG_EOF)) ? 1 : 0)

/**
  * @brief  Set the SDMA source address.
  * @param  addr: This address must between the EFUSE address(0x1F00 0000 - 0x1F00 0FFF).
  * @return None.
  */
#define __SDMA_SRC_ADDR_SET(addr)               (SDMA->SRC = addr) 

/**
  * @brief  Get the SDMA source address.
  * @param  None
  * @return SDMA source address.
  */
#define __SDMA_SRC_ADDR_GET()                   (SDMA->SRC) 

/**
  * @brief  Set the SDMA PKE address.
  * @param  addr: addr: This address must between the specified address.
  * @return None.
  */
#define __SDMA_PKE_ADDR_SET(addr)               (SDMA->PKEA = addr) 


/**
  * @brief  Get the SDMA PKE address, the default address is 0x00000400.
  * @param  None.
  * @return PKE address.
  */
#define __SDMA_PKE_ADDR_GET()                   (SDMA->PKEA) 

/**
  * @}
  */

/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SDMA_Exported_Functions SDMA Exported Functions
  * @{
  */

/**
 * @brief       Deinitializes the SDMA  registers to their default reset values.
 * @param       ptr_sdma: Pointer to sdma_reg_t containing the SDMA registers.
 * @return      None.        
 */
void sdma_def_init(sdma_reg_t * ptr_sdma);

/**
 * @brief       Deinitializes the SDMA  registers according to the specified parameters in the ptr_config_struct.
 * @param       ptr_sdma: Pointer to sdma_reg_t containing the SDMA registers.This parameter can be SDMA.
 * @param       ptr_config_struct: Pointer to a sdma_config_t structure containing the configuration.
 * @return      None.        
 */
void sdma_init(sdma_reg_t * ptr_sdma,sdma_config_t * ptr_config_struct);

/**
 * @brief  Configure the SDMA source and destination addresses.
 * @param  src_addr: source address
 * @param  src_addr: destination address
 * @param  size: SDMA transmission bytes size.
 * @return None
 */
void sdma_transmit_data(uint32_t src_addr,uint32_t dis_addr, uint32_t size);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_sdma.h */


/**
  * @}
  */

/**
  * @}
  */
