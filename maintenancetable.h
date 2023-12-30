#ifndef MAINTENANCETABLE_H
#define MAINTENANCETABLE_H

#include <QTableWidget>
#include <iostream>
#include <fstream>
#include <sstream>
//#include <string>


class MaintenanceTable {
public:
    static QTableWidget* tableWidget;

    MaintenanceTable();

    static void setTable(QTableWidget *newTable);
    static QTableWidget& getTable();
    static void borrar();
    static void guardarCSV();
};

#endif // MAINTENANCETABLE_H
