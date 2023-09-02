// Dado un arreglo de 10 nombres de personas, realice un programa que cargue el arreglo, lo ordene de forma ascendente
// y lo muestre por pantalla ordenado.
#include <iostream>
#include <string.h>

using namespace std;

void ordenarNombres(string arr[], int n) {
    // Metodo burbuja para ordenar el array de string
    bool intercambiado;
    do {
        intercambiado = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                intercambiado = true;
            }
        }
    } while (intercambiado);
}

int main() {
    int N = 10;
    string personas[N];
    cout << "Ingrese los 10 nombres:" << endl;
    for (int i=0; i<N; i++) {
        cout << "Nombre " << i+1 << ": ";
        cin >> personas[i];
        cout << endl;
    }
    ordenarNombres(personas, N);

    cout << "La lista de nombres ordenada es:" << endl;
    for (int i=0; i<N; i++) {
        cout << "Nombre " << i+1 << ": " << personas[i] << endl;
    }
    system ("pause");
    return 0;
}