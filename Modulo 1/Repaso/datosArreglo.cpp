#include <iostream>
using namespace std;

int main() {
    // Arreglo con capacidad para 5 numeros
    int numeros[5];

    cout << "INSERCION DE NUMEROS EN UN ARREGLO" << endl;

    // Insertamos datos en cada posicion del arreglo
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << endl;
    cout << "Datos almacenados:" << endl;

    // Mostramos todos los numeros capturados
    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }

    cout << endl;

    return 0;
}