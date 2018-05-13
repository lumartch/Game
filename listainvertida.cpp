#include "listainvertida.h"


DatosInvertida::DatosInvertida() {
    actual = 0;
    siguiente = -1;
    strcpy(usernameOwner, "");
    strcpy(nombrePersonaje, "");
    posArchivo = 0;
    activo = true;
}

void DatosInvertida::setActual(const int& actual) {
    this->actual = actual;
}

void DatosInvertida::setSiguiente(const int& siguiente) {
    this->siguiente = siguiente;
}

void DatosInvertida::setUsernameOwner(const std::string& usernameOwner) {
    strcpy(this->usernameOwner, usernameOwner.c_str());
}

void DatosInvertida::setNombrePersonaje(const std::string& nombrePersonaje) {
    strcpy(this->nombrePersonaje, nombrePersonaje.c_str());
}

void DatosInvertida::setPosArchivo(const long int& posArchivo) {
    this->posArchivo = posArchivo;
}

int DatosInvertida::getActual() {
    return actual;
}

int DatosInvertida::getSiguiente() {
    return siguiente;
}

char* DatosInvertida::getUsernameOwner() {
    return usernameOwner;
}

char* DatosInvertida::getNombrePersonaje() {
    return nombrePersonaje;
}

long int DatosInvertida::getPosArchivo() {
    return posArchivo;
}

std::string DatosInvertida::toString() {
    std::string res;
    res += std::to_string(actual) + "|" +std::string(usernameOwner) + "|" + std::string(nombrePersonaje) + "|" + std::to_string(siguiente)
    + "|PosArchivo: " +std::to_string(posArchivo) + "|Activo: "+std::to_string(activo) +"\n";
    return res;
}

void DatosInvertida::setActivo(const bool& activo) {
    this->activo = activo;
}

bool DatosInvertida::getActivo() {
    return activo;
}

NodoInvertida::NodoInvertida() {
    siguiente = nullptr;
    siguientePersonaje = nullptr;
}

NodoInvertida::NodoInvertida(DatosInvertida dato) {
    siguiente = nullptr;
    siguientePersonaje = nullptr;
    this->dato = dato;
}

NodoInvertida::~NodoInvertida() {

}

void NodoInvertida::setSig(NodoInvertida* siguiente) {
    this->siguiente = siguiente;
}

void NodoInvertida::setSigPers(NodoInvertida* siguientePersonaje) {
    this->siguientePersonaje = siguientePersonaje;
}

void NodoInvertida::setDato(DatosInvertida c) {
    this->dato = c;
}

NodoInvertida* NodoInvertida::getSig() {
    return siguiente;
}

NodoInvertida* NodoInvertida::getSigPers() {
    return siguientePersonaje;
}

DatosInvertida& NodoInvertida::getDato() {
    return dato;
}

ListaInvertida::ListaInvertida() {
    primero = nullptr;
    cont = 0;
}

ListaInvertida::~ListaInvertida() {
    this->eliminarTodo();
}

NodoInvertida* ListaInvertida::ultimaPos() {
    if(primero == nullptr){
        return nullptr;
    }

    NodoInvertida* aux = primero;
    while(aux->getSig() != nullptr) {
        aux = aux->getSig();
    }
    return aux;
}

int ListaInvertida::inserta(DatosInvertida datos, NodoInvertida* pos, int& posIndice) {
    datos.setActual(cont);
    NodoInvertida* aux = new NodoInvertida(datos);
    if(pos == nullptr) {
        aux->setSig(primero);
        primero = aux;
    } else {
        aux->setSig(pos->getSig());
        pos->setSig(aux);
    }

    if(posIndice == -1){
        posIndice = cont;
    }
    else{
        NodoInvertida* newSigInv = primero;
        int i = 0;
        while(i < posIndice) {
            newSigInv = newSigInv->getSig();
            i++;
        }

        while(newSigInv->getSigPers() != nullptr){

            newSigInv = newSigInv->getSigPers();
        }

        newSigInv->setSigPers(aux);
        newSigInv->getDato().setSiguiente(cont);
    }
    cont++;
    return posIndice;
}

bool ListaInvertida::estaVacia() {
    return primero == nullptr;
}

int ListaInvertida::eliminarLogico(const int& posIndice, std::string& nomPersonaje) {
    NodoInvertida* actual = primero;
    int posNueva = posIndice;
    int i = 0;
    while(i < posIndice) {
        actual = actual->getSig();
        i++;
    };
    NodoInvertida* anterior;
    while(actual != nullptr){
        if(std::string(actual->getDato().getNombrePersonaje()) == nomPersonaje){
            break;
        }
        anterior = actual;
        actual = actual->getSigPers();
    }

    if(actual->getDato().getActual() == posIndice){
        posNueva = actual->getDato().getSiguiente();
        if(actual->getSigPers() != nullptr){
            actual->setSigPers(nullptr);
        }
    }
    else{
        if(actual->getSigPers() != nullptr){
            anterior->setSigPers(actual->getSigPers());
            anterior->getDato().setSiguiente(actual->getDato().getSiguiente());
        }
        else{
            anterior->setSigPers(nullptr);
            anterior->getDato().setSiguiente(-1);
        }
    }
    actual->getDato().setSiguiente(-1);
    actual->getDato().setActivo(false);
    return posNueva;
}

