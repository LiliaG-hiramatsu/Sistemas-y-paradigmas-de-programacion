// Realice el ejercicio 3 de la parte de Arreglos, creando las funciones correspondientes para leer los arreglos,
// realizar la suma solicitada y otra para indicar los elementos que están en A y no están en B.
// Dados dos arreglos A y B de igual número de elementos, se desea generar e imprimir un arreglo C conteniendo las sumas:
// A[i] + B[i] = C[i]. También indicar (solo imprimir por pantalla) aquellos elementos que están en el arreglo A y no están en el arreglo B.

#include <iostream>
using namespace std;

void crear_arreglo(int arr[], int size);
void sumar_arreglos(int arr_A[], int arr_B[], int arr_C[], int size);
void mostrar_elem_no_repetidos(int arr_A[], int arr_B[], int size);

int main() {
    int N, A[N], B[N], C[N];
    cout << "Ingresar el valor de N: ";
    cin >> N;
    cout << endl;
    cout << "Crear el vector A" << endl;
    crear_arreglo(A, N);
    cout << "Crear el vector B" << endl;
    crear_arreglo(B, N);
    cout << "El vector C es:" << endl;
    sumar_arreglos(A, B, C, N);
    cout << "Los elementos del vector A que no estan en B:" << endl;
    mostrar_elem_no_repetidos(A, B, N);
    return 0;
}

void crear_arreglo(int arr[], int size) {
    cout << "Ingresar elementos del vector:" << endl;
    for (int i=0; i<size; i++) {
        cout << "Elemento " << i << ": ";
        cin >> arr[i];
        cout << endl;
    }
}

void sumar_arreglos(int arr_A[], int arr_B[], int arr_C[], int size) {
    for (int i=0; i<size; i++) {
        arr_C[i] = arr_A[i] + arr_B[i];
    }
    for (int i=0; i<size; i++) {
        cout << "Elemento " << i << ": " << arr_C[i] << endl;
    }
}

void mostrar_elem_no_repetidos(int arr_A[], int arr_B[], int size) {
    bool encontrado;
    for (int i=0; i<size; i++) {
        encontrado = false;
        for (int j=0; j<size; j++) {
            if (arr_A[i] == arr_B[j]) {
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << arr_A[i] << " ";
        }
    }
    cout << endl;
}