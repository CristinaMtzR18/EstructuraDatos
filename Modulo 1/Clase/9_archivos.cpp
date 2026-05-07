/*
    EJERCICIO 9: ARCHIVOS

    Este programa registra eventos y los guarda en un archivo de texto llamado
    bitacora.txt. Sirve para comprender la persistencia de datos.

    Temas principales:
    - Archivos en C++
    - ofstream
    - Escritura de datos en archivo
    - Persistencia
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string usuario;
    string accion;
    string hora;
    int cantidad;

    // ofstream permite escribir en archivos
    ofstream archivo;

    cout << "REGISTRO DE EVENTOS EN ARCHIVO" << endl;

    cout << "Cuantos eventos deseas registrar?: ";
    cin >> cantidad;

    cin.ignore();

    // Abrimos el archivo en modo escritura
    archivo.open("bitacora.txt");

    // Validamos que el archivo se haya abierto correctamente
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cout << "Evento " << i + 1 << endl;

        cout << "Nombre del usuario: ";
        getline(cin, usuario);

        cout << "Accion realizada: ";
        getline(cin, accion);

        cout << "Hora: ";
        getline(cin, hora);

        // Guardamos la informacion en el archivo
        archivo << usuario << " | " << accion << " | " << hora << endl;
    }

    // Cerramos el archivo para guardar correctamente la informacion
    archivo.close();

    cout << endl;
    cout << "Informacion guardada correctamente en bitacora.txt" << endl;

    return 0;
}