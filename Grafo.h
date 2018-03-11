#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class Vertice;
class Arista;
class Referencia;

class Referencia{
private:
    int peso;
    char actual[20];
    char siguiente[20];
public:
    Referencia();
    Referencia(const int &peso);
    void setPeso(const int& peso);
    int getPeso();
    void setActual(const char* actual);
    char* getActual();
    void setSiguiente(const char* siguiente);
    char* getSiguiente();
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
    Arista *sigArista;
    Vertice *sigVertice;
public:
    Vertice();
    Vertice(const std::string & nombre);
    void setNombre(const std::string &nombre);
    char* getNombre();
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
    void insertarVertice(Vertice* verPos, std::string &nombre);
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
