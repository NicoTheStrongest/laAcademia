#include <iostream>
#include <limits>
#include <cctype>
#include <string>

using namespace std;

int ejercicio3();
int ejercicio1();
int ejercicio5();
int ejercicio7();
int ejercicio9();
int ejercicio11();
int ejercicio13();
int ejercicio15();
int ejercicio17();
int ejercicio19();
int ejercicio21();
int ejercicio23();
int ejercicio25();
int ejercicio27();
int ejercicio29();


int pedirNumReal();
int pedirNumEntero();
int validarImpar(int numero);
int mcd(int a, int b);

int main (){
    int n;
    cout<<"ingrese el # de ejercicio que desea evaluar: ";
    n = pedirNumEntero();
    switch (n) {
    case 1:
        ejercicio1();
        break;
    case 3:
        ejercicio3();
        break;
    case 5:
        ejercicio5();
        break;
    case 7:
        ejercicio7();
        break;
    case 9:
        ejercicio9();
        break;
    case 11:
        ejercicio11();
        break;
    case 13:
        ejercicio13();
        break;
    case 15:
        ejercicio15();
        break;
    case 17:
        ejercicio17();
        break;
    case 19:
        ejercicio19();
        break;
    case 21:
        ejercicio21();
        break;
    case 23:
        ejercicio23();
        break;
    case 25:
        ejercicio25();
        break;
    case 27:
        ejercicio27();
        break;
    case 29:
        ejercicio29();
        break;
    default:
    cout<<"perdio por salchichon";
        break;
    }
    return 0;
}




//                          problemas




int ejercicio29(){
    //adivina un numero mediante pistas de <, >, y = ingresadas por el usuario.
    int low = 0 , high = 100, mid;
    char pista;
    while (low<=high){
        mid = (low+high)/2;
        cout<<mid<<" es <, > o = que su numero?: ";
        cin>>pista;
        switch (pista)
        {
        case '>':
            high = mid - 1;
            break;
        case '<':
            low = mid + 1;
            break;
        case '=':
            cout<<"Su numero es: "<<mid;
            return 0;
            break;
        default:
            break;
        }
    }
    return 0;
}


int ejercicio27() {
    //calculadora de dos numeros, imprime resuldo de la suma, resta, multiplicacion o division.
    double a, b;
    char opera;
    cout<<"Dame un numero a: ";
    a = pedirNumReal();
    cout<<"Dame un numero b: ";
    b = pedirNumReal();
    cout<<"Ingrese el simbolo de la operacion que quiere realizar: ";
    cin>>opera;
    while (opera!='-' && opera!='+' && opera!='*' && opera!='/'){
        cout<<"ingrese un operador valido.";
        cin>>opera;
    }
    switch (opera)
    {
    case '*':
        cout<<a<<"*"<<b<<"="<<a*b;
        break;
    case '+':
        cout<<a<<"+"<<b<<"="<<a+b;
        break;
    case '/':
        cout<<a<<"/"<<b<<"="<<a/b;
        break;
    case '-':
        cout<<a<<"-"<<b<<"="<<a-b;
        break;
    default:
        break;
    }
    return 0;
}

int ejercicio25(){
    //devuelve la cantidad de digitos de un numero entero n;
    int n, digitos;
    string num;
    cout<<"dame un numero entero: ";
    n = pedirNumEntero();
    num = to_string(n);
    digitos = size(num);
    cout<<n<<" tiene "<<digitos<<" digitos.";
    return 0;
}

int ejercicio23() {
    //pide dos numero he impide el minimo comun multiplo de ambos.
    int a, b, mcm;
    cout<<"dame un numero a: ";
    cin>>a;
    cout<<"dame un numero b: ";
    cin>>b;
    mcm = abs(a*b)/mcd(a, b);
    cout<<"El MCM de "<<a<<" y "<<b<<" es: "<<mcm;
    return 0;
}


