/*
Intercambie los elementos de un vector de N elementos: el primero pasa a la última posición y el último a la primera posición, 
el segundo pasa a la penúltima posición y viceversa.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    int vector[n], nuevo_vector[n];
    cout << endl;
    cout << "Ingrese los elementos del vector: " << endl;
    for (int i=0; i<n; i++) {
        cin >> vector[i];
        cout << endl;
    }
    for (int i=0; i<n; i++) {
        nuevo_vector[i] = vector[n-i-1];
    }
    cout << "El vector queda:" << endl;
    for (int i=0; i<n; i++) {
        cout << nuevo_vector[i];
        cout << " ";
    }
    cout << endl;
    return 0;
}