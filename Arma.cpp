#include "Arma.h"

Arma::Arma() {
    strcpy(nombre, "Ninguna");
    strcpy(descripcion, "Para obtener un arma, necesitas explorar.");
    ataque = 0;
    precio = 0;
}

Arma::~Arma() {
    //dtor
}
void Arma::setNombre(const std::string& nombre) {
    strcpy(this->nombre, nombre.c_str());
}

void Arma::setDescripcion(const std::string& descripcion) {
    strcpy(this->descripcion, descripcion.c_str());
}

void Arma::setPrecio(const int& precio) {
    this->precio = precio;
}

void Arma::setAtaque(const int& ataque) {
    this->ataque = ataque;
}

char* Arma::getNombre() {
    return nombre;
}

char* Arma::getDescripcion() {
    return descripcion;
}

int Arma::getPrecio() {
    return precio;
}

int Arma::getAtaque() {
    return ataque;
}

std::string Arma::toString() {
    std::string res;
    res += std::string(nombre) + "| Ataque: " + std::to_string(ataque) + "| Precio: " + std::to_string(precio);
    res += "\nDescripcion: " + std::string(descripcion);
    return res;
}

std::string Arma::toFile() {
    std::string res;
    res += std::string(nombre) + "|" + std::string(descripcion) + "|" + std::to_string(ataque) + "|" + std::to_string(ataque) + "\n";
    return res;
}

