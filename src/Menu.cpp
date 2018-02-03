#include "Menu.h"

Menu::Menu() {
    menuPrincipal();
}

Menu::~Menu() {
    //dtor
}

void Menu::menuPrincipal() {
    string opc;
    do {
        system("clear");
        cout << "***Menu de cuentas***" << endl << endl;
        cout << "1) Agregar usuario." << endl;
        cout << "2) Acceder." << endl;
        cout << "3) Mostrar todo." << endl;
        cout << "4) Salir." << endl;
        do {
            cout << "Elige una opcion: ";
            getline(cin, opc);
            if(opc != "1" and opc != "2" and opc != "3" and opc != "4") {
                cout << endl << "La opcion es invalida. Intente de nuevo." << endl << endl;
            }
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
        if(opc == "1") {
            agregar();
        } else if(opc == "2") {
            acceder();
        } else if(opc == "3") {
            mostrarTodo();
        } else {
            listaCuentas.guardarEnDisco();
            salir();
        }
        if(opc != "2") {
            pausa();
        }
    } while(opc != "4");
}

void Menu::acceder() {
    string auxUser, auxPass;
    cout << endl <<"Ingrese el username: ";
    getline(cin, auxUser);
    cout << "Ingrese la contraseña: ";
    getline(cin, auxPass);
    if(!listaCuentas.cuentaCorrecta(auxUser, auxPass)) {
        cout << endl << endl << "La cuenta no existe o la contraseña no coincide. Intente de nuevo." << endl;
        pausa();
        return;
    }
    int pos = listaCuentas.busqueda(auxUser);
    string opc;
    do {
        system("clear");
        cout << "***Menu Acceder***" << endl;
        cout << "1) Mostrar." << endl;
        cout << "2) Modificar." << endl;
        cout << "3) Eliminar." << endl;
        cout << "4) Regresar al menu principal." << endl;
        do {
            cout << "Elige una opcion: ";
            getline(cin, opc);
            if(opc != "1" and opc != "2" and opc != "3" and opc != "4") {
                cout << endl << "La opcion es invalida. Intente de nuevo." << endl << endl;
            }
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
        if(opc == "1") {
            mostrar(pos);
        } else if(opc == "2") {
            modificarMenu(pos);
        } else if(opc == "3") {
            eliminar(pos);
            pausa();
            return;
        } else {
            cout << endl << "Regresando al menu principal..." << endl;
        }
        if(opc != "2") {
            pausa();
        }
    } while(opc != "4");
}

void Menu::agregar() {
    system("clear");
    cout << "***Agregar cuenta***" << endl << endl;
    string auxStr, auxPass;
    Cuenta auxCuenta;
    do {
        cout << "Ingrese le username: ";
        getline(cin, auxStr);
        if(!usernameValido(auxStr)) {
            cout << "Cuenta ya existente, o vacia. Intente de nuevo." << endl;
        }
    } while(!usernameValido(auxStr));
    auxCuenta.setUserName(auxStr);

    do {
        cout << "Ingrese el nombre real: ";
        getline(cin, auxStr);
        if(!nombreValido(auxStr)) {
            cout << "El nombre es invalido, o vacio. Intente de nuevo." << endl;
        }
    } while(!nombreValido(auxStr));
    auxCuenta.setNombre(auxStr);

    do {
        cout << "Ingrese el email: ";
        getline(cin, auxStr);
        if(!correoValido(auxStr)) {
            cout << "El correo es invalido, o vacio. Intente de nuevo." << endl;
        }
    } while(!correoValido(auxStr));
    auxCuenta.setCorreo(auxStr);
    do {
        cout << "Ingrese su contraseña: ";
        getline(cin, auxStr);
        cout << "Confirme su contraseña: ";
        getline(cin, auxPass);
        if(auxStr != auxPass) {
            cout << endl << "La contraseña ingresada no coincide. intente de nuevo." << endl;
        }
    } while(auxStr != auxPass);
    auxCuenta.setPasswd(auxStr);

    listaCuentas.inserta(auxCuenta);
}

void Menu::eliminar(const int &pos) {
    system("clear");
    string auxStr = listaCuentas[pos].getUserName();
    cout << "***Eliminar cuenta***" << endl << endl;
    listaCuentas.eliminarDato(auxStr);
    cout << "Dato eliminado exitosamente." << endl;
}

void Menu::modificarMenu(const int &pos) {
    string opc, auxStr;
    do {
        system("clear");
        cout << "Modificar cuenta***" << endl;
        cout << listaCuentas[pos].toString() << endl << endl;
        cout << "Que desea modificar?" << endl;
        cout << "1) Nombre." << endl;
        cout << "2) Correo electronico." << endl;
        cout << "3) Password." << endl;
        cout << "4) Regresar al menu anterior..." << endl;
        do {
            cout << "Elije una opcion: ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4");
        if(opc == "1") {
            do {
                cout << endl << "Ingrese el nuevo nombre: ";
                getline(cin, auxStr);
                if(!nombreValido(auxStr)) {
                    cout << endl << "Formato erroneo de nombre. Intente de nuevo." << endl;
                }
            } while(!nombreValido(auxStr));

            listaCuentas[pos].setNombre(auxStr);
        } else if(opc == "2") {
            do {
                cout << endl << "Ingrese el nuevo correo: ";
                getline(cin, auxStr);
                if(!correoValido(auxStr)) {
                    cout << endl << "Formato erroneo del correo. Intente de nuevo." << endl;
                }
            } while(!correoValido(auxStr));
            listaCuentas[pos].setCorreo(auxStr);
        } else if(opc == "3") {
            string auxPass;
            do {
                cout << endl << "Ingrese la nueva contraseña: ";
                getline(cin, auxStr);
                cout << "Confirme su contraseña: ";
                getline(cin, auxPass);
                if(auxStr != auxPass) {
                    cout << endl << "La contraseña ingresada no coincide. intente de nuevo." << endl;
                }
            } while(auxStr != auxPass);
            listaCuentas[pos].setPasswd(auxStr);
        } else {
            cout << endl << "Regresando al menú acceder...";
        }
        pausa();
    } while(opc != "4");
}

void Menu::mostrar(const int &pos) {
    system("clear");
    string auxStr;
    cout << "***Mostrar usuario***" << endl << endl;
    cout << endl << listaCuentas[pos].toString() << endl;
}

void Menu::mostrarTodo() {
    system("clear");
    cout << "***Mostrar cuentas***" << endl << endl;
    for(int i = 0; i < listaCuentas.getCont(); i++) {
        cout << "Usuario #" << i + 1 << endl;
        cout << listaCuentas[i].toString() << endl << endl;
    }
}

void Menu::salir() {
    cout << endl << endl << "Gracias por usar el asistente de cuentas." << endl;
}

void Menu::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.get();
}

bool Menu::usernameValido(std::string &username) {
    for(int i = 0; i < listaCuentas.getCont(); i++) {
        if(listaCuentas[i].getUserName() == username or username.length() <= 0) {
            return false;
        }
    }
    return true;
}

bool Menu::correoValido(std::string &correo) {
    regex rx("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(regex_match(correo, rx) == true and correo.length() > 0) {
        return true;
    }
    return false;
}

bool Menu::nombreValido(std::string &nombre) {
    regex rx("[a-zA-Z ]*");
    if(regex_match(nombre, rx) == true and nombre.length() > 0) {
        return true;
    }
    return false;
}

bool Menu::passwdValido(std::string &password) {
    return false;
}
