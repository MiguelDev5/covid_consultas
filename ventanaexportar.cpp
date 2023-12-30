#include "ventanaexportar.h"
#include "ui_ventanaexportar.h"
#include "maintenancetable.h"
ventanaExportar::ventanaExportar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ventanaExportar)
{
    ui->setupUi(this);
}

ventanaExportar::~ventanaExportar()
{
    delete ui;
}

void ventanaExportar::on_pushButton_clicked()
{

}


void ventanaExportar::on_pushButton_expo_clicked()
{
    string nombreArchivo = ui->nombreArchivo->text().toStdString();
    MaintenanceTable::guardarCSV(nombreArchivo);
}

