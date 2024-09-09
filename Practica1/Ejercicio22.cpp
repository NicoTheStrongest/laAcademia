/*Escriba un programa que pida una cantidad entera de segundos y la imprima en
formato horas:minutos:segundos.*/

#include <iostream>

using namespace std;

int main()
{
    int entero_segundos;
    int horas, minutos,segundos;
    cout << "Ingrese un numero entero de segundos: " ;
    cin >> entero_segundos;
    horas = entero_segundos / 3600;
    minutos = (entero_segundos % 3600) / 60;
    segundos = entero_segundos % 60;
    cout << horas << ":" << minutos << ":" << segundos << endl;

    return 0;
}
