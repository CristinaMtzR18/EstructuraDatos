#include <iostream>
using namespace std;

int main() {
    // Declaramos un arreglo para guardar 5 edades
    int edades[5];

    cout << "REGISTRO DE EDADES" << endl;

    // Pedimos al usuario que capture las edades
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa la edad de la persona " << i + 1 << ": ";
        cin >> edades[i];
    }

    cout << endl;
    cout << "Edades registradas:" << endl;

    // Recorremos el arreglo para mostrar las edades guardadas
    for (int i = 0; i < 5; i++) {
        cout << "Persona " << i + 1 << ": " << edades[i] << " anios" << endl;
    }

    return 0;
}