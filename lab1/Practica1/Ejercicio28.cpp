/* Escriba un programa que encuentre el valor aproximado de pi en base a la siguiente
suma infinita: π = 4(1 −1/3+1/5−1/7+1/9...) El usuario debe ingresar el número de elementos usados en la aproximación*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    double pi = 0.0;
    double signo = 1.0;
    int denominador = 1;
    cout << "Ingrese el número de términos para la aproximación de pi: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        pi += signo * (4.0 / denominador);
        signo = -signo;
        denominador += 2;
    }
    cout << "pi es aproximadamente: " << pi << endl;

    return 0;
}
