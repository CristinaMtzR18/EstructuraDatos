#include <iostream>
using namespace std;

int main() {
    int numeros[5];
    int buscar;
    bool encontrado = false;

    cout << "BUSQUEDA DE UN NUMERO EN UN ARREGLO" << endl;

    // Capturamos los numeros
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa el numero " << i + 1 << ": ";
        cin >> numeros[i];
    }

    cout << endl;
    cout << "Ingresa el numero que deseas buscar: ";
    cin >> buscar;

    // Recorremos el arreglo para buscar el numero
    for (int i = 0; i < 5; i++) {
        if (numeros[i] == buscar) {
            cout << "El numero " << buscar << " se encontro en la posicion " << i << endl;
            encontrado = true;
        }
    }

    // Si no se encontro el numero, mostramos mensaje
    if (encontrado == false) {
        cout << "El numero " << buscar << " no se encontro en el arreglo." << endl;
    }

    return 0;
}