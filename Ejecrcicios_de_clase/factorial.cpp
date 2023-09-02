#include <iostream>
using namespace std;

int factorial(int x);

int main() {
    int n;
    cout << "ingresar un numero: ";
    cin >> n;
    
    int resultado = factorial(n);

    cout << "El resultado del factorial es: ";
    cout << resultado;
    return 0;
}

int factorial(int x) {
    
}