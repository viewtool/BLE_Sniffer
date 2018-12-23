
/**
 ****************************************************************************************
 *
 * @file generictab.cpp
 *
 * @brief first page displayed
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
#include "GenericTab.h"

#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>

#include <QApplication>
#ifdef Q_OS_WIN32
#include <Windows.h>
#endif
#include <stdlib.h>
#include "ble_sniffer_driver.h"
#include "LocalTab.h"

/**
 ****************************************************************************************
 *
 * @file generictab.cpp
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: $
 *
 ****************************************************************************************
 */

cmd_buf cmdBuf;
extern vtble myBLE;
extern unsigned char inq_type;
extern unsigned char inq_mode;
extern struct gap_read_ver_req_cmp_evt verInf;
extern struct gap_read_bdaddr_req_cmp_evt bdaddrInf;
extern struct gap_event_common_cmd_complete ret;
extern QStringList masterInfoLists;
extern QString comStr, baudrateStr;
extern int com_port_open_success;
extern struct app_env_tag *app_env, appEnv;

GenericTab::GenericTab(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    resetButton     = new QPushButton(tr("Reset"));
    connect(resetButton, SIGNAL(clicked()),
            this, SLOT(resetSlot()));
    pauseButton = new QPushButton(tr("Pause/Play"));
    connect(pauseButton, SIGNAL(clicked()),
            this, SLOT(pauseSlot()));
    QHBoxLayout *endButtonLayout = new QHBoxLayout;
    endButtonLayout->addWidget(resetButton);
    endButtonLayout->addWidget(pauseButton);
    mainLayout->addLayout(endButtonLayout);
    mainLayout->addStretch(1);
    setLayout(mainLayout);

    seconds_tick = 0;
    QTimer *timer = new QTimer(this);
   // set timer for 2 mini seconds (2ms)
    timer->start(2);
    capture_started = 0;
    cmdBuf.flag = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(timeup()));

}

GenericTab::~GenericTab()
{
}

struct S_GENERIC genericInfo;
void GenericTab::enableSlot()
{
}

extern QTreeWidgetItem *pmasterItem;
extern QTreeWidgetItem *pslaveItem[8];
extern QStringList slaveInfoLists;
extern QStringList masterInfoLists;
extern QList <QStringList> allSlaveInfoLists;
extern int slaveNum;
extern int slaveCounter;
extern int childCount;
void GenericTab::pauseSlot()
{
    capture_started ^= 1;
}

void GenericTab::receive_app_env(struct app_env_tag *appenvInfo)
{
}

void GenericTab::receive_app_env_final(struct app_env_tag *appenvInfo)
{
}


void GenericTab::disableSlot()
{
}

int GenericTab::privacyInfo()
{
    return NULL;
}
struct ble_device{
    QString Name;
    QString MacAddr;
    uint32_t AccessAddress;
    int RSSI;
    bool Selected;
    QString Status;
    uint32_t NoNewDataTime;
    uint32_t judge_disconnected;
    int connected_channel;
};

struct rawshark_rec_s {
    uint32_t ts_sec;      /* Time stamp (seconds) */
    uint32_t ts_usec;     /* Time stamp (microseconds) */
    uint32_t caplen;      /* Length of the packet buffer */
    uint32_t len;         /* "On the wire" length of the packet */
};

QList<struct ble_device> bleDevList;
HANDLE hPipe[20] = {NULL};
bool getDataFlag = false;
QMutex mutex;
//bool pipeConnectFlag = false;
uint64_t TimeOffset = 0;
uint64_t StartTimestamp = 0;

QString WINAPI findBleDevName(uint8_t *pData,int len)
{
        return "UNKNOWN DEVICE";
}

void WINAPI addDevToList(struct ble_device bleDev)
{
}

