#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class datos
{
private:
    vector<string> claves;
    vector<int> indices;
    void construirindices();
public:
    void cargarDatos(string archivo);
    int consultarCantidad();
    int buscar(string buscado);
};

int datos::buscar(string buscado){
    if (buscado.empty()||claves.empty())
    {
        return -1;
    }
    if ((buscado[0]<'A')||(buscado[0]>'Z'))
    {
        return -1;
    }
    int m =buscado[0]-'A';
    int bajo=indices[m];
    int alto=indices[m+1]-1;
    while (bajo<=alto) {
        int medio=((alto-bajo)/2)+bajo;
        if (claves[medio]==buscado)         //comparacion con medio
        {
            return medio;
        }
        else if (claves[medio]<buscado)     //descarte de la parte izquierda
        {
            bajo=medio+1;
        }
        else /*if (claves[medio]>buscado)*/     //descarte de la parte derecha
        {
            alto=medio-1;
        }
    }
    return -1;
}

void datos::construirindices(){
    indices.resize(27, -1);
    indices[0]=0;
    for (size_t i = 0; i < claves.size(); ++i)
    {
        int letra = claves[i][0] - 'A';

        if (indices[letra] == -1)
        {
            indices[letra] = i;
        }
    }
    indices[26]=claves.size();
    for (int letra = 25; letra >= 0; --letra)
    {
        if (indices[letra] == -1)
        {
            indices[letra] = indices[letra + 1];
        }
    }
}


void datos::cargarDatos(string archivo)
{
    ifstream entrada(archivo);
    if (!entrada.is_open())
    {
        cout<<"No se pudo abrir el archivo.\n";
        return;
    }
    claves.clear();
    std::string linea;
    while (getline(entrada,linea)) {
        claves.push_back(linea);
    }
    construirindices();
}

int datos::consultarCantidad(){
    return claves.size();
}

int main()
{
    datos arr;
    arr.cargarDatos("data.txt");
    cout<<"Numero de claves encontradas: "<<arr.consultarCantidad();
    string buscado;
    while (true) { 
        cout<<"\nIngresa la clave a buscar, ingresa \"-1\" para salir: ";
        cin >> buscado;
        if (buscado=="-1")
        {
            break;
        }
        int posEncontrada = arr.buscar(buscado);
        if (posEncontrada==-1)
        {
            cout<<"\nLa clave buscada no se encontro.";
        }
        else{
            cout<<"\nLa clave buscada esta en la posicion: " << posEncontrada;
        }
    }
	return 0;
}