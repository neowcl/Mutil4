/**
* @file        cbm858xm_flash.c
* @brief       This file provides all the basic FLASH firmware functions.
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


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include  "cbm858xm_flash.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/
#define FLASH_UID_START_ADDR    0x1FFFFCA0  /*!< Flash UID start address */  
#define FLASH_UID_SUM_ADDR      0x1FFFFC9C  /*!< Flash UID sum address */  

/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup FLASH
  * @brief    FLASH driver modules
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
  *         |1WS(2CPU cycle)    |    24 < HCLK <= 48        |
  *         -------------------------------------------------
  * @return None
  */
void flash_wait_counter_set(uint32_t counter)
{
    ASSERT(FMC_WCR_WCNT_CHECK(counter));
    
    MODIFY_REG(FLASH->WCR, FMC_WCR_WCNT, counter);
}

/**
  * @brief  Unlock the flash control register and program memory access.
  * @param  None
  * @return None
  */
void flash_unlock(void)
{
    if((FLASH->CTR & FMC_CTR_LOCK) != RESET)
    {
        /* Unlocking the program memory access */
        FLASH->CCODE = FMC_CCODE_VALUE1;
        FLASH->CCODE = FMC_CCODE_VALUE2;
    }
}

/**
  * @brief  Lock the Program memory access.
  * @param  None
  * @return None
  */
void flash_lock(void)
{
    /* Set the lock bit*/
    FLASH->CTR |= FMC_CTR_LOCK;
}

/**
  * @brief  Erases a specified page in program memory. 
  *         The flash_unlock() function must be called before runing this function.
  * @param  page_addr: The page address in program memory to be erased.       
  * @return flash current status.         
  */
flash_status_t flash_page_erase(uint32_t page_addr)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
  
    if(status == FLASH_STATUS_COMPLETE)
    { 
        /* If the previous operation is completed, proceed to erase the page */
        FLASH->CTR |= FMC_CTR_PERS;
        FLASH->ERSADR  = page_addr;
        FLASH->CTR |= FMC_CTR_START;
        
        /* Wait for last operation to be completed */
        status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
    
        /* Disable the PERS Bit */
        FLASH->CTR &= ~FMC_CTR_PERS;
    }
    
    /* Return the Erase Status */
    return status;
}

/**
  * @brief  Erases all flash pages.
  *         The flash_unlock() function must be called before runing this function.
  * @param  None
  * @return flash status.
  */
flash_status_t flash_all_pages_erase(void)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    /* if the previous operation is completed, proceed to erase all pages */
    FLASH->CTR |= FMC_CTR_CHIPERS;
    FLASH->CTR |= FMC_CTR_START;
    
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    /* Disable the CHIPERS Bit */
    FLASH->CTR &= ~FMC_CTR_CHIPERS;

    /* Return the Erase Status */
    return status;
}

/**
  * @brief  Programs a word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t flash_word_program(uint32_t addr, uint32_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    /* Enable the word program */ 
	FLASH->CFG |= FMC_CFG_PGWORD;
	
    /* Proceed to program the word */    
    FLASH->CTR |= FMC_CTR_PG;
    
    *(__IO uint32_t*)addr = value;
	
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    /* Disable the PG Bit */
    FLASH->CTR &= ~FMC_CTR_PG;

    /* Return the Program Status */
    return status;
}

/**
  * @brief  Programs a half word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t flash_half_word_program(uint32_t addr, uint16_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

	/*Proceed to program the new data */
    FLASH->CFG &= (~FMC_CFG_PGWORD);
   	FLASH->CTR |= FMC_CTR_PG;
  
   	*(__IO uint16_t*)addr = value;

   	/* Wait for last operation to be completed */
   	status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
   
   	/* Disable the PG Bit */
   	FLASH->CTR &= ~FMC_CTR_PG;
  
    /* Return the Program Status */
    return status;
}

/**
  * @brief  Unlocks option bytes block access.
  * @param  None
  * @return None
  */
void flash_option_bytes_unlock(void)
{
    if((FLASH->CTR & FMC_CTR_OBWEN) == RESET)
    { 
        /* Unlocking the option bytes block access */
        FLASH->OBCCODE = FMC_OBCCODE_VALUE1;
        FLASH->OBCCODE = FMC_OBCCODE_VALUE2;
    }
}

/**
  * @brief  Locks option bytes block access
  * @param  None
  * @return None
  */
void flash_option_bytes_lock(void)
{
    /* Set the OBWEN bit to lock the option bytes block access */
    FLASH->CTR &= ~FMC_CTR_OBWEN;
}

