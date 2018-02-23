#ifndef MENUPERSONAJES_H
#define MENUPERSONAJES_H

#include "Personaje.h"
#include "Historial.h"
#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

class MenuPersonajes
{
    public:
        MenuPersonajes();
        MenuPersonajes(Personaje &pers);
        void menuPrincipal();
        void modificar();
        void mostrar();
        void completarMision();
        void abandonar();
        void pausa();
        virtual ~MenuPersonajes();

    private:
        Personaje personaje;
        bool validoOpcMenu(std::string &opc);
        bool validoOpcModificar(std::string &opc);
        bool validoOpcRazaRol(std::string& opc);
        void guardarPersonaje(const std::string&archivo, Personaje &pers);
};

#endif // MENUPERSONAJES_H
