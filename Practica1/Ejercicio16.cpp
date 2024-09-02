/*Escriba un programa que pida constantemente números hasta que se ingrese
el número cero e imprima en pantalla el promedio de los números ingresados (excluyendo el cero).*/

#include <iostream>

using namespace std;

int main()
{
    double numero;
    double suma = 0.0;
    int conteo = 0;
    cout << "Ingrese numeros (Ingrese 0 para terminar): " << endl;
    while (true) {
        cin >> numero;
        if (numero == 0){
            break;
        }
        suma += numero;
        conteo++;
    }
    double promedio = suma / conteo;
    cout << "El promedio es: " << promedio;
        return 0;
}
