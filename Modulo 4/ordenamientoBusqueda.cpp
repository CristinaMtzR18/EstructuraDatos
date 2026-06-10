#include <iostream>

using namespace std;

const int N = 12;

// Función para validar que el número de equipo esté en el rango permitido
bool validarEquipo(int numero) {
    return numero >= 1 && numero <= 12;
}

// Función para copiar los datos de un arreglo a otro
void copiarArreglo(int origen[], int destino[]) {
    for (int i = 0; i < N; i++) {
        destino[i] = origen[i];
    }
}

// Función para mostrar los equipos
void mostrarEquipos(int equipos[]) {
    cout << "\nEquipos PAD-Bienestar:\n";

    for (int i = 0; i < N; i++) {
        cout << equipos[i] << " ";
    }

    cout << endl;
}

// Función para ordenar los equipos usando el método burbuja
void ordenamientoBurbuja(int equipos[]) {
    int auxiliar;

    // El ciclo externo controla las pasadas
    for (int i = 0; i < N - 1; i++) {

        // El ciclo interno compara elementos consecutivos
        for (int j = 0; j < N - i - 1; j++) {

            // Si el elemento actual es mayor que el siguiente, se intercambian
            if (equipos[j] > equipos[j + 1]) {
                auxiliar = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = auxiliar;
            }
        }
    }

    cout << "\nLos equipos fueron ordenados correctamente con burbuja.\n";
}

// Función para buscar un equipo usando búsqueda binaria
int busquedaBinaria(int equipos[], int numeroBuscado) {
    int inicio = 0;
    int fin = N - 1;

    while (inicio <= fin) {
        int mitad = (inicio + fin) / 2;

        if (equipos[mitad] == numeroBuscado) {
            return mitad;
        } else if (numeroBuscado < equipos[mitad]) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }

    return -1;
}

int main() {
    int opcion;
    int numeroBuscado;
    int posicion;

    /*
        Arreglo original de equipos.
        Se colocan desordenados para poder aplicar el método burbuja.
    */
    int equiposOriginales[N] = {7, 2, 11, 4, 1, 9, 12, 5, 3, 10, 6, 8};

    /*
        Arreglo que será ordenado.
        Esto permite conservar el arreglo original sin modificarlo.
    */
    int equiposOrdenados[N];

    bool estaOrdenado = false;

    copiarArreglo(equiposOriginales, equiposOrdenados);

    do {
        cout << "\n===== PAD-Bienestar / Ordenamiento y Busqueda =====\n";
        cout << "1. Mostrar equipos en orden original\n";
        cout << "2. Ordenar equipos con metodo burbuja\n";
        cout << "3. Mostrar equipos ordenados\n";
        cout << "4. Buscar equipo con busqueda binaria\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarEquipos(equiposOriginales);
                break;

            case 2:
                ordenamientoBurbuja(equiposOrdenados);
                estaOrdenado = true;
                break;

            case 3:
                if (estaOrdenado) {
                    mostrarEquipos(equiposOrdenados);
                } else {
                    cout << "\nPrimero debes ordenar los equipos con la opcion 2.\n";
                }
                break;

            case 4:
                if (!estaOrdenado) {
                    cout << "\nPrimero debes ordenar los equipos antes de usar busqueda binaria.\n";
                    break;
                }

                cout << "\nIngresa el numero de equipo a buscar (1-12): ";
                cin >> numeroBuscado;

                if (!validarEquipo(numeroBuscado)) {
                    cout << "\nError: el numero de equipo debe estar entre 1 y 12.\n";
                    break;
                }

                posicion = busquedaBinaria(equiposOrdenados, numeroBuscado);

                if (posicion != -1) {
                    cout << "\nEquipo encontrado.\n";
                    cout << "Numero de equipo: " << numeroBuscado << endl;
                    cout << "Posicion dentro del arreglo ordenado: " << posicion << endl;
                } else {
                    cout << "\nEl equipo no fue encontrado en el arreglo.\n";
                }

                break;

            case 5:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion no valida. Intenta nuevamente.\n";
        }

    } while (opcion != 5);

    return 0;
}