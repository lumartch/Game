#ifndef LISTAINVERTIDA_H
#define LISTAINVERTIDA_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#define ARCHIVO "LISTA_INVERTIDA.txt"

class DatosInvertida {
private:
    int actual;
    int siguiente;
    char usernameOwner[30];
    char nombrePersonaje[30];
    long int posArchivo;
    bool activo;
public:
    DatosInvertida();
    void setActual(const int &actual);
    void setSiguiente(const int &siguiente);
    void setUsernameOwner(const std::string & usernameOwner);
    void setNombrePersonaje(const std::string &nombrePersonaje);
    void setPosArchivo(const long int & posArchivo);
    void setActivo(const bool &activo);
    int getActual();
    int getSiguiente();
    char* getUsernameOwner();
    char* getNombrePersonaje();
    long int getPosArchivo();
    bool getActivo();
    std::string toString();
};

class NodoInvertida {
private:
    NodoInvertida* siguiente;
    NodoInvertida* siguientePersonaje;
    DatosInvertida dato;
public:
    NodoInvertida();
    NodoInvertida(DatosInvertida dato);
    virtual ~NodoInvertida();
    void setSig(NodoInvertida* siguiente);
    void setSigPers(NodoInvertida* siguientePersonaje);
    void setDato(DatosInvertida c);
    NodoInvertida* getSig();
    NodoInvertida* getSigPers();
    DatosInvertida& getDato();
};

class ListaInvertida {
private:
    NodoInvertida* primero;
    int cont;
    void insertaCargado(DatosInvertida datos, NodoInvertida* pos);
    void organizaNodos();
public:
    ListaInvertida();
    void eliminarTodo();
    virtual ~ListaInvertida();
    NodoInvertida* ultimaPos();
    int inserta(DatosInvertida datos, NodoInvertida* pos, int& posIndice);
    bool estaVacia();
    int eliminarLogico(const int &posIndice, std::string& nomPersonaje);
    void eliminacionPersonajesLogica(const int &posIndice);
    int activacionLogica(std::string& nomPersonaje, std::string &username, const int& posIndice);
    bool cuentaPersonajeLineal(std::string& nomPersonaje, std::string &username);
    void guardarEnDisco();
    void cargarDesdeDisco();
    int getCont();
    int buscar(const std::string& nomPersonaje);
    void eliminarNodo(const std::string& nomPersonaje);
    bool existePersonaje(std::string &nomPersonaje);
    std::string toString();
    std::string personajesJugador(const int &pos);
    NodoInvertida* operator[](const int &pos);
};

#endif // LISTAINVERTIDA_H
