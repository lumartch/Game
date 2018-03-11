#ifndef LISTAINVENTARIO_H
#define LISTAINVENTARIO_H

#include <fstream>
#include <iostream>
#include "Arma.h"

class ListaInventario {
public:
    ListaInventario();
    bool estaVacia();
    bool estaLlena();
    void insertar(const int& pos, const Arma& inv);
    void eliminar(const int& pos);
    int primerPos();
    int ultimaPos();
    int posSiguiente(const int& pos);
    int posAnterior(const int& pos);
    int encontrar(const int&pos);
    std::string toString();
    void borrarTodo();
    Arma& operator[](const int& pos);
    void leerDelDisco(const std::string &archivo);
    void escribirAlDisco(const std::string &archivo);
    virtual ~ListaInventario();
private:
    Arma inventario[50];
    int ultimo;
    int cont;
};

#endif // LISTAINVENTARIO_H
