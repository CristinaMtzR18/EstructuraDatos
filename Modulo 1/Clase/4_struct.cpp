/*
    EJERCICIO 4: STRUCT

    Este programa registra los datos de un estudiante usando una estructura.
    Un struct permite agrupar varios datos relacionados, aunque sean de
    diferentes tipos.

    Temas principales:
    - Tipos definidos por el usuario
    - struct
    - Acceso a campos con el operador punto
    - Uso de getline para capturar texto completo
*/

#include <iostream>
#include <string>
using namespace std;

// Definimos una estructura llamada Estudiante
struct Estudiante {
    int matricula;
    string nombre;
    float promedio;
};

int main() {
    // Creamos una variable de tipo Estudiante
    Estudiante alumno;

    cout << "REGISTRO DE ESTUDIANTE" << endl;

    cout << "Ingresa la matricula: ";
    cin >> alumno.matricula;

    // Limpiamos el salto de linea antes de usar getline
    cin.ignore();

    cout << "Ingresa el nombre completo: ";
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