/**
* @file        cbm858xm_flash.h
* @brief       This file contains all the functions prototypes for the flash firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.12
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.12    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_FLASH_H__
#define __CBM858xM_FLASH_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm.h"


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup Flash_Exported_Types FLASH Exported Types
  * @{
  */

/** @struct flash_status_t
  * @brief Flash operate Status 
  */ 
typedef enum      
{
    FLASH_STATUS_ERROR    = 0,      /*!< Flash erase/program protection error */ 
    FLASH_STATUS_COMPLETE,          /*!< Flash Program complete */  
    FLASH_STATUS_TIMEOUT            /*!< Flash operate timeout */  
}flash_status_t;

/**
  * @}
  */


/** @defgroup Flash_Exported_Constants FLASH Exported Constants
  * @{
  */

/** 
  * @brief Flash OB byte address check
  */  
#define FLASH_OB_BYTE_ADDRESS_CHECK(address)     (((address) >= 0x1FFFF800) && ((address) <= 0x1FFFF810)) 

/** 
  * @brief FLASH_FUNC Definition
  */ 
#define FLASH_FUNC_FWUP              		  	     FMC_CFGU_FWUP_EN       	 	/*!< FLASH fast wake-up in deepsleep mode */

/** 
  * @brief Flash status flag and status check
  */
#define FLASH_FLAG_BUSY                          FMC_STS_BUSY                /*!< FLASH busy flag */  
#define FLASH_FLAG_PGERR                         FMC_STS_PGERR               /*!< FLASH programming error flag */  
#define FLASH_FLAG_WPERR                         FMC_STS_WPERR               /*!< FLASH write protected error flag */  
#define FLASH_FLAG_ENDF                          FMC_STS_ENDF                /*!< FLASH end of programming flag */

/** 
  * @brief Flash operate timeou value
  */ 
#define FLASH_OPERATE_TIMEOUT                    ((uint32_t)0x000B0000)      /*!< FLASH operate timeout */

/** 
  * @brief SWD port lock
  */
#define FLASH_OB_SWD_LOCK                        ((uint8_t)0x43)     		/*!< SWD port lock */  

/** 
  * @brief Boot lock
  */
#define EFUSE_BOOT_LOCK                        ((uint8_t)0x43)     		/*!< Boot lock */  

/** 
  * @brief Enable bootloader write protect
  */
#define EFUSE_BOOT_PROTECT                       ((uint32_t)0x00010000)     /*!< Enable bootloader write protect */  

/** 
  * @brief Enable RNG clock
  */
#define EFUSE_RNGCK_CFG                          ((uint32_t)0x00020000)     /*!< Disable RNG clock */  

/** 
  * @brief Lifecycle configure value
  */
#define LCS_CFG_VALUE                            ((uint32_t)0xAC53BC43)      /*!< Lifecycle configure value */     

#define EFUSE_LIFECYC_MODE_CHECK(mode)           (((mode) == FMC_STS2_LCSSTS_LEVEL0) || ((mode) == FMC_STS2_LCSSTS_LEVEL1) || \
                                                  ((mode) == FMC_STS2_LCSSTS_LEVEL2) || ((mode) == FMC_STS2_LCSSTS_LEVEL3))        

/**
  * @}
  */

/** @defgroup Flash_wait_counts FLASH wait counts
  * @{
  */
#define FMC_WCR_WCNT_0                          ((uint32_t)0x00000000)      /*!< FLASH wait 0 cycle */ 
#define FMC_WCR_WCNT_1                          FMC_WCR_WCNT                /*!< FLASH wati 1 cycle */  
/**
  * @}
  */
#define FMC_WCR_WCNT_CHECK(wcnt)                (((wcnt) == FMC_WCR_WCNT_0) || ((wcnt) == FMC_WCR_WCNT_1))

/** @defgroup Flash_Sector_Write_Protection  FLASH  Sector Write Protection 
  * @{
  */
