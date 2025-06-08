/*
-------------------------------------------------------------------------------------------------------
Tarea: #4 - Lista Enlazada (Linked List)
Materia: IDS343-01-ESTRUCTURAS DE DATOS Y ALGORITMOS I (6-8pm)
-------------------------------------------------------------------------------------------------------
Una Lista Enlazada (Linked List) es una estructura de datos en donde cada nodo apunta a uno siguiente
y de esta manera se mantiene un enlace entre los nodos. Para nuestro caso, haremos el problema un poco
m�s real exigiendo que al insertar cada nodo, este se inserte de manera ordenada (ascendente) de modo
que los nodos se indexen seg�n su dato. La Lista Enlazada (Linked List) tiene la siguiente forma
para los nodos:

struct LinkedList {
 int dato;
 LinkedList *next;
};

RESTRICCIONES:
    A. La Lista Enlazada (Linked List) debe poder realizar las operaciones Insertar, Buscar,
       Eliminar y Mostrar la Lista Enlazada.

    B. Al insertar un nuevo nodo el programa debe contemplar realizar la inserci�n del nodo donde le
       corresponda, ya que la lista debe estar ordenada en forma ascendente seg�n su dato.

    C. El programa deber� tener un men� con las opciones para Insertar, Buscar, Eliminar y
       Mostrar la Lista Enlazada y Salir.

    D. Las entradas de datos del usuario deben ser debidamente validas.

    E. El programa debe ser lo suficientemente especializado para informar al usuario cuando la
       Lista Enlazada (Linked List) est� vac�a.

INTEGRANTES (Grupo 6):
    Samira Jaquez - 1125467
    Dominique Jeldes - 1121623
    Enmanuel Carrasco - 1124404
    Juan Castillo - 1127310
    Sebastian Ventura - 1128066
    Elianyer Gomez - 1118021

Fecha: 5/Diciembre/2022

*/

#include <iostream>

using namespace std;

struct LinkedList {
    int dato;
    LinkedList* next;
};

// Puntero al primer nodo de la lista
LinkedList* cabeza = nullptr;

#pragma region Funciones Auxiliares

//Verificar si la Lista Esta Vacia
bool estaVacia() {
    return cabeza == nullptr;
}

//Validar Input del Usuario - Numero Entero
int pedirNumero() {

    double numero;
    int numeroEntero;

    cout << "Ingrese un numero: ";

    while (true) {
        if (cin >> numero) {

            if (numero == (int)numero) {
                numeroEntero = (int)numero;
                cin.ignore(1000, '\n'); // Limpiar buffer
                break;
            }
            else {
                cout << "ERROR: No se permiten decimales. Solo numeros enteros." << endl;
            }
        }
        else {
            cout << "ERROR: Entrada invalida. Solo numeros." << endl;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nVuelva a ingresar un numero: ";
    }

    return numeroEntero;
}

#pragma endregion

#pragma region Operaciones de Lista Enlazada

//Insertar Elemento de Manera Ordenada (Ascendente)
void insertar() {

    LinkedList* nuevo = new LinkedList;
    nuevo->dato = pedirNumero();
    nuevo->next = nullptr;

    // Si la lista est� vac�a o el nuevo dato es menor que el primer elemento
    if (estaVacia() || nuevo->dato < cabeza->dato) {
        nuevo->next = cabeza;
        cabeza = nuevo;
        cout << "\nElemento " << nuevo->dato << " insertado al inicio de la lista.\n\n";
        return;
    }

    // Buscar la posici�n correcta para insertar
    LinkedList* actual = cabeza;
    LinkedList* anterior = nullptr;

    while (actual != nullptr && actual->dato < nuevo->dato) {
        anterior = actual;
        actual = actual->next;
    }

    // Verificar si el elemento ya existe
    if (actual != nullptr && actual->dato == nuevo->dato) {
        cout << "\nERROR: El elemento " << nuevo->dato << " ya existe en la lista.\n\n";
        delete nuevo;
        return;
    }

    // Insertar el nuevo nodo en la posici�n correcta
    anterior->next = nuevo;
    nuevo->next = actual;

    cout << "\nElemento " << nuevo->dato << " insertado correctamente en la lista.\n\n";
}
//Fin de Func. insertar

//Buscar Elemento en la Lista
void buscar() {

    if (estaVacia()) {
        cout << "\nLista vacia.\n\n";
        return;
    }

    int valor = pedirNumero();
    LinkedList* temp = cabeza;
    int posicion = 1;

    while (temp != nullptr) {
        if (temp->dato == valor) {
            cout << "\nElemento " << valor << " encontrado en la posicion " << posicion << ".\n\n";
            return;
        }
        temp = temp->next;
        posicion++;
    }

    cout << "\nElemento " << valor << " no encontrado en la lista.\n\n";
}
//Fin de Func. buscar

//Eliminar Elemento de la Lista
void eliminar() {

    if (estaVacia()) {
        cout << "\nLista vacia.\n\n";
        return;
    }

    int valor = pedirNumero();

    // Si el elemento a eliminar es el primero
    if (cabeza->dato == valor) {
        LinkedList* temp = cabeza;
        cabeza = cabeza->next;
        delete temp;
        cout << "\nElemento " << valor << " eliminado de la lista.\n\n";
        return;
    }

    // Buscar el elemento en el resto de la lista
    LinkedList* actual = cabeza;
    LinkedList* anterior = nullptr;

    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->next;
    }

    if (actual == nullptr) {
        cout << "\nElemento " << valor << " no encontrado en la lista.\n\n";
        return;
    }

    // Eliminar el nodo encontrado
    anterior->next = actual->next;
    delete actual;
    cout << "\nElemento " << valor << " eliminado de la lista.\n\n";
}
//Fin de Func. eliminar

