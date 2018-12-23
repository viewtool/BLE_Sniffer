/**
 ****************************************************************************************
 *
 * @file localtab.h
 *
 * @brief logging Window
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

#ifndef LOCALTAB_H
#define LOCALTAB_H

//#include <QtGui/QPushButton.h>
//#include <QtGui/QTextBrowser>
#include <QPushButton>
#include <QTextBrowser>
#include <QScrollBar>
#include <QStatusBar>
#include <QApplication>

#include "bletype.h"

class LocalTab : public QWidget
{
    Q_OBJECT
public:
    LocalTab(QWidget *parent = 0);
    QTextEdit *logTextEdit;

    friend class vtool;

public slots:
    void clear();
    void receive_ver_inf(struct gap_read_ver_req_cmp_evt versionInfo);
    void receive_bdaddr_inf(struct gap_read_bdaddr_req_cmp_evt addrInfo);
    void receive_app_env(struct app_env_tag *appenvInfo);
    void receive_inqInf(struct gap_dev_inq_result_rep inqInf);
    void receive_conn_inf(struct gap_le_create_conn_req_cmp_evt connInfo);
    void receive_dev_rec(struct app_dev_record devrecInfo);
    void receive_svc_rec(struct gatt_svc_rec svcrecInfo);
    void receive_char_inf(struct gatt_disc_char_rec charinfInfo);
    void receive_exceptionMsg(const QString msg);
    void receive_userConnectSet(struct CONNECTINFO userConnectSetInfo);
    void receive_userModeSet(struct S_DISCOVERING_MODE userModeSetInfo);
    void receive_userGenericSet(struct S_GENERIC setGenericInfo);
    void receive_userServiceDiscoverySet(struct SERVICE_DISCOVERY serviceInfo);
    void receive_userCharDiscoverySet(struct CHAR_DISCOVERY charInfo);
    void receive_userReadCharSet(struct READ_CHAR readCharInfo);
    void receive_userWriteCharSet(struct WRITE_CHAR writeCharInfo);
    void receive_connectExcpMsg(QString str);

    void receive_rem_inf(struct rem_info remInfo);
    void receive_call_api_inf(QString str);
    void receive_uart_opened(int port, int baudrate, int status);  
    void rx_raw_data_display(cmd_buf *cb);
    void ota_display(QString otaStr); 

public:

};

#endif // LOCALTAB_H
