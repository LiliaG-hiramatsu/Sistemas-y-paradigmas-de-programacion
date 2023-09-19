// Un profesor de matemática desea almacenar información de las calificaciones correspondientes a seis exámenes
// realizados por cada estudiante de su cátedra.
// Realice un main() que acepte como entrada el nombre, los datos de residencia y las calificaciones de cada alumno.
// a) Determine la calificación media de cada alumno y muestre por pantalla los datos de cada alumno incluyendo la media calculada.
// b) Nombre y apellido de los alumnos con mayor media.

#include <iostream>
#include <string.h>
using namespace std;

#define N 10

struct alumnos {
    char nombre[30];
    char apellido[30];
    char domicilio[100];
    char localidad[40];
    char ciudad[40];
    int notas[6];
} vecAlum[N];

float calcular_media(int notas_alumno[]) {
    int suma=0;
    for (int i=0; i<6; i++) {
        suma += notas_alumno[i];
    }
    return suma/6;
}

void mejores_promedios(alumnos arr[], float promedios[]) {
    for (int i=0; i<N-1; i++) {
        int posmenor = i;
        for (int j=i+1; j<N; j++) {
            if (promedios[j] < promedios[posmenor]) {
                posmenor = j;
            }
        }
        // Intercambio de promedios
        float aux = promedios[i];
        promedios[i] = promedios[posmenor];
        promedios[posmenor] = aux;

        // Intercambio de alumnos
        alumnos auxAlumno = arr[i];
        arr[i] = arr[posmenor];
        arr[posmenor] = auxAlumno;
    }
    
    cout << "MEJORES PROMEDIOS" << endl;
    for (int i=0; i<N-7; i++) {
        cout << arr[N-i].nombre << endl;
        cout << arr[N-i].apellido << endl;
        cout << promedios[N-i] << endl;
    }
}

int main() {
    cout << "Ingrese los datos de los alumnos" << endl;
    for (int i=0; i<N; i++) {
        cout << "Nombre: ";
        cin >> vecAlum[i].nombre;
        cin.ignore();
        cout << "Apellido: ";
        cin >> vecAlum[i].apellido;
        cin.ignore();
        cout << "Domicilio: ";
        cin >> vecAlum[i].domicilio;
        cin.ignore();
        cout << "Localidad: ";
        cin >> vecAlum[i].localidad;
        cin.ignore();
        cout << "Ciudad: ";
        cin >> vecAlum[i].ciudad;
        cin.ignore();
        cout << "Ingrese las notas del alumno:" << endl;
        for (int j=0; j<6; j++) {
            cin >> vecAlum[i].notas[j];
        }
    }
    float medias[N];
    for (int i=0; i<N; i++) {
        medias[i] = calcular_media(vecAlum[i].notas);
    }
    
    cout << "DATOS ALUMNOS" << endl;
    for (int i=0; i<N; i++) {
        cout << "Nombre: " << vecAlum[i].nombre << endl;
        cout << "Apellido: " << vecAlum[i].apellido << endl;
        cout << "Domicilio: " << vecAlum[i].domicilio << endl;
        cout << "Localidad: " << vecAlum[i].localidad << endl;
        cout << "Ciudad: " << vecAlum[i].ciudad << endl;
        cout << "Media del alumno " << vecAlum[i].nombre << ": " << medias[i] << endl;
    }

    mejores_promedios(vecAlum, medias);
    
    return 0;
}