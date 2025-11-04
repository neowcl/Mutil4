
#include "main.h"

uint8_t  Ex_Flag;
 
uint8_t timea_prescaler=0;
uint16_t timea_comparison=1024; // 理论转换时间 250ms

extern volatile uint32_t timing_delay;

void delay_ms(volatile uint32_t value)
{
    timing_delay = value;

    while (timing_delay != 0);
}

/**
 * @fn void exti4_15_config(void)
 * @brief  Configure EXTI4_15 (PA6 as input).
 * @param  None
 * @return None
 */

void delay_us(uint32_t us)
{
    uint64_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD;

    ticks = us * (reload / (1000000 / RT_TICK_PER_SECOND));
    told = SysTick->VAL;
    while (1)
    {
        tnow = SysTick->VAL;
        if (tnow != told)
        {
            if (tnow < told)
            {
                tcnt += told - tnow;
            }
            else
            {
                tcnt += reload - tnow + told;
            }
            told = tnow;
            if (tcnt >= ticks)
            {
                break;
            }
        }
    }
}


void exti4_15_PA13_config(void)
{
    nvic_config_t nvic_config_struct;

    __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);
    __RCU_APB2_CLK_ENABLE(RCU_APB2_PERI_SYSCFG);
    /* Configure PA13 as input floating. */
    gpio_mode_set(GPIOA, GPIO_PIN_13, GPIO_MODE_IN_FLOAT);
    /* Connect EXTI13 Line to PA13 pin. */
	  syscfg_exti_line_config(SYSCFG_EXTI_PORT_PA, SYSCFG_EXTI_PIN_13); 
    /* Configure EXTI13 line. */
    __EXTI_INTR_ENABLE(EXTI_LINE_13);
    __EXTI_EDGE_ENABLE(EXTI_EDGE_RISING, EXTI_LINE_13);
	
	
//	
    /* Enable and set EXTI4_15 interrupt. */
    nvic_config_struct.IRQn = IRQn_EXTI4_15;
    nvic_config_struct.priority = 0x01;
    nvic_config_struct.enable_flag = ENABLE;
    nvic_init(&nvic_config_struct);
}

void exti4_15_PA11_config(void)
{
    nvic_config_t nvic_config_struct;

    __RCU_AHB_CLK_ENABLE(RCU_AHB_PERI_GPIOA);
    __RCU_APB2_CLK_ENABLE(RCU_APB2_PERI_SYSCFG);

    /* Connect EXTI13 Line to PA13 pin. */
    syscfg_exti_line_config(SYSCFG_EXTI_PORT_PA, SYSCFG_EXTI_PIN_11); 
    /* Configure EXTI13 line. */
    __EXTI_INTR_ENABLE(EXTI_LINE_11);
    __EXTI_EDGE_ENABLE(EXTI_EDGE_FALLING, EXTI_LINE_11);

    /* Enable and set EXTI4_15 interrupt. */
    nvic_config_struct.IRQn = IRQn_EXTI4_15;
    nvic_config_struct.priority = 0x01;
    nvic_config_struct.enable_flag = ENABLE;
    nvic_init(&nvic_config_struct);
}

#define PAGE_SIZE 1024

/**@brief Read a page at a specified address. Note unlock (gcr_reg_unlock()) before performing this operation.
 *
 * @param[in]  addr: Specifies the address to be read. Note address must be aligned to 4 bytes.
 * @param[in]  sz: Specifies the data length to be read.
 * @param[in]  buf: Specifies the data to be read.
 * @param[out] None.
 *
 * @return 	The return value refers to the flash_status_t enumeration value.
 */
