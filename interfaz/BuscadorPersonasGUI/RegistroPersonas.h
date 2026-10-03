#pragma once

#include "Persona.h"
#include <string>
#include <vector>

class RegistroPersonas
{
private:
    std::vector<Persona> personas;
    std::vector<int> indices;

    void construirindices();
    void cargarDatos(std::string archivo);

public:
    RegistroPersonas(std::string archivo);

    int getSize();
    Persona getPersona(int i);
    int buscar(std::string buscado);
};