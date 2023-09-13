// El presupuesto anual de una empresa se distribuye entre sus áreas, se solicita desarrollar un programa para poder registrar el porcentaje
// y el monto distribuido entre las áreas en una estructura de datos (arreglo bidimensional) luego de que la junta directiva decide 
// el presupuesto total anual. Por otro lado, se solicita desarrollar una función para registrar gastos asociados a cada área donde se 
// debe controlar si dicho gasto es posible o no de acuerdo a los gastos ya registrados. Finalmente debe haber otra función que indique 
// el saldo disponible actual de cada área y el porcentaje que han utilizado de su disponible. Desarrolle el menú correspondiente para 
// su mejor operatividad.

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

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


    return 0;
}

