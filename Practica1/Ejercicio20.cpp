/*Escriba un programa que pida un número N e imprima si es o no un palíndromo
(igual de derecha a izquierda que de izquierda a derecha).*/

#include <iostream>

using namespace std;

int main()
{
    int numero, numero_original, ultimo_digito;
    int numero_alreves = 0;
    cout << "Ingrese un número: ";
    cin >> numero;
    numero_original = numero;
    while (numero > 0) {
        ultimo_digito = numero % 10;
        numero_alreves = numero_alreves * 10 + ultimo_digito;
        numero = numero / 10;
    }
    if (numero_original == numero_alreves) {
        cout << numero_original << " es un número palíndromo." << endl;
    }
    else {
        cout << numero_original << " no es un número palíndromo." << endl;
    }

    return 0;
}
