#include "Lista.h"

Lista::Lista() {
    primero = nullptr;
    cont = 0;
    cargarDesdeDisco("Cuentas.txt");
}

Lista::~Lista() {
    Nodo* aux;
    while(primero != nullptr){
        aux = primero;
        primero = primero->getSig();
        delete aux;
    }
}

void Lista::inserta(Cuenta c){
    Nodo* nuevoNodo = new Nodo(c);
    nuevoNodo->setSig(primero);
    primero = nuevoNodo;
    cont++;
}

bool Lista::cuentaCorroborada(std::string &username, std::string &password){
    Nodo* aux(primero);
    for(int i = 0; i < getCont(); i++){
        if(aux->getDato().getUserName() == username and aux->getDato().getPasswd() == password){
            return true;
        }
        aux = aux->getSig();
    }
    return false;
}

void Lista::guardarEnDisco(){
    ofstream fout("Cuentas.txt");
    Nodo* aux;
    aux = primero;
    for(int i = 0; i < cont; i++){
        Cuenta c = aux->getDato();
        fout << c.toFile() << endl;
        aux = aux->getSig();
    }
    fout.close();
}

int Lista::busqueda(std::string &username){
    int i;
    Nodo* aux(primero);
    for(i = 0; i < getCont(); i++){
        if(aux->getDato().getUserName() == username){
            return i;
        }
        aux = aux->getSig();
    }
    return -1;
}

void Lista::eliminarDato(std::string &username){
    int pos = busqueda(username);
    if(pos == -1){
        return;
    }
    Nodo* aux(primero);
    Nodo* nodoEl;
    int i = 0;
    while(i != pos - 1){
        aux = aux->getSig();
        i++;
    }
    nodoEl = aux->getSig();
    aux->setSig(nodoEl->getSig());
    cont--;
    delete nodoEl;
}

int Lista::getCont(){
    return cont;
}

Cuenta& Lista::operator[](const int &pos){
    Nodo* aux(primero);
    for(int i = 0; i < pos; i++){
        aux = aux->getSig();
    }
    return aux->getDato();
}

void Lista::cargarDesdeDisco(std::string nombreArchivo){
    ifstream fin(nombreArchivo);
    if(!fin.good()){
        ofstream fout(nombreArchivo);
        return;
    }
    std::string stringObj;
    fin >> stringObj;
    while (!fin.eof()){
        Cuenta obj(stringObj);
        inserta(obj);
        fin >> stringObj;
    }
    fin.close();
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

Cuenta& Nodo::getDato(){
    return dato;
}

void Nodo::setDato(Cuenta c){
    dato = c;
}
