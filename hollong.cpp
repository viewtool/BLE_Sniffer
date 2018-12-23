
/**
 ****************************************************************************************
 *
 * @file hollong.cpp
 *
 *
 * Copyright (C) ViewTool 2018
 *
 * $Rev: $
 *
 ****************************************************************************************
 */

#include "common.h"
#include "app_config.h"
#include "hollong.h"
#include "ui_hollong.h"
//#include <QtGui>
#include <QtWidgets>
#include "asGlobalFunc.h"
#include "setcom.h"

#include "vtcom.h"

#include "bledll.h"
#include <stdio.h>
#include "am_aci.h"

extern vtble myBLE;
extern int slaveCounter;
extern struct gap_dev_inq_result_rep inqInf;
extern struct app_env_tag *app_env;
extern struct gap_le_create_conn_req_cmp_evt conn_inf;
extern volatile rx_round_buf rxBuf;
extern cmd_buf cmdBuf;
extern struct app_dev_record *dev_rec;
extern struct gap_read_ver_req_cmp_evt verInf;
extern struct gap_read_bdaddr_req_cmp_evt bdaddrInf;
extern struct gatt_disc_char_rec *char_inf, charInf;
extern struct gatt_svc_rec svc_rec_info;
struct app_env_tag appEnv;
extern volatile int ota_state; 
extern volatile int tx_ready_to_send_data; 
extern int ota_bulk_mode; 
extern volatile int bootloader_ready; 
extern volatile int bootLoader_flag;
extern void rxbuf_retrieve_cmd();
extern int rxbuf_to_be_processed();

#ifndef WINDOWS
extern void Sleep(int ms);
#endif

vtool::vtool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vtool)
{
    ui->setupUi(this);
    autoUpdateGUITimerID = 0;
    autoUpdateGUITimerID = startTimer(50);
    QTimer *timer = new QTimer(this);
   // set timer for one second (1000ms)
   timer->start(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(timeup()));
    done_task = -1; 	// NO task done yet
    seconds_tick = 0;

    
     stopScanTimerID = 0; 
     discServiceTimerID = 0; 	
     discCharsTimerID = 0; 	

    createActions();
    createMenus();
    createToolBars();


    Local      = new LocalTab;

    Generic    = new GenericTab;
    Generic->receTreeFromVt(ui->treeWidget);
    Generic->receLocalFromVT(Local);
    connect(Generic, SIGNAL(userGenericSet(S_GENERIC)),
            Local, SLOT(receive_userGenericSet(S_GENERIC)));
    connect(Generic, SIGNAL(rx_data_to_display(cmd_buf*)),
             Local, SLOT(rx_raw_data_display(cmd_buf*)));
    ui->tracestabWidget->addTab(Local, tr("Local Device Traces"));

    masterFlags = true;
    if (masterFlags == true)
    {
        ui->settingstabWidget->clear();
        ui->settingstabWidget->addTab(Generic, tr("Generic"));
    }

    treeWidgetHeaderList << tr("Address") << tr("Name") << tr("Address Type") << tr("State") << tr("Role")
                         << tr("Authentication") << tr("Encryption") << tr("Version") << tr("Found");
    ui->treeWidget->setHeaderLabels(treeWidgetHeaderList);
    ui->treeWidget->setColumnWidth(0, 130);
    ui->treeWidget->setColumnWidth(1, 50);
    ui->treeWidget->setColumnWidth(2, 50);
    ui->treeWidget->setColumnWidth(3, 60);
    ui->treeWidget->setColumnWidth(4, 65);
    ui->treeWidget->setColumnWidth(5, 70);
    ui->treeWidget->setColumnWidth(6, 70);
    ui->treeWidget->setColumnWidth(7, 60);
    ui->treeWidget->setColumnWidth(8, 40);

    #pragma comment(lib, "./release/bledll.lib")
#ifdef WINDOWS
    QLibrary myLib1("vtble.dll");
    if (myLib1.load()) {
    }
    else {
        QMessageBox::warning(this, "Warning",
                             "vtble.dll loading failed!", QMessageBox::Ok);
        return;
    }
#endif
    connect(ui->treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            this, SLOT(showmasterSelected(QTreeWidgetItem*,int)));

    settingCOM();

}

void vtool::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(saveAction);

    deviceMenu = menuBar()->addMenu(tr("&Device"));
    deviceMenu->addAction(COMAction);
}

void vtool::createActions()
{
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setIcon(QIcon(":/images/save.png"));
    saveAction->setShortcut(QKeySequence::SaveAs);
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveAs()));

    COMAction = new QAction(tr("&Set COM"), this);
    connect(COMAction, SIGNAL(triggered()), this, SLOT(settingCOM()));
}

void vtool::createToolBars()
{
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(saveAction);

    deviceToolBar = addToolBar(tr("&Device"));
}

