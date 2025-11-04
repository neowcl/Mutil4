/**
* @file        cbm858xm_spi.h
* @brief       This file contains all the functions prototypes for the SPI firmware library. 
* @author      ChipSea MCU Group
* @version     1.0.0
* @date        2022.05.23
* @copyright   CHIPSEA TECHNOLOGIES (SHENZHEN) CORP.
* @note        
****************************************************************************************************
* @par Modify record:
* <tr><th>Date          <th>Version    <th>Author     <th>Description
* <tr><td>2022.05.23    <td>1.0.0      <td>ChipSea    <td>
* -# 
* </table>
*
****************************************************************************************************
*/


#ifndef __CBM858xM_SPI_H__
#define __CBM858xM_SPI_H__


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

/** @addtogroup SPI
  * @{
  */

/***************************************************************************************************
 * @definitions
***************************************************************************************************/
/** @defgroup SPI_Exported_Types SPI Exported Types
  * @{
  */

/** @struct spi_config_t 
  * @brief  SPI Init structure definition.
  */
typedef struct
{
    uint16_t spi_direct;            /*!< Specifies the SPI unidirectional or bidirectional data mode, it can be one of
                                         the following values: @ref SPI_direction. */

    uint16_t spi_mode;              /*!< Specifies the SPI mode,it can be one of the following values: @ref SPI_mode. */

    uint16_t data_width;            /*!< Specifies the SPI data size, it can be one of the following values: @ref 
                                         SPI_data_width. */

    uint16_t spi_cpol;              /*!< Specifies the serial clock steady state, it can be one of the following values:
                                         @ref SPI_Clock_Polarity. */

    uint16_t spi_cpha;              /*!< Specifies the clock active edge for the bit capture, it can be one of the
                                         following values: @ref SPI_Clock_Phase. */

    uint16_t spi_nss;               /*!< Specifies whether the NSS signal is managed by NSS pin, it can be one of the
                                         following values: @ref SPI_SSM. */

    uint16_t spi_predivid;          /*!< Specifies the baud rate prescaler value, it can be one of the following values:
                                         @ref SPI_pre_divide. */

    uint16_t first_bit;             /*!< Specifies whether data transfers start from MSB or LSB bit, it can be one of
                                         the following values: @ref SPI_first_bit. */

    uint16_t crc_polynomial;        /*!< Specifies the polynomial used for the CRC calculation. */
}spi_config_t;
/**
  * @}
  */


/** @defgroup SPI_Exported_Constants SPI Exported Constants
  * @{
  */

/*! Checks SPI definition. */
#define SPI_SPI1_CHECK(bus)     				(((bus) == SPI1))
#define SPI_LIST_CHECK(bus)     				(((bus) == SPI1) || ((bus) == SPI2))


/** @defgroup SPI_direction SPI direction
  * @{
  */

#define SPI_DIR_2LINES_FULL_DUPLEX      		((uint16_t)0x0000)      /*!< SPI 2 lines full duplex. */
#define SPI_DIR_2LINES_ONLY_RX          		((uint16_t)0x0400)      /*!< SPI 2 lines read only. */
#define SPI_DIR_1LINES_RX               		((uint16_t)0x8000)      /*!< SPI 1 line read. */
#define SPI_DIR_1LINES_TX               		((uint16_t)0xC000)      /*!< SPI 1 line Write. */
/**
  * @}
  */

/*! Checks SPI direction. */
#define SPI_DIR_LINES_CHECK(value)      		(((value) == SPI_DIR_2LINES_FULL_DUPLEX) || \
                                        		((value) == SPI_DIR_2LINES_ONLY_RX)      || \
                                        		((value) == SPI_DIR_1LINES_RX)           || \
                                        		((value) == SPI_DIR_1LINES_TX))


/** @defgroup SPI_mode SPI mode
  * @{
  */

#define SPI_MODE_MASTER     		    		((uint16_t)0x0104)      /*!< SPI master mode. */
#define SPI_MODE_SLAVE      	        		((uint16_t)0x0000)      /*!< SPI slave mode. */
/**
  * @}
  */

/*! Checks SPI mode. */
#define SPI_MODE_CHECK(mode)            		(((mode) == SPI_MODE_MASTER) || ((mode) == SPI_MODE_SLAVE))


/** @defgroup SPI_data_width SPI data width
  * @{
  */

