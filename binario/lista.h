#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

struct nodo {
    int num;
    struct nodo *sig, *ant;
};
typedef struct nodo *pnodo;

class lista {
public:
    pnodo prim;
    pnodo ultm;
    pnodo getPrim() const { return prim; }
    pnodo getUltm() const { return ultm; }
    lista(); // Constructor base
    lista(lista &); // Constructor de copia
    virtual ~lista(); // Destructor
    void pedirDatos();
    void entrarDatos(int);
    void insertarAlInicio(int);
    void quitarDatos();
    void borrarDatos(int);
    int validar(int);
    void imprimir1();
    void imprimir2();
private:
    pnodo nuevo;
};

#endif
