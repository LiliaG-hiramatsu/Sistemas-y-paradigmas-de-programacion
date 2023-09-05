#include <iostream>
using namespace std;

int main() {
    struct legajo {
        int edad;
        char nombre[50];
        float sueldo;
    } alumno, profesor;
    struct legajo legajo_vendedores, legajo_profesionales;
    
    legajo_profesionales.edad = 20;
    cout << "Ingresar la edad de los vendedores: ";
    cin >> legajo_vendedores.edad;
    cout << "Ingresar el nombre del alumno: ";
    cin >> alumno.nombre;
    
    return 0;
}