#define SPI_DATA_WIDTH_4BIT         			((uint16_t)0x0300)      /*!< Specifies data width is 4 bits. */
#define SPI_DATA_WIDTH_5BIT         			((uint16_t)0x0400)      /*!< Specifies data width is 5 bits. */
#define SPI_DATA_WIDTH_6BIT         			((uint16_t)0x0500)      /*!< Specifies data width is 6 bits. */
#define SPI_DATA_WIDTH_7BIT         			((uint16_t)0x0600)      /*!< Specifies data width is 7 bits. */
#define SPI_DATA_WIDTH_8BIT         			((uint16_t)0x0700)      /*!< Specifies data width is 8 bits. */
#define SPI_DATA_WIDTH_9BIT         			((uint16_t)0x0800)      /*!< Specifies data width is 9 bits. */
#define SPI_DATA_WIDTH_10BIT        			((uint16_t)0x0900)      /*!< Specifies data width is 10 bits. */
#define SPI_DATA_WIDTH_11BIT        			((uint16_t)0x0A00)      /*!< Specifies data width is 11 bits. */
#define SPI_DATA_WIDTH_12BIT        			((uint16_t)0x0B00)      /*!< Specifies data width is 12 bits. */
#define SPI_DATA_WIDTH_13BIT        			((uint16_t)0x0C00)      /*!< Specifies data width is 13 bits. */
#define SPI_DATA_WIDTH_14BIT        			((uint16_t)0x0D00)      /*!< Specifies data width is 14 bits. */
#define SPI_DATA_WIDTH_15BIT        			((uint16_t)0x0E00)      /*!< Specifies data width is 15 bits. */
#define SPI_DATA_WIDTH_16BIT        			((uint16_t)0x0F00)      /*!< Specifies data width is 16 bits. */
/**
  * @}
  */

/*! Checks SPI data width. */
#define IS_SPI_DATA_SIZE(size)      			(((size) == SPI_DATA_WIDTH_4BIT)  || ((size) == SPI_DATA_WIDTH_5BIT)   || \
                                     			((size) == SPI_DATA_WIDTH_6BIT)   || ((size) == SPI_DATA_WIDTH_7BIT)   || \
                                     			((size) == SPI_DATA_WIDTH_8BIT)   || ((size) == SPI_DATA_WIDTH_9BIT)   || \
                                     			((size) == SPI_DATA_WIDTH_10BIT)  || ((size) == SPI_DATA_WIDTH_11BIT)  || \
                                     			((size) == SPI_DATA_WIDTH_12BIT)  || ((size) == SPI_DATA_WIDTH_13BIT)  || \
                                     			((size) == SPI_DATA_WIDTH_14BIT)  || ((size) == SPI_DATA_WIDTH_15BIT)  || \
                                     			((size) == SPI_DATA_WIDTH_16BIT))


/** @defgroup SPI_CRC_length SPI CRC length
  * @{
  */

#define SPI_CRC_LEN_8BIT        				((uint16_t)0x0000)      /*!< Specifies CRC calculation length is 8 bits. */
#define SPI_CRC_LEN_16BIT       				SPI_CTR1_CRC16          /*!< Specifies CRC calculation length is 16 bits. */
/**
  * @}
  */

/*! Checks SPI CRC length. */
#define SPI_CRC_LEN_CHECK(value)        		(((value) == SPI_CRC_LEN_8BIT) || ((value) == SPI_CRC_LEN_16BIT))


/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */

#define SPI_CPOL_LOW        					((uint16_t)0x0000)      /*!< SPI CPOL output low level. */
#define SPI_CPOL_HIGH       					SPI_CTR1_CPOL           /*!< SPI CPOL output high level. */
/**
  * @}
  */

/*! Checks SPI Clock Polarity. */
#define SPI_CPOL_CHECK(value)       			(((value) == SPI_CPOL_LOW) || ((value) == SPI_CPOL_HIGH))


/** @defgroup SPI_Clock_Phase SPI Clock Phase
  * @{
  */

#define SPI_CPHA_1EDGE      					((uint16_t)0x0000)      /*!< SPI smaple data at 1st edge. */
#define SPI_CPHA_2EDGE      					SPI_CTR1_CPHA           /*!< SPI sample data at 2nd edge. */
/**
  * @}
  */

/*! Checks SPI Clock Phase. */
#define SPI_CPHA_CHECK(value)       			(((value) == SPI_CPHA_1EDGE) || ((value) == SPI_CPHA_2EDGE))


/** @defgroup SPI_SSM SPI SSM(Slave Select management)
  * @{
  */

#define SPI_SSM_SW      						SPI_CTR1_SWNSSM         /*!< SPI software NSS management is selected. */
#define SPI_SSM_HW      						((uint16_t)0x0000)      /*!< SPI hardware NSS management is selected. */
/**
  * @}
  */

/*! Checks SPI SSM. */
#define SPI_SSM_CHECK(NSS)      				(((NSS) == SPI_SSM_SW) || ((NSS) == SPI_SSM_HW))


