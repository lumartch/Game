#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <cstring>
#include "Inventario.h"

class Personaje {
public:
    Personaje();
    void setUsernameOwner(const std::string &usernameOwner);
    void setNombre(const std::string & nombre);
    void setGenero(const std::string & genero);
    void setRol(const std::string &rol);
    void setRaza(const std::string &raza);
    void setArma(const std::string &arma);
    void setEquipo(const std::string &equipo);
    void setExperiencia(const long int &exp);
    void setHistorial(const std::string &historial);
    char* getUsernameOwner();
    char* getNombre();
    char* getGenero();
    char* getRol();
    char* getRaza();
    char* getArma();
    char* getEquipo();
    long int getExperiencia();
    std::string getHistorial();
    std::string toString();
    virtual ~Personaje();

private:
    char usernameOwner[30];
    char nombre[30];
    char genero[10];
    char rol[30];
    char raza[30];
    char arma[30];
    char equipo[30];
    Inventario inventario;
    long int experiencia;
    std::string historial;
};

#endif // PERSONAJE_H
