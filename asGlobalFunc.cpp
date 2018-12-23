#include "common.h"
#include "app_config.h"
#include "asGlobalFunc.h"
#include <QtWidgets>

QTreeWidgetItem *pmasterItem;
QTreeWidgetItem *pslaveItem[BLE_SCAN_DEVICE_MAX];
bool masterHaveAdded;
bool slaveHaveAdded[BLE_SCAN_DEVICE_MAX];
QStringList masterInfoLists = getmasterInfoList();
QStringList slaveInfoLists  = getslaveInfoList();
QList <QStringList> allSlaveInfoLists;

int slaveNum;
int slaveCounter;
int childCount;
bool connectSuccessOrNotFlag[BLE_CONNECTION_MAX];

void Init()
{
}

QTreeWidgetItem* addmasterInfoList(QTreeWidget *masterparent, QStringList masterInfoList)
{
    return NULL;
}

QTreeWidgetItem* addslaveInfoList(QTreeWidgetItem *slaveparent, QStringList slaveInfoList, int index)
{
    return NULL;
}

QTreeWidgetItem* deleteslaveInfoList(int index)
{
    return NULL;
}
QStringList getmasterInfoList()
{
}

QStringList getslaveInfoList()
{
}