flash_status_t flash_page_read(uint32_t addr, uint16_t sz, uint8_t *buf)
{
    uint16_t i, j;
    uint16_t repeat, remainder;
    uint32_t data;

    ASSERT(FLASH_PROGRAM_ADDRESS_CHECK(addr));
    //logInfo("addr %#X\n", addr);
    repeat = sz / 4;
    remainder = sz % 4;

    for(i = 0; i <= repeat; i++)
    {
        data = *(__IO uint32_t *)addr;     /*!< read flash data */
        if(i == repeat)
        {
            if(remainder > 0)
            {
                for(j = 0; j < remainder; j++)
                {
                    buf[j] = (uint8_t)(data >> (8 * j));
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            buf[0] = (uint8_t)data;
            buf[1] = (uint8_t)(data >> 8);
            buf[2] = (uint8_t)(data >> 16);
            buf[3] = (uint8_t)(data >> 24);
        }
        addr += 4;
        buf += 4;
    }
    return FLASH_STATUS_COMPLETE;
}



/**@brief Programs a page at a specified address.
 * 		  Note unlock (gcr_reg_unlock()) before performing this operation.
 *
 * @param[in]  addr: Specifies the address to be programmed. Note address needs to be word-aligned(4 byte).
 * @param[in]  buf: Specifies the data to be programmed.
 * @param[out] None.
 *
 * @return 	The return value refers to the flash_status_t enumeration value.
 */
flash_status_t flash_page_write(uint32_t addr, uint16_t sz, uint8_t *buf)
{
    uint32_t ret = 0;
    uint32_t data = 0;
    uint16_t repeat, remainder;
    uint32_t i, j;
    //logInfo("addr %#X", addr);
    
    repeat = sz / 4;
    remainder = sz % 4;

    for(i = 0; i <= repeat; i++)
    {
        data = 0;
        if(i == repeat)         /*!< The remaining data is less than 4 bytes */
        {
            if(remainder > 0)
            {
                for(j = 0; j < remainder; j++)
                {
                    data |= ((uint32_t)buf[j]) << (8 * j) ;
                }
                data |= 0xFFFFFFFFu << (8 * j);
            }
            else
            {
                break;
            }
        }
        else
        {
            data |= ((uint32_t)buf[3]) << 24;
            data |= ((uint32_t)buf[2]) << 16;
            data |= ((uint32_t)buf[1]) << 8;
            data |= ((uint32_t)buf[0]);
        }
        ret = flash_word_program(addr, data);
        if(ret == FLASH_STATUS_COMPLETE)
        {
            addr += 4;
            buf += 4;
        }
        else
        {
            return ret;
        }
    }
    return ret;
}


//更新flash的数据，需要先读取数据，然后再擦除和写入，操作一页时需要100ms
//0--ok, -1--fail
int8_t fmc_write_flash(uint32_t addr, const uint8_t *data, uint16_t len)
{
    uint16_t srcPos;
    uint16_t destPos;
    uint32_t start_addr;
    uint8_t page_buf[PAGE_SIZE];

    //flash_count_reg();//flash写入次数计数

    addr += FMC_DATA_FLASH_BASE_ADDR;//设置为绝对地址

    srcPos = 0;  //在data中的位置.
    destPos = addr % PAGE_SIZE;  //在page_buf中的位置
    start_addr = addr - destPos; // 计算起始的地址

    __disable_irq();// 关闭全局中断
    flash_unlock();

    while(srcPos < len)
    {
        flash_page_read(start_addr, PAGE_SIZE, page_buf);  // 读取整页

        while(destPos < PAGE_SIZE && srcPos < len)
        {
            page_buf[destPos++] = data[srcPos++];
        }
        //擦除
        if(FLASH_STATUS_COMPLETE != flash_page_erase(start_addr))
        {
            //report_error_code(ERROR_CODE_FLASH_BUSY);
            return -1;
        }
        // 保存页
        if(FLASH_STATUS_COMPLETE != flash_page_write(start_addr, PAGE_SIZE, page_buf))
        {
            //report_error_code(ERROR_CODE_FLASH_BUSY);
            return -1;
        }

        // NEXT PAGE.
        start_addr += PAGE_SIZE;
        destPos = 0;
    }

    flash_lock();
    __enable_irq();// 开启全局中断

    return 0;
}
