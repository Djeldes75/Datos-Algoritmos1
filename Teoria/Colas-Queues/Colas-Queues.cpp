/*
-------------------------------------------------------------------------------------------------------
Tarea: #4 - Colas (Queues)
Materia: IDS343-01-ESTRUCTURAS DE DATOS Y ALGORITMOS I (6-8pm)
-------------------------------------------------------------------------------------------------------
Una Cola (Queue) es una estructura de datos en donde el primero en entrar es el primero en salir. Para
nuestro caso, haremos el problema un poco mas complejo a�adi�ndole lo que se conoce como
prioridad. En los casos en que una Cola tiene prioridad se considera esta al momento de insertar un
nuevo nodo a la estructura. La Cola tiene la siguiente forma para los nodos:

struct Queue {
 int dato;
 Queue *next;
};

RESTRICCIONES:
    A. La Cola debe poder realizar las operaciones Enqueue y Dequeue.

    B. Las prioridades van de 0 a 16. En los casos que el usuario decida una prioridad m�s alta que 16 se
    considerara la default, y se insertara el nuevo nodo al final de la estructura.

    C. El programa deber� tener un menu con las opciones para Enqueue y Dequeue, adem�s de poder
    desplegar todos los elementos de la cola, provocando Dequeue de toda la estructura Cola.

    D. Las entradas de datos del usuario deben ser debidamente validas.

    E. El programas debe ser lo suficientemente especializado para informar al usuario cuando la cola esta
    vac�a.

INTEGRANTES (Grupo 6):
    Samira Jaquez - 1125467
    Dominique Jeldes - 1121623
    Enmanuel Carrasco - 1124404
    Juan Castillo - 1127310
    Sebastian Ventura - 1128066
    Elianyer Gomez - 1118021

Fecha: 30/05/2025

*/

#include <iostream>

using namespace std;

struct Queue {
    int dato;
    Queue* next;   // Puntero al siguiente nodo en la cola
};

// Array de 17 punteros a Queue que representa las colas de diferentes prioridades.
Queue* colas[17];

#pragma region Func. Auxi.

//Recorre e inicializa las 17(16) colas, y las inicia vacias
void inicializar() {

    for (int i = 0; i < 17; i++) {
        colas[i] = nullptr;
    }
}

/// <summary>
/// Verifica si todas las colas de prioridad est�n vac�as.
/// Recorre todas las colas y retorna false si encuentra alguna con elementos.
/// </summary>
/// <returns>true si todas las colas est�n vac�as, false en caso contrario</returns>
bool estaVacia() {
    // Revisa cada una de las 17 colas
    for (int i = 0; i < 17; i++) {
        if (colas[i] != nullptr) return false;  // Si encuentra una cola con elementos, no est� vac�a
    }
    return true;  // Todas las colas est�n vac�as
}

/// <summary>
/// Solicita al usuario que ingrese un n�mero entero con validaci�n de entrada.
/// Maneja errores de entrada y rechaza caracteres no num�ricos.
/// Si se ingresa un decimal, toma solo la parte entera autom�ticamente.
/// </summary>
/// <returns>N�mero entero v�lido ingresado por el usuario</returns>
int pedirNumero() {
    int valor;
    cout << "Ingrese un numero entero: ";

    // Ciclo de validaci�n: repite hasta obtener un n�mero v�lido
    while (!(cin >> valor)) {
        cout << "Error: Solo numeros enteros permitidos.\n";
        cin.clear();              // Limpia el estado de error de cin
        cin.ignore(1000, '\n');   // Descarta la entrada inv�lida del buffer
        cout << "Ingrese un numero entero: ";
    }
    cin.ignore(1000, '\n');  // Limpia el buffer despu�s de leer correctamente

    return valor;
}

