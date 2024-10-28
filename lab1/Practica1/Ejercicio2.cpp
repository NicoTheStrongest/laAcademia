/*Escriba un programa que pida un número N e imprima en pantalla si es par o impar.*/

#include <iostream>

using namespace std;

int main()
{
    int numero;
    cout << "Digite un numero: " << endl;
    cin >> numero;
    cout << numero << endl;
    if (numero == 0){
        cout << "El numero es cero";
    }
    else if (numero % 2 == 0){
        cout << "El numero es par";
    }
    else{
        cout << "El numero es impar";
    }
    return 0;
}