/** @defgroup SPI_pre_divide SPI baud rate pre divide
  * @{
  */

#define SPI_BAUD_RATE_PDIV_2        			((uint16_t)0x0000)      /*!< SPI baud rate is pre-divided by 2. */
#define SPI_BAUD_RATE_PDIV_4        			((uint16_t)0x0008)      /*!< SPI baud rate is pre-divided by 4. */
#define SPI_BAUD_RATE_PDIV_8        			((uint16_t)0x0010)      /*!< SPI baud rate is pre-divided by 8. */
#define SPI_BAUD_RATE_PDIV_16       			((uint16_t)0x0018)      /*!< SPI baud rate is pre-divided by 16. */
#define SPI_BAUD_RATE_PDIV_32       			((uint16_t)0x0020)      /*!< SPI baud rate is pre-divided by 32. */
#define SPI_BAUD_RATE_PDIV_64       			((uint16_t)0x0028)      /*!< SPI baud rate is pre-divided by 64. */
#define SPI_BAUD_RATE_PDIV_128      			((uint16_t)0x0030)      /*!< SPI baud rate is pre-divided by 128. */
#define SPI_BAUD_RATE_PDIV_256      			((uint16_t)0x0038)      /*!< SPI baud rate is pre-divided by 256. */
/**
  * @}
  */

/*! Checks SPI baud rate pre divide. */
#define SPI_BAUD_RATE_PDIV_CHECK(value)     	(((value) == SPI_BAUD_RATE_PDIV_2)   || \
                                             	((value) == SPI_BAUD_RATE_PDIV_4)   || \
                                             	((value) == SPI_BAUD_RATE_PDIV_8)   || \
                                             	((value) == SPI_BAUD_RATE_PDIV_16)  || \
                                             	((value) == SPI_BAUD_RATE_PDIV_32)  || \
                                             	((value) == SPI_BAUD_RATE_PDIV_64)  || \
                                             	((value) == SPI_BAUD_RATE_PDIV_128) || \
                                             	((value) == SPI_BAUD_RATE_PDIV_256))


/** @defgroup SPI_first_bit SPI first bit
  * @{
  */

#define SPI_FIRST_BIT_MSB       				((uint16_t)0x0000)      /*!< SPI MSB transmitted first. */
#define SPI_FIRST_BIT_LSB       				SPI_CTR1_LSBF           /*!< SPI LSB transmitted first. */
/**
  * @}
  */

/*! Checks SPI first bit. */
#define SPI_FIRST_BIT_CHECK(flag)       		(((flag) == SPI_FIRST_BIT_MSB) || ((flag) == SPI_FIRST_BIT_LSB))


/*! Checks SPI CRC polynomial value. */
#define SPI_CRC_POLYNOMIAL_CHECK(value)     	((value) >= 0x1)


/** @defgroup SPI_FIFO_reception_threshold SPI FIFO reception threshold
  * @{
  */

/*! RXNE is occurred if FIFO level is grater or equal to 0.5. */
#define SPI_FIFO_RX_THRESHOLD_HF        		((uint16_t)0x0000)
/*! RXNE is occurred if FIFO level is grater or equal to 0.25. */
#define SPI_FIFO_RX_THRESHOLD_QF       			SPI_CTR2_RXNE8
/**
  * @}
  */

/*! Checks SPI FIFO reception threshold. */
#define SPI_FIFO_RX_THRESHOLD_CHECK(value)      (((value) == SPI_FIFO_RX_THRESHOLD_HF) || \
                                                ((value) == SPI_FIFO_RX_THRESHOLD_QF))


/** @defgroup SPI_DMA_transfer_requests SPI DMA transfer requests
  * @{
  */

#define SPI_DMA_TX      						SPI_CTR2_DMATXEN        /*!< SPI tx buffer DMA transfer request. */
#define SPI_DMA_RX      						SPI_CTR2_DMARXEN        /*!< SPI rx buffer DMA transfer request. */
/**
  * @}
  */


/** @defgroup SPI_DMA_transmit_number SPI DMA transmit number
  * @{
  */

#define SPI_DMA_TX_EVEN_RX_EVEN     			((uint16_t)0x0000)      /*!< SPI number of data for tx/rx is even. */
#define SPI_DMA_TX_ODD_RX_EVEN      			((uint16_t)0x4000)      /*!< SPI number of data for tx is odd and for Rx is even. */
#define SPI_DMA_TX_EVEN_RX_ODD      			((uint16_t)0x2000)      /*!< SPI number of data for tx is even and for Rx is odd. */
#define SPI_DMA_TX_ODD_RX_ODD       			((uint16_t)0x6000)      /*!< SPI number of data for tx/rx is odd. */
/**
  * @}
  */

