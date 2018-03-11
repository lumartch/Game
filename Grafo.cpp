#include "Grafo.h"

Referencia::Referencia() {
    peso = 0;
    strcpy(actual, "");
    strcpy(siguiente, "");
}

Referencia::Referencia(const int& peso) : Referencia() {
    this->peso = peso;
}

void Referencia::setPeso(const int& peso) {
    this->peso = peso;
}

int Referencia::getPeso() {
    return peso;
}

void Referencia::setActual(const char* actual) {
    strcpy(this->actual, actual);
}

char* Referencia::getActual() {
    return actual;
}

void Referencia::setSiguiente(const char* siguiente) {
    strcpy(this->siguiente, siguiente);
}

char* Referencia::getSiguiente() {
    return siguiente;
}

Arista::Arista() {
    siguiente = nullptr;
    origen = nullptr;
    destino = nullptr;
}

Arista::Arista(const Referencia& refer) : Arista() {
    this->refer = refer;
}

void Arista::setReferencia(const Referencia& refer) {
    this->refer = refer;
}

Referencia& Arista::getReferencia() {
    return refer;
}

void Arista::setSiguiente(Arista* siguiente) {
    this->siguiente = siguiente;
}

Arista* Arista::getSiguiente() {
    return siguiente;
}

void Arista::setOrigen(Vertice* origen) {
    this->origen = origen;
}

Vertice* Arista::getOrigen() {
    return origen;
}

void Arista::setDestino(Vertice* destino) {
    this->destino = destino;
}

Vertice* Arista::getDestino() {
    return destino;
}

Vertice::Vertice() {
    sigArista = nullptr;
    sigVertice = nullptr;
}

Vertice::Vertice(const std::string& nombre) : Vertice() {
    strcpy(this->nombre, nombre.c_str());
}

void Vertice::setNombre(const std::string& nombre) {
    strcpy(this->nombre, nombre.c_str());
}

char* Vertice::getNombre() {
    return nombre;
}

void Vertice::setSigVertice(Vertice* sigVertice) {
    this->sigVertice = sigVertice;
}

Vertice* Vertice::getSigVertice() {
    return sigVertice;
}

void Vertice::setSigArista(Arista* sigArista) {
    this->sigArista = sigArista;
}

Arista* Vertice::getSigArista() {
    return sigArista;
}

Grafo::Grafo() {
    primero = nullptr;
    contVertices = 0;
}

Grafo::~Grafo() {
    borrarTodo();
}

void Grafo::insertarVertice(Vertice* verPos, std::string & nombre) {
    if(existeVertice(nombre)) {
        return;
    }
    Vertice* aux(new Vertice(nombre));
    if(verPos == nullptr) {
        aux->setSigVertice(primero);
        primero = aux;
    } else {
        aux->setSigVertice(verPos->getSigVertice());
        verPos->setSigVertice(aux);
    }
    contVertices++;
}

Vertice* Grafo::verticePrimerPos() {
    return primero;
}

Vertice* Grafo::verticePosSiguiente(Vertice* pos) {
    if(estaVacioGrafo() or pos == nullptr) {
        return nullptr;
    }
    return pos->getSigVertice();
}

Vertice* Grafo::verticePosAnterior(Vertice* pos) {
    if(estaVacioGrafo() or pos == nullptr) {
        return nullptr;
    }
    Vertice *aux(primero);
    while(aux->getSigVertice() != pos and aux != nullptr) {
        aux = aux->getSigVertice();
    }
    return aux;
}

Vertice* Grafo::verticeUltimaPos() {
    if(estaVacioGrafo()) {
        return nullptr;
    }
    Vertice* aux(primero);
    while(aux->getSigVertice() != nullptr) {
        aux = aux->getSigVertice();
    }
    return aux;
}

Vertice* Grafo::regresaVertice(const std::string & nombre) {
    Vertice* aux(primero);
    while(aux != nullptr) {
        std::string auxNombre = aux->getNombre();
        if(auxNombre == nombre) {
            return aux;
        }
        aux = aux->getSigVertice();
    }
    return nullptr;
}

bool Grafo::existeVertice(const std::string& nombre) {
    Vertice *aux(primero);
    while(aux != nullptr) {
        std::string auxNombre = aux->getNombre();
        if(auxNombre == nombre) {
            return true;
        }
        aux = aux->getSigVertice();
    }
    return false;
}

