/**
 ****************************************************************************************
 *
 * @file am_aci.h
 *
 * @brief Header file - AM_ACI.
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: $
 *
 ****************************************************************************************
 */
#ifndef AM_ACI_H_
#define AM_ACI_H_

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
#include <stdint.h>

#define MAX_BULK_DATA_LEN     4*1024


/*
 * ENUMERATION DEFINITIONS
 ****************************************************************************************
 */
/// GAP Interface
enum
{
	/// Cancel an existing connection request
	AM_ACI_CMD_REQ = 0,
	/// Read the white list size
	AM_ACI_CMD_1,
	/// Add device in the white list
	AM_ACI_CMD_RESET,
	/// Remove or clear device(s) in the white list
	AM_ACI_CMD_RESET_RESPONSE,
	/// Read Link and Host layer versions
	AM_ACI_CMD_READ_VER_REQ = 4,    
	// Read version response 
	AM_ACI_CMD_READ_VER_RSP, 
	/// Read Local Mac Address
	AM_ACI_CMD_READ_LOCAL_MAC_REQ,	
	// Read Local Mac Address response 
	AM_ACI_CMD_READ_LOCAL_MAC_RSP, 
	// Enter IAP mode for bootloader 
	AM_ACI_CMD_ENTER_ISP_CMD,
	// Response from device to make sure entered IAP mode, ready to receive IAP command
	AM_ACI_CMD_ENTER_ISP_RSP,
	///scan enable: 12
	AM_ACI_CMD_SCAN = 0x20,
	/// Read remote version information
	AM_ACI_CMD_SCAN_RESPONSE,    
	AM_ACI_CMD_STOP_SCAN           = 0x22,
	AM_ACI_CMD_STOP_SCAN_RSP           = 0x23,
	AM_ACI_CMD_CONNECT 			= 0x24,
	AM_ACI_CMD_CONNECT_RSP 			= 0x25,
	AM_ACI_CMD_DIS_SVC				= 0x26,
	AM_ACI_CMD_DIS_SVC_RSP				= 0x27,
	AM_ACI_CMD_DIS_CHAR			= 0x28,
	AM_ACI_CMD_DIS_CHAR_RSP  			= 0x29,
	AM_ACI_CMD_WRITE_CHAR			= 0x2A,
	AM_ACI_CMD_WRITE_CHAR_RSP			= 0x2B,
	AM_ACI_CMD_READ_CHAR			= 0x2C,
	AM_ACI_CMD_READ_CHAR_RSP			= 0x2D,    
	AM_ACI_CMD_DISCONNECT				= 0x2E,
	AM_ACI_CMD_DISCONNECT_RSP			= 0x2F,
	AM_ACI_CMD_WRITE_BULK_HEADER_CMD	= 0x30,
	AM_ACI_CMD_WRITE_BULK_HEADER_RSP	= 0x31,
	AM_ACI_CMD_WRITE_BULK_DATA_CMD 		= 0x32,
	AM_ACI_CMD_WRITE_BULK_DATA_RSP 		= 0x33,
	AM_ACI_CMD_EXCHANGE_MTU_CMD		= 0x34,
	AM_ACI_CMD_EXCHANGE_MTU_RSP		= 0x35,
	AM_ACI_CMD_FIND_INFO			= 0x36,
	AM_ACI_CMD_FIND_INFO_RSP		= 0x37,
};


#endif // AM_ACI_H_
