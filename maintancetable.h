#ifndef MAINTANCETABLE_H
#define MAINTANCETABLE_H

#include <QTableWidget>

class MaintanceTable{
public:
    static QTableWidget *tableWidget;

    MaintanceTable();

    static void setTable(QTableWidget *newTable);
};

#endif // MAINTANCETABLE_H
