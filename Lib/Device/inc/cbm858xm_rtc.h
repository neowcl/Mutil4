/**
* @file        cbm858xm_rtc.h
* @brief       This file contains all the functions prototypes for the RTC firmware library. 
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


#ifndef __CBM858xM_RTC_H__
#define __CBM858xM_RTC_H__


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

/** @addtogroup RTC
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup RTC_Exported_Types RTC Exported Types
  * @{
  */

/** @struct rtc_init_t 
  * @brief  RTC Init structures definition.
  */
typedef struct
{
    uint32_t hour_format;       	/*!< Specifies the RTC hour format. */
    uint32_t rtc_divider1;      	/*!< Specifies the RTC first pre-divider factor lower than 0x7F. */
    uint32_t rtc_divider2;      	/*!< Specifies the RTC second pre-divider factor lower than 0x1FFF. */
}rtc_init_t;


/** @struct rtc_time_t 
  * @brief  RTC Time structure definition.
  */
typedef struct
{
    uint8_t rtc_hours;          	/*!< Specifies the RTC hour, HourFormat_12 (0~11), HourFormat_24 (0~23). */
    uint8_t rtc_minutes;        	/*!< Specifies the RTC minutes (0~59). */
    uint8_t rtc_seconds;        	/*!< Specifies the RTC seconds (0~59). */
    uint8_t am_pm_sel;          	/*!< Specifies the RTC AM/PM, it can be one of the following values: @ref RTC_AM_PM. */
}rtc_time_t; 


/** @struct rtc_date_t
  * @brief  RTC Date structure definition.
  */
typedef struct
{
    uint8_t rtc_weekday;        	/*!< Specifies weekday. */
    uint8_t rtc_month;          	/*!< Specifies month. */
    uint8_t rtc_date;           	/*!< Specifies date (value in the 1-31). */
    uint8_t rtc_year;           	/*!< Specifies year (value in the 0-99). */
}rtc_date_t;


/** @struct rtc_alarm_t
  * @brief  RTC Alarm structure definition.
  */
typedef struct
{
    rtc_time_t alarm_time;          /*!< Specifies the RTC alarm time members. */
    uint32_t alarm_mask;            /*!< Specifies the RTC alarm masks. */
    uint32_t date_weekday_sel;      /*!< Specifies the RTC alarm is on date or weekday. */
    uint8_t date_weekday;           /*!< Specifies the RTC alarm date/weekday. */
    uint8_t reserved0;              /*!< Reserved. */
    uint16_t reserved1;             /*!< Reserved. */
}rtc_alarm_t;
/**
  * @}
  */


/** @defgroup RTC_Exported_Constants RTC Exported Constants
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_hour_format RTC hour format
  * @{
  */

#define RTC_HOUR_FORMAT_24      				((uint32_t)0x00000000)      /*!< Specifies the RTC hour format ,vaule in 0~23. */
#define RTC_HOUR_FORMAT_12      				((uint32_t)0x00000040)      /*!< Specifies the RTC hour format, vaule in 0~11. */
/**
  * @}
  */

/*! Checks RTC hour format. */
#define RTC_HOUR_FORMAT_CHECK(format)       	(((format) == RTC_HOUR_FORMAT_12) || ((format) == RTC_HOUR_FORMAT_24))


/*! Checks RTC first pre-divider factor. */
#define RTC_PDIV1_CHECK(prediv)     			((prediv) <= 0x7F)


/*! Checks RTC second pre-divider factor. */
#define RTC_PDIV2_CHECK(prediv)     			((prediv) <= 0x7FFF)


/*! Checks RTC time definitions. */
#define RTC_HOUR12_CHECK(hour)          		(((hour) > 0) && ((hour) <= 12))
#define RTC_HOUR24_CHECK(hour)          		((hour) <= 23)
#define RTC_MINUTES_CHECK(minutes)      		((minutes) <= 59)
#define RTC_SECONDS_CHECK(seconds)      		((seconds) <= 59)


/** @defgroup RTC_AM_PM RTC AM/PM 
  * @{
  */

#define RTC_AM_HOUR12       					((uint8_t)0x00)     		/*!< select AM. */
#define RTC_PM_HOUR12       					((uint8_t)0x40)     		/*!< select PM. */
/**
  * @}
  */

/*! Checks RTC AM/PM defintion. */
#define RTC_AM_PM_HOUR12_CHECK(pm)      		(((pm) == RTC_AM_HOUR12) || ((pm) == RTC_PM_HOUR12))


/*! Checks RTC year. */
#define RTC_YEAR_CHECK(year)        			((year) <= 99)


/** @defgroup RTC_month RTC month
  * @{
  */

