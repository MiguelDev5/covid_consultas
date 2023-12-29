#include "searchform.h"

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

void SearchForm::on_pushButton_clicked()
{
    // Nombre del archivo CSV que deseas buscar
    string nombreArchivo = "C:/MIGUEL/UNSA/TO/pruebas/pruebas.csv";

    // Valores que estás buscando en dos columnas específicas
    string valorBuscado1 = "29763924";
    string valorBuscado2 = "PRIVADO";

    // Números de columna en las que deseas buscar los valores
    size_t columnaBuscada1 = 2;  // Por ejemplo, buscar en la tercera columna
    size_t columnaBuscada2 = 6;  // Por ejemplo, buscar en la quinta columna

    // Llamada a la función y muestra de los resultados
    string resultados = MSearchController::buscarEnArchivoCSV(nombreArchivo, valorBuscado1, valorBuscado2, columnaBuscada1, columnaBuscada2);
    cout << resultados;
}