/// <summary>
/// Solicita al usuario que ingrese un valor de prioridad (0-16) con validaci�n.
/// Similar a pedirNumero() pero espec�fico para prioridades.
/// </summary>
/// <returns>N�mero entero que representa la prioridad deseada</returns>
int pedirPrioridad() {
    int prioridad;
    cout << "Prioridad (0-16): ";

    // Ciclo de validaci�n para la prioridad
    while (!(cin >> prioridad)) {
        cout << "Error: Solo numeros enteros permitidos.\n";
        cin.clear();              // Limpia el estado de error
        cin.ignore(1000, '\n');   // Descarta entrada inv�lida
        cout << "Prioridad (0-16): ";
    }
    cin.ignore(1000, '\n');  // Limpia el buffer

    return prioridad;
}

#pragma endregion

#pragma region OPERACIONES PRINCIPALES

/// <summary>
/// Operaci�n Enqueue: Inserta un nuevo elemento en la cola con prioridad especificada.
/// Crea un nuevo nodo, solicita datos al usuario y lo inserta en la cola correspondiente.
/// Si la prioridad est� fuera del rango 0-16, usa prioridad 16 (default/final).
/// </summary>
void enqueue() {
    // Crear nuevo nodo din�micamente
    Queue* nuevo = new Queue;

    // Solicitar datos al usuario
    cout << "Dato: ";
    nuevo->dato = pedirNumero();

    // Solicitar prioridad
    int prioridad = pedirPrioridad();

    // Validar rango de prioridad (0-16)
    if (prioridad < 0 || prioridad > 16) {
        cout << "Prioridad invalida. Usando 16 (final).\n";
        prioridad = 16;  // Usar prioridad default
    }

    nuevo->next = nullptr;  // El nuevo nodo no apunta a nada inicialmente

    // Insertar en la cola correspondiente a la prioridad
    if (colas[prioridad] == nullptr) {
        // Si la cola est� vac�a, el nuevo nodo es el primero
        colas[prioridad] = nuevo;
    }
    else {
        // Si la cola tiene elementos, agregar al final (FIFO dentro de la misma prioridad)
        Queue* temp = colas[prioridad];
        // Buscar el �ltimo nodo de esta cola
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Conectar el nuevo nodo al final
        temp->next = nuevo;
    }

    // Confirmar la inserci�n al usuario
    cout << "Insertado: " << nuevo->dato << " (Prioridad " << prioridad << ")\n";
}

/// <summary>
/// Operaci�n Dequeue: Elimina el elemento con mayor prioridad de la cola.
/// Busca la primera cola no vac�a (menor �ndice = mayor prioridad) y elimina su primer elemento.
/// Libera la memoria del nodo eliminado para evitar memory leaks.
/// </summary>
void dequeue() {
    // Verificar si hay elementos que eliminar
    if (estaVacia()) {
        cout << "Cola vacia. No se puede eliminar.\n";
        return;
    }

    // Buscar la primera cola con elementos (mayor prioridad)
    for (int i = 0; i < 17; i++) {
        if (colas[i] != nullptr) {
            // Guardar referencia al nodo a eliminar
            Queue* temp = colas[i];

            // Informar al usuario qu� se est� eliminando
            cout << "Eliminado: " << temp->dato << " (Prioridad " << i << ")\n";

            // Actualizar el puntero de la cola para que apunte al siguiente
            colas[i] = colas[i]->next;

            // Liberar la memoria del nodo eliminado
            delete temp;
            return;  // Salir despu�s de eliminar un elemento
        }
    }
}

#pragma endregion

#pragma region VISUALIZACION

/// <summary>
/// Muestra todos los elementos de todas las colas organizados por prioridad.
/// Recorre cada cola desde la prioridad 0 hasta la 16 y muestra su contenido.
/// No elimina elementos, solo los visualiza.
/// </summary>
void mostrar() {
    // Verificar si hay elementos que mostrar
    if (estaVacia()) {
        cout << "Cola vacia.\n";
        return;
    }

    cout << "\n=== CONTENIDO DE LA COLA ===\n";
    int contador = 1;  // Numeraci�n secuencial de elementos

    // Recorrer todas las colas de prioridad
    for (int i = 0; i < 17; i++) {
        Queue* temp = colas[i];  // Puntero temporal para recorrer la cola

        // Recorrer todos los nodos de esta cola espec�fica
        while (temp != nullptr) {
            cout << contador << ". Dato: " << temp->dato << " | Prioridad: " << i << "\n";
            temp = temp->next;  // Avanzar al siguiente nodo
            contador++;         // Incrementar numeraci�n
        }
    }
    cout << "============================\n";
}