int ejercicio21() {
    //recibe letra y devuelve letra en mayuscula o minuscula y viceversa, imprime la conversión
    char letra;
    bool condi = true;
    while (condi) {
        cout<<"dame un caracter de letra: ";
        cin>>letra;
        if (letra>=65 and letra<=90){
            letra = tolower(letra);
            cout<<"Letra convertida: "<<letra;
            condi = false;
        }
        else if (letra >= 97 and letra <= 122){
            letra = toupper(letra);
            cout<<"Letra convertida: "<<letra;
            condi = false;
        }
        else {
            cout<<"Tiene que ingresar una letra del abecedario";
        }
    }
    return 0;
}

int ejercicio19(){
    int n;
    bool a = true;
    cout<<"deme un numero entero: ";
    n = pedirNumEntero();
    for (int i = n ; i > 1 ; i--){
        if (n%i==0){
            cout<<endl<<n<<" NO es un numero primo.";
            a = false;
            break;
        }
    }
    if (a){
        cout<<endl<<n<<" es un numero primo";
    }
    return 0;
}

int ejercicio17(){
    int n, max=-999999999;
    do {
        cout<<"dame un numero entero: ";
        n = pedirNumEntero();
        if (n>max && n!=0){
            max = n;
        }
    }
    while (n!=0);
    if (max!=-999999999){
        cout<<endl<<"el numero mayor fue : "<<max;
    }
    else {
        cout<<endl<<"no ingreso numeros";
    }
    return 0;
}


int ejercicio15(){
    int n, sumar=0;
    do {
        cout<<"dame un numero entero: ";
        n = pedirNumEntero();
        if (n != 0){
            sumar = sumar + n;
        }
    }
    while (n != 0);
    cout<<endl<<"La suma es: "<<sumar;
    return 0;
}


int ejercicio13(){
    int n;
    cout<<"deme un numero entero: ";
    n = pedirNumEntero();
    for (int i=1;i<=n;i++){
        if (n%i==0){
            cout<<i<<endl;
        }
    }
    return 0;
}


int ejercicio11(){
    int n;
    cout<<"dame un numero entero: ";
    n = pedirNumEntero();
    for (int i=1;i<=10;i++){
        cout<<i<<" X "<<n<<" = "<<n*i<<endl;
    }
    return 0;
}

int ejercicio9(){
    const double PI = 3.1416;
    int n;
    double peri, area;
    cout<<"dame un numero entero: ";
    n = pedirNumEntero();
    peri = 2*n*PI;
    area = PI*n*n;
    cout<<"perimetro = "<<peri<<endl<<"area = "<<area;
    return 0;
}

int ejercicio7 () {
    int a;
    cout<<"ingrese el numero entero: ";
    a = pedirNumEntero();
    long int sumar = 0;
    int i = a;
    for (i; i > 0; i--) {
        sumar = sumar + i;
    }
    cout<<"La sumatoria de 0 a "<<a<<" es: "<<sumar;
    return 0;
}

int ejercicio5(){
    double a,b;
    int d;
    cout<<"dame un numero a: ";
    a = pedirNumReal();
    cout<<"dame un numero b: ";
    b = pedirNumReal();
    d = a/b;
    cout<<"la division redondeada es "<<d;
    return 0;
}

int ejercicio3(){
    int a,b;
    
    cout<<"dame un numero a ";
    cin>>a;
    
    cout<<"dame un numero b ";
    cin>>b;
    
    if (a < b)
        cout<<b<<" es mayor";
    else
        if (a > b)
            cout<<a<<" es mayor";
        else
            cout<<"los numeros son iguales";
    return 0;
}

int ejercicio1(){
    int a,b,c;
    
    cout<<"ingrese A";
    cin>>a;

    cout<<"ingrese B";
    cin>>b;
    
    c = a%b;
    
    cout<<"el residuo de la division es "<<c;
    return 0;
}




//                         funciones funcionales




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














