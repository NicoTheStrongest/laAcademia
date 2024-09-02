//Escriba un programa que pida un número N e imprima todas las potencias desde N^1 hasta N^5.

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    int potencia = 1;
    for (int i = 1; i <= 5; i++) {
        potencia *= N;
        cout << N << "^" << i << " = " << potencia << endl;
    }
    return 0;
}
