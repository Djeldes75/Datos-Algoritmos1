/*
-------------------------------------------------------------------------------------------------------
Tarea: #5 - Gesti�n de un �rbol Binario de B�squeda
Materia: IDS343-01-ESTRUCTURAS DE DATOS Y ALGORITMOS I (6-8pm)
-------------------------------------------------------------------------------------------------------
    Realizar un programa C++ que permita gestionar un �rbol Binario de B�squeda. El programa
    debe permitir insertar, buscar y eliminar un nodo; adem�s de presentar (utilizando cualquiera
    de los recorridos) el �rbol de acuerdo a las reglas que existen para el �rbol binario de b�squeda.

    RESTRICCIONES:
    A. El primer nodo siempre ser� el root.

    B. Al presentar el �rbol debe ser de un modo intuitivo, que muestre la topolog�a de forma
    que represente en �rbol.

    C. Puede utilizar cualquiera de los recorridos para arboles (InOrden, PreOrden o
    PostOrden).

    D. Al eliminar un nodo debe observar las reglas para la sustituci�n del nodo, permitiendo
    as� que el �rbol se reconstruya.

    E. Al insertar un nodo deben observarse las reglas para arboles binarios de b�squeda, es
    decir, los nodos cuyo valor sea mayor que el nodo ra�z a la derecha (en el sub�rbol
    derecho), en caso contrario a la izquierda (en el sub�rbol izquierdo). Rec

INTEGRANTES (Grupo 6):
    Samira Jaquez - 1125467
    Dominique Jeldes - 1121623
    Enmanuel Carrasco - 1124404
    Juan Castillo - 1127310
    Sebastian Ventura - 1128066
    Elianyer Gomez - 1118021

Fecha: 14/Jun/2025

*/

#include <iostream>

using namespace std;

struct ArboLBST {
    int dato;
    ArboLBST* izquierda;
    ArboLBST* derecha;
};

//Variable global
ArboLBST* root = nullptr;


#pragma region Validaciones

//Validacion Universal para Enteros
int validarEntero(const char* mensaje) {

    int valor;
    char caracterSiguiente;
    bool entradaValida = false;

    cout << mensaje;

    while (!entradaValida) {

        if (cin >> valor) {

            caracterSiguiente = cin.peek();

            if (caracterSiguiente == '\n' || caracterSiguiente == ' ') {
                cin.ignore(10000, '\n');
                entradaValida = true;
            }
            else {
                cout << "ERROR: Entrada invalida.\nIntente nuevamente: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        else {
            cout << "ERROR: Entrada invalida.\nIntente nuevamente: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return valor;
}//FIN

//Validar Opcion del Menu
int leerOpcionMenu() {

    int opcion;
    bool opcionValida = false;

    while (!opcionValida) {

        opcion = validarEntero("");

        if (opcion >= 1 && opcion <= 4) {
            opcionValida = true;
        }
        else {
            cout << "ERROR: Opcion invalida. Intente nuevamente (1-4): ";
        }
    }

    return opcion;
}//FIN

//Validar Dato
int leerDato() {
    return validarEntero("Ingrese un numero: ");
}//FIN

#pragma endregion

#pragma region Funciones Auxiliares

//Verificar si la Lista Esta Vacia
bool estaVacia() {

    return root == nullptr;

    ArboLBST* nuevo = new ArboLBST;
    nuevo->dato = leerDato();
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    return nuevo;

    //Para encontrar el valor minimo del arbol
    ArboLBST* encontrarMinimo();
        //
        //


}//FIN

#pragma endregion

#pragma region Insertar/Eliminar/Buscar/Mostrar

void insertar() {


};
//FIN

void eliminar() {


};
//FIN

void buscar() {


};
//FIN

void mostrar() {


};
//FIN

#pragma endregion

#pragma region Menu

void mostrarMenu() {
    cout << "============================" << endl;
    cout << "   Arbol Binario de Busqueda" << endl;
    cout << "============================" << endl;
    cout << "1.Insertar" << endl;
    cout << "2.Eliminar" << endl;
    cout << "3.Buscar" << endl;
    cout << "4.Salir" << endl;
    cout << "============================" << endl;
    cout << "Opcion: ";
}

#pragma endregion

int main() {

    int opcion = leerOpcionMenu();

    mostrarMenu();

    do
    {
        switch (opcion) {

        case 0:
            cout << "\n--- INSERTAR ELEMENTO ---\n";
            insertar();
            break;

        case 1:
            cout << "\n--- ELIMINAR ELEMENTO ---\n";
            eliminar();
            break;

        case 2:
            cout << "\n--- BUSCAR ELEMENTO ---\n";
            buscar();
            break;

        case 4:
            cout << "\n--- Mostrar ELEMENTO(S) ---\n";
            mostrar();
            break;

        case 5:
            // Limpiar memoria antes de salir

            cout << "\nFin del programa.\n";
            break;
        }
    }
    while (opcion != 4);

    return 0;
}