#define FLASH_WPROT_NONE 						            ((uint32_t)0x00000000)		/*!< Disable write protection of all sectors */
#define FLASH_WPROT_SECTOR0	                	  ((uint32_t)0x00000001)   	/*!< Write protection of sector 0 */	  
#define FLASH_WPROT_SECTOR1		                  ((uint32_t)0x00000002)   	/*!< Write protection of sector 1 */	  
#define FLASH_WPROT_SECTOR2                		  ((uint32_t)0x00000004)   	/*!< Write protection of sector 2 */  
#define FLASH_WPROT_SECTOR3                		  ((uint32_t)0x00000008)   	/*!< Write protection of sector 3 */  
#define FLASH_WPROT_SECTOR4                		  ((uint32_t)0x00000010)   	/*!< Write protection of sector 4 */  
#define FLASH_WPROT_SECTOR5                		  ((uint32_t)0x00000020)   	/*!< Write protection of sector 5 */  
#define FLASH_WPROT_SECTOR6                		  ((uint32_t)0x00000040)   	/*!< Write protection of sector 6 */  
#define FLASH_WPROT_SECTOR7                		  ((uint32_t)0x00000080)   	/*!< Write protection of sector 7 */  
#define FLASH_WPROT_SECTOR8                		  ((uint32_t)0x00000100)   	/*!< Write protection of sector 8 */  
#define FLASH_WPROT_SECTOR9                		  ((uint32_t)0x00000200)   	/*!< Write protection of sector 9 */  
#define FLASH_WPROT_SECTOR10                	  ((uint32_t)0x00000400)   	/*!< Write protection of sector 10 */
#define FLASH_WPROT_SECTOR11                	  ((uint32_t)0x00000800)  	/*!< Write protection of sector 11 */
#define FLASH_WPROT_SECTOR12                	  ((uint32_t)0x00001000)   	/*!< Write protection of sector 12 */
#define FLASH_WPROT_SECTOR13                	  ((uint32_t)0x00002000)   	/*!< Write protection of sector 13 */
#define FLASH_WPROT_SECTOR14                	  ((uint32_t)0x00004000)   	/*!< Write protection of sector 14 */
#define FLASH_WPROT_SECTOR15                	  ((uint32_t)0x00008000)   	/*!< Write protection of sector 15 */
#define FLASH_WPROT_SECTOR16                    ((uint32_t)0x00010000)   	/*!< Write protection of sector 16 */
#define FLASH_WPROT_SECTOR17                    ((uint32_t)0x00020000)   	/*!< Write protection of sector 17 */
#define FLASH_WPROT_SECTOR18                    ((uint32_t)0x00040000)   	/*!< Write protection of sector 18 */
#define FLASH_WPROT_SECTOR19                    ((uint32_t)0x00080000)   	/*!< Write protection of sector 19 */
#define FLASH_WPROT_SECTOR20                    ((uint32_t)0x00100000)   	/*!< Write protection of sector 20 */
#define FLASH_WPROT_SECTOR21                    ((uint32_t)0x00200000)   	/*!< Write protection of sector 21 */
#define FLASH_WPROT_SECTOR22                    ((uint32_t)0x00400000)   	/*!< Write protection of sector 22 */
#define FLASH_WPROT_SECTOR23                    ((uint32_t)0x00800000)   	/*!< Write protection of sector 23 */
#define FLASH_WPROT_SECTOR24                    ((uint32_t)0x01000000)   	/*!< Write protection of sector 24 */
#define FLASH_WPROT_SECTOR25                    ((uint32_t)0x02000000)   	/*!< Write protection of sector 25 */
#define FLASH_WPROT_SECTOR26                    ((uint32_t)0x04000000)   	/*!< Write protection of sector 26 */
#define FLASH_WPROT_SECTOR27                    ((uint32_t)0x08000000)   	/*!< Write protection of sector 27 */
#define FLASH_WPROT_SECTOR28                    ((uint32_t)0x10000000)   	/*!< Write protection of sector 28 */
#define FLASH_WPROT_SECTOR29                    ((uint32_t)0x20000000)   	/*!< Write protection of sector 29 */
#define FLASH_WPROT_SECTOR30                    ((uint32_t)0x40000000)   	/*!< Write protection of sector 30 */
#define FLASH_WPROT_SECTOR31                    ((uint32_t)0x80000000)   	/*!< Write protection of sector 31 */
#define FLASH_WPROT_SECTOR_ALL                  ((uint32_t)0xFFFFFFFF)     	/*!< Write protection of all Sectors */
/**
  * @}
  */

