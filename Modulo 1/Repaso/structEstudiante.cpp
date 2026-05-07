#include <iostream>
#include <string>
using namespace std;

// Definimos una estructura para representar a un estudiante
struct Estudiante {
    int matricula;
    string nombre;
    float promedio;
};

int main() {
    Estudiante alumno;

    cout << "REGISTRO DE ESTUDIANTE" << endl;

    cout << "Ingresa la matricula: ";
    cin >> alumno.matricula;

    // Limpiamos el salto de linea pendiente antes de usar getline
    cin.ignore();

    cout << "Ingresa el nombre: ";
    getline(cin, alumno.nombre);

    cout << "Ingresa el promedio: ";
    cin >> alumno.promedio;

    cout << endl;
    cout << "DATOS DEL ESTUDIANTE" << endl;
    cout << "Matricula: " << alumno.matricula << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Promedio: " << alumno.promedio << endl;

    return 0;
}