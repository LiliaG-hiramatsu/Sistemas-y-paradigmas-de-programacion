// Dados dos arreglos A y B de igual número de elementos, se desea generar e imprimir un arreglo C conteniendo las sumas:
// A[i] + B[i] = C[i]. También indicar (solo imprimir por pantalla) aquellos elementos que están en el arreglo A y no están en el arreglo B.

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Ingrese el valor de N: ";
    cin >> N;
    int A[N], B[N], C[N];
    cout << "Ingrese los elementos del vector A:" << endl;
    for (int i=0; i<N; i++){
        cin >> A[i];
        cout << endl;
    }
    cout << "Ingrese los elementos del vector B:" << endl;
    for (int i=0; i<N; i++){
        cin >> B[i];
        cout << endl;
    }
    for (int i=0; i<N; i++){
        C[i] = A[i] + B[i];
    }
    cout << "El vector C queda:" << endl;
    for (int i=0; i<N; i++) {
        cout << C[i] << " ";
    }
    bool encontrado;
    cout << endl << "Los elementos que estan en el vector A y no estan en el vector B es/son:" << endl;
    for (int i=0; i<N; i++) {
        encontrado = false;
        for (int j=0; j<N; j++) {
            if (A[i] == B[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    return 0;
}