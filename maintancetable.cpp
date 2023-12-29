#include "maintancetable.h"


QTableWidget* MaintanceTable::tableWidget = nullptr;

void MaintanceTable::setTable(QTableWidget *newTable) {
    tableWidget = newTable;
}
