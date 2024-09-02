#include <iostream>
#include <limits>
#include <cctype>
#include <string>

using namespace std;

int problema1();
int problema5();
int problema3();
int problema7();
int problema9();
int problema11();
int problema13();
int problema15();
int problema17();

int pedirNumReal();
int pedirNumEntero();
int validarImpar(int numero);
int mcd(int a, int b);
void imprimirMatriz(int* matriz, int n);
int sumaDiagonales(int* matriz, int n);

int main(){
    int n;
    cout<<"ingrese el # de ejercicio que desea evaluar: ";
    n = pedirNumEntero();
    switch (n)
    {
    case 1:
        problema1();
        break;
    case 3:
        problema3();
        break;
    case 5:
        problema5();
        break;
    case 7:
        problema7();
        break;
    case 9:
        problema9();
        break;
    case 11:
        problema11();
        break;
    case 13:
        problema13();
        break;
    case 15:
        problema15();
        break;
    case 17:
        problema17();
        break;
    default:
        break;
    }
    return 0;
}



//                    problemas




int problema17(){
    return 0;
}

int problema15(){
    // pide un impar y calcula la suma de los numeros en la diagonal e una
    // espiral de n*n.
    int n, valor = 1, medio, sumat;
    cout<<"dame un numero n entero impar para generar una matriz nxn: ";
    n = pedirNumEntero();
    n = validarImpar(n);
    int matrizA [n][n];
    int fila = (n/2);
    int columna = (n/2);
    matrizA [fila][columna] = valor++;
    int pasos = 1;
    while (valor<=n*n){
        for (int i = 0; i < pasos && valor <= n*n; i++)
        {
            columna++;
            matrizA[fila][columna]=valor++;
        }
        for (int i = 0; i < pasos && valor <= n*n; i++)
        {
            fila++;
            matrizA[fila][columna]=valor++;
        }
        pasos++;
        for (int i = 0; i < pasos && valor <= n*n; i++)
        {
            columna--;
            matrizA[fila][columna]=valor++;
        }
        for (int i = 0; i < pasos && valor <= n*n; i++)
        {
            fila--;
            matrizA[fila][columna]=valor++;
        }
        pasos++;
    }
    imprimirMatriz(&matrizA[0][0], n);
    int suma = sumaDiagonales(&matrizA[0][0], n);
    cout << "La suma de las diagonales es: " << suma << endl;
    return 0;
}

int problema13(){
    // Calcula la sumatoria de los numeros primos menores a un numero.
    int n;
    int acum=0;
    int nmenores=2;
    cout<<"Ingrese un numero mayor que 0"<<endl;
    cin>>n;
    while(n<=0){
        cout<<"Ingrese un numero mayor que 0"<<endl;
        cin>>n;
    }
    if (n>2){
        while(nmenores<n && n!=2){
            bool primo=true;
            int cont=2;
            while(nmenores>cont && primo){
                if (nmenores % cont == 0){
                    primo=false;
                }
                cont++;
            }
            if (primo){
                acum=acum+nmenores;
            }
            nmenores=nmenores+1;
        }
        cout<<"El resultao de la suma es: "<<acum;
    }
    else{
        cout<<"El resultao de la suma es: "<<acum;
    }
    return 0;
}

int problema11(){  
    // Calcula el mcm de los numeros menores a n.
    int n;
    cout<<"Escriba un # entero positivo y diferente de 0"<<endl;
    cin>>n;
    while(n<=0){
        cout<<"Escriba un # entero positivo"<<endl;
        cin>>n;
    }
    int multip=n;
    int mcm=n;
    while(multip>=1){
        if(mcm%multip==0){
            multip--;
        }
        else{
            mcm=mcm+n;
            multip=n;
        }
    } 
    cout<<"El minimimo comun multiplo es:"<<mcm;
    return 0;
}

int problema9(){ 
    //sumatoria de los digitos de un numero elevados a si mismos
    int n;
    int mod;
    int sumat=0;
    cout<<"ingrese un numero entero:"<<endl;
    cin>>n;
    if(n<0){
        n=n*(-1);
    }
    while(n>=1){
        int cont=1;
        int poten=1;
        mod=(n%10);
        n=(n-mod)/10;
        while(cont<=mod){
            poten=poten*mod;
            cont++;
        }
        sumat=sumat+poten;
    }
    cout<<"El resultado de la suma es: "<<sumat;
    return 0;
}

int problema7(){
    //calcular la sumatoria de los numeros pares menores que x y que ademas
    //pertenezcan a la serie de fibonacci.
    int x;
    int suma=0;
    int cont=1;
    int termino1=1;
    int termino2=1;
    int aux;
    cout<<"ingrese un # mayor que 0"<<endl;
    cin>>x;
    while(x<=0){
        cout<<"ingrese un # mayor que 0"<<endl;
        cin>>x;
    }
    while(termino2<x){
        if(cont==1){
            aux=termino1;
            cont++;
        }
        else{
            termino2=aux+termino1;
            termino1=aux;
            aux=termino2;
        }
        if (termino2%2==0 && termino2<x){
            suma=suma+termino2;
        }
    }
    cout<<"El resultado de la suma es: "<<suma;
    return 0;
}


