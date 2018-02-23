#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <string>
#include <cstring>

class Historial
{
    public:
        Historial();
        void setTitulo(const std::string & titulo);
        void setDescripcion(const std::string & descripcion);
        void setExperiencia(const long int& experiencia);
        char* getTitulo();
        char* getDescipcion();
        long int getExperiencia();
        std::string toString();
        virtual ~Historial();

    private:
        char titulo[20];
        char descripcion[100];
        long int experiencia;
};

#endif // HISTORIAL_H
