/*
-------------------------------------------------------------------------------------
Tarea: #2 - Pilas (Stacks)
Materia: IDS343-01-ESTRUCTURAS DE DATOS Y ALGORITMOS I (6-8pm)
-------------------------------------------------------------------------------------
Una pila (stack) es una estructura de datos en donde el �ltimo en entrar es el primero en salir.
Construir un programa C++ que simule una pila, utilizando una estructura de datos como la que
sigue para los nodos:

struct Pila {
 int dato;
 Pila *next;
};

RESTRICCIONES:
A. La pila debe poder realizar las operaciones de Push y Pop.
B. Tener en consideraci�n de desplegar un mensaje de "Empty Stack", cuando se trate de
hacer un Pop cuando la pila este vac�a.
C. El programa debe tener un men� para realizar las operaciones de Push, Pop y Desplegar
toda la pila realizando Pops hasta el �ltimo nodo. Adem�s, debe tener una opci�n de
salir del programa.

Nota: Este programa valida correctamente las entradas del usuario y maneja escenarios de errores para garantizar su robustez.

INTEGRANTES (Grupo 6):
    Samira Jaquez - 1125467
    Dominique Jeldes - 1121623
    Enmanuel Carrasco - 1124404
    Juan Castillo - 1127310
    Sebastian Ventura - 1128066
    Elianyer Gomez - 1118021

Fecha: 28/05/2025
*/

#include <iostream>

using namespace std;

//Estructura base
struct Pila {
    int dato; //Son 4 bytes en un sis. de 64
    Pila* next; //puntero llamado next, pesa 8 bytes.
};

//Variable global:
Pila* top = nullptr;

#pragma region Validacion

//Valida el numero pedido
int NumPedido() {

    double numero;
    int numeroEntero;

    cout << "\nIngrese un numero: ";

    while (true) {
        if (cin >> numero) {
            
            //Compara el numero(double) con su parte entera, si mismo
            if (numero == (int)numero) {
                //Si el numero no tiene decimales, lo convierte en ENTERO y lo guarda
                numeroEntero = (int)numero;
                break;
            }
            else {
                cout << "\nERROR: No se permiten decimales. Solo numeros enteros." << endl;
            }
        }
        else {
            cout << "\nERROR: Entrada invalida. Solo numeros." << endl;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nIngrese un numero: ";
    }

    return numeroEntero;
}


// Validaci�n del menu EN CASO de que el usuario escoga (0) o un numero mayor a (4)
int validarOpcionMenu() {

    int opcion;

    while (!(cin >> opcion)) {
        cout << "ERROR: Debe ingresar un numero entero valido." << endl;
        cout << "Seleccione una opcion: ";

        cin.clear();
        cin.ignore(1000, '\n');
    }

    return opcion;
}

#pragma endregion

#pragma region Push/Pop/Desplegar

// OPERACI�N PUSH - Agregar elemento a la pila
void push() {
    //Se ingresa el num. y dentro de esa funci�n se valida
    int valor = NumPedido();

    //Se crea un nuevo nodo COSA que se ocupa reservar un espacio dentro de la memoria, o llamado HEAP,
    Pila* nuevo = new Pila;

    nuevo->dato = valor;
    nuevo->next = top; //El nuevo nodo literalmente "apunta" al que era el tope o "top"

    //Se actualiza el nodo con el valor
    top = nuevo;

    cout << "Elemento " << valor << " agregado a la pila." << endl;
}

// OPERACI�N POP - Quitar elemento de la pila
void pop() {

    if (top == nullptr) {
        cout << "Empty Stack" << endl;
        return;
    }

    //Se guarda el valor que se quita (como temporal)
    int valor = top->dato;
    Pila* temp = top;

    //Y se mueve el top al siguiente elemento 
    top = top->next;

    //Elimina lo que estaba antes para liberar memoria
    delete temp;

    cout << "Elemento " << valor << " removido de la pila." << endl;
}

// DESPLEGAR TODA LA PILA
void DesplegarTodaPila() {

    if (top == nullptr) {
        cout << "Empty Stack" << endl;
        return;
    }

    cout << "\nDesplegando toda la pila:" << endl;

    while (top != nullptr) {
        cout << "Pop: " << top->dato << endl;

        Pila* temp = top;
        top = top->next;

        delete temp;
    }

    cout << "Pila completamente vaciada." << endl;
}

#pragma endregion

// MEN� PRINCIPAL
void mostrarMenu() {
    cout << "\n=== SIMULADOR DE PILA ===" << endl;
    cout << "1. Push (Agregar elemento)" << endl;
    cout << "2. Pop (Quitar elemento)" << endl;
    cout << "3. Desplegar toda la pila" << endl;
    cout << "4. Salir\n" << endl;
    cout << "Seleccione una opcion: ";
}

#pragma region Programa Principal

int main() {

    int opcion;

    cout << "PROGRAMA SIMULADOR DE PILA (STACK)" << endl;

    do {
        mostrarMenu();
        opcion = validarOpcionMenu();

        switch (opcion) {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            DesplegarTodaPila();
            break;

        case 4:
            cout << "\nSaliendo del programa..." << endl;

            // Liberar memoria restante antes de salir
            while (top != nullptr) {
                Pila* temp = top;
                top = top->next;
                delete temp;
            }
            break;

        default:
            cout << "\nERROR: Opcion invalida. Seleccione del 1 al 4." << endl;
            break;
        }

    } while (opcion != 4);

    return 0;
}

#pragma endregion