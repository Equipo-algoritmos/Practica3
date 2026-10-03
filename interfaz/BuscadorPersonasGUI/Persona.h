#pragma once

#include <string>

class Persona
{
private:
    std::string clave;
    std::string nombre;
    int edad;

public:
    Persona(std::string c, std::string n, int e);

    std::string getClave();
    std::string getNombre();
    int getEdad();
};