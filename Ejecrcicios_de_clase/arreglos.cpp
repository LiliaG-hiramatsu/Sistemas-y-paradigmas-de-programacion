#include <iostream>
using namespace std;

int main() {
    int elementos[10];
    cout << "Ingresar los elementos: ";
    int len = sizeof(elementos);
    cout << len;
    /*
    for (int i=0; i < len; i++) {
        cin >> elementos[i];
    }
    cout << "Los elementos ingresados son:";
    cout << endl;
    for (int i=0; i < len; i++) {
        cout << elementos[i];
        cout << endl;
    }
    */
    return 0;
}