void WINAPI printf_raw_data(int channel,unsigned char *data,int data_len)
{
    QString str;
    uint32_t AccessAddress = data[10]|(data[11]<<8)|(data[12]<<16)|(data[13]<<24);
    str = QTime::currentTime().toString("ss:zzz ");
    str.append(QString().sprintf("%d(%d)-->",channel,data_len));
    for(int i=0;i<data_len;i++){
        if(i == 10){
            str.append(QString().sprintf("[%02X ",data[i]));
        }else if(i == 13){
            str.append(QString().sprintf("%02X] ",data[i]));
        }else{
            if(AccessAddress == 0x8e89bed6){
                if(i == 16){
                    str.append(QString().sprintf("[%02X ",data[i]));
                }else if(i == 21){
                    str.append(QString().sprintf("%02X] ",data[i]));
                }else{
                    str.append(QString().sprintf("%02X ",data[i]));
                }
            }else{
                str.append(QString().sprintf("%02X ",data[i]));
            }
        }
    }
    qDebug()<<str;
}

void WINAPI get_raw_data_cb(int dev_index,int channel,unsigned char *data,int data_len)
{
    QMutexLocker locker(&mutex);
#if 1
    cmdBuf.flag = 1;
    cmdBuf.param_len = data_len;
    memcpy(cmdBuf.param, data, data_len);
    printf_raw_data(channel,data,data_len);
    return;
#endif
    //qDebug()<<"get_raw_data_cb in";
    //qDebug()<<QTime::currentTime().toString("hh:mm");
    uint64_t us = (uint64_t)data[3]|((uint64_t)data[4]<<8)|((uint64_t)data[5]<<16)|((uint64_t)data[6]<<24)|((uint64_t)data[7]<<32)|((uint64_t)data[8]<<40);
    us >>= 5;
    if(TimeOffset == 0){
        TimeOffset = us;
        qDebug()<<"TimeOffset = "<<TimeOffset;
    }
#ifdef QT_DEBUG
    QString TimeStr;
    TimeStr.sprintf("%02X%02X%02X%02X%02X%02X",data[8],data[7],data[6],data[5],data[4],data[3]);
    qDebug()<<"Time = "<<TimeStr;
#endif
    getDataFlag = true;
    struct ble_device bleDev;
    int i=0;
    bleDev.AccessAddress = data[10]|(data[11]<<8)|(data[12]<<16)|(data[13]<<24);
    if(bleDev.AccessAddress == 0x8e89bed6){
        uint8_t PDUType = data[14]&0xF;
        uint8_t payload_len = data[15]&0x3F;
        switch(PDUType)
        {
            case 0x00://ADV_IND
            case 0x01://ADV_DIRECT_IND
            case 0x02://ADV_NONCONN_IND
            case 0x06://ADV_SCAN_IND
            case 0x04://SCAN_RSP
            //将设备添加或者更新到设备列表中
            bleDev.MacAddr = QString().sprintf("%02X:%02X:%02X:%02X:%02X:%02X",data[21],data[20],data[19],data[18],data[17],data[16]);
            bleDev.Name = findBleDevName(&data[22],payload_len-6);//减去6字节MAC地址
            bleDev.RSSI = data[data_len-2]-94;
            bleDev.Status = "disconnected";
            bleDev.NoNewDataTime = 0;
            for(i=0;i<bleDevList.length();i++){
                if((bleDev.MacAddr == bleDevList.at(i).MacAddr)){
                    if(bleDevList.at(i).Status != "disconnected"){
                        if(channel == bleDevList.at(i).connected_channel){//若建立连接的通道也收到了广播包，则证明确实是断开了连接
                            addDevToList(bleDev);
                        }
                    }else{
                        addDevToList(bleDev);
                    }
                    break;
                }
            }
            //列表中没有添加设备，新增设备
            if(i == bleDevList.length()){
                addDevToList(bleDev);
            }
            break;
            case 0x03://SCAN_REQ
            bleDev.MacAddr = QString().sprintf("%02X:%02X:%02X:%02X:%02X:%02X",data[21+6],data[20+6],data[19+6],data[18+6],data[17+6],data[16+6]);
            for(int i=0;i<bleDevList.length();i++){
                if((bleDev.MacAddr == bleDevList.at(i).MacAddr)){
                    bleDev = bleDevList.at(i);
                    bleDev.RSSI = data[data_len-2]-94;
                    bleDev.Status = "disconnected";
                    bleDev.NoNewDataTime = 0;
                    bleDevList.replace(i,bleDev);
                }
            }
            break;
            case 0x05://CONNECT_REQ
            bleDev.MacAddr = QString().sprintf("%02X:%02X:%02X:%02X:%02X:%02X",data[21+6],data[20+6],data[19+6],data[18+6],data[17+6],data[16+6]);
            qDebug()<<"CONNECT MacAddr == "<<bleDev.MacAddr;
            for(int i=0;i<bleDevList.length();i++){
                if((bleDev.MacAddr == bleDevList.at(i).MacAddr)){
                    qDebug()<<"CONNECT AccessAddress = "<<QString().sprintf("%08X",bleDev.AccessAddress);
                    bleDev = bleDevList.at(i);
                    bleDev.RSSI = data[data_len-2]-94;
                    bleDev.AccessAddress = data[10+12+2+4+0]|(data[10+12+2+4+1]<<8)|(data[10+12+2+4+2]<<16)|(data[10+12+2+4+3]<<24);
                    bleDev.Status = "connecting";
                    bleDev.NoNewDataTime = 0;
                    bleDev.judge_disconnected = 0;
                    bleDev.connected_channel = channel;
                    bleDevList.replace(i,bleDev);
                }
            }
            break;
            default:
            break;
        }
    }else{
        int i = 0;
        for(i=0;i<bleDevList.length();i++){
            if((bleDev.AccessAddress == bleDevList.at(i).AccessAddress)){
                bleDev = bleDevList.at(i);
                bleDev.RSSI = data[data_len-2]-94;
                bleDev.Status = "connected";
                bleDev.judge_disconnected = 0;
                bleDev.NoNewDataTime = 0;
                bleDevList.replace(i,bleDev);
                break;
            }
        }
    }
    getDataFlag = false;
    //qDebug()<<"get_raw_data_cb out";
}

