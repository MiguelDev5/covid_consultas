#include "nodo.h"

Nodo::Nodo(string fecha_corte, string uuid, string fecha_muestra, string edad,
         string sexo, string institucion, string ubigeo_paciente,
         string departamento_paciente, string provincia_paciente,
         string distrito_paciente, string departamento_muestra,
         string provincia_muestra, string distrito_muestra, string tipo_muestra,
         string resultado)
        : fecha_corte(fecha_corte), uuid(uuid), fecha_muestra(fecha_muestra),
        edad(edad), sexo(sexo), institucion(institucion),
        ubigeo_paciente(ubigeo_paciente),
        departamento_paciente(departamento_paciente),
        provincia_paciente(provincia_paciente),
        distrito_paciente(distrito_paciente),
        departamento_muestra(departamento_muestra),
        provincia_muestra(provincia_muestra),
        distrito_muestra(distrito_muestra), tipo_muestra(tipo_muestra),
        resultado(resultado), siguiente(nullptr) {}
