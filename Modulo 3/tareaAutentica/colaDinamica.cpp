#include <iostream>

using namespace std;

// 1. DEFINICIÓN DEL NODO
// Cada nodo representa un turno dentro de la cola
struct Turno {
    int numeroTurno;      // Dato: número de turno registrado
    Turno* siguiente;     // Apuntador al siguiente turno en la cola
};

// 2. FUNCIÓN PARA VALIDAR EL TURNO
// Se valida que el número de turno sea positivo
bool validarTurno(int numero) {
    return numero > 0;
}

// 3. AGREGAR TURNO A LA COLA
// Esta función inserta un nuevo turno al final de la cola
void agregarTurno(Turno** frente, Turno** final, int numero) {
    if (!validarTurno(numero)) {
        cout << "Error: El numero de turno debe ser mayor que 0." << endl;
        return;
    }

    // Se reserva memoria dinámica para un nuevo nodo
    Turno* nuevo = new Turno;

    // Se asignan los datos al nuevo nodo
    nuevo->numeroTurno = numero;
    nuevo->siguiente = nullptr;

    // Si la cola está vacía, el nuevo nodo será el primero y el último
    if (*frente == nullptr) {
        *frente = nuevo;
        *final = nuevo;
    } else {
        // Si ya hay turnos, el último nodo apunta al nuevo
        (*final)->siguiente = nuevo;

        // Ahora el nuevo nodo se convierte en el final de la cola
        *final = nuevo;
    }

    cout << "Turno " << numero << " agregado a la cola." << endl;
}

// 4. ATENDER TURNO
// Esta función elimina el primer nodo de la cola, respetando FIFO
void atenderTurno(Turno** frente, Turno** final) {
    // Validar si la cola está vacía
    if (*frente == nullptr) {
        cout << "No hay turnos en espera. La cola esta vacia." << endl;
        return;
    }

    // El nodo que se va a atender es el primero de la cola
    Turno* auxiliar = *frente;

    cout << "Atendiendo al turno " << auxiliar->numeroTurno << "." << endl;

    // El frente avanza al siguiente nodo
    *frente = (*frente)->siguiente;

    // Si después de avanzar ya no hay nodos, también se limpia el final
    if (*frente == nullptr) {
        *final = nullptr;
    }

    // Se libera la memoria del turno atendido
    delete auxiliar;
}

// 5. MOSTRAR COLA DE TURNOS
// Esta función recorre la cola desde el frente hasta el final
void mostrarCola(Turno* frente) {
    Turno* actual = frente;

    if (actual == nullptr) {
        cout << "No hay turnos en espera. La cola esta vacia." << endl;
        return;
    }

    cout << "Cola de turnos en espera:" << endl;

    while (actual != nullptr) {
        cout << "[Turno " << actual->numeroTurno << "] -> ";
        actual = actual->siguiente;
    }

    cout << "NULL" << endl;
}

// 6. LIBERAR MEMORIA AL SALIR
// Esta función elimina todos los nodos que hayan quedado en la cola
void liberarCola(Turno** frente, Turno** final) {
    Turno* actual = *frente;

    while (actual != nullptr) {
        Turno* auxiliar = actual;
        actual = actual->siguiente;
        delete auxiliar;
    }

    *frente = nullptr;
    *final = nullptr;
}

// 7. MENÚ PRINCIPAL
int main() {
    Turno* frente = nullptr; // Apuntador al primer turno de la cola
    Turno* final = nullptr;  // Apuntador al último turno de la cola

    int opcion;
    int numero;

    do {
        cout << "\n--- MENU PAD-BIENESTAR ---" << endl;
        cout << "1. Agregar un turno" << endl;
        cout << "2. Atender un turno" << endl;
        cout << "3. Mostrar cola de turnos" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero de turno: ";
                cin >> numero;
                agregarTurno(&frente, &final, numero);
                break;

            case 2:
                atenderTurno(&frente, &final);
                break;

            case 3:
                mostrarCola(frente);
                break;

            case 4:
                cout << "Saliendo del sistema..." << endl;
                liberarCola(&frente, &final);
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }

    } while (opcion != 4);

    return 0;
}