#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>

#include "./ui_mainwindow.h"

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

    if (username.toStdString() == "admin" && password.toStdString() == "admin"){
        this->hide();
        SecondWindow *second = new SecondWindow();
        second->show();
    } else {
        QMessageBox::information(this, "Información de inicio de sesión", "Usuario y/o contraseña incorrecto(s).");
    }
}