#define MONTH_JANUARY       					((uint8_t)0x01)     		/*!< January. */
#define MONTH_FEBRUARY      					((uint8_t)0x02)     		/*!< February. */
#define MONTH_MARCH         					((uint8_t)0x03)     		/*!< March. */
#define MONTH_APRIL         					((uint8_t)0x04)     		/*!< April. */
#define MONTH_MAY           					((uint8_t)0x05)     		/*!< May. */
#define MONTH_JUNE          					((uint8_t)0x06)     		/*!< Jun. */
#define MONTH_JULY          					((uint8_t)0x07)     		/*!< July. */
#define MONTH_AUGUST        					((uint8_t)0x08)     		/*!< August. */
#define MONTH_SEPTEMBER     					((uint8_t)0x09)     		/*!< September. */
#define MONTH_OCTOBER       					((uint8_t)0x10)     		/*!< October. */
#define MONTH_NOVEMBER      					((uint8_t)0x11)     		/*!< November. */
#define MONTH_DECEMBER      					((uint8_t)0x12)     		/*!< December. */
/**
  * @}
  */

/*! Checks RTC month. */
#define MONTH_CHECK(month)      				(((month) >= 1) && ((month) <= 12))


/*! Checks RTC date. */
#define DATE_CHECK(date)        				(((date) >= 1) && ((date) <= 31))


/** @defgroup RTC_weekday RTC weekday
  * @{
  */

#define	WEEKDAY_MONDAY          				((uint8_t)0x01)     		/*!< Monday. */
#define	WEEKDAY_TUESDAY         				((uint8_t)0x02)     		/*!< Tuesday. */
#define	WEEKDAY_WEDNESDAY       				((uint8_t)0x03)     		/*!< Wednesday. */
#define	WEEKDAY_THURSDAY        				((uint8_t)0x04)     		/*!< Thursday. */
#define	WEEKDAY_FRIDAY          				((uint8_t)0x05)    			/*!< Friday. */
#define	WEEKDAY_SATURDAY        				((uint8_t)0x06)     		/*!< Saturday. */
#define	WEEKDAY_SUNDAY          				((uint8_t)0x07)     		/*!< Sunday. */
/**
  * @}
  */

/*! Checks RTC weekday. */
#define WEEKDAY_CHECK(weekday)      			(((weekday) == WEEKDAY_MONDAY)    || ((weekday) == WEEKDAY_TUESDAY)  || \
                                     			((weekday) == WEEKDAY_WEDNESDAY) || ((weekday) == WEEKDAY_THURSDAY) || \
                                     			((weekday) == WEEKDAY_FRIDAY)    || ((weekday) == WEEKDAY_SATURDAY) || \
                                     			((weekday) == WEEKDAY_SUNDAY))


/** @defgroup RTC_date_weekday_sel RTC date weekday select
  * @{
  */

#define RTC_DATE_WEEKDAY_SEL_DATE           	((uint32_t)0x00000000)      /*!< Select date. */
#define RTC_DATE_WEEKDAY_SEL_WEEKDAY        	((uint32_t)0x40000000)      /*!< Select weekday. */
/**
  * @}
  */

/*! Checks RTC date weekday select. */
#define RTC_DATE_WEEKDAY_SEL_CHECK(sel)     	(((sel) == RTC_DATE_WEEKDAY_SEL_DATE) || \
                                            	((sel) == RTC_DATE_WEEKDAY_SEL_WEEKDAY))


/** @defgroup RTC_alarm_mask RTC alarm mask
  * @{
  */

#define RTC_ALARM_MASK_NONE             		((uint32_t)0x00000000)      /*!< All fields are not masked. */
#define RTC_ALARM_MASK_DATE_WEEKDAY     		((uint32_t)0x80000000)      /*!< Date_weekday field is masked. */
#define RTC_ALARM_MASK_HOURS            		((uint32_t)0x00800000)      /*!< Hours field is masked. */
#define RTC_ALARM_MASK_MINUTES          		((uint32_t)0x00008000)      /*!< Minutes field is masked. */
#define RTC_ALARM_MASK_SECONDS          		((uint32_t)0x00000080)      /*!< Seconds field is masked. */
#define RTC_ALARM_MASK_ALL              		((uint32_t)0x80808080)      /*!< All fields are masked. */
/**
  * @}
  */

/*! Checks RTC alarm mask. */
#define RTC_ALARM_MASK_CHECK(mask)      		(((mask) & 0x7F7F7F7F) == (uint32_t)RESET)


