#include <iostream>
#include <limits>

using namespace std;

int ejercicio5();
int ejercicio7();
int ejercicio9();
int ejercicio11();
int ejercicio13();
int ejercicio15();
int ejercicio17();
int ejercicio19();
int problema5();


int pedirNumReal();
int pedirNumEntero();
int validarImpar(int numero);

int main (){
    int n;
    cout<<"ingrese el # de ejercicio que desea evaluar: ";
    n = pedirNumEntero();
    switch (n) {
    case 1:
        //ejercicio1();
        break;
    case 3:
        //ejercicio3();
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
    case 31:
        problema5();
        break;
    default:
        break;
    }
    return 0;
}




//                          ejercicios y problemas




int problema5(){
    int n;
    int espa, lineas;
    int asteline = 1;
    cout<<"dame un entero par: ";
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
















