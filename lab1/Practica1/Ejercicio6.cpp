/*Escriba un programa que pida dos números A y B e imprima en pantalla la potencia
A^B, sin hacer uso de librerías matemáticas.*/

#include <iostream>

using namespace std;

int main()
{
    int A, B;
    long long resultado = 1;
    cout << "Ingrese la base: ";
    cin >> A;
    cout << "Ingrese el exponente: ";
    cin >> B;
    for (int i = 0; i < B; i++) {
        resultado *= A;
    }
    cout << "El resultado de " << A << "^" << B << " es: " << resultado << endl;
    return 0;
}
