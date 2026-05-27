#include <iostream>
#include <string>
using namespace std;

const int N = 5;

// Función para mostrar los nodos del sistema
void mostrarNodos(string nodos[]) {
    cout << "\nNodos del sistema PAD-Bienestar:\n";
    for (int i = 0; i < N; i++) {
        cout << i << " = " << nodos[i] << endl;
    }
}

// Función para mostrar la matriz de adyacencia
void mostrarMatriz(int matriz[N][N]) {
    cout << "\nMatriz de conexiones:\n\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nNota: 1 significa que existe conexión directa.";
    cout << "\n      0 significa que no existe conexión directa.\n";
}

// Función para consultar si dos nodos están conectados
void consultarConexion(int matriz[N][N], string nodos[]) {
    int origen, destino;

    cout << "\nIngresa el número del primer nodo: ";
    cin >> origen;

    cout << "Ingresa el número del segundo nodo: ";
    cin >> destino;

    if (origen < 0 || origen >= N || destino < 0 || destino >= N) {
        cout << "\nError: los nodos deben estar entre 0 y " << N - 1 << ".\n";
        return;
    }

    if (matriz[origen][destino] == 1) {
        cout << "\nSí existe conexión directa entre "
             << nodos[origen] << " y " << nodos[destino] << ".\n";
    } else {
        cout << "\nNo existe conexión directa entre "
             << nodos[origen] << " y " << nodos[destino] << ".\n";
    }
}

int main() {
    int opcion;

    string nodos[N] = {
        "Router principal",
        "Equipo 1",
        "Equipo 2",
        "Zona de atención",
        "Servidor de bitácora"
    };

    /*
        Matriz de adyacencia del PAD-Bienestar.

        1 = existe conexión directa
        0 = no existe conexión directa
    */
    int matriz[N][N] = {
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };

    do {
        cout << "\n===== SIG-Conecta / PAD-Bienestar =====\n";
        cout << "1. Mostrar nodos del sistema\n";
        cout << "2. Mostrar matriz de conexiones\n";
        cout << "3. Consultar conexión entre dos nodos\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarNodos(nodos);
                break;

            case 2:
                mostrarMatriz(matriz);
                break;

            case 3:
                mostrarNodos(nodos);
                consultarConexion(matriz, nodos);
                break;

            case 4:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpción no válida. Intenta nuevamente.\n";
        }

    } while (opcion != 4);

    return 0;
}