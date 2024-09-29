#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "fGenerales.h"

using namespace std;

int main(){
    // Crear estructura de datos para el programa.
    int semilla = 0;
    int* ptrSemilla = &semilla;
    int size = 1;
    int* ptrSize = &size;
    string** estructura = new string*[size];
    for (int i = 0; i < size; ++i) {
        estructura[i] = new string[4];
    }
    //aaaaaaaaaaa
    desencriptar(estructura, ptrSize, ptrSemilla);


    for (int i = 0; i < size; ++i) {
        if (!(estructura[i][0]=="")){
            for (int j = 0; j < 4; ++j) {
                cout<<estructura[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    encriptar(estructura, ptrSize, ptrSemilla);

    /*
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
    encriptar(estructura, ptrSize, ptrSemilla);

    //Mensaje de salida exitosa
    mensajeSalida();
    */

    //              DELETES
    for (int i = 0; i < size; ++i) {
        delete[] estructura[i];
    }
    delete[] estructura;

    return 0;
}


