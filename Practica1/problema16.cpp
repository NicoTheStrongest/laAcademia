/*La serie de Collatz se conforma con la siguiente regla: sea n un elemento de la serie,
si n es par, el siguiente elemento es n/2, y si n es impar, el siguiente elemento es 3n+1.
Escriba un programa que reciba un número k y calcule cual es el elemento inicial j (semilla), menor
que k, que produce la serie más larga y diga cuantos términos m tiene la serie.*/

#include <iostream>

using namespace std;

int main()
{
    int k;
    cout << "Ingrese un numero: ";
    cin >> k;

    int maxLongitud = 0;
    int semillaMaxima = 0;

    for (int j = 1; j < k; ++j) {
        int n = j;
        int longitud = 0;

        cout << "Serie para la semilla " << j << ": ";

        while (n != 1) {
            cout << n << " ";
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            longitud++;
        }
        cout << n << endl;
        longitud++;

        if (longitud > maxLongitud) {
            maxLongitud = longitud;
            semillaMaxima = j;
        }
    }

    cout << "La serie mas larga es con la semilla: " << semillaMaxima
         << ", teniendo " << maxLongitud << " terminos." << endl;

    return 0;
}
