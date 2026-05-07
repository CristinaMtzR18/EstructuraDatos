/*
    EJERCICIO 5: ARREGLOS DE STRUCT

    Este programa registra 3 estudiantes usando un arreglo de estructuras.
    Cada posición del arreglo guarda un estudiante completo con matrícula,
    nombre y promedio.

    Temas principales:
    - struct
    - Arreglos
    - Arreglos de estructuras
    - Recorrido de registros
*/

#include <iostream>
#include <string>
using namespace std;

struct Estudiante {
    int matricula;
    string nombre;
    float promedio;
};

int main() {
    // Arreglo de estructuras para guardar 3 estudiantes
    Estudiante grupo[3];

    cout << "REGISTRO DE GRUPO" << endl;

    // Captura de estudiantes
    for (int i = 0; i < 3; i++) {
        cout << endl;
        cout << "Estudiante " << i + 1 << endl;

        cout << "Matricula: ";
        cin >> grupo[i].matricula;

        cin.ignore();

        cout << "Nombre completo: ";
        getline(cin, grupo[i].nombre);

        cout << "Promedio: ";
        cin >> grupo[i].promedio;
    }

    cout << endl;
    cout << "LISTA DE ESTUDIANTES REGISTRADOS" << endl;

    // Mostrar estudiantes
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". "
             << grupo[i].nombre
             << " | Matricula: " << grupo[i].matricula
             << " | Promedio: " << grupo[i].promedio
             << endl;
    }

    return 0;
}