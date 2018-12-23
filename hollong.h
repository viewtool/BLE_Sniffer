/**
 ****************************************************************************************
 *
 * @file hollong.h
 *
 * @brief Main functionalities
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

#ifndef HOLLONG_H
#define HOLLONG_H

#include <QMainWindow>
#include <qdialog.h>
#include <qwidget.h>
#include <QTreeWidget>
#include "GenericTab.h"
#include "app_config.h"
#include "LocalTab.h"
#include "ConnectionTab.h"

#ifdef Q_OS_WIN32
#include <Windows.h>
#endif
#include "bletype.h"
#include "appsFunc.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
class QGroupBox;
class QDialogButtonBox;
class QTabWidget;
class QCheckBox;
QT_END_NAMESPACE

namespace Ui {
class vtool;
}

class vtool : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit vtool(QWidget *parent = 0);
    ~vtool();

public:
    int done_task;

public:
    friend class ConnectionTab;
    friend class GenericTab;
    friend class ModeTab;
 
private slots:
    void saveAs();
    void settingCOM();
    void showmasterSelected(QTreeWidgetItem * item, int column); //点击树节点事件
    
private:
    Ui::vtool *ui;

private:
    LocalTab *Local;

    GenericTab *Generic;


private:
    void createActions();
    void createMenus();
    void createToolBars();
    void treeWidgetInit();
    void rsp_cmd_process(uint8_t cmd, uint8_t *param, uint16_t param_len); 
    void rsp_cmd_hci_process(uint8_t type, uint8_t *param, uint16_t param_len); 
    uint8_t rx_raw_data_parse(uint8_t *rD, int rxSize); 	
    uint8_t rx_raw_data_retrieve_cmd(uint8_t cmd, uint8_t *rD);

    QMenu *fileMenu;
    QMenu *deviceMenu;

    QAction *saveAction;
    QAction *InitDeviceAction;
    QAction *COMAction;

    QToolBar *fileToolBar;
    QToolBar *deviceToolBar;
    QToolBar *editToolBar;

    bool slaveFlags;
    bool masterFlags;

    QCheckBox *masterCheckBox;
    QCheckBox *slave1CheckBox;

    QStringList treeWidgetHeaderList;
    QStringList rootTextList;
    QStringList masterNameTextList;
    QStringList slaveNameTextList;

    QTreeWidgetItem *master;
    QTreeWidgetItem *master1;

    QList<QTreeWidgetItem *> deviceNameList;


    QStringList test;
    QList <QStringList> dataHexInfo;
	
public slots:
    void receive_bdaddrInf(struct gap_read_bdaddr_req_cmp_evt bdaddrInfo);
    void receive_rx_raw_data(uint8_t *rxData, int rxSize);
    int   slo_bledev_discover_service(struct gatt_svc_rec *svc); 	
    int   slo_bledev_discover_chars(struct gatt_char_disc *char_rec); 	
    void slo_task_done(int task_id); 
    void timer_start(unsigned int *timerID); 
    void timer_end(unsigned int *timerID);	
    int timer_is_up(unsigned int timerID, unsigned int time); 	
    void timeup(); 


signals:
    void uart_opened(int port, int baudrate, int status);
    void rx_data_to_display(cmd_buf *cb);
    void rx_data_cmd_reset_received();
    void sig_cmd_read_version();
    void sig_cmd_read_local_mac();
    void gap_dev_inq_result_rep_info(struct gap_dev_inq_result_rep inqInf);
    void app_env_tag_Info(struct app_env_tag *app_env_Info);
    void app_env_tag_Info_final(struct app_env_tag *app_env_Info);	
    void gap_le_create_conn_req_cmp_evt_info(struct gap_le_create_conn_req_cmp_evt conn_inf_info);
    void call_api_info(QString str);
    void sig_rxbuf_processing(uint8_t *rxData, int rxSize);
    void app_dev_record_info(struct app_dev_record dev_rec_info);
    void vt_app_read_ver_req(struct gap_read_ver_req_cmp_evt temp);
    void sendbdaddrInfo(struct gap_read_bdaddr_req_cmp_evt temp);
    void app_svc_rec_info(struct gatt_svc_rec svc_rec_info);
    void gatt_disc_char_rec_info(struct gatt_disc_char_rec char_inf_info);	
    void sig_ota_start_scan(void);
    void sig_ota_connect(void); 	
    void sig_ota_discover_service(void);	
    void sig_ota_discover_characteristics(void);
    void sig_ota_ble_init_done(void);
    void sig_stop_scan_again(int count);
    void sig_discover_service(struct gatt_svc_rec *svc);
    void sig_discover_chars(struct gatt_char_disc *char_rec);
    void sig_notification(uint8_t *response,int len);
    void sig_bulk_notification(uint8_t cmd, uint8_t *response,int len);
    void timeout(); 

protected:
    int autoUpdateGUITimerID;
    unsigned int seconds_tick; 
    int failure_count; 
    uint32_t stopScanTimerID; 	
    uint32_t discServiceTimerID; 	
    uint32_t discCharsTimerID; 	
};

#endif // HOLLONG_H
