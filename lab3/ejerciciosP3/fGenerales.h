#ifndef FGENERALES_H
#define FGENERALES_H

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

//                  FUNCIONES

void desencriptar(string**& arreglo, int* size, int* semilla);
void encriptar(string**& arreglo, int* size, int* semilla);

void expandirArreglo(string**& arr, int& size);
void menuGeneral(const string& fileName);
int opcionesMenuGeneral(const string& mensaje1, const string& mensaje2, const string opcionesValidas[], int size);

bool menuSalida();
void agregarUsuario(string**& arreglo, int* size);
int iniciarSesion(string** arreglo, int size, string* docUsuario);
bool validarContrasena(string** arreglo, int size, string documento, string contrasena, int* rol);
bool validarDocumento(string** arreglo, int size, string documento);
int menuUsuario();
void retirarDinero(string** arreglo, int size, string documento);
void consultarSaldo(string** arreglo, int size, string documento, bool descontar = false);
void mensajeSalida();

void limpiarPantalla();
int pedirNumEntero();
bool validarNumeros(string cadena);
void formatoDocumento(string* documento);
string quitarEspacios(string cadena);
void validarSaldo(string *saldo);
string validarRol(int rol);

//                  FUNCIONES DEL PROFESOR

void escribirArchivo(string nombreArchivo, string texto, bool limpiar);
string leerArchivoPorLinea(string nombreArchivo);
string leerArchivoPorCaracter(string nombreArchivo);
string char2binario(string nombreArchivo);

#endif // FGENERALES_H
