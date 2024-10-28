#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>
#include <map>

using namespace std;

class Enrutador
{
private:
    //Atributos
    string nombre;
    map<string, map<string, int>> rutas;

public:
    //Constructor
    Enrutador(const string& nombre);
    //Getter
    string getNombre()const;
    const map<string, map<string, int>>& getRutas() const;
    //Setter
    void setNombre(string nuevoNombre);
    //Metodos
    void agregarVecino(const string& origen, const string& destino, int costo);
    void eliminarVecino(string& destino);
    void mostrarTabla();
    int obtenerCosto(const string& origen, const string& destino)const;
};

#endif // ENRUTADOR_H
