/*
    EJERCICIO 8: COLA

    Este programa simula una cola de turnos de atención.
    La primera persona que entra es la primera persona que será atendida.

    Temas principales:
    - Cola estática
    - Principio FIFO
    - Operación enqueue: agregar al final
    - Operación dequeue: atender desde el frente
    - Control de frente, final y cantidad
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Cola estatica con capacidad para 5 personas
    string cola[5];

    int frente = 0;
    int final = 0;
    int cantidad = 0;
    int opcion;

    do {
        cout << endl;
        cout << "COLA DE TURNOS" << endl;
        cout << "1. Agregar persona a la cola" << endl;
        cout << "2. Atender persona" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                // Validamos que la cola no este llena
                if (cantidad < 5) {
                    cout << "Nombre de la persona: ";
                    getline(cin, cola[final]);

                    // El final avanza porque ahí se agregará la siguiente persona
                    final++;

                    // Aumenta el número de personas en espera
                    cantidad++;

                    cout << "Persona agregada a la cola." << endl;
                } else {
                    cout << "La cola esta llena." << endl;
                }
                break;

            case 2:
                // Validamos que haya personas en la cola
                if (cantidad > 0) {
                    cout << "Atendiendo a: " << cola[frente] << endl;

                    // El frente avanza hacia la siguiente persona
                    frente++;

                    // Disminuye el número de personas en espera
                    cantidad--;
                } else {
                    cout << "La cola esta vacia." << endl;
                }
                break;

            case 3:
                if (cantidad > 0) {
                    cout << "PERSONAS EN ESPERA" << endl;

                    for (int i = frente; i < final; i++) {
                        cout << cola[i] << endl;
                    }
                } else {
                    cout << "No hay personas esperando." << endl;
                }
                break;

            case 4:
                cout << "Fin del programa." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}