#ifndef ARMA_H
#define ARMA_H

#include <string>
#include <cstring>

class Arma{
public:
    Arma();
    void setNombre(const std::string &nombre);
    void setDescripcion(const std::string &descripcion);
    void setPrecio(const int &precio);
    void setAtaque(const int &ataque);
    char* getNombre();
    char* getDescripcion();
    int getPrecio();
    int getAtaque();
    std::string toString();
    std::string toFile();
    virtual ~Arma();

private:
    char nombre[30];
    char descripcion[200];
    int ataque;
    int precio;
};


#endif // ARMA_H
