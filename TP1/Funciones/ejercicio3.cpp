// Dos números son amigos, si cada uno de ellos es igual a la suma de los divisores del otro. Por ejemplo, 220
// y 284 son amigos, ya que:
// Suma de divisores de 284: 1 + 2 + 4 + 71 + 142 = 220
// Suma de divisores de 220: 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284
// Hacer una función que determine si dos números dados como parámetros son amigos o no.
#include <iostream>
using namespace std;

void numerosAmigos(int n1, int n2);

int main() {
    int num1, num2;
     cout << "Ingrese el primer numero: ";
     cin >> num1;
     cout << endl;
     cout << "Ingrese el segundo numero: ";
     cin >> num2;
     cout << endl;
     numerosAmigos(num1, num2);
     
     return 0;
}

void numerosAmigos(int n1, int n2) {
    int acc1 = 0, acc2 = 0;

     for (int i=1; i<n1; i++) {
        if (n1 % i == 0) {
            acc1 += i;
        }
     }
     for (int i=1; i<n2; i++) {
        if (n2 % i == 0) {
            acc2 += i;
        }
     }
     if (acc1 == n2 && acc2 == n1) {
        cout << "Los numeros " << n1 << " y " << n2 << " son amigos.";
     } else {
        cout << "Los numeros " << n1 << " y " << n2 << " no son amigos.";
     }
}