/*! Checks SPI DMA transmit number. */
#define SPI_DMA_TX_RX_NUMBER_CHECK(value)       (((value) == SPI_DMA_TX_EVEN_RX_EVEN) || \
                                                ((value) == SPI_DMA_TX_ODD_RX_EVEN)  || \
                                                ((value) == SPI_DMA_TX_EVEN_RX_ODD)  || \
                                                ((value) == SPI_DMA_TX_ODD_RX_ODD))


/** @defgroup NSS_value NSS value
  * @{
  */

#define SPI_SOFTWARE_NSS_SET        			SPI_CTR1_NVSWNSSM       /*!< SPI set NSS pin internally. */
#define SPI_SOFTWARE_NSS_RESET      			((uint16_t)0x0000)      /*!< SPI reset NSS pin internally. */
/**
  * @}
  */

/*! Checks NSS value. */
#define SPI_SOFTWARE_NSS_CHECK(value)       	(((value) == SPI_SOFTWARE_NSS_SET) || ((value) == SPI_SOFTWARE_NSS_RESET))


/** @defgroup SPI_transmit_direction SPI transmit direction
  * @{
  */

#define SPI_TRANSMIT_DIR_RX     				((uint16_t)0x0000)      /*!< SPI selects rx receive direction. */
#define SPI_TRANSMIT_DIR_TX     				((uint16_t)0x4000)      /*!< SPI selects tx transmit direction. */
/**
  * @}
  */

/*! Checks SPI transmit direction. */
#define SPI_TRANSMIT_DIR_CHECK(value)       	(((value) == SPI_TRANSMIT_DIR_RX) || ((value) == SPI_TRANSMIT_DIR_TX))


/** @defgroup SPI_interrupts SPI interrupts
  * @{
  */

#define SPI_INTR_TXE            				((uint16_t)0x0080)      /*!< SPI tx buffer empty interrupt enable. */
#define SPI_INTR_RXNE           				((uint16_t)0x0040)      /*!< SPI rx buffer not empty interrupt enable. */
#define SPI_INTR_ERR            				((uint16_t)0x0020)      /*!< SPI error interrupt enable. */
#define SPI_INTR_RXOFERR        				((uint16_t)0x0020)      /*!< Receiver data overflow error interrupt enable. */
#define SPI_INTR_MMERR          				((uint16_t)0x0020)      /*!< Multi-master error interrupt enable. */
#define SPI_INTR_NWERR          				((uint16_t)0x0020)      /*!< Error of SPI NSS or I2S WS interrupt enable. */
#define SPI_INTR_TXUFERR        				((uint16_t)0x0020)      /*!< Transmitter data underflow error interrupt enable. */
/**
  * @}
  */


/** @defgroup SPI_transmission_fifo_level_status SPI transmission fifo level status
  * @{
  */

#define SPI_TX_FIFO_LEVEL_STATUS_EMPTY          ((uint16_t)0x0000)      /*!< SPI tx fifo is empty. */
#define SPI_TX_FIFO_LEVEL_STATUS_1_4_FULL       ((uint16_t)0x0800)      /*!< SPI tx fifo more than 0.25 full. */
#define SPI_TX_FIFO_LEVEL_STATUS_1_2_FULL       ((uint16_t)0x1000)      /*!< SPI tx fifo more than 0.5 full. */
#define SPI_TX_FIFO_LEVEL_STATUS_FULL           ((uint16_t)0x1800)      /*!< SPI tx fifo is full. */
/**
  * @}
  */


/** @defgroup SPI_reception_fifo_level_status SPI reception fifo level status
  * @{
  */

#define SPI_RX_FIFO_LEVEL_STATUS_EMPTY          ((uint16_t)0x0000)      /*!< SPI rx fifo is empty. */
#define SPI_RX_FIFO_LEVEL_STATUS_1_4_FULL       ((uint16_t)0x0200)      /*!< SPI rx fifo more than 0.25 full. */
#define SPI_RX_FIFO_LEVEL_STATUS_1_2_FULL       ((uint16_t)0x0400)      /*!< SPI rx fifo more than 0.5 full. */
#define SPI_RX_FIFO_LEVEL_STATUS_FULL           ((uint16_t)0x0600)      /*!< SPI rx fifo is full. */
/**
  * @}
  */


/** @defgroup SPI_flags SPI flags
  * @{
  */

