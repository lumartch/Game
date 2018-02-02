#ifndef LISTA_H
#define LISTA_H

#include "Cuenta.h"
#include <fstream>
#include <iostream>

class Nodo;

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void inserta(Cuenta cuenta);
        bool cuentaCorroborada(std::string &username, std::string &password);
        int busqueda(std::string &username);
        void eliminarDato(std::string &username);
        void guardarEnDisco();
        int getCont();
        void cargarDesdeDisco(std::string nombreArchivo);
        Cuenta& operator[](const int &pos);

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
        Cuenta& getDato();
        void setDato(Cuenta c);
    private:
        Nodo* siguiente;
        Cuenta dato;
};



#endif // LISTA_H
