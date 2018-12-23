/**
 ****************************************************************************************
 *
 * @file setcom.h
 *
 * @brief setting com port
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

#ifndef SETCOM_H
#define SETCOM_H

#include <QDialog>
#include <QLineEdit>
#include "ui_setcom.h"


namespace Ui {
class setCom;
}

class setCom : public QDialog, public Ui::setCom
{
    Q_OBJECT
    
public:
    explicit setCom(QWidget *parent = 0);
    ~setCom();
public:
    void set_com(int a, long b);
    void set_com(QString a, long b) ;
public:

private slots:
    //void accept();
    void on_okpushButton_clicked();
    void slotTextChange(QString);
private:
    Ui::setCom *ui;

private:
    QString str1, str2;
    QLineEdit *m_portInput;

};

#endif // SETCOM_H
