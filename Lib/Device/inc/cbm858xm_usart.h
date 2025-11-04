/**
* @file        cbm858xm_usart.h
* @brief       This file contains all the functions prototypes for the USART firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.19
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.19    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_USART_H__
#define __CBM858xM_USART_H__


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

/** @addtogroup USART
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup USART_Exported_Types USART Exported Types
  * @{
  */

/** @struct usart_config_t
  * @brief  USART base configuration structure definition.
  */
typedef struct
{
    uint32_t baud_rate;         /*!< Specifies the USART baud rate, It supports up to 1M bit/s. */

    uint32_t data_width;        /*!< Specifies the data width, it can be one of the following values: @ref
                                     USART_data_width. */

    uint32_t stop_bits;         /*!< Specifies the number of stop bits, it can be one of the following values: @ref
                                     USART_stop_bits. */

    uint32_t parity;            /*!< Specifies the parity mode, it can be one of the following values: @ref
                                     USART_parity. */

    uint32_t usart_mode;        /*!< Specifies the USART transmite mode, it can be one of the following values: @ref
                                     USART_transmite_mode. */

    uint32_t flow_control;      /*!< Specifies the hardware flow control mode, it can be one of the following values:
                                     @ref USART_flow_control. */
}usart_config_t;


/** @struct usart_clock_t
  * @brief  USART Clock Init Structure definition.
  */
typedef struct
{
    uint32_t clock_flag;        /*!< Enabled or disabled the USART clock, it can be one of the following values: @ref
                                     USART_clock_enable. */

    uint32_t usart_cpol;        /*!< Specifies the steady state of the serial clock Polarity, it can be one of the
                                     following values: @ref USART_clock_polarity. */

    uint32_t usart_cpha;        /*!< Specifies the clock Phase, it can be one of the following values: @ref
                                     USART_clock_phase. */

    uint32_t usart_lastbit;     /*!< Specifies whether the clock pulse corresponding to the last transmitted data bit
                                     (MSB) has to be output on the SCLK pin in synchronous mode, it can be one of the
                                     following values: @ref USART_lastbit. */
}usart_clock_t;
/**
  * @}
  */


/** @defgroup USART_Exported_Constants USART Exported Constants
  * @{
  */


/*! Checks USART definition. */
#define USART_SELECT_CHECK(select)          	(((select) == USART1) || ((select) == USART2))

#define USART_SELECT_12_CHECK(select)       	(((select) == USART1) || ((select) == USART2))

#define USART_SELECT_1_CHECK(select)        	(((select) == USART1))


/** @defgroup  USART_data_width USART data width
  * @{
  */

#define USART_DATA_WIDTH_7      				((uint32_t)0x10001000)      			/*!< USART transmit data_width 7 bits. */
#define USART_DATA_WIDTH_8      				((uint32_t)0x00000000)      			/*!< USART transmit data_width 8 bits. */
#define USART_DATA_WIDTH_9      				(USART_CTR1_DL)               			/*!< USART transmit data_width 9 bits. */
/**
  * @}
  */

/*! Checks USART data width. */
#define USART_DATA_WIDTH_CHECK(length)      	(((length) == USART_DATA_WIDTH_8) || ((length) == USART_DATA_WIDTH_9) || \
                                            	((length) == USART_DATA_WIDTH_7))


/** @defgroup  USART_stop_bits USART stop bits
  * @{
  */

#define USART_STOP_BIT_0_5      				(USART_CTR2_STOPLEN_0)        			/*!< USART transmit 0.5 stop bit. */
#define USART_STOP_BIT_1        				((uint32_t)0x00000000)      			/*!< USART transmit 1 stop bit. */
#define USART_STOP_BIT_2        				(USART_CTR2_STOPLEN_1)        			/*!< USART transmit 2 stop bits. */
#define USART_STOP_BIT_1_5      				(USART_CTR2_STOPLEN)          			/*!< USART transmit 1.5 stop bits. */
/**
  * @}
  */

/*! Checks USART stop bits. */
#define USART_STOP_BIT_CHECK(stopbits)      	(((stopbits) == USART_STOP_BIT_0_5) || ((stopbits) == USART_STOP_BIT_1) || \
                                            	((stopbits) == USART_STOP_BIT_2)   || ((stopbits) == USART_STOP_BIT_1_5))


/** @defgroup USART_parity USART parity
  * @{
  */

#define USART_PARITY_NO         				((uint32_t)0x00000000)                  /*!< USART with no parity. */
#define USART_PARITY_EVEN       				(USART_CTR1_PEN)                        /*!< USART with even parity. */
#define USART_PARITY_ODD        				(USART_CTR1_PEN | USART_CTR1_ODDS)      /*!< USART with odd parity. */
/**
  * @}
  */

/*! Checks USART parity. */
#define USART_PARITY_CHECK(parity)          	(((parity) == USART_PARITY_NO) || ((parity) == USART_PARITY_EVEN) || \
                                            	((parity) == USART_PARITY_ODD))


/** @defgroup USART_transmite_mode USART transmite mode
  * @{
  */

#define USART_MODE_RX       					(USART_CTR1_REN)      					/*!< USART receiver enable. */
#define USART_MODE_TX       					(USART_CTR1_TEN)      					/*!< USART transmitter enable. */
/**
  * @}
  */

/*! Checks USART transmite mode. */
#define USART_MODE_CHECK(mode)      			((((mode) & (uint32_t)0xFFFFFFF3) == 0x00) && ((mode) != (uint32_t)0x00))


/** @defgroup USART_flow_control USART flow control
  * @{
  */

#define USART_FLOW_CONTROL_NONE         		((uint32_t)0x00000000)                  /*!< USART no flow control. */
#define USART_FLOW_CONTROL_RTS          		(USART_CTR3_RTSEN)                      /*!< USART RTS flow control. */
#define USART_FLOW_CONTROL_CTS          		(USART_CTR3_CTSEN)                      /*!< USART CTS flow control. */
#define USART_FLOW_CONTROL_RTS_CTS      		(USART_CTR3_RTSEN | USART_CTR3_CTSEN)   /*!< USART RTC_CTS flow control. */
/**
  * @}
  */

