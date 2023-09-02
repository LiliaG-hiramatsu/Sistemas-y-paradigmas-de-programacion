// Escribir un programa que contenga una función la cual recibe como parámetros un arreglo y un número en
// particular. Dicha función debe imprimir por pantalla las posiciones donde se encuentra ese numero en el
// arreglo, si el numero no se encuentra en el arreglo indicarlo con un mensaje final.
#include <iostream>
using namespace std;

void mostrar_posicion(int arr[], int size, int numero);

int main() {
    int num, N;
    cout << "Ingrese N: ";
    cin >> N;
    cout << endl;
    int vector[N];
    cout << "Ingrese un numero: ";
    cin >> num;
    cout << endl;
    cout << "Crear el arreglo" << endl;
    for (int i=0; i<N; i++) {
        cout << "Elemento " << i << ": ";
        cin >> vector[i];
        cout << endl;
    }
    mostrar_posicion(vector, N, num);

    system("pause");
    return 0;
}

void mostrar_posicion(int arr[], int size, int numero) {
    bool noEncontrado = true;
    for (int i=0; i<size; i++) {
        if (arr[i] == numero) {
            noEncontrado = false;
            cout << "El numero esta en la/s posicion/es: " << i;
        }
        cout << endl;
    }
    if (noEncontrado) {
        cout << "El numero no se encuentra en el array." << endl;
    }
}