/*Escriba un programa que reciba 3 números a, b, c, y calcule la suma de todos los
múltiplos de a y b que sean menores a c. Tenga en cuenta no sumar 2 veces los múltiplos comunes*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Ingrese el valor de a: ";
    cin >> a;
    cout << "Ingrese el valor de b: ";
    cin >> b;
    cout << "Ingrese el valor de c: ";
    cin >> c;

    set<int> multiplos;
    int suma = 0;
    for (int i = a; i < c; i += a) {
        multiplos.insert(i);
    }
    for (int i = b; i < c; i += b) {
        multiplos.insert(i);
    }
    for (int num : multiplos) {
        suma += num;
    }
    bool primero = true;
    cout << "Multiplos: ";
    for (int num : multiplos) {
        if (!primero) {
            cout << " + ";
        }
        cout << num;
        primero = false;
    }
    cout << " = " << suma << endl;

    return 0;
}
