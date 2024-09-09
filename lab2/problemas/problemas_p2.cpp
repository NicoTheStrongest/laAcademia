#include <iostream>
#include <random>
#include <cstdlib>
#include <string>
#include <cctype>
// #include <conio.h>
// #include <stdlib.h>

using namespace std;

int problema2();
int problema4();
int problema6();
int problema8();
int problema10();
int problema11();


int pedirNumEntero();
int validarPar(int numero);
string quitarEspacios(string cadena);
string convertirMayus(string cadena);
int definirRomano(char romano);

int main()
{
    int n;
    cout<<"Ingrese el # del problema que desea evaluar, tiene que ser par: ";
    n = pedirNumEntero();
    n = validarPar(n);
    switch (n) {
    case 2:
        problema2();
        break;
    case 4:
        problema4();
        break;
    case 6:
        problema6();
        break;
    case 8:
        problema8();
        break;
    case 10:
        problema10();
        break;
    case 11:
        problema11();
        break;
    default:
        break;
    }
    return 0;
}



int problema11(){


    return 0;
}

int problema10(){
    string romano;
    int tamanio, arabigo=0, t1, t2;
    cout<<"ingrese un numero en romano: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, romano);
    romano = convertirMayus(romano);
    tamanio = romano.size();
    for (int i = 0; i < tamanio; ++i) {
        t1 = definirRomano(romano[i]);
        t2 = definirRomano(romano[i+1]);
        if (t1 >= t2){
            arabigo += t1;
        }
        else {
            arabigo -= t1;
        }
    }
    cout<<arabigo;
    return 0;
}

int problema8(){
    string cadena, cadenaNum="", cadenaStr="";
    int tamanio;
    cout<<"dame una cadena de caracteres: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cadena);
    tamanio = cadena.size();
    for (int i = 0; i < tamanio; ++i) {
        if (cadena[i]>=48 && cadena[i]<=57){
            cadenaNum+=cadena[i];
        }
        else {
            cadenaStr+=cadena[i];
        }
    }
    cout<<"Original: "<<cadena<<endl;
    cout<<"letras: "<<cadenaStr<<" Numeros: "<<cadenaNum<<endl;
    return 0;
}


int problema6(){
    string cadena;
    int tamanio;
    cout<<"deme una cadena de caracteres: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cadena);
    tamanio = cadena.size();
    for (int i = 0; i < tamanio; ++i) {
        if (cadena[i]>='a' && cadena[i]<='z'){
            char caracter = toupper(cadena[i]);
            cout<<caracter;
        }
        else{
            char caracter = cadena[i];
            cout<<caracter;
        }
    }
    cout<<endl;
    return 0;
}


int problema4(){
    string cadena;
    int cadenaInt;
    cout<<"dame una cadena de caracteres: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //limpiar buffer del cin.
    getline(std::cin, cadena);
    cadena = quitarEspacios(cadena);
    cadenaInt = stoi(cadena);
    cout<<"valor de la cadena en entero es: "<<cadenaInt<<endl;
    return 0;
}

int problema2(){
    int num_aleatorio;
    int n = 10;
    char* arreglo = new char[n];
    //char arreglo [n];
    int* arregloCont = new int [25]();
    char letra = 64;
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        num_aleatorio = rand() % 25 + 2;
        letra = letra + num_aleatorio;
        arreglo[i] = letra;
        cout<<letra;
        arregloCont [num_aleatorio-1] +=1;
        letra = 64;
    }
    cout<<endl;
    for (int i = 0; i < 25; ++i) {
        letra+=1;
        cout<<letra<<": "<<arregloCont[i]<<endl;
    }
    delete [] arreglo;
    delete [] arregloCont;
    return 0;
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

int validarPar(int numero){
    while (numero%2!=0) {
        cout<<"tiene que ser un numero par"<<endl;
        cout<<"ingrese un numero par";
        numero = pedirNumEntero();
    }
    return numero;
}

string quitarEspacios(string cadena){
    string cadenaClear = "";
    int tamano;
    tamano = cadena.size();
    for (int i = 0; i < tamano; ++i) {
        if (cadena[i]==' '){
            cadenaClear = cadenaClear;
        }
        else {
            cadenaClear = cadenaClear + cadena[i];
        }
    }
    return cadenaClear;
}

string convertirMayus(string cadena){
    int tamanio;
    string cadenaMayus = "";
    tamanio = cadena.size();
    for (int i = 0; i < tamanio; ++i) {
        if (cadena[i]>='a' && cadena[i]<='z'){
            char caracter = toupper(cadena[i]);
            cadenaMayus += caracter;
        }
        else{
            char caracter = cadena[i];
            cadenaMayus += caracter;
        }
    }
    return cadenaMayus;
}


int definirRomano(char romano){
    const int M=1000, D=500, C=100, L=50, X=10, V=5, I=1;
    switch (romano) {
    case 'I': return I;
    case 'V': return V;
    case 'X': return X;
    case 'L': return L;
    case 'C': return C;
    case 'D': return D;
    case 'M':return M;
    default: return 0;
    }
}