/**
  * @brief  Erases all option bytes except the Read protection (RPROT).
  *         The flash_option_bytes_unlock() function must be called before runing this function.   
  * @param  None
  * @return flash status.
  */
flash_status_t flash_option_bytes_erase(void)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    /* Proceed to erase the option bytes */
    FLASH->CTR |= FMC_CTR_OBERS;
    FLASH->CTR |= FMC_CTR_START;

    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    if(status == FLASH_STATUS_COMPLETE)
    {
        /* Disable the OBERS bit if the erase operation is complete */
        FLASH->CTR &= ~FMC_CTR_OBERS;
    }
    else
    {
        if (status != FLASH_STATUS_TIMEOUT)
        {
            /* Disable the OBPG bit */
            FLASH->CTR &= ~FMC_CTR_OBPG;
        }
    }
    
    /* Return the erase status */
    return status;
}

/**
  * @brief  Configure the Bootloader space. The flash_option_bytes_unlock() function 
  *         must be called before runing this function.
  * @param  set_value: This parameter can be a combination of 
  *         one of @arg OB_BOOTCFG_16K(Bootloader size 16KB)
  *                @arg OB_BOOTCFG_32K(Bootloader size 32KB)
  *                @arg OB_BOOTCFG_64K(Bootloader size 64KB)
  * @return flash status.
  */
flash_status_t flash_option_bytes_bootspace_set(uint8_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;
    
    status = flash_option_bytes_set(OB_BASE + 0x00, value);

    /* Return the erase status */
    return status;
}

/**
  * @brief  Programs the FLASH User Option Byte, It can be FWDT_SW, RST_DSM, RST_PWD,
  *         BOOT0/1 and VDDA detection. The flash_option_bytes_unlock() function must be called before runing
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
flash_status_t flash_option_bytes_user_set(uint8_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;
    
    status = flash_option_bytes_set(OB_BASE + 0x02, value);

    /* Return the erase status */
    return status;
}

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
flash_status_t flash_option_bytes_write_protect_enable(uint32_t value)
{
    uint8_t wport0 = 0xFF;
    uint8_t wport1 = 0xFF;
    uint8_t wport2 = 0xFF;
    uint8_t wport3 = 0xFF;
    flash_status_t status = FLASH_STATUS_COMPLETE;

    value = (uint32_t)(~value);
    wport0 = value & OB_WPROT0_WPROT0;
    wport1 = (value >> 8) & OB_WPROT0_WPROT0;
    wport2 = (value >> 16) & OB_WPROT0_WPROT0;
    wport3 = (value >> 24) & OB_WPROT0_WPROT0;

    if(wport0 != 0x00)
    {
        status = flash_option_bytes_set(OB_BASE + 0x08, wport0);
    }

    if((status == FLASH_STATUS_COMPLETE) && (wport1 != 0x00))
    {
        status = flash_option_bytes_set(OB_BASE + 0x0A, wport1);
    }

    if((status == FLASH_STATUS_COMPLETE) && (wport2 != 0x00))
    {
        status = flash_option_bytes_set(OB_BASE + 0x0C, wport2);
    }

    if((status == FLASH_STATUS_COMPLETE) && (wport3 != 0x00))
    {
        status = flash_option_bytes_set(OB_BASE + 0x0E, wport3);
    }
    /* Return the write protection operation Status */
    return status;
}

/**
  * @brief  Lock the SWD port. 
  * @note   The flash_option_bytes_unlock() function must be called before runing this function.
  * @note   This function valid only during product development
  * @param  value: specifies the data to be programmed,it can be FLASH_OB_SWD_LOCK.
  * @return flash status.
  */
flash_status_t flash_option_bytes_swd_lock_set(uint8_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;
    
    status = flash_option_bytes_set(OB_BASE + 0x10, value);

    /* Return the erase status */
    return status;
}


/**
  * @brief  Programs a half word at a specified Option Byte address.
  * @note   The flash_option_bytes_unlock() function must be called before runing this function.
  * @note   Call the flash_option_bytes_lock() to disable the flash register access and the option bytes.   
  * @param  addr: specifies the address to be programmed can be 0x1FFFF800 to 0x1FFFF80E.
  * @param  value: specifies the data to be programmed.
  * @return flash status.
  */
