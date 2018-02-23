#ifndef OBJETO_H
#define OBJETO_H

#include <string>
#include <cstring>

class Objeto {
public:
    Objeto();
    void setNombre(const std::string &nombre);
    void setDescripcion(const std::string &descripcion);
    void setPrecio(const long int &precio);
    char* getNombre();
    char* getDescripcion();
    long int getPrecio();
    std::string toString();
    virtual ~Objeto();

private:
    char nombre[20];
    char descripcion[100];
    long int precio;
};

#endif // OBJETO_H
