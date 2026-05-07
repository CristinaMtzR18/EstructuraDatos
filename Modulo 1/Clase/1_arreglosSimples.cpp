/*
    EJERCICIO 1: ARREGLOS SIMPLES

    Este programa registra las edades de 5 personas usando un arreglo.
    El objetivo es comprender que un arreglo permite guardar varios datos
    del mismo tipo bajo un solo nombre.

    Tema principal:
    - Arreglos unidimensionales
    - Captura de datos
    - Recorrido básico de un arreglo
*/

#include <iostream>
using namespace std;

int main() {
    // Declaramos un arreglo de 5 espacios para guardar edades
    int edades[5];

    cout << "REGISTRO DE EDADES" << endl;

    // Captura de edades
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa la edad de la persona " << i + 1 << ": ";
        cin >> edades[i];
    }

    cout << endl;
    cout << "EDADES REGISTRADAS" << endl;

    // Mostrar edades guardadas
    for (int i = 0; i < 5; i++) {
        cout << "Persona " << i + 1 << ": " << edades[i] << " anios" << endl;
    }

    return 0;
}