// El presupuesto anual de una empresa se distribuye entre sus áreas, se solicita desarrollar un programa para poder registrar el porcentaje
// y el monto distribuido entre las áreas en una estructura de datos (arreglo bidimensional) luego de que la junta directiva decide 
// el presupuesto total anual. 
// Por otro lado, se solicita desarrollar una función para registrar gastos asociados a cada área donde se 
// debe controlar si dicho gasto es posible o no de acuerdo a los gastos ya registrados.
// Finalmente debe haber otra función que indique el saldo disponible actual de cada área y el porcentaje que han utilizado de su disponible. 
// Desarrolle el menú correspondiente para su mejor operatividad.

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <sstream>

using namespace std;

#define N 3 // cantidad de areas
#define M 5 // cantidad de gastos

vector<vector<string>> areas(N, vector<string>(2));     // filas: cantidad de areas; columnas: codigo de area y nombre
vector<vector<int>> presupuestos_areas(N, vector<int>(3));   // filas: cantidad de areas; columnas: codigo del area, porcentaje y presupuesto en pesos
vector<vector<int>> gastos(N, vector<int>(M));
vector<int> suma(M, 0);

void configurarAreas(vector<vector<string>>& areas, vector<vector<int>>& presupuestos_areas, int presupuesto) {
    for (int i=0; i < N; i++) {
        cout << "Ingrese el codigo del area " << i+1 << ": ";
        cin >> areas[i][0];
        cout << "Ingrese el nombre del area " << areas[i][0] << ": ";
        cin >> areas[i][1];
        cout << "Ingrese el porcentaje destinado al area de " << areas[i][1] << ": ";
        cin >> presupuestos_areas[i][1];
        presupuestos_areas[i][2] = presupuestos_areas[i][1] * presupuesto / 100;
        cout << "El monto en pesos destinado al area " << areas[i][1] << " es: $ " << presupuestos_areas[i][2] << endl;
    }
}

void cargarGastos(vector<vector<string>>& areas, vector<vector<int>>& presupuestos_areas, vector<vector<int>>& gastos, int presupuesto) {
    int acc = 0;
    bool repetir = true;
    while (repetir) {
        cout << "\nSeleccione el area para la cual desea registrar gastos:" << endl;
        for (int i=0; i<N; i++) {
            cout << "Presione " << i+1 << " para el area " << areas[i][1] << endl;
        }
        int opcion;
        cin >> opcion;
        cout << "Ingresar los gastos (en pesos) del area " << areas[opcion-1][1] << endl;
        for (int j=0; j<M; j++) {
            cin >> gastos[opcion-1][j];
            acc += gastos[opcion-1][j];
            if (acc > presupuestos_areas[opcion-1][2]) {
                cout << "No hay fondos disponibles." << endl;
                acc -= gastos[opcion-1][j];
                j = M;
            }
        }
        presupuestos_areas[opcion-1][2] -= acc;
        presupuestos_areas[opcion-1][1] = presupuestos_areas[opcion-1][2]*100 / presupuesto;
        cout << "El gasto total del area " << areas[opcion-1][1] << " es de: $ " << acc << endl;
        cout << "\nDesea cargar gastos de otro area?" << endl << "1. SI" << endl << "2. NO" << endl;
        int salir;
        cin >> salir;
        if (salir == 2) {
            repetir = false;
        }
    }
}

void verSaldo(vector<vector<string>>& areas, vector<vector<int>>& presupuestos_areas) {
    for (int i=0; i<N; i++) {
        cout << "Saldo disponible del area " << areas[i][1] << " es: $";
        cout << presupuestos_areas[i][2] << endl;
        cout << "Porcentaje utilizado: " << presupuestos_areas[i][1] << " %" << endl;
    }
}

int main() {
    int presupuesto, opc;
    bool flat = true;
    while (flat) {
        cout << "\nMenu" << endl;
        cout << "1. Ingresar presupuesto anual" << endl;
        cout << "2. Ingresar areas y presupuesto destinado a ella" << endl;
        cout << "3. Registrar gastos de cada area" << endl;
        cout << "4. Ver el saldo actual disponible de cada area" << endl;
        cout << "5. Ver areas y su presupuesto asociado" << endl;
        cout << "6. Ver areas y los gastos realizados" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1:
                cout << "Ingresar el presupuesto anual: ";
                cin >> presupuesto;
                if (presupuesto <= 0) {
                    cout << "Debe ingresar un presupuesto valido." << endl;
                    cout << "Ingresar el presupuesto anual: ";
                    cin >> presupuesto;
                }
                cout << "El presupuesto es de: $ " << presupuesto << endl;
                break;

            case 2:
                cout << "Cargar areas\n";
                configurarAreas(areas, presupuestos_areas, presupuesto);
                break;

            case 3:
                cout << "Cargar gastos\n";
                cargarGastos(areas, presupuestos_areas, gastos, presupuesto);
                break;

            case 4:
                cout << "Saldos disponibles\n";
                verSaldo(areas, presupuestos_areas);
                break;

            case 5:
                cout << "Areas y presupuestos\n";
                for (int i=0; i<N; i++) {
                    cout << "Al area " << areas[i][1] << " le corresponde $ " << presupuestos_areas[i][2] << endl;
                }
                break;

            case 6:
                cout << "Areas y gastos realizados\n";
                for (int i=0; i<N; i++) {
                    for (int j=0; j<M; j++) {
                        suma[i] += gastos[i][j];
                    }
                    cout << "El area " << areas[i][1] << " gasto $ " << suma[i] << endl;
                }
                break;

            case 0:
                flat = false;
                break;

            default:
                cout << "Ingresar una opcion valida";
                break;
        }
    }
    return 0;
}

