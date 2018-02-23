#include "ListaHistorial.h"

ListaHistorial::ListaHistorial() {
    cont = 0;
    ultimo = -1;
}

ListaHistorial::~ListaHistorial()
{

}


bool ListaHistorial::estaVacia() {
    return ultimo == -1;
}

bool ListaHistorial::estaLlena() {
    return ultimo == 49;
}

void ListaHistorial::insertar(const int& pos, Historial& his) {
    if(estaLlena() or pos <-1 or pos > ultimo) {
        //std::cout << "Desbordamiento de datos.";
        return;
    }
    if(existeHistorial(his)){
        return;
    }
    int i = ultimo;
    while(i > pos){
        historial[i + 1] = historial[i];
        i--;
    }
    historial[pos + 1] = his;
    ultimo++;
}

void ListaHistorial::eliminar(const int& pos) {
    if(estaVacia() or pos < 0 or pos > ultimo) {
        //std::cout << "Insuficiencia de datos.";
        return;
    }
    int i = pos;
    while(i < ultimo) {
        historial[i] = historial[i+1];
        i++;
    }
    ultimo--;
}

int ListaHistorial::primerPos() {
    if(estaVacia()) {
        return -1;
    }
    return 0;
}

int ListaHistorial::ultimaPos() {
    return ultimo;
}

int ListaHistorial::posSiguiente(const int& pos) {
    if(estaVacia() or pos < 0 or pos > ultimo-1) {
        //throw ListException("Insuficiencia de datos al hacer posSiguiente.");
        return -1;
    }
    return pos + 1;
}

int ListaHistorial::posAnterior(const int& pos) {
    if(estaVacia() or pos < 1 or pos > ultimo) {
        //throw ListException("Insuficiencia de datos al hacer posAnterior.");
        return -1;
    }
    return pos - 1;
}

int ListaHistorial::encontrar(const int& pos) {
    return -1;
}

Historial& ListaHistorial::operator[](const int& pos) {
    if(estaVacia() or pos < 1 or pos > ultimo){
        return historial[-1];
    }
    return historial[pos];
}

bool ListaHistorial::existeHistorial(Historial& his) {
    for(int i; i < ultimo; i++){
        std::string auxTitulo = historial[i].getTitulo();
        std::string auxTitulo2 = his.getTitulo();
        if(auxTitulo == auxTitulo2){
            return true;
        }
    }
    return false;
}


std::string ListaHistorial::toString() {
    if(estaVacia()){
        return "El historial se encuentra vacio.\n";
    }
    std::string res;
    for(int i = 0; i <= ultimo; i++){
        res += std::to_string(i + 1) + ") " + historial[i].toString()  +  "\n";
    }
    return res;
}

void ListaHistorial::borrarTodo() {
    ultimo = -1;
}