void Grafo::eliminarVertice(Vertice* vertice) {
    if(estaVacioGrafo() or vertice == nullptr) {
        return;
    }
    //Borra adyacencias del vertice
    borrarAdyacencias(vertice);
    //Borra adyacencia del resto de vertices
    Vertice* aux(primero);
    while(aux != nullptr) {
        borrarCoincidenciaAdyacente(aux, vertice);
        aux = aux->getSigVertice();
    }
    //Elimina el vertice
    if(vertice == primero) {
        primero = primero->getSigVertice();
    } else {
        verticePosAnterior(vertice)->setSigVertice(vertice->getSigVertice());
    }
    delete vertice;
    contVertices--;
}


void Grafo::insertaAdyacencia(Vertice* origen, Vertice* destino, const int& peso = 0) {
    if(existeAdyacencia(origen, destino)) {
        return;
    }
    Referencia refer(peso);
    Arista* aux(new Arista(refer));
    Arista* ultimaPos = adyacenciaUltimaPos(origen);
    Arista* primerPos = adyacenciaPrimerPos(origen);
    if(ultimaPos == nullptr) {
        aux->setSiguiente(primerPos);
        primerPos = aux;
        origen->setSigArista(primerPos);
    } else {
        aux->setSiguiente(ultimaPos->getSiguiente());
        ultimaPos->setSiguiente(aux);
    }
    aux->setOrigen(origen);
    aux->setDestino(destino);
}

Arista* Grafo::adyacenciaPrimerPos(Vertice* origen) {
    Arista* aux(origen->getSigArista());
    return aux;
}

Arista* Grafo::adyacenciaPosSiguiente(Vertice* origen, Arista* pos) {
    Arista* aux(origen->getSigArista());
    if(aux == nullptr or pos == nullptr) {
        return nullptr;
    }
    return pos->getSiguiente();
}

Arista* Grafo::adyacenciaPosAnterior(Vertice* origen, Arista* pos) {
    Arista* aux(origen->getSigArista());
    if(aux == nullptr or pos == nullptr) {
        return nullptr;
    }
    while(aux != nullptr and aux->getSiguiente() != pos) {
        aux = aux->getSiguiente();
    }
    return aux;
}

