#include <iostream>
using namespace std;

int main() {
    // Matriz de 3 estudiantes y 3 dias
    int asistencia[3][3];

    cout << "TABLA DE ASISTENCIAS" << endl;
    cout << "Ingresa 1 si asistio y 0 si falto." << endl;

    // Captura de asistencias
    for (int estudiante = 0; estudiante < 3; estudiante++) {
        cout << endl;
        cout << "Estudiante " << estudiante + 1 << endl;

        for (int dia = 0; dia < 3; dia++) {
            cout << "Dia " << dia + 1 << ": ";
            cin >> asistencia[estudiante][dia];
        }
    }

    cout << endl;
    cout << "TABLA GENERAL DE ASISTENCIA" << endl;

    // Mostramos la matriz
    for (int estudiante = 0; estudiante < 3; estudiante++) {
        cout << "Estudiante " << estudiante + 1 << ": ";

        for (int dia = 0; dia < 3; dia++) {
            cout << asistencia[estudiante][dia] << " ";
        }

        cout << endl;
    }

    cout << endl;
    cout << "TOTAL DE ASISTENCIAS POR ESTUDIANTE" << endl;

    // Calculamos total de asistencias por estudiante
    for (int estudiante = 0; estudiante < 3; estudiante++) {
        int total = 0;

        for (int dia = 0; dia < 3; dia++) {
            total = total + asistencia[estudiante][dia];
        }

        cout << "Estudiante " << estudiante + 1 << ": " << total << " asistencias" << endl;
    }

    return 0;
}