/** @defgroup Flash_Option_BOOTCFG  FLASH Option Bytes bootloader size 
  * @{
  */ 
#define OB_BOOTCFG_16K                          ((uint8_t)0x00)             /*!< Configure Bootloader size 16KB */  
#define OB_BOOTCFG_32K                          ((uint8_t)0x02)             /*!< Configure Bootloader size 32KB */  
#define OB_BOOTCFG_64K                          ((uint8_t)0x03)             /*!< Configure Bootloader size 64KB */ 
/**
  * @}
  */
#define OB_BOOTCFG_SELECT_CHECK(source)         (((source) == OB_BOOTCFG_16K) || ((source) == OB_BOOTCFG_32K)||  \
                                                ((source) == OB_BOOTCFG_64K))

/** @defgroup Flash_Option_Bytes_FWDT  FLASH Option Bytes FWDT 
  * @{
  */ 
#define OB_FWDT_SW                              ((uint8_t)0x01)             /*!< Software FWDT selected */  
#define OB_FWDT_HW                              ((uint8_t)0x00)             /*!< Hardware FWDT selected */  
/**
  * @}
  */
#define OB_FWDT_SELECT_CHECK(source)            (((source) == OB_FWDT_SW) || ((source) == OB_FWDT_HW))

/** @defgroup Flash_Option_Bytes_DSM  FLASH Option Bytes STOP control by reset select. 
  * @{
  */    
#define OB_DSM_NO_RST                           ((uint8_t)0x02)             /*!< No reset generated when entering in DSM */  
#define OB_DSM_RST                              ((uint8_t)0x00)             /*!< Reset generated when entering in DSM */  
/**
  * @}
  */
#define OB_DSM_RST_SELECT_CHECK(source)         (((source) == OB_DSM_NO_RST) || ((source) == OB_DSM_RST))

/** @defgroup Flash_Option_Bytes_STDBY  FLASH Option Bytes STDBY control by reset select.
  * @{
  */  
#define OB_PWD_NO_RST                           ((uint8_t)0x04)             /*!< No reset generated when entering in PWD */  
#define OB_PWD_RST                              ((uint8_t)0x00)             /*!< Reset generated when entering in PWD */  
/**
  * @}
  */
#define OB_PWD_RST_SELECT_CHECK(source)         (((source) == OB_PWD_NO_RST) || ((source) == OB_PWD_RST))

/** @defgroup Flash_Option_Startup  FLASH Option Bytes startup mode 
  * @{
  */ 
#define FLASH_OB_STARTUP_BOOT                   ((uint8_t)0x00)             /*!< Startup from Bootloader */  
#define FLASH_OB_STARTUP_SRAM                   ((uint8_t)0x08)             /*!< Startup from SRAM */  
#define FLASH_OB_STARTUP_APROM                  ((uint8_t)0x18)             /*!< Startup from APROM */ 
/**
  * @}
  */
#define OB_STARTUP_CHECK(source)                (((source) == FLASH_OB_STARTUP_BOOT) || ((source) == FLASH_OB_STARTUP_SRAM)|| \
                                                ((source) == FLASH_OB_STARTUP_APROM))

/** @defgroup Flash_Option_VDDA  FLASH Option Bytes VDD detect 
  * @{
  */ 
#define FLASH_OB_VDDA_ON                        ((uint8_t)0x20)             /*!< Analog detecting on VDDA Power source ON */  
#define FLASH_OB_VDDA_OFF                       ((uint8_t)0x00)             /*!< Analog detecting on VDDA Power source OFF */  
/**
  * @}
  */
#define FLASH_OB_VDDA_CHECK(analog)             (((analog) == FLASH_OB_VDDA_ON) || ((analog) == FLASH_OB_VDDA_OFF))

/** @defgroup Flash_Option_SRAM_Parity FLASH Option Bytes SRAM Parity enable Set 
  * @{
  */
#define FLASH_OB_SRAM_PARITY_SET                ((uint8_t)0x00)             /*!< SRAM parity enable Set */  
#define FLASH_OB_SRAM_PARITY_RESET              ((uint8_t)0x40)             /*!< SRAM parity enable reset */  
/**
  * @}
  */
