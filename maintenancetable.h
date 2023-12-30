#ifndef MAINTENANCETABLE_H
#define MAINTENANCETABLE_H

#include <QTableWidget>

class MaintenanceTable {
public:
    static QTableWidget* tableWidget;

    MaintenanceTable();

    static void setTable(QTableWidget *newTable);
    static QTableWidget& getTable();
    static void borrar();
};

#endif // MAINTENANCETABLE_H
