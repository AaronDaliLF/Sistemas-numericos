#include "lista.h"

// Constructor por defecto
lista::lista() {
    prim = ultm = nullptr; // Inicializa los punteros prim y ultm a nullptr
}

// Constructor de copia
lista::lista(lista &copia) {
    prim = ultm = nullptr; // Inicializa los punteros prim y ultm a nullptr
    if (copia.prim != nullptr) { // Verifica si la lista copia no está vacía
        struct nodo *pcopia = copia.prim; // Crea un puntero a nodo que apunta al inicio de la lista copia
        // Recorre la lista copia y copia sus elementos en la lista actual
        while (pcopia != nullptr) {
            this->entrarDatos(pcopia->num); // Inserta el valor de cada nodo en la lista actual
            pcopia = pcopia->sig; // Avanza al siguiente nodo en la lista copia
        }
    }
}

// Destructor
lista::~lista() {
    // Elimina todos los nodos de la lista
    while (prim != nullptr) {
        struct nodo *p = prim; // Crea un puntero temporal que apunta al primer nodo
        prim = prim->sig; // Avanza el puntero prim al siguiente nodo
        delete p; // Libera la memoria del nodo actual
    }
    ultm = nullptr; // Establece el puntero ultm a nullptr
}

// Método para insertar un nuevo nodo al final de la lista
void lista::entrarDatos(int v) {
    nuevo = new struct nodo; // Crea un nuevo nodo
    nuevo->num = v; // Asigna el valor v al nuevo nodo
    nuevo->sig = nullptr; // Establece el puntero siguiente del nuevo nodo a nullptr
    nuevo->ant = ultm; // Establece el puntero anterior del nuevo nodo al último nodo de la lista actual

    if (prim == nullptr) { // Verifica si la lista está vacía
        prim = ultm = nuevo; // Si la lista está vacía, el nuevo nodo es tanto el primero como el último
    } else {
        ultm->sig = nuevo; // Establece el puntero siguiente del último nodo al nuevo nodo
        ultm = nuevo; // Actualiza el puntero ultm para que apunte al nuevo nodo
    }
}

// Método para insertar un nuevo nodo al inicio de la lista
void lista::insertarAlInicio(int v) {
    nuevo = new struct nodo; // Crea un nuevo nodo
    nuevo->num = v; // Asigna el valor v al nuevo nodo
    nuevo->sig = prim; // Establece el puntero siguiente del nuevo nodo al primer nodo de la lista actual
    nuevo->ant = nullptr; // Establece el puntero anterior del nuevo nodo a nullptr

    if (prim == nullptr) { // Verifica si la lista está vacía
        prim = ultm = nuevo; // Si la lista está vacía, el nuevo nodo es tanto el primero como el último
    } else {
        prim->ant = nuevo; // Establece el puntero anterior del primer nodo al nuevo nodo
        prim = nuevo; // Actualiza el puntero prim para que apunte al nuevo nodo
    }
}

// Método para validar si un valor está presente en la lista
int lista::validar(int v) {
    pnodo p = prim; // Crea un puntero que apunta al primer nodo de la lista
    while (p != nullptr && p->num != v) p = p->sig; // Recorre la lista buscando el valor v
    return (p != nullptr) ? 1 : 0; // Retorna 1 si el valor se encuentra en la lista, de lo contrario, retorna 0
}

// Método para borrar un nodo que contiene un valor específico de la lista
void lista::borrarDatos(int v) {
    pnodo p = prim; // Crea un puntero que apunta al primer nodo de la lista
    while (p != nullptr && p->num != v) p = p->sig; // Busca el nodo que contiene el valor v
    if (p != nullptr) { // Verifica si se encontró el nodo
        if (p == prim) { // Verifica si el nodo es el primero en la lista
            prim = prim->sig; // Actualiza el puntero prim para que apunte al siguiente nodo
            if (prim != nullptr) prim->ant = nullptr; // Establece el puntero anterior del nuevo primer nodo a nullptr
        } else if (p == ultm) { // Verifica si el nodo es el último en la lista
            ultm = ultm->ant; // Actualiza el puntero ultm para que apunte al nodo anterior
            if (ultm != nullptr) ultm->sig = nullptr; // Establece el puntero siguiente del nuevo último nodo a nullptr
        } else {
            // Si el nodo está en el medio de la lista, actualiza los punteros de los nodos vecinos
            p->ant->sig = p->sig;
            p->sig->ant = p->ant;
        }
        delete p; // Libera la memoria del nodo encontrado
    }
}

// Método para imprimir los elementos de la lista en orden directo
void lista::imprimir1() {
    pnodo p = prim; // Crea un puntero que apunta al primer nodo de la lista
    while (p != nullptr) { // Recorre la lista
        cout << "  " << p->num; // Imprime el valor del nodo actual
        p = p->sig; // Avanza al siguiente nodo
    }
}

// Método para imprimir los elementos de la lista en orden inverso
void lista::imprimir2() {
    pnodo p = ultm; // Crea un puntero que apunta al último nodo de la lista
    while (p != nullptr) { // Recorre la lista en orden inverso
        cout << "  " << p->num; // Imprime el valor del nodo actual
        p = p->ant; // Retrocede al nodo anterior
    }
}
