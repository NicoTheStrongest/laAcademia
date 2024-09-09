//Escriba un programa que pida un número N e imprima si es o no un cuadrado perfecto.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numero;
    cout << "Ingrese un numero: " << endl;
    cin >> numero;
    double raiz = sqrt(numero);
    int raizEntera = raiz;

    if (raizEntera * raizEntera == numero) {
        cout << numero << " Es un cuadrado perfecto." << endl;
    }
    else {
        cout << numero << " No es un cuadrado perfecto." << endl;
    }
    return 0;
}
