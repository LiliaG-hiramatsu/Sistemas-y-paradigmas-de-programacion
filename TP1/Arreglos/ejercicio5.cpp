// Dadas dos matrices M y N de 3 x 2, se pide generar una tercer matriz P cuyos elementos sean la suma de
// los elementos correspondientes de las otras dos.
#include <iostream>
using namespace std;

int main() {
    int filas = 3, columnas = 2;
    int M[filas][columnas], N[filas][columnas], P[filas][columnas];

    cout << "Llenar matriz M:" << endl;
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            cout << "Elemento " << i << "x" << j << " = ";
            cin >> M[i][j];
            cout << endl;
        }
    }
    cout << "Llenar matriz N:" << endl;
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            cout << "Elemento " << i << "x" << j << " = ";
            cin >> N[i][j];
            cout << endl;
        }
    }
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            P[i][j] = M[i][j] + N[i][j];
        }
    }
    cout << "La matriz P es:" << endl;
    for (int i=0; i<filas; i++) {
        for (int j=0; j<columnas; j++) {
            cout << "P[" << i << "," << j << "] = " << P[i][j] << endl;
        }
    }
    system ("pause");
    return 0;
}