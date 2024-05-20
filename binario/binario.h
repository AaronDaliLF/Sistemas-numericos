#ifndef BINARIO_H
#define BINARIO_H

#include "lista.h"
#include <iostream>
using namespace std;

class binario {
    friend ostream &operator<<(ostream &, const binario &);
public:
    binario(long = 0);
    binario operator+(const binario &) const;
private:
    lista bin; // Usar la lista doblemente enlazada para almacenar los dígitos binarios.
};

#endif // BINARIO_H
