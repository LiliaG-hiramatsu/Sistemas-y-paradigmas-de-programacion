// Escribe la declaración de un tipo de estructura que se llamará TALUMNO, con la siguiente información:
// Identificador de alumno: un entero
// Edad: un entero
// Notas: un vector de 5 reales que contiene las notas del alumno en las 5 asignaturas
// Pasa: un booleano (cierto o falso) que nos dice si el alumno puede pasar o no de curso
// a) Escribe la declaración de una variable llamada alumno de tipo TALUMNO, y el código necesario para
// poner el campo pasa de esa variable en true si el alumno a aprobado más de 3 asignaturas o a false en caso
// contrario. Dicha acción debe realizarse con una función.
// b) Escribe la declaración de un vector de 8 elementos de tipo TALUMNO. Escribe después el código
// necesario para aumentar, a todos los alumnos mayores de 20 años, 0,5 puntos en la calificación de todas las
// asignaturas. Dicha acción debe realizarse con una función.
#include <iostream>
#include <stdlib.h>
using namespace std;

struct talumno {
    int id;
    int edad;
    float notas[5];
    bool pasa;
};

void subir_nota(talumno arr_alumno[], string materias[]) {
    for (int i=0; i<8; i++) {
        if (arr_alumno[i].edad > 20) {
            for (int j=0; j<5; j++) {
                arr_alumno[i].notas[j] += 0.5;
                cout << endl << "Las calificaciones del alumno de id " << arr_alumno[i].id << " quedan:" << endl;
                cout << "Asignatura " << materias[j] << ": ";
                cout << arr_alumno[i].notas[j] << endl;
            }
        }
    }
}

bool alumno_pasa(talumno alumno) {
    int contador = 0;
    for (int i=0; i<5; i++) {
        if (alumno.notas[i] >= 6) {
            contador++;
        }
    }
    if (contador > 3) {
        alumno.pasa = true;
    } else {
        alumno.pasa = false;
    }
    return alumno.pasa;
}

int main () {
    struct talumno alumno;
    string asignaturas[5];
    talumno arreglo_alumnos[8];

    cout << "Ingrese el id del alumno: ";
    cin >> alumno.id;
    cin.ignore();
    cout << "Ingrese la edad del alumno: ";
    cin >> alumno.edad;
    cin.ignore();
    cout << "Ingrese las 5 asignaturas que curso el alumno:" << endl;
    for (int i=0; i<5; i++) {
        cin >> asignaturas[i];
        cin.ignore();
    }
    cout << "Ingrese las notas del alumno:" << endl;
    for (int i=0; i<5; i++) {
        cin >> alumno.notas[i];
    }
    if (alumno_pasa(alumno)) {
        cout << endl << "El alumno de id " << alumno.id << " pasa de curso." << endl;
    } else {
        cout << endl << "El alumno de id " << alumno.id << " no pasa de curso." << endl;
    }

    cout << endl << "Ingrese los datos de los 8 alumnos" << endl;
    for (int i=0; i<8; i++) {
        cout << "ID: ";
        cin >> arreglo_alumnos[i].id;
        cin.ignore();
        cout << "Edad: ";
        cin >> arreglo_alumnos[i].edad;
        cin.ignore();
        cout << "Asignaturas que curso:" << endl;
        for (int j=0; j<5; j++) {
            cin >> asignaturas[j];
            cin.ignore();
        }
        cout << "Notas de cada asignatura:" << endl;
        for (int j=0; j<5; j++) {
            cin >> arreglo_alumnos[i].notas[j];
        }
    }
    subir_nota(arreglo_alumnos, asignaturas);

    return 0;
}