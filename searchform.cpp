#include "searchform.h"
#include "maintenancetable.h"
#include "extractdata.h"
#include "listaenlazada.h"

SearchForm::SearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchForm)
{
    ui->setupUi(this);
}

SearchForm::~SearchForm()
{
    delete ui;
}

void SearchForm::on_pushButton_clicked(){
    MaintenanceTable::borrar();
    QTableWidget *tableWidget;

    ListaEnlazada *temList = ExtractData::getListaTotal();
    temList->eliminarfiltro();

    QString uuid = ui->uuid->text();
    QString fecha = ui->fecha->text();
    QString institucion = ui->institucion->text();
    QString ubigeo = ui->ubigeo->text();

    if(uuid.toStdString() != ""){
        temList->busqueda(1, uuid.toStdString());
    }
    if(fecha.toStdString() != ""){
        temList->busqueda(2, fecha.toStdString());
    }
    if(institucion.toStdString() != ""){
        temList->busqueda(3, institucion.toStdString());
    }
    if(ubigeo.toStdString() != ""){
        temList->busqueda(4, ubigeo.toStdString());
    }

    temList->getData();
}

