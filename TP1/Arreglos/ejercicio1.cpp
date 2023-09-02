#include <iostream>
using namespace std;

int main() {
    int elementos[10], suma = 0, mayor = 100000;

    cout << "Ingresar los numeros:";
    cout << endl;
    for (int i=0; i<10; i++) {
        cin >> elementos[i];
        if (i % 2 == 0) {
            suma += elementos[i];
        } else {
            if (elementos[i] > elementos[i+1]) {
                mayor = elementos[i];
            } else {
                mayor = elementos[i+1];
            }
        }
        
    }
    cout << "El resultado de la suma de los elementos que ocupan posiciones pares es: ";
    cout << suma;
    cout << endl;

    cout << "El mayor numero de los elementos que ocupan posiciones impares es: ";
    cout << mayor;
    cout << endl;

    return 0;
}