/** @defgroup RTC_alarm_subseconds_masks RTC alarm subseconds masks
  * @{
  */

    #define RTC_SUB_SECOND_MASK_ALL             ((uint8_t)0x00)     		/*!< RTC_SSEC all alarm SSEC fields are masked. */
    #define RTC_SUB_SECOND_MASK_SSEC14_1        ((uint8_t)0x01)     		/*!< Only SSEC[0] valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_2        ((uint8_t)0x02)     		/*!< Only SSEC[1:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_3        ((uint8_t)0x03)     		/*!< Only SSEC[2:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_4        ((uint8_t)0x04)    		    /*!< Only SSEC[3:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_5        ((uint8_t)0x05)    		    /*!< Only SSEC[4:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_6        ((uint8_t)0x06)    		    /*!< Only SSEC[5:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_7        ((uint8_t)0x07)     		/*!< Only SSEC[6:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_8        ((uint8_t)0x08)     		/*!< Only SSEC[7:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_9        ((uint8_t)0x09)     		/*!< Only SSEC[8:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_10       ((uint8_t)0x0A)     		/*!< Only SSEC[9:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_11       ((uint8_t)0x0B)     		/*!< Only SSEC[10:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_12       ((uint8_t)0x0C)     		/*!< Only SSEC[11:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14_13       ((uint8_t)0x0D)     		/*!< Only SSEC[12:0]valid. */
    #define RTC_SUB_SECOND_MASK_SSEC14          ((uint8_t)0x0E)     		/*!< Only SSEC[13:0]valid. */
    #define RTC_SUB_SECOND_MASK_NONE            ((uint8_t)0x0F)     		/*!< SSEC[14:0] valid, must match to activate alarm. */
/**
  * @}
  */


/** @defgroup RTC_output_source RTC output source
  * @{
  */

#define RTC_OUTPUT_SOURCE_DISABLE       		((uint32_t)0x00000000)      /*!< Rtc output clock suorce disable. */
#define RTC_OUTPUT_SOURCE_ALARM         		((uint32_t)0x00200000)      /*!< Select alarm output clock suorce. */
#define RTC_OUTPUT_SOURCE_WAKEUP        		((uint32_t)0x00600000)      /*!< Select wakeup output clock suorce. */
/**
  * @}
  */

/*! Checks RTC output source. */
#define RTC_OUTPUT_SOURCE_CHECK(output)     	(((output) == RTC_OUTPUT_SOURCE_DISABLE) || \
                                            	((output) == RTC_OUTPUT_SOURCE_ALARM)   || \
                                            	((output) == RTC_OUTPUT_SOURCE_WAKEUP))


/** @defgroup RTC_output_polarity RTC output polarity
  * @{
  */

#define RTC_OUTPUT_POLARITY_HIGH        		((uint32_t)0x00000000)      /*!< Set alarm polarity output high. */
#define RTC_OUTPUT_POLARITY_LOW         		((uint32_t)0x00100000)      /*!< Set alarm polarity output low. */
/**
  * @}
  */

/*! Checks RTC output polarity. */
#define RTC_OUTPUT_POLARITY_CHECK(pol)      	(((pol) == RTC_OUTPUT_POLARITY_HIGH) || ((pol) == RTC_OUTPUT_POLARITY_LOW))


/** @defgroup RTC_daylight_saving RTC daylight saving
  * @{
  */

#define RTC_DAYLIGHT_SAVING_DEC1H       		((uint32_t)0x00020000)      /*!< Select winter time (sub one hour). */
#define RTC_DAYLIGHT_SAVING_INC1H       		((uint32_t)0x00010000)      /*!< Select summer time (add one hour). */
/**
  * @}
  */

/*! Checks RTC daylight saving. */
#define RTC_DAYLIGHT_SAVING_CHECK(saving)       (((saving) == RTC_DAYLIGHT_SAVING_DEC1H) || \
                                                ((saving) == RTC_DAYLIGHT_SAVING_INC1H))


/** @defgroup RTC_daylight_saving_flag RTC daylight saving flag
  * @{
  */

#define RTC_DAYLIGHT_SAVING_FLAG_RESET      	((uint32_t)0x00000000)      /*!< No effect. */
#define RTC_DAYLIGHT_SAVING_FLAG_SET        	((uint32_t)0x00040000)      /*!< Select daylight-saving. */
/**
  * @}
  */

/*! Checks RTC daylight saving flag. */
#define RTC_DAYLIGHT_SAVING_FLAG_CHECK(operation)   (((operation) == RTC_DAYLIGHT_SAVING_FLAG_RESET) || \
                                                    ((operation) == RTC_DAYLIGHT_SAVING_FLAG_SET))


/** @defgroup RTC_output_type RTC output type
  * @{
  */

