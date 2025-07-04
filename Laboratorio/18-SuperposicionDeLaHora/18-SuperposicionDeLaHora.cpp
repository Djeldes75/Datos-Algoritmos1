/*
-------------------------------------------------------------------------------------------------------
Tarea:  Horario y Minutero de un Reloj
Materia: IDS343-01L-LAB. ESTRUCTURAS DE DATOS Y ALGORITMOS I
-------------------------------------------------------------------------------------------------------
Descripci�n:

   Hacer un programa en C++ que determine cu�ntas veces se superponen la
   horaria y la minutera en un reloj an�logo, indique las horas y minutos en que se superponen
   las manecillas.

Autor:
   Dominique Jeldes ID: 1121623

Fecha:
   30/Junio/2025

*/

#include <iostream>

using namespace std;

int main() {

    cout << "Superposiciones de las manecillas en un reloj analogico (12 horas):\n\n";

    int totalSuperposiciones = 0;

    for (int h = 0; h < 12; h++) {
        // F�rmula: (60 * h) / 11
        double minutos = (60.0 * h) / 11.0;

        int horas = h;
        int minutosEnteros = (int)minutos;
        int segundos = (int)((minutos - minutosEnteros) * 60 + 0.5); // redondeo a segundos

        // Ajuste si los segundos llegan a 60
        if (segundos == 60) {
            minutosEnteros++;
            segundos = 0;
        }

        // Ajuste si los minutos llegan a 60
        if (minutosEnteros == 60) {
            horas = (horas + 1) % 12;
            minutosEnteros = 0;
        }

        // Imprimir en formato hh:mm:ss
        cout << "Superposicion #" << (totalSuperposiciones + 1) << ": ";
        printf("%02d:%02d:%02d\n", horas == 0 ? 12 : horas, minutosEnteros, segundos);

        totalSuperposiciones++;
    }

    cout << "\nTotal de superposiciones en 12 horas: " << totalSuperposiciones << endl;



    return 0;
}