#define FLASH_OB_SRAM_PARITY_CHECK(parity)      (((parity) == FLASH_OB_SRAM_PARITY_SET) || ((parity) == FLASH_OB_SRAM_PARITY_RESET))

/** @defgroup Efuse_key_valid  securce key valid set 
  * @{
  */ 
#define EFUSE_SECURE_KEY1_VALID                 ((uint32_t)0x10000001)      /*!< Secure key 1 valid Set */  
#define EFUSE_SECURE_KEY1_INVALID               ((uint32_t)0x10000000)      /*!< Secure key 1 invalid Set */
#define EFUSE_SECURE_KEY2_VALID                 ((uint32_t)0x20000001)      /*!< Secure key 2 valid Set */
#define EFUSE_SECURE_KEY2_INVALID               ((uint32_t)0x20000000)      /*!< Secure key 2 invalid Set */
#define EFUSE_SECURE_KEY3_VALID                 ((uint32_t)0x30000001)      /*!< Secure key 3 valid Set */
#define EFUSE_SECURE_KEY3_INVALID               ((uint32_t)0x30000000)      /*!< Secure key 3 invalid Set */
 /**
  * @}
  */
 #define EFUSE_KEY_VALID_CHECK(valid)      (((valid) == EFUSE_SECURE_KEY1_VALID) || ((valid) == EFUSE_SECURE_KEY1_INVALID) || \
                                            ((valid) == EFUSE_SECURE_KEY2_VALID) || ((valid) == EFUSE_SECURE_KEY2_INVALID) || \
                                            ((valid) == EFUSE_SECURE_KEY3_VALID) || ((valid) == EFUSE_SECURE_KEY3_INVALID))

/** @defgroup RCU_Macro_function RCU Macro function definition
  * @{
  */

/**
  * @brief  Enables the FMC wait.
  * @param  None    
  * @return None
  */
#define __FLASH_WAIT_ENABLE()                   (FLASH->WCR |= FMC_WCR_WE)

/**
  * @brief  Disables the FMC wait.
  * @param  None    
  * @return None
  */
#define __FLASH_WAIT_DISABLE()                  (FLASH->WCR &= ~FMC_WCR_WE)

/**
  * @brief  Checks whether the FLASH wait status is set or not.
  * @param  None
  * @return Flash wait status (SET or RESET).
  */
#define __FLASH_WAIT_STATUS_GET()               ((FLASH->WCR & FMC_WCR_WS) ? SET : RESET)

/**
  * @brief  Enables the FLASH fast wake-up in deepsleep mode.      
  * @param  None.
  * @return None.
  */
#define __FLASH_FUNC_FWUP_ENABLE()              (FLASH->CFGU |= FLASH_FUNC_FWUP)

/**
  * @brief  Disables the FLASH fast wake-up in deepsleep mode.      
  * @param  None.
  * @return None.
  */
#define __FLASH_FUNC_FWUP_DISABLE()             (FLASH->CFGU &= ~FLASH_FUNC_FWUP)

/**
  * @brief  Update OB (option bytes).
  * @param  None
  * @return None
  */
#define __FLASH_OPT_UPDATE()                    (FLASH->CTR |= FMC_CTR_OBUPDATE)

/**
  * @brief  Get the FLASH User Option Bytes values.
  * @param  None
  * @return The flash User Option Bytes .
  */
#define __FLASH_OPT_USER_GET()                  ((uint8_t)(FLASH->OBSTS >> 8))

/**
  * @brief  Get the flash Write Protection Option Bytes value.
  * @param  None
  * @return Flash Write Protection Option Bytes register value(WPSTS).
  */
#define __FLASH_OPT_WRITE_PROTECT_GET()         (FLASH->WPSTS)

/**
  * @brief  Enables the specified flash interrupts.
  * @param  FLAG: specifies the FLASH interrupt sources.
  *         It can be any combination of the following values:
  *          @arg FMC_CTR_ENDIE(end of programming Interrupt)
  *          @arg FMC_CTR_ERRIE(Error Interrupt)
  * @return None 
  */
#define __FLASH_INTR_ENABLE(FLAG)           (FLASH->CTR |= FLAG)

