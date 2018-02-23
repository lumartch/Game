#ifndef LISTAINVENTARIO_H
#define LISTAINVENTARIO_H

#include "Objeto.h"

class ListaInventario {
public:
    ListaInventario();
    bool estaVacia();
    bool estaLlena();
    void insertar(const int& pos, const Objeto& inv);
    void eliminar(const int& pos);
    int primerPos();
    int ultimaPos();
    int posSiguiente(const int& pos);
    int posAnterior(const int& pos);
    int encontrar(const int&pos);
    std::string toString();
    void borrarTodo();
    Objeto& operator[](const int& pos);
    virtual ~ListaInventario();
private:
    Objeto inventario[50];
    int ultimo;
    int cont;
};

#endif // LISTAINVENTARIO_H
