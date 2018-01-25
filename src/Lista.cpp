#include "Lista.h"

Lista::Lista() {
    primero = nullptr;
    cont = 0;
}

Lista::~Lista() {
    //dtor
}

void Lista::inserta(Cuenta c){
    Nodo* nuevoNodo = new Nodo(c);
    nuevoNodo->setSig(primero);
    primero = nuevoNodo;
    cont++;
}

/*std::string Lista::mostrarTodo(){
    Nodo* aux = primero;
    std::string toString;
    while(aux != nullptr){
        toString += aux->getDato().toString() + "\n";
        aux = aux->getSig();
    }
    return toString;
}*/

void Lista::guardarEnDisco(){
    ofstream fout("Cuentas.txt");
    Nodo* aux;
    aux = primero;
    for(int i = 0; i < cont; i++){
        Cuenta c = aux->getDato();
        fout << c.toString() << endl;
        aux = aux->getSig();
    }
    fout.close();
}

int Lista::getCont(){
    return cont;
}

Cuenta Lista::operator[](const int &pos){
    Nodo* aux(primero);
    for(int i = 0; i < pos; i++){
        aux = aux->getSig();
    }
    return aux->getDato();
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