flash_status_t flash_option_bytes_set(uint32_t addr, uint8_t value)
{
    uint8_t times = 0;
	uint16_t reg[10] = {0};
		
    flash_status_t status = FLASH_STATUS_COMPLETE;
    
    ASSERT(FLASH_OB_BYTE_ADDRESS_CHECK(addr));
	
	/* Read the option bytes */
	reg[0] = OB->USERRDP1;
	reg[1] = OB->USERRDP2;
	reg[2] = OB->DATA0;
	reg[3] = OB->DATA1;
	reg[4] = OB->WPROTOB1;
	reg[5] = OB->WPROTOB2;
	reg[6] = OB->WPROTOB3;
	reg[7] = OB->WPROTOB4;
	reg[8] = OB->USER2_1;
	reg[9] = OB->USER2_2;

    /* Proceed to erase the option bytes */
    FLASH->CTR |= FMC_CTR_OBERS;
    FLASH->CTR |= FMC_CTR_START;

    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
    
    if(status == FLASH_STATUS_COMPLETE)
    {
        FLASH->CTR &= ~FMC_CTR_OBERS;
        FLASH->CTR |= FMC_CTR_OBPG;
        
        while(times <= 0x10)
        {
            if(addr == (OB_BASE + times))
            {
                *(__IO uint16_t*)addr = value;
            }
            else
            {
                *(__IO uint16_t*)(OB_BASE + times) = reg[times >> 1];
            }
            times = times + 2;
        }
        /* Wait for last operation to be completed */
        status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
        
        if(status != FLASH_STATUS_TIMEOUT)
        {
            /* Disable the OBPG bit if tht program operation is completed*/
            FLASH->CTR &= ~FMC_CTR_OBPG;
        }
    }

    /* Return the Option Byte Data Program Status */
    return status;
}

/**
  * @brief  eFuse erases a specified page in program memory. 
  *         The flash_unlock() function must be called before runing this function.
  * @param  page_addr: The page address in program memory to be erased. Starting address is 0x1F001000.
  * @return flash current status.         
  */
flash_status_t efuse_page_erase(uint32_t page_addr)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    ASSERT(EFUSE_PROGRAM_ADDRESS_CHECK(page_addr));
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
  
    if(status == FLASH_STATUS_COMPLETE)
    { 
        /* If the previous operation is completed, proceed to erase the page */
        FLASH->CTR |= FMC_CTR_EFSERS;
        FLASH->ERSADR = page_addr;
        FLASH->CTR |= FMC_CTR_START;
        
        /* Wait for last operation to be completed */
        status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
    
        /* Disable the EFSERS Bit */
        FLASH->CTR &= ~FMC_CTR_EFSERS;
    }
    
    /* Return the Erase Status */
    return status;
}

/**
  * @brief  eFuse programs a half word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t efuse_half_word_program(uint32_t addr, uint16_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;
    
    ASSERT(EFUSE_PROGRAM_ADDRESS_CHECK(addr));

	/*Proceed to program the new data */
    FLASH->CFG &= (~FMC_CFG_PGWORD);
   	FLASH->CTR |= FMC_CTR_EFSPG;
    
    *(__IO uint16_t*)addr = value;

    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    /* Disable the EFSPG Bit */
    FLASH->CTR &= ~FMC_CTR_EFSPG;

    /* Return the Program Status */
    return status;
}

/**
  * @brief  eFuse programs a word at a specified address.
  *         The flash_unlock() function must be called before runing this function.
  * @param  addr: specifies the address to be programmed.
  * @param  value: specifies the data to be programmed.
  * @return flash status. 
  */
flash_status_t efuse_word_program(uint32_t addr, uint32_t value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;
    
    ASSERT(EFUSE_PROGRAM_ADDRESS_CHECK(addr));

	/*Proceed to program the new data */
    FLASH->CFG |= FMC_CFG_PGWORD;
   	FLASH->CTR |= FMC_CTR_EFSPG;
    
    *(__IO uint32_t*)addr = value;

    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    /* Disable the EFSPG Bit */
    FLASH->CTR &= ~FMC_CTR_EFSPG;

    /* Return the Program Status */
    return status;
}

/**
  * @brief  eFuse key calculation CRC32. 
  *         The flash_unlock() function must be called before runing this function.
  * @param  crc_value: Get the calacluation CRC32 result, if the calucaltion fails, the result is 0.       
  * @return flash current status.         
  */