/// <summary>
/// Vac�a completamente todas las colas eliminando todos los elementos en orden de prioridad.
/// Simula m�ltiples operaciones Dequeue hasta que todas las colas est�n vac�as.
/// Muestra cada elemento eliminado para que el usuario vea el proceso.
/// </summary>
void vaciarTodo() {
    // Verificar si hay elementos que eliminar
    if (estaVacia()) {
        cout << "Cola vacia.\n";
        return;
    }

    cout << "\n=== VACIANDO COLA COMPLETA ===\n";
    int contador = 1;  // Contador de elementos eliminados

    // Continuar eliminando hasta que todas las colas est�n vac�as
    while (!estaVacia()) {
        // Buscar la primera cola con elementos (mayor prioridad)
        for (int i = 0; i < 17; i++) {
            if (colas[i] != nullptr) {
                // Mostrar qu� se est� eliminando
                cout << contador << ". Eliminando: " << colas[i]->dato << " (Prioridad " << i << ")\n";

                // Guardar referencia al nodo a eliminar
                Queue* temp = colas[i];

                // Actualizar puntero de la cola
                colas[i] = colas[i]->next;

                // Liberar memoria
                delete temp;

                contador++;  // Incrementar contador
                break;       // Salir del for para buscar el siguiente elemento de mayor prioridad
            }
        }
    }
    cout << "Cola completamente vacia.\n";
}

#pragma endregion

#pragma region MENU

/// <summary>
/// Muestra el men� principal del programa con todas las opciones disponibles.
/// Presenta una interfaz clara y organizada para que el usuario elija la operaci�n deseada.
/// </summary>
void menu() {
    cout << "=================================\n";
    cout << "       Cola con Prioridad\n";
    cout << "---------------------------------\n";
    cout << "Prioridades: 0 (alta) a 16 (baja)\n";
    cout << "=================================\n";
    cout << "1. Enqueue (Insertar)\n";
    cout << "2. Dequeue (Eliminar)\n";
    cout << "3. Mostrar cola\n";
    cout << "4. Vaciar cola completa\n";
    cout << "5. Salir\n";
    cout << "=================================\n";
    cout << "Opcion: ";
}

/// <summary>
/// Solicita al usuario que seleccione una opci�n del men� con validaci�n de entrada.
/// Maneja entradas inv�lidas y asegura que se ingrese un n�mero entero.
/// </summary>
/// <returns>N�mero entero representando la opci�n seleccionada por el usuario</returns>
int pedirOpcion() {

    int opcion;
    // Validar entrada hasta obtener un n�mero v�lido
    while (!(cin >> opcion)) {
        cout << "Error: Solo numeros enteros permitidos.\n";
        cin.clear();              // Limpiar estado de error
        cin.ignore(1000, '\n');   // Descartar entrada inv�lida
        cout << "Opcion: ";
    }
    cin.ignore(1000, '\n');  // Limpiar buffer
    return opcion;
}

#pragma endregion

#pragma region MAIN xd

int main() {
    
    inicializar();

    int opcion;

    do {

        menu();                    
        opcion = pedirOpcion();    

        
        switch (opcion) {

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            mostrar();
            break;

        case 4:
            vaciarTodo();
            break;

        case 5:
            
            //Limpia la memory por que no esta de grati'
            for (int i = 0; i < 17; i++) {

                while (colas[i] != nullptr) {

                    Queue* temp = colas[i];

                    colas[i] = colas[i]->next;

                    delete temp;
                }
            }
            cout << "Programa terminado.\n";
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo.\n";
        }

        // Pausa para que el usuario vea los resultados antes del siguiente men�
        if (opcion != 5) {
            cout << "\nPresione Enter para continuar...";
            cin.get();
        }

    } while (opcion != 5);

    return 0;
}

#pragma endregion