#define SPI_FLAG_RXNE           				SPI_STS_RXNE        	/*!< Receive buffer not empty flag. */
#define SPI_FLAG_TXE            				SPI_STS_TXE         	/*!< Transmit buffer not empty flag. */
#define SPI_FLAG_I2SCSF         				SPI_STS_I2SCSF      	/*!< I2S channel side flag. */
#define SPI_FLAG_TXUFERR        				SPI_STS_TXUFERR     	/*!< Transmit data underflow error flag. */
#define SPI_FLAG_CRCERR         				SPI_STS_CRCERR      	/*!< CRC error flag. */
#define SPI_FLAG_MMERR          				SPI_STS_MMERR       	/*!< Multi-master error flag. */
#define SPI_FLAG_RXOFERR        				SPI_STS_RXOFERR     	/*!< Receive data overflow error flag. */
#define SPI_FLAG_BUSY           				SPI_STS_BUSY        	/*!< Busy flag. */
#define SPI_FLAG_NWERR          				SPI_STS_NWERR       	/*!< Error of SPI NSS or I2S WS. */
/**
  * @}
  */


/** @defgroup SPI_function_enable_reg SPI function enable reg
  * @{
  */

#define SPI_CRC_REG_TX                  		TCRC        			/*!< SPI CRC send reg. */
#define SPI_CRC_REG_RX                  		RCRC        			/*!< SPI CRC receive reg. */
#define SPI_ENABLE_REG_CRC              		CTR1        			/*!< SPI CRC enable reg. */
#define SPI_ENABLE_REG_NSS_OUT          		CTR2        			/*!< SPI NSS output enable reg. */
#define SPI_ENABLE_REG_NSS_PULSE        		CTR2        			/*!< SPI NSS pulse mode enable reg. */
#define SPI_ENABLE_REG_TI_MODE          		CTR2        			/*!< SPI TI mode enable reg. */
/**
  * @}
  */


/** @defgroup SPI_function_enable_bits SPI function enable bits
  * @{
  */

#define SPI_ENABLE_BIT_CRC              		SPI_CTR1_CRCEN      	/*!< SPI CRC enable bit. */
#define SPI_ENABLE_BIT_NSS_OUT          		SPI_CTR2_NSSOEN     	/*!< SPI NSS output enable bit. */
#define SPI_ENABLE_BIT_NSS_PULSE        		SPI_CTR2_NSSPM      	/*!< SPI NSS pulse mode enable bit. */
#define SPI_ENABLE_BIT_TI_MODE          		SPI_CTR2_TIEN       	/*!< SPI TI mode enable bit. */
/**
  * @}
  */
/**
  * @}
  */


/***************************************************************************************************
 * @functions
***************************************************************************************************/
/** @defgroup SPI_Exported_Functions SPI Exported Functions
  * @{
  */

/**
  * @brief  Deinitializes the SPIx peripheral registers to their default reset values.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return None.
  */