#define RTC_OUTPUT_OPEN_DRAIN      				((uint32_t)0x00000000)      /*!< Output type open_drain. */
#define RTC_OUTPUT_PUSH_PULL        			((uint32_t)0x00040000)      /*!< Output type push_pull. */
/**
  * @}
  */

/*! Checks RTC output type. */
#define RTC_OUTPUT_TYPE_CHECK(type)     		(((type) == RTC_OUTPUT_OPEN_DRAIN) || ((type) == RTC_OUTPUT_PUSH_PULL))


/** @defgroup RTC_always_on_registers RTC always on registers
  * @{
  */

#define RTC_AO_REGISTER0        				((uint32_t)0x00000000)      /*!< RTC always on register0. */
#define RTC_AO_REGISTER1        				((uint32_t)0x00000001)      /*!< RTC always on register1. */
#define RTC_AO_REGISTER2        				((uint32_t)0x00000002)      /*!< RTC always on register2. */
#define RTC_AO_REGISTER3        				((uint32_t)0x00000003)      /*!<<RTC always on register3. */
#define RTC_AO_REGISTER4        				((uint32_t)0x00000004)      /*!< RTC always on register4. */


/** @defgroup RTC_BIN_DCB_format RTC BIN/DCB format
  * @{
  */

#define RTC_FORMAT_BIN      					((uint32_t)0x00000000)      /*!< Data format bin. */
#define RTC_FORMAT_BCD      					((uint32_t)0x00000001)      /*!< Data format BCD. */
/**
  * @}
  */

/*! Checks RTC BIN/DCB format. */
#define RTC_FORMAT_CHECK(format)        		(((format) == RTC_FORMAT_BIN) || ((format) == RTC_FORMAT_BCD))


/** @defgroup RTC_function_register RTC function register
  * @{
  */

#define RTC_ENABLE_REG_DIR_ACCESS       		RTC->CTR        			/*!< Direct access register. */
#define RTC_ENABLE_REG_WAKEUP           		RTC->CTR        			/*!< Wakeup timer. */
#define RTC_ENABLE_REG_PULLUP_DIS       		RTC->MF         			/*!< Inbreak disable pull up. */
/**
  * @}
  */


/** @defgroup RTC_function_bit RTC function bit
  * @{
  */

#define RTC_ENABLE_BIT_DIR_ACCESS       		RTC_CTR_DAR             	/*!< Direct access register. */
#define RTC_ENABLE_BIT_WAKEUP           		RTC_CTR_WUTE            	/*!< Wakeup timer. */
/**
  * @}
  */


/** @defgroup RTC_interrupt_register RTC interrupt_register
  * @{
  */
#define RTC_INTR_REG_ALARM              		RTC->CTR        			/*!< Alarm interrupt enable. */
#define RTC_INTR_REG_WAKEUP             		RTC->CTR        			/*!< Wakeup interrupt enable. */
/**
  * @}
  */


/** @defgroup RTC_interrupt_bit RTC interrupt bit
  * @{
  */

#define RTC_INTR_BIT_ALARM              		((uint32_t)0x00001000)      /*!< Alarm interrupt enable. */
#define RTC_INTR_BIT_WAKEUP             		((uint32_t)0x00004000)      /*!< Wakeup interrupt enable. */
/**
  * @}
  */


/** @defgroup RTC_flag_register RTC flag register
  * @{
  */

#define RTC_FLAG_REG_DAYLIGHT_SAVING        	RTC->CTR        			/*!< Daylight saving flag. */
#define RTC_FLAG_REG_WAKEUP                 	RTC->STS        			/*!< Wakeup flag. */
#define RTC_FLAG_REG_ALARM                  	RTC->STS        			/*!< Alarm flag. */
#define RTC_FLAG_REG_INITE                  	RTC->STS        			/*!< Initialization mode set. */
#define RTC_FLAG_REG_INITF                  	RTC->STS        			/*!< Initialization mode enter flag. */
#define RTC_FLAG_REG_RSF                    	RTC->STS        			/*!< Synchronization flag. */
#define RTC_FLAG_REG_INITS                  	RTC->STS        			/*!< Initialization status flag. */
#define RTC_FLAG_REG_SHF_BUSY               	RTC->STS        			/*!< Shift busy flag. */
#define RTC_FLAG_REG_WAKEUP_WRITE           	RTC->STS        			/*!< Wakeup write flag. */
/**
  * @}
  */


/** @defgroup RTC_flag_bit RTC flag bit
  * @{
  */

