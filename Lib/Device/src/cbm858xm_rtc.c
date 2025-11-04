/**
* @file        cbm858xm_rtc.c
* @brief       This file provides all the basic RTC firmware functions.
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.24
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.24    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


/***************************************************************************************************
 * @includes
***************************************************************************************************/
#include "cbm858xm_rtc.h"


/***************************************************************************************************
 * @definitions
***************************************************************************************************/
#define RTC_TIME_RESERVED_MASK      ((uint32_t)0x007F7F7F)      /*!< RTC time register RESERVED mask. */
#define RTC_DATE_RESERVED_MASK      ((uint32_t)0x00FFFF3F)      /*!< RTC date register RESERVED mask. */
#define RTC_INIT_MASK               ((uint32_t)0xFFFFFFFF)      /*!< RTC date register RESERVED mask. */
#define RTC_RSF_MASK                ((uint32_t)0xFFFFFF5F)      /*!< RTC status register synchronization flag mask. */


#define RTC_INIT_MODE_TIMEOUT       ((uint32_t) 0x00004000)     /*!< RTC INIT state timeout. */
#define RTC_SYNCHRO_TIMEOUT         ((uint32_t) 0x00008000)     /*!< synchro timeout. */


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @defgroup RTC RTC
  * @brief    RTC driver modules
  * @{
  */

///@cond

/***************************************************************************************************
 * @variables
***************************************************************************************************/


/***************************************************************************************************
 * @functions
***************************************************************************************************/
static uint8_t rtc_byte_convert_bcd(uint8_t value);
static uint8_t rtc_bcd_convert_byte(uint8_t value);


/**
  * @brief  Deinitializes the RTC registers to their default reset values.
  * @param  None.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_def_init(void)
{
    error_status_t status = ERROR;

    /* Set Initialization mode. */
    if (rtc_init_mode_enter() == ERROR)
    {
        status = ERROR;
    }
    else
    {
        /* Reset TIME, DATE and CTR registers. */
        RTC->TIME      = (uint32_t)0x00000000;
        RTC->DATE      = (uint32_t)0x00002101;
        RTC->CTR      &= (uint32_t)0x00000000;
        RTC->PDIV      = (uint32_t)0x007F00FF;
        RTC->ACFG1     = (uint32_t)0x00000000;
        RTC->ACFG2     = (uint32_t)0x00000000;

        /* Reset STS register and exit initialization mode. */
        RTC->STS = (uint32_t)0x00000000;

        /* Reset  multi-function configuration register. */
        RTC->MF = 0x00000000;

        /* Wait till the RTC RSF flag is set */
        if (rtc_synchro_wait() == ERROR)
        {
            status = ERROR;
        }
        else
        {
            status = SUCCESS;
        }

    }

    return status;
}


/**
  * @brief  Initializes the RTC registers according to the specified parameters in ptr_init_struct. RTC prescaler
  *         register can be written in initialization step only.
  * @param  ptr_init_struct: Pointer to a rtc_init_t structure that contains the configuration information for the RTC
  *         peripheral.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_init(rtc_init_t* ptr_init_struct)
{
    error_status_t status = ERROR;

    ASSERT(RTC_HOUR_FORMAT_CHECK(ptr_init_struct->hour_format));
    ASSERT(RTC_PDIV1_CHECK(ptr_init_struct->rtc_divider1));
    ASSERT(RTC_PDIV2_CHECK(ptr_init_struct->rtc_divider2));

    /* Set initialization mode. */
    if (rtc_init_mode_enter() == ERROR)
    {
        status = ERROR;
    }
    else
    {
        MODIFY_REG(RTC->CTR, RTC_CTR_FMT12, ptr_init_struct->hour_format);

        /* Configure the RTC PDIV. */
        RTC->PDIV = (ptr_init_struct->rtc_divider1 << 16) | ptr_init_struct->rtc_divider2;

        /* Exit initialization mode. */
        __RTC_INIT_MODE_EXIT();
        status = SUCCESS;
    }

    return status;
}


/**
  * @brief  Fills each rtc_init_struct member with its default value.
  * @param  ptr_init_struct: Pointer to a ptr_init_struct structure which will be initialized.
  * @return None.
  */
