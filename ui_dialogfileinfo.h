/********************************************************************************
** Form generated from reading UI file 'dialogfileinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFILEINFO_H
#define UI_DIALOGFILEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogFileInfo
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *labelFileName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *labelFileSize;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *labelFileVision;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *labelFileType;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLabel *labelStorageType;
    QCheckBox *checkBoxUserSettings;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *comboBoxBlockSize;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *comboBoxStorageType;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *DialogFileInfo)
    {
        if (DialogFileInfo->objectName().isEmpty())
            DialogFileInfo->setObjectName(QStringLiteral("DialogFileInfo"));
        DialogFileInfo->resize(308, 243);
        gridLayout = new QGridLayout(DialogFileInfo);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(DialogFileInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(80, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        labelFileName = new QLabel(DialogFileInfo);
        labelFileName->setObjectName(QStringLiteral("labelFileName"));
        labelFileName->setFrameShape(QFrame::WinPanel);
        labelFileName->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(labelFileName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DialogFileInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(80, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        labelFileSize = new QLabel(DialogFileInfo);
        labelFileSize->setObjectName(QStringLiteral("labelFileSize"));
        labelFileSize->setFrameShape(QFrame::WinPanel);
        labelFileSize->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(labelFileSize);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(DialogFileInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(80, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        labelFileVision = new QLabel(DialogFileInfo);
        labelFileVision->setObjectName(QStringLiteral("labelFileVision"));
        labelFileVision->setFrameShape(QFrame::WinPanel);
        labelFileVision->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(labelFileVision);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(DialogFileInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(80, 16777215));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        labelFileType = new QLabel(DialogFileInfo);
        labelFileType->setObjectName(QStringLiteral("labelFileType"));
        labelFileType->setFrameShape(QFrame::WinPanel);
        labelFileType->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(labelFileType);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(DialogFileInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(80, 16777215));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_5);

        labelStorageType = new QLabel(DialogFileInfo);
        labelStorageType->setObjectName(QStringLiteral("labelStorageType"));
        labelStorageType->setFrameShape(QFrame::WinPanel);
        labelStorageType->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(labelStorageType);


        verticalLayout->addLayout(horizontalLayout_5);

        checkBoxUserSettings = new QCheckBox(DialogFileInfo);
        checkBoxUserSettings->setObjectName(QStringLiteral("checkBoxUserSettings"));

        verticalLayout->addWidget(checkBoxUserSettings);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(DialogFileInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(80, 16777215));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        comboBoxBlockSize = new QComboBox(DialogFileInfo);
        comboBoxBlockSize->setObjectName(QStringLiteral("comboBoxBlockSize"));
        comboBoxBlockSize->setEnabled(false);

        horizontalLayout_6->addWidget(comboBoxBlockSize);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(DialogFileInfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(80, 16777215));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_7);

        comboBoxStorageType = new QComboBox(DialogFileInfo);
        comboBoxStorageType->setObjectName(QStringLiteral("comboBoxStorageType"));
        comboBoxStorageType->setEnabled(false);

        horizontalLayout_7->addWidget(comboBoxStorageType);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(DialogFileInfo);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout_8->addWidget(pushButtonOK);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(DialogFileInfo);

        comboBoxBlockSize->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(DialogFileInfo);
    } // setupUi

    void retranslateUi(QDialog *DialogFileInfo)
    {
        DialogFileInfo->setWindowTitle(QApplication::translate("DialogFileInfo", "File Infomation", Q_NULLPTR));
        label->setText(QApplication::translate("DialogFileInfo", "Name:", Q_NULLPTR));
        labelFileName->setText(QApplication::translate("DialogFileInfo", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogFileInfo", "Size:", Q_NULLPTR));
        labelFileSize->setText(QApplication::translate("DialogFileInfo", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogFileInfo", "Vision:", Q_NULLPTR));
        labelFileVision->setText(QApplication::translate("DialogFileInfo", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogFileInfo", "File Type:", Q_NULLPTR));
        labelFileType->setText(QApplication::translate("DialogFileInfo", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogFileInfo", "Storage Type:", Q_NULLPTR));
        labelStorageType->setText(QApplication::translate("DialogFileInfo", "TextLabel", Q_NULLPTR));
        checkBoxUserSettings->setText(QApplication::translate("DialogFileInfo", "User Settings", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogFileInfo", "Block Size:", Q_NULLPTR));
        comboBoxBlockSize->clear();
        comboBoxBlockSize->insertItems(0, QStringList()
         << QApplication::translate("DialogFileInfo", "32", Q_NULLPTR)
         << QApplication::translate("DialogFileInfo", "64", Q_NULLPTR)
         << QApplication::translate("DialogFileInfo", "128", Q_NULLPTR)
         << QApplication::translate("DialogFileInfo", "256", Q_NULLPTR)
         << QApplication::translate("DialogFileInfo", "512", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("DialogFileInfo", "Storage Type:", Q_NULLPTR));
        comboBoxStorageType->clear();
        comboBoxStorageType->insertItems(0, QStringList()
         << QApplication::translate("DialogFileInfo", "internal flash", Q_NULLPTR)
         << QApplication::translate("DialogFileInfo", "external flash", Q_NULLPTR)
        );
        pushButtonOK->setText(QApplication::translate("DialogFileInfo", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogFileInfo: public Ui_DialogFileInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFILEINFO_H