/*! Checks USART flow control. */
#define USART_FLOW_CONTROL_CHECK(flag)      	(((flag) == USART_FLOW_CONTROL_NONE) || \
                                            	((flag) == USART_FLOW_CONTROL_RTS)  || \
                                            	((flag) == USART_FLOW_CONTROL_CTS)  || \
                                            	((flag) == USART_FLOW_CONTROL_RTS_CTS))


/** @defgroup USART_clock_enable USART clock enable
  * @{
  */

#define USART_CLOCK_DISABLE     				((uint32_t)0x00000000)      			/*!< CK pin disable. */
#define USART_CLOCK_ENABLE      				(USART_CTR2_CKEN)             			/*!< CK pin enable. */
/**
  * @}
  */

/*! Checks USART clock enable. */
#define USART_CLOCK_CHECK(clock)        		(((clock) == USART_CLOCK_DISABLE) || ((clock) == USART_CLOCK_ENABLE))


/** @defgroup USART_clock_polarity USART clock polarity
  * @{
  */

#define USART_CPOL_LOW      					((uint32_t)0x00000000)      /*!< USART clock polarity output low level when idle. */
#define USART_CPOL_HIGH     					(USART_CTR2_CPOL)           /*!< USART clock polarity output high level when idle. */
/**
  * @}
  */

/*! Checks USART clock polarity. */
#define USART_CPOL_CHECK(cpol)      			(((cpol) == USART_CPOL_LOW) || ((cpol) == USART_CPOL_HIGH))


/** @defgroup USART_clock_phase USART clock phase
  * @{
  */

#define USART_CPHA_EDGE_1       				((uint32_t)0x00000000)      /*!< USART sampling data at the first edge. */
#define USART_CPHA_EDGE_2       				(USART_CTR2_CPHA)           /*!< USART sampling data at the second edge. */
/**
  * @}
  */

/*! Checks USART clock phase. */
#define USART_CPHA_CHECK(cpha)      			(((cpha) == USART_CPHA_EDGE_1) || ((cpha) == USART_CPHA_EDGE_2))


/** @defgroup USART_lastbit USART lastbit
  * @{
  */

#define USART_LAST_BIT_DISABLE      			((uint32_t)0x00000000)      /*!< USART Lastbit disable. */
#define USART_LAST_BIT_ENABLE       			(USART_CTR2_CKLEN)          /*!< USART Lastbit enable. */
/**
  * @}
  */

/*! Checks USART lastbit. */
#define USART_LAST_BIT_CHECK(flag)      		(((flag) == USART_LAST_BIT_DISABLE) || ((flag) == USART_LAST_BIT_ENABLE))


/** @defgroup USART_wakeup USART wakeup
  * @{
  */

#define USART_RX_WAKEUP_IDLE_LINE       		((uint32_t)0x00000000)      /*!< USART receiver wakeup by an idle line. */
#define USART_RX_WAKEUP_ADDR_MARK       		(USART_CTR1_RXWKUPS)        /*!< USART receiver wakeup by an address mark. */
/**
  * @}
  */

/*! Checks USART wakeup. */
#define USART_RX_WAKEUP_CHECK(flag)     		((((flag)) == USART_RX_WAKEUP_IDLE_LINE) || \
                                         		(((flag)) == USART_RX_WAKEUP_ADDR_MARK))


/** @defgroup USART_address_length USART address length
  * @{
  */

#define USART_ADDRESS_4BIT      				((uint32_t)0x00000000)      /*!< USART 4 bits address detection selection. */
#define USART_ADDRESS_7BIT      				(USART_CTR2_ADRM7)          /*!< USART 7 bits address detection selection. */
/**
  * @}
  */

/*! Checks USART address length. */
#define USART_ADDRESS_BIT_CHECK(addr)       	(((addr) == USART_ADDRESS_4BIT) || ((addr) == USART_ADDRESS_7BIT))


/** @defgroup USART_wakeup_methods USART wakeup methods
  * @{
  */

#define USART_WAKEUP_SOURCE_ADDR_MATCH      	((uint32_t)0x00000000)      /*!< USART wakeup with address matched. */
#define USART_WAKEUP_SOURCE_START_BIT       	(USART_CTR3_WKUPMTHD_1)     /*!< USART wakeup with start bit. */
#define USART_WAKEUP_SOURCE_RXNE            	(USART_CTR3_WKUPMTHD)       /*!< USART wakeup with RXNE. */
/**
  * @}
  */

/*! Checks USART wakeup methods. */
#define USART_WAKEUP_SOURCE_CHECK(flag)     	(((flag) == USART_WAKEUP_SOURCE_ADDR_MATCH) || \
                                            	((flag) == USART_WAKEUP_SOURCE_START_BIT)  || \
                                            	((flag) == USART_WAKEUP_SOURCE_RXNE))


/** @defgroup USART_lin_break USART lin break
  * @{
  */

#define USART_LIN_BREAK_10BIT       			((uint32_t)0x00000000)      /*!< USART 10-bit break from frame detection. */
#define USART_LIN_BREAK_11BIT       			(USART_CTR2_LINBRK11)       /*!< USART 11-bit break from frame detection. */
/**
  * @}
  */

/*! Checks USART lin break. */
#define USART_LIN_BREAK_BIT_CHECK(flag)     	(((flag) == USART_LIN_BREAK_10BIT) || ((flag) == USART_LIN_BREAK_11BIT))


/** @defgroup USART_IRDA_mode USART IRDA mode
  * @{
  */

#define USART_IRDA_MODE_LP          			(USART_CTR3_IRMS)           /*!< USART IRDA low power mode. */
#define USART_IRDA_MODE_NORMAL      			((uint32_t)0x00000000)      /*!< USART IRDA normal mode. */
/**
  * @}
  */

/*! Checks USART IRDA mode. */
#define USART_IRDA_MODE_CHECK(select)       	(((select) == USART_IRDA_MODE_LP) || ((select) == USART_IRDA_MODE_NORMAL))


