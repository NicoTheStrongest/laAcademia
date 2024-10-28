#include <iostream>

#include <Red.h>
#include <Enrutador.h>

using namespace std;

int menuRed(){
    int opcion;
    cout << "\n***** GESTION DE RED *****\n" << endl;
    cout << "1. Agregar enrutador\n";
    cout << "2. Remover enrutador\n";
    cout << "3. Agregar enlace entre enrutadores\n";
    cout << "4. Mostrar tabla de enrutamiento\n";
    cout << "5. Calcular costo de envio\n";
    cout << "6. Calcular ruta mas corta\n";
    cout << "7. Simulacion\n";
    cout << "0. Salir\n";
    cout << "Selecciona una opcion: ";
    cin >> opcion;
    return opcion;
}

void limpiarPantalla(){
    // Imprime varias líneas en blanco para dar la ilusión de limpiar la pantalla
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}


int main()
{
    Red red;
    //Enrutador enrutador;
    red.cargarDatos();
    bool sesionActiva = true;
    while(sesionActiva == true){
        limpiarPantalla();
        int opcion = menuRed();
        limpiarPantalla();
        switch (opcion) {
        case 1:
            //Agregar enrutador
            {
            red.agregarEnrutador();
            }
            break;
        case 2:
            //Eliminar enrutador
            {
            red.removerEnrutador();
            }
            break;
        case 3:
            //Agregar enlace
            {
            red.actualizarEnlaces();
            }
            break;
        case 4:
            //Tabla de enrutamiento
            {
            red.mostrarRed();
            }
            break;
        case 5:
            //Costo de envio
            {
            red.calcularCosto();
            }
            break;
        case 6:
            //Mejor ruta
            {
            red.calcularRuta();
            }
            break;
        case 7:
            //Red aleatoria para pruebas
            {
            red.generarRedAleatoria();
            }
            break;
        case 0:
            //Salir del programa
            {
            sesionActiva = false;
            }
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    }
    return 0;
}
