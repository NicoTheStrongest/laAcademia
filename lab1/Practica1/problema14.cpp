/*Un número palíndromo es igual de derecha a izquierda y de izquierda a derecha,
escriba un programa que calcule el número palíndromo más grande que se puede obtener
como una multiplicación de números de 3 dígitos*/

#include <iostream>

using namespace std;

int main()
{
    int maxPalindromo = 0;
    int factor1 = 0, factor2 = 0;

    for (int i = 999; i >= 100; --i) {
        for (int j = i; j >= 100; --j) {
            int producto = i * j;
            int original = producto;
            int reverso = 0;

            while (original > 0) {
                reverso = reverso * 10 + original % 10;
                original /= 10;
            }

            if (producto == reverso && producto > maxPalindromo) {
                maxPalindromo = producto;
                factor1 = i;
                factor2 = j;
            }
        }
    }

    cout << factor1 << " * " << factor2 << " = " << maxPalindromo << endl;

    return 0;
}