#define RTC_FLAG_BIT_DAYLIGHT_SAVING        	RTC_CTR_SAVEF           	/*!< Daylight saving flag. */
#define RTC_FLAG_BIT_WAKEUP                 	RTC_STS_WUTF            	/*!< Wakeup flag. */
#define RTC_FLAG_BIT_ALARM                  	RTC_STS_ALRF            	/*!< Alarm flag. */
#define RTC_FLAG_BIT_INITE                   	RTC_STS_INITE           	/*!< Initialization mode set. */
#define RTC_FLAG_BIT_INITF                   	RTC_STS_INITF           	/*!< Initialization mode enter flag. */
#define RTC_FLAG_BIT_RSF                     	RTC_STS_RSF             	/*!< Synchronization flag. */
#define RTC_FLAG_BIT_INITS                  	RTC_STS_INITS           	/*!< Initialization status flag. */
#define RTC_FLAG_BIT_SHF_BUSY               	RTC_STS_SHF_BUSY        	/*!< Shift busy flag. */
#define RTC_FLAG_BIT_WAKEUP_WRITE           	RTC_STS_WUTWF           	/*!< Wakeup write flag. */
/**
  * @}
  */


/** @defgroup RTC_wakeup_clock RTC wakeup clock
  * @{
  */

#define RTC_WAKEUP_CLOCK_RTCCLK_DIV16       	((uint32_t)0x00000000)      /*!< RTC wakeup clock is div16. */
#define RTC_WAKEUP_CLOCK_RTCCLK_DIV8        	((uint32_t)0x00000001)      /*!< RTC wakeup clock is div8. */
#define RTC_WAKEUP_CLOCK_RTCCLK_DIV4        	((uint32_t)0x00000002)      /*!< RTC wakeup clock is div4. */
#define RTC_WAKEUP_CLOCK_RTCCLK_DIV2        	((uint32_t)0x00000003)      /*!< RTC wakeup clock is div2. */
#define RTC_WAKEUP_CLOCK_SPRE_16BITS        	((uint32_t)0x00000004)      /*!< RTC wakeup clock is spre16. */
#define RTC_WAKEUP_CLOCK_SPRE_17BITS        	((uint32_t)0x00000007)      /*!< RTC wakeup clock is spre17. */
/**
  * @}
  */

/*! Checks RTC wakeup clock. */
#define RTC_WAKEUP_CLOCK_CHECK(clk)     		(((clk) == RTC_WAKEUP_CLOCK_RTCCLK_DIV16) || \
                                         		((clk) == RTC_WAKEUP_CLOCK_RTCCLK_DIV8)  || \
                                         		((clk) == RTC_WAKEUP_CLOCK_RTCCLK_DIV4)  || \
                                         		((clk) == RTC_WAKEUP_CLOCK_RTCCLK_DIV2)  || \
                                         		((clk) == RTC_WAKEUP_CLOCK_SPRE_16BITS)  || \
                                         		((clk) == RTC_WAKEUP_CLOCK_SPRE_17BITS))
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup RTC_Exported_Functions RTC Exported Functions
  * @{
  */

/**
  * @brief  Deinitializes the RTC registers to their default reset values.
  * @param  None.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
#define __RTC_DEF_INIT()                            ((rtc_def_init() & SUCCESS) ? SUCCESS: ERROR)

/**
  * @brief  Enables the RTC registers write protection.It can be writed to a wrong key reactivates the write protection.
  *         The protection mechanism is not affected by system reset.
  * @param  None.
  * @return None.
  */
#define __RTC_WRITE_PROTECTION_ENABLE()              (RTC->CCODE = 0xFF)

/**
  * @brief  Disables the RTC registers write protection.
  * @param  None.
  * @return None.
  */
#define __RTC_WRITE_PROTECTION_DISABLE()            do{ \
                                                         (RTC->CCODE = 0xCA); \
                                                         (RTC->CCODE = 0x53); \
                                                      }while(0)

/**
  * @brief  Exits the RTC initialization mode.
  * @param  None.
  * @return None.
  */
#define __RTC_INIT_MODE_EXIT()                      (RTC->STS &= ~RTC_STS_INITE)

/**
  * @brief  Configures the RTC alarm subseconds value and mask. 
  * @param  VALUE: It can be a value from 0 to 0x00007FFF.
  * @param  MASK: Specifies the subseconds mask bits (RTC_ACFG2 SSEC[14:0]).
  *         It can be one of following values:
  *          @arg RTC_SUB_SECOND_MASK_ALL
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_1
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_2
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_3
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_4
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_5
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_6
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_7
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_8
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_9
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_10
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_11
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_12
  *          @arg RTC_SUB_SECOND_MASK_SSEC14_13
  *          @arg RTC_SUB_SECOND_MASK_SSEC14
  *          @arg RTC_SUB_SECOND_MASK_NONE
  * @note   This function is performed only when the Alarm is disabled. The precondition of calling this interface is 
  *         the write protection is disabled.
  * @return None.
  */
