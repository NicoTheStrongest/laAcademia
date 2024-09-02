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
    return 0;
}

int problema13(){  //     revisar
    int X;
    int acum=0;
    int a=2;
    cout<<"Ingrese un numero mayor que 0"<<endl;
    cin>>X;
    while(X<=0){
        cout<<"Ingrese un numero mayor que 0"<<endl;
        cin>>X;
    }
    if (X>2){
        while(a<X && X!=2){
            bool bandera=true;
            int cont=2;
            while(a>cont && bandera){
                if (a%cont==0){
                    bandera=false;
                }
                cont++;
            }
            if (bandera){
                acum=acum+a;
            }
            a=a+1;
        }
        cout<<"El resultao de la suma es: "<<acum;
    }
    else{
        cout<<"El resultao de la suma es: "<<acum;
    }
    return 0;
}

int problema11(){  //     revisar
    int X;
    cout<<"Escriba un # entero positivo"<<endl;
    cin>>X;
    while(X<=0){
        cout<<"Escriba un # entero positivo"<<endl;
        cin>>X;
    }
    int cont=X;
    int val=X;
    while(cont>=1){
        if(val%cont==0){
            cont--;
        }
        else{
            val=val+X;
            cont=X;
        }
    }
    cout<<"El minimimo comun multiplo es:"<<val;
    return 0;
}

int problema9(){  //             revisar
    int X;
    int a;
    int acum=0;
    cout<<"ingrese un numero entero:"<<endl;
    cin>>X;
    if(X<0){
        X=X*(-1);

    }
    while(X>=1){
        a=(X%10);
        X=(X-a)/10;
        int cont=1;
        int acumm=1;
        while(cont<=a){
            acumm=acumm*a;
            cont++;
        }
        acum=acum+acumm;
    }
    cout<<"El resultado de la suma es: "<<acum;
    return 0;
}

int problema7(){ //             revisar
    int X;
    int acum=0;
    int cont=1;
    int i=1;
    int j;
    int z=1;
    cout<<"ingrese un # mayor que 0"<<endl;
    cin>>X;
    while(X<=0){
        cout<<"ingrese un # mayor que 0"<<endl;
        cin>>X;
    }
    while(X>z){
        if(cont==1){
            j=i;
            cont++;
        }
        else{
            z=j+i;
            i=j;
            j=z;
        }
        if (z%2==0 && z<X){
            acum=acum+z;
        }
    }
    cout<<"El resultado de la suma es: "<<acum;
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






