#include <iostream>
#include <random>
#include <cstdlib> // Para srand() y rand()
#include <string>
#include <cctype> //para el toupper

using namespace std;

//            PROTOTIPADO DE FUNCIONES

int problema2();
int problema4();
int problema6();
int problema8();
int problema10();
int problema12();
int problema14();
int problema16();
int problema18();

void mostrarMatrizDinamica(int** matriz, int n);
int pedirNumEntero();
int validarPar(int numero);
int validarImpar(int numero);
string quitarEspacios(string cadena);
string convertirMayus(string cadena);
int definirRomano(char romano);
void mostrarCubo(bool cubo, int* matriz, int tamanio);
void pedirNumerosP12(int* matriz, int tamanio);
bool verificarCubo(int* matriz, int tamanio);
int rotar90(int** matriz, int n);
int rotar180(int** matriz, int n);
int rotar270(int** matriz, int n);
int pedirNumerosP14(int** matriz, int n);
int combinatoriaP16(int n);
int factorial(int n);
void permutacionesP18(int* arreglo, int* numeros, int n, const int size);
void moverBasura(int* arreglo, int tamanio, int posicion);
bool validarNumeros(std::string cadena);


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
    case 12:
        problema12();
        break;
    case 14:
        problema14();
        break;
    case 16:
        problema16();
        break;
    case 18:
        problema18();
        break;
    default:
        cout<<"Ejercicio no encontrado.";
        break;
    }
    return 0;
}

int problema2(){
    /*
    Genera 200 letras mayusculas aleatorias y cuenta cuantas veces aparecen cada una de las letras del
    abecedario.
    */
    int num_aleatorio;
    int n = 10;
    char* arreglo = new char[n]; //Arreglo dinamico de n posiciones.
    int* arregloCont = new int [25](); //Arreglo dinamico de 25 posiciones para cada letra.
    char letra = 64; //char de inicio de las letras mayusculas.
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        num_aleatorio = rand() % 25 + 2; // numero aleatorio entre 0 y 25
        letra = letra + num_aleatorio; //encuentra la mayuscula partiendo del car de inicio (A).
        arreglo[i] = letra; //añade al arreglo de n posiciones.
        cout<<letra; //imprime de una vez para mas eficiencia.
        arregloCont [num_aleatorio-1] +=1; // suma 1 al contador correspondiente a la letra en arregloCont
        letra = 64; // reinicia char (A).
    }
    cout<<"\n";
    //para la imprimir las veces que aparece cada letra.
    for (int i = 0; i <= 25; ++i) {
        letra+=1;
        cout<<letra<<": "<<arregloCont[i]<<endl;
    }
    //liberaciones.
    delete [] arreglo;
    delete [] arregloCont;
    return 0;
}

int problema4(){
    /*
    Recibe un cadena de caracteres numericos, verifica que cada posición sea un numero y en caso
    verdadero retorna el entero.
    */
    string cadena;
    int cadenaInt;
    cout<<"\nDame una cadena de caracteres: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //limpiar buffer del cin.
    getline(std::cin, cadena);
    cadena = quitarEspacios(cadena);
    bool numeros = validarNumeros(cadena);
    if (numeros){cadenaInt = stoi(cadena); cout<<"\nValor de la cadena en entero es: "<<cadenaInt<<"\n";}
    else{cout<<"\nNo se puede convertir a entero\n";}
    cout<<endl;
    cout<<endl;
    return 0;
}

