#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "Lista.h"
#include "Cuenta.h"
#include <regex>


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
    void salir();
    void pausa();

private:
    Lista listaCuentas;
    bool correoValido(std::string &correo);
    bool usernameValido(std::string &username);
    bool nombreValido(std::string &nombre);
    bool passwdValido(std::string &password);
};

#endif // MENU_H