void rtc_struct_init(rtc_init_t* ptr_init_struct)
{
    /* Initialize the hour_format member. */
    ptr_init_struct->hour_format = RTC_HOUR_FORMAT_24;

    /* Init the first pre-divider factor member. */
    ptr_init_struct->rtc_divider1 = (uint32_t)0x7F;

    /* Init the second pre-divider factor member. */
    ptr_init_struct->rtc_divider2 = (uint32_t)0xFF;//should modify
}


/**
  * @brief  Enters the RTC Initialization mode.
  * @param  None.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_init_mode_enter(void)
{
    __IO uint32_t init_counter = 0x00;
    uint32_t status_value = 0x00;
    error_status_t status = ERROR;

    /* Check if the initialization mode is set */
    if ((RTC->STS & RTC_STS_INITF) == (uint32_t)RESET)
    {
        /* Set the Initialization mode */
        RTC->STS |= RTC_STS_INITE;
        /* Wait till RTC is in INIT state and if time out is reached exit. */
        do
        {
            status_value = RTC->STS & RTC_STS_INITF;
            init_counter++;  
        } while ((init_counter < RTC_INIT_MODE_TIMEOUT) && (status_value == 0x00));
        
        if ((RTC->STS & RTC_STS_INITF) != RESET)
        {
            status = SUCCESS;
        }
        else
        {
            status = ERROR;
        }
    }
    else
    {
        status = SUCCESS;
    }

    return status;
}


/**
  * @brief  Waits until the RTC time and date registers (RTC_TIME and RTC_DATE) are synchronized with RTC APB clock.
  * @param  None.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_synchro_wait(void)
{
    __IO uint32_t sync_counter = 0;
    uint32_t temp_status = 0x00;
    error_status_t status = ERROR;

    if ((RTC->CTR & RTC_CTR_DAR) != RESET)
    {
        /* Direct access mode. */
        status = SUCCESS;
    }
    else
    {
        /* Clear RSF flag. */
        RTC->STS &= (uint32_t)RTC_RSF_MASK;

        /* Wait the registers to be synchronised. */
        do
        {
            temp_status = RTC->STS & RTC_STS_RSF;
            sync_counter++;  
        } while((sync_counter < RTC_SYNCHRO_TIMEOUT) && (temp_status == 0x00));

        if ((RTC->STS & RTC_STS_RSF) != RESET)
        {
            status = SUCCESS;
        }
        else
        {
            status = ERROR;
        }
    }

    return (status);
}


