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
    tableWidget = new QTableWidget(2, 6);

    tableWidget->setHorizontalHeaderLabels(QStringList() << "FECHA_CORTE" << "UUID" << "FECHA_MUESTRA" << "Edad" << "Sexo" << "Institucion");

    tableWidget->setItem(0, 0, new QTableWidgetItem("Dato 00"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("Dato 01"));
    tableWidget->setItem(0, 2, new QTableWidgetItem("Dato 02"));
    tableWidget->setItem(0, 3, new QTableWidgetItem("Dato 03"));
    tableWidget->setItem(0, 4, new QTableWidgetItem("Dato 04"));
    tableWidget->setItem(0, 5, new QTableWidgetItem("Dato 06"));

    MaintenanceTable::setTable(tableWidget);
    // (FIN) TABLA DE EJEMPLO



    // CONTENEDOR 01
    QWidget *containerWidget1 = new QWidget();

    QVBoxLayout *containerLayout1 = new QVBoxLayout(containerWidget1);
    containerLayout1->addWidget(formularioBusqueda);
    containerLayout1->addWidget(content1);
    containerLayout1->addWidget(tableWidget);
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
