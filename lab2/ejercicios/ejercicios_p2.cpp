#include <iostream>

using namespace std;

void fun_c(double *a, int n, double *promedio, double*suma);

int main()
{
    int n = 3;
    double promedio;
    double suma;
    double arreglo [n] = {10,10,10};
    fun_c(&arreglo[0], n, &promedio, &suma);
    cout<<"promedio: "<<promedio<<endl;
    return 0;
}

void fun_c(double *a, int n, double *promedio, double*suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++)
        *suma = *suma + a[i];
    *promedio = *suma / n;
}


