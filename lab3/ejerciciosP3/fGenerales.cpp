#include <iostream>
#include <fGenerales.h>
#include <fstream>
#include <string>
#include <bitset>
#include <random>
#include <cstdlib> // Para srand() y rand()
#include <cctype> //para el toupper

using namespace std;


void desencriptar(){}
void encriptar(){}

void leerArchivo(string**& arreglo, int* size){
    //lee un archivo con formato preestablecido y lo guarda como string en un arreglo dinamico.
    string nombreArchivo = "hola.txt";
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }
    int indice = 0;
    string contenido;
    string linea;
    while (getline(archivo, linea)){
        if (indice >= *size){
            expandirArreglo(arreglo, *size); // aumenta la memoria cuando se exceden las 10 lineas.
            contenido = linea + "\n";
            arreglo[indice][0] = contenido;
            indice++;
        }
        else {
            contenido = linea + "\n";
            arreglo[indice][0] = contenido;
            indice++;
        }
    }
    archivo.close();
    return;
}


// Función que expande un arreglo dinámico
void expandirArreglo(string**& arr, int& size) {
    // Paso 1: Crear un nuevo arreglo con una posición más
    string** nuevoArr = new string*[size + 1];
    for (int i = 0; i < size+1; ++i) {
        nuevoArr[i] = new string[4];
    }

    // Paso 2: Copiar elementos al nuevo arreglo
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < 4; ++j) {
            nuevoArr[i][j] = arr[i][j];
        }
    }

    // Paso 3: Liberar la memoria del arreglo original
    for (int i = 0; i < size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    // Paso 4: Actualizar el puntero para que apunte al nuevo arreglo
    arr = nuevoArr;

    // Paso 5: Aumentar el tamaño
    size += 1;
}

// Función que abre un archivo, lo imprime y lo cierra
void menuGeneral(const string& fileName) {
    // Crear un objeto ifstream para leer el archivo
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

int iniciarSesion(){
    //inicia sesion como usuario o administrador.
    limpiarPantalla();
    string nombre = "prints/MenuPrincipal.txt";
    menuGeneral(nombre);
    string documento;
    cout<<"Documento: ";
    getline(cin, documento);
    //validar formato contraseña
    //validar que sea la registrada con el archivo sudo, si si, iniciar sesion

    //return 0 para cuando quiera salir.
    return 2;
}

int menuUsuario(){
    //imprimer el menu de usuario y retorna un int relacionado a la actividiad para realizar
    limpiarPantalla();
    string nombre = "prints/MenuUsuario.txt";
    menuGeneral(nombre);
    string mensaje1 = "Elige una opcion (1, 2, 0): ";
    string mensaje2 = "Opción no valida, intenta de nuevo.";

    // Opciones válidas en un arreglo
    const int size = 3;
    string opcionesValidas[size] = {"1", "2", "0"};
    int opcionElegida = opcionesMenuGeneral(mensaje1, mensaje2, opcionesValidas, size);
    return opcionElegida;
}

void mensajeSalida(){
    //Imprime el mensaje cuando sale del programa.
    string nombre = "prints/MensajeSalida.txt";
    menuGeneral(nombre);
}

void limpiarPantalla(){
    // Imprime varias líneas en blanco para dar la ilusión de limpiar la pantalla
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}

int pedirNumEntero(){
    int numero;
    while (!(std::cin >> numero)) {
        // Si la entrada no es un número, std::cin entra en un estado de error
        std::cin.clear(); // Limpia el estado de error de std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada inválida
        std::cout << "Entrada no valida. Por favor, ingresa un numero entero: ";
    }
    return numero;
}






















//                          FUNCIONES DEL PROFESOR



void escribirArchivo(string nombreArchivo, string texto, bool limpiar = false){
    fstream archivo;
    if (limpiar){ // Si limpiar es verdadero, se sobreescribe el archivo
        archivo.open(nombreArchivo, ios::out | ios::trunc); // trunc para borrar y escribir
    }
    else{ // Si limpiar es falso, se agrega contenido al final del archivo
        archivo.open(nombreArchivo, ios::out | ios::app); // app para agregar en la ultima linea
    }

    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return;
    }

    archivo << texto << endl;
    archivo.close();
}

string leerArchivoPorLinea(string nombreArchivo){
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    string linea;
    while (getline(archivo, linea)){
        contenido += linea + "\n";
    }
    archivo.close();

    return contenido;
}

string leerArchivoPorCaracter(string nombreArchivo){
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()){
        cout << "Error al abrir el archivo\n";
        return "";
    }

    string contenido;
    char c;
    while (archivo.get(c)){
        contenido += c;
    }
    cout<<contenido;
    archivo.close();

    return contenido;
}

string char2binario(string nombreArchivo){
    //convierte el texto de un archivo en binario.
    ifstream archivo;
    try{
        archivo.open(nombreArchivo);
        if (!archivo.is_open())
        {
            cout << "Error al abrir el archivo\n";
            return "";
        }
    }
    catch (const std::exception &e){
        cerr << e.what() << '\n';
    }

    char caracter;
    string str_binario;

    while (archivo.get(caracter)){
        bitset<8> binario(caracter);
        str_binario += binario.to_string();
    }
    archivo.close();

    return str_binario;
}














//              PARA ENCRIPTAR Y DESENCRIPTAR
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