/** @defgroup USART_driver_polarity USART driver polarity
  * @{
  */

#define USART_DE_POLARITY_HIGH      			((uint32_t)0x00000000)      /*!< USART driver polarity with high level. */
#define USART_DE_POLARITY_LOW       			(USART_CTR3_DEPS)           /*!< USART driver polarity with low level. */
/**
  * @}
  */

/*! Checks USART driver polarity. */
#define USART_DE_POLARITY_CHECK(flag)       	(((flag) == USART_DE_POLARITY_LOW) || ((flag) == USART_DE_POLARITY_HIGH))


/** @defgroup USART_auto_baud_rate_mode USART auto baud rate mode
  * @{
  */

#define USART_AUTO_RATE_MEASURE_START_BIT       ((uint32_t)0x00000000)      /*!< Measurement start bit. */
#define USART_AUTO_RATE_MEASURE_FALLING_EDGE    (USART_CTR2_ABRSEL_0)       /*!< Measure the falling edge. */
/**
  * @}
  */

/*! Checks USART auto baud rate mode. */
#define USART_AUTO_RATE_MEASURE_CHECK(flag)     (((flag) == USART_AUTO_RATE_MEASURE_START_BIT) || \
                                                ((flag) == USART_AUTO_RATE_MEASURE_FALLING_EDGE))


/*! Checks USART baud rate. */
#define USART_BAUD_RATE_CHECK(rate)     		(((rate) > 0) && ((rate) <= 1000000))


/*! Checks USART RS485 driver preactive time. */
#define USART_DE_PREACTIVE_TIME_CHECK(time)     (((time)) <= 0x1F)


/*! Checks USART RS485 driver proactive time. */
#define USART_DE_PROACTIVE_TIME_CHECK(time)     (((time)) <= 0x1F)


/*! Checks USART retry num. */
#define USART_RETRY_NUM_CHECK(counter)      	((counter) <= 0x7)


/*! Checks USART time_out. */
#define USART_TIMEOUT_CHECK(timeout)        	((timeout) <= 0x00FFFFFF)


/** @defgroup USART_function_enable_registers USART function enable registers
  * @{
  */

#define USART_ENABLE_REG_RX                 	CTR1        				/*!< RX enable register. */
#define USART_ENABLE_REG_TX                 	CTR1        				/*!< TX enable register. */
#define USART_ENABLE_REG_OVERSAMPLING       	CTR1        				/*!< Oversampling enable register. */
#define USART_ENABLE_REG_SAMPLE_METHOD      	CTR3        				/*!< Sample method enable register. */
#define USART_ENABLE_REG_MSB_FIRST          	CTR2        				/*!< MSB first enable register. */
#define USART_ENABLE_REG_DATA_INVERSE       	CTR2        				/*!< Data bit inversion enable register. */
#define USART_ENABLE_REG_RX_INVERSE         	CTR2        				/*!< RX pin inversion enable register. */
#define USART_ENABLE_REG_TX_INVERSE         	CTR2        				/*!< TX pin inversion enable register. */
#define USART_ENABLE_REG_PIN_SWAP           	CTR2        				/*!< TX/RX pins swap enable register. */
#define USART_ENABLE_REG_RECV_OVERTIME      	CTR2        				/*!< Receive overtime enable register. */
#define USART_ENABLE_REG_STOP_MODE          	CTR1        				/*!< Stop mode enable register. */
#define USART_ENABLE_REG_AUTO_BAUDRATE      	CTR2        				/*!< Auto baud rate enable register. */
#define USART_ENABLE_REG_RECV_MASK          	CTR1        				/*!< Receive mask enable register. */
#define USART_ENABLE_REG_LIN_MODE           	CTR2        				/*!< Lin mode enable register. */
#define USART_ENABLE_REG_HALF_DUPLEX        	CTR3        				/*!< Half duplex enable register. */
#define USART_ENABLE_REG_SMARTCARD          	CTR3        				/*!< Smart card enable register. */
#define USART_ENABLE_REG_SMARTCARD_NACK     	CTR3        				/*!< Smart card nack enable register. */
#define USART_ENABLE_REG_IRDA               	CTR3        				/*!< IRDA enable register. */
#define USART_ENABLE_REG_DRIVER             	CTR3        				/*!< Driver enable register. */
#define USART_ENABLE_REG_NORXOF             	CTR3        				/*!< Receive overflow detection off enable register. */
#define USART_ENABLE_REG_DMAMASK            	CTR3        				/*!< DMA request mask enable register. */
/**
  * @}
  */


/** @defgroup USART_function_enable_bits USART function enable bits
  * @{
  */

