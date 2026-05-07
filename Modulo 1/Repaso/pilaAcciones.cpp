#include <iostream>
#include <string>
using namespace std;

int main() {
    string pila[5];
    int tope = -1;
    int opcion;

    do {
        cout << endl;
        cout << "PILA DE ACCIONES - FUNCION DESHACER" << endl;
        cout << "1. Apilar accion" << endl;
        cout << "2. Desapilar ultima accion" << endl;
        cout << "3. Ver accion del tope" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                // Verificamos si la pila tiene espacio
                if (tope < 4) {
                    tope++;

                    cout << "Ingresa la accion realizada: ";
                    getline(cin, pila[tope]);

                    cout << "Accion apilada correctamente." << endl;
                } else {
                    cout << "La pila esta llena." << endl;
                }
                break;

            case 2:
                // Verificamos si la pila no esta vacia
                if (tope >= 0) {
                    cout << "Se deshizo la accion: " << pila[tope] << endl;
                    tope--;
                } else {
                    cout << "La pila esta vacia. No hay acciones para deshacer." << endl;
                }
                break;

            case 3:
                if (tope >= 0) {
                    cout << "Accion en el tope: " << pila[tope] << endl;
                } else {
                    cout << "La pila esta vacia." << endl;
                }
                break;

            case 4:
                if (tope >= 0) {
                    cout << "Contenido de la pila:" << endl;

                    // Se muestra desde el tope hacia abajo
                    for (int i = tope; i >= 0; i--) {
                        cout << pila[i] << endl;
                    }
                } else {
                    cout << "La pila esta vacia." << endl;
                }
                break;

            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 5);

    return 0;
}