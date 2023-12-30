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
    //QTableWidget *tableWidget;

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
    ui->edad->setText("");
    ui->sexo->setText("");
    ui->departamento->setText("");
    ui->provincia->setText("");
    ui->distrito->setText("");
    ui->tipo_muestra->setText("");
    ui->resultado->setText("");
}


void SearchForm::on_pushButton_2_clicked()
{
    MaintenanceTable::borrar();

    ListaEnlazada *copyList = new ListaEnlazada();
    ListaEnlazada *temList = ExtractData::getListaTotal();

    temList->listaCopia(copyList);

    //BORRAR LISTA COPIADA

    QString edad = ui->edad->text();
    QString sexo = ui->sexo->text();
    QString departamento = ui->departamento->text();
    QString provincia = ui->provincia->text();
    QString distrito = ui->distrito->text();
    QString tipo_muestra = ui->tipo_muestra->text();
    QString resultado = ui->resultado->text();

    if(edad.toStdString() != ""){
        copyList->filtro(1, edad.toStdString());
    }
    if(sexo.toStdString() != ""){
        copyList->filtro(2, sexo.toStdString());
    }
    if(departamento.toStdString() != ""){
        copyList->filtro(3, departamento.toStdString());
    }
    if(provincia.toStdString() != ""){
        copyList->filtro(4, provincia.toStdString());
    }
    if(distrito.toStdString() != ""){
        copyList->filtro(5, distrito.toStdString());
    }
    if(tipo_muestra.toStdString() != ""){
        copyList->filtro(6, tipo_muestra.toStdString());
    }
    if(resultado.toStdString() != ""){
        copyList->filtro(7, resultado.toStdString());
    }

    copyList->getData();
}