#define USART_ENABLE_BIT_RX                 	USART_CTR1_REN          	/*!< RX enable bit. */
#define USART_ENABLE_BIT_TX                 	USART_CTR1_TEN          	/*!< TX enable bit. */
#define USART_ENABLE_BIT_OVERSAMPLING       	USART_CTR1_OVRS         	/*!< Oversampling enable bit. */
#define USART_ENABLE_BIT_SAMPLE_METHOD      	USART_CTR3_SPMS         	/*!< Sample method enable bit. */
#define USART_ENABLE_BIT_MSB_FIRST          	USART_CTR2_MSBF         	/*!< MSB first enable bit. */
#define USART_ENABLE_BIT_DATA_INVERSE       	USART_CTR2_DINV         	/*!< Data bit inversion enable bit. */
#define USART_ENABLE_BIT_RX_INVERSE         	USART_CTR2_RXINV        	/*!< RX pin inversion enable bit. */
#define USART_ENABLE_BIT_TX_INVERSE         	USART_CTR2_TXINV        	/*!< TX pin inversion enable bit. */
#define USART_ENABLE_BIT_PIN_SWAP           	USART_CTR2_TXRXSWAP     	/*!< TX/RX pins swap enable bit. */
#define USART_ENABLE_BIT_RECV_OVERTIME      	USART_CTR2_ROTEN        	/*!< Receive overtime enable bit. */
#define USART_ENABLE_BIT_STOP_MODE          	USART_CTR1_WKUPDSM      	/*!< Stop mode enable bit. */
#define USART_ENABLE_BIT_AUTO_BAUDRATE      	USART_CTR2_ABREN        	/*!< Auto baud rate enable bit. */
#define USART_ENABLE_BIT_RECV_MASK          	USART_CTR1_RXMSKEN      	/*!< Receive mask enable bit. */
#define USART_ENABLE_BIT_LIN_MODE           	USART_CTR2_LINEN        	/*!< Lin mode enable bit. */
#define USART_ENABLE_BIT_HALF_DUPLEX        	USART_CTR3_HDEN         	/*!< Half duplex enable bit. */
#define USART_ENABLE_BIT_SMARTCARD          	USART_CTR3_SCEN         	/*!< Smart card enable bit. */
#define USART_ENABLE_BIT_SMARTCARD_NACK     	USART_CTR3_SCNACK       	/*!< Smart card nack enable bit. */
#define USART_ENABLE_BIT_IRDA               	USART_CTR3_IRDAEN       	/*!< IRDA enable bit. */
#define USART_ENABLE_BIT_DRIVER             	USART_CTR3_DEN          	/*!< Driver enable bit. */
#define USART_ENABLE_BIT_NORXOF             	USART_CTR3_NORXOF       	/*!< Receive overflow detection off enable bit. */
#define USART_ENABLE_BIT_DMAMASK            	USART_CTR3_DRMRE        	/*!< DMA request mask enable bit. */
/**
  * @}
  */


/** @defgroup USART_RX_TX_DMA USART RX/TX DMA
  * @{
  */

#define USART_DMA_TX        					USART_CTR3_TXDMA        	/*!< USART transmit with DMA. */
#define USART_DMA_RX        					USART_CTR3_RXDMA        	/*!< USART receive with DMA. */
/**
  * @}
  */


/** @defgroup  USART_trigger_operate  USART trigger operate
  * @{
  */

#define USART_TRIGGER_OPERATE_ABRT          	USART_SWTR_ABRT         	/*!< USART auto baud rate trigger. */
#define USART_TRIGGER_OPERATE_BRKFST        	USART_SWTR_BRKFST       	/*!< USART break frame send trigger. */
#define USART_TRIGGER_OPERATE_RXMSKT        	USART_SWTR_RXMSKT       	/*!< USART reception mask mode trigger. */
#define USART_TRIGGER_OPERATE_RXNECLR       	USART_SWTR_RXNECLR      	/*!< USART RXNE clear trigger. */
#define USART_TRIGGER_OPERATE_TXESET        	USART_SWTR_TXESET       	/*!< USART TXE set trigger. */
/**
  * @}
  */


/** @defgroup USART_interrupt_enable_registers USART interrupt enable registers
  * @{
  */

#define USART_INTR_ENABLE_REG_CM            	CTR1        				/*!< Character match interrupt. */
#define USART_INTR_ENABLE_REG_ROT           	CTR1        				/*!< Receive overtime interrupt. */
#define USART_INTR_ENABLE_REG_TC            	CTR1        				/*!< Transmission complete interrupt. */
#define USART_INTR_ENABLE_REG_TXE           	CTR1        				/*!< Transmit empty interrupt. */
#define USART_INTR_ENABLE_REG_RXNE          	CTR1        				/*!< Receiver buffer not empty interrupt. */
#define USART_INTR_ENABLE_REG_IDLE          	CTR1        				/*!< Idle frame detection interrupt	. */
#define USART_INTR_ENABLE_REG_PERR          	CTR1        				/*!< Parity Error interrupt. */
#define USART_INTR_ENABLE_REG_ENDBLK        	CTR1        				/*!< End of block interrupt. */
#define USART_INTR_ENABLE_REG_LINBK         	CTR2        				/*!< LIN Break detection interrupt. */
#define USART_INTR_ENABLE_REG_CTSI          	CTR3        				/*!< CTS interrupt. */
#define USART_INTR_ENABLE_REG_OVRERR        	CTR3        				/*!< Overflow error interrupt. */
#define USART_INTR_ENABLE_REG_NERR         	    CTR3        				/*!< Noise error interrupt. */
#define USART_INTR_ENABLE_REG_FERR          	CTR3        				/*!< Frame error interrupt. */
#define USART_INTR_ENABLE_REG_WKUP          	CTR3        				/*!< Wakeup from stop mode interrupt. */
/**
  * @}
  */


/** @defgroup USART_interrupt_enable_bits USART interrupt enable bits
  * @{
  */

#define USART_INTR_ENABLE_BIT_CM            	USART_CTR1_CMIE         	/*!< Character match interrupt. */
#define USART_INTR_ENABLE_BIT_ROT           	USART_CTR1_OVRTIE       	/*!< Receive overtime interrupt. */
#define USART_INTR_ENABLE_BIT_TC            	USART_CTR1_TCIE         	/*!< Transmission complete interrupt. */
#define USART_INTR_ENABLE_BIT_TXE           	USART_CTR1_TXEIE        	/*!< Transmit empty interrupt. */
#define USART_INTR_ENABLE_BIT_RXNE          	USART_CTR1_RXNEIE       	/*!< Receiver buffer not empty interrupt. */
#define USART_INTR_ENABLE_BIT_IDLE          	USART_CTR1_IDLEIE       	/*!< Idle frame detection interrupt	. */
#define USART_INTR_ENABLE_BIT_PERR          	USART_CTR1_PERRIE       	/*!< Parity Error interrupt. */
#define USART_INTR_ENABLE_BIT_ENDBLK        	USART_CTR1_BTCIE        	/*!< End of block interrupt. */
#define USART_INTR_ENABLE_BIT_LINBK         	USART_CTR2_LBDIE        	/*!< LIN Break detection interrupt. */
#define USART_INTR_ENABLE_BIT_CTSI          	USART_CTR3_CTSIE        	/*!< CTS interrupt. */
#define USART_INTR_ENABLE_BIT_OVRERR        	USART_CTR3_ERRIE        	/*!< Overflow error interrupt. */
#define USART_INTR_ENABLE_BIT_NERR          	USART_CTR3_ERRIE        	/*!< Noise error interrupt. */
#define USART_INTR_ENABLE_BIT_FERR          	USART_CTR3_ERRIE        	/*!< Frame error interrupt. */
#define USART_INTR_ENABLE_BIT_WKUP          	USART_CTR3_WKUPIE       	/*!< Wakeup from stop mode interrupt. */
/**
  * @}
  */


