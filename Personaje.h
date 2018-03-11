#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Arma.h"

#include <cstring>
#include <string>

class Personaje {
public:
    Personaje();
    void setUsernameOwner(const std::string &usernameOwner);
    void setNombre(const std::string & nombre);
    void setGenero(const std::string & genero);
    void setRol(const std::string &rol);
    void setRaza(const std::string &raza);
    void setArma(const Arma &arma);
    void setEquipo(const std::string &equipo);
    void setUbicacionActual(const std::string &ubicacionActual);
    void setExperiencia(const long int &exp);
    char* getUsernameOwner();
    char* getNombre();
    char* getGenero();
    char* getRol();
    char* getRaza();
    Arma getArma();
    char* getEquipo();
    char* getUbicacionActual();
    long int getExperiencia();
    void setMision(const int &pos);
    bool* getMisiones();
    virtual ~Personaje();

private:
    char usernameOwner[30];
    char nombre[30];
    char genero[10];
    char rol[30];
    char raza[30];
    Arma arma;
    char equipo[30];
    char ubicacionActual[30];
    long int experiencia;
    bool misiones[3];
};

#endif // PERSONAJE_H
