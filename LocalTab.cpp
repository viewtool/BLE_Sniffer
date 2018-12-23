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


#include "common.h"
#include "app_config.h"
#include "LocalTab.h"
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>

LocalTab::LocalTab(QWidget *parent) : QWidget(parent)
{
    QPushButton *clearbutton     = new QPushButton("clear", this);
    QObject::connect(clearbutton, SIGNAL(clicked()), this, SLOT(clear()));

    QLabel *logAreaMarginLabel_1 = new QLabel(tr(""));
    QLabel *logAreaMarginLabel_2 = new QLabel(tr(""));
    QLabel *logAreaMarginLabel_3 = new QLabel(tr(""));
    logTextEdit = new QTextEdit(this);
   // logTextEdit->setFixedWidth(565);
   // logTextEdit->setFixedHeight(210);

    QScrollBar *sb = logTextEdit->verticalScrollBar();
    sb->setValue(sb->maximum());

    QHBoxLayout *horizontal = new QHBoxLayout;
    horizontal->addWidget(logAreaMarginLabel_1);
    horizontal->addWidget(logAreaMarginLabel_2);
    horizontal->addWidget(logAreaMarginLabel_3);
    horizontal->addWidget(clearbutton);

    QVBoxLayout *logAreaLayout = new QVBoxLayout;
    logAreaLayout->addWidget(logTextEdit);
    logAreaLayout->addLayout(horizontal);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(logAreaLayout);

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}
extern bool isLiteral(unsigned char c);
void LocalTab::receive_ver_inf(struct gap_read_ver_req_cmp_evt versionInfo)
{
}

void LocalTab::receive_bdaddr_inf(gap_read_bdaddr_req_cmp_evt addrInfo)
{
}

void LocalTab::receive_userGenericSet(S_GENERIC setGenericInfo)
{
}

void LocalTab::receive_userModeSet(struct S_DISCOVERING_MODE userModeSetInfo)
{
}

void LocalTab::receive_inqInf(struct gap_dev_inq_result_rep inqInf)
{
}

void LocalTab::receive_app_env(struct app_env_tag *appenvInfo)
{
}

void LocalTab::receive_userConnectSet(struct CONNECTINFO userConnectSetInfo)
{
}

void LocalTab::receive_conn_inf(struct gap_le_create_conn_req_cmp_evt connInfo)
{
}

void LocalTab::receive_connectExcpMsg(QString str)
{
}
void LocalTab::receive_dev_rec(app_dev_record devrecInfo)
{
}

void LocalTab::receive_userServiceDiscoverySet(SERVICE_DISCOVERY serviceInfo)
{
}

void LocalTab::receive_userCharDiscoverySet(CHAR_DISCOVERY charInfo)
{
}

void LocalTab::receive_userReadCharSet(READ_CHAR readCharInfo)
{
}

void LocalTab::receive_userWriteCharSet(WRITE_CHAR writeCharInfo)
{
}
void LocalTab::receive_svc_rec(gatt_svc_rec svcrecInfo)
{
}

void LocalTab::receive_char_inf(gatt_disc_char_rec charinfInfo)
{
}

#define BLE_LENGTH_MAX 1
void LocalTab::receive_exceptionMsg(const QString msg)
{
}

//extern volatile STATE state_message;

void LocalTab::receive_rem_inf(struct rem_info remInfo)
{
}

void LocalTab::receive_call_api_inf(QString str)
{
}

void LocalTab::clear()
{
    logTextEdit->clear();
}

void LocalTab::receive_uart_opened(int port, int baudrate, int status)
{
}

void LocalTab::rx_raw_data_display(cmd_buf *cb)
{
#if 1
    QString str; 
    QString s[512]; 
    int len, i;
    uint8_t header, packetID, cmd, param_len; 
    header = 0;
    packetID = 0;
    cmd = 0;
    param_len = cb->param_len;
    str.sprintf("0x%x,0x%x,0x%x,0x%x: ", header, packetID, cmd, param_len);
    qDebug() << "raw display:" << str;
#if 1
       for(i=0; i<param_len; i++)
	   {
	       s[i].sprintf("0x%x,", cb->param[i]);
           str.append(s[i]);
	   }
#endif
	logTextEdit->append(str);
#endif 
	QScrollBar *sbar = logTextEdit->verticalScrollBar();
	sbar->setValue(sbar->maximum());	
}

void LocalTab::ota_display(QString otaStr)
{
}