int problema6(){
    /*
    Recibe una cadena de caracteres y cambia las letras minusculas a mayusculas, el resto lo deja
    igual.
    */
    string cadena;
    cout<<"deme una cadena de caracteres: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //limpiar buffer del cin.
    getline(cin, cadena);
    cout<<endl;
    cout<<"Original: "<< cadena<<". En mayuscula: ";
    for (int i = 0; i < (int)cadena.size(); ++i) {
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
    cout<<endl;
    return 0;
}

int problema8(){
    /*
    Separa, de una cadena de caracteres, los numero de las letras y de los simbolos.
    */
    string cadena, cadenaNum="", cadenaStr="", cadenaSimbol="";
    int tamanio;
    cout<<"dame una cadena de caracteres: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, cadena);
    cout<<endl;
    cout<<endl;
    tamanio = cadena.size();
    for (int i = 0; i < tamanio; ++i) {
        if (cadena[i]>=48 && cadena[i]<=57){
            cadenaNum+=cadena[i];
        }
        else {
            if ((cadena[i]>=65  && cadena[i]<=90)  || (cadena[i]>=97  && cadena[i]<=122)){cadenaStr+=cadena[i];}
            else{cadenaSimbol+=cadena[i];}
        }
    }
    cout<<"Original: "<<cadena<<endl;
    cout<<"letras: "<<cadenaStr<<"\t Numeros: "<<cadenaNum<<"\t Simbolos: "<<cadenaSimbol<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}

int problema10(){
    /*
    Conversion de arabigo a romano.
    */
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
    cout<<"El numero ingresado fue: "<<romano<<endl;
    cout<<"Que corresponde a: "<<arabigo;

    cout<<endl;
    cout<<endl;
    return 0;
}

int problema12(){
    int n;
    cout<<"dame un entero para la matriz cuadrada: ";
    n = pedirNumEntero();
    n = validarImpar(n);
    if (n>0){
        int matriz[n][n];
        pedirNumerosP12(&matriz[0][0], n*n);
        bool cubo = verificarCubo(&matriz[0][0], n);
        mostrarCubo(cubo, &matriz[0][0], n);
    }
    else {cout<<"Numero invalido";}
    return 0;
}

int problema14(){
    // rotacion de matriz (90, 180 y 270).
    int** matriz = new int*[5];
    for (int i = 0; i < 5; ++i) {
        matriz[i] = new int [5];
    }
    pedirNumerosP14(matriz, 5);
    mostrarMatrizDinamica(matriz, 5);
    rotar90(matriz, 5);
    rotar180(matriz, 5);
    rotar270(matriz, 5);
    return 0;
}

int problema16(){
    //combinatoria en mallas n*n
    int n;
    cout<<"Dame el numero n para la malla (nxn): ";
    n = pedirNumEntero();
    while (n<0){
        cout<<"Tiene que ser positivo\n";
        cout<<"Dame un numero entero positivo: ";
    }
    int posiblesCaminos = combinatoriaP16(n);
    cout<<"Para una malla de "<<n<<"x"<<n<<" puntos hay "<<posiblesCaminos<<" caminos\n\n";
    return 0;
}

int problema18(){
    //permutaciones lexicograficas de los numeros del cero al 9
    int size = 10;
    int* arreglo = new int[size];
    int* numeros = new int[size] {0,1,2,3,4,5,6,7,8,9};
    int n;
    cout<<"Dame un numero n para hallar sus permutaciones lexicograficas: ";
    n = pedirNumEntero();
    while (n<0){
        cout<<"Tiene que ser positivo\n";
        cout<<"Dame un numero entero positivo: ";
    }
    permutacionesP18(arreglo, numeros, n, size);
    delete[] arreglo;
    delete[] numeros;
    return 0;
}




//                            FUNCIONES FUNCIONALES

void mostrarMatrizDinamica(int** matriz, int n){
    cout<<"\n\nMatriz:\n";
    for (int i = 0; i < n; ++i) {
        cout<<"\n";
        for (int j = 0; j < n; ++j) {
            cout<<matriz[i][j]<<"\t";
        }
    }
    cout<<"\n";
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

int validarImpar(int numero){
    while (numero%2==0) {
        cout<<"tiene que ser un numero impar"<<endl;
        cout<<"ingrese un numero impar";
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

void mostrarCubo(bool cubo, int* matriz, int n){
    cout<<"\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){cout<<matriz[i*n+j]<<" ";}
        cout<<"\n";
    }
    if (cubo){cout<<"\n es un cubo magico\n";}
    else {cout<<"\n no es un cubo magico\n";}
}

void pedirNumerosP12(int* matriz, int tamanio){
    int entrada;
    cout<<"dame el numero de la matriz fila por fila\n";
    for (int i = 0; i < tamanio; i++){
        cout<<"numero: ";
        entrada = pedirNumEntero();
        matriz[i] = entrada;
    }
}

bool verificarCubo(int* matriz, int n){
    int suma = 0;
    // suma inicial para conocer cuanto deben sumar las demas filas y diagonales.
    for (int j = 0; j < n; ++j) {
        suma += matriz[j];
    }
    int acumDiagonal1 = 0, acumDiagonal2 = 0, sumaFila = 0, sumaColumna = 0;
    for (unsigned short int i = 0; i < n ; i++){
        acumDiagonal1 += matriz[i*(n+1)];
        acumDiagonal2 += matriz[(i+1)*(n-1)];
        for (int j = 0; j < n; j++){
            sumaFila += matriz[i*n+j];
            sumaColumna += matriz[j*n+i];
        }
        if (sumaFila != suma || sumaColumna != suma){return false;}
        else {sumaFila = 0; sumaColumna = 0;}

    }
    if (acumDiagonal1 == suma && acumDiagonal2 == suma){return true;}
    else {return false;}
}

int rotar90(int** matriz, int n){
    //rota una matriz 5 x 5 90 grados.
    cout<<"\ngiro de 90 grados:\n";
    for (int i = n-1; i >= 0; i--){
        cout<<"\n";
        for (int j = 0; j < n; ++j) {
            cout<<matriz[j][i]<<"\t";
        }
    }
    cout<<"\n";
    return 0;
}

int rotar180(int** matriz, int n){
    //rota una matriz 5 x 5 180 grados.
    cout<<"\ngiro de 180 grados:\n";
    for (int i = n-1; i >= 0; i--){
        cout<<"\n";
        for (int j = n-1; j >= 0; --j) {
            cout<<matriz[i][j]<<"\t";
        }
    }
    cout<<"\n";
    return 0;
}

int rotar270(int** matriz, int n){
    //rota una matriz 5 x 5 270 grados.
    cout<<"\ngiro de 270 grados:\n";
    for (int i = 0; i < n; i++){
        cout<<"\n";
        for (int j = n-1; j >= 0; --j) {
            cout<<matriz[j][i]<<"\t";
        }
    }
    cout<<"\n\n";
    return 0;
}

int pedirNumerosP14(int** matriz, int n){
    //pide numero para llenar la matriz 5*5
    int entrada;
    cout<<"dame los numeros enteros de la matriz\n";
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; ++j) {
            cout<<"numero: ";
            entrada = pedirNumEntero();
            matriz[i][j] = entrada;
        }
    }
    return 0;
}

int combinatoriaP16(int n){
    int resultado = 0, numerador = factorial(n+n), denominador1 = factorial(n), denominador2 = factorial(2*n-n);
    resultado = numerador/(denominador1*denominador2);
    return resultado;
}

int factorial(int n){
    int resultado = 1;
    for (int i = 1; i <= n; ++i) {resultado *= i;}
    return resultado;
}

void permutacionesP18(int* arreglo, int* numeros, int n, const int size){
    long int limite = factorial(size);
    if (n > 0 && n < limite){
        int bloque, termino;
        long int enesimo = n-1;
        for (int i = 9, j = 0; i >= 0; --i) {
            bloque = factorial(i);
            termino = enesimo/bloque;
            arreglo[j] = numeros[termino]; j++;
            moverBasura(numeros, size, numeros[termino]);
            if (termino > 0){enesimo = enesimo%bloque;}
        }
        cout<<"La permutacion numero "<<n<<" es: ";
        //mostrar permutacion.
        for (int i = 0; i < size; ++i) {
            cout<<arreglo[i];
        }
        cout<<"\n";
    }
    else{cout<<"numero fuera de rango";}
}

void moverBasura(int* arreglo, int tamanio, int posicion){
    for (int i = 0, j = 0; i < tamanio; ++i) {
        if (arreglo[i] != posicion){arreglo[j] = arreglo[i]; j++;}
    }
}

bool validarNumeros(std::string cadena){
    //valida que una cadena solo contenga numeros
    for (int i = 0; i < (int)cadena.size(); ++i) {
        if (!(cadena[i]>=48  && cadena[i]<=57)){return false;}
    }
    return true;
}