int problema5(){
    int n;
    int espa, lineas;
    int asteline = 1;
    cout<<"dame un entero impar: ";
    n = pedirNumEntero();
    n = validarImpar(n);
    espa = (n/2);
    lineas = (n/2)+1;
    cout<<endl;
    for (int i = 1 ; i <= lineas ; i++){
        for (int j=0 ;j <= espa; j++){
            cout<<" ";
        }
        for (int k=1 ;k <= asteline;k++) {
            cout<<"*";
        }
        cout<<endl;
        espa = espa - 1;
        asteline = asteline + 2;
    }
    asteline = n-2;
    espa = 1;
    for (int i = lineas-1; i>0; i--){
        for (int j = 0; j<=espa ; j++){
            cout<<" ";
        }
        for (int k = 1; k <=asteline; k++){
            cout<<"*";
        }
        cout<<endl;
        espa = espa + 1;
        asteline = asteline - 2;
    }
    return 0;
}

int problema3() {
    // mes y dia validos.
    int mes;
    cout<<"Ingrese el # de un mes"<<endl;
    cin>> mes;
    if (!(mes>0 && mes<=12)){
        cout<<mes<<" es un mes invalido";
    }
    else{
        int dia;
        cout<<"ingrese un # de dia"<<endl;
        cin>>dia;
        if (mes==1 || mes==3|| mes==5|| mes==7|| mes==8|| mes==10|| mes==12){
            if (dia<0 && dia <=31){
                cout<<dia<<"/"<<mes<<" es una fecha valida";
            }
            else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida";
            }
        }
        else if(mes==4|| mes==6| mes==9||mes==11){
            if (dia<0 && dia <=30){
                 cout<<dia<<"/"<<mes<<" es una fecha valida";
            }
            else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida";
            }
        }
        else if(mes==2){
            if (dia>=0 && dia <=28){
                cout<<dia<<"/"<<mes<<" es una fecha valida";
            }
            else if(dia==29){
                cout<<dia<<"/"<<mes<<" es valida en bisiesto";
            }
            else{
                cout<<dia<<"/"<<mes<<" es una fecha invalida";
            }
        }
    }
    return 0;
}

int problema1(){
    //verifica que un caracter ingresado es una vocal, consonante o ninguna.
    char letra;
    cout<<"Ingrese un letra del abecesario: ";
    cin>>letra;
    letra = tolower(letra);
    if (letra==97 or letra==101 or letra==105 or letra==111 or letra==117)
    {
        cout<<letra<<" es una vocal";
    }
    else if (letra>=97 and letra<=122)
    {
        cout<<letra<<" es una consonante";
    }
    else {
        cout<<"no es una letra";
    }
    return 0;
}




//                    funciones funcionales





int pedirNumReal(){
    double numero;
    while (!(std::cin >> numero)) {
        // Si la entrada no es un número, std::cin entra en un estado de error
        std::cin.clear(); // Limpia el estado de error de std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada inválida
        std::cout << "Entrada no válida. Por favor, ingresa un número: ";
    }
    return numero;
}

int pedirNumEntero(){
    int numero;
    while (!(std::cin >> numero)) {
        // Si la entrada no es un número, std::cin entra en un estado de error
        std::cin.clear(); // Limpia el estado de error de std::cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada inválida
        std::cout << "Entrada no válida. Por favor, ingresa un número entero: ";
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

int mcd(int a, int b) {
    bool cond = true;
    int cont = 1;
    while (cond) {
        cont += 1;
        if (a%cont==0 and b%cond==0)
        {
            cond = false;
        }
    }
    return cont;
}

void imprimirMatriz(int* matriz, int n) {
    for (int i = 0; i < n; ++i) {        // Recorre las filas
        for (int j = 0; j < n; ++j) {    // Recorre las columnas
            // Acceso a los elementos usando aritmética de punteros
            cout << *(matriz + i * n + j) << "\t";
        }
        cout << endl;  // Nueva línea al final de cada fila
    }
}

int sumaDiagonales(int* matriz, int n) {
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        // Sumar el elemento de la diagonal principal
        suma += *(matriz + i * n + i);
        // Sumar el elemento de la diagonal inversa
        suma += *(matriz + i * n + (n - 1 - i));
    }

    // Si n es impar, restamos el elemento central, ya que fue contado dos veces
    if (n % 2 != 0) {
        suma -= *(matriz + (n / 2) * n + (n / 2));
    }

    return suma;
}

