#include "maintenancetable.h"

QTableWidget* MaintenanceTable::tableWidget = nullptr;

void MaintenanceTable::setTable(QTableWidget *newTable) {
    MaintenanceTable::tableWidget = newTable;
}

