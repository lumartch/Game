#include "ListaInventario.h"

ListaInventario::ListaInventario() {
    cont = 0;
    ultimo = -1;
}
bool ListaInventario::estaVacia() {
    return ultimo == -1;
}

bool ListaInventario::estaLlena() {
    return ultimo == 49;
}

void ListaInventario::insertar(const int& pos, const Arma& arma) {
    if(estaLlena() or pos <-1 or pos > ultimo) {
        //std::cout << "Desbordamiento de datos.";
        return;
    }
    int i = ultimo;
    while(i > pos) {
        inventario[i + 1] = inventario[i];
        i--;
    }
    inventario[pos + 1] = arma;
    ultimo++;
}

void ListaInventario::eliminar(const int& pos) {
    if(estaVacia() or pos < 0 or pos > ultimo) {
        //std::cout << "Insuficiencia de datos.";
        return;
    }
    int i = pos;
    while(i < ultimo) {
        inventario[i] = inventario[i+1];
        i++;
    }
    ultimo--;
}

int ListaInventario::primerPos() {
    if(estaVacia()) {
        return -1;
    }
    return 0;
}

int ListaInventario::ultimaPos() {
    return ultimo;
}

int ListaInventario::posSiguiente(const int& pos) {
    if(estaVacia() or pos < 0 or pos > ultimo-1) {
        //throw ListException("Insuficiencia de datos al hacer posSiguiente.");
        return -1;
    }
    return pos + 1;
}

int ListaInventario::posAnterior(const int& pos) {
    if(estaVacia() or pos < 1 or pos > ultimo) {
        //throw ListException("Insuficiencia de datos al hacer posAnterior.");
        return -1;
    }
    return pos - 1;
}

int ListaInventario::encontrar(const int& pos) {
    return -1;
}

Arma& ListaInventario::operator[](const int& pos) {
    if(estaVacia() or pos < 1 or pos > ultimo) {
        return inventario[-1];
    }
    return inventario[pos];
}

std::string ListaInventario::toString() {
    if(estaVacia()) {
        return "El inventario se encuentra vacio.\n";
    }
    std::string res;
    for(int i = 0; i <= ultimo; i++) {
        res += std::to_string(i+1) + ") " + inventario[i].toString()  +  "\n";
    }
    return res;
}

void ListaInventario::borrarTodo() {
    ultimo = -1;
}

void ListaInventario::leerDelDisco(const std::string &archivo) {
    std::ifstream file(archivo);
    std::string auxStr;
    Arma arma;
    if(file.good()){
        while(!file.eof()){
            getline(file, auxStr, '|');
            arma.setNombre(auxStr);
            getline(file, auxStr, '|');
            arma.setDescripcion(auxStr);
            getline(file, auxStr, '|');
            arma.setAtaque(atoi(auxStr.c_str()));
            getline(file, auxStr, '\n');
            arma.setPrecio(atoi(auxStr.c_str()));
            if(file.eof()){break;}
            insertar(ultimaPos(), arma);
        }
    }
    else{
        std::ofstream fout(archivo);
        fout.close();
    }
    file.close();
}

void ListaInventario::escribirAlDisco(const std::string &archivo) {
    std::ofstream file(archivo);
    for(int i = 0; i < ultimo; i++){
        file << inventario[i].toFile();
    }
    file.close();
}


ListaInventario::~ListaInventario() {
    //dtor
}