/**
  * @brief  Set the RTC current time.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_time_struct: Pointer to a rtc_time_t structure that contains the time config information for the RTC.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_time_set(uint32_t format_flag, rtc_time_t* ptr_time_struct)
{
    uint32_t reg = 0;
    error_status_t status = ERROR;

    ASSERT(RTC_FORMAT_CHECK(format_flag));

    if (format_flag == RTC_FORMAT_BIN)
    {
        if ((RTC->CTR & RTC_CTR_FMT12) != (uint32_t)RESET)
        {
            ASSERT(RTC_HOUR12_CHECK(ptr_time_struct->rtc_hours));
            ASSERT(RTC_AM_PM_HOUR12_CHECK(ptr_time_struct->am_pm_sel));
        }
        else
        {
            ptr_time_struct->am_pm_sel = 0x00;
            ASSERT(RTC_HOUR24_CHECK(ptr_time_struct->rtc_hours));
        }

        ASSERT(RTC_MINUTES_CHECK(ptr_time_struct->rtc_minutes));
        ASSERT(RTC_SECONDS_CHECK(ptr_time_struct->rtc_seconds));
    }
    else
    {
        if ((RTC->CTR & RTC_CTR_FMT12) != (uint32_t)RESET)
        {
            reg = rtc_bcd_convert_byte(ptr_time_struct->rtc_hours);
            ASSERT(RTC_HOUR12_CHECK(reg));
            ASSERT(RTC_AM_PM_HOUR12_CHECK(ptr_time_struct->am_pm_sel));
        }
        else
        {
            ptr_time_struct->am_pm_sel = 0x00;
            ASSERT(RTC_HOUR24_CHECK(rtc_bcd_convert_byte(ptr_time_struct->rtc_hours)));
        }

        ASSERT(RTC_MINUTES_CHECK(rtc_bcd_convert_byte(ptr_time_struct->rtc_minutes)));
        ASSERT(RTC_SECONDS_CHECK(rtc_bcd_convert_byte(ptr_time_struct->rtc_seconds)));
    }

    /* Check the input parameters format. */
    if (format_flag != RTC_FORMAT_BIN)
    {
        reg = (((uint32_t)(ptr_time_struct->rtc_hours) << 16) | \
              ((uint32_t)(ptr_time_struct->rtc_minutes) << 8) | \
              ((uint32_t)ptr_time_struct->rtc_seconds) | \
              ((uint32_t)(ptr_time_struct->am_pm_sel) << 16));
    }
    else
    {
        reg = (uint32_t)(((uint32_t)rtc_byte_convert_bcd(ptr_time_struct->rtc_hours) << 16) | \
                    ((uint32_t)rtc_byte_convert_bcd(ptr_time_struct->rtc_minutes) << 8) | \
                    ((uint32_t)rtc_byte_convert_bcd(ptr_time_struct->rtc_seconds)) | \
                    (((uint32_t)ptr_time_struct->am_pm_sel) << 16));
    }

    /* Set Initialization mode. */
    if (rtc_init_mode_enter() == ERROR)
    {
        status = ERROR;
    }
    else
    {
        /* Set the RTC_TIME register. */
        RTC->TIME = (uint32_t)(reg & RTC_TIME_RESERVED_MASK);

        /* Exit initialization mode. */
        __RTC_INIT_MODE_EXIT(); 

        /* If RTC_CTR_DAR bit = 0, wait for synchro else this check is not needed. */
        if ((RTC->CTR & RTC_CTR_DAR) == RESET)
        {
            if (rtc_synchro_wait() == ERROR)
            {
                status = ERROR;
            }
            else
            {
                status = SUCCESS;
            }
        }
        else
        {
            status = SUCCESS;
        }

    }

    return status;
}


/**
  * @brief  Fill each rtc ptr_time_struct member with its default value (00h: 00min: 00sec).
  * @param  ptr_time_struct: Pointer to a rtc_time_t structure which will be initialized.
  * @return None.
  */
void rtc_time_struct_init(rtc_time_t* ptr_time_struct)
{
    /* Time = 00h:00min:00sec. */
    ptr_time_struct->am_pm_sel = RTC_AM_HOUR12;
    ptr_time_struct->rtc_hours = 0;
    ptr_time_struct->rtc_minutes = 0;
    ptr_time_struct->rtc_seconds = 0; 
}


/**
  * @brief  Get the RTC current Time.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_time_struct: Pointer to a rtc_time_t structure that will contain the returned current time config.
  * @return None.
  */
void rtc_time_get(uint32_t format_flag, rtc_time_t* ptr_time_struct)
{
    uint32_t reg = 0;

    /* Check the parameters. */
    ASSERT(RTC_FORMAT_CHECK(format_flag));

    /* Get the RTC_TIME register. */
    reg = (uint32_t)(RTC->TIME & RTC_TIME_RESERVED_MASK); 

    /* Fill the structure fields with the read parameters. */
    ptr_time_struct->rtc_hours = (uint8_t)((reg & (RTC_TIME_HORTEN | RTC_TIME_HORUNT)) >> 16);
    ptr_time_struct->rtc_minutes = (uint8_t)((reg & (RTC_TIME_MINTEN | RTC_TIME_MINUNT)) >>8);
    ptr_time_struct->rtc_seconds = (uint8_t)(reg & (RTC_TIME_SECTEN | RTC_TIME_SECUNT));
    ptr_time_struct->am_pm_sel = (uint8_t)((reg & (RTC_TIME_PM)) >> 16);  

    /* Check the input parameters format. */
    if (format_flag == RTC_FORMAT_BIN)
    {
        /* Convert the structure parameters to Binary format */
        ptr_time_struct->rtc_hours = (uint8_t)rtc_bcd_convert_byte(ptr_time_struct->rtc_hours);
        ptr_time_struct->rtc_minutes = (uint8_t)rtc_bcd_convert_byte(ptr_time_struct->rtc_minutes);
        ptr_time_struct->rtc_seconds = (uint8_t)rtc_bcd_convert_byte(ptr_time_struct->rtc_seconds);
    }
}


