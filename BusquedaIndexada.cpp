#include <cstddef>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class Persona
{
    private:
        string clave;
        string nombre;
        int edad;       
    public:
        Persona(string c, string n, int e);
        string getClave();
        string getNombre();
        int getEdad();
};

class RegistroPersonas
{
    private:
        std::vector<Persona> personas;
        std::vector<int> indices;
        void construirindices();
        void cargarDatos(string archivo);
    public:
        RegistroPersonas(string archivo);
        int getSize();
        Persona getPersona(int i);
        int buscar(string buscado);
};

int RegistroPersonas::buscar(string buscado){
    if (buscado.empty()||personas.empty())
        return -1;
    if ((buscado[0]<'A')||(buscado[0]>'Z'))
        return -1;
    int m =buscado[0]-'A';
    int bajo=indices[m];
    int alto=indices[m+1]-1;
    while (bajo<=alto) {
        int medio=((alto-bajo)/2)+bajo;
        string claveCentral=personas[medio].getClave();
        if (claveCentral==buscado)         //comparacion con medio
            return medio;
        else if (claveCentral<buscado)     //descarte de la parte izquierda
            bajo=medio+1;
        else /*if (claveCentral>buscado)*/     //descarte de la parte derecha
            alto=medio-1;
    }
    return -1;
}

void RegistroPersonas::construirindices(){
    indices.assign(27, -1);
    for (size_t i = 0; i < personas.size(); ++i)
    {
        string clave=personas[i].getClave();
        int letra = clave[0] - 'A';
        if (indices[letra] == -1)
            indices[letra] = i;
    }
    indices[26]=personas.size();
    for (int letra = 25; letra >= 0; --letra)
    {
        if (indices[letra] == -1)
            indices[letra] = indices[letra + 1];
    }
}

Persona RegistroPersonas::getPersona(int i){
    return personas.at(i);
}

RegistroPersonas::RegistroPersonas(string archivo){
    cargarDatos(archivo);
}

void RegistroPersonas::cargarDatos(string archivo){
    ifstream entrada(archivo);
    if (!entrada.is_open())
    {
        cout<<"No se pudo abrir el archivo.\n";
        return;
    }
    std::string linea;
    while (getline(entrada,linea)) {
        istringstream campos(linea);
        string clave, nombre, edadTexto;
        getline(campos,clave,';');
        getline(campos,nombre,';');
        getline(campos,edadTexto);
        int edad=stoi(edadTexto);
        Persona nueva(clave,nombre,edad);
        personas.push_back(nueva);
    }
    construirindices();
}

int RegistroPersonas::getSize(){
    return personas.size();
}

int Persona::getEdad(){
    return edad;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getClave(){
    return clave;
}

Persona::Persona(string c, string n, int e){
    clave=c;
    nombre=n;
    edad=e;
}

int main()
{
    RegistroPersonas registro("personas.txt");
    cout <<"Numero de claves encontradas: " << registro.getSize();
    string buscado;
    while (true) {
        cout<<"\nIngresa la clave a buscar, ingresa \"-1\" para salir: ";
        cin>> buscado;
        if (buscado=="-1")
            break;
        int posicion = registro.buscar(buscado);
        if (posicion!=-1)
        {
        Persona nueva = registro.getPersona(posicion);
        cout <<"\nEmpleado No.:" <<nueva.getClave() <<" Nombre: "<<nueva.getNombre()<<" Edad: "<<nueva.getEdad();
        }
        else
            cout<<"\nPersona no encontrada";
    }
    return 0;
}