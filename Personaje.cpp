#include "Personaje.h"

Personaje::Personaje() {
    strcpy(usernameOwner, "");
    strcpy(nombre, "" );
    strcpy(genero, "");
    strcpy(rol, "");
    strcpy(raza, "");
    strcpy(arma, "N/A");
    strcpy(equipo, "N/A");
    experiencia = 0;
    historial = "N/A";
}

Personaje::~Personaje() {
    //dtor
}
void Personaje::setNombre(const std::string& nombre) {
    strcpy(this->nombre, nombre.c_str());
}

void Personaje::setGenero(const std::string& gen) {
    strcpy(genero, gen.c_str());
}

void Personaje::setRol(const std::string& r) {
    strcpy(rol, r.c_str());
}

void Personaje::setRaza(const std::string& raza) {
    strcpy(this->raza, raza.c_str());
}

void Personaje::setArma(const std::string& arma) {
    strcpy(this->arma, arma.c_str());
}

void Personaje::setEquipo(const std::string& equipo) {
    strcpy(this->equipo, equipo.c_str());
}

void Personaje::setExperiencia(const long int& exp) {
    experiencia = exp;
}

void Personaje::setHistorial(const std::string& historial) {
    this->historial = historial;
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

char* Personaje::getArma() {
    return arma;
}

char* Personaje::getEquipo() {
    return equipo;
}

long int Personaje::getExperiencia() {
    return experiencia;
}

std::string Personaje::getHistorial() {
    return historial;
}

std::string Personaje::toString() {
    std::string res = "Nombre: " + std::string(nombre) +
                      "\nGenero: " + std::string(genero) +
                      "\nRol: "+ std::string(rol) +
                      "\nRaza: " + std::string(raza) +
                      "\nArma: " + std::string(arma) +
                      "\nEquipo: " + std::string(equipo) +
                      "\nExperiencia: " + std::to_string(experiencia) +
                      "\nHistorial: " + historial;
    return res;
}

void Personaje::setUsernameOwner(const std::string& usernameOwner) {
    strcpy(this->usernameOwner, usernameOwner.c_str());
}

char* Personaje::getUsernameOwner() {
    return usernameOwner;
}
