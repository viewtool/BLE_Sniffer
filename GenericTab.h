/**
 ****************************************************************************************
 *
 * @file generictab.h
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

#ifndef GENERICTAB_H
#define GENERICTAB_H

#include <qwidget.h>
#if 0
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton.h>
#include <QtGui/QTreeWidgetItem>
#include <QtGui/QRadioButton>
#include <QtGui/QCheckBox>
#include <QFile>
#include <QtGui/QMessageBox>
#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#else
#include <QLineEdit>
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QRadioButton>
#include <QCheckBox>
#include <QFile>
#include <QMessageBox>
#include <QComboBox>
#include <QLabel>
#endif

#include "asGlobalFunc.h"
#include "bledll.h"
#include "LocalTab.h"

class GenericTab : public QWidget
{
    Q_OBJECT
public:
    explicit GenericTab(QWidget *parent = 0);
    //friend class vtool;
    ~GenericTab();

public:
    int privacyInfo();
    int decToBin(int decimal);
    void receTreeFromVt(QTreeWidget * temp);
    void receLocalFromVT(LocalTab *temp);
    void emit_raw_data(cmd_buf *cb);

private slots:
    //QString setDeviceNameSlot();
    void enableSlot();
    void disableSlot();
    void resetSlot();
    void stopScanSlot();
    void receive_bdaddrInf(struct gap_read_bdaddr_req_cmp_evt bdaddrInfo);
    void receive_app_env(struct app_env_tag *appenvInfo);
    void receive_app_env_final(struct app_env_tag *appenvInfo);	
    void pauseSlot();
    void randomSlot();
    void setSlot();
    void _randomSlot();
    void _setSlot();
    void endSetSlot();
    void timeup();

signals:
    void userGenericSet(struct S_GENERIC);
    void app_env_tag_Info_final(struct app_env_tag *app_env_Info);		
    void rx_data_to_display(cmd_buf *cb);

private:
    QCheckBox *activeScanCheckBox;
    QLabel *modeLabel;
    QCheckBox *whiteListCheckBox;
    QComboBox *modeComboBox;
    QLabel *devicesFoundLabel;
    QPushButton *pauseButton;
    QPushButton *cancelButton;

    QLabel *IRKLabel;
    QLabel *CSRKLabel;
    QLineEdit *IRKLineEdit;
    QLineEdit *CSRKLineEdit;
    QPushButton *randomButton;
    QPushButton *setButton;
    QPushButton *_randomButton;
    QPushButton *_setButton;

    QComboBox *endComboBox;
    QPushButton *endSetButton;

    QCheckBox *externalCheckBox;
    QPushButton *resetButton;
    QPushButton *stopScanButton;
    QPushButton *basicSetButton;

    QTreeWidget *ptreeWidget;
    LocalTab *Local;

    QString slavebdaddrStrAll;
    QStringList slavebdaddrList;

private:
    unsigned int seconds_tick;
    int capture_started;

protected:
};

#endif // GENERICTAB_H
