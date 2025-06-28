/*
-------------------------------------------------------------------------------------------------------
Tarea: N�meros Persistentes
Materia: IDS343-01-L LAB. ESTRUCTURAS DE DATOS Y ALGORITMOS I
-------------------------------------------------------------------------------------------------------
Descripcion:
   N�meros persistentes son aquellos que al multiplicar sus d�gitos repetidamente hasta que el resultado sea un solo d�gito,

 Autor:
    Dominique Jeldes - 1121623


Fecha: 25/Jun/2025

*/

#include <iostream>

using namespace std;

// Funci�n que multiplica los d�gitos de un n�mero
int multiplicarDigitos(int n) {
    int producto = 1;
    while (n > 0) {
        producto *= (n % 10);
        n /= 10;
    }
    return producto;
}

// Funci�n que calcula la persistencia de un n�mero
int calcularPersistencia(int n) {
    int contador = 0;
    while (n >= 10) { // mientras tenga m�s de un d�gito
        n = multiplicarDigitos(n);
        contador++;
    }
    return contador;
}

int main() {
    int numeroMayorPersistencia = 0;
    int mayorPersistencia = 0;

    // Recorremos los n�meros de dos d�gitos
    for (int i = 10; i <= 99; i++) {
        int p = calcularPersistencia(i);
        if (p > mayorPersistencia) {
            mayorPersistencia = p;
            numeroMayorPersistencia = i;
        }
    }

    cout << "El numero de dos digitos con mayor persistencia es: " << numeroMayorPersistencia << endl;
    cout << "Su persistencia es: " << mayorPersistencia << endl;

    return 0;
}