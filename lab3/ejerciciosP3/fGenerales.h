#ifndef FGENERALES_H
#define FGENERALES_H

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

//                  FUNCIONES

void desencriptar();
void encriptar();

void leerArchivo(string**& arreglo, int* size);
void expandirArreglo(string**& arr, int& size);
void menuGeneral(const string& fileName);
int opcionesMenuGeneral(const string& mensaje1, const string& mensaje2, const string opcionesValidas[], int size);

int iniciarSesion();
int menuUsuario();
void mensajeSalida();

void limpiarPantalla();
int pedirNumEntero();

//                  FUNCIONES DEL PROFESOR
void escribirArchivo(string nombreArchivo, string texto, bool limpiar);
string leerArchivoPorLinea(string nombreArchivo);
string leerArchivoPorCaracter(string nombreArchivo);
string char2binario(string nombreArchivo);

#endif // FGENERALES_H