void vtool::saveAs()
{
    QString str = QDate::currentDate().toString("yyyy.MM.dd-") + QTime::currentTime().toString("hh.mm.ss");
    QString fileName = QFileDialog::getSaveFileName (this, tr("Save File"), str,
                            "Text files (*.txt);;Excel files (*.xls);;Any files (*)");
    if(fileName.isNull()) {
        return;
    }
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning (this, tr("save file"),
                    tr("can not save file %1:\n %2").arg(fileName).arg(file.errorString()));
    }
    else
    {
        QTextStream out(&file);
        out << Local->logTextEdit->toPlainText();
    }
}

bool isLiteral(unsigned char c)
{
    if((c == 0x20) || (c >= 0x30 && c <= 0x39) || (c >= 0x41 && c <= 0x5a) || (c >= 0x61 && c <= 0x7a) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void vtool::showmasterSelected(QTreeWidgetItem * item, int column)
{
}

int master_device_ready = 0;
extern int com_port_open_success;
extern int com_port_setting_done;
extern QStringList masterInfoLists;
extern int comOpenSucIndex;
int _com, _baudrate;
extern volatile int threadLife;

#ifdef Q_OS_MACOS
QString com;
#endif
void vtool::settingCOM()
{
}

extern QStringList masterInfoLists;

void vtool::receive_bdaddrInf(struct gap_read_bdaddr_req_cmp_evt bdaddrInfo)
{
}

// mode: 0=hex, 1=decimal
int convA2I(const char *string, int mode)
{
    int i, j=0, num = 0;

    if(string[0] == '\0')     /* null string */
        return -1;

    while(string[j] == ' ')
        j++;
    if( j== (int)strlen(string))  /* string with only spaces */
        return -2;

    switch(mode) {
    case 0:
        for (i=j; i<(int)strlen(string); i++) {
         if(string[i] >= '0' && string[i] <= '9') {
                num = num*16 + string[i]-'0';
         } else if(string[i] >= 'A' && string[i] <= 'F') {
                num = num*16 + string[i]-'A'+10;
         } else if(string[i] >= 'a' && string[i] <= 'f') {
                num = num*16 + string[i]-'a'+10;
         } else {
            return -1;
         }
        }
        break;
    case 1:
        for (i=j; i<(int)strlen(string); i++) {
            num = num*10 + string[i]-'0';
        }
        break;
    default:
        break;
    }
    return num;
}



#define KEYWORDS_SCAN_RESPONSE "BD Addr:"
#define KEYWORDS_CONNECTION_RESPONSE "BD"

/***
int strcspn(string, control) - search for init substring w/o control chars

Purpose:
       returns the index of the first character in string that belongs
       to the set of characters specified by control.  This is equivalent
       to the length of the length of the initial substring of string
       composed entirely of characters not in control.  Null chars not
       considered.

Entry:
      char *string - string to search
      char *control - set of characters not allowed in init substring

Exit:
      returns the index of the first char in string
      that is in the set of characters specified by control.

Uses:

Exceptions:

***/

int tStrCSpn(const char *pS, const char *pSS)
{
    const char *pStr, *pStrSet;
     pStr = pS;
     pStrSet = pSS;

    unsigned char map[32] = {0};

    while(*pStrSet)
    {
        map[*pStrSet >> 3] |= (1 << (*pStrSet & 7));
        pStrSet++;
    }

    map[0] |= 1;

    int count = 0;
    while(!(map[*pStr >> 3] & (1 << (*pStr & 7))))
    {
        count++;
        pStr++;
    }

    return count;
}

static int count_bledev_discover_service = 0;
int vtool::slo_bledev_discover_service(struct gatt_svc_rec *svc)
{
}

/**
 ****************************************************************************************
 *
 * @file hollong.cpp
 *
 * @brief Main functionalities
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

int vtool::slo_bledev_discover_chars(struct gatt_char_disc *char_rec)
{
}


#define BD_ADDR_FIRST_BYTE_POS    9
#define BD_ADDR_SPAN    3

/*
return retrieved command

*/
#define INPUT_DELAY_TIME    2000

void vtool::rsp_cmd_hci_process(uint8_t type, uint8_t *param, uint16_t param_len)
{
}

void vtool::rsp_cmd_process(uint8_t cmd, uint8_t *param, uint16_t param_len)
{
}

void vtool::receive_rx_raw_data(uint8_t *rxData, int rxSize)
{
}

void vtool::slo_task_done(int task_id)
{
}

void vtool::timer_start(unsigned int *timerID)
{
}

void vtool::timer_end(unsigned int *timerID)
{
}

int vtool::timer_is_up(unsigned int timerID, unsigned int time)
{
    return 1;
}


void vtool::timeup()
{
}

vtool::~vtool()
{
    delete ui;
}


