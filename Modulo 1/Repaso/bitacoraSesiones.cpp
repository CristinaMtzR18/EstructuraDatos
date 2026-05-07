#include <iostream>
#include <string>
using namespace std;

struct Sesion {
    int idUsuario;
    string nombre;
    string horaInicio;
    int equipo;
};

int main() {
    Sesion sesiones[5];
    int cantidad = 0;
    int opcion;

    do {
        cout << endl;
        cout << "BITACORA DE SESIONES ACTIVAS PAD-BIENESTAR" << endl;
        cout << "1. Registrar sesion" << endl;
        cout << "2. Mostrar sesiones activas" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                // Verificamos que aun haya espacio para registrar sesiones
                if (cantidad < 5) {
                    cout << "ID de usuario: ";
                    cin >> sesiones[cantidad].idUsuario;

                    cin.ignore();

                    cout << "Nombre del usuario: ";
                    getline(cin, sesiones[cantidad].nombre);

                    cout << "Hora de inicio: ";
                    getline(cin, sesiones[cantidad].horaInicio);

                    cout << "Equipo asignado: ";
                    cin >> sesiones[cantidad].equipo;

                    cantidad++;

                    cout << "Sesion registrada correctamente." << endl;
                } else {
                    cout << "Ya no se pueden registrar mas sesiones activas." << endl;
                }
                break;

            case 2:
                if (cantidad == 0) {
                    cout << "No hay sesiones registradas." << endl;
                } else {
                    cout << endl;
                    cout << "SESIONES ACTIVAS" << endl;

                    for (int i = 0; i < cantidad; i++) {
                        cout << "Sesion " << i + 1 << endl;
                        cout << "ID: " << sesiones[i].idUsuario << endl;
                        cout << "Nombre: " << sesiones[i].nombre << endl;
                        cout << "Hora de inicio: " << sesiones[i].horaInicio << endl;
                        cout << "Equipo: " << sesiones[i].equipo << endl;
                        cout << "------------------------" << endl;
                    }
                }
                break;

            case 3:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 3);

    return 0;
}