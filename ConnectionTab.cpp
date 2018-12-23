#include "common.h"
#include "app_config.h"
#include "ConnectionTab.h"
#include "common.h"
#include "bledll.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QGroupBox>
#include <QtWidgets>


#define GAP_CONN_EST_SCAN_INT                               0x0500
#define GAP_CONN_EST_SCAN_WIND                              0x0160
#define GAP_CONN_EST_SUPERV_TIMEOUT                         0x07D0

#define GAP_CONN_EST_MAX_CE_LEN                             0x0140
#define GAP_CONN_EST_MIN_CE_LEN                             0x0000
#define GAP_UND_CONN_ADV_INT_MAX                            0x00A0
#define GAP_DIR_CONN_ADV_INT_MIN                            0x00A0

