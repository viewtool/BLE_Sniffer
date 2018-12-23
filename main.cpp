/**
 ****************************************************************************************
 *
 * @file main.cpp
 *
 * @brief main entry
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
//#include <QtGui/QApplication>
#include <QApplication>
#include "app_config.h"
#include "am_aci.h"
#include "hollong.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vtool w;
    w.show();
    
    return a.exec();
}