void ListaInvertida::eliminacionPersonajesLogica(const int& posIndice) {
    NodoInvertida* actual = primero;
    int i = 0;
    while(i < posIndice) {
        actual = actual->getSig();
        i++;
    };

    NodoInvertida* aux;
    while(actual != nullptr){
        aux = actual;
        actual = actual->getSigPers();

        aux->setSigPers(nullptr);
        aux->getDato().setActivo(false);
        aux->getDato().setSiguiente(-1);
    }
}

bool ListaInvertida::cuentaPersonajeLineal(std::string& nomPersonaje, std::string& username) {
    NodoInvertida* aux = primero;
    while(aux != nullptr){
        if(std::string(aux->getDato().getUsernameOwner()) == username and std::string(aux->getDato().getNombrePersonaje()) == nomPersonaje){
            return true;
        }
        aux = aux->getSig();
    }
    return false;
}

int ListaInvertida::activacionLogica(std::string& nomPersonaje, std::string &username, const int& posIndice) {
    int i = 0;
    int posNueva = posIndice;

    NodoInvertida* actualizar = primero;
    while(actualizar != nullptr){
        if(std::string(actualizar->getDato().getUsernameOwner()) == username and std::string(actualizar->getDato().getNombrePersonaje()) == nomPersonaje){
            break;
        }
        actualizar = actualizar->getSig();
    }

    NodoInvertida* aux = primero;
    while(i < posIndice){
        aux = aux->getSig();
        i++;
    }
    while(aux->getSigPers() != nullptr){
        aux = aux->getSigPers();
    }


    if(posIndice == -1){
        posNueva = actualizar->getDato().getActual();

    }
    else{
        aux->setSigPers(actualizar);
        aux->getDato().setSiguiente(actualizar->getDato().getActual());

    }
    actualizar->setSigPers(nullptr);
    actualizar->getDato().setActivo(true);
    return posNueva;
}

void ListaInvertida::guardarEnDisco() {
    NodoInvertida* aux = primero;
    std::ofstream file(ARCHIVO);
    while(aux != nullptr) {
        DatosInvertida dato;
        dato = aux->getDato();
        file.write((char*)&dato, sizeof(DatosInvertida));
        aux = aux->getSig();
    }
    file.close();
}

int ListaInvertida::getCont() {
    return cont;
}

std::string ListaInvertida::toString() {
    std::string res;
    NodoInvertida* aux = primero;
    while(aux != nullptr) {
        res += aux->getDato().toString();
        aux = aux->getSig();
    }
    return res;
}


void ListaInvertida::insertaCargado(DatosInvertida datos, NodoInvertida* pos) {
    datos.setActual(cont);
    NodoInvertida* aux = new NodoInvertida(datos);
    if(pos == nullptr) {
        aux->setSig(primero);
        primero = aux;
    } else {
        aux->setSig(pos->getSig());
        pos->setSig(aux);
    }
    cont++;
}

void ListaInvertida::organizaNodos() {
    NodoInvertida* aux = primero;
    while(aux != nullptr){
        int sig = aux->getDato().getSiguiente();
        if(sig != -1){
            int i = 0;
            NodoInvertida* auxSigPers = primero;
            while(i < sig){
                auxSigPers = auxSigPers->getSig();
                i++;
            }
            aux->setSigPers(auxSigPers);
        }
        aux = aux->getSig();
    }
}

void ListaInvertida::cargarDesdeDisco() {
    std::ifstream file(ARCHIVO);
    if(!file.good()){
        file.close();
        std::ofstream fileIn(ARCHIVO, std::ios::app);
        fileIn.close();
        return;
    }
    else{
        DatosInvertida datos;
        while(!file.eof()){
            file.read((char*)&datos, sizeof(DatosInvertida));
            if(file.eof()){break;}
            insertaCargado(datos, ultimaPos());
        }
    }
    file.close();
    organizaNodos();
}

NodoInvertida* ListaInvertida::operator[](const int& pos) {
    NodoInvertida* aux = primero;
    int i = 0;
    while(i < pos) {
        aux = aux->getSig();
        i++;
    }
    return aux;
}

void ListaInvertida::eliminarTodo() {
    NodoInvertida* aux;
    while(primero != nullptr) {
        aux = primero;
        primero = primero->getSig();
        delete aux;
    }
    cont = 0;
}


std::string ListaInvertida::personajesJugador(const int& posIndice){
    NodoInvertida* aux = primero;
    int i = 0;
    while(i < posIndice) {
        aux = aux->getSig();
        i++;
    }

    std::string res;
    while(aux->getDato().getSiguiente() != -1){
        res += aux->getDato().toString();
        aux = aux->getSigPers();
    }
    res += aux->getDato().toString();
    return res;
}

bool ListaInvertida::existePersonaje(std::string& nomPersonaje) {
    NodoInvertida* aux = primero;
    while(aux != nullptr){
        if(std::string(aux->getDato().getNombrePersonaje()) == nomPersonaje){
            return true;
        }
        aux = aux->getSig();
    }
    return false;
}
