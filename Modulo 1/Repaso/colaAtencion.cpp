#include <iostream>
#include <string>
using namespace std;

int main() {
    string cola[5];
    int frente = 0;
    int final = 0;
    int cantidad = 0;
    int opcion;

    do {
        cout << endl;
        cout << "COLA DE TURNOS PAD-BIENESTAR" << endl;
        cout << "1. Agregar persona a la cola" << endl;
        cout << "2. Atender primera persona" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                // Verificamos si la cola tiene espacio
                if (cantidad < 5) {
                    cout << "Ingresa el nombre de la persona: ";
                    getline(cin, cola[final]);

                    final++;
                    cantidad++;

                    cout << "Persona agregada a la cola." << endl;
                } else {
                    cout << "La cola esta llena." << endl;
                }
                break;

            case 2:
                // Verificamos si la cola no esta vacia
                if (cantidad > 0) {
                    cout << "Atendiendo a: " << cola[frente] << endl;

                    frente++;
                    cantidad--;
                } else {
                    cout << "La cola esta vacia." << endl;
                }
                break;

            case 3:
                if (cantidad > 0) {
                    cout << "Personas en espera:" << endl;

                    for (int i = frente; i < final; i++) {
                        cout << cola[i] << endl;
                    }
                } else {
                    cout << "No hay personas en la cola." << endl;
                }
                break;

            case 4:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}