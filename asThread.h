#ifndef VTTHREAD_H
#define VTTHREAD_H

#include <QThread>
#include <QtCore>
#include <QMap>


#ifdef Q_OS_WIN32
#include <Windows.h>
#endif
#include "vtcom.h"
#include "bledll.h"

typedef struct 
{
   int state; 
   char *key_str; 
}state_key_str; 


int rxbuf_to_be_processed(); 

class vtThread : public QThread
{
    Q_OBJECT
public:
    vtThread();
    ~vtThread();
public:
    void uart_proc();
    void rxData_display(int rxPos, int rxSize, uint8_t *rxData);
    void lookup();
    void rxData_process(unsigned char *rxData, unsigned int rxSize);

public:
    unsigned char writeBuffer[16];
    unsigned char readBuffer[16];
    vtble m_BLE;

protected:
    void run();

private:
    vtcom m_com;
    int com;
    int writeFlags;
    int readFlags;
    int ret;
    int timeout;
    int tx_size;	
    QMap<int, QString> gapmap;
    QMap<int, QString> gattmap;
    QMap<int, QString> smpcmap;

protected:

signals:
    void rx_raw_data_received(uint8_t *rxData, int rxSize);
    void bl_raw_data_received(uint8_t *rxData, int rxSize);
    void writeFlagChanged(int );
    void readFlagChanged(int );
    void exceptionMsg(const QString );

};

#endif // VTCOMTHREAD_H