/**
  * @brief  Disables the specified flash interrupts.
  * @param  FLAG: specifies the FLASH interrupt sources.
  *         It can be any combination of the following values:
  *          @arg FMC_CTR_ENDIE(end of programming Interrupt)
  *          @arg FMC_CTR_ERRIE(Error Interrupt)
  * @return None 
  */
#define __FLASH_INTR_DISABLE(FLAG)          (FLASH->CTR &= ~(FLAG))

/**
  * @brief  Checks whether the specified  flash interrupts is enabled or not.
  * @param  FLAG: specifies the FLASH interrupt sources enable get.
  *         It can be one of the following values:
  *          @arg FMC_CTR_ENDIE(end of programming Interrupt)
  *          @arg FMC_CTR_ERRIE(Error Interrupt)
  * @return SET or RESET
  */
#define __FLASH_INTR_ENABLE_GET(FLAG)       ((FLASH->CTR & FLAG) ? SET : RESET)

/**
  * @brief  Clears the FLASH's flags.
  * @param  FLAG: specifies the FLASH flags to clear.It can be any combination of the following values:
  *          @arg FLASH_FLAG_PGERR(FLASH Programming error flag flag)
  *          @arg FLASH_FLAG_WPERR(FLASH Write protected error flag)
  *          @arg FLASH_FLAG_ENDF(FLASH End of Programming flag)
  * @return None
  */
#define __FLASH_FLAG_CLEAR(FLAG)            (FLASH->STS = FLAG)

/**
  * @brief  Get the SWD disabled status. 
  * @param  FLAG: specifies the SWD disabled status.
  *         It can be the following values:
  *          @arg FMC_STS2_SWDLK_STS(SWD disabled status).
  * @return SET or RESET
  */
#define __FLASH_SWDLOCK_STAT_GET(FLAG)      ((FLASH->STS2 & FLAG) ? SET : RESET)

/**
  * @brief  Get the bootloader write protect status. 
  * @param  FLAG: specifies the bootloader write protect status.
  *         It can be the following values:
  *          @arg FMC_STS2_BTWRP_STS(bootloader write protect status).
  * @return SET or RESET
  */
#define __FLASH_BTWRP_STAT_GET(FLAG)        ((FLASH->STS2 & FLAG) ? SET : RESET)

/**
  * @brief  Get the Flash BIST sealing status. 
  * @param  FLAG: specifies the Flash BIST sealing status.
  *         It can be the following values:
  *          @arg FMC_STS2_FBSEAL_STS(Flash BIST sealing status).
  * @return SET or RESET
  */
#define __FLASH_FBSEAL_STAT_GET(FLAG)        ((FLASH->STS2 & FLAG) ? SET : RESET)

/**
  * @brief  Get the sealing of product information area status. 
  * @param  FLAG: specifies the sealing of product information area status.
  *         It can be the following values:
  *          @arg FMC_STS2_PDSEAL_STS(sealing of product information area status).
  * @return SET or RESET
  */
#define __FLASH_PDSEAL_STAT_GET(FLAG)        ((FLASH->STS2 & FLAG) ? SET : RESET)

/**
  * @brief  Get the TRNG power on self-test status. 
  * @param  FLAG: specifies the TRNG power on self-test status.
  *         It can be the following values:
  *          @arg FMC_STS2_TRNG_STS(sealing of product information area status).
  * @return SET or RESET
  */
#define __FLASH_TRNG_STAT_GET(FLAG)        ((FLASH->STS2 & FLAG) ? SET : RESET)

/**
  * @brief  Get the number of successful TRNG power on self-test.
  * @param  None
  * @return The flash User Option Bytes .
  */
#define __FLASH_TRNG_SUCCESS_NUM_GET()              ((uint8_t)((FLASH->STS2 >> 20)&0x0F))

/**
  * @}
  */



