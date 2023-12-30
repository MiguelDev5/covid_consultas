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
void MaintenanceTable::guardarCSV(){
    int numRows = MaintenanceTable::tableWidget->rowCount();
    int numCols = MaintenanceTable::tableWidget->columnCount();

    // Nombre del archivo CSV
    std::string nombreArchivo = "resultadosDeTablaInterfaz.csv";

    // Abrir el archivo CSV para escritura
    std::ofstream archivoCSV(nombreArchivo);

    // GUARDAR el contenido de cada celda
    if (archivoCSV.is_open()){
        archivoCSV << "Fecha Corte;UUID;Fecha Muestra;Edad;Sexo;Institucion;Ubigeo Paciente;Departamento_Paciente;Provincia_Paciente;Distrito_Paciente;Departamento_Muestra;Provincia_Muestra;Distrito_Muestra;Tipo_Muestra;Resultado\n";
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                QTableWidgetItem *item = tableWidget->item(i, j);
                if (item)
                {
                    archivoCSV << item->text().toStdString() << ";";
                }
            }
            archivoCSV << "\n";
        }
        // Cerrar el archivo
        archivoCSV.close();
        std::cout << "Datos exportados exitosamente a " << nombreArchivo << std::endl;
    }else{
        std::cerr << "Error al abrir el archivo CSV." << std::endl;
    }

}




