/**
* @file        cbm858xm_fwdt.h
* @brief       This file contains all the functions prototypes for the FWDT firmware library. 
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


#ifndef __CBM858xM_FWDT_H__
#define __CBM858xM_FWDT_H__


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

/** @addtogroup FWDT
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup FWDT_Exported_Constants FWDT Exported Constants
  * @{
  */

/** @defgroup FWDT_write_access FWDT write access
  * @{
  */

#define FWDT_WRITE_ACCESS_ENABLE        	((uint16_t)0x5555)      /*!< FWDT write access enable. */
#define FWDT_WRITE_ACCESS_DISABLE       	((uint16_t)0x0000)      /*!< FWDT write access disable. */
/**
  * @}
  */


/** @defgroup FWDT_CCODE_register_bit_mask FWDT CCODE register bit mask
  * @{
  */

#define CCODE_CCODE_RELOAD              	((uint16_t)0xAAAA)      /*!< Reload counter. */
#define CCODE_CCODE_ENABLE              	((uint16_t)0xCCCC)      /*!< FWDT enable. */
/**
  * @}
  */


/** @defgroup FWDT_prescaler_selection FWDT prescaler selection
  * @{
  */

#define FWDT_PRESCALER_4        			((uint8_t)0x00)         /*!< FWDT prescaler divider 4. */
#define FWDT_PRESCALER_8        			((uint8_t)0x01)         /*!< FWDT prescaler divider 8. */
#define FWDT_PRESCALER_16       			((uint8_t)0x02)         /*!< FWDT prescaler divider 16. */
#define FWDT_PRESCALER_32       			((uint8_t)0x03)         /*!< FWDT prescaler divider 32. */
#define FWDT_PRESCALER_64       			((uint8_t)0x04)         /*!< FWDT prescaler divider 64. */
#define FWDT_PRESCALER_128      			((uint8_t)0x05)         /*!< FWDT prescaler divider 128. */
#define FWDT_PRESCALER_256      			((uint8_t)0x06)         /*!< FWDT prescaler divider 256. */
/**
  * @}
  */


/** @defgroup FWDT_flags FWDT flags
  * @{
  */

#define FWDT_FLAG_DRF       				FWDT_STS_DRF            /*!< Prescaler value update flag. */
#define FWDT_FLAG_UVRF      				FWDT_STS_UVRF           /*!< Reload value update flag. */
#define FWDT_FLAG_WRF       				FWDT_STS_WRF            /*!< Window value update flag. */
/**
  * @}
  */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup FWDT_Exported_Functions FWDT Exported Functions
  * @{
  */

/**
  * @brief  Enables write access to FWDT_PDIV and FWDT_UVAL registers.
  * @param  None.
  * @return None.
  */
#define __FWDT_WRITE_ACCESS_ENABLE()        (FWDT->CCODE = FWDT_WRITE_ACCESS_ENABLE)

/**
  * @brief  Disables write access to FWDT_PDIV and FWDT_UVAL registers.
  * @param  None.
  * @return None.
  */
#define __FWDT_WRITE_ACCESS_DISABLE()       (FWDT->CCODE = FWDT_WRITE_ACCESS_DISABLE)

/**
  * @brief  Reloads FWDT counter with value defined in the reload register.
  * @param  None.
  * @return None.
  */
#define __FWDT_RELOAD_COUNTER()             (FWDT->CCODE = CCODE_CCODE_RELOAD)

/**
  * @brief  Enables FWDT.
  * @note   Write access to FWDT_PDIV and FWDT_UVAL registers disabled.
  * @param  None.
  * @return None.
  */
#define __FWDT_ENABLE()                     (FWDT->CCODE = CCODE_CCODE_ENABLE)

/**
  * @brief  Sets FWDT Prescaler value.
  * @param  VALUE: Specifies the FWDT Prescaler value.
  *         It can be one of the following values:
  *          @arg FWDT_PRESCALER_4: FWDT prescaler set to 4.
  *          @arg FWDT_PRESCALER_8: FWDT prescaler set to 8.
  *          @arg FWDT_PRESCALER_16: FWDT prescaler set to 16.
  *          @arg FWDT_PRESCALER_32: FWDT prescaler set to 32.
  *          @arg FWDT_PRESCALER_64: FWDT prescaler set to 64.
  *          @arg FWDT_PRESCALER_128: FWDT prescaler set to 128.
  *          @arg FWDT_PRESCALER_256: FWDT prescaler set to 256.
  * @return None.
  */
#define __FWDT_PRESCALER_CONFIG(VALUE)      (FWDT->PDIV = (VALUE))

/**
  * @brief  Sets FWDT reload value.
  * @param  VALUE: Specifies the FWDT Reload value.
  * @note   This parameter must be a number between 0 and 0x0FFF.
  * @return None.
  */
#define __FWDT_RELOAD_VALUE_SET(VALUE)      (FWDT->UVAL = (0x0FFF & VALUE))

/**
  * @brief  Checks whether the specified FWDT flag is set or not.
  * @param  FLAG: Specifies the flag to check.
  *         It can be one of the following values:
  *          @arg FWDT_FLAG_DRF: Prescaler value update flag.
  *          @arg FWDT_FLAG_UVRF: Reload value update flag.
  *          @arg FWDT_FLAG_WRF: Window value update flag.
  * @return Bit status (SET or RESET).
  */
#define __FWDT_FLAG_STATUS_GET(FLAG)        ((FWDT->STS & (FLAG)) ? SET : RESET)

/**
  * @brief  Sets the FWDT window value.
  * @param  VALUE: Specifies the window value to be compared to the downcounter.
  * @note   This parameter must be a number between 0 and 0x0FFF.
  * @return None.
  */
#define __FWDT_WINDOW_VALUE_SET(VALUE)      (FWDT->WINVAL = (VALUE))

/**
  * @brief  Gets the FWDT window value.
  * @note   This parameter must be a number between 0 and 0x0FFF.
  * @param  None.
  * @return FWDT window value.
  */
#define __FWDT_WINDOW_VALUE_GET()           ((FWDT->WINVAL) & 0xFFF)
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_fwdt.h */


/**
  * @}
  */

/**
  * @}
  */
