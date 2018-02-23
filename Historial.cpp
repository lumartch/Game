#include "Historial.h"

Historial::Historial() {
    strcpy(descripcion, "");
    experiencia = 0;
}
void Historial::setDescripcion(const std::string& descripcion) {
    strcpy(this->descripcion, descripcion.c_str());
}

void Historial::setExperiencia(const long int& experiencia) {
    this->experiencia = experiencia;
}

char* Historial::getDescipcion() {
    return descripcion;
}

long int Historial::getExperiencia() {
    return experiencia;
}

std::string Historial::toString() {
    std::string res = "Mision: " + std::string(titulo) +
                    "\nDescripcion: " + std::string(descripcion) +
                    "\nExperiencia: " + std::to_string(experiencia);
    return res;
}

void Historial::setTitulo(const std::string& titulo) {
    strcpy(this->titulo, titulo.c_str());
}

char* Historial::getTitulo() {
    return titulo;
}


Historial::~Historial() {
    //dtor
}
