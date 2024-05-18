#include "listadecimal.h"

void menu();

int main() {
    ListaDecimal A;
    char op = '0';
    while (op < '5') {
        menu();
        cin >> op;
        switch (op) {
            case '1': A.pedirDatos();
                break;
            case '2': A.quitarDatos();
                break;
            case '3': A.imprimir1();
                break;
            case '4': A.imprimir2();
                break;
            case '5': 
                break;
            default: cout << "\n\n\tERROR EN OPCION";
                op = '0';
        }
    }
    ListaDecimal B(A); // Invocar el constructor de copia
    cout << "\nLista A = "; A.imprimir1();
    cout << "\nLista B = "; B.imprimir1();

    ListaDecimal C = A + B; // Realizar la suma de listas
    cout << "\nLista C = A + B = " << C;

    return 0;
}

void menu() {
    cout << "\n\n\t*** MENU PRINCIPAL ***";
    cout << "\n\n1. Entrar datos a la lista";
    cout << "\n2. Borrar datos de la lista";
    cout << "\n3. Imprimir lista de prim a ultimo";
    cout << "\n4. Imprimir lista de ultimo a primero";
    cout << "\n5. Salir del menu";
    cout << "\n\n\tEscoja opcion: ";
}