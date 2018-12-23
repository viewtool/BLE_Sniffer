#ifndef DIALOGFILEINFO_H
#define DIALOGFILEINFO_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QFileInfo>

namespace Ui {
class DialogFileInfo;
}

class DialogFileInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFileInfo(QWidget *parent = 0,QString fileName="");
    ~DialogFileInfo();
    int BlockSize;
private slots:
    void on_pushButtonOK_clicked();

    void on_checkBoxUserSettings_clicked(bool checked);

    void on_comboBoxBlockSize_currentIndexChanged(const QString &arg1);

    void on_comboBoxStorageType_currentIndexChanged(int index);

private:
    Ui::DialogFileInfo *ui;
    QString fileName;
    QFile *pFirmwareFile;
};

#endif // DIALOGFILEINFO_H
