#ifndef MSEARCHCONTROLLER_H
#define MSEARCHCONTROLLER_H
#include <string>

using namespace std;

class MSearchController
{
public:
    MSearchController();
    static string buscarEnArchivoCSV(const std::string& nombreArchivo, const std::string& valorBuscado1, const std::string& valorBuscado2, size_t columnaBuscada1, size_t columnaBuscada2);
};

#endif // MSEARCHCONTROLLER_H
