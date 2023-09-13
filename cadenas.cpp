#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;



int main() {
    // CADENAS
    // Definicion
    char palabra[] = "Alejandro";
    char palabra2[] = {'A', 'l', 'e', 'j', 'a', 'n', 'd', 'r', 'o'}; //es lo mismo
    char nombre[30];
    // Ingresar por teclado una cadena
    cout << "Ingrese su nombre: ";
    //cin >> nombre; // esto no se hace porque si ingresamos un espacio no tomara nada mas despues de el
    gets(nombre); //esta es la forma correcta
    // tiene un problema y es que no tiene en cuenta el espacio de memoria reservado para la cadena
    cin.getline(nombre, 20, '\n');
    // esta es la mejor forma pq no toma mas espacio que el reservado en memoria y tampoco se corta 
    // cuando encuentra un espacio, sino que lo hace cuando encuentra un salto de linea (o lo que le
    // indiquemos en el tercer parametro)
    // Longitud de una cadena
    int longitud_cadena = strlen(palabra); // para obtener la longitud de la cadena
    // Copiar una cadena
    char palabra_copia[];
    strcpy(palabra_copia, palabra); // para copiar el contenido de una cadena en otra
    // Comparar cadenas
    if(strcmp(palabra, palabra2) == 0){} // true: son iguales, false: son diferentes
    if(strcmp(palabra, palabra2) != 0){} // true: son diferentes, false: son iguales
    if(strcmp(palabra, palabra2) > 0){} //palabra es mayor a palabra2 alfabeticamente
    // Concatenar cadenas
    char cad1[] = "Esto es una cadena";
    char cad2[] = " de ejemplo";
    char cad3[30];
    strcpy(cad3, cad1); // cad3 = "Esto es una cadena"
    strcat(cad3, cad2); // cad3 = "Esto es una cadena de ejemplo"
    // Invertir una cadena
    char cad[] = "Hiramatsu";
    strrev(cad);
    // Pasar una cadena a mayuscula
    char minus[] = "hola";
    strupr(minus); // si una letra ya esta en mayus la deja como esta
    // Pasar una cadena a minuscula
    char mayus[] = "PROGRAMACION";
    strlwr(mayus); // si una letra esta en minuscula la deja como esta
    // convertir una cadena a numeros - funcion atoi() y atof() --> Importarlas desde stdlib.h
    //"123" -> 123
    char num_cad[] = "123";
    int num;
    num = atoi(num_cad);
    char float_cad[] = "123.345";
    float num_foat = atof(float_cad);


    getch(); //para evitar que el ejecutable se cierre - de la libreria conio.h
    return 0;
}