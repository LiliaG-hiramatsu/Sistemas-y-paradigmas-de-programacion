#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int arreglo[10] = {82, 6, 4, 12, 19, 12, 89, 68, 45, 37};
    int i, pasada, aux, menor, posmenor;
    for (pasada=0; pasada<9; pasada++) {
        menor = arreglo[pasada];
        posmenor = pasada;
        for (i=pasada+1; i<10; i++) {
            if (arreglo[i] < menor) {
                menor = arreglo[i];
                posmenor = i;
            }
        }
        aux = arreglo[pasada];
        arreglo[pasada] = arreglo[posmenor];
        arreglo[posmenor] = aux;
    }
    cout << "ARREGLO ORDENADO DE MENOR A MAYOR" << endl;
    for (i=0; i<10; i++) {
        cout << arreglo[i] << " - ";
    }
    cout << endl;

    system("pause");
    return 0;
}