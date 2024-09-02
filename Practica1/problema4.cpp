/*Escriba un programa para leer dos números enteros con el siguiente significado: el
valor del primer número representa una hora del día en un reloj de 24 horas, de modo que 1245
representa las doce y cuarenta y cinco de la tarde. El segundo entero representa un tiempo de duración de la misma manera,
por lo que 345 representa tres horas y 45 minutos. El programa debe sumar esta duración primer número, y el resultado
será impreso en la misma notación, en este caso 1630, que es el tiempo de 3 horas y 45 minutos después de 12:45.*/


#include <iostream>

using namespace std;

int main()
{
    int hora, duracion;
    cout << "Ingrese la hora: ";
    cin >> hora;
    int horas_iniciales = hora / 100;
    int minutos_iniciales = hora % 100;
    if (horas_iniciales < 0 || horas_iniciales > 23 || minutos_iniciales < 0 || minutos_iniciales > 59) {
        cout << hora << " es un tiempo invalido." << endl;
        return 1;
    }
    cout << "Ingrese el tiempo de duracion: ";
    cin >> duracion;
    int horas_duracion = duracion / 100;
    int minutos_duracion = duracion % 100;
    if (horas_duracion < 0 || horas_duracion > 23 || minutos_duracion < 0 || minutos_duracion > 59) {
        cout << duracion << " es un tiempo invalido." << endl;
        return 1;
    }
    int horas_finales = horas_iniciales + horas_duracion;
    int minutos_finales = minutos_iniciales + minutos_duracion;
    if (minutos_finales >= 60) {
        minutos_finales -= 60;
        horas_finales += 1;
    }
    if (horas_finales >= 24) {
        horas_finales -= 24;
    }
    cout << "La hora es " << (horas_finales < 10 ? "0" : "") << horas_finales
         << (minutos_finales < 10 ? "0" : "") << minutos_finales << "." << endl;

    return 0;
}
