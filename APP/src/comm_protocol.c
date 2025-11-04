/***************************************************************************//**
 * @file     protocol.c
 * @version  V1.0.0
 * @author
 * @date
 * @brief
 *
 * @copyright Copyright (C) 2020 Chipsea Technologies Corp. All rights reserved.
 *****************************************************************************/

#include "main.h"
#include <stdlib.h>
#include "comm_protocol.h"
#include <string.h>
#include "hdp.h"


#define HMAC_SHA256_LENGTH             32




uint8_t rcv_random = 0;
uint8_t new_random = 0;

/**
  * @brief  cal_crc8_check
  * @param  input data
  * @retval crc8
  */
uint8_t cal_crc8_check(uint8_t *data, uint16_t len)
{
    uint8_t crc = 0;
    uint8_t i;

    while (len--)
    {
        crc ^= *data++;
        for (i = 0; i < 8; i++)
        {
            if (crc & 0x80)
            {
                crc = (uint8_t)((crc << 1) ^ 0x07);
            }
            else
            {
                crc <<= 1;
            }
        }
    }
    return crc;
}
    
/**
  * @brief  get_new_random
  * @param  上一次的随机数
  * @retval crc8
  */
uint8_t get_new_random(uint8_t last_random)
{
    uint8_t ret;
    srand(__LPTIM_COUNTER_GET());
    ret = (uint8_t)(rand()&0xFF);
    if(ret == last_random){
        ret += 1;
    }
    if(ret == 0){
        ret += 1;
    }
    return ret;
}

uint8_t task_event = 0;

/**
  * @brief  设置任务事件，用于debugmode接收完成操作
  * @param  事件值，按位计算
  * @retval none
  */
void set_task_event(uint8_t event)
{
    task_event |= event;
}

/**
  * @brief  check_rx_data_packet
  * @param  input data
  * @retval crc8
  */
int8_t check_rx_data_packet(uint8_t *input_data)
{
    uint8_t  cal_crc = 0;
    uint16_t packet_len;
    comm_rx_packet_t *rx_packet;
    rx_packet = (comm_rx_packet_t*) input_data;

    /*len check*/
    packet_len = rx_packet->len[1];
    packet_len =(packet_len << 8) + rx_packet->len[0] + 4;
    if(packet_len  > (255-1)){
        return RET_FAIL;
    }

    /*crc check*/
    cal_crc = cal_crc8_check(input_data, packet_len-1);
    if(cal_crc != *(input_data+packet_len-1)){
        return RET_CHECK_ERROR;
    }

    /*random check*/
    rcv_random = rx_packet->random;
    #if (RANDOM_ENABLE)
    if((rx_packet->cmd != CONNECTED_CMD)&&(rx_packet->cmd != READ_INFO_CMD)){
        if(rcv_random != new_random){
            return RET_RANDOM_ERROR;
        }
    }
    #endif

    return RET_OK;
}

/**
  * @brief  read ap information
  * @param  input data
  * @retval crc8
  */
// void filled_info_cmd(uint8_t *data)
// {
//     uint8_t sp_buf[16] = {0x00};

//     comm_tx_packet_t *tx_packet;
//     uint8_t *pdata;
//     tx_packet =  (comm_tx_packet_t*)data;

//     tx_packet->sync = SYNC_CODE;
//     tx_packet->cmd = READ_INFO_CMD + 0x80;
//     tx_packet->len[0]  = 4+8;//
//     tx_packet->len[1]  = 0;
//     tx_packet->errcode = RET_OK;
//     tx_packet->random[0] = rcv_random;
//     new_random = get_new_random(rcv_random);
//     tx_packet->random[1] = new_random;

//     pdata =  data + 7;

//     flash_unique_id_get(sp_buf);
//     memcpy(pdata, sp_buf, 16);  //chip id
//     pdata += 16;

//     *pdata = 0x02; pdata++;//APP

//     *pdata = FW_TYPE; pdata++;//ver H
//     *pdata = FW_VERSION >> 8; pdata++;//ver M
//     *pdata = FW_VERSION &0xFF; pdata++;//ver L
    
//     *pdata = 52; pdata++;//app size L
//     *pdata = 0; pdata++; //app size H
//     *pdata = 8; pdata++; //param size

