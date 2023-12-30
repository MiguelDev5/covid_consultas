    #ifndef EXTRACTDATA_H
    #define EXTRACTDATA_H

    #include "listaenlazada.h"

    class ExtractData
    {
    public:
        static ListaEnlazada *listaTotal;
        ExtractData();
        static void extraerRegistros(const std::string &rutaArchivo, char delimitador, ListaEnlazada *lista);

        // Getter para listaTotal
        static ListaEnlazada *getListaTotal();

        // Setter para listaTotal
        static void setListaTotal(ListaEnlazada *nuevaLista);
    };

    #endif // EXTRACTDATA_H
