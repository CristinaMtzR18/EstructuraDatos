#include <iostream>
#include <string>

using namespace std;

// Constantes generales
const int TOTAL_EQUIPOS = 12;
const int TOTAL_NODOS = 12;

// =====================================================
// GESTION DE SESIONES ACTIVAS
// =====================================================

struct Sesion {
    int numeroEquipo;
    Sesion* siguiente;
};

Sesion* listaSesiones = nullptr;

// Valida que el equipo este entre 1 y 12
bool validarEquipo(int numero) {
    return numero >= 1 && numero <= TOTAL_EQUIPOS;
}

// Verifica si ya existe una sesion en el equipo
bool existeSesion(int numero) {
    Sesion* actual = listaSesiones;

    while (actual != nullptr) {
        if (actual->numeroEquipo == numero) {
            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}

// Dar de alta una sesion
void altaSesion(int numero) {
    if (!validarEquipo(numero)) {
        cout << "\nError: el numero de equipo debe estar entre 1 y 12.\n";
        return;
    }

    if (existeSesion(numero)) {
        cout << "\nYa existe una sesion activa en el equipo " << numero << ".\n";
        return;
    }

    Sesion* nuevo = new Sesion;
    nuevo->numeroEquipo = numero;
    nuevo->siguiente = listaSesiones;
    listaSesiones = nuevo;

    cout << "\nSesion registrada en el equipo " << numero << ".\n";
}

// Dar de baja una sesion
void bajaSesion(int numero) {
    if (listaSesiones == nullptr) {
        cout << "\nNo hay sesiones activas.\n";
        return;
    }

    if (!validarEquipo(numero)) {
        cout << "\nError: el numero de equipo debe estar entre 1 y 12.\n";
        return;
    }

    Sesion* actual = listaSesiones;
    Sesion* anterior = nullptr;

    while (actual != nullptr && actual->numeroEquipo != numero) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "\nNo se encontro sesion activa en el equipo " << numero << ".\n";
        return;
    }

    if (anterior == nullptr) {
        listaSesiones = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;

    cout << "\nSesion finalizada en el equipo " << numero << ".\n";
}

// Mostrar sesiones activas
void mostrarSesiones() {
    if (listaSesiones == nullptr) {
        cout << "\nNo hay sesiones activas.\n";
        return;
    }

    Sesion* actual = listaSesiones;

    cout << "\nSesiones activas:\n";

    while (actual != nullptr) {
        cout << "[Equipo " << actual->numeroEquipo << "] -> ";
        actual = actual->siguiente;
    }

    cout << "NULL\n";
}

// Liberar memoria antes de salir
void liberarSesiones() {
    Sesion* actual = listaSesiones;

    while (actual != nullptr) {
        Sesion* borrar = actual;
        actual = actual->siguiente;
        delete borrar;
    }

    listaSesiones = nullptr;
}

// Menu de sesiones
void menuSesiones() {
    int opcion;
    int numero;

    do {
        cout << "\n===== GESTION DE SESIONES ACTIVAS =====\n";
        cout << "1. Dar de alta una sesion\n";
        cout << "2. Dar de baja una sesion\n";
        cout << "3. Mostrar sesiones activas\n";
        cout << "4. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese numero de equipo (1-12): ";
                cin >> numero;
                altaSesion(numero);
                break;

            case 2:
                cout << "Ingrese numero de equipo a finalizar: ";
                cin >> numero;
                bajaSesion(numero);
                break;

            case 3:
                mostrarSesiones();
                break;

            case 4:
                cout << "\nRegresando al menu principal...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 4);
}

// =====================================================
// CONEXIONES DEL SISTEMA
// =====================================================

string nodos[TOTAL_NODOS] = {
    "Equipo 1",
    "Equipo 2",
    "Equipo 3",
    "Equipo 4",
    "Equipo 5",
    "Equipo 6",
    "Equipo 7",
    "Equipo 8",
    "Equipo 9",
    "Equipo 10",
    "Equipo 11",
    "Equipo 12"
};

/*
    Matriz de adyacencia de los 12 equipos PAD-Bienestar.

    1 = existe conexion directa
    0 = no existe conexion directa

    Esta matriz es dirigida y no simetrica.
*/
int matriz[TOTAL_NODOS][TOTAL_NODOS] = {
    // E1 E2 E3 E4 E5 E6 E7 E8 E9 E10 E11 E12
    { 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 }, // Equipo 1
    { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, // Equipo 2
    { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 }, // Equipo 3
    { 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }, // Equipo 4
    { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0 }, // Equipo 5
    { 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0 }, // Equipo 6
    { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 }, // Equipo 7
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 }, // Equipo 8
    { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0 }, // Equipo 9
    { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1 }, // Equipo 10
    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // Equipo 11
    { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }  // Equipo 12
};

// Valida que el nodo este entre 0 y 11
bool validarNodo(int nodo) {
    return nodo >= 0 && nodo < TOTAL_NODOS;
}

// Muestra los 12 equipos que forman parte del grafo
void mostrarNodos() {
    cout << "\nNodos del sistema PAD-Bienestar:\n";

    for (int i = 0; i < TOTAL_NODOS; i++) {
        cout << i << " = " << nodos[i] << endl;
    }

    cout << "\nNota: para consultar una conexion, usa el numero del nodo.\n";
    cout << "Ejemplo: 0 representa Equipo 1, 1 representa Equipo 2, etc.\n";
}

// Muestra la matriz de adyacencia de los 12 equipos
void mostrarMatriz() {
    cout << "\nMatriz de conexiones entre equipos:\n\n";

    cout << "     ";

    for (int i = 0; i < TOTAL_NODOS; i++) {
        cout << i << " ";
    }

    cout << endl;

    for (int i = 0; i < TOTAL_NODOS; i++) {
        if (i < 10) {
            cout << " " << i << " | ";
        } else {
            cout << i << " | ";
        }

        for (int j = 0; j < TOTAL_NODOS; j++) {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\n1 = existe conexion directa";
    cout << "\n0 = no existe conexion directa\n";
}

// Consulta si dos equipos tienen conexion directa
void consultarConexion() {
    int origen;
    int destino;

    mostrarNodos();

    cout << "\nIngresa el numero del primer nodo: ";
    cin >> origen;

    cout << "Ingresa el numero del segundo nodo: ";
    cin >> destino;

    if (!validarNodo(origen) || !validarNodo(destino)) {
        cout << "\nError: los nodos deben estar entre 0 y " << TOTAL_NODOS - 1 << ".\n";
        return;
    }

    if (matriz[origen][destino] == 1) {
        cout << "\nSi existe conexion directa de "
             << nodos[origen] << " hacia " << nodos[destino] << ".\n";
    } else {
        cout << "\nNo existe conexion directa de "
             << nodos[origen] << " hacia " << nodos[destino] << ".\n";
    }
}

// Menu de conexiones
void menuConexiones() {
    int opcion;

    do {
        cout << "\n===== CONEXIONES DEL SISTEMA =====\n";
        cout << "1. Mostrar nodos del sistema\n";
        cout << "2. Mostrar matriz de conexiones\n";
        cout << "3. Consultar conexion entre dos nodos\n";
        cout << "4. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarNodos();
                break;

            case 2:
                mostrarMatriz();
                break;

            case 3:
                consultarConexion();
                break;

            case 4:
                cout << "\nRegresando al menu principal...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 4);
}

// =====================================================
// ORDENAMIENTO Y BUSQUEDA DE EQUIPOS CON SESION ACTIVA
// =====================================================

// Copia los equipos con sesion activa a un arreglo
int llenarArregloSesionesActivas(int equiposActivos[]) {
    int cantidad = 0;
    Sesion* actual = listaSesiones;

    while (actual != nullptr && cantidad < TOTAL_EQUIPOS) {
        equiposActivos[cantidad] = actual->numeroEquipo;
        cantidad++;
        actual = actual->siguiente;
    }

    return cantidad;
}

// Muestra un arreglo de equipos activos
void mostrarEquiposActivos(int equipos[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nNo hay equipos con sesiones activas.\n";
        return;
    }

    cout << "\nEquipos con sesiones activas:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << equipos[i] << " ";
    }

    cout << endl;
}

// Ordena solo los equipos que tienen sesion activa
void ordenarBurbujaActivos(int equipos[], int cantidad) {
    int auxiliar;

    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (equipos[j] > equipos[j + 1]) {
                auxiliar = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = auxiliar;
            }
        }
    }

    cout << "\nEquipos activos ordenados correctamente con burbuja.\n";
}

// Busca un equipo dentro del arreglo ordenado de sesiones activas
int buscarBinariaActivos(int equipos[], int cantidad, int numeroBuscado) {
    int inicio = 0;
    int fin = cantidad - 1;

    while (inicio <= fin) {
        int mitad = (inicio + fin) / 2;

        if (equipos[mitad] == numeroBuscado) {
            return mitad;
        }

        if (numeroBuscado < equipos[mitad]) {
            fin = mitad - 1;
        } else {
            inicio = mitad + 1;
        }
    }

    return -1;
}

// Menu de ordenamiento y busqueda
void menuOrdenamientoBusqueda() {
    int opcion;
    int numeroBuscado;
    int posicion;

    int equiposActivos[TOTAL_EQUIPOS];
    int cantidadActivos = 0;
    bool estaOrdenado = false;

    do {
        cout << "\n===== ORDENAMIENTO Y BUSQUEDA DE EQUIPOS CON SESION ACTIVA =====\n";
        cout << "1. Mostrar equipos con sesiones activas\n";
        cout << "2. Ordenar equipos activos con metodo burbuja\n";
        cout << "3. Mostrar equipos activos ordenados\n";
        cout << "4. Buscar equipo activo con busqueda binaria\n";
        cout << "5. Regresar al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cantidadActivos = llenarArregloSesionesActivas(equiposActivos);
                mostrarEquiposActivos(equiposActivos, cantidadActivos);
                estaOrdenado = false;
                break;

            case 2:
                cantidadActivos = llenarArregloSesionesActivas(equiposActivos);

                if (cantidadActivos == 0) {
                    cout << "\nNo hay equipos activos para ordenar.\n";
                    break;
                }

                ordenarBurbujaActivos(equiposActivos, cantidadActivos);
                estaOrdenado = true;
                break;

            case 3:
                if (!estaOrdenado) {
                    cout << "\nPrimero debes ordenar los equipos activos.\n";
                } else {
                    mostrarEquiposActivos(equiposActivos, cantidadActivos);
                }
                break;

            case 4:
                if (!estaOrdenado) {
                    cout << "\nPrimero debes ordenar los equipos activos antes de buscar.\n";
                    break;
                }

                cout << "\nIngresa el numero de equipo a buscar (1-12): ";
                cin >> numeroBuscado;

                if (!validarEquipo(numeroBuscado)) {
                    cout << "\nError: el numero de equipo debe estar entre 1 y 12.\n";
                    break;
                }

                posicion = buscarBinariaActivos(equiposActivos, cantidadActivos, numeroBuscado);

                if (posicion != -1) {
                    cout << "\nEl equipo " << numeroBuscado << " SI tiene sesion activa.\n";
                    cout << "Posicion dentro del arreglo ordenado: " << posicion << endl;
                } else {
                    cout << "\nEl equipo " << numeroBuscado << " NO tiene sesion activa.\n";
                }

                break;

            case 5:
                cout << "\nRegresando al menu principal...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 5);
}

// =====================================================
// MENU PRINCIPAL
// =====================================================

int main() {
    int opcion;

    do {
        cout << "\n=====================================\n";
        cout << " SISTEMA INTEGRAL PAD-BIENESTAR\n";
        cout << "=====================================\n";
        cout << "1. Gestion de sesiones activas\n";
        cout << "2. Conexiones del sistema\n";
        cout << "3. Ordenamiento y busqueda de equipos\n";
        cout << "4. Salir del sistema\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuSesiones();
                break;

            case 2:
                menuConexiones();
                break;

            case 3:
                menuOrdenamientoBusqueda();
                break;

            case 4:
                liberarSesiones();
                cout << "\nSaliendo del sistema PAD-Bienestar...\n";
                break;

            default:
                cout << "\nOpcion invalida.\n";
        }

    } while (opcion != 4);

    return 0;
}