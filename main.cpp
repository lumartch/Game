#include <iostream>
#include "Cuenta.h"
#include "Lista.h"

using namespace std;

int main() {
    Cuenta cl("asd","asd","asd","asd");

    Lista listaCuentas;
    listaCuentas.inserta(cl);
    listaCuentas.mostrarTodo();
    return 0;
}
