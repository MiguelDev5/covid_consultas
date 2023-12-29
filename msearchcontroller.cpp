#include "msearchcontroller.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

MSearchController::MSearchController(){}

string MSearchController::buscarEnArchivoCSV(const string& nombreArchivo, const string& valorBuscado1, const string& valorBuscado2, size_t columnaBuscada1, size_t columnaBuscada2) {
    // Intenta abrir el archivo
    ifstream archivo(nombreArchivo);

    // Verifica si se pudo abrir correctamente
    if (!archivo.is_open()) {
        return "Error al abrir el archivo CSV.";
    }

    // Vector para almacenar los datos leídos del CSV
    vector<vector<string>> datos;

    // Lee el archivo línea por línea
    string linea;
    while (getline(archivo, linea)) {
        istringstream ss(linea);
        vector<string> fila;

        // Lee cada campo separado por comas en la línea
        while (getline(ss, linea, ';')) {
            fila.push_back(linea);
        }

        // Agrega la fila al vector de datos
        datos.push_back(fila);
    }

    // Cierra el archivo después de leer
    archivo.close();

    // Almacena los resultados de la búsqueda
    string resultados;

    // Realiza la búsqueda en el vector de datos
    for (const auto& fila : datos) {
        if (columnaBuscada1 - 1 < fila.size() && columnaBuscada2 - 1 < fila.size() &&
            fila[columnaBuscada1 - 1] == valorBuscado1 && fila[columnaBuscada2 - 1] == valorBuscado2) {
            // Se encontró un registro que cumple con el criterio de búsqueda
            for (const auto& campo : fila) {
                resultados += campo + " ";
            }
            resultados += "\n";
        }
    }

    return resultados;
}