/**
  * @brief  Gets the RTC current calendar subseconds value.
  * @param  None.
  * @return RTC current calendar subseconds value.
  */
uint32_t rtc_subsecond_get(void)
{
    uint32_t reg = 0;

    /* Get subseconds values from the correspondent registers. */
    reg = (uint32_t)(RTC->SSEC);

    /* Read DATE register to unfroze calendar registers. */
    (void) (RTC->DATE);

    return (reg);
}


/**
  * @brief  Set the RTC current date.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_date_struct: Ppointer to a rtc_date_t structure that contains the date config information for the RTC.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_date_set(uint32_t format_flag, rtc_date_t* ptr_date_struct)
{
    uint32_t reg = 0;
    error_status_t status = ERROR;

    ASSERT(RTC_FORMAT_CHECK(format_flag));

    if ((format_flag == RTC_FORMAT_BIN) && ((ptr_date_struct->rtc_month & 0x10) == 0x10))
    {
        ptr_date_struct->rtc_month = (ptr_date_struct->rtc_month & (uint32_t)~(0x10)) + 0x0A;
    }
    if (format_flag == RTC_FORMAT_BIN)
    {
        ASSERT(RTC_YEAR_CHECK(ptr_date_struct->rtc_year));
        ASSERT(MONTH_CHECK(ptr_date_struct->rtc_month));
        ASSERT(DATE_CHECK(ptr_date_struct->rtc_date));
    }
    else
    {
        ASSERT(RTC_YEAR_CHECK(rtc_bcd_convert_byte(ptr_date_struct->rtc_year)));
        reg = rtc_bcd_convert_byte(ptr_date_struct->rtc_month);
        ASSERT(MONTH_CHECK(reg));
        reg = rtc_bcd_convert_byte(ptr_date_struct->rtc_date);
        ASSERT(DATE_CHECK(reg));
    }
    ASSERT(WEEKDAY_CHECK(ptr_date_struct->rtc_weekday));

    /* Check the input parameters format */
    if (format_flag != RTC_FORMAT_BIN)
    {
        reg = ((((uint32_t)ptr_date_struct->rtc_year) << 16) | \
              (((uint32_t)ptr_date_struct->rtc_month) << 8) | \
              ((uint32_t)ptr_date_struct->rtc_date) | \
              (((uint32_t)ptr_date_struct->rtc_weekday) << 13)); 
    }
    else
    {
        reg = (((uint32_t)rtc_byte_convert_bcd(ptr_date_struct->rtc_year) << 16) | \
              ((uint32_t)rtc_byte_convert_bcd(ptr_date_struct->rtc_month) << 8) | \
              ((uint32_t)rtc_byte_convert_bcd(ptr_date_struct->rtc_date)) | \
              ((uint32_t)ptr_date_struct->rtc_weekday << 13));
    }

    /* Set initialization mode. */
    if (rtc_init_mode_enter() == ERROR)
    {
        status = ERROR;
    }
    else
    {
        /* Set the RTC_DATE register. */
        RTC->DATE = (uint32_t)(reg & RTC_DATE_RESERVED_MASK);

        /* Exit initialization mode. */
        __RTC_INIT_MODE_EXIT(); 

        /* If RTC_CTR_DAR bit = 0, wait for synchro else this check is not needed. */
        if ((RTC->CTR & RTC_CTR_DAR) == RESET)
        {
            if (rtc_synchro_wait() == ERROR)
            {
                status = ERROR;
            }
            else
            {
                status = SUCCESS;
            }
        }
        else
        {
            status = SUCCESS;
        }
    }

    return status;
}