Arista* Grafo::adyacenciaUltimaPos(Vertice* origen) {
    if(origen->getSigArista() == nullptr) {
        return nullptr;
    }
    Arista* aux(origen->getSigArista());
    while(aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    return aux;
}

Arista* Grafo::regresaAdyacencia(Vertice* origen, Vertice* destino) {
    Arista* aux(origen->getSigArista());
    while(aux != nullptr) {
        if(aux->getDestino() == destino) {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

bool Grafo::existeAdyacencia(Vertice* origen, Vertice* destino) {
    Arista* aux(origen->getSigArista());
    while(aux != nullptr) {
        if(aux->getDestino() == destino) {
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

void Grafo::eliminarAdyacencia(Vertice* origen, Arista* adyacencia) {
    if(estaVacioGrafo() or adyacencia == nullptr) {
        return;
    }
    Arista* primerPos = adyacenciaPrimerPos(origen);
    if(adyacencia == primerPos) {
        //primero = primero->getSigVertice();
        origen->setSigArista(primerPos->getSiguiente());
    } else {
        adyacenciaPosAnterior(origen, adyacencia)->setSiguiente(adyacencia->getSiguiente());
    }
    delete adyacencia;
}

bool Grafo::estaVacioGrafo() {
    return primero == nullptr;
}

int Grafo::getNumVertices() {
    return contVertices;
}

void Grafo::guardar(const std::string& archivoVertice, const std::string& archivoArista) {
    std::remove(archivoVertice.c_str());
    std::remove(archivoArista.c_str());
    std::ofstream file_vertices(archivoVertice);
    Vertice* aux(primero);
    while(aux != nullptr) {
        //Guardado de vertices
        char origen[20];
        strcpy(origen, aux->getNombre());
        file_vertices.write((char*)&origen, sizeof(origen));
        //Guardadp de aristas
        std::ofstream file_Aristas(archivoArista, std::ios::app);
        Arista* auxArista(aux->getSigArista());
        while(auxArista != nullptr) {
            char destino[20];
            Referencia refer = auxArista->getReferencia();
            refer.setActual(origen);
            strcpy(destino, auxArista->getDestino()->getNombre());
            refer.setSiguiente(destino);
            file_Aristas.write((char*)&refer, sizeof(refer));
            auxArista = auxArista->getSiguiente();
        }
        file_Aristas.close();
        aux = aux->getSigVertice();
    }
    file_vertices.close();
}

void Grafo::cargar(const std::string& archivoVertice, const std::string& archivoArista) {
    borrarTodo();
    std::ifstream file_vertices(archivoVertice);
    if(file_vertices.good()) {
        while(!file_vertices.eof()) {
            char origen[20];
            file_vertices.read((char*)&origen, sizeof(origen));
            if(file_vertices.eof()) {
                break;
            }
            std::string nom = origen;
            insertarVertice(verticeUltimaPos(), nom);
        }
    }
    file_vertices.close();


    std::ifstream file_aristas(archivoArista);
    if(file_aristas.good()) {
        while(!file_aristas.eof()) {
            Referencia refer;
            file_aristas.read((char*)&refer, sizeof(refer));
            if(file_aristas.eof()) {
                break;
            }
            std::string orig = refer.getActual();
            std::string dest = refer.getSiguiente();
            int peso = refer.getPeso();
            Vertice *origen(regresaVertice(orig));
            Vertice *destino(regresaVertice(dest));
            insertaAdyacencia(origen, destino, peso);
        }
    }
    file_aristas.close();
}

std::string Grafo::toListaAdyacencia() {
    if(estaVacioGrafo()) {
        return "Esta vacio el grafo.\n";
    }
    std::string res;
    Vertice* aux = primero;
    while(aux != nullptr) {
        std::string origen = (aux->getNombre());
        if(aux->getSigVertice() != nullptr) {
            res += origen + toStringAdyacencias(aux) + "\n" + "|\n";
        } else {
            res += origen + toStringAdyacencias(aux) + "\n";
        }
        aux = aux->getSigVertice();
    }
    return res;
}

std::string Grafo::toStringVertices() {
    if(estaVacioGrafo()) {
        return "Esta vacio el grafo.\n";
    }
    std::string res;
    Vertice* aux = primero;
    while(aux != nullptr) {
        if(aux->getSigVertice() != nullptr) {
            res += std::string(aux->getNombre()) + "| ";
        } else {
            res += std::string(aux->getNombre());
        }
        aux = aux->getSigVertice();
    }
    return res;
}

std::string Grafo::toStringAdyacencias(Vertice* origen) {
    std::string res;
    Arista* aux(origen->getSigArista());
    while(aux != nullptr) {
        res += "-->" + std::string(aux->getDestino()->getNombre()) + ":" + std::to_string(aux->getReferencia().getPeso());
        aux = aux->getSiguiente();
    }
    return res;
}

void Grafo::borrarTodo() {
    Vertice* aux(primero);
    while(aux != nullptr) {
        borrarAdyacencias(aux);
        aux = aux->getSigVertice();
    }
    borrarVertices();
}

void Grafo::borrarVertices() {
    Vertice* aux;
    while(primero != nullptr) {
        aux  = primero;
        primero = primero->getSigVertice();
        aux->setSigVertice(nullptr);
        aux->setSigVertice(nullptr);
        delete aux;
    }
    contVertices = 0;
}

void Grafo::borrarAdyacencias(Vertice* origen) {
    Arista* inicio = adyacenciaPrimerPos(origen);
    while(inicio != nullptr) {
        Arista* aux = inicio;
        inicio = inicio->getSiguiente();
        origen->setSigArista(inicio);
        delete aux;
    }
}

void Grafo::borrarCoincidenciaAdyacente(Vertice* origen, Vertice* destino) {
    Arista* inicio = adyacenciaPrimerPos(origen);
    Arista* aux;
    while(inicio != nullptr) {
        aux = inicio;
        inicio = inicio->getSiguiente();
        if(aux->getDestino() == destino) {
            if(aux == adyacenciaPrimerPos(origen)) {
                origen->setSigArista(aux->getSiguiente());
            } else {
                adyacenciaPosAnterior(origen, aux)->setSiguiente(aux->getSiguiente());
            }
            delete aux;
        }
    }
}

Vertice* Grafo::operator[](const int& pos) {
    Vertice* aux(primero);
    for(int i = 0; i < pos; i++) {
        aux = aux->getSigVertice();
    }
    return aux;
}

