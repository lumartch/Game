#include <iostream>
#include "Cuenta.h"
#include "Lista.h"

using namespace std;

int main() {
    Cuenta cl("Lumart","lumart@gmail.com","Luis","asd");

    Lista listaCuentas;
    listaCuentas.inserta(cl);
    listaCuentas.inserta(cl);
    listaCuentas.inserta(cl);
    //cout << listaCuentas.mostrarTodo();
    /*for(int i = 0; listaCuentas.getCont(); i++){
        cout << listaCuentas[i].toString() << endl;
    }*/
    listaCuentas.guardarEnDisco();
    return 0;
}
