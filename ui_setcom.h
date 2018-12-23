/********************************************************************************
** Form generated from reading UI file 'setcom.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETCOM_H
#define UI_SETCOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setCom
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *serialcomboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *BandcomboBox;
    QPushButton *okpushButton;
    QLineEdit *portStrEdit;

    void setupUi(QDialog *setCom)
    {
        if (setCom->objectName().isEmpty())
            setCom->setObjectName(QStringLiteral("setCom"));
        setCom->resize(302, 247);
        groupBox = new QGroupBox(setCom);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 140, 281, 51));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 261, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        serialcomboBox = new QComboBox(layoutWidget);
        serialcomboBox->setObjectName(QStringLiteral("serialcomboBox"));
        serialcomboBox->setMinimumSize(QSize(69, 20));

        horizontalLayout->addWidget(serialcomboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        BandcomboBox = new QComboBox(layoutWidget);
        BandcomboBox->setObjectName(QStringLiteral("BandcomboBox"));
        BandcomboBox->setMinimumSize(QSize(69, 20));

        horizontalLayout->addWidget(BandcomboBox);

        okpushButton = new QPushButton(setCom);
        okpushButton->setObjectName(QStringLiteral("okpushButton"));
        okpushButton->setGeometry(QRect(210, 200, 75, 23));
        portStrEdit = new QLineEdit(setCom);
        portStrEdit->setObjectName(QStringLiteral("portStrEdit"));
        portStrEdit->setGeometry(QRect(44, 190, 71, 20));

        retranslateUi(setCom);

        QMetaObject::connectSlotsByName(setCom);
    } // setupUi

    void retranslateUi(QDialog *setCom)
    {
        setCom->setWindowTitle(QApplication::translate("setCom", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("setCom", "Setting COM", Q_NULLPTR));
        label->setText(QApplication::translate("setCom", "COM", Q_NULLPTR));
        serialcomboBox->clear();
        serialcomboBox->insertItems(0, QStringList()
         << QApplication::translate("setCom", "1", Q_NULLPTR)
         << QApplication::translate("setCom", "2", Q_NULLPTR)
         << QApplication::translate("setCom", "3", Q_NULLPTR)
         << QApplication::translate("setCom", "4", Q_NULLPTR)
         << QApplication::translate("setCom", "5", Q_NULLPTR)
         << QApplication::translate("setCom", "6", Q_NULLPTR)
         << QApplication::translate("setCom", "7", Q_NULLPTR)
         << QApplication::translate("setCom", "8", Q_NULLPTR)
         << QApplication::translate("setCom", "9", Q_NULLPTR)
         << QApplication::translate("setCom", "10", Q_NULLPTR)
         << QApplication::translate("setCom", "11", Q_NULLPTR)
         << QApplication::translate("setCom", "12", Q_NULLPTR)
         << QApplication::translate("setCom", "13", Q_NULLPTR)
         << QApplication::translate("setCom", "14", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("setCom", "Baudrates", Q_NULLPTR));
        BandcomboBox->clear();
        BandcomboBox->insertItems(0, QStringList()
         << QApplication::translate("setCom", "9600", Q_NULLPTR)
         << QApplication::translate("setCom", "19200", Q_NULLPTR)
         << QApplication::translate("setCom", "28800", Q_NULLPTR)
         << QApplication::translate("setCom", "38400", Q_NULLPTR)
         << QApplication::translate("setCom", "57600", Q_NULLPTR)
         << QApplication::translate("setCom", "115200", Q_NULLPTR)
         << QApplication::translate("setCom", "230400", Q_NULLPTR)
         << QApplication::translate("setCom", "460800", Q_NULLPTR)
         << QApplication::translate("setCom", "921600", Q_NULLPTR)
        );
        okpushButton->setText(QApplication::translate("setCom", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class setCom: public Ui_setCom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETCOM_H