/**
  * @brief  Fills each rtc_date_struct member with its default value (Monday, January 01 xx00).
  * @param  ptr_date_struct: Pointer to a rtc_date_t structure which will be initialized.
  * @return None.
  */
void rtc_date_struct_init(rtc_date_t* ptr_date_struct)
{
    /* Monday, January 01 xx00. */
    ptr_date_struct->rtc_weekday = WEEKDAY_MONDAY;
    ptr_date_struct->rtc_date = 1;
    ptr_date_struct->rtc_month = MONTH_JANUARY;
    ptr_date_struct->rtc_year = 0;
}


/**
  * @brief  Get the RTC current date.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_date_struct: Pointer to a rtc_date_t struct that will contain the returned current date configuration.
  * @return None.
  */
void rtc_date_get(uint32_t format_flag, rtc_date_t* ptr_date_struct)
{
    uint32_t reg = 0;

    ASSERT(RTC_FORMAT_CHECK(format_flag));

    /* Get the RTC_TIME register. */
    reg = (uint32_t)(RTC->DATE & RTC_DATE_RESERVED_MASK); 

    /* Fill the structure fields with the read parameters. */
    ptr_date_struct->rtc_year = (uint8_t)((reg & (RTC_DATE_YTEN | RTC_DATE_YUNT)) >> 16);
    ptr_date_struct->rtc_month = (uint8_t)((reg & (RTC_DATE_MTEN | RTC_DATE_MUNT)) >> 8);
    ptr_date_struct->rtc_date = (uint8_t)(reg & (RTC_DATE_DTEN | RTC_DATE_DUNT));
    ptr_date_struct->rtc_weekday = (uint8_t)((reg & (RTC_DATE_WUNT)) >> 13);

    /* Check the input parameters format. */
    if (format_flag == RTC_FORMAT_BIN)
    {
        /* Convert the structure parameters to Binary format. */
        ptr_date_struct->rtc_year = (uint8_t)rtc_bcd_convert_byte(ptr_date_struct->rtc_year);
        ptr_date_struct->rtc_month = (uint8_t)rtc_bcd_convert_byte(ptr_date_struct->rtc_month);
        ptr_date_struct->rtc_date = (uint8_t)rtc_bcd_convert_byte(ptr_date_struct->rtc_date);
        ptr_date_struct->rtc_weekday = (uint8_t)(ptr_date_struct->rtc_weekday);   
    }
}


