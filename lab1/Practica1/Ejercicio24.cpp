/*Escriba un programa que pida una número entero e imprima un cuadrado de dicho
tamaño, los bordes del cuadrado deben estar hechos con el carácter `+' y el interior debe estar vacío*/

#include <iostream>

using namespace std;

int main()
{
    int numero;
    cout << " Ingrese un numero: ";
    cin >> numero;
    for (int i = 0; i < numero; i++) {
        for (int j = 0; j < numero; j++) {
            if (i == 0 || i == numero - 1 || j == 0 || j == numero - 1) {
                cout << "+";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;

}
