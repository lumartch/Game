#ifndef LISTA_H
#define LISTA_H

#include "Cuenta.h"
#include <fstream>

class Nodo;

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void inserta(Cuenta cuenta);
        //std::string mostrarTodo();
        void guardarEnDisco();
        int getCont();
        Cuenta operator[](const int &pos);
    protected:

    private:
        Nodo* primero;
        int cont;
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