/**
  * @brief  Set the specified RTC Alarm. The Alarm register can only be written when the corresponding alarm is disabled
  *         (Use the rtc_alarm_enable_ctrl(DISABLE)).
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_alarm_struct: Pointer to a rtc_alarm_t structure that contains the alarm configuration parameters.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_alarm_set(uint32_t format_flag, rtc_alarm_t* ptr_alarm_struct)
{
    uint32_t reg = 0;

    ASSERT(RTC_FORMAT_CHECK(format_flag));
    ASSERT(RTC_ALARM_MASK_CHECK(ptr_alarm_struct->alarm_mask));
    ASSERT(RTC_DATE_WEEKDAY_SEL_CHECK(ptr_alarm_struct->date_weekday_sel));

    if (format_flag == RTC_FORMAT_BIN)
    {
        if ((RTC->CTR & RTC_CTR_FMT12) != (uint32_t)RESET)
        {
            ASSERT(RTC_HOUR12_CHECK(ptr_alarm_struct->alarm_time.rtc_hours));
            ASSERT(RTC_AM_PM_HOUR12_CHECK(ptr_alarm_struct->alarm_time.am_pm_sel));
        }
        else
        {
            ptr_alarm_struct->alarm_time.am_pm_sel = 0x00;
            ASSERT(RTC_HOUR24_CHECK(ptr_alarm_struct->alarm_time.rtc_hours));
        }
        ASSERT(RTC_MINUTES_CHECK(ptr_alarm_struct->alarm_time.rtc_minutes));
        ASSERT(RTC_SECONDS_CHECK(ptr_alarm_struct->alarm_time.rtc_seconds));

        if(ptr_alarm_struct->date_weekday_sel == RTC_DATE_WEEKDAY_SEL_DATE)
        {
            ASSERT(DATE_CHECK(ptr_alarm_struct->date_weekday));
        }
        else
        {
            ASSERT(WEEKDAY_CHECK(ptr_alarm_struct->date_weekday));
        }
    }
    else
    {
        if ((RTC->CTR & RTC_CTR_FMT12) != (uint32_t)RESET)
        {
            reg = rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_hours);
            ASSERT(RTC_HOUR12_CHECK(reg));
            ASSERT(RTC_AM_PM_HOUR12_CHECK(ptr_alarm_struct->alarm_time.am_pm_sel));
        } 
        else
        {
            ptr_alarm_struct->alarm_time.am_pm_sel = 0x00;
            ASSERT(RTC_HOUR24_CHECK(rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_hours)));
        }

        ASSERT(RTC_MINUTES_CHECK(rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_minutes)));
        ASSERT(RTC_SECONDS_CHECK(rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_seconds)));
    
        if(ptr_alarm_struct->date_weekday_sel == RTC_DATE_WEEKDAY_SEL_DATE)
        {
            reg = rtc_bcd_convert_byte(ptr_alarm_struct->date_weekday);
            ASSERT(DATE_CHECK(reg));    
        }
        else
        {
            reg = rtc_bcd_convert_byte(ptr_alarm_struct->date_weekday);
            ASSERT(WEEKDAY_CHECK(reg));      
        }    
    }

    /* Check the input parameters format. */
    if (format_flag != RTC_FORMAT_BIN)
    {
        reg = (((uint32_t)(ptr_alarm_struct->alarm_time.rtc_hours) << 16) | \
              ((uint32_t)(ptr_alarm_struct->alarm_time.rtc_minutes) << 8) | \
              ((uint32_t)ptr_alarm_struct->alarm_time.rtc_seconds) | \
              ((uint32_t)(ptr_alarm_struct->alarm_time.am_pm_sel) << 16) | \
              ((uint32_t)(ptr_alarm_struct->date_weekday) << 24) | \
              ((uint32_t)ptr_alarm_struct->date_weekday_sel) | \
              ((uint32_t)ptr_alarm_struct->alarm_mask)); 
    }
    else
    {
        reg = (((uint32_t)rtc_byte_convert_bcd(ptr_alarm_struct->alarm_time.rtc_hours) << 16) | \
              ((uint32_t)rtc_byte_convert_bcd(ptr_alarm_struct->alarm_time.rtc_minutes) << 8) | \
              ((uint32_t)rtc_byte_convert_bcd(ptr_alarm_struct->alarm_time.rtc_seconds)) | \
              ((uint32_t)(ptr_alarm_struct->alarm_time.am_pm_sel) << 16) | \
              ((uint32_t)rtc_byte_convert_bcd(ptr_alarm_struct->date_weekday) << 24) | \
              ((uint32_t)ptr_alarm_struct->date_weekday_sel) | \
              ((uint32_t)ptr_alarm_struct->alarm_mask)); 
    }

    /* Configure the Alarm register. */
    RTC->ACFG1 = (uint32_t)reg;
}


/**
  * @brief  Fill each rtc ptr_alarm_struct member with its default value (time  = 00h: 00mn: 00sec // Date = 1st day of
  *         the month // Mask = all fields are not masked).
  * @param  ptr_alarm_struct: Pointer to a @ref rtc_alarm_t structure which will be initialized.
  * @return None.
  */
void rtc_alarm_struct_init(rtc_alarm_t* ptr_alarm_struct)
{
    /* Alarm time settings : time = 00h:00mn:00sec. */
    ptr_alarm_struct->alarm_time.am_pm_sel = RTC_AM_HOUR12;
    ptr_alarm_struct->alarm_time.rtc_hours = 0;
    ptr_alarm_struct->alarm_time.rtc_minutes = 0;
    ptr_alarm_struct->alarm_time.rtc_seconds = 0;

    /* Alarm date settings : date = 1st day of the month. */
    ptr_alarm_struct->date_weekday_sel = RTC_DATE_WEEKDAY_SEL_DATE;
    ptr_alarm_struct->date_weekday = 1;

    /* Alarm masks settings : mask = all fields are not masked. */
    ptr_alarm_struct->alarm_mask = RTC_ALARM_MASK_NONE;
}