//     tx_packet->len[0]  = 4 + 23;
//     *pdata = cal_crc8_check(data, tx_packet->len[0]+3);
// }

/**
  * @brief  connected_cmd
  * @param  input data
  * @retval crc8
  */
void filled_connected_cmd(uint8_t *data)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    tx_packet =  (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd = CONNECTED_CMD+0x80;
    tx_packet->len[0]  = 4+9;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = RET_OK;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = 0x02 ; pdata++;
    *pdata = 'C' ; pdata++;
    *pdata = 'B' ; pdata++;
    *pdata = 'M' ; pdata++;
    *pdata = 'X' ; pdata++;
    *pdata = '5' ; pdata++;
    *pdata = '8' ; pdata++;
    *pdata = 'X' ; pdata++;
    *pdata = 0 ; pdata++;
    *pdata = cal_crc8_check(data, tx_packet->len[0]+3);
}

/**
  * @brief  disconnected_cmd
  * @param  input data
  * @retval crc8
  */
void filled_disconnected_cmd(uint8_t *data)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    tx_packet = (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd = DISCONNECT_CMD+0x80;
    tx_packet->len[0]  = 4+0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = RET_OK;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check(data, tx_packet->len[0]+3);
}

/**
  * @brief  Command handshake authentication .
  * @param  None
  * @return command execute result.
  */
int8_t cmd_handshake(uint8_t *input_data)
{
/**
* @brief: the hamc sha256 key define
* User-provided key
*/
    uint8_t hmac_sha256_key[] = { 0xFF,0xFF,0x00,0x00,0xEE,0xEE,0x11,0x11,\
                                  0xDD,0XDD,0x22,0x22,0xCC,0xCC,0x33,0x33,\
                                  0xBB,0XBB,0X44,0X44,0XAA,0XAA,0X55,0X55,\
                                  0X99,0X99,0X88,0X88,0X66,0X66,0X77,0X77 };
    int8_t res = RET_OK;
    uint8_t  sha256_radombuff[HMAC_SHA256_LENGTH] = {0};
    uint8_t buf_calc_summary[HMAC_SHA256_LENGTH];

    memcpy(sha256_radombuff, &input_data[5], HMAC_SHA256_LENGTH);
    sha256_hmac_calc(&sha256_radombuff[0],
                    HMAC_SHA256_LENGTH,
                    &hmac_sha256_key[0],
                    sizeof(hmac_sha256_key),
                    &buf_calc_summary[0]);

    if(0 != memcmp(&input_data[5+32], &buf_calc_summary[0], HMAC_SHA256_LENGTH)){
        res = RET_FAIL;
    }
    return res;
}


int8_t handle_hmac(uint8_t *input_data,uint8_t *output_data)
{
    uint8_t hmac_sha256_key[HMAC_SHA256_LENGTH];
    int8_t res = RET_OK;
    uint8_t  sha256_radombuff[HMAC_SHA256_LENGTH] = {0};
    uint8_t buf_calc_summary[HMAC_SHA256_LENGTH];
   

    memcpy(hmac_sha256_key,SHA256_KEY,HMAC_SHA256_LENGTH);
    memcpy(sha256_radombuff, input_data, HMAC_SHA256_LENGTH);
    sha256_hmac_calc(&sha256_radombuff[0],
                    HMAC_SHA256_LENGTH,
                    &hmac_sha256_key[0],
                    sizeof(hmac_sha256_key),
                    &buf_calc_summary[0]);

     memcpy(output_data, &buf_calc_summary[0], HMAC_SHA256_LENGTH);
    
    return 0;
}

/**
  * @brief  filled_authen_cmd.
  * @param  None
  * @return none.
  */
