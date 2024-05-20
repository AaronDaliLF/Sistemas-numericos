#include "binario.h"

// Constructor que convierte un número decimal en binario
binario::binario(long valor) {
    // Inicializa la lista vacía
    bin = lista();

    // Convierte el número decimal en binario y lo guarda en la lista
    while (valor != 0) {
        bin.insertarAlInicio(valor % 2); // Inserta el residuo de la división en la lista (dígito binario)
        valor /= 2; // Divide el valor por 2 para continuar con el siguiente dígito binario
    }

    // Si el valor original era 0, asegura que la lista contenga solo un 0
    if (bin.getPrim() == nullptr) {
        bin.insertarAlInicio(0);
    }
}

#include <string>

// Sobrecarga del operador de suma para sumar dos números binarios
binario binario::operator+(const binario &op2) const {
    binario temp; // Crea un objeto binario temporal para almacenar el resultado de la suma
    int acarreo = 0; // Inicializa el acarreo en 0
    string sumaString; // Variable para almacenar los bits calculados en la suma

    // Obtiene los punteros al último nodo de cada lista (el bit menos significativo)
    pnodo nodo1 = bin.getUltm();
    pnodo nodo2 = op2.bin.getUltm();

    // Realiza la suma de los bits de manera similar a la suma binaria manual
    while (nodo1 != nullptr || nodo2 != nullptr || acarreo != 0) {
        // Obtiene los bits correspondientes de los operandos y el acarreo
        int bit1 = (nodo1 != nullptr) ? nodo1->num : 0; // Obtiene el bit del primer operando (o 0 si no hay más bits)
        int bit2 = (nodo2 != nullptr) ? nodo2->num : 0; // Obtiene el bit del segundo operando (o 0 si no hay más bits)
        int suma = bit1 + bit2 + acarreo; // Realiza la suma de los bits y el acarreo
        sumaString += to_string(suma % 2); // Almacena el bit resultante de la suma en la variable string
        acarreo = suma / 2; // Actualiza el acarreo para la próxima iteración

        // Avanza los punteros al nodo anterior para continuar con la suma
        if (nodo1 != nullptr) nodo1 = nodo1->ant;
        if (nodo2 != nullptr) nodo2 = nodo2->ant;
    }

    // Invierte la cadena de bits para mostrar el resultado en el orden correcto
    string resultado;
    for (int i = sumaString.size() - 1; i >= 0; --i) {
        resultado += sumaString[i];
    }
    // Muestra el resultado en binario
    std::cout << "\n\n" << "n1 + n2 = " << resultado;

    return temp; // Retorna el objeto binario temporal (aún no implementado)
}

// Sobrecarga del operador de inserción para imprimir un objeto binario en una secuencia de salida
ostream &operator<<(ostream &salida, const binario &num) {
    pnodo p = num.bin.getPrim(); // Obtiene un puntero al primer nodo de la lista binaria

    if (p == nullptr) { // Verifica si la lista está vacía
        salida << "0"; // Si está vacía, imprime un solo 0
        return salida; // Retorna la secuencia de salida
    }

    // Imprime los bits en el orden correcto de la lista
    while (p != nullptr) {
        salida << p->num; // Imprime el bit actual
        p = p->sig; // Avanza al siguiente bit en la lista
    }

    return salida; // Retorna la secuencia de salida con los bits impresos
}
