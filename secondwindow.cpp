#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "maintenancetable.h"
#include "searchform.h"

#include <QTableWidget>
#include <QHeaderView>
#include <QDialog>
#include <QDebug>

SecondWindow::SecondWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::SecondWindow){
    ui->setupUi(this);

    // Crear el diseño principal
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QPushButton *searchButton = new QPushButton("Buscar", this);

    // Crear el formulario de búsqueda
    qDebug() << "Creando formulario de búsqueda";
    SearchForm *formularioBusqueda = new SearchForm();
    formularioBusqueda->setMinimumSize(200, 200);
    formularioBusqueda->setVisible(true);
    qDebug() << "Agregando formulario al diseño";

    // (INICIO) 3 TABBARS (Mantenimiento, Búsqueda, Estadística)
    tabWidget = new QTabWidget();
    tabWidget->setMinimumSize(400, 300);

    content1 = new QLabel("RESULTADOS DE LA BÚSQUEDA: ");
    content2 = new QLabel("Contenido de la opción 2");
    content3 = new QLabel("Contenido de la opción 3");
    // (FIN) 3 TABBARS




    // (INICIO) TABLA DE EJEMPLO
    QTableWidget *tableWidget;
    tableWidget = new QTableWidget(20, 15);

    tableWidget->setHorizontalHeaderLabels(QStringList()
                                           << "FECHA_CORTE"
                                           << "UUID"
                                           << "FECHA_MUESTRA"
                                           << "Edad"
                                           << "Sexo"
                                           << "Institucion"
                                           << "Ubigeo P."
                                           << "Departamento P"
                                           << "Provincia P"
                                           << "Distrito P"
                                           << "Departamento M."
                                           << "Provincia M."
                                           << "Distrito M."
                                           << "Tipo M."
                                           << "Resultado");

    MaintenanceTable::setTable(tableWidget);
    // (FIN) TABLA DE EJEMPLO



    // CONTENEDOR 01
    QWidget *containerWidget1 = new QWidget();

    QVBoxLayout *containerLayout1 = new QVBoxLayout(containerWidget1);
    containerLayout1->addWidget(formularioBusqueda);
    containerLayout1->addWidget(content1);
    containerLayout1->addWidget(MaintenanceTable::tableWidget);
    containerWidget1->setLayout(containerLayout1);
    formularioBusqueda->show();



    // CONTENEDOR 02
    QWidget *containerWidget2 = new QWidget();
    QVBoxLayout *containerLayout2 = new QVBoxLayout(containerWidget2);
    containerLayout2->addWidget(content2);
    containerLayout2->addWidget(searchButton);
    containerWidget2->setLayout(containerLayout2);



    // CONTENEDOR 03
    QWidget *containerWidget3 = new QWidget();
    QVBoxLayout *containerLayout3 = new QVBoxLayout(containerWidget3);
    containerLayout3->addWidget(content3);
    containerWidget3->setLayout(containerLayout3);



    // AGREGAR CONTENIDOS
    tabWidget->addTab(containerWidget1, "Búsqueda");
    tabWidget->addTab(containerWidget2, "Mantenimiento");
    tabWidget->addTab(containerWidget3, "Estadísticas");

    mainLayout->addWidget(tabWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

SecondWindow::~SecondWindow(){
    delete ui;
}

void SecondWindow::on_actionSalir_triggered(){
    this->hide();
    MainWindow *first = new MainWindow();
    first->show();
}

void SecondWindow::on_actionAcerca_de_triggered(){
    QTableWidget *tableWidget;
//    tableWidget = new QTableWidget(2, 6);

//    tableWidget->setHorizontaleaderLabels(QStringList() << "FECHA_CORTE" << "UUID" << "FECHA_MUESTRA" << "Edad" << "Sexo" << "Institucion");
    tableWidget = &MaintenanceTable::getTable();


    tableWidget->setItem(0, 0, new QTableWidgetItem("Dato 1234"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("Dato 012341"));
    tableWidget->setItem(0, 2, new QTableWidgetItem("Dato 01234"));
    tableWidget->setItem(0, 3, new QTableWidgetItem("Dato 012343"));
    tableWidget->setItem(0, 4, new QTableWidgetItem("Dato 012344"));
    tableWidget->setItem(0, 5, new QTableWidgetItem("Dato 0123416"));

//    tableWidget->setTable(tableWidget);

}


void SecondWindow::on_export_2_triggered()
{
    MaintenanceTable::guardarCSV();
    //ListaEnlazada *temList = ExtractData::getListaTotal();
    //temList->mostrarTabla();
}

