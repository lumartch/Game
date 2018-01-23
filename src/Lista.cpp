#include "Lista.h"

Lista::Lista() {
    primero = nullptr;
}

Lista::~Lista() {
    //dtor
}

void Lista::inserta(Cuenta c){
    Nodo* nuevoNodo = new Nodo(c);
    nuevoNodo->setSig(primero);
    primero = nuevoNodo;
}

void Lista::mostrarTodo(){
    Nodo* aux = primero;
    while(aux != nullptr){
        cout << aux->getDato().toString() << endl;
        aux = aux->getSig();
    }
}

Nodo::Nodo() {
    siguiente = nullptr;
}

Nodo::Nodo(Cuenta c) {
    siguiente = nullptr;
    dato = c;
}

Nodo::~Nodo() {

}

void Nodo::setSig(Nodo* siguiente){
    this->siguiente = siguiente;
}

Nodo* Nodo::getSig(){
    return siguiente;
}

Cuenta Nodo::getDato(){
    return dato;
}

void Nodo::setDato(Cuenta c){
    dato = c;
}
