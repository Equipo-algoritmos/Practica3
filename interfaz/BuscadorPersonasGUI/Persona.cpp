#include "Persona.h"

Persona::Persona(std::string c, std::string n, int e)
{
    clave = c;
    nombre = n;
    edad = e;
}

int Persona::getEdad()
{
    return edad;
}

std::string Persona::getNombre()
{
    return nombre;
}

std::string Persona::getClave()
{
    return clave;
}