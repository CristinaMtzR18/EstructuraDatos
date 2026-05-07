#include <iostream>
#include <string>
using namespace std;

int main() {
    string productos[5];
    int cantidad = 0;
    int opcion;

    do {
        cout << endl;
        cout << "LISTA ESTATICA DE PRODUCTOS" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        cin.ignore();

        switch (opcion) {
            case 1:
                // Verificamos si la lista ya esta llena
                if (cantidad < 5) {
                    cout << "Ingresa el nombre del producto: ";
                    getline(cin, productos[cantidad]);

                    // Aumentamos la cantidad de productos registrados
                    cantidad++;

                    cout << "Producto agregado correctamente." << endl;
                } else {
                    cout << "La lista esta llena. No se pueden agregar mas productos." << endl;
                }
                break;

            case 2:
                if (cantidad == 0) {
                    cout << "La lista esta vacia." << endl;
                } else {
                    cout << "Productos registrados:" << endl;

                    for (int i = 0; i < cantidad; i++) {
                        cout << i + 1 << ". " << productos[i] << endl;
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