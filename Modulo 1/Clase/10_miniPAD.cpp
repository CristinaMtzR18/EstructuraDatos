/*
    EJERCICIO 10: MINI CASO PAD-BIENESTAR

    Este programa simula un sistema básico para registrar sesiones activas
    en un Punto de Acceso Digital para el Bienestar.

    El sistema permite:
    1. Registrar sesiones activas.
    2. Mostrar las sesiones activas.
    3. Guardar las sesiones en un archivo de texto.
    4. Salir del sistema.

    Cada sesión guarda:
    - ID del usuario
    - Nombre del usuario
    - Hora de inicio
    - Equipo asignado

    Temas integrados:
    - struct
    - Arreglos de struct
    - Lista estática
    - Recorrido de arreglos
    - Menú con do while
    - Archivos con ofstream
    - Persistencia de datos

    Relación con PAD-Bienestar:
    Este ejercicio representa una solución mínima para organizar sesiones activas
    en un punto de atención con recursos limitados.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Estructura para representar una sesion activa
struct Sesion {
    int idUsuario;
    string nombre;
    string horaInicio;
    int equipo;
};

int main() {
    // Arreglo de estructuras para guardar maximo 5 sesiones
    Sesion sesiones[5];

    // Cantidad controla cuantas sesiones han sido registradas
    int cantidad = 0;

    // Opcion guarda la decisión del usuario en el menú
    int opcion;

    do {
        cout << endl;
        cout << "SISTEMA PAD-BIENESTAR" << endl;
        cout << "1. Registrar sesion activa" << endl;
        cout << "2. Mostrar sesiones activas" << endl;
        cout << "3. Guardar sesiones en archivo" << endl;
        cout << "4. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        // Limpia el salto de línea que queda después de leer la opción
        cin.ignore();

        switch (opcion) {
            case 1:
                /*
                    OPCION 1: REGISTRAR SESION

                    Aquí se capturan los datos de una sesión activa.
                    Primero se valida que todavía haya espacio disponible
                    en el arreglo.
                */

                if (cantidad < 5) {
                    cout << endl;
                    cout << "REGISTRO DE SESION" << endl;

                    cout << "ID de usuario: ";
                    cin >> sesiones[cantidad].idUsuario;

                    cin.ignore();

                    cout << "Nombre del usuario: ";
                    getline(cin, sesiones[cantidad].nombre);

                    cout << "Hora de inicio: ";
                    getline(cin, sesiones[cantidad].horaInicio);

                    cout << "Equipo asignado: ";
                    cin >> sesiones[cantidad].equipo;

                    // Se incrementa la cantidad porque ya se registró una nueva sesión
                    cantidad++;

                    cout << "Sesion registrada correctamente." << endl;
                } else {
                    cout << "No se pueden registrar mas sesiones. Capacidad maxima alcanzada." << endl;
                }
                break;

            case 2:
                /*
                    OPCION 2: MOSTRAR SESIONES ACTIVAS

                    Aquí se recorren las sesiones registradas y se muestran
                    en pantalla. Solo se recorren las posiciones ocupadas.
                */

                if (cantidad == 0) {
                    cout << "No hay sesiones activas registradas." << endl;
                } else {
                    cout << endl;
                    cout << "SESIONES ACTIVAS" << endl;

                    for (int i = 0; i < cantidad; i++) {
                        cout << "Sesion " << i + 1 << endl;
                        cout << "ID usuario: " << sesiones[i].idUsuario << endl;
                        cout << "Nombre: " << sesiones[i].nombre << endl;
                        cout << "Hora de inicio: " << sesiones[i].horaInicio << endl;
                        cout << "Equipo asignado: " << sesiones[i].equipo << endl;
                        cout << "-----------------------------" << endl;
                    }
                }
                break;

            case 3: {
                /*
                    OPCION 3: GUARDAR SESIONES EN ARCHIVO

                    Aquí se crea un archivo de texto y se guarda la información
                    de las sesiones registradas. Esto permite conservar la información
                    aunque el programa termine.
                */

                ofstream archivo;

                archivo.open("sesiones_pad_bienestar.txt");

                if (!archivo) {
                    cout << "Error al crear el archivo." << endl;
                } else {
                    archivo << "BITACORA DE SESIONES PAD-BIENESTAR" << endl;
                    archivo << "-----------------------------------" << endl;

                    for (int i = 0; i < cantidad; i++) {
                        archivo << "Sesion " << i + 1 << endl;
                        archivo << "ID usuario: " << sesiones[i].idUsuario << endl;
                        archivo << "Nombre: " << sesiones[i].nombre << endl;
                        archivo << "Hora de inicio: " << sesiones[i].horaInicio << endl;
                        archivo << "Equipo asignado: " << sesiones[i].equipo << endl;
                        archivo << "-----------------------------" << endl;
                    }

                    archivo.close();

                    cout << "Sesiones guardadas correctamente en sesiones_pad_bienestar.txt" << endl;
                }

                break;
            }

            case 4:
                cout << "Saliendo del sistema PAD-Bienestar..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    return 0;
}