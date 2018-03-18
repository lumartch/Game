#ifndef MENUPERSONAJES_H
#define MENUPERSONAJES_H

#ifndef _WIN32
#define CLEAR "clear"
#define MKDIR "mkdir Personajes/"
#define DIR "Personajes/"
#define DIRGRAFO "Grafo/Linux/"
#define SLASH "/"
#else
#define CLEAR "cls"
#define MKDIR "mkdir Personajes\\"
#define DIR "Personajes\\"
#define DIRGRAFO "Grafo\\Windows\\"
#define SLASH "\\"
#endif

#include "ListaHistorial.h"
#include "ListaInventario.h"
#include "Personaje.h"
#include "Historial.h"
#include "Grafo.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <iomanip>

using namespace std;

class MenuPersonajes {
public:
    MenuPersonajes();
    MenuPersonajes(Personaje &pers, Grafo &grafo);
    void menuPrincipal();
    void modificar();
    void mostrar();
    void completarMision();
    void abandonar();
    void mostrarMapa();
    void pausa();
    virtual ~MenuPersonajes();

private:
    Personaje personaje;
    Grafo grafoPersonaje;
    Grafo grafoGeneral;
    string mkVertices, mkAristas;
    ListaHistorial listaHistorial;
    ListaInventario listaInventario;
    bool validoOpcMenu(std::string &opc);
    bool validoOpcModificar(std::string &opc);
    bool validoOpcRazaRol(std::string& opc);
    void guardarPersonaje(const std::string&archivo, Personaje &pers);
};

#endif // MENUPERSONAJES_H
