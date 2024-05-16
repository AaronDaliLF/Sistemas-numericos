#include "listadecimal.h"

ListaDecimal::ListaDecimal() {
    head = nullptr;
    tail = nullptr;
}

ListaDecimal::ListaDecimal(const ListaDecimal& copia) {
    head = nullptr;
    tail = nullptr;
    if (copia.head != nullptr) {
        Nodo* pcopia = copia.head;
        while (pcopia != nullptr) {
            entrarDatos(pcopia->dato);
            pcopia = pcopia->next;
        }
    }
}

ListaDecimal::~ListaDecimal() {
    Nodo* temp = head;
    while (temp) {
        Nodo* next = temp->next;
        delete temp;
        temp = next;
    }
}

void ListaDecimal::pedirDatos() {
    long dato;
    char res = 's';
    while (res == 's' || res == 'S') {
        cout << "\n\nDigite dato a entrar: ";
        cin >> dato;
        if (validar(dato) == 0) {
            entrarDatos(dato);
            cout << "\n\tDato guardado con exito\n";
        } else
            cout << "\n\tDato existente no se guardo\n";
        do {
            cout << "\n\nDesea entrar otro dato (s/n): ";
            cin >> res;
        } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
    }
}

void ListaDecimal::entrarDatos(long v) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = v;
    nuevo->next = nullptr;
    nuevo->prev = tail;
    if (tail) {
        tail->next = nuevo;
    } else {
        head = nuevo;
    }
    tail = nuevo;
}

void ListaDecimal::quitarDatos() {
    long dato;
    char res = 's';
    while (res == 's' || res == 'S') {
        cout << "\n\nDigite dato a borrar: ";
        cin >> dato;
        if (validar(dato) == 1) {
            borrarDatos(dato);
            cout << "\n\tDato borrado con exito\n";
        } else
            cout << "\n\tEl dato no existe\n";
        do {
            cout << "\n\nDesea borrar otro dato (s/n): ";
            cin >> res;
        } while (res != 's' && res != 'S' && res != 'n' && res != 'N');
    }
}

int ListaDecimal::validar(long v) {
    Nodo* p = head;
    while (p != nullptr && p->dato != v) p = p->next;
    if (p == nullptr) return 0;
    return 1;
}

void ListaDecimal::borrarDatos(long v) {
    Nodo* p = head;
    if (p->dato == v) {
        head = p->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete p;
    } else if (tail->dato == v) {
        p = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete p;
    } else {
        while (p->dato != v) p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
}

void ListaDecimal::imprimir1() {
    Nodo* p = head;
    if (p == nullptr) {
        cout << "0";
    } else {
        while (p != nullptr) {
            cout << p->dato;
            p = p->next;
        }
    }
}

void ListaDecimal::imprimir2() {
    Nodo* p = tail;
    if (p == nullptr) {
        cout << "0";
    } else {
        while (p != nullptr) {
            cout << p->dato;
            p = p->prev;
        }
    }
}

ListaDecimal ListaDecimal::operator+(const ListaDecimal& op2) const {
    ListaDecimal resultado;
    Nodo* nodo1 = tail;
    Nodo* nodo2 = op2.tail;
    int carry = 0;

    while (nodo1 || nodo2 || carry) {
        int sum = carry;
        if (nodo1) {
            sum += nodo1->dato;
            nodo1 = nodo1->prev;
        }
        if (nodo2) {
            sum += nodo2->dato;
            nodo2 = nodo2->prev;
        }
        resultado.entrarDatos(sum % 10);
        carry = sum / 10;
    }


    return resultado;
}



ostream& operator<<(ostream& salida, const ListaDecimal& num) {
    Nodo* temp = num.tail;
    if (temp == nullptr) {
        salida << "0";
    } else {
        while (temp) {
            salida << temp->dato;
            temp = temp->prev;
        }
    }
    return salida;
}
