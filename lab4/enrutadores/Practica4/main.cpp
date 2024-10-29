#include <iostream>

#include <Red.h>
#include <Enrutador.h>

using namespace std;

int menuArchivo();
int menuRed();
void limpiarPantalla();
void menuGeneral(const string& fileName);
int opcionesMenuGeneral(const string& mensaje1, const string& mensaje2, const string opcionesValidas[], int size);

int main()
{
    Red red;
    bool sesionActiva = true;
    while(sesionActiva == true){

        int opcionCargar = menuArchivo();
        if(opcionCargar == 1){red.cargarDatos(); red.setCargaDatos(opcionCargar);}
        else if(opcionCargar == 2){red.cargarDatosSimulacion(); red.setCargaDatos(opcionCargar);}
        else if(opcionCargar == 0){break;}

        bool sesionActiva2 = true;
        while(sesionActiva2 == true){
            int opcion = menuRed();
            switch (opcion) {
            case 1:
                //AGREGAR ENRUTADOR.
                {
                    limpiarPantalla();
                    red.agregarEnrutador();
                }
                break;
            case 2:
                //ELIMINAR ENRUTADOR.
                {
                    limpiarPantalla();
                    red.removerEnrutador();
                }
                break;
            case 3:
                //AGREGAR ENLACE.
                {
                    limpiarPantalla();
                    red.agregarEnlaces();
                }
                break;
            case 4:
                //ELIMINAR ENLACE.
                {
                    limpiarPantalla();
                    red.eliminarEnlacesRed();
                }
                break;
            case 5:
                //MOSTRAR TABLA.
                {
                    limpiarPantalla();
                    red.mostrarRed();
                }
                break;
            case 6:
                //COSTO DE ENVIO.
                {
                    limpiarPantalla();
                    red.calcularCosto();
                }
                break;
            case 7:
                //MEJOR RUTA.
                {
                    limpiarPantalla();
                    red.calcularRuta();
                }
                break;
            case 8:
                //SIMULACION.
                {
                    red.generarRedAleatoria();
                }
                break;
            case 0:
                //Salir del programa
                {
                    sesionActiva = false;
                    sesionActiva2 = false;
                }
                break;
            default:
                cout << "Opcion no valida." << endl;
                break;
            }
        }
    }
    return 0;
}

int menuArchivo(){
    //para saber cual archivo quiere leer;
    limpiarPantalla();
    string nombre = "./../../prints/MenuArchivo.txt";
    menuGeneral(nombre);
    string mensaje1 = "Elige una opcion: ";
    string mensaje2 = "Opcion no valida, intenta de nuevo.";
    const int size = 3;
    string opcionesValidas[size] = {"1", "2", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

void menuGeneral(const string& fileName) {
    // Función que abre un archivo, lo imprime y lo cierra
    ifstream archivo(fileName);

    // Comprobar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << fileName << endl;
        return;
    }

    // Leer el archivo línea por línea y mostrar el contenido
    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    // Cerrar el archivo
    archivo.close();
}

int opcionesMenuGeneral(const string& mensaje1, const string& mensaje2, const string opcionesValidas[], int size) {
    string opcion;
    // Bucle infinito hasta que se reciba una opción válida
    while (true) {
        cout << mensaje1;
        cin >> opcion;
        // Verificar si la opción ingresada está en el arreglo de opciones válidas
        bool esValida = false;
        for (int i = 0; i < size; ++i) {
            if (opcionesValidas[i] == opcion) {
                esValida = true;
                break;
            }
        }
        // Si la opción es válida, convertirla a entero y retornarla
        if (esValida) {
            return stoi(opcion);  // Convertir la opción válida a entero y retornarla
        } else {
            cout << mensaje2 << endl;  // Mensaje de opción incorrecta
        }
    }
}

int menuRed(){
    limpiarPantalla();
    string nombre = "./../../prints/MenuPrincipal.txt";
    menuGeneral(nombre);
    string mensaje1 = "Elige una opcion: ";
    string mensaje2 = "Opcion no valida, intenta de nuevo.";
    const int size = 9;
    string opcionesValidas[size] = {"1", "2", "3", "4", "5", "6", "7", "8", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

void limpiarPantalla(){
    // Imprime varias líneas en blanco para dar la ilusión de limpiar la pantalla
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}
