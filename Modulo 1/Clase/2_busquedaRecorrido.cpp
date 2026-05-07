/*
    EJERCICIO 2: BUSQUEDA Y RECORRIDO

    Este programa registra 5 calificaciones, las recorre para mostrarlas,
    calcula la suma y el promedio, y después permite buscar una calificación
    específica dentro del arreglo.

    Temas principales:
    - Recorrido de arreglos
    - Búsqueda lineal
    - Acumuladores
    - Uso de variable booleana
*/

#include <iostream>
using namespace std;

int main() {
    float calificaciones[5];
    float suma = 0;
    float promedio;
    float buscar;
    bool encontrado = false;

    cout << "BUSQUEDA Y RECORRIDO DE CALIFICACIONES" << endl;

    // Capturar calificaciones
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa la calificacion " << i + 1 << ": ";
        cin >> calificaciones[i];

        // Acumulamos la suma mientras recorremos el arreglo
        suma = suma + calificaciones[i];
    }

    // Calculamos el promedio general
    promedio = suma / 5;

    cout << endl;
    cout << "CALIFICACIONES CAPTURADAS" << endl;

    // Recorrido del arreglo para mostrar los datos
    for (int i = 0; i < 5; i++) {
        cout << "Calificacion " << i + 1 << ": " << calificaciones[i] << endl;
    }

    cout << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Promedio: " << promedio << endl;

    cout << endl;
    cout << "Ingresa la calificacion que deseas buscar: ";
    cin >> buscar;

    // Busqueda lineal: revisa elemento por elemento
    for (int i = 0; i < 5; i++) {
        if (calificaciones[i] == buscar) {
            cout << "La calificacion " << buscar << " se encontro en la posicion " << i << endl;
            encontrado = true;
        }
    }

    // Si después de recorrer todo el arreglo no se encontró el dato
    if (encontrado == false) {
        cout << "La calificacion no se encontro en el arreglo." << endl;
    }

    return 0;
}