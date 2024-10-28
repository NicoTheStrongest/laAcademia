//Escriba un programa que pida dos números A y B e imprima en pantalla el menor.

#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cout << "Ingrese el primer numero: " << endl;
    cin >> A;
    cout << "Ingrese el segundo numero: " << endl;
    cin >> B;
    if (A < B){
        cout << "El menor es " << A << endl;
    }
    else if (B < A){
        cout << "El menor es " << B << endl;
    }
    else{
        cout << "Los numeros son iguales.";
    }
    return 0;
}
