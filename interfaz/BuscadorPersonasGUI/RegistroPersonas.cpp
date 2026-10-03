#include "Persona.h"
#include "RegistroPersonas.h"

#include <fstream>
#include <sstream>

int RegistroPersonas::buscar(std::string buscado)
{
    if (buscado.empty() || personas.empty())
        return -1;

    if ((buscado[0] < 'A') || (buscado[0] > 'Z'))
        return -1;

    int m = buscado[0] - 'A';
    int bajo = indices[m];
    int alto = indices[m + 1] - 1;

    while (bajo <= alto)
    {
        int medio = ((alto - bajo) / 2) + bajo;

        std::string claveCentral =
            personas[medio].getClave();

        if (claveCentral == buscado)
            return medio;

        else if (claveCentral < buscado)
            bajo = medio + 1;

        else
            alto = medio - 1;
    }

    return -1;
}

void RegistroPersonas::construirindices()
{
    indices.assign(27, -1);

    for (size_t i = 0; i < personas.size(); ++i)
    {
        std::string clave =
            personas[i].getClave();

        int letra = clave[0] - 'A';

        if (indices[letra] == -1)
            indices[letra] = i;
    }

    indices[26] = personas.size();

    for (int letra = 25; letra >= 0; --letra)
    {
        if (indices[letra] == -1)
            indices[letra] = indices[letra + 1];
    }
}

Persona RegistroPersonas::getPersona(int i)
{
    return personas.at(i);
}

RegistroPersonas::RegistroPersonas(std::string archivo)
{
    cargarDatos(archivo);
}

void RegistroPersonas::cargarDatos(std::string archivo)
{
    std::ifstream entrada(archivo);

    if (!entrada.is_open())
        return;

    std::string linea;

    while (std::getline(entrada, linea))
    {
        std::istringstream campos(linea);

        std::string clave;
        std::string nombre;
        std::string edadTexto;

        std::getline(campos, clave, ';');
        std::getline(campos, nombre, ';');
        std::getline(campos, edadTexto);

        int edad = std::stoi(edadTexto);

        Persona nueva(clave, nombre, edad);

        personas.push_back(nueva);
    }

    construirindices();
}

int RegistroPersonas::getSize()
{
    return static_cast<int>(personas.size());
}