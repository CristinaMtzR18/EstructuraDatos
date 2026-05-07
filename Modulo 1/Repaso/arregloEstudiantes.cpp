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

    cout << "REGISTRO DE GRUPO DE ESTUDIANTES" << endl;

    for (int i = 0; i < 3; i++) {
        cout << endl;
        cout << "Estudiante " << i + 1 << endl;

        cout << "Matricula: ";
        cin >> grupo[i].matricula;

        cin.ignore();

        cout << "Nombre: ";
        getline(cin, grupo[i].nombre);

        cout << "Promedio: ";
        cin >> grupo[i].promedio;
    }

    cout << endl;
    cout << "LISTA DE ESTUDIANTES REGISTRADOS" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". "
             << grupo[i].nombre
             << " | Matricula: " << grupo[i].matricula
             << " | Promedio: " << grupo[i].promedio
             << endl;
    }

    return 0;
}