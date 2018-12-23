#ifndef CONNECTIONTAB_H
#define CONNECTIONTAB_H

#include <qwidget.h>
#if 0
#include <QtGui/QPushButton.h>
#include <QtGui/QRadioButton>
#include <QMessageBox>
#include <QtGui/QSpinBox>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#else
#include <QPushButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QComboBox>
#endif
#include "bledll.h"
#include "bletype.h"
#include "asGlobalFunc.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
class QGroupBox;
class QDialogButtonBox;
class QTabWidget;
QT_END_NAMESPACE

class ConnectionTab : public QWidget
{
    Q_OBJECT
public:
    ConnectionTab(QWidget *parent = 0);
    void setTreeWidget( QTreeWidget* temp )
    {
        treeWidget = temp;
    }
    uint8_t getfiltPolicy();

public slots:
    void establishSlot();
    void terminateSlot();
    void readSlot();
    //void updateSlot();

signals:
    //void gap_le_create_conn_req_cmp_evt_info(struct gap_le_create_conn_req_cmp_evt conn_inf_info);
    //void app_dev_record_info(struct app_dev_record dev_rec_info);
    void userConnectSetInfo(struct CONNECTINFO);
    void connectExcpMsg(QString );
private slots:
    void receive_conn_inf(struct gap_le_create_conn_req_cmp_evt connInfo);
    void receive_rem_inf(struct rem_info remInfo);

private:
    QLabel *minConnectIntervalLabel;
    QSpinBox *minConnectIntervalSpinBox;
    QLabel *minUnit;
    QLabel *maxConnectIntervalLabel;
    QSpinBox *maxConnectIntervalSpinBox;
    QLabel *maxUnit;
    QLabel *slaveLatencyLabel;
    QSpinBox *slaveLatencySpinBox;
    QLabel *superTimeoutLabel;
    QSpinBox *superTimeoutSpinBox;
    QLabel *superTimeoutUnit;

    QLabel *addrTypeLabel;
    QComboBox *addrTypeComboBox;
    QCheckBox *whiteListCheckBox;
    QLabel *slaveBDALabel;
    QComboBox *slaveBDAComboBox;
    QPushButton *establishButton;
    QPushButton *cancelButton;
    QLabel *connectHandleLabel;
    QLineEdit *connectHandleLineEdit;
    QPushButton *terminateButton;

    QLabel   *versionLabel;
    QLabel   *companyIDLabel;
    QLabel   *featuresLabel;
    QLineEdit *versionLineEdit;
    QLineEdit *companyIDLineEdit;
    QLineEdit *featuresLineEdit;
    QPushButton *readButton;

    QTreeWidget* treeWidget;

private:
};

#endif // CONNECTIONTAB_H