#define __RTC_ALARM_SUBSEC_CONFIG(VALUE, MASK)      (RTC->ACFG2 = (VALUE | ((uint32_t)MASK << 24)))

/**
  * @brief  Gets the RTC alarm subseconds value.
  * @param  None.
  * @return RTC alarm subseconds value.
  */
#define __RTC_ALARM_SUBSEC_GET()                    (RTC->ACFG2 & RTC_ACFG2_SSEC)

/**
  * @brief Writes a data in the specified AO (always on) registers.
  * @param  REG: AO (always on) registers number.
  *         It can beo one of following values:
  *          @arg RTC_AO_REGISTER0: RTC always on register0.
  *          @arg RTC_AO_REGISTER1: RTC always on register1.
  *          @arg RTC_AO_REGISTER2: RTC always on register2.
  *          @arg RTC_AO_REGISTER3: RTC always on register3.
  *          @arg RTC_AO_REGISTER4: RTC always on register4.
  * @param  VALUE: Data to be written in the specified AO (always on) registers.
  * @return None.
  */
#define __RTC_AO_REGISTER_WRITE(REG, VALUE)         (*(__IO uint32_t *)(RTC_BASE + 0x50 + REG * 4) = VALUE)

/**
  * @brief  Reads data from the specified AO (always on) registers.
  * @param  REG: AO (always on) registers number.
  *         It can beo one of following values:
  *          @arg RTC_AO_REGISTER0: RTC always on register0.
  *          @arg RTC_AO_REGISTER1: RTC always on register1.
  *          @arg RTC_AO_REGISTER2: RTC always on register2.
  *          @arg RTC_AO_REGISTER3: RTC always on register3.
  *          @arg RTC_AO_REGISTER4: RTC always on register4.
  * @return the value of the specified AO (always on) registers.
  */
#define __RTC_AO_REGISTER_READ(REG)                 (*(__IO uint32_t *)(RTC_BASE + 0x50 + REG * 4))

/**
  * @brief  Enables the specified RTC function. Note that the precondition of is the write protection is disabled when
  *         direct access register and calibration output is enabled.
  * @param  FUNC: Specifies the RTC function.
  *         It can be one of the following values:
  *          @arg DIR_ACCESS: direct access register.
  *          @arg WAKEUP: wakeup timer.
  * @return None.
  */
#define __RTC_FUNC_ENABLE(FUNC)                     ((RTC_ENABLE_REG_##FUNC) |= (RTC_ENABLE_BIT_##FUNC))

/**
  * @brief  Disables the specified RTC function. Note that the precondition of is the write protection is disabled when
  *         direct access register and calibration output is disabled.           
  * @param  FUNC: Specifies the RTC function.
  *         It can be one of the following values:
  *          @arg DIR_ACCESS: direct access register.
  *          @arg WAKEUP: wakeup timer.
  * @return None.
  */
#define __RTC_FUNC_DISABLE(FUNC)                    ((RTC_ENABLE_REG_##FUNC) &= ~(RTC_ENABLE_BIT_##FUNC))

/**
  * @brief  Enables the specified RTC interrupts.
  * @param  INT: Specifies the RTC interrupt sources to be enabled.
  *         It can be any combination of following values:
  *          @arg RTC_INTR_BIT_ALARM: alarm interrupt.
  *          @arg RTC_INTR_BIT_WAKEUP: wakeup interrupt.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
#define __RTC_INTR_ENABLE(INT)                      (RTC->CTR |= (uint32_t)(INT))

/**
  * @brief  Disables the specified RTC interrupts.
  * @param  INT: Specifies the RTC interrupt sources to be disabled.
  *         It can be any combination of following values:
  *          @arg RTC_INTR_BIT_ALARM: alarm interrupt.
  *          @arg RTC_INTR_BIT_WAKEUP: wakeup interrupt.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
#define __RTC_INTR_DISABLE(INT)                     (RTC->CTR &= ~(INT))

/**
  * @brief  Checks whether the specified RTC interrupt enabled or not.
  * @param  INT: Specifies the RTC interrupt sources.
  *         It can be one of following values:
  *          @arg ALARM: alarm interrupt.
  *          @arg WAKEUP: wakeup interrupt.
  * @return SET or RESET.
  */
#define __RTC_INTR_ENABLE_STATUS_GET(INT)           (((RTC_INTR_REG_##INT) & (RTC_INTR_BIT_##INT)) ? SET : RESET)

