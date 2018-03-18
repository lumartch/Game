#ifndef GRAFO_H
#define GRAFO_H

#include "Arma.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class Vertice;
class Arista;
class Referencia;

class Referencia{
private:
    int nivelNecesario;
    char origen[20];
    char destino[20];

public:
    Referencia();
    Referencia(const int &nivelNecesario);
    void setNivelNecesario(const int& nivelNecesario);
    int getNivelNecesario();
    void setOrigen(const char* origen);
    char* getOrigen();
    void setDestino(const char* destino);
    char* getDestino();
};

class Arista {
private:
    Referencia refer;
    Arista *siguiente;
    Vertice *origen;
    Vertice *destino;
public:
    Arista();
    Arista(const Referencia & refer);
    void setReferencia(const Referencia& refer);
    Referencia& getReferencia();
    void setSiguiente(Arista* siguiente);
    Arista* getSiguiente();
    void setOrigen(Vertice* origen);
    Vertice* getOrigen();
    void setDestino(Vertice* destino);
    Vertice* getDestino();
};

class Vertice{
private:
    char nombre[20];
    char tipoClima[20];
    char dificultad[20];
    Arma recompensa;
    Arista *sigArista;
    Vertice *sigVertice;
public:
    Vertice();
    Vertice(const std::string & nombre, const std::string &tipoClima, const std::string& dificultad, const Arma& recompensa);
    void setNombre(const std::string &nombre);
    char* getNombre();
    void setTipoClima(const std::string &tipoClima);
    char* getTipoClima();
    void setDificultad(const std::string &dificultad);
    char* getDificultad();
    void setRecompensa(const Arma &recompensa);
    Arma getRecompensa();
    void setSigVertice(Vertice* sigVertice);
    Vertice* getSigVertice();
    void setSigArista(Arista* sigArista);
    Arista* getSigArista();
};

class Grafo {
private:
    int contVertices;
    Vertice* primero;
public:
    Grafo();
    //Vertices
    void insertarVertice(Vertice* verPos, std::string &nombre, std::string &tipoClima, std::string &dificultad, Arma& recompensa);
    Vertice* verticePrimerPos();
    Vertice* verticePosSiguiente(Vertice* pos);
    Vertice* verticePosAnterior(Vertice* pos);
    Vertice* verticeUltimaPos();
    Vertice* regresaVertice(const std::string &nombre);
    void eliminarVertice(Vertice *vertice);
    bool existeVertice(const std::string &nombre);
    //Aristas
    void insertaAdyacencia(Vertice* origen, Vertice* destino, const int& peso);
    Arista* adyacenciaPrimerPos(Vertice* origen);
    Arista* adyacenciaPosSiguiente(Vertice* origen, Arista* pos);
    Arista* adyacenciaPosAnterior(Vertice* origen, Arista* pos);
    Arista* adyacenciaUltimaPos(Vertice* origen);
    Arista* regresaAdyacencia(Vertice* origen, Vertice* destino);
    void eliminarAdyacencia(Vertice* origen, Arista* adyacencia);
    bool existeAdyacencia(Vertice* origen, Vertice* destino);

    bool estaVacioGrafo();
    int getNumVertices();

    std::string toListaAdyacencia();
    std::string toStringVertices();
    std::string toStringAdyacencias(Vertice* origen);

    Vertice* operator[](const int&pos);

    void borrarTodo();
    void borrarVertices();
    void borrarAdyacencias(Vertice* origen);
    void borrarCoincidenciaAdyacente(Vertice* origen, Vertice* destino);
    void guardar(const std::string& archivoVertice, const std::string& archivoArista);
    void cargar(const std::string& archivoVertice, const std::string& archivoArista);
    virtual ~Grafo();
};


#endif // GRAFO_H