/** @defgroup USART_flags USART flags
  * @{
  */

#define USART_FLAG_RENACT       				USART_STS_RENACTF       	/*!< REN (receiver enable) active flag. */
#define USART_FLAG_TENACT       				USART_STS_TENACTF       	/*!< TEN (transmitter enable) active flag. */
#define USART_FLAG_RXMSK        				USART_STS_RXMSKF        	/*!< Reception mask mode flag. */
#define USART_FLAG_BRKS         				USART_STS_BRKSF         	/*!< Break frame send flag. */
#define USART_FLAG_BSY          				USART_STS_BSYF          	/*!< Busy flag. */
#define USART_FLAG_ABRT         				USART_STS_ABRTF         	/*!< Auto baud rate flag. */
#define USART_FLAG_ABRTERR      				USART_STS_ABRTERRF      	/*!< Auto baud rate error flag. */
#define USART_FLAG_CTS          				USART_STS_CTSF          	/*!< CTS level flag. */
#define USART_FLAG_CM           				USART_STS_CMF           	/*!< Character match interrupt flag. */
#define USART_FLAG_ROT          				USART_STS_ROTF          	/*!< Receiver overtime interrupt flag. */
#define USART_FLAG_TC           				USART_STS_TCF           	/*!< Transmission complete interrupt flag. */
#define USART_FLAG_TXE          				USART_STS_TXE           	/*!< Tranmsit buffer empty interrupt flag. */
#define USART_FLAG_RXNE         				USART_STS_RXNE          	/*!< Receiver buffer not empty interrupt flag. */
#define USART_FLAG_IDLE         				USART_STS_IDLEF         	/*!< Idle frame detection interrupt flag. */
#define USART_FLAG_ENDBLK       				USART_STS_ENDBLKF       	/*!< End of block interrupt flag. */
#define USART_FLAG_LINBK        				USART_STS_LINBKF        	/*!< LIN break detection interrupt flag. */
#define USART_FLAG_CTSI         				USART_STS_CTSIF         	/*!< CTS level change interrupt flag. */
#define USART_FLAG_OVRERR       				USART_STS_OVRERRF       	/*!< Reception overflow error interrupt flag. */
#define USART_FLAG_NERR         				USART_STS_NF            	/*!< Start bit noise interrupt flag. */
#define USART_FLAG_FERR         				USART_STS_FERRF         	/*!< Frame error interrupt flag. */
#define USART_FLAG_PERR         				USART_STS_PERRF         	/*!< Parity error interrupt flag. */
#define USART_FLAG_WKUP         				USART_STS_WKUPF         	/*!< Wakeup from stop mode interrupt flag. */
/**
  * @}
  */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup USART_Exported_Functions USART Exported Functions
  * @{
  */

/**
  * @brief  Initializes registers of the USARTx to default values.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @return None.
  */
#define __USART_DEF_INIT(USARTx)            	do{ \
                                                	((RCU_PERI_RST_REG_##USARTx) |= (RCU_PERI_RST_BIT_##USARTx)); \
                                                	((RCU_PERI_RST_REG_##USARTx) &= ~(RCU_PERI_RST_BIT_##USARTx)); \
                                                }while(0U)

/**
  * @brief  Transmits single data through the USARTx peripheral.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  value: The data to transmit.
  * @return None.
  */
#define __USART_DATA_SEND(USARTx, value)    	(((USARTx)->TXBUF) = (value & 0x01FF))

/**
  * @brief  Returns the most recent received data by the USARTx peripheral.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @return The received data.
  */
#define __USART_DATA_RECV(USARTx)           	((uint16_t)((USARTx)->RXBUF & 0x01FF))

/**
  * @brief  Enables the specified USART peripheral.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @return None.
  */
#define __USART_ENABLE(USARTx)              	((USARTx)->CTR1 |= USART_CTR1_UEN)

/**
  * @brief  Disables the specified USART peripheral.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @return None.
  */
#define __USART_DISABLE(USARTx)             	((USARTx)->CTR1 &= ~(USART_CTR1_UEN))

/**
  * @brief  Enables the specified USART function.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  FUNC: Specifies the USART function.
  *         It can be one of the following values:
  *          @arg RX: USART Data RX.
  *          @arg TX: USART Data TX.
  *          @arg OVERSAMPLING: 8-bit oversampling enable, disable for 16-bit oversampling.
  *          @arg SAMPLE_METHOD: Single sample mode enable, disable for 3 samples mode.
  *          @arg MSB_FIRST: MSB first
  *          @arg DATA_INVERSE: Data bit inversion.
  *          @arg RX_INVERSE: RX pin inversion.
  *          @arg TX_INVERSE: TX pin inversion.
  *          @arg PIN_SWAP: TX/RX pins swap, has to be enabled before USARTx module enabled.
  *          @arg RECV_OVERTIME: Receive overtime, only for USART1.
  *          @arg STOP_MODE: Stop mode, only for USART1.
  *          @arg AUTO_BAUDRATE: Auto baud rate detection, for USART1 and USART2.
  *          @arg RECV_MASK: Receive mask.
  *          @arg LIN_MODE: LIN mode, only for USART1.
  *          @arg HALF_DUPLEX: Half duplex mode.
  *          @arg SMARTCARD: Smart card, only for USART1.
  *          @arg SMARTCARD_NACK: Smart card nack, only for USART1.
  *          @arg IRDA: IRDA mode, only for USART1.
  *          @arg DRIVER: RS485 Driver.
  *          @arg NORXOF: Receive overflow detection off enable, disable for the detection on.
  *          @arg DMAMASK: DMA request mask on reception error.
  * @return None.
  */
#define __USART_FUNC_ENABLE(USARTx, FUNC)   	((USARTx)->USART_ENABLE_REG_##FUNC |= USART_ENABLE_BIT_##FUNC)

/**
  * @brief  Disables the specified USART function.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  FUNC: Specifies the USART function.
  *         It can be one of the following values:
  *          @arg RX: USART Data RX.
  *          @arg TX: USART Data TX.
  *          @arg OVERSAMPLING: 8-bit oversampling enable, disable for 16-bit oversampling.
  *          @arg SAMPLE_METHOD: Single sample mode enable, disable for 3 samples mode.
  *          @arg MSB_FIRST: MSB first
  *          @arg DATA_INVERSE: Data bit inversion.
  *          @arg RX_INVERSE: RX pin inversion.
  *          @arg TX_INVERSE: TX pin inversion.
  *          @arg PIN_SWAP: TX/RX pins swap, has to be enabled before USARTx module enabled.
  *          @arg RECV_OVERTIME: Receive overtime, only for USART1.
  *          @arg STOP_MODE: Stop mode, only for USART1.
  *          @arg AUTO_BAUDRATE: Auto baud rate detection, for USART1 and USART2.
  *          @arg RECV_MASK: Receive mask.
  *          @arg LIN_MODE: LIN mode, only for USART1.
  *          @arg HALF_DUPLEX: Half duplex mode.
  *          @arg SMARTCARD: Smart card, only for USART1.
  *          @arg SMARTCARD_NACK: Smart card nack, only for USART1.
  *          @arg IRDA: IRDA mode, only for USART1.
  *          @arg DRIVER: RS485 Driver.
  *          @arg NORXOF: Receive overflow detection off enable, disable for the detection on.
  *          @arg DMAMASK: DMA request mask on reception error.
  * @return None.
  */
#define __USART_FUNC_DISABLE(USARTx, FUNC)  	((USARTx)->USART_ENABLE_REG_##FUNC &= ~(USART_ENABLE_BIT_##FUNC))

/**
  * @brief  Enables the specified USART DMA requests.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  DMA: Specifies the USART DMA request.
  *         It can be any combination of the following values:
  *          @arg USART_DMA_RX: RX DMA request.
  *          @arg USART_DMA_TX: TX DMA request.
  * @return None.
  */
#define __USART_DMA_ENABLE(USARTx, DMA)     	((USARTx)->CTR3 |= DMA)

/**
  * @brief  Disables the specified USART DMA requests.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  DMA: Specifies the USART DMA request.
  *         It can be any combination of the following values:
  *          @arg USART_DMA_RX: RX DMA request.
  *          @arg USART_DMA_TX: TX DMA request.
  * @return None.
  */
#define __USART_DMA_DISABLE(USARTx, DMA)    	((USARTx)->CTR3 &=~ (DMA))

/**
  * @brief  Enables the specified USART's trigger.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  TRG: Specifies the USART trigger..
  *         It can be any combination of the following values:
  *          @arg USART_TRIGGER_OPERATE_TXESET: Transmit data trigger.
  *          @arg USART_TRIGGER_OPERATE_RXNECLR: Receive data clear trigger.
  *          @arg USART_TRIGGER_OPERATE_RXMSKT: Reception mask mode trigger.
  *          @arg USART_TRIGGER_OPERATE_BRKFST: Break frame send trigger.
  *          @arg USART_TRIGGER_OPERATE_ABRT: Auto baud rate trigger.
  * @return None.
  */
#define __USART_TRIGGER_ENABLE(USARTx, TRG)    ((USARTx)->SWTR |= TRG)

/**
  * @brief  Enables the specified USART interrupts.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  INT: Specifies the USART interrupt sources to be enabled.
  *         It can be one of the following values:
  *          @arg CM: Character match interrupt.
  *          @arg ROT: Receive overtime interrupt.
  *          @arg TC: Transmission complete interrupt.
  *          @arg TXE: Transmit empty interrupt.
  *          @arg RXNE: Receiver buffer not empty interrupt.
  *          @arg IDLE: Idle frame detection interrupt.
  *          @arg PERR: Parity Error interrupt.
  *          @arg ENDBLK: End of block interrupt.
  *          @arg LINBK: LIN Break detection interrupt.
  *          @arg CTSI: CTS detection interrupt.
  *          @arg OVRERR: Overflow error interrupt.
  *          @arg NERR: Noise error interrupt.
  *          @arg FERR: Frame error interrupt.
  *          @arg WKUP: Wakeup interrupt.
  * @return None.
  */
#define __USART_INTR_ENABLE(USARTx, INT)       ((USARTx)->USART_INTR_ENABLE_REG_##INT |= USART_INTR_ENABLE_BIT_##INT)

/**
  * @brief  Disables the specified USART interrupts.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  INT: Specifies the USART interrupt sources to be disabled.
  *         It can be one of the following values:
  *          @arg CM: Character match interrupt.
  *          @arg ROT: Receive overtime interrupt.
  *          @arg TC: Transmission complete interrupt.
  *          @arg TXE: Transmit empty interrupt.
  *          @arg RXNE: Receiver buffer not empty interrupt.
  *          @arg IDLE: Idle frame detection interrupt.
  *          @arg PERR: Parity Error interrupt.
  *          @arg ENDBLK: End of block interrupt.
  *          @arg LINBK: LIN Break detection interrupt.
  *          @arg CTSI: CTS detection interrupt.
  *          @arg OVRERR: Overflow error interrupt.
  *          @arg NERR: Noise error interrupt.
  *          @arg FERR: Frame error interrupt.
  *          @arg WKUP: Wakeup interrupt.
  * @return None.
  */
#define __USART_INTR_DISABLE(USARTx, INT)      ((USARTx)->USART_INTR_ENABLE_REG_##INT &= ~(USART_INTR_ENABLE_BIT_##INT))

/**
  * @brief  Checks whether the specified USART interrupt enabled or not.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  INT: Specifies the USART interrupt sources to check.
  *         It can be one of the following values:
  *          @arg CM: Character match interrupt.
  *          @arg ROT: Receive overtime interrupt.
  *          @arg TC: Transmission complete interrupt.
  *          @arg TXE: Transmit empty interrupt.
  *          @arg RXNE: Receiver buffer not empty interrupt.
  *          @arg IDLE: Idle frame detection interrupt.
  *          @arg PERR: Parity Error interrupt.
  *          @arg ENDBLK: End of block interrupt.
  *          @arg LINBK: LIN Break detection interrupt.
  *          @arg CTSI: CTS detection interrupt.
  *          @arg OVRERR: Overflow error interrupt.
  *          @arg NERR: Noise error interrupt.
  *          @arg FERR: Frame error interrupt.
  *          @arg WKUP: Wakeup interrupt.
  * @return SET or RESET.
  */
#define __USART_INTR_ENABLE_STATUS_GET(USARTx, INT)     (((USARTx)->USART_INTR_ENABLE_REG_##INT & \
                                                        (USART_INTR_ENABLE_BIT_##INT)) ? SET : RESET)

/**
  * @brief  Checks whether the specified USART flag is set or not.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  FLAG: Specifies the flag to check..
  *         It can be one of the following values:
  *          @arg RENACT: Receive Enable acknowledge flag.
  *          @arg TENACT: Transmit Enable acknowledge flag.
  *          @arg BRKS: Send Break flag.
  *          @arg RXMSK: Reception mask mode flag.
  *          @arg BSY: Busy flag.
  *          @arg ABRT: Auto baud rate flag.
  *          @arg ABRTERR: Auto baud rate error flag.
  *          @arg CTS: CTS flag.
  *          @arg CM: Character match interrupt flag.
  *          @arg ROT: Receive overtime interrupt flag.
  *          @arg TC: Transmission complete interrupt flag.
  *          @arg TXE: Transmit empty interrupt flag.
  *          @arg RXNE: Receiver buffer not empty interrupt flag.
  *          @arg IDLE: Idle frame detection interrupt flag.
  *          @arg PERR: Parity Error interrupt flag.
  *          @arg ENDBLK: End of block interrupt flag, not available for CS32F036 devices.
  *          @arg LINBK: LIN Break detection interrupt flag, not available for CS32F036 devices.
  *          @arg CTSI: CTS detection interrupt flag.  
  *          @arg OVRERR: Overflow error interrupt flag.
  *          @arg NERR: Noise error interrupt flag.
  *          @arg FERR: Frame error interrupt flag.
  *          @arg WKUP: Wakeup interrupt flag.
  * @return SET or RESET.
  */
#define __USART_FLAG_STATUS_GET(USARTx, FLAG)       (((USARTx)->STS & (USART_FLAG_##FLAG)) ? SET : RESET)

/**
  * @brief  Checks whether the specified USART interrupt has occured or not.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  INT: Specifies the USART interrupt sources to check.
  *         It can be one of the following values:
  *          @arg CM: Character match interrupt.
  *          @arg ROT: Receive overtime interrupt.
  *          @arg TC: Transmission complete interrupt.
  *          @arg TXE: Transmit empty interrupt.
  *          @arg RXNE: Receiver buffer not empty interrupt.
  *          @arg IDLE: Idle frame detection interrupt.
  *          @arg PERR: Parity Error interrupt.
  *          @arg ENDBLK: End of block interrupt.
  *          @arg LINBK: LIN Break detection interrupt.
  *          @arg CTSI: CTS detection interrupt.
  *          @arg OVRERR: Overflow error interrupt.
  *          @arg NERR: Noise error interrupt.
  *          @arg FERR: Frame error interrupt.
  *          @arg WKUP: Wakeup interrupt.
  * @return SET or RESET.
  */
#define __USART_INTR_STATUS_GET(USARTx, INT)        (__USART_INTR_ENABLE_STATUS_GET(USARTx, INT) && \
                                                     __USART_FLAG_STATUS_GET(USARTx, INT))
/**
  * @brief  Clears the USARTx's flags.
  * @param  USARTx: USARTx where x can be 1, 2.
  * @param  FLAG: Specifies the flag to clear.
  *         It can be any combination of the following values: 
  *          @arg USART_FLAG_CM: Character match flag.
  *          @arg USART_FLAG_ROT: Receive overtime flag.
  *          @arg USART_FLAG_TC: Transmission Complete flag.
  *          @arg USART_FLAG_IDLE: Idle frame detection flag.
  *          @arg USART_FLAG_ENDBLK: End of block flag, not available for CS32F036 devices. 
  *          @arg USART_FLAG_LINBK: LIN Break detection flag, not available for CS32F036 devices.
  *          @arg USART_FLAG_CTSI: CTS interrupt flag.
  *          @arg USART_FLAG_OVRERR: Overflow error flag.
  *          @arg USART_FLAG_NERR: Noise flag.
  *          @arg USART_FLAG_FERR: Frame error flag.
  *          @arg USART_FLAG_PERR: Parity error flag.
  *          @arg USART_FLAG_WKUP: Wakeup from stop mode flag.
  * @return None.
  */
#define __USART_FLAG_CLEAR(USARTx, FLAG)            ((USARTx)->IFCLR = FLAG)

/**
  * @brief  Initializes the ptr_usart peripheral according to the specified parameters in the ptr_config.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2, 6, 7 or 8.
  * @param  ptr_config: Pointer to a usart_config_t structure containing the configuration for the specified USART
  *                     peripheral.
  * @return None.
  */
void usart_init(usart_reg_t* ptr_usart, usart_config_t* ptr_config);

/**
  * @brief  Fills each ptr_config member with its default value.
  * @param  ptr_config: Pointer to a usart_config_t structure containing the configuration for the specified USART
  *                     peripheral.
  * @return None.
  */
void usart_config_struct_init(usart_config_t* ptr_config);

/**
  * @brief  Initializes the USARTx peripheral Clock according to the specified parameters in the ptr_clock.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  ptr_clock: Pointer to a usart_clock_t structure that contains the configuration information for the
  *                    specified USART peripheral. 
  * @return None. 
  */
void usart_clock_init(usart_reg_t* ptr_usart, usart_clock_t* ptr_clock);

/**
  * @brief  Fills each ptr_clock member with its default value.
  * @param  ptr_clock: Pointer to a usart_clock_t structure which will be initialized.
  * @return None.
  */
void usart_clock_struct_init(usart_clock_t* ptr_clock);

/**
  * @brief  Sets the system clock prescaler.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies the prescaler clock.
  * @note   This function has to be called before calling usart_enable_ctrl() function.
  * @return None.
  */
void usart_prescaler_set(usart_reg_t* ptr_usart, uint8_t value);

/**
  * @brief  Selects the USART WakeUp method for stop mode.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  wakeup_source: Specifies the selected USART wakeup method.
  *         It can be one of the following values:
  *           @arg USART_WAKEUP_SOURCE_ADDR_MATCH: Wakeup on address match.
  *           @arg USART_WAKEUP_SOURCE_START_BIT: Wakeup on Start bit detection.
  *           @arg USART_WAKEUP_SOURCE_RXNE: Wakeup on RXNE.
  * @note   This function has to be called before calling usart_enable_ctrl() function.
  * @return None.
  */
void usart_stop_mode_wakeup_config(usart_reg_t* ptr_usart, uint32_t wakeup_source);

/**
  * @brief  Selects the USART auto baud rate method.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  rate_value: Specifies the selected USART auto baud rate method.
  *          This parameter can be one of the following values:
  *            @arg USART_AUTO_RATE_MEASURE_START_BIT: Start Bit duration measurement.
  *            @arg USART_AUTO_RATE_MEASURE_FALLING_EDGE: Falling edge to falling edge measurement.
  * @note   This function has to be called before calling usart_enable_ctrl() function.
  * @return None.
  */
void usart_auto_baud_rate_config(usart_reg_t* ptr_usart, uint32_t rate_value);

/**
  * @brief  Sets the address of the USART node.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  addr: Indicates the address of the USART node.
  * @return None.
  */
void usart_address_set(usart_reg_t* ptr_usart, uint8_t addr);

/**
  * @brief  Selects the USART WakeUp method from mute mode.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  flag: Specifies the USART wakeup method.
  *          This parameter can be one of the following values:
  *            @arg USART_RX_WAKEUP_IDLE_LINE: WakeUp by an idle line detection.
  *            @arg USART_RX_WAKEUP_ADDR_MARK: WakeUp by an address mark.
  * @return None.
  */
void usart_recv_wakeup_config(usart_reg_t* ptr_usart, uint32_t flag);

/**
  * @brief  Configure the the USART Address detection length.
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  addr: Specifies the USART address length detection.
  *          This parameter can be one of the following values:
  *            @arg USART_ADDRESS_4BIT: 4-bit address length detection.
  *            @arg USART_ADDRESS_7BIT: 7-bit address length detection.
  * @return None.
  */
void usart_addr_detect_config(usart_reg_t* ptr_usart, uint32_t addr);

/**
  * @brief  Sets the USART LIN Break detection length.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the LIN break detection length.
  *          This parameter can be one of the following values:
  *            @arg USART_LIN_BREAK_10BIT: 10-bit break detection.
  *            @arg USART_LIN_BREAK_11BIT: 11-bit break detection.
  * @return None.
  */
void usart_lin_break_detect_config(usart_reg_t* ptr_usart, uint32_t value);

/**
  * @brief  Sets the specified USART guard time for smart card mode.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the guard time.
  * @note   The value must be greater than 0x0.
  * @return None.
  */
void usart_guard_time_set(usart_reg_t* ptr_usart, uint8_t value);

/**
  * @brief  Sets the Smart Card number of retries in transmit and receive.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the Smart Card auto retry times.
  * @return None.
  */
void usart_auto_retry_times_set(usart_reg_t* ptr_usart, uint8_t value);

/**
  * @brief  Sets the Smar Card Block number.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  block_number: Specifies the Smart Card block number.
  * @return None.
  */
void usart_block_value_set(usart_reg_t* ptr_usart, uint8_t block_number);

/**
  * @brief  Sets the receiver Time Out value.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the Receiver Time Out value.
  * @return None.
  */
void usart_recv_overtime_set(usart_reg_t* ptr_usart, uint32_t value);

/**
  * @brief  Configures the USART's IrDA interface.
  * @param  ptr_usart: Pointer to USARTx where x can be 1 to select USART peripheral.
  * @param  value: Specifies the IrDA mode,it can be one of the following values:
  *          @arg USART_IRDA_MODE_LP: IRDA in low power mode.
  *          @arg USART_IRDA_MODE_NORMAL: IRDA in normal mode.
  * @return None.
  */
void usart_irda_config(usart_reg_t* ptr_usart, uint32_t value);

/**
  * @brief  Configures the USART's DE polarity
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies the DE polarity
  *         It can be one of the following values:
  *          @arg USART_DE_POLARITY_LOW: DE polarity is low.
  *          @arg USART_DE_POLARITY_HIGH: DE polarity is high.
  * @return None.
  */
void usart_driver_enable_polarity_config(usart_reg_t* ptr_usart, uint32_t value);

/**
  * @brief  Sets the specified RS485 DE Pre-active time 
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies DE Pre-active time between the activation of the DE signal and the the beginning of the
  *                start bit.
  * @return None.
  */
void usart_driver_enable_preactive_time_set(usart_reg_t* ptr_usart, uint8_t value);

/**
  * @brief  Sets the specified RS485 DE Pos-active time
  * @param  ptr_usart: Pointer to USARTx where x can be 1, 2.
  * @param  value: Specifies the time between the middle of the last stop bit in a transmitted message and the
  *                Pos_activation of the DE signal.
  * @return None.
  */
void usart_driver_enable_posactive_time_set(usart_reg_t* ptr_usart, uint8_t value);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_usart.h */


/**
  * @}
  */

/**
  * @}
  */
