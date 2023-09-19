// Desarrolle un programa que indique el tamaño de memoria ocupado por las variables E y U

#include <iostream>
using namespace std;

struct estructura_inicial{
    int x;
    float p;
    char nombre[10];
} E;

union union_inicial{
    int m;
    long a;
    char s[10];
} U;

int main() {

    cout << "El espacio de memoria ocupado por la variable E es: " << sizeof(E) << " bytes" << endl;
    cout << "El espacio de memoria ocupado por la variable U es: " << sizeof(U) << " bytes" << endl;

    return 0;
}