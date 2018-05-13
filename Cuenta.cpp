#include "Cuenta.h"

Cuenta::Cuenta() {
    username = "";
    nombre = "";
    correo = "";
    passwd = "";
    posIndice = -1;
    maxPersonajes = 3;
}


Cuenta::Cuenta(std::string cuentaString) {
    std::string usr, email, name, pass, auxPosIndice, auxMaximo;
    int i;
    for(i = 0; cuentaString[i] != '|'; i++) {
        name += cuentaString[i];
    }
    for(i++; cuentaString[i] != '|'; i++) {
        usr += cuentaString[i];
    }
    for(i++; cuentaString[i] != '|'; i++) {
        email += cuentaString[i];
    }
    for(i++; cuentaString[i] != '|'; i++) {
        pass += cuentaString[i];
    }
    for(i++; cuentaString[i] != '|'; i++) {
        auxPosIndice += cuentaString[i];
    }
    for(i++; cuentaString[i] != '\0'; i++) {
        auxMaximo += cuentaString[i];
    }
    nombre = name;
    username = usr;
    correo = email;
    passwd = pass;
    posIndice = atoi(auxPosIndice.c_str());
    maxPersonajes = atoi(auxMaximo.c_str());
}

Cuenta::Cuenta(std::string username, std::string correo, std::string nombre, std::string passwd, long int &posIndice, int &maxPersonajes) {
    this->username = username;
    this->correo = correo;
    this->nombre = nombre;
    this->passwd = passwd;
    this->posIndice = posIndice;
    this->maxPersonajes = maxPersonajes;
}

Cuenta::~Cuenta() {
    //dtor
}

void Cuenta::setUserName(std::string& user) {
    username = user;
}

void Cuenta::setCorreo(std::string& email) {
    correo = email;
}

void Cuenta::setNombre(std::string& name) {
    nombre = name;
}

void Cuenta::setPasswd(std::string& pass) {
    passwd = pass;
}

std::string Cuenta::getUserName() {
    return username;
}

std::string Cuenta::getCorreo() {
    return correo;
}

std::string Cuenta::getNombre() {
    return nombre;
}

std::string Cuenta::getPasswd() {
    return passwd;
}

std::string Cuenta::toString() {
    std::string r = "";
    r = "Username: " + username + "\nNombre: " + nombre + "\nCorreo Electronico: " + correo + "\nMaximo de personajes: " + std::to_string(maxPersonajes) + "\nSiguiente Lista invertida: " + std::to_string(posIndice);
    return r;
}

std::string Cuenta::toFile() {
    std::string r = "";
    r = nombre + "|" + username + "|" + correo + "|" + passwd + "|" + std::to_string(posIndice) + "|" + std::to_string(maxPersonajes);
    return r;
}

void Cuenta::setPosIndice(const long int& posIndice) {
    this->posIndice = posIndice;
}

long int Cuenta::getPosIndice() {
    return posIndice;
}

void Cuenta::setMaxPersonajes(const int& maxPersonajes) {
    this->maxPersonajes = maxPersonajes;
}

int Cuenta::getMaxPersonajes() {
    return maxPersonajes;
}


