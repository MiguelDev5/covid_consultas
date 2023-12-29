#ifndef MAINTENANCETABLE_H
#define MAINTENANCETABLE_H

#include <QTableWidget>

class MaintenanceTable {
public:
    static QTableWidget* tableWidget;

    MaintenanceTable();

    static void setTable(QTableWidget *newTable);
};

#endif // MAINTENANCETABLE_H