flash_status_t efuse_key_crc32_calc(uint32_t* crc_value)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;
    uint32_t ret = 0;
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);   
    if(status == FLASH_STATUS_COMPLETE)
    {
        /* If the previous operation is completed, proceed to calculation CRC32 */
        FLASH->CTR |= FMC_CTR_EFSSKCRC;
        FLASH->CTR |= FMC_CTR_STARTCRC;
        
        /* Wait for last operation to be completed */
        status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
    
        /* Disable the EFSSKCRC Bit */
        FLASH->CTR &= ~FMC_CTR_EFSSKCRC;
        ret = FLASH->CRC32;
    }

    *crc_value = ret;
    /* Return the Program Status */
    return status;
}

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
flash_status_t efuse_lifecycle_set(uint32_t lcs_mode)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    ASSERT(EFUSE_LIFECYC_MODE_CHECK(lcs_mode));

    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);   
    if(status == FLASH_STATUS_COMPLETE)
    {
        /* If the previous operation is completed, proceed program the lifecycle */
        FLASH->CFG |= FMC_CFG_PGWORD;
        FLASH->CTR |= FMC_CTR_EFSPG;
        if(lcs_mode == FMC_STS2_LCSSTS_LEVEL1)
        {
            EFUSE->LCS1 = LCS_CFG_VALUE;
        }
        else if(lcs_mode == FMC_STS2_LCSSTS_LEVEL2)
        {
            EFUSE->LCS1 = LCS_CFG_VALUE;
            EFUSE->LCS2 = LCS_CFG_VALUE;
        }
        else if(lcs_mode == FMC_STS2_LCSSTS_LEVEL3)
        {
            EFUSE->LCS3 = 0x00;
        }
    }
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    /* Disable the EFSPG Bit */
    FLASH->CTR &= ~FMC_CTR_EFSPG;

    /* Return the Program Status */
    return status;
}

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
flash_status_t efuse_secure_key_valid_set(uint32_t valid_data)
{
    flash_status_t status = FLASH_STATUS_COMPLETE;

    ASSERT(EFUSE_KEY_VALID_CHECK(valid_data));
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
    if(status == FLASH_STATUS_COMPLETE)
    {
        FLASH->CFG |= FMC_CFG_PGWORD;
        FLASH->CTR |= FMC_CTR_EFSPG;
        if((valid_data & 0x30000000) == 0x10000000)
        {
            EFUSE->KEY1_VALID = valid_data;
        }
        else if((valid_data & 0x30000000) == 0x20000000)
        {
            EFUSE->KEY2_VALID = valid_data;
        }
        else if((valid_data & 0x30000000) == 0x30000000)
        {
            EFUSE->KEY2_VALID = valid_data;
        }
    }
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);

    /* Disable the EFSPG Bit */
    FLASH->CTR &= ~FMC_CTR_EFSPG;
    /* Return the Program Status */
    return status;
}

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
flash_status_t efuse_option_area_cfg(uint32_t value)
{
    uint32_t reg = 0;
    uint32_t temp = 0;
    flash_status_t status = FLASH_STATUS_COMPLETE;

    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);   
    if(status == FLASH_STATUS_COMPLETE)
    {
        /* If the previous operation is completed, proceed program the lifecycle */
        FLASH->CTR |= FMC_CTR_START;
        temp = ~(uint32_t)((value>>16)&0xFF);
        reg = ((temp<<24)&0xFF000000);
        reg |= value;
        EFUSE->CTR = reg;
    }
    /* Wait for last operation to be completed */
    status = flash_operation_wait(FLASH_OPERATE_TIMEOUT);
    /* Return the Program Status */
    return status;
}


/**
  * @brief  Waits for a FLASH operation to complete or delay timeout.
  * @param  counter: FLASH programming Timeout
  * @return flash status.
  */
flash_status_t flash_operation_wait(uint32_t counter)
{ 
    while((FLASH->STS & FMC_STS_BUSY) && (counter != 0x00))
    {
        counter--;
    }
    if(FLASH->STS & (FMC_STS_PGERR|FMC_STS_WPERR))
    {
        return FLASH_STATUS_ERROR;
    }

    if(counter == 0)
    {
        return FLASH_STATUS_TIMEOUT;
    }
    
    return FLASH_STATUS_COMPLETE;
}

/**@brief Get the unique id, it size is 12 bytes.
 * @param  buf: Specifies the data to be read.
 * @return Is the UID valid, 1: valid, 0: invalid.
 */
uint8_t flash_unique_id_get(uint8_t *buf)
{
    uint32_t data;
    uint8_t temp = 0;
    uint8_t i,j;
    uint32_t addr = FLASH_UID_START_ADDR;

    for(i=0;i<3;i++)
    {
        data = *(__IO uint32_t *)addr;     /*!< read flash data */
        j = i*4;
        buf[j] = (uint8_t)data;
        buf[j+1] = (uint8_t)(data >> 8);
        buf[j+2] = (uint8_t)(data >> 16);
        buf[j+3] = (uint8_t)(data >> 24);
        addr += 4;
        temp += buf[j]+buf[j+1]+buf[j+2]+buf[j+3];
    }

    data = *(__IO uint32_t *)(FLASH_UID_SUM_ADDR);
    if(temp != (uint8_t)data)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */
