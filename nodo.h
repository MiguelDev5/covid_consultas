#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
using namespace std;

class Nodo{
public:
    string fecha_corte;
    string uuid;
    string fecha_muestra;
    string edad;
    string sexo;
    string institucion;
    string ubigeo_paciente;
    string departamento_paciente;
    string provincia_paciente;
    string distrito_paciente;
    string departamento_muestra;
    string provincia_muestra;
    string distrito_muestra;
    string tipo_muestra;
    string resultado;
    Nodo *siguiente;
    bool visible = true;

    Nodo(std::string fecha_corte, std::string uuid, std::string fecha_muestra,
         std::string edad, std::string sexo, std::string institucion,
         std::string ubigeo_paciente, std::string departamento_paciente,
         std::string provincia_paciente, std::string distrito_paciente,
         std::string departamento_muestra, std::string provincia_muestra,
         std::string distrito_muestra, std::string tipo_muestra,
         std::string resultado);
};

#endif // NODO_H
