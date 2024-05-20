#include "binario.h"

int main()
{
    // Creación de tres objetos binarios con diferentes valores.
    binario n1(79);
    binario n2(369);
    binario n3;

    // Impresión de los valores de los objetos binarios.
    cout << "\nn1 es " << n1;
    cout << "\nn2 es " << n2;    

    // Suma de dos objetos binarios y asignación del resultado a n3.
    n3 = n1 + n2;
    // Impresión de la suma de los objetos binarios.
    cout << "\n\n" << n1 << " + " << n2 << " = " << n3;

    cout << "\n\n";

    return 0;
}
