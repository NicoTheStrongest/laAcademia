/*Escriba un programa que genere un número aleatorio A (entre 0 y 100) y le pida al
usuario que lo adivine, el usuario ingresa un número B y el programa le dirá si B es mayor o menor
que A, esto se repetirá hasta que el usuario adivine el número, en ese momento el programa le dirá
el número de intentos que tardo el usuario en adivinar el número.*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int A = rand() % 101;
    int B;
    int intentos = 0;

    cout << "Adivina el numero entre 0 y 100" << endl;

    do {
        cout << "Ingresa un numero: ";
        cin >> B;
        intentos++;

        if (B > A) {
            cout << "El numero es menor que " << B << endl;
        } else if (B < A) {
            cout << "El numero es mayor que " << B << endl;
        } else {
            cout << "Adivinaste el numero en " << intentos << " intentos." << endl;
        }
    } while (B != A);

    return 0;
}
