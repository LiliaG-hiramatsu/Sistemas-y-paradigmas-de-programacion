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

using namespace std;

float gastos_registrados_por_area(string area, float presupuesto_area, float acc) {
    float gasto;
    while(acc <= presupuesto_area) {
        cout << "Ingrese el gasto realizado por el area " << area << ": ";
        cin >> gasto;
        acc += gasto;
        if (gasto > presupuesto_area || acc > presupuesto_area) {
            cout << "El gasto no es posible porque supera el presupuesto." << endl;
            acc -= gasto;
            return acc;
        }
        int res;
        cout << "Desea ingresar mas gastos?" << endl << "1- SI" << endl << "2- NO" << endl;
        cin >> res;
        if (res == 2) {
            return acc;
        } else {
            continue;
        }
    }
}

void saldo_disponible(string area, float presupuesto_area, float acc) {
    cout << "**AREA " << area << endl;
    cout << "Saldo disponible: $ " << presupuesto_area - acc << endl;
    cout << "Porcentaje utilizado: " << acc*100/presupuesto_area << " %" << endl;
}

int main() {
    int presupuesto;
    cout << "Ingresar el presupuesto anual: ";
    cin >> presupuesto;
    while (presupuesto <= 0) {
        cout << "Debe ingresar un presupuesto valido: ";
        cin >> presupuesto;
    }

    int cantidad_areas;
    cout << "Especifique cuantas areas existen en su empresa: ";
    cin >> cantidad_areas;
    cin.ignore(); // problema con el carácter de nueva línea que queda en el búfer
    // se utiliza cin.ignore() para eliminar el carácter de nueva línea en el búfer antes de entrar en el bucle

    string areas[cantidad_areas];
    for (int i=0; i < cantidad_areas; i++) {
        cout << "Ingrese el nombre del area " << i+1 << ": ";
        getline(cin, areas[i]);
    }
    
    int N = cantidad_areas;
    float porcentajes[N];
    cout << "Especifique el porcentaje de presupuesto destinado a cada area:" << endl;
    for (int i=0; i<N; i++) {
        cout << "Porcentaje para el area de " << areas[i] << ": ";
        cin >> porcentajes[i];
    }

    cout << endl;
    cout << "En resumen:" << endl;
    for (int i=0; i<N; i++) {
        cout << "Al area de " << areas[i] << " le corresponde el " << porcentajes[i] << " % del presupuesto." << endl;
    }

    float presupuesto_areas[N];
    for (int i=0; i<N; i++) {
        presupuesto_areas[i] = porcentajes[i] * presupuesto / 100;
    }
    cout << "El monto que le corresponde a cada area es:" << endl;
    for (int i=0; i<N; i++) {
        cout << "Al area de " << areas[i] << " le corresponde $" << presupuesto_areas[i] << endl;
    }

    
    int opcion, salir;
    vector<float> gastos_acumulados(N, 0); //Inicializo el vector con ceros
    bool flat = true;
    
    cout << endl;
    cout << "REGISTRO DE GASTOS POR AREA" << endl;
    while (flat) {
        cout << "Para salir de este menu presione 0. Para continuar presione 1: ";
        cin >> salir;
        if (salir == 0) {
            flat = false;
        } else {
            cout << "Seleccione el area para la cual desea registrar gastos:" << endl;
            for (int j=0; j<N; j++) {
                cout << "Presione " << j+1 << " para el area " << areas[j] << endl;
            }
            cin >> opcion;
            gastos_acumulados[opcion-1] = gastos_registrados_por_area(areas[opcion-1], presupuesto_areas[opcion-1], gastos_acumulados[opcion-1]);
            
            cout << "El gasto total del area " << areas[opcion-1] << " es de: $" << gastos_acumulados[opcion-1] << endl;
        }
    }
    cout << "Salio del menu para registrar gastos con exito." << endl;

    cout << endl;
    cout << "SALDOS DISPONIBLES" << endl;
    for (int i=0; i<N; i++) {
        saldo_disponible(areas[i], presupuesto_areas[i], gastos_acumulados[i]);
    }

    return 0;
}

