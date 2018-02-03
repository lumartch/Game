#include "Cuenta.h"

Cuenta::Cuenta() {
    username = "";
    nombre = "";
    correo = "";
    passwd = "";
}


Cuenta::Cuenta(std::string cuentaString) {
    string usr, email, name, pass;
    int i;
    for(i = 0; cuentaString[i] != '|'; i++){
        name += cuentaString[i];
    }
    for(i++; cuentaString[i] != '|'; i++){
        usr += cuentaString[i];
    }
    for(i++; cuentaString[i] != '|'; i++){
        email += cuentaString[i];
    }
    for(i++; cuentaString[i] != '\0'; i++){
        pass += cuentaString[i];
    }
    nombre = name;
    username = usr;
    correo = email;
    passwd = pass;
}

Cuenta::Cuenta(string username, string correo, string nombre, string passwd){
    this->username = username;
    this->correo = correo;
    this->nombre = nombre;
    this->passwd = passwd;
}

Cuenta::~Cuenta() {
    //dtor
}

void Cuenta::setUserName(std::string& user){
    username = user;
}

void Cuenta::setCorreo(std::string& email){
    correo = email;
}

void Cuenta::setNombre(std::string& name){
    nombre = name;
}

void Cuenta::setPasswd(std::string& pass){
    passwd = pass;
}

std::string Cuenta::getUserName(){
    return username;
}

std::string Cuenta::getCorreo(){
    return correo;
}

std::string Cuenta::getNombre(){
    return nombre;
}

std::string Cuenta::getPasswd(){
    return passwd;
}

string Cuenta::toString(){
    string r = "";
    r = "Username: " + username + "\nNombre: " + nombre + "\nCorreo Electronico: " + correo;
    return r;
}

string Cuenta::toFile(){
    string r = "";
    r = nombre + "|" + username + "|" + correo + "|" + passwd;
    return r;
}

