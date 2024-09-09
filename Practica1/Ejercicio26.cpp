/*Escriba un programa que pida tres números e imprima el tipo de triangulo (isósceles, equilátero, escaleno) que se formaría, si sus lados tienen la longitud denida por los números
ingresados. Tenga en cuenta el caso en que los números ingresados no forman un triángulo.*/


#include <iostream>

using namespace std;

int main()
{
    int a, b , c;
    cout << "Ingrese tres numeros: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a + b > c && a + c > b && b + c > a){
        if (a == b && b == c){
            cout << "Se forma un triangulo equilatero.";
        }
        else if (a == b || a == c || b == c){
            cout << "Se forma un triangulo isosceles.";
        }
        else{
            cout << "Se forma un triangulo escaleno.";
        }
    }
    else{
        cout << "Las longitudes ingresadas no forman un triangulo.";
    }
    return 0;
}
