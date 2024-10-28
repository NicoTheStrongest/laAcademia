//Escriba un programa que calcula el máximo factor primo de un número.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    int numero = n;
    int mayorFactorPrimo = 1;
    int divisor = 2;

    while (n > 1) {
        if (n % divisor == 0) {
            mayorFactorPrimo = divisor;
            while (n % divisor == 0) {
                n /= divisor;
            }
        }
        ++divisor;
    }

    cout << "El mayor factor primo de " << numero << " es: " << mayorFactorPrimo << endl;

    return 0;
}