void filled_authen_cmd(uint8_t *data)
{
    int res;
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;

    res = cmd_handshake(data);

    tx_packet = (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd = AUTHEN_CMD+0x80;
    tx_packet->len[0]  = 4+0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = res;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check(data, tx_packet->len[0]+3);
}

/**
  * @brief  filled_write_block_cmd.
  * @param
  * @return none.
  */
void filled_write_block_cmd(uint8_t *data)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    tx_packet = (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd = WRITE_BLOCK_CMD + 0x80;
    tx_packet->len[0]  = 4+0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = RET_OK;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check( data, tx_packet->len[0]+3);
}

/**
  * @brief  filled_read_block_cmd.
  * @param
  * @return none.
  */
void filled_read_block_cmd(uint8_t *data)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    tx_packet = (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd  = READ_BLOCK_CMD + 0x80;
    tx_packet->len[0]  = 4+0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = RET_OK;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check( data, tx_packet->len[0]+3);
}

/**
  * @brief  跳转至boot.
  * @param
  * @return none.
  */
void filled_jump_cmd(uint8_t *data)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    int8_t err_code = RET_OK;
    tx_packet = (comm_tx_packet_t*)data;
    err_code = RET_UNSEAL_ERR;
    /* 判断解锁状态 */
    if(f_us)
    { 
        err_code = RET_OK;
        set_task_event(JUMP_EVENT);
    }

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd = JUMP_CMD + 0x80;
    tx_packet->len[0]  = 4 + 0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = err_code;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check( data, tx_packet->len[0]+3);
}

/**
  * @brief  解锁memory操作.
  * @param
  * @return none.
  */
void filled_unlock_memory_cmd(uint8_t *data)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    tx_packet = (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd = UNLOCK_PARAM_CMD + 0x80;
    tx_packet->len[0]  = 4+0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = RET_OK;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check( data, tx_packet->len[0]+3);
}

//芯片复位处理
void run_task_event(void)
{
    if(task_event&JUMP_EVENT){
        task_event ^= JUMP_EVENT;
        //enter_reset();
    }
}

/**
  * @brief  错误码响应帧.
  * @param
  * @return none.
  */
void tx_err_code_packet(uint8_t *data, uint8_t err_code)
{
    comm_tx_packet_t *tx_packet;
    uint8_t *pdata;
    tx_packet =  (comm_tx_packet_t*)data;

    tx_packet->sync = SYNC_CODE;
    tx_packet->cmd |= 0x80;
    tx_packet->len[0]  = 4+0;
    tx_packet->len[1]  = 0;
    tx_packet->errcode = err_code;
    tx_packet->random[0] = rcv_random;
    new_random = get_new_random(rcv_random);
    tx_packet->random[1] = new_random;
    pdata =  data+7;
    *pdata = cal_crc8_check(data, tx_packet->len[0]+3);
}


/**
  * @brief  解析接收帧.
  * @param
  * @return none.
  */
int8_t parse_rx_data_packet(uint8_t *input_data)
{
    comm_rx_packet_t *rx_packet;
    rx_packet = (comm_rx_packet_t*) input_data;
   // logInfo("private cmd = %#X", rx_packet->cmd);

    switch(rx_packet->cmd)
    {
        case CONNECTED_CMD: //50 连接扫描
            filled_connected_cmd(input_data);
            break;
        case READ_INFO_CMD: //51 读取信息
            //filled_info_cmd(input_data);
            break;
        case AUTHEN_CMD:    //52 鉴权
            filled_authen_cmd(input_data);
            break;
        case JUMP_CMD:      //53 跳转
            filled_jump_cmd(input_data);
            break;
        // case UNLOCK_PARAM_CMD: //56 解锁命令
        //     filled_unlock_memory_cmd(input_data);
        //     break;
        // case READ_DATA_MEMORY_CMD:  //57 读取参数区
        //     data_memory_read_fun(input_data);
        //     break;
        // case WRITE_DATA_MEMORY_CMD: //58 写参数区
        //     data_memory_write_fun(input_data);
        //     break;
        // case DISCONNECT_CMD:        //5A 断开连接命令
        //     filled_disconnected_cmd(input_data);
        //     break;
        // case WRITE_REGISTER_CMD:   //5B 写寄存器
        //     register_write_fun(input_data);
        //     break;
        // case READ_REGISTER_CMD:     //5C 读寄存器
        //     register_read_fun(input_data);
        //     break;
        // case WRITE_BLOCK_CMD:       //60写command 命令
        //     //filled_write_block_cmd(input_data);
        //     //write_command_id_handle(input_data);
        //     break;
        // case READ_BLOCK_CMD:        //5F 读command 命令
        //     //filled_read_block_cmd(input_data);
        //     //read_command_id_handle(input_data);
        //     break;
    }
    return 0;
}
