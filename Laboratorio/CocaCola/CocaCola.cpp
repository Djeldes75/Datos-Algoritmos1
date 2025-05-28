/*
    -------------------------------------------------------------------------------------
TAREA: Coca Cola (LABORATORIO)
Materia: IDS343L-01-LABORATORIO ESTRUCTURAS DE DATOS Y ALGORITMOS I
-----------------------------------------------------------------------------------------
Descripci�n:
    Escribir un programa que imprima los n�meros del 1 al 100, pero con las siguientes reglas:
    - Si el n�mero es divisible por 3, imprimir "Coca" en lugar del n�mero
    - Si el n�mero es divisible por 5, imprimir "Cola" en lugar del n�mero
    - Si el n�mero es divisible por ambos 3 y 5 (es decir, por 15), imprimir "Coca Cola"
    - Si el n�mero no es divisible por 3 ni por 5, imprimir el n�mero tal como es

INTEGRANTES:
    Dominique Jeldes - 1121623

Fecha: 23/May/2025

*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    for (int i = 1; i <= 100; i++) {

        if (i % 3 == 0 && i % 5 == 0) {

            cout << "Coca Cola" << endl;
        }

        else if (i % 3 == 0) {

            cout << "Coca" << endl;
        }

        else if (i % 5 == 0) {

            cout << "Cola" << endl;
        }

        else {

            cout << i << endl;
        }
    }

    /*

    for (int i = 1; i <= 100; i++) {

        // Creamos un string vac�o donde acumularemos el texto
        string output = "";

        // Si el n�mero es divisible por 3, a�adimos "Coca" al string
        output += (i % 3 == 0) ? "Coca" : "";

        // Si el n�mero es divisible por 5, a�adimos "Cola" al string
        output += (i % 5 == 0) ? "Cola" : "";

        // Si el string est� vac�o, significa que no era divisible ni por 3 ni por 5,
        // por lo tanto imprimimos el n�mero; de lo contrario, imprimimos el contenido del string

        cout << (output.empty() ? to_string(i) : output) << endl;
    }

    */

    return 0;
}
