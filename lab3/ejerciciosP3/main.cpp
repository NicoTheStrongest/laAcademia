#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "fGenerales.h"

using namespace std;

int main(){
    // Crear estructura de datos para el programa.
    int size = 3;
    int* ptrSize = &size;
    string** estructura = new string*[size];
    for (int i = 0; i < size; ++i) {
        estructura[i] = new string[4];
    }

    // Leer el archivo (falta desencriptar)
    desencriptar();
    leerArchivo(estructura, ptrSize);

    // Trabajo bajo la estructura de datos.
    bool volver = true;
    while (volver){
        int numUsuario = iniciarSesion();
        if (numUsuario == 1){//administrador
            limpiarPantalla();
            //agregar usuario (documento, clave, saldo, rol)
            //preguntar si quiere salir
            volver = false;
        }
        else if (numUsuario == 2){//usuario
            int opcionUsuario = menuUsuario();
            if (opcionUsuario == 1){//consultar saldo
            }
            else if(opcionUsuario == 2){//retirar dinero
            }
            else if(opcionUsuario == 0){//salir
                limpiarPantalla();
                volver = false;
            }
        }
        else if (numUsuario == 0){//salir el sistema
            volver = false;
        }
    }


    // Escribir en el archivo base todos los datos que se agregaron y modificaron
    encriptar();

    //Mensaje de salida exitosa
    mensajeSalida();

    /*
    for (int i = 0; i < size; ++i) {
        if (!(estructura[i][0]=="")){cout<<estructura[i][0];}
    }
    */

    //              DELETES
    for (int i = 0; i < size; ++i) {
        delete[] estructura[i];
    }
    delete[] estructura;

    //              CLASE DE LAB
    /*
    string binario, archivo = "hola.txt";
    //std::string texto = "01000001011000100100001101100100";
    //                     01000001011000100100001101100100
    std::string texto = "AbCd";
    escribirArchivo(archivo, texto, true);
    binario = char2binario(archivo);
    cout<<"texto en binario: "<<binario;
    */

    //              CONVERTIR STRING EN BINARIO PARA UTILIZAR BITWISE
    /*
    std::string binStr = "11001100";  // cadena binaria de 8 bits
    int num = std::stoi(binStr, 0, 2); // convierte la cadena a entero base 2
    std::bitset<8> binResult(~num);  // Para mostrar los 8 bits del resultado
    cout<<binResult;
    */
    //                  PARA DIVIDIR EN N BLOQUES
    /*
    int n, indice = 0, posiciones;
    string binario = "01000001011000100100001101100100", bloque;
    cout<<"ingrese la semilla: ";
    cin>>n;
    if(((int)size(binario))%n == 0){posiciones = ((int)size(binario))/n;}
    else {posiciones = (((int)size(binario))/n)+1;}
    std::string* arreglo = new std::string[posiciones];
    for (int i = 0; i < (int)size(binario); i+=n) {
        bloque = "";
        for (int j = i; j < n+i; ++j) {
            bloque += binario[j];
        }
        arreglo[indice] = bloque;
        indice++;
    }

    delete [] arreglo;
    */
    return 0;
}