#define __SPI_DEF_INIT(SPIx)                        do{ \
                                                        ((RCU_PERI_RST_REG_##SPIx) |= (RCU_PERI_RST_BIT_##SPIx)); \
                                                        ((RCU_PERI_RST_REG_##SPIx) &= ~(RCU_PERI_RST_BIT_##SPIx)); \
                                                    } while(0U)


/**
  * @brief  Enables the SPIx.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return None.
  */
#define __SPI_ENABLE(SPIx)                          (SPIx->CTR1 |= SPI_CTR1_SPIEN) 


/**
  * @brief  Disables the SPIx.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return None.
  */
#define __SPI_DISABLE(SPIx)                         (SPIx->CTR1 &= ~SPI_CTR1_SPIEN)


/**
  * @brief  Transmit the SPIx CRC value.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return None.
  */
#define __SPI_CRC_SEND(SPIx)                        (SPIx->CTR1 |= SPI_CTR1_NXTCRC)


/**
  * @brief  Enables the SPI/I2S interrupts.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @param  INTR: SPI interrupt source to be enabled.
  *         It can be any combination of flowing values:
  *          @arg SPI_INTR_TXE: Tx buffer empty interrupt enable.
  *          @arg SPI_INTR_RXNE: Rx buffer not empty interrupt enable.
  *          @arg SPI_INTR_ERR: Error interrupt enable.
  * @return None.
  */
#define __SPI_INTR_ENABLE(SPIx, INTR)               (SPIx->CTR2 |= INTR)


/**
  * @brief  Disables the SPI/I2S interrupts.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @param  INTR: SPI interrupt source to be enabled.
  *         It can be any combination of flowing values:
  *          @arg SPI_INTR_TXE: Tx buffer empty interrupt enable.
  *          @arg SPI_INTR_RXNE: Rx buffer not empty interrupt enable.
  *          @arg SPI_INTR_ERR: Error interrupt enable.
  * @return None.
  */
#define __SPI_INTR_DISABLE(SPIx, INTR)              (SPIx->CTR2 &= ~(INTR))


/**
  * @brief  Enable the SPIx DMA interface.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @param  DIR: Specifies the SPI DMA transfer request to be enabled.
  *         It can be any combination of flowing values:
  *          @arg SPI_DMA_TX: Tx buffer DMA transfer request.
  *          @arg SPI_DMA_RX: Rx buffer DMA transfer request.
  * @return None.
  */
#define __SPI_DMA_ENABLE(SPIx, DIR)                 (SPIx->CTR2 |= DIR)


/**
 * 
  * @brief  Disable the SPIx/I2Sx DMA interface.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI/I2S mode.
  * @param  DIR: Specifies the SPI DMA transfer request to be enabled.
  *         It can be any combination of flowing values:
  *          @arg SPI_DMA_TX: Tx buffer DMA transfer request.
  *          @arg SPI_DMA_RX: Rx buffer DMA transfer request.
  * @return None.
  */
#define __SPI_DMA_DISABLE(SPIx, DIR)                (SPIx->CTR2 &= ~(DIR))


/**
  * @brief  Enables the specified function of SPIx.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  FUNC: Specifies the SPIx function.
  *         It can be one of the following values:
  *          @arg CRC: CRC value calculation enable.
  *          @arg NSS_OUT: SS output enable, It can be called only after the spi_init() has been called and the NSS
  *                        hardware management mode is selected.
  *          @arg NSS_PULSE: NSS pulse mode enable. It can be called only after the spi_init() function has been called. 
  *                          When TI mode is selected, the control bits NSSP is not taken into consideration and are
  *                          configured by hardware respectively to the TI mode requirements.
  *          @arg TI_MODE: TI mode enable.
  * @return None.
  */
#define __SPI_FUNC_ENABLE(SPIx, FUNC)               ((SPIx->SPI_ENABLE_REG_##FUNC) |= (SPI_ENABLE_BIT_##FUNC))


/**
  * @brief  Disables the specified function of SPIx.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  FUNC: Specifies the SPIx function.
  *         It can be one of the following values:
  *          @arg CRC: CRC value calculation enable.
  *          @arg NSS_OUT: SS output enable, It can be called only after the spi_init() has been called and the NSS
  *                        hardware management mode is selected.
  *          @arg NSS_PULSE: NSS pulse mode enable. It can be called only after the spi_init() function has been called. 
  *                          When TI mode is selected, the control bits NSSP is not taken into consideration and are
  *                          configured by hardware respectively to the TI mode requirements.
  *          @arg TI_MODE: TI mode enable.
  * @return None.
  */
#define __SPI_FUNC_DISABLE(SPIx, FUNC)              ((SPIx->SPI_ENABLE_REG_##FUNC) &= ~(SPI_ENABLE_BIT_##FUNC))


/**
  * @brief  Get the current SPIx Transmission FIFO filled level.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return The Transmission FIFO filling state.
  *          @arg SPI_TX_FIFO_LEVEL_STATUS_EMPTY: FIFO is empty.
  *          @arg SPI_TX_FIFO_LEVEL_STATUS_1_4_FULL: more than 1/4 full.
  *          @arg SPI_TX_FIFO_LEVEL_STATUS_1_2_FULL: more than 1/2 full.
  *          @arg SPI_TX_FIFO_LEVEL_STATUS_FULL: FIFO is full.
  */
#define __SPI_TXFIFO_STATUS_GET(SPIx)               (SPIx->STS & SPI_STS_TXFIFOS)


/**
  * @brief  Returns the current SPIx Reception FIFO filled level.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return The Reception FIFO filling state.
  *          @arg SPI_RX_FIFO_LEVEL_STATUS_EMPTY: FIFO is empty.
  *          @arg SPI_RX_FIFO_LEVEL_STATUS_1_4_FULL: more than 1/4 full.
  *          @arg SPI_RX_FIFO_LEVEL_STATUS_1_2_FULL: more than 1/2 full.
  *          @arg SPI_RX_FIFO_LEVEL_STATUS_FULL: FIFO is full.
  */
#define __SPI_RXFIFO_STATUS_GET(SPIx)               (SPIx->STS & SPI_STS_RXFIFOS)


/**
  * @brief  Checks whether the specified SPI flag is set or not.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral  in SPI mode.
  * @param  value: Specifies the SPI flag to check.
  *         It can be one of the following values:
  *          @arg TXE: Transmit buffer empty interrupt flag.
  *          @arg RXNE: Receive buffer not empty interrupt flag.
  *          @arg BUSY: Busy flag.
  *          @arg RXOFERR: Receiver data overflow error interrupt flag.
  *          @arg MMERR: Multi-master error interrupt flag.
  *          @arg CRCERR: CRC Error flag.
  *          @arg NWERR: Error of SPI NSS or I2S WS interrupt flag.
  *          @arg TXUFERR: Transmitter data underflow error interrupt flag.
  *          @arg I2SCSF: I2S Channel side flag)
  * @return SET or RESET.
  */
#define __SPI_FLAG_STATUS_GET(SPIx, FLAG)           ((SPIx->STS & (SPI_FLAG_##FLAG)) ? SET : RESET)


/**
  * @brief  Clears the SPIx CRC Error (CRCERR) flag.
  * @note   Only CRCERR can be clear.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @return None.
  */
#define __SPI_FLAG_CLEAR(SPIx)                      (SPIx->STS &= ~SPI_STS_CRCERR)


/**
  * @brief  Checks whether the specified SPI interrupt has enabled or not.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @param  INTR: Specifies the SPI interrupt source enable to check.
  *         It can be one of the following values:
  *          @arg TXE: Tx buffer empty interrupt get.
  *          @arg RXNE: Rx buffer not empty interrupt get.
  *          @arg RXOFERR: Receiver data overflow error interrupt get.
  *          @arg MMERR: Multi-master error interrupt get.
  *          @arg NWERR: Error of SPI NSS or I2S WS interrupt get.
  *          @arg TXUFERR: Transmitter data underflow error interrupt get.
  * @return SET or RESET.
  */
#define __SPI_INTR_ENABLE_STATUS_GET(SPIx, INTR)    ((SPIx->CTR2 & (SPI_INTR_##INTR)) ? SET : RESET)


/**
  * @brief  Checks whether the specified SPI interrupt has occured or not.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @param  INTR: Specifies the SPI interrupt source occoured to check.
  *         It can be one of the following values:
  *          @arg TXE: Tx buffer empty interrupt get.
  *          @arg RXNE: Rx buffer not empty interrupt get.
  *          @arg RXOFERR: Receiver data overflow error interrupt get.
  *          @arg MMERR: Multi-master error interrupt get.
  *          @arg NWERR: Error of SPI NSS or I2S WS interrupt get.
  *          @arg TXUFERR: Transmitter data underflow error interrupt get.
  * @return SET or RESET.
  */
#define __SPI_INTR_STATUS_GET(SPIx, INTR)           (__SPI_INTR_ENABLE_STATUS_GET(SPIx, INTR) && \
                                                     __SPI_FLAG_STATUS_GET(SPIx, INTR))


/**
  * @brief  Transmits a byte data through the SPIx.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Value to be transmitted.
  * @return None.
  */
#define __SPI_8BITS_DATA_SEND(SPIx,value)           (*(__IO uint8_t *)(SPIx##_BASE + 0x0C) = value)


/**
  * @brief  Transmits a 16bits data through the SPIx.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @param  value: Data to be transmitted.
  * @return None.
  */
#define __SPI_16BITS_DATA_SEND(SPIx,value)          ((SPIx->DATA) = value)


/**
  * @brief  Returns received a 8bits data by the SPIx.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @return The value of the received data.
  */
#define __SPI_8BITS_DATA_RECV(SPIx)                 (*(__IO uint8_t *)(SPIx##_BASE + 0x0C))


/**
  * @brief  Returns received a 16bits data by the SPIx. 
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral in SPI mode.
  * @return The value of the received data.
  */
#define __SPI_16BITS_DATA_RECV(SPIx)                ((uint16_t)(SPIx->DATA))


/**
  * @brief Returns the transmit or the receive CRC register value for the specified SPI.
  * @param  SPIx: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  DIR: Specifies the CRC register to be read.
  *         It can be one of the flowing values:
  *          @arg TX: Selects Tx CRC register.
  *          @arg RX: Selects Rx CRC register.
  * @return The selected CRC register value.
  */
#define __SPI_CRC_GET(SPIx, DIR)                    (SPIx->SPI_CRC_REG_##DIR)


/**
  * @brief  Returns the CRC Polynomial register value for the specified SPI.
  * @param  SPIx: pointer to SPIx (x can be 1 or 2) peripheral.
  * @return The CRC polynomial register value.
  */
#define __SPI_CRC_POLYN_GET(SPIx)                   (SPIx->CRCPOLYR)


/**
  * @brief  Fills each spi_config_t member with its default value.
  * @param  ptr_config: Pointer to a spi_config_t structure which will be initialized.
  * @return None.
  */
void spi_struct_init(spi_config_t* ptr_config);


/**
  * @brief  Initializes the SPIx peripheral according to the ptr_config.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral .
  * @param  ptr_config: Pointer to a spi_config_t structure that contains the configuration for SPI peripheral.
  * @return None.
  */
void spi_init(spi_reg_t* ptr_spi, spi_config_t* ptr_config);


/**
  * @brief  Configures the data width for the selected SPI.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI data size.
  *         It can be one of the following values:
  *          @arg SPI_DATA_WIDTH_4BIT: Specifies data width is 4 bits.
  *          @arg SPI_DATA_WIDTH_5BIT: Specifies data width is 5 bits.
  *          @arg SPI_DATA_WIDTH_6BIT: Specifies data width is 6 bits.
  *          @arg SPI_DATA_WIDTH_7BIT: Specifies data width is 7 bits.
  *          @arg SPI_DATA_WIDTH_8BIT: Specifies data width is 8 bits.
  *          @arg SPI_DATA_WIDTH_9BIT: Specifies data width is 9 bits.
  *          @arg SPI_DATA_WIDTH_10BIT: Specifies data width is 10 bits.
  *          @arg SPI_DATA_WIDTH_11BIT: Specifies data width is 11 bits.
  *          @arg SPI_DATA_WIDTH_12BIT: Specifies data width is 12 bits.
  *          @arg SPI_DATA_WIDTH_13BIT: Specifies data width is 13 bits.
  *          @arg SPI_DATA_WIDTH_14BIT: Specifies data width is 14 bits.
  *          @arg SPI_DATA_WIDTH_15BIT: Specifies data width is 15 bits.
  *          @arg SPI_DATA_WIDTH_16BIT: Specifies data width is 16 bits.
  * @return None.
  */
void spi_data_width_config(spi_reg_t * ptr_spi, uint16_t value);


/**
  * @brief  Configures the FIFO reception threshold for the selected SPI.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral .
  * @param  value: Specifies the FIFO reception threshold.
  *         It can be one of the following values:
  *          @arg SPI_FIFO_RX_THRESHOLD_HF: Event is generated if the FIFO level is greater or equal to 1/2.
  *          @arg SPI_FIFO_RX_THRESHOLD_QF: Event is generated if the FIFO  level is greater or equal to 1/4.
  * @return None.
  */
void spi_fifo_recv_threshold_config(spi_reg_t* ptr_spi, uint16_t value);


/**
  * @brief  Config the data transfer direction.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the data transfer direction.
  *         It can be one of the following values:
  *          @arg SPI_TRANSMIT_DIR_TX: SPI selects Tx transmit direction.
  *          @arg SPI_TRANSMIT_DIR_RX: SPI selects Rx receive direction.
  * @return None.
  */
void spi_transmit_direct_config(spi_reg_t* ptr_spi, uint16_t value);


/**
  * @brief  Configures NSS value in software NSS mode.
  * @note   It can be called only after the spi_init() function has  been called.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI NSS internal state.
  *         It can be one of the following values:
  *          @arg SPI_SOFTWARE_NSS_SET: Set NSS pin internally.
  *          @arg SPI_SOFTWARE_NSS_RESET: Reset NSS pin internally.
  * @return None.
  */
void spi_software_nss_config(spi_reg_t* ptr_spi, uint16_t value);


/**
  * @brief  Configures the CRC calculation length. 
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI CRC calculation length.
  *         It can be one of the following values:
  *          @arg SPI_CRC_LEN_8BIT: Set CRC Calculation to 8 bits.
  *          @arg SPI_CRC_LEN_16BIT: Set CRC Calculation to 16 bits.
  * @return None.
  */
void spi_crc_length_config(spi_reg_t* ptr_spi, uint16_t value);


/**
  * @brief  Configures the number of data Even/Odd for the DMA transfers.
  * @param  ptr_spi: Pointer to SPIx (x can be 1 or 2) peripheral.
  * @param  value: Specifies the SPI last DMA transfers state.
  *         It can be one of the following values:
  *          @arg SPI_DMA_TX_EVEN_RX_EVEN: TX and rx transmission data number are all even.
  *          @arg SPI_DMA_TX_ODD_RX_EVEN: TX data number is odd, rx data number is even.
  *          @arg SPI_DMA_TX_EVEN_RX_ODD: TX data number is even, rx data number is odd.
  *          @arg SPI_DMA_TX_ODD_RX_ODD: TX data number is odd, rx data number is odd.
  * @return None.
  */
void spi_dma_odd_even_config(spi_reg_t* ptr_spi, uint16_t value);
/**
  * @}
  */


#ifdef __cplusplus
}
#endif

#endif /* cbm858xm_spi.h */


/**
  * @}
  */

/**
  * @}
  */
