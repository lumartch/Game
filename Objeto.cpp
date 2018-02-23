#include "Objeto.h"

Objeto::Objeto() {
    strcpy(nombre, "");
    strcpy(descripcion, "");
    precio = 0;
}

void Objeto::setNombre(const std::string& nombre) {
    strcpy(this->nombre, nombre.c_str());
}

void Objeto::setDescripcion(const std::string& descripcion) {
    strcpy(this->descripcion, descripcion.c_str());
}

void Objeto::setPrecio(const long int& precio) {
    this->precio = precio;
}

char* Objeto::getNombre() {
    return nombre;
}

char* Objeto::getDescripcion() {
    return descripcion;
}

long int Objeto::getPrecio() {
    return precio;
}

std::string Objeto::toString() {
    std::string res = "Objeto: " + std::string(nombre) +  "\nDescripcion: " + std::string(descripcion) +
                       "\nPrecio: " + std::to_string(precio);
    return res;
}


Objeto::~Objeto() {
    //dtor
}
