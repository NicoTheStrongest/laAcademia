#include <iostream>
#include <vector>

#include "Enrutador.h"

//Constructor
Enrutador::Enrutador(const string& nombre) : nombre(nombre) {}

//Getter
string Enrutador:: getNombre() const {return nombre;}
const map<string, map<string, int>>& Enrutador::getRutas() const {return rutas;}

//Setter
void Enrutador::setNombre(string nuevoNombre){
    nombre = nuevoNombre;
}

//Metodo para agregar una relacion entre dos enrutadores
void Enrutador::agregarVecino(const string& origen, const string& destino, int costo){
    rutas[origen][destino] = costo;
}

//Metodo para eliminar una relacion entre dos enrutadores
void Enrutador::eliminarEnlaceEnrutador(const string& origen, const string& destino){
    //elimina el enlace origen-destino
    string filaClave, nom;
    for (auto it = rutas.begin(); it != rutas.end(); ++it) {
        filaClave = it->first; // Clave de la fila
        if(filaClave == origen){
            auto& mapaInterno = it->second; // Mapa interno
            for (auto it2 = mapaInterno.begin(); it2 != mapaInterno.end(); ++it2) {
                nom = it2->first; //clave de la columna
                if(nom == destino){
                    mapaInterno.erase(nom);
                }
            }
        }
        else if(filaClave == destino){
            auto& mapaInterno = it->second; // Mapa interno
            for (auto it2 = mapaInterno.begin(); it2 != mapaInterno.end(); ++it2) {
                nom = it2->first; //clave de la columna
                if(nom == origen){
                    mapaInterno.erase(nom);
                }
            }
        }
    }
}

//Metodo para eliminar relacion entre enrutadores
void Enrutador::eliminarVecino(string& destino){
    rutas.erase(destino);
    string filaClave, nom;
    for (auto it = rutas.begin(); it != rutas.end(); ++it) {
        filaClave = it->first; // Clave de la fila
        auto& mapaInterno = it->second; // Mapa interno
        for (auto it2 = mapaInterno.begin(); it2 != mapaInterno.end(); ++it2) {
            nom = it2->first; //clave de la columna
            if(nom == destino){
                mapaInterno.erase(nom);
            }
        }
    }
}

//Metodo para obtener el costo de llegar de un enrutador a otro
int Enrutador::obtenerCosto(const string& origen, const string& destino) const{
    auto itOrigen = rutas.find(origen);
    if(itOrigen != rutas.end()){
        auto itDestino = itOrigen->second.find(destino);
        if(itDestino != itOrigen->second.end()){
            return itDestino->second;
        }
    }
    return -1;
}

//Metodo para mostrar la tabla de enrutamiento de cada enrutador
void Enrutador::mostrarTabla(){
    for(const auto& origen : rutas){
        cout << "---------------------" << endl;
        cout << "Origen: " << origen.first << endl;
        for(const auto& destino : origen.second){
           cout << "Destino: "<< destino.first << ", Costo: " << destino.second << endl;
        }
    }
}

