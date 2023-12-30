#include "listaenlazada.h"
#include "maintenancetable.h"

Nodo *cabeza;
void ListaEnlazada::insertarAlInicio(string fecha_corte, string uuid, string fecha_muestra,
                      string edad, string sexo, string institucion,
                      string ubigeo_paciente, string departamento_paciente,
                      string provincia_paciente, string distrito_paciente,
                      string departamento_muestra, string provincia_muestra,
                      string distrito_muestra, string tipo_muestra,
                      string resultado)
{
    Nodo *nuevoNodo =
        new Nodo(fecha_corte, uuid, fecha_muestra, edad, sexo, institucion,
                 ubigeo_paciente, departamento_paciente, provincia_paciente,
                 distrito_paciente, departamento_muestra, provincia_muestra,
                 distrito_muestra, tipo_muestra, resultado);
    nuevoNodo->siguiente = cabeza;
    cabeza= nuevoNodo;
}

void ListaEnlazada::busqueda(int n, string dato)
{
    Nodo *actual = cabeza;
    switch (n)
    {
    case 1:
        while (actual != nullptr)
        {
            if (actual->uuid != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 2:
        while (actual != nullptr)
        {
            if (actual->fecha_muestra != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 3:
        while (actual != nullptr)
        {
            if (actual->institucion != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 4:
        while (actual != nullptr)
        {
            if (actual->ubigeo_paciente != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
    }
    cout << "Busqueda: " << endl;
}

void ListaEnlazada::mostrar()
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->visible == true)
        {
            std::cout << "Fecha Corte: " << actual->fecha_corte << std::endl
                      << "UUID: " << actual->uuid << std::endl
                      << "Fecha Muestra: " << actual->fecha_muestra << std::endl
                      << "Edad: " << actual->edad << std::endl
                      << "Sexo: " << actual->sexo << std::endl
                      << "Institucion: " << actual->institucion << std::endl
                      << "Ubigeo Paciente: " << actual->ubigeo_paciente << std::endl
                      << "Departamento Paciente: " << actual->departamento_paciente
                      << std::endl
                      << "Provincia Paciente: " << actual->provincia_paciente
                      << std::endl
                      << "Distrito Paciente: " << actual->distrito_paciente
                      << std::endl
                      << "Departamento Muestra: " << actual->departamento_muestra
                      << std::endl
                      << "Provincia Muestra: " << actual->provincia_muestra
                      << std::endl
                      << "Distrito Muestra: " << actual->distrito_muestra
                      << std::endl
                      << "Tipo Muestra: " << actual->tipo_muestra << std::endl
                      << "Resultado: " << actual->resultado << std::endl
                      << std::endl;
        }
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}


void ListaEnlazada::getData()
{
    Nodo *actual = cabeza;


    QTableWidget *tableWidget;
    //    tableWidget = new QTableWidget(2, 6);

    //    tableWidget->setHorizontaleaderLabels(QStringList() << "FECHA_CORTE" << "UUID" << "FECHA_MUESTRA" << "Edad" << "Sexo" << "Institucion");
    tableWidget = &MaintenanceTable::getTable();


    tableWidget->setItem(0, 0, new QTableWidgetItem("Dato 1234"));


    //    tableWidget->setTable(tableWidget);

    int count = 0;
    while (actual != nullptr)
    {
        if (actual->visible == true)
        {
            cout << "asdf" << count;
            tableWidget->setItem(count, 0, new QTableWidgetItem(QString::fromStdString(actual->fecha_corte)));
            tableWidget->setItem(count, 1, new QTableWidgetItem(QString::fromStdString(actual->uuid)));
            tableWidget->setItem(count, 2, new QTableWidgetItem(QString::fromStdString(actual->fecha_muestra)));
            tableWidget->setItem(count, 3, new QTableWidgetItem(QString::fromStdString(actual->edad)));
            tableWidget->setItem(count, 4, new QTableWidgetItem(QString::fromStdString(actual->sexo)));
            tableWidget->setItem(count, 5, new QTableWidgetItem(QString::fromStdString(actual->institucion)));
            tableWidget->setItem(count, 6, new QTableWidgetItem(QString::fromStdString(actual->ubigeo_paciente)));
            tableWidget->setItem(count, 7, new QTableWidgetItem(QString::fromStdString(actual->departamento_paciente)));
            tableWidget->setItem(count, 8, new QTableWidgetItem(QString::fromStdString(actual->provincia_paciente)));
            tableWidget->setItem(count, 9, new QTableWidgetItem(QString::fromStdString(actual->distrito_paciente)));
            tableWidget->setItem(count, 10, new QTableWidgetItem(QString::fromStdString(actual->departamento_muestra)));
            tableWidget->setItem(count, 11, new QTableWidgetItem(QString::fromStdString(actual->provincia_muestra)));
            tableWidget->setItem(count, 12, new QTableWidgetItem(QString::fromStdString(actual->distrito_muestra)));
            tableWidget->setItem(count, 13, new QTableWidgetItem(QString::fromStdString(actual->tipo_muestra)));
            tableWidget->setItem(count, 14, new QTableWidgetItem(QString::fromStdString(actual->resultado)));
            count++;
        }
        actual = actual->siguiente;

    }
    std::cout << std::endl;
}


void ListaEnlazada::filtro(int n, string dato)
{
    Nodo *actual = cabeza;
    switch (n)
    {
    case 1:
        while (actual != nullptr)
        {
            if (actual->edad != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 2:
        while (actual != nullptr)
        {
            if (actual->sexo != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 3:
        while (actual != nullptr)
        {
            if (actual->departamento_paciente != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 4:
        while (actual != nullptr)
        {
            if (actual->provincia_paciente != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 5:
        while (actual != nullptr)
        {
            if (actual->distrito_paciente != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
        break;
    case 6:
        while (actual != nullptr)
        {
            if (actual->tipo_muestra != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
    case 7:
        while (actual != nullptr)
        {
            if (actual->resultado != dato)
                actual->visible = false;
            actual = actual->siguiente;
        }
    }
    cout << "Filtro: " << endl;
}
void ListaEnlazada::eliminarfiltro()
{
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        actual->visible = true;
        actual = actual->siguiente;
    }
}

void ListaEnlazada::mostrarTabla()
{
    // Nombre del archivo CSV
    std::string nombreArchivo = "resuladosConFiltro.csv";

    // Abrir el archivo CSV para escritura
    std::ofstream archivoCSV(nombreArchivo);

    Nodo *actual = cabeza;
    if (archivoCSV.is_open()) {
        // Escribir los encabezados de las columnas
        archivoCSV << "Fecha Corte;UUID;Fecha Muestra;Edad;Sexo;Institucion;Ubigeo Paciente;Departamento_Paciente;Provincia_Paciente;Distrito_Paciente;Departamento_Muestra;Provincia_Muestra;Distrito_Muestra;Tipo_Muestra;Resultado\n";
        while (actual != nullptr)
        {
            if (actual->visible == true)
            {
                archivoCSV << actual->fecha_corte << ";"<<
                    actual->uuid << ";"<<
                    actual->fecha_muestra << ";"<<
                    actual->edad << ";"<<
                    actual->sexo << ";"<<
                    actual->institucion << ";"<<
                    actual->ubigeo_paciente << ";"<<
                    actual->departamento_paciente<< ";" <<
                    actual->provincia_paciente <<";"<<
                    actual->distrito_paciente << ";" <<
                    actual->departamento_muestra<< ";" <<
                    actual->provincia_muestra<<";"<<
                    actual->distrito_muestra<<";"<<
                    actual->tipo_muestra << ";"<<
                    actual->resultado << "\n";
            }
            actual = actual->siguiente;
        }
        // Cerrar el archivo
        archivoCSV.close();
        std::cout << "Datos exportados exitosamente a " << nombreArchivo << std::endl;
    }else {
        std::cerr << "Error al abrir el archivo CSV." << std::endl;
    }
    //std::cout << std::endl;
}

int* ListaEnlazada::busquedaDepartamentos(string depa)
{
    int *arr = new int[4];  // Asigna memoria para un arreglo de 4 elementos
    arr[0] = 0; //ASPIRADO TRAQUEAL
    arr[1] = 0; //HISOPADO NASAL Y FARINGEO
    arr[2] = 0; //LAVADO BRONCOALVEOLAR
    arr[3] = 0; //TEJIDO PULMONAR
    arr[4] = 0; //
    arr[5] = 0; //
    arr[6] = 0; //
    arr[7] = 0; //
    Nodo *actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->departamento_paciente == depa)
        {

            if(actual->resultado == "POSITIVO"){
                if (actual->tipo_muestra == "ASPIRADO TRAQUEAL")
                    arr[0]++;
                if (actual->tipo_muestra == "HISOPADO NASAL Y FARINGEO")
                    arr[1]++;
                if (actual->tipo_muestra == "LAVADO BRONCOALVEOLAR")
                    arr[2]++;
                if (actual->tipo_muestra == "TEJIDO PULMONAR")
                    arr[3]++;
            }else{
                if (actual->tipo_muestra == "ASPIRADO TRAQUEAL")
                    arr[4]++;
                if (actual->tipo_muestra == "HISOPADO NASAL Y FARINGEO")
                    arr[5]++;
                if (actual->tipo_muestra == "LAVADO BRONCOALVEOLAR")
                    arr[6]++;
                if (actual->tipo_muestra == "TEJIDO PULMONAR")
                    arr[7]++;
            }
        }
        actual = actual->siguiente;
    }
    return arr;
}

void ListaEnlazada::listaCopia(ListaEnlazada* listaCopia){
    Nodo *actual = cabeza;

    while (actual != nullptr)
    {
        if (actual->visible == true)
        {
            listaCopia->insertarAlInicio(actual->fecha_corte, actual->uuid, actual->fecha_muestra,
                                         actual->edad, actual->sexo, actual->institucion,
                                         actual->ubigeo_paciente, actual->departamento_paciente,
                                         actual->provincia_paciente, actual->distrito_paciente,
                                         actual->departamento_muestra, actual->provincia_muestra,
                                         actual->distrito_muestra, actual->tipo_muestra,
                                         actual->resultado);
        }
        actual = actual->siguiente;
    }
};
