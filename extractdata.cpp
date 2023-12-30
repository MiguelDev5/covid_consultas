// extractdata.cpp
#include "extractdata.h"

// Inicializa el miembro estático
ListaEnlazada* ExtractData::listaTotal = nullptr;


ListaEnlazada* ExtractData::getListaTotal() {
    return listaTotal;
}

void ExtractData::setListaTotal(ListaEnlazada* nuevaLista) {
    listaTotal = nuevaLista;
}

void ExtractData::extraerRegistros(const std::string &rutaArchivo, char delimitador, ListaEnlazada *lista)
{
    std::ifstream archivo(rutaArchivo);
    std::string linea;

    if (!archivo.is_open())
    {
        std::cerr << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return;
    }

    // Liberar memoria de la lista anterior (si existe)
    delete listaTotal;
    listaTotal = new ListaEnlazada();

    while (std::getline(archivo, linea))
    {
        std::istringstream s(linea);
        std::string campo;

        while (std::getline(s, campo, delimitador))
        {
            if (!campo.empty())
            {
                std::string fecha_corte, uuid, fecha_muestra, edad, sexo, institucion,
                    ubigeo_paciente, departamento_paciente, provincia_paciente,
                    distrito_paciente, departamento_muestra, provincia_muestra,
                    distrito_muestra, tipo_muestra, resultado;

                fecha_corte = campo;
                std::getline(s, uuid, delimitador);
                std::getline(s, fecha_muestra, delimitador);
                std::getline(s, edad, delimitador);
                std::getline(s, sexo, delimitador);
                std::getline(s, institucion, delimitador);
                std::getline(s, ubigeo_paciente, delimitador);
                std::getline(s, departamento_paciente, delimitador);
                std::getline(s, provincia_paciente, delimitador);
                std::getline(s, distrito_paciente, delimitador);
                std::getline(s, departamento_muestra, delimitador);
                std::getline(s, provincia_muestra, delimitador);
                std::getline(s, distrito_muestra, delimitador);
                std::getline(s, tipo_muestra, delimitador);
                std::getline(s, resultado, delimitador);

                listaTotal->insertarAlInicio(
                    fecha_corte, uuid, fecha_muestra, edad, sexo, institucion,
                    ubigeo_paciente, departamento_paciente, provincia_paciente,
                    distrito_paciente, departamento_muestra, provincia_muestra,
                    distrito_muestra, tipo_muestra, resultado);
            }
        }
    }
}