void GenericTab::resetSlot()
{
    int DevIndex = 0;
    int ret;
    if(1){
        ret = scan_dev(NULL);
        if(ret <= 0){
            qDebug()<<"scan_dev() : "<<ret;
            QMessageBox::warning(this,"Warning","No device connected!");
            return;
        }
        ret = open_dev(DevIndex);
        if(ret != 3){
            QMessageBox::warning(this,"Warning","Open device faild!");
            return;
        }
        TimeOffset = 0;
        StartTimestamp = QDateTime::currentDateTime().currentMSecsSinceEpoch();
        start_get_data(DevIndex,get_raw_data_cb);
        capture_started = 1;
        qDebug()<<"start get data";
    }else{
        stop_get_data(DevIndex);
        qDebug()<<"stop get data";
    }
}

void GenericTab::stopScanSlot()
{
}

extern QStringList masterInfoLists;
void GenericTab::receive_bdaddrInf(struct gap_read_bdaddr_req_cmp_evt bdaddrInfo)
{
}

void GenericTab::receTreeFromVt(QTreeWidget *temp)
{
}

void GenericTab::receLocalFromVT(LocalTab *temp)
{
    Local = temp;
}

void GenericTab::randomSlot()
{
}

void GenericTab::setSlot()
{
}

void GenericTab::_randomSlot()
{
}

void GenericTab::_setSlot()
{
}

uint8_t sec_lvl;
void GenericTab::endSetSlot()
{
}

void GenericTab::timeup()
{
    seconds_tick++;
    if(capture_started && (cmdBuf.flag == 1))
    {
        cmdBuf.flag = 0;
        emit rx_data_to_display(&cmdBuf);
    }
//    qDebug()<<"seconds_tick:"<<seconds_tick;
}
