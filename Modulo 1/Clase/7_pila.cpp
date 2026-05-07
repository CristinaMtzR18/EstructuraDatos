/*
    EJERCICIO 7: PILA

    Este programa simula una pila de acciones para una función de deshacer.
    La última acción agregada será la primera en eliminarse.

    Temas principales:
    - Pila estática
    - Principio LIFO
    - Operación push: agregar al tope
    - Operación pop: quitar del tope
    - Consulta del tope
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Pila estatica con capacidad para 5 acciones
    string pila[5];

    // El tope empieza en -1 porque la pila esta vacia
    int tope = -1;
    int opcion;

    do {
        cout << endl;
        cout << "PILA DE ACCIONES - DESHACER" << endl;
        cout << "1. Agregar accion" << endl;
        cout << "2. Deshacer ultima accion" << endl;
        cout << "3. Ver accion del tope" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                // Validar que la pila no este llena
                if (tope < 4) {
                    // Primero subimos el tope
                    tope++;

                    // Luego guardamos la acción en la nueva posición del tope
                    cout << "Ingresa la accion: ";
                    getline(cin, pila[tope]);

                    cout << "Accion agregada al tope." << endl;
                } else {
                    cout << "La pila esta llena." << endl;
                }
                break;

            case 2:
                // Validar que la pila no este vacia
                if (tope >= 0) {
                    cout << "Se deshizo la accion: " << pila[tope] << endl;

                    // Al disminuir el tope, el ultimo elemento deja de considerarse activo
                    tope--;
                } else {
                    cout << "La pila esta vacia. No hay acciones para deshacer." << endl;
                }
                break;

            case 3:
                if (tope >= 0) {
                    cout << "Accion actual en el tope: " << pila[tope] << endl;
                } else {
                    cout << "La pila esta vacia." << endl;
                }
                break;

            case 4:
                if (tope >= 0) {
                    cout << "CONTENIDO DE LA PILA" << endl;

                    // Se muestra desde arriba hacia abajo
                    for (int i = tope; i >= 0; i--) {
                        cout << pila[i] << endl;
                    }
                } else {
                    cout << "La pila esta vacia." << endl;
                }
                break;

            case 5:
                cout << "Fin del programa." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 5);

    return 0;
}