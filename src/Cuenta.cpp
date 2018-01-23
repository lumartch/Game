#include "Cuenta.h"

Cuenta::Cuenta() {
    //ctor
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

string Cuenta::toString(){
    string r = "";
    r = nombre + "|" + username + "|" + correo;
    return r;
}
