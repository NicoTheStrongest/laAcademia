//Escriba un programa que pida un número N e imprima en pantalla su factorial.

#include <iostream>

using namespace std;

int main()
{
    int N;
    long long factorial = 1;
    cout << "Ingrese un numero: ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }
    cout << N << "! = " << factorial << endl;
    return 0;
}
