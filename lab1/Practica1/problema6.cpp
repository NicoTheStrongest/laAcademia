/*Escriba un programa que encuentre el valor aproximado del número de euler en base
a la siguiente suma innita:
e = (1/0! +1/1! +1/2! +1/3! +1/4! +1/5! + ... ) El usuario debe ingresar el número de elementos usados en la aproximación*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    double e = 0.0;
    double factorial = 1.0;
    cout << "Ingrese el numero de elementos para la aproximacion: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            factorial *= i;
        }
        e += 1.0 / factorial;
    }
    cout << "e es aproximadamente: " << e << endl;

    return 0;
}
