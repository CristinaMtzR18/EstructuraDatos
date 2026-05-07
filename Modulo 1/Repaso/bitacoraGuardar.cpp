#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string nombre;
    string accion;
    string hora;
    int cantidad;

    // ofstream permite escribir en archivos
    ofstream archivo;

    cout << "REGISTRO DE BITACORA EN ARCHIVO" << endl;

    cout << "Cuantos eventos deseas registrar?: ";
    cin >> cantidad;

    cin.ignore();

    // Abrimos el archivo en modo escritura
    archivo.open("bitacora.txt");

    // Verificamos si el archivo se abrio correctamente
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    for (int i = 0; i < cantidad; i++) {
        cout << endl;
        cout << "Evento " << i + 1 << endl;

        cout << "Nombre del usuario: ";
        getline(cin, nombre);

        cout << "Accion realizada: ";
        getline(cin, accion);

        cout << "Hora: ";
        getline(cin, hora);

        // Escribimos el evento dentro del archivo
        archivo << nombre << " | " << accion << " | " << hora << endl;
    }

    // Cerramos el archivo para guardar correctamente la informacion
    archivo.close();

    cout << endl;
    cout << "La bitacora fue guardada correctamente en el archivo bitacora.txt" << endl;

    return 0;
}