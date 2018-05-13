#ifndef MENU_H
#define MENU_H

#include "Lista.h"
#include "Cuenta.h"
#include "Personaje.h"
#include "MenuPersonajes.h"
#include "listainvertida.h"

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
    void mostrarPersonajes(const int &pos);
    void crearPersonaje(const int &pos);
    void eliminarPersonaje(const int &pos);
    void eliminarLogico(const int &pos);
    void activarLogico(const int &pos);
    void accederPersonaje(const int &pos);
    void salir();
    void pausa();
    void mostrarListaInvertida();
    void insertaListaInvertida();

private:
    Lista listaCuentas;
    ListaInvertida listaInvertida;
    Grafo grafoGeneral;
    bool correoValido(std::string &correo);
    bool usernameValido(std::string &username);
    bool nombreValido(std::string &nombre);
    bool passwdValido(std::string &password);
    bool existePersonaje(std::string &personaje);
    bool existePersonajeCuenta(std::string &nomPersonaje, const int &posIndice);
    bool validoOpcMod(std::string &opc);
    void guardarPersonaje(const std::string&archivo, Personaje pers, const int &posIndice);
    bool validoDato(std::string &dato);
    Personaje regresaPersonaje(std::string &nomPersonaje, const int &posIndice);
    bool validoOpcRazaRol(std::string &opc);
    bool maxPersonajes(std::string &username, const int &pos);
};

#endif // MENU_H