/**
  * @brief  Checks whether the specified RTC flag is set or not.
  * @param  FLAG: Specifies the RTC_STS register status bit.
  *         It can be one of following values:
  *          @arg DAYLIGHT_SAVING: Daylight saving flag.
  *          @arg WAKEUP: Wakeup flag.
  *          @arg ALARM: Alarm flag.
  *          @arg INITE: Initialization mode set flag.
  *          @arg INITF: Initialization mode enter flag.
  *          @arg RSF: Synchronization flag.
  *          @arg INITS: Nitialization status flag.
  *          @arg SHF_BUSY: Shift busy flag.
  *          @arg WAKEUP_WRITE: Wakeup write flag.
  * @return The new state of set_flag (SET or RESET).
  */
#define __RTC_FLAG_STATUS_GET(FLAG)                 (((RTC_FLAG_REG_##FLAG) & (RTC_FLAG_BIT_##FLAG)) ? SET : RESET)

/**
  * @brief  Checks whether the specified RTC interrupt has occurred or not.
  * @param  INT: Specifies the RTC interrupt source to check.
  *         It can be one of following values:
  *          @arg ALARM: Alarm interrupt.
  *          @arg WAKEUP: Wakeup interrupt.
  * @return SET or RESET.
  */
#define __RTC_INTR_STATUS_GET(INT)                  (__RTC_INTR_ENABLE_STATUS_GET(INT) && __RTC_FLAG_STATUS_GET(INT))

/**
  * @brief  Clears the RTC's pending flags.
  * @param  FLAG: Specifies the flag to clear.
  *         It can be any combination of the following values:
  *          @arg RTC_FLAG_BIT_WAKEUP: Wakeup flag.
  *          @arg RTC_FLAG_BIT_ALRF: Alarm flag.
  *          @arg RTC_FLAG_BIT_RSF: Synchronization flag.
  * @return None.
  */
#define __RTC_FLAG_CLEAR(FLAG)                      (RTC->STS = (~(((FLAG) | RTC_STS_INITE) & 0x0001FFFF) | \
                                                    (RTC->STS & RTC_STS_INITE)))

/**
  * @brief  Deinitializes the RTC registers to their default reset values.
  * @param  None.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_def_init(void);

/**
  * @brief  Initializes the RTC registers according to the specified parameters in ptr_init_struct. RTC prescaler
  *         register can be written in initialization step only.
  * @param  ptr_init_struct: Pointer to a rtc_init_t structure that contains the configuration information for the RTC
  *         peripheral.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_init(rtc_init_t* ptr_init_struct);

/**
  * @brief  Fills each rtc_init_struct member with its default value.
  * @param  ptr_init_struct: Pointer to a ptr_init_struct structure which will be initialized.
  * @return None.
  */
void rtc_struct_init(rtc_init_t* ptr_init_struct);

/**
  * @brief  Enters the RTC Initialization mode.
  * @param  None.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_init_mode_enter(void);

/**
  * @brief  Waits until the RTC time and date registers (RTC_TIME and RTC_DATE) are synchronized with RTC APB clock.
  * @param  None.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_synchro_wait(void);

/**
  * @brief  Set the RTC current time.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_time_struct: Pointer to a rtc_time_t structure that contains the time config information for the RTC.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_time_set(uint32_t format_flag, rtc_time_t* ptr_time_struct);

/**
  * @brief  Fill each rtc ptr_time_struct member with its default value (00h: 00min: 00sec).
  * @param  ptr_time_struct: Pointer to a rtc_time_t structure which will be initialized.
  * @return None.
  */
void rtc_time_struct_init(rtc_time_t* ptr_time_struct);

/**
  * @brief  Get the RTC current Time.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_time_struct: Pointer to a rtc_time_t structure that will contain the returned current time config.
  * @return None.
  */
void rtc_time_get(uint32_t format_flag, rtc_time_t* ptr_time_struct);

/**
  * @brief  Gets the RTC current calendar subseconds value.
  * @param  None.
  * @return RTC current calendar subseconds value.
  */
uint32_t rtc_subsecond_get(void);

/**
  * @brief  Set the RTC current date.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_date_struct: Pointer to a rtc_date_t structure that contains the date config information for the RTC.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_date_set(uint32_t format_flag, rtc_date_t* ptr_date_struct);

/**
  * @brief  Fills each rtc_date_struct member with its default value (Monday, January 01 xx00).
  * @param  ptr_date_struct: Pointer to a rtc_date_t structure which will be initialized.
  * @return None.
  */
void rtc_date_struct_init(rtc_date_t* ptr_date_struct);

