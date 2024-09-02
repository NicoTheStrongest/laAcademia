//Escriba un programa que pida un número N e imprima en pantalla todos los múltiplos de dicho número entre 1 y 100.

#include <iostream>

using namespace std;

int main()
{
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;
    cout << "Multiplos de " << N << " menores que 100: " << endl;

    for (int i = 1; i * N < 100; i++) {
        cout << i * N << endl;
    }
    return 0;
}
