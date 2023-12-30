#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>

#include "./ui_mainwindow.h"
#include "extractdata.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionMantenimiento_triggered()
{
    this->hide();
    SecondWindow *second = new SecondWindow();
    second->show();
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if (username == "admin" && password == "admin") {
        string rutaArchivo = "C:/Users/Usuario/Documents/Trabajos/pruebas.csv";
        char delimitador = ';';

        try {
            ListaEnlazada* lista = new ListaEnlazada();
            ExtractData::extraerRegistros(rutaArchivo, delimitador, lista);

            // Realizar operaciones con 'lista' si es necesario

            this->hide();
            SecondWindow *second = new SecondWindow();
            second->show();

            // Liberar memoria
            delete lista;
        } catch (const std::exception& e) {
            // Manejar excepciones al leer el archivo
            QMessageBox::critical(this, "Error de lectura", QString("Error al leer el archivo: ") + e.what());
        }
    } else {
        QMessageBox::information(this, "Información de inicio de sesión", "Usuario y/o contraseña incorrecto(s).");
    }
}