/**
  * @brief  Get the RTC current date.
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_date_struct: Pointer to a rtc_date_t struct that will contain the returned current date configuration.
  * @return None.
  */
void rtc_date_get(uint32_t format_flag, rtc_date_t* ptr_date_struct);

/**
  * @brief  Set the specified RTC Alarm. The Alarm register can only be written when the corresponding alarm is disabled
  *         (Use the rtc_alarm_enable_ctrl(DISABLE)).
  * @param  format_flag: It can be Binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_alarm_struct: Pointer to a rtc_alarm_t structure that contains the alarm configuration parameters.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_alarm_set(uint32_t format_flag, rtc_alarm_t* ptr_alarm_struct);

/**
  * @brief  Fill each rtc ptr_alarm_struct member with its default value (time  = 00h: 00mn: 00sec // Date = 1st day of
  *         the month // Mask = all fields are not masked).
  * @param  ptr_alarm_struct: Pointer to a @ref rtc_alarm_t structure which will be initialized.
  * @return None.
  */
void rtc_alarm_struct_init(rtc_alarm_t* ptr_alarm_struct);

/**
  * @brief  Get the RTC alarm value and masks.
  * @param  format_flag: It can be binary data format (RTC_FORMAT_BIN), or BCD data format (RTC_FORMAT_BCD).
  * @param  ptr_alarm_struct: Pointer to a rtc_alarm_t struct that will contains the output alarm configuration values.
  * @return None.
  */
void rtc_alarm_get(uint32_t format_flag, rtc_alarm_t* ptr_alarm_struct);

/**
  * @brief  Enables or disables the specified RTC alarm. 
  * @param  enable_flag: It can be: ENABLE or DISABLE.
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return Execute status: SUCCESS or ERROR.
  */
error_status_t rtc_alarm_enable_ctrl(enable_state_t enable_flag);

/**
  * @brief  Configures the RTC wakeup clock source only. The WakeUp Clock source can only be changed when the RTC wakeup
  *         is disabled (Use the rtc_wakeup_enable_ctrl(DISABLE)). 
  * @param  wakeup_clk: It can be one of the following values:
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV16
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV8
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV4
  *          @arg RTC_WAKEUP_CLOCK_RTCCLK_DIV2
  *          @arg RTC_WAKEUP_CLOCK_SPRE_16BITS
  *          @arg RTC_WAKEUP_CLOCK_SPRE_17BITS
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_wakeup_clock_config(uint32_t wakeup_clk); 

/**
  * @brief  Adds or substract one hour from the current time. 
  * @param  save_time_value: It can be one of the following values:
  *          @arg RTC_DAYLIGHT_SAVING_DEC1H: Substract one hour.
  *          @arg RTC_DAYLIGHT_SAVING_INC1H: Add one hour.
  * @param  flag: specifies the value to be written in the SAVEF bit.
  *         It can be one of the following values:
  *          @arg RTC_DAYLIGHT_SAVING_FLAG_RESET
  *          @arg RTC_DAYLIGHT_SAVING_FLAG_SET
  * @note   The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_daylight_saving_config(uint32_t save_time_value, uint32_t flag);

/**
  * @brief  Configures the RTC output source. 
  * @param  config_value: It can be one of the following values:
  *          @arg RTC_OUTPUT_SOURCE_DISABLE: Rtc output clock suorce disable).
  *          @arg RTC_OUTPUT_SOURCE_ALARM: Select alarm output clock suorce).
  *          @arg RTC_OUTPUT_SOURCE_WAKEUP: Select wakeup output clock suorce).
  * @param   config_polarity: It can be one of the following values:
  *          @arg RTC_OUTPUT_POLARITY_HIGH: Output pin is high).
  *          @arg RTC_OUTPUT_POLARITY_LOW: Output pin is low).
  * @note    The precondition of calling this interface is the write protection is disabled.
  * @return None.
  */
void rtc_output_config(uint32_t config_value, uint32_t config_polarity);

/**
  * @brief  Configures the RTC output pin mode. 
  * @param  output_type: Specifies the RTC Output (PC13) pin mode.
  *         It can be one of the following values:
  *          @arg RTC_OUTPUT_OPEN_DRAIN: RTC output is configured in open drain mode.
  *          @arg RTC_OUTPUT_PUSH_PULL: RTC output is configured in push pull mode.
  * @return None.
  */
void rtc_output_type_config(uint32_t output_type);

/**
  * @brief  Sets the wakeup reload value.
  * @param  reload_vlaue: Select reload value.
  * @return None.
  */
void rtc_wakeup_reload_value_set(uint16_t reload_vlaue);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_rtc.h */


/**
  * @}
  */

/**
  * @}
  */