/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup FLASH_Exported_Functions FLASH Exported Functions
  * @{
  */

/**
  * @brief  Sets WCNT (wait conuter).
  * @param  counter: set wait count value. It can be one of the following values:
  *          @arg FMC_WCR_WCNT_0(0 cycle)
  *          @arg FMC_WCR_WCNT_1(1 cycle)
  * @note   For reading data from Flash memory, the number of wait states
  * @note   must be correctly programmed according to  the CPU clock (HCLK) 
  * @note   -------------------------------------------------
  *         |  Wait states      |   HCLK  frequency (MHz)   |
  *         |-------------------|---------------------------|
  *         |0WS(1CPU cycle)    |    0 < HCLK <= 24         |
  *         |1WS(2CPU cycle)    |    24 < HCLK <= 32        |
  *         -------------------------------------------------
  * @return None
  */
void flash_wait_counter_set(uint32_t counter);

/**
  * @brief  Unlock the flash control register and program memory access.
  * @param  None
  * @return None
  */
void flash_unlock(void);

/**
  * @brief  Lock the Program memory access.
  * @param  None
  * @return None
  */
void flash_lock(void);

/**
  * @brief  Erases a specified page in program memory. 
  *         The flash_unlock() function must be called before runing this function.
  * @param  page_addr: The page address in program memory to be erased.       
  * @return flash current status.         
  */
flash_status_t flash_page_erase(uint32_t page_addr);

/**
  * @brief  Erases all flash pages.
  *         The flash_unlock() function must be called before runing this function.
  * @param  None
  * @return flash status.
  */
flash_status_t flash_all_pages_erase(void);

/**
  * @brief  Programs a word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t flash_word_program(uint32_t addr, uint32_t value);

/**
  * @brief  Programs a half word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t flash_half_word_program(uint32_t addr, uint16_t value);

/**
  * @brief  Unlocks option bytes block access.
  * @param  None
  * @return None
  */
void flash_option_bytes_unlock(void);

/**
  * @brief  Locks option bytes block access
  * @param  None
  * @return None
  */
void flash_option_bytes_lock(void);

/**
  * @brief  Erases all option bytes except the Read protection (RPROT).
  *         The flash_option_bytes_unlock() function must be called before runing this function.   
  * @param  None
  * @return flash status.
  */
flash_status_t flash_option_bytes_erase(void);

/**
  * @brief  Configure the Bootloader space. The flash_option_bytes_unlock() function 
  *         must be called before runing this function.
  * @param  set_value: This parameter can be a combination of 
  *         one of @arg OB_BOOTCFG_16K(Bootloader size 16KB)
  *                @arg OB_BOOTCFG_32K(Bootloader size 32KB)
  *                @arg OB_BOOTCFG_64K(Bootloader size 64KB)
  * @return flash status.
  */
flash_status_t flash_option_bytes_bootspace_set(uint8_t value);

/**
  * @brief  Programs the FLASH User Option Byte, It can be FWDT_SW, RST_DSM, RST_PWD,
  *         BOOT1 and VDDA detection. The flash_option_bytes_unlock() function must be called before runing
  *         this function.
  * @param  set_value: This parameter must be a combination of the following parameters:
  *         one of @arg OB_FWDT_HW(Hardware WDG selected), 
  *                @arg OB_FWDT_SW(Software WDG selected), and 
  *         one of @arg OB_DSM_RST(reset generated when entering in DSM), 
  *                @arg OB_DSM_NO_RST(No reset generated when entering in DSM) and 
  *         one of @arg OB_PWD_NO_RST(reset generated when entering in PWD), 
  *                @arg OB_PWD_RST(reset generated when entering in PWD) and
  *         one of @arg FLASH_OB_STARTUP_BOOT(Startup from Bootloader)
  *                @arg FLASH_OB_STARTUP_SRAM(Startup from SRAM)
  *                @arg FLASH_OB_STARTUP_APROM(Startup from APROM) and
  *         one of @arg FLASH_OB_VDDA_ON(Analog monitoring on VDDA Power source ON),
  *                @arg FLASH_OB_VDDA_OFF(Analog monitoring on VDDA Power source OFF) and 
  *         one of @arg FLASH_OB_SRAM_PARITY_SET(SRAM Parity SET),
  *                @arg FLASH_OB_SRAM_PARITY_RESET(SRAM Parity RESET).
  *	@note	If only one bit is configured, other bits will be cleared.
  * @return flash status.
  */
flash_status_t flash_option_bytes_user_set(uint8_t value);

/**
  * @brief  Write protects (WPROT) the desired pages.
  *         The flash_option_bytes_unlock() function must be called before runing this function.  
  * @param  set_value: specifies the address of the pages to be write protected.
  *          It can be any combinations of the following values:
  *           @arg FLASH_WPROT_NONE (Disable write protection of all sectors)    
  *           @arg FLASH_WPROT_SECTOR0 (Write protection of sector 0)  
  *           @arg FLASH_WPROT_SECTOR1 (Write protection of sector 1)   
  *           @arg FLASH_WPROT_SECTOR2 (Write protection of sector 2)   
  *           @arg FLASH_WPROT_SECTOR3 (Write protection of sector 3)  
  *           @arg FLASH_WPROT_SECTOR4 (Write protection of sector 4)  
  *           @arg FLASH_WPROT_SECTOR5 (Write protection of sector 5)  
  *           @arg FLASH_WPROT_SECTOR6 (Write protection of sector 6)  
  *           @arg FLASH_WPROT_SECTOR7 (Write protection of sector 7)  
  *           @arg FLASH_WPROT_SECTOR8 (Write protection of sector 8)  
  *           @arg FLASH_WPROT_SECTOR9 (Write protection of sector 9)  
  *           @arg FLASH_WPROT_SECTOR10 (Write protection of sector 10)  
  *           @arg FLASH_WPROT_SECTOR11 (Write protection of sector 11)  
  *           @arg FLASH_WPROT_SECTOR12 (Write protection of sector 12)  
  *           @arg FLASH_WPROT_SECTOR13 (Write protection of sector 13)  
  *           @arg FLASH_WPROT_SECTOR14 (Write protection of sector 14)  
  *           @arg FLASH_WPROT_SECTOR15 (Write protection of sector 15)
  *           @arg FLASH_WPROT_SECTOR16 (Write protection of sector 16)  
  *           @arg FLASH_WPROT_SECTOR17 (Write protection of sector 17)   
  *           @arg FLASH_WPROT_SECTOR18 (Write protection of sector 18)   
  *           @arg FLASH_WPROT_SECTOR19 (Write protection of sector 19)  
  *           @arg FLASH_WPROT_SECTOR20 (Write protection of sector 20)  
  *           @arg FLASH_WPROT_SECTOR21 (Write protection of sector 21)  
  *           @arg FLASH_WPROT_SECTOR22 (Write protection of sector 22)  
  *           @arg FLASH_WPROT_SECTOR23 (Write protection of sector 23)  
  *           @arg FLASH_WPROT_SECTOR24 (Write protection of sector 24)  
  *           @arg FLASH_WPROT_SECTOR25 (Write protection of sector 25)  
  *           @arg FLASH_WPROT_SECTOR26 (Write protection of sector 26)  
  *           @arg FLASH_WPROT_SECTOR27 (Write protection of sector 27)  
  *           @arg FLASH_WPROT_SECTOR28 (Write protection of sector 28)  
  *           @arg FLASH_WPROT_SECTOR29 (Write protection of sector 29)  
  *           @arg FLASH_WPROT_SECTOR30 (Write protection of sector 30)  
  *           @arg FLASH_WPROT_SECTOR31 (Write protection of sector 31)  
  *           @arg FLASH_WPROT_SECTOR_ALL (Write protection of all sectors)   
  * @return flash status. 
  */
flash_status_t flash_option_bytes_write_protect_enable(uint32_t value);

/**
  * @brief  Lock the SWD port. 
  * @note   The flash_option_bytes_unlock() function must be called before runing this function.
  * @note   This function valid only during product development
  * @param  value: specifies the data to be programmed,it can be FLASH_OB_SWD_LOCK.
  * @return flash status.
  */
flash_status_t flash_option_bytes_swd_lock_set(uint8_t value);

/**
  * @brief  Programs a half word at a specified Option Byte address.
  * @note   The flash_option_bytes_unlock() function must be called before runing this function.
  * @note   Call the flash_option_bytes_lock() to disable the flash register access and the option bytes.   
  * @param  addr: specifies the address to be programmed can be 0x1FFFF800 to 0x1FFFF80E.
  * @param  value: specifies the data to be programmed.
  * @return flash status.
  */
flash_status_t flash_option_bytes_set(uint32_t addr, uint8_t value);

/**
  * @brief  eFuse erases a specified page in program memory. 
  *         The flash_unlock() function must be called before runing this function.
  * @param  page_addr: The page address in program memory to be erased.       
  * @return flash current status.         
  */
flash_status_t efuse_page_erase(uint32_t page_addr);

/**
  * @brief  eFuse programs a half word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t efuse_half_word_program(uint32_t addr, uint16_t value);

/**
  * @brief  eFuse programs a word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t efuse_word_program(uint32_t addr, uint32_t value);

/**
  * @brief  eFuse key calculation CRC32. 
  *         The flash_unlock() function must be called before runing this function.
  * @param  crc_value: Get the calacluation CRC32 result, if the calucaltion fails, the result is 0.
  * @return flash current status.
  */
flash_status_t efuse_key_crc32_calc(uint32_t* crc_value);

/**
  * @brief  eFuse lifecycle set, chip have four lifecycle, as follows: chip manufacturing(default), product development,
  *         user phase and self destruction phase.
  *         The flash_unlock() and flash_option_bytes_unlock() function must be called before runing this function.
  * @param  lcs_mode: lifecycle mode, it can be one of the following values:
  *          @arg FMC_STS2_LCSSTS_LEVEL1 (Lifecycle product development)
  *          @arg FMC_STS2_LCSSTS_LEVEL2 (Lifecycle user phase)
  *          @arg FMC_STS2_LCSSTS_LEVEL3 (Lifecycle self destruction phase)
  * @note   The lifecycle value write only once, the update takes effect only after power on reset or setting OBUPDATE.
  * @return flash current status.         
  */
flash_status_t efuse_lifecycle_set(uint32_t lcs_mode);

/**
  * @brief  eFuse secure key valid set
  *         The flash_unlock() and flash_option_bytes_unlock() function must be called before runing this function.
  * @param  valid_data: valid data, it can be one of the following values:
  *          @arg EFUSE_SECURE_KEY1_VALID (Secure key 1 valid)
  *          @arg EFUSE_SECURE_KEY1_INVALID (Secure key 1 invalid)
  *          @arg EFUSE_SECURE_KEY2_VALID (Secure key 2 valid)
  *          @arg EFUSE_SECURE_KEY2_INVALID (Secure key 2 invalid)
  *          @arg EFUSE_SECURE_KEY3_VALID (Secure key 3 valid)
  *          @arg EFUSE_SECURE_KEY3_INVALID (Secure key 3 invalid)
  * @note   The valid_data can only be written once.
  * @return flash current status.         
  */
flash_status_t efuse_secure_key_valid_set(uint32_t valid_data);

/**
  * @brief  Configure the EFUSE option area.
  *         The flash_unlock() and flash_option_bytes_unlock() function must be called before runing this function.
  * @param  The value support combination ,it can be set the following values:
  *          @arg EFUSE_BOOT_LOCK: The chip can only be started from the Bootloader and is not controlled by other option bytes.
  *          @arg EFUSE_BOOT_PROTECT: Enable bootloader write protect.
  *          @arg EFUSE_RNGCK_CFG: Disable RNG clock.
  * @note   This function write only once.
  * @return flash current status.         
  */
flash_status_t efuse_option_area_cfg(uint32_t value);

/**
  * @brief  Programs a half word at a specified Option Byte address.
  * @note   The flash_option_bytes_unlock() function must be called before runing this function.
  * @note   Call the flash_option_bytes_lock() to disable the flash register access and the option bytes.   
  * @param  addr: specifies the address to be programmed can be 0x1FFFF800 to 0x1FFFF80E.
  * @param  value: specifies the data to be programmed.
  * @return flash status.
  */
flash_status_t flash_option_bytes_set(uint32_t addr, uint8_t value);

/**
  * @brief  Waits for a FLASH operation to complete or  delay timeout.
  * @param  counter: FLASH programming Timeout
  * @return flash status.
  */
flash_status_t flash_operation_wait(uint32_t counter);

/**@brief Get the unique id, it size is 12 bytes.
 * @param  buf: Specifies the data to be read.
 * @return Is the UID valid, 1: valid, 0: invalid.
 */
uint8_t flash_unique_id_get(uint8_t *buf);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_flash.h */


/**
  * @}
  */

/**
  * @}
  */
