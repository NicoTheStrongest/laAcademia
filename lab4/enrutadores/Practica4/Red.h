#ifndef RED_H
#define RED_H

#include "Enrutador.h"
#include <vector>
#include <map>
#include <time.h>
#include <limits>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Red
{
private:
    //Atributos
    vector<Enrutador> enrutadores;
    int cargaDatos;

public:
    //Constructor
    Red();
    //Getter
    vector<Enrutador> getEnrutadores() const;
    //setters
    void setCargaDatos(int opcion);
    //Metodos
    void cargarDatos();
    void cargarDatosSimulacion();
    void agregarEnrutador();
    void agregarEnlaceLectura(string nombre1, string nombre2, int costo);
    void agregarEnlaces();
    void eliminarEnlacesRed();
    void removerEnrutador();
    void actualizarRed();
    void mostrarRed();
    void calcularCosto();
    void calcularRuta();
    void generarRedAleatoria();
    int obtenerCosto(const string& enrutador1, const string& enrutador2);
    Enrutador& obtenerEnrutador(const string& enrutador);
};

#endif // RED_H
