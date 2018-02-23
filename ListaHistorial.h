#ifndef LISTAHISTORIAL_H
#define LISTAHISTORIAL_H

#include "Historial.h"

class ListaHistorial {
public:
    ListaHistorial();
    virtual ~ListaHistorial();
    bool estaVacia();
    bool estaLlena();
    void insertar(const int& pos, Historial& his);
    void eliminar(const int& pos);
    int primerPos();
    int ultimaPos();
    int posSiguiente(const int& pos);
    int posAnterior(const int& pos);
    int encontrar(const int&pos);
    std::string toString();
    void borrarTodo();
    Historial& operator[](const int& pos);
    bool existeHistorial(Historial& his);
private:
    Historial historial[50];
    int ultimo;
    int cont;
};

#endif // LISTAHISTORIAL_H
