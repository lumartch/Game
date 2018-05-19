#include "Lista.h"

Nodo::Nodo() {
    siguiente = nullptr;
}

Nodo::Nodo(Cuenta c) {
    siguiente = nullptr;
    dato = c;
}

Nodo::~Nodo() {

}

void Nodo::setSig(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo* Nodo::getSig() {
    return siguiente;
}

Cuenta& Nodo::getDato() {
    return dato;
}

void Nodo::setDato(Cuenta c) {
    dato = c;
}


Lista::Lista() {
    primero = nullptr;
    cont = 0;
    cargarDesdeDisco("Cuentas.txt");
}

Lista::~Lista() {
    Nodo* aux;
    while(primero != nullptr) {
        aux = primero;
        primero = primero->getSig();
        delete aux;
    }
}

void Lista::inserta(Cuenta c) {
    Nodo* nuevoNodo = new Nodo(c);
    nuevoNodo->setSig(primero);
    primero = nuevoNodo;
    cont++;
}


bool Lista::estaVacia(){
    return primero == nullptr;
}

bool Lista::cuentaCorrecta(std::string &username, std::string &password) {
    Nodo* aux(primero);
    for(int i = 0; i < getCont(); i++) {
        if(aux->getDato().getUserName() == username and aux->getDato().getPasswd() == password) {
            return true;
        }
        aux = aux->getSig();
    }
    return false;
}

void Lista::guardarEnDisco() {
    std::ofstream fout("Cuentas.txt");
    Nodo* aux(primero);
    for(int i = 0; i < cont; i++) {
        Cuenta c = aux->getDato();
        fout << c.toFile() << std::endl;
        aux = aux->getSig();
    }
    fout.close();
}

int Lista::busqueda(std::string &username) {
    int i = 0;
    Nodo* aux = primero;
     while(aux != nullptr){
        if(aux->getDato().getUserName() == username) {
            return i;
        }
        i++;
        aux = aux->getSig();
     }
    return -1;
}

void Lista::eliminarDato(std::string &username) {
    int pos = busqueda(username);
    if(estaVacia() or pos == -1){
        return;
    }
    Nodo* aux = primero;
    if(pos == 0){
        primero = primero->getSig();
    }
    else{
        int i = 0;
        Nodo* ant;
        while(i < pos - 1 ){
            aux = aux->getSig();
            i++;
        }
        ant = aux;
        aux = aux->getSig();
        if(aux->getSig() == nullptr){
            ant->setSig(nullptr);
        }
        else{
            ant->setSig(aux->getSig());
        }
        /*ant = aux;
        ant->setSig(aux->getSig());*/
    }
    cont--;
    delete aux;

}

int Lista::getCont() {
    return cont;
}

Cuenta& Lista::operator[](const int &pos) {
    Nodo* aux(primero);
    for(int i = 0; i < pos; i++) {
        aux = aux->getSig();
    }
    return aux->getDato();
}

void Lista::cargarDesdeDisco(std::string nombreArchivo) {
    std::ifstream fin(nombreArchivo);
    if(!fin.good()) {
        std::ofstream fout(nombreArchivo);
        return;
    }
    std::string stringObj;
    getline(fin,stringObj);
    while (!fin.eof()) {
        Cuenta obj(stringObj);
        inserta(obj);
        getline(fin,stringObj);
    }
    fin.close();
}

void Lista::eliminarIndice() {
    Nodo* aux = primero;
    while(aux != nullptr){
        aux->getDato().setPosIndice(-1);
        aux = aux->getSig();
     }
}

