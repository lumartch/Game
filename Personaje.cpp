#include "Personaje.h"

Personaje::Personaje() {
    strcpy(usernameOwner, "");
    strcpy(nombre, "" );
    strcpy(genero, "");
    strcpy(rol, "");
    strcpy(raza, "");
    strcpy(ubicacionActual, "");
    strcpy(equipo, "N/A");
    experiencia = 0;
    for(int i = 0; i < 3; i++) {
        misiones[i] = false;
    }
}

Personaje::~Personaje() {
    //dtor
}
void Personaje::setNombre(const std::string& nombre) {
    strcpy(this->nombre, nombre.c_str());
}

void Personaje::setGenero(const std::string& genero) {
    strcpy(this->genero, genero.c_str());
}

void Personaje::setRol(const std::string& rol) {
    strcpy(this->rol, rol.c_str());
}

void Personaje::setRaza(const std::string& raza) {
    strcpy(this->raza, raza.c_str());
}

void Personaje::setArma(const Arma& arma) {
    this->arma = arma;
}

void Personaje::setEquipo(const std::string& equipo) {
    strcpy(this->equipo, equipo.c_str());
}

void Personaje::setExperiencia(const long int& experiencia) {
    this->experiencia += experiencia;
}

char* Personaje::getNombre() {
    return nombre;
}

char* Personaje::getGenero() {
    return genero;
}

char* Personaje::getRol() {
    return rol;
}

char* Personaje::getRaza() {
    return raza;
}

Arma Personaje::getArma() {
    return arma;
}

char* Personaje::getEquipo() {
    return equipo;
}

long int Personaje::getExperiencia() {
    return experiencia;
}

void Personaje::setUsernameOwner(const std::string& usernameOwner) {
    strcpy(this->usernameOwner, usernameOwner.c_str());
}

char* Personaje::getUsernameOwner() {
    return usernameOwner;
}

void Personaje::setMision(const int& pos) {
    /*if(pos == 1){
        misiones[0] = true;
    }
    else if(pos == 2){
        misiones[1] = true;
    }
    else{
        misiones[2] = true;
    }*/
    misiones[pos] = true;
}

bool* Personaje::getMisiones() {
    return misiones;
}

void Personaje::setUbicacionActual(const std::string& ubicacionActual) {
    strcpy(this->ubicacionActual, ubicacionActual.c_str());
}

char* Personaje::getUbicacionActual() {
    return ubicacionActual;
}
