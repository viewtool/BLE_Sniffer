/********************************************************************************
** Form generated from reading UI file 'hollong.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOLLONG_H
#define UI_HOLLONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vtool
{
public:
    QWidget *centralWidget;
    QGroupBox *devicegroupBox;
    QTreeWidget *treeWidget;
    QGroupBox *tracesgroupBox;
    QTabWidget *tracestabWidget;
    QGroupBox *settinggroupBox;
    QTabWidget *settingstabWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *vtool)
    {
        if (vtool->objectName().isEmpty())
            vtool->setObjectName(QStringLiteral("vtool"));
        vtool->resize(1194, 730);
        vtool->setMaximumSize(QSize(16777215, 730));
        vtool->setContextMenuPolicy(Qt::ActionsContextMenu);
        centralWidget = new QWidget(vtool);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        devicegroupBox = new QGroupBox(centralWidget);
        devicegroupBox->setObjectName(QStringLiteral("devicegroupBox"));
        devicegroupBox->setGeometry(QRect(10, 10, 601, 341));
        treeWidget = new QTreeWidget(devicegroupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 20, 581, 311));
        tracesgroupBox = new QGroupBox(centralWidget);
        tracesgroupBox->setObjectName(QStringLiteral("tracesgroupBox"));
        tracesgroupBox->setGeometry(QRect(10, 350, 601, 311));
        tracestabWidget = new QTabWidget(tracesgroupBox);
        tracestabWidget->setObjectName(QStringLiteral("tracestabWidget"));
        tracestabWidget->setGeometry(QRect(10, 20, 581, 281));
        settinggroupBox = new QGroupBox(centralWidget);
        settinggroupBox->setObjectName(QStringLiteral("settinggroupBox"));
        settinggroupBox->setGeometry(QRect(620, 10, 561, 651));
        settingstabWidget = new QTabWidget(settinggroupBox);
        settingstabWidget->setObjectName(QStringLiteral("settingstabWidget"));
        settingstabWidget->setGeometry(QRect(10, 20, 541, 624));
        settingstabWidget->setMinimumSize(QSize(541, 0));
        vtool->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vtool);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1194, 23));
        vtool->setMenuBar(menuBar);
        statusBar = new QStatusBar(vtool);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        vtool->setStatusBar(statusBar);

        retranslateUi(vtool);

        tracestabWidget->setCurrentIndex(-1);
        settingstabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(vtool);
    } // setupUi

    void retranslateUi(QMainWindow *vtool)
    {
        vtool->setWindowTitle(QApplication::translate("vtool", "HollongApp", Q_NULLPTR));
        devicegroupBox->setTitle(QApplication::translate("vtool", "Devices", Q_NULLPTR));
        tracesgroupBox->setTitle(QApplication::translate("vtool", "Traces", Q_NULLPTR));
        settinggroupBox->setTitle(QApplication::translate("vtool", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class vtool: public Ui_vtool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLLONG_H
