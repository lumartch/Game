#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <regex>
#include "Lista.h"
#include "Cuenta.h"
#include "Personaje.h"
#include "MenuPersonajes.h"



using namespace std;

class Menu {
public:
    Menu();
    virtual ~Menu();
    void menuPrincipal();
    void acceder();
    void agregar();
    void eliminar(const int &pos);
    void modificarMenu(const int &pos);
    void mostrar(const int &pos);
    void mostrarTodo();
    void crearPersonaje(const int &pos);
    void eliminarPersonaje(const int &pos);
    void accederPersonaje(const int &pos);
    void salir();
    void pausa();

private:
    Lista listaCuentas;
    bool correoValido(std::string &correo);
    bool usernameValido(std::string &username);
    bool nombreValido(std::string &nombre);
    bool passwdValido(std::string &password);
    bool existePersonaje(std::string &personaje);
    bool existePersonajeCuenta(std::string &nomPersonaje, std::string &username);
    bool validoOpcMod(std::string &opc);
    void guardarPersonaje(const std::string&archivo, Personaje &pers);
    bool validoDato(std::string &dato);
    Personaje regresaPersonaje(std::string &nomPersonaje, std::string &username);
    bool validoOpcRazaRol(std::string &opc);
    bool maxPersonajes(std::string &username);
};

#endif // MENU_H
