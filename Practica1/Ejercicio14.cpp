/*Escriba un programa que imprima dos columnas paralelas, una con los números del
1 al 50 y otra con los números del 50 al 1.*/

#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 50; i++) {
        cout << i << " " << (51 - i) << endl;
    }

    return 0;
}
