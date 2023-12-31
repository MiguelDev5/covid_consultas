#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//#include <array>
#include "Nodo.h"

using namespace std;

// Definición de la clase ListaEnlazada
class ListaEnlazada{
private:
    Nodo *cabeza;
public:
    // Insertar un nuevo nodo al principio de la lista
    ListaEnlazada() : cabeza(nullptr){}
    // Insertar un nuevo nodo al principio de la lista
    void insertarAlInicio(string fecha_corte, string uuid, string fecha_muestra,
                          string edad, string sexo, string institucion,
                          string ubigeo_paciente, string departamento_paciente,
                          string provincia_paciente, string distrito_paciente,
                          string departamento_muestra, string provincia_muestra,
                          string distrito_muestra, string tipo_muestra,
                          string resultado);

    void busqueda(int n, string dato);
    void mostrar(); //consola
    void getData();
    void filtro(int n, string dato);
    void eliminarfiltro();
    void listaCopia(ListaEnlazada* listaCopia);
};

#endif // LISTAENLAZADA_H
