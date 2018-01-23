#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Cuenta.h"

using namespace std;

class Nodo;

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void inserta(Cuenta cuenta);
        void mostrarTodo();
    protected:

    private:
        Nodo* primero;
};

class Nodo{
    public:
        Nodo();
        Nodo(Cuenta cuenta);
        virtual ~Nodo();
        void setSig(Nodo* siguiente);
        Nodo* getSig();
        Cuenta getDato();
        void setDato(Cuenta c);
    private:
        Nodo* siguiente;
        Cuenta dato;

};



#endif // LISTA_H