//Mostrar Todos los Elementos de la Lista
void mostrar() {

    if (estaVacia()) {
        cout << "\nLista vacia.\n\n";
        return;
    }

    cout << "\n=== CONTENIDO DE LA LISTA ENLAZADA ===\n";
    LinkedList* temp = cabeza;
    int contador = 1;

    while (temp != nullptr) {
        cout << contador << ". " << temp->dato << "\n";
        temp = temp->next;
        contador++;
    }
    cout << "=====================================\n\n";
}

#pragma endregion

#pragma region MENU

//Mostrar Menu Principal
void menu() {
    cout << "=======================================\n";
    cout << "       Lista Enlazada (Linked List)\n";
    cout << "=======================================\n";
    cout << "1. Insertar\n";
    cout << "2. Buscar\n";
    cout << "3. Eliminar\n";
    cout << "4. Mostrar Lista\n";
    cout << "5. Salir\n";
    cout << "=======================================\n";
    cout << "Opcion: ";
}
//Fin de Func. Menu

//Validar Input del Usuario - Opcion de Menu
int pedirOpcion() {

    double opcion;
    int opcionEntera;

    while (true) {

        if (cin >> opcion) {

            if (opcion == (int)opcion) {
                opcionEntera = (int)opcion;
                cin.ignore(1000, '\n');
                break;
            }
            else {
                cout << "Error: Solo numeros enteros permitidos.\n";
            }
        }
        else {
            cout << "Error: Entrada invalida. Solo numeros.\n";
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nVuelva a ingresar una opcion: ";

    }
    return opcionEntera;
}
//Fin de Func. pedirOpcion

#pragma endregion

#pragma region MAIN

int main() {

    int opcion;

    do {

        menu();
        opcion = pedirOpcion();

        switch (opcion) {

        case 1:
            insertar();
            break;

        case 2:
            buscar();
            break;

        case 3:
            eliminar();
            break;

        case 4:
            mostrar();
            break;

        case 5:
            // Limpiar memoria antes de salir
            while (cabeza != nullptr) {
                LinkedList* temp = cabeza;
                cabeza = cabeza->next;
                delete temp;
            }
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "ERROR: Opcion invalida. Intente nuevamente.\n\n";
        }

    } while (opcion != 5);

    return 0;
}

#pragma endregion