/**
  * @brief  Get the RTC alarm value and masks.
  * @param  format_flag: It can be binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_alarm_struct: Pointer to a rtc_alarm_t struct that will contains the output alarm configuration values.
  * @return None.
  */
void rtc_alarm_get(uint32_t format_flag, rtc_alarm_t* ptr_alarm_struct)
{
    uint32_t reg = 0;

    ASSERT(RTC_FORMAT_CHECK(format_flag));

    /* Get the RTC_ACFG1 register. */
    reg = (uint32_t)(RTC->ACFG1);

    /* Fill the structure with the read parameters. */
    ptr_alarm_struct->alarm_time.rtc_hours = (uint8_t)((reg & (RTC_ACFG1_HORTEN | RTC_ACFG1_HORUNT)) >> 16);
    ptr_alarm_struct->alarm_time.rtc_minutes = (uint8_t)((reg & (RTC_ACFG1_MINTEN | RTC_ACFG1_MINUNT)) >> 8);
    ptr_alarm_struct->alarm_time.rtc_seconds = (uint8_t)(reg & (RTC_ACFG1_SECTEN | RTC_ACFG1_SECUNT));
    ptr_alarm_struct->alarm_time.am_pm_sel = (uint8_t)((reg & RTC_ACFG1_PM) >> 16);
    ptr_alarm_struct->date_weekday = (uint8_t)((reg & (RTC_ACFG1_DTEN | RTC_ACFG1_DUNT)) >> 24);
    ptr_alarm_struct->date_weekday_sel = (uint8_t)(reg & RTC_ACFG1_WDSEL);
    ptr_alarm_struct->alarm_mask = (uint8_t)(reg & RTC_ALARM_MASK_ALL);

    if (format_flag == RTC_FORMAT_BIN)
    {
        ptr_alarm_struct->alarm_time.rtc_hours = rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_hours);
        ptr_alarm_struct->alarm_time.rtc_minutes = rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_minutes);
        ptr_alarm_struct->alarm_time.rtc_seconds = rtc_bcd_convert_byte(ptr_alarm_struct->alarm_time.rtc_seconds);
        ptr_alarm_struct->date_weekday = rtc_bcd_convert_byte(ptr_alarm_struct->date_weekday);
    }
}


/**
  * @brief  Enables or disables the specified RTC alarm. 
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_alarm_enable_ctrl(enable_state_t enable_flag)
{
    __IO uint32_t alarm_counter = 0x00;
    uint32_t alarm_status = 0x00;
    error_status_t status = ERROR;

    ASSERT(FUNCTIONAL_STATE_CHECK(enable_flag));

    /* Configure the alarm state. */
    if (enable_flag != DISABLE)
    {
        RTC->CTR |= RTC_CTR_ALRE;

        status = SUCCESS;
    }
    else
    {
        /* Disable the alarm in RTC_CTR register. */
        RTC->CTR &= ~RTC_CTR_ALRE;

        /* Wait till RTC ALR flag is set and if time out is reached exit. */
        do
        {
            alarm_status = RTC->STS & RTC_STS_ALRWAF;
            alarm_counter++;
        } while ((alarm_counter < RTC_INIT_MODE_TIMEOUT) && (alarm_status == 0x00));

        if ((RTC->STS & RTC_STS_ALRWAF) == RESET)
        {
            status = ERROR;
        }
        else
        {
            status = SUCCESS;
        }
    }

    return status;
}


/**
  * @brief  Configures the RTC wakeup clock source only. The WakeUp Clock source can only be changed when the RTC wakeup
  *         is disabled (Use the rtc_wakeup_enable_ctrl(DISABLE)). 
  * @param  wakeup_clk: It can be one of the following values:
  * @note   The precondition of calling this interface is the write protection is disabled.
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV16
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV8
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV4
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV2
  *          @arg RTC_WAKEUP_CLOCK_SPRE_16BITS
  *          @arg RTC_WAKEUP_CLOCK_SPRE_17BITS
  * @return None.
  */
