#include <iostream>

using namespace std;

// 1. DEFINICIÓN DEL NODO
struct Sesion {
    int numeroEquipo;    // Dato: número de equipo (1-12)
    Sesion* siguiente;   // Apuntador al siguiente nodo
};

// 2. FUNCIÓN PARA VALIDAR EQUIPO (Requerimiento de la tarea)
bool validarEquipo(int numero) {
    return (numero >= 1 && numero <= 12);
}

// 3. DAR DE ALTA
void altaSesion(Sesion** lista, int numero) {
    if (!validarEquipo(numero)) {
        cout << "Error: Numero de equipo fuera de rango (1-12)." << endl;
        return;
    }

    // Uso de memoria dinámica con 'new' (Equivalente a malloc en C++)
    Sesion* nuevo = new Sesion; 
    nuevo->numeroEquipo = numero;
    nuevo->siguiente = *lista; // El nuevo nodo apunta al que era el primero
    *lista = nuevo;           // El inicio de la lista ahora es el nuevo nodo

    cout << "Sesion en equipo " << numero << " registrada." << endl;
}

// 4. DAR DE BAJA (Eliminación por valor)
void bajaSesion(Sesion** lista, int numero) {
    Sesion *actual = *lista;
    Sesion *anterior = nullptr;

    // Recorrido para buscar el nodo
    while (actual != nullptr && actual->numeroEquipo != numero) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        if (anterior == nullptr) {
            *lista = actual->siguiente; // Borrar el primero
        } else {
            // Se "salta" el nodo en la cadena
            anterior->siguiente = actual->siguiente; 
        }
        // Liberar memoria con 'delete' (Equivalente a free)
        delete actual; 
        cout << "Sesion en equipo " << numero << " finalizada." << endl;
    } else {
        cout << "No se encontro sesion activa en equipo " << numero << "." << endl;
    }
}

// 5. MOSTRAR SESIONES (Recorrido secuencial)
void mostrarSesiones(Sesion* lista) {
    Sesion* actual = lista;
    if (actual == nullptr) {
        cout << "No hay sesiones activas." << endl;
        return;
    }

    cout << "Sesiones activas: " << endl;
    while (actual != nullptr) {
        cout << "[Equipo " << actual->numeroEquipo << "] -> ";
        actual = actual->siguiente; // Avanzar al siguiente
    }
    cout << "NULL" << endl;
}

// 6. MENÚ PRINCIPAL
int main() {
    Sesion* listaPAD = nullptr; // Inicio de la lista vacío
    int opcion, numero;

    do {
        cout << "\n--- MENU PAD-BIENESTAR ---" << endl;
        cout << "1. Dar de alta una sesion" << endl;
        cout << "2. Dar de baja una sesion" << endl;
        cout << "3. Mostrar sesiones activas" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese numero de equipo (1-12): ";
                cin >> numero;
                altaSesion(&listaPAD, numero);
                break;
            case 2:
                cout << "Ingrese numero de equipo a finalizar: ";
                cin >> numero;
                bajaSesion(&listaPAD, numero);
                break;
            case 3:
                mostrarSesiones(listaPAD);
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while(opcion != 4);

    return 0;
}