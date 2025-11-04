/**
* @file        cbm858xm_conf.h
* @brief       This file contains all the functions prototypes for the configure firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.04.26
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.04.26    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_CONF_H__
#define __CBM858xM_CONF_H__


#ifdef __cplusplus
 extern "C" {
#endif


/***************************************************************************************************
 * @includes
***************************************************************************************************/


/** @addtogroup CBM858xM_StdPeriph_Driver
  * @{
  */

/** @addtogroup CONFIG
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup Conf_Exported_Types CONF Exported Types
  * @{
  */

/**
  * @}
  */


/** @defgroup CONF_Exported_Constants CONF Exported Constants
  * @{
  */

//Fill the content
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup CONF_Exported_Functions CONF Exported Functions
  * @{
  */

/** @brief Uncomment the line below to expanse the "ASSERT" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1 */

#ifdef  USE_FULL_ASSERT
/** @brief  The ASSERT macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed. 
  *         If expr is true, it returns no value.
  * @retval None
  */
#define ASSERT(expr) ((expr) ? (void)0 : assert_failed((unsigned char *)__FILE__, __LINE__))

/** @brief  Reports the name of the file and the  line number error.
  * @param  fileName: pointer to the  file name
  * @param  line:  error line  number
  * @return None
  */
void assert_failed(unsigned char* file, unsigned int line);

#else
#define ASSERT(expr) ((void)0)
#endif 
/**
  * @}
  */



#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_conf.h */


/**
  * @}
  */

/**
  * @}
  */
