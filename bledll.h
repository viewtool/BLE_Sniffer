/**
 ****************************************************************************************
 *
 * @file bledll.h
 *
 * @brief ble dll funtion definition
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

#ifndef _BLEDLL_H
#define _BLEDLL_H

#pragma once
#ifdef BLEDLL_EXPORTS
	#define DLL_API _declspec(dllexport)
#else
	#define DLL_API _declspec(dllimport)
#endif

#include "retcode.h"
#ifdef Q_OS_WIN32
#include <Windows.h>
#endif
#include "type.h"

class vtble
{
public:
    vtble();
    ~vtble();
       int Open(unsigned int Timeout);
       void Close();
        void ble_init(void);
        void ble_reset_req(void);
        int ble_get_tx_ready();
        void ble_set_timeout(int time);
        void ble_set_tx_ready(int tx_ready);
        int ble_get_tx_size();
        int ble_get_rx_read_delay_time();
        void ble_set_rx_ready(int rx_ready);
        unsigned char *ble_get_tx_buffer();
        int ble_set_rx_data(unsigned char *buf, int size);
        int ble_rx_proc(unsigned char *rxData);
        int ble_read_ver_req(void);
        int ble_read_loc_addr_req(void);
        int ble_dev_inq_req(uint8_t inq_type, uint8_t own_addr_type);
        int ble_stop_dev_inq();
        int ble_dev_inq_req_set(uint8_t scan_type);
	 int ble_connection_config(struct gap_conn_param *conn_para);
        int ble_create_conn_req(void);
        int ble_discon_req(uint16_t connection_handle);
        int ble_disc_all_svc_req(struct gatt_svc_rec *svc);
        int ble_disc_all_char_req(struct gatt_char_disc *char_rec);
        int ble_write(uint8_t dev, uint8_t instance, uint16_t handle, uint8_t *data, uint16_t len);
        int ble_write_sync(uint8_t dev, uint8_t instance, uint16_t handle, uint8_t *data, uint16_t len); 		
        int ble_read(uint8_t dev, uint8_t instance, uint16_t handle);
        int ble_bulk_data_header_write(uint8_t device_id, uint8_t att_id, uint16_t charHdl, uint16_t checksum, uint16_t len);
	 int ble_bulk_data_write(uint8_t *data, uint16_t len);	
	 int uart_tx(uint8_t *buf, uint16_t size); 
	 int ble_exchange_MTU(uint8_t dev, uint8_t instance, uint16_t mtu); 
	 void ble_enter_iap(void); 
	 int ble_find_info(uint16_t start_handle, uint16_t end_handle, uint8_t dev, uint8_t instance); 

    protected:
        int m_hFile;
        bool m_bOpen;
};

#endif //_BLEDLL_H
