/**
 ****************************************************************************************
 *
 * @file app_config.h
 *
 * @brief Application Configuration File
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

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#ifndef WINDOWS
//#ifndef FALSE
#define FALSE 0
//#endif
//#ifndef TRUE
#define TRUE 1
//#endif
#endif
#define VT_SVC_DISC_USED   1
#define RW_BLE_USE_CRYPT   1

#define CFG_ALLROLES
#define CFG_CON    8
#define BLE_CONNECTION_MAX   8

#define BLE_SVC_REC_MAX     16
#define PASSKEY   111111

#define KEY_LEN             0x10
#define CFM_LEN             0x10
#define RAND_NB_LEN         0x08
#define BD_ADDR_LEN         0x06

#define OTA_MTU            247
#define MAX_BULK_DATA_LEN    (4*1024)

// Application Version Number
#define VT_APP_VER              "1.0.1"
// Application device name setting
#define VT_DEV_NAME             "VT BLE"

#define CONSOLE_MODE    1
#define CONSOLE_HEX_MODE    1

#define CMD_PACKET_MINIMUM_SIZE      5
#define CMD_PACKET_PARAM_LEN_POS   3

#define BOOTLOADER_CMD_PACKET_SIZE      4


#define WRITE_DATA_MAX    256

#define AM_FEATURES       1
#define OTA_FEATURE       1
#define BOOTLOADER_FEATURE  1
#define OTA_BULK             1


#if OTA_FEATURE
#define MAX_SCAN_TIME      3  // seconds
#else 
#define MAX_SCAN_TIME      10  // seconds
#endif 
#define STOP_SCAN_INTERVAL_TIME      1  // seconds
#define DISC_SERVICE_INTERVAL_TIME  3  // seconds
#define DISC_CHARS_INTERVAL_TIME     3  // seconds


#ifdef WIN32
#define SPRINTF(a)    TRACE a
#endif 

#endif // RWBLE_CONFIG_H_

