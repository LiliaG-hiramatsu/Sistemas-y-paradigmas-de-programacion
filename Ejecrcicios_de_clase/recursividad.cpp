#include <iostream>
using namespace std;

int suma(int actual, int final);

int main() {
    int n;
    cout << "Ingrese un valor: ";
    cin >> n;

    int resultado = suma(1, n);

    cout << "El resultado de la suma es: ";
    cout << resultado;
    cout << endl;
    return 0;
}

int suma(int actual, int final) {
    int siguiente = actual + 1;

    if (actual != final) {
        return actual + suma(siguiente, final);
    } else {
        return final;
    }
}