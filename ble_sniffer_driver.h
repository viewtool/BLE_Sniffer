/**
 ****************************************************************************************
 *
 * @file ble_sniffer_driver.h
 *
 * @brief driver funtion definition
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: 1.0$
 *
 * Change History:
 * 12/21/18: Initial release, working on capturing BLE data, see captured data in file: 2018.12.21-14.52.34.txt
 *
 ****************************************************************************************
 */


#ifndef __BLE_SNIFFER_DRIVER_H__
#define __BLE_SNIFFER_DRIVER_H__

#ifndef WINAPI
#ifndef OS_UNIX
#define WINAPI __stdcall
#else
#define WINAPI
#endif // OS_UNIX
#endif
#include <stdint.h>


typedef void (WINAPI *bsniffer_get_raw_data_cb_fn)(int dev_index,int channel,unsigned char *data,int data_len);

#ifdef __cplusplus
extern "C"
{
#endif

int WINAPI scan_dev(uint64_t *pserial);
int WINAPI open_dev(int dev_index);
int WINAPI close_dev(int dev_index);
int WINAPI get_raw_data(int dev_index,bsniffer_get_raw_data_cb_fn get_raw_data_cb_fn,int timeout);

int WINAPI start_get_data(int dev_index,bsniffer_get_raw_data_cb_fn callback);
int WINAPI stop_get_data(int dev_index);

#ifdef __cplusplus
}
#endif

#endif
