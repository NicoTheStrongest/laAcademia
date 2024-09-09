/*. Se necesita un programa que permita determinar la mínima combinación de billetes
y monedas para una cantidad de dinero determinada. Los billetes en circulación son de $50.000,
$20.000, $10.000, $5.000, $2.000 y $1.000, y las monedas son de $500, $200, $100 y $50.
Hacer un programa que entregue el número de billetes y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas disponibles no se puede lograr la
cantidad deseada, el sistema deberá decir lo que resta para lograrla.*/

#include <iostream>

using namespace std;

int main()
{
    int cantidad, faltante;
    cout << "Ingrese la cantidad de dinero: ";
    cin >> cantidad;
    int billetes50000 = cantidad / 50000;
    cantidad %= 50000;
    int billetes20000 = cantidad / 20000;
    cantidad %= 20000;
    int billetes10000 = cantidad / 10000;
    cantidad %= 10000;
    int billetes5000 = cantidad / 5000;
    cantidad %= 5000;
    int billetes2000 = cantidad / 2000;
    cantidad %= 2000;
    int billetes1000 = cantidad / 1000;
    cantidad %= 1000;
    int monedas500 = cantidad / 500;
    cantidad %= 500;
    int monedas200 = cantidad / 200;
    cantidad %= 200;
    int monedas100 = cantidad / 100;
    cantidad %= 100;
    int monedas50 = cantidad / 50;
    cantidad %= 50;

    faltante = cantidad;

    cout << endl << "50000: " << billetes50000 << endl;
    cout << "20000: " << billetes20000 << endl;
    cout << "10000: " << billetes10000 << endl;
    cout << "5000: " << billetes5000 << endl;
    cout << "2000: " << billetes2000 << endl;
    cout << "1000: " << billetes1000 << endl;
    cout << "500: " << monedas500 << endl;
    cout << "200: " << monedas200 << endl;
    cout << "100: " << monedas100 << endl;
    cout << "50: " << monedas50 << endl;
    if (faltante > 0) {
        cout << "Faltante: " << faltante << endl;
    }

    return 0;
}
