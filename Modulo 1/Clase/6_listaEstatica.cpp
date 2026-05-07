/*
    EJERCICIO 6: LISTA ESTATICA

    Este programa simula una lista estática de productos con capacidad máxima
    de 5 elementos. Permite agregar productos y mostrarlos.

    Temas principales:
    - Lista estática
    - Arreglo de tamaño fijo
    - Menú con do while
    - Validación de lista llena y lista vacía
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Lista estatica con capacidad maxima de 5 productos
    string productos[5];

    // Cantidad indica cuantos productos se han agregado
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
                // Validamos que la lista no este llena
                if (cantidad < 5) {
                    cout << "Nombre del producto: ";
                    getline(cin, productos[cantidad]);

                    // Aumentamos la cantidad de productos registrados
                    cantidad++;

                    cout << "Producto agregado correctamente." << endl;
                } else {
                    cout << "La lista esta llena. No se pueden agregar mas productos." << endl;
                }
                break;

            case 2:
                // Validamos si la lista está vacía
                if (cantidad == 0) {
                    cout << "La lista esta vacia." << endl;
                } else {
                    cout << "PRODUCTOS REGISTRADOS" << endl;

                    for (int i = 0; i < cantidad; i++) {
                        cout << i + 1 << ". " << productos[i] << endl;
                    }
                }
                break;

            case 3:
                cout << "Fin del programa." << endl;
                break;

            default:
                cout << "Opcion no valida." << endl;
        }

    } while (opcion != 3);

    return 0;
}