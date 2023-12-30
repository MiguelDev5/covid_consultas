#include "maintenancetable.h"

QTableWidget* MaintenanceTable::tableWidget = nullptr;

void MaintenanceTable::setTable(QTableWidget *newTable) {
    MaintenanceTable::tableWidget = newTable;
}

QTableWidget& MaintenanceTable::getTable() {
    if (!tableWidget) {
        // Manejar el caso en que la tabla no está inicializada
        throw std::runtime_error("La tabla no está inicializada");
    }

    return *tableWidget;
}

void MaintenanceTable::borrar() {
    int numRows = MaintenanceTable::tableWidget->rowCount();
    int numCols = MaintenanceTable::tableWidget->columnCount();

    // Limpiar el contenido de cada celda
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            QTableWidgetItem *item = tableWidget->item(i, j);
            if (item)
            {
                delete item; // Eliminar el objeto QTableWidgetItem
                tableWidget->setItem(i, j, nullptr); // Establecer la celda como nula
            }
        }
    }
}



