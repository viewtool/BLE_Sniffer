#ifndef VTGLOBALFUNC_H
#define VTGLOBALFUNC_H

#include <QTreeWidgetItem>
#include "bletype.h"

QTreeWidgetItem* addmasterInfoList(QTreeWidget *masterparent, QStringList masterInfoList);
QTreeWidgetItem* addslaveInfoList(QTreeWidgetItem *slaveparent, QStringList slaveInfoList, int index);
void Init();
QStringList getslaveInfoList();
QStringList getmasterInfoList();

QTreeWidgetItem* deleteslaveInfoList(int index);

#endif // VTGLOBALFUNC_H
