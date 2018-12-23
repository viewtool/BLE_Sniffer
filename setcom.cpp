/**
 ****************************************************************************************
 *
 * @file setcom.cpp
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

#include "common.h"
#include "app_config.h"
#include "setcom.h"
#include "ui_setcom.h"
#include <QtGui>
#ifdef Q_OS_WIN32
#include <Windows.h>
#endif

QString comStr;
QString baudrateStr;

extern int _com;
extern int _baudrate;

int com_port_setting_done = 1;

setCom::setCom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setCom)
{
    ui->setupUi(this);
    ui->portStrEdit->hide();
    connect(ui->serialcomboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(slotTextChange(QString)));

#ifdef Q_OS_MACOS
        ui->portStrEdit->show();
        ui->serialcomboBox->hide();
#endif
}

void setCom::set_com(int a, long b)
{
    str1 = QString::number(a, 10);
    str2 = QString::number(b, 10);
    ui->serialcomboBox->setEditable(true);
    ui->serialcomboBox->setEditText(str1);
    ui->BandcomboBox->setEditable(true);
    ui->BandcomboBox->setEditText(str2);
}

void setCom::set_com(QString a, long b) //for mac
{
    str1 = a;
    str2 = QString::number(b, 10);
    ui->portStrEdit->setText(str1);
    ui->BandcomboBox->setEditable(true);
    ui->BandcomboBox->setEditText(str2);
}
void setCom::on_okpushButton_clicked()
{
    QString strComport, strBaudrate;
    strComport = QString::number(_com, 10);
    strBaudrate = QString::number(_baudrate, 10);

    QString fileName = "setcom.ini";
    QFile file(fileName);
#ifdef Q_OS_MACOS
    comStr = ui->portStrEdit->text();
#else
    comStr = ui->serialcomboBox->currentText();

#endif
    baudrateStr = ui->BandcomboBox->currentText();
    if (file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&file);
        out << comStr << '|' << baudrateStr;
    }

    com_port_setting_done = 0;

    accept();
}

setCom::~setCom()
{
    delete ui;
}
void setCom::slotTextChange(QString str)
{
    if(str == "other")
        ui->portStrEdit->show();
}