void rtc_wakeup_clock_config(uint32_t wakeup_clk)
{
        ASSERT(RTC_WAKEUP_CLOCK_CHECK(wakeup_clk));

        MODIFY_REG(RTC->CTR, RTC_CTR_WUCKSEL, wakeup_clk);
}


/**
  * @brief  Adds or substract one hour from the current time. 
  * @param  save_time_value: It can be one of the following values:
  *          @arg RTC_DAYLIGHT_SAVING_DEC1H: substract one hour.
  *          @arg RTC_DAYLIGHT_SAVING_INC1H: add one hour.
  * @param  flag: specifies the value to be written in the SAVEF bit.
  *         It can be one of the following values:
  *          @arg RTC_DAYLIGHT_SAVING_FLAG_RESET
  *          @arg RTC_DAYLIGHT_SAVING_FLAG_SET
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_daylight_saving_config(uint32_t save_time_value, uint32_t flag)
{
    ASSERT(RTC_DAYLIGHT_SAVING_CHECK(save_time_value));
    ASSERT(RTC_DAYLIGHT_SAVING_FLAG_CHECK(flag));

    MODIFY_REG(RTC->CTR, 0x00070000, save_time_value | flag);
}


/**
  * @brief  Configures the RTC output source. 
  * @param  config_value: It can be one of the following values:
  *          @arg RTC_OUTPUT_SOURCE_DISABLE: rtc output clock suorce disable).
  *          @arg RTC_OUTPUT_SOURCE_ALARM: select alarm output clock suorce).
  *          @arg RTC_OUTPUT_SOURCE_WAKEUP: select wakeup output clock suorce).
  * @param  config_polarity: It can be one of the following values:
  *          @arg RTC_OUTPUT_POLARITY_HIGH: output pin is high).
  *          @arg RTC_OUTPUT_POLARITY_LOW: output pin is low).
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_output_config(uint32_t config_value, uint32_t config_polarity)
{
    ASSERT(RTC_OUTPUT_SOURCE_CHECK(config_value));
    ASSERT(RTC_OUTPUT_POLARITY_CHECK(config_polarity));

    MODIFY_REG(RTC->CTR, (RTC_CTR_OUTSRC | RTC_CTR_APOL), config_value | config_polarity);
}


/**
  * @brief  Configures the RTC output pin mode. 
  * @param  output_type: Specifies the RTC Output (PA12) pin mode.
  *         It can be one of the following values:
  *          @arg RTC_OUTPUT_OPEN_DRAIN: RTC output is configured in open drain mode.
  *          @arg RTC_OUTPUT_PUSH_PULL: RTC output is configured in push pull mode.
  * @return None.
  */
void rtc_output_type_config(uint32_t output_type)
{
    ASSERT(RTC_OUTPUT_TYPE_CHECK(output_type));

    MODIFY_REG(RTC->MF, RTC_MF_PC12DATA, output_type);
}


/**
  * @brief Sets the wakeup reload value.
  * @param reload_vlaue: Select reload value.
  * @return None.
  */
void rtc_wakeup_reload_value_set(uint16_t reload_vlaue)
{
    RTC->WUTR = (uint32_t)reload_vlaue;
}


/**
  * @brief  Converts a 2 digit decimal to BCD format.
  * @param  value: Byte to be converted.
  * @return Converted byte
  */
static uint8_t rtc_byte_convert_bcd(uint8_t value)
{
    uint8_t bcd_high = 0;

    while (value >= 10)
    {
        bcd_high++;
        value -= 10;
    }

    return  ((uint8_t)(bcd_high << 4) | value);
}

/**
  * @brief  Convert from 2 digit BCD to Binary.
  * @param  value: BCD value to be converted.
  * @return Converted byte.
  */
static uint8_t rtc_bcd_convert_byte(uint8_t value)
{
    uint8_t temp = 0;

    temp = ((uint8_t)(value & (uint8_t)0xF0) >> (uint8_t)0x4) * 10;
    return (temp + (value & (uint8_t)0x0F));
}

///@endcond

/**
  * @}
  */

/**
  * @}
  */
