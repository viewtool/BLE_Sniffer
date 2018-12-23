#include "dialogfileinfo.h"
#include "ui_dialogfileinfo.h"

DialogFileInfo::DialogFileInfo(QWidget *parent, QString fileName) :
    QDialog(parent),
    ui(new Ui::DialogFileInfo)
{
}

DialogFileInfo::~DialogFileInfo()
{
}

void DialogFileInfo::on_checkBoxUserSettings_clicked(bool checked)
{
}

void DialogFileInfo::on_comboBoxBlockSize_currentIndexChanged(const QString &arg1)
{
}

void DialogFileInfo::on_comboBoxStorageType_currentIndexChanged(int index)
{
}
