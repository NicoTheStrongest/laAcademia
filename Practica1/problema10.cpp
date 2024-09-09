//Escriba un programa que reciba un número n e imprima el enésimo número primo.

#include <iostream>

using namespace std;

int main()
{
    int n;
    int contador = 0;
    int numero = 2;
    int enesimoPrimo;
    cout << "Ingrese el numero: ";
    cin >> n;

    while (contador < n) {
        bool esPrimo = true;
        for (int i = 2; i * i <= numero; ++i) {
            if (numero % i == 0) {
                esPrimo = false;
                break;
            }
        }
        if (esPrimo) {
            ++contador;
            enesimoPrimo = numero;
        }

        ++numero;
    }
    cout << endl << "El primo numero " << n << " es: " << enesimoPrimo << endl;

    return 0;
}
