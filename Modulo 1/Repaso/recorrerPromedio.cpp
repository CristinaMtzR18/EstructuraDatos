#include <iostream>
using namespace std;

int main() {
    float calificaciones[5];
    float suma = 0;
    float promedio;

    cout << "PROMEDIO DE CALIFICACIONES" << endl;

    // Capturamos las calificaciones
    for (int i = 0; i < 5; i++) {
        cout << "Ingresa la calificacion " << i + 1 << ": ";
        cin >> calificaciones[i];

        // Acumulamos cada calificacion en la variable suma
        suma = suma + calificaciones[i];
    }

    // Calculamos el promedio
    promedio = suma / 5;

    cout << endl;
    cout << "Calificaciones capturadas:" << endl;

    // Mostramos las calificaciones
    for (int i = 0; i < 5; i++) {
        cout << calificaciones[i] << " ";
    }

    cout << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Promedio final: " << promedio << endl;

    return 0;
}