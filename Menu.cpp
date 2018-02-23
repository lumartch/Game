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
        cout << "3) Salir." << endl;
        cout << "0) Mostrar todo(Super usuario)." << endl;
        do {
            cout << "Elige una opcion: ";
            getline(cin, opc);
            if(opc != "1" and opc != "2" and opc != "3" and opc != "0") {
                cout << endl << "La opcion es invalida. Intente de nuevo." << endl << endl;
            }
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "0");
        if(opc == "1") {
            agregar();
        } else if(opc == "2") {
            acceder();
        } else if(opc == "0") {
            mostrarTodo();
        } else {
            listaCuentas.guardarEnDisco();
            salir();
        }
        if(opc != "2") {
            pausa();
        }
    } while(opc != "3");
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
        cout << "***Menu para el usuario " << listaCuentas[pos].getUserName() << "***" << endl << endl;
        cout << "1) Mostrar Cuenta." << endl;
        cout << "2) Modificar Cuenta." << endl;
        cout << "3) Eliminar Cuenta." << endl;
        cout << "4) Crear personaje." << endl;
        cout << "5) Eliminar personaje." << endl;
        cout << "6) Acceder a personaje." << endl;
        cout << "7) Regresar al menu principal." << endl;
        do {
            cout << "Elige una opcion: ";
            getline(cin, opc);
            if(!validoOpcMod(opc)) {
                cout << endl << "La opcion es invalida. Intente de nuevo." << endl << endl;
            }
        } while(!validoOpcMod(opc));
        if(opc == "1") {
            mostrar(pos);
        } else if(opc == "2") {
            modificarMenu(pos);
        } else if(opc == "3") {
            eliminar(pos);
            pausa();
            return;
        } else if(opc == "4") {
            crearPersonaje(pos);
        } else if(opc == "5") {
            eliminarPersonaje(pos);
        } else if(opc == "6") {
            accederPersonaje(pos);
        } else {
            cout << endl << "Regresando al menu principal..." << endl;
        }
        if(opc != "7") {
            pausa();
        }
    } while(opc != "7");
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
    string opc;
    do {
        cout << "Esta seguro de eliminar la cuenta?(S/N): ";
        getline(cin, opc);
    } while(opc != "S" and opc != "s" and
            opc != "N" and opc != "n");
    if(opc == "S" or opc == "s") {
        listaCuentas.eliminarDato(auxStr);
        //Eliminar del archivo
        cout << "Dato eliminado exitosamente." << endl;
    } else {
        cout << "Dato conservado exitosamente." << endl;
    }
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
        if(opc != "4"){
            pausa();
        }
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

void Menu::crearPersonaje(const int &pos) {
    system("clear");
    cout << "*** Crear personaje ***" << endl << endl;
    string usnm = listaCuentas[pos].getUserName();
    if(maxPersonajes(usnm)) {
        cout << "Esta cuenta ya cuenta con el maximo de personajes a ingresar. \n"
             "No puede ingresar mas personajes." << endl;
        return;
    }
    Personaje pers;
    string auxStr;
    //Nombre personaje
    do {
        cout << "Ingrese el nombre del personaje: ";
        getline(cin, auxStr);
        if(existePersonaje(auxStr) or !validoDato(auxStr)) {
            cout << endl << "El nombre de personaje ya existe. Intente de nuevo." << endl;
        }
    } while(existePersonaje(auxStr) or !validoDato(auxStr));
    pers.setNombre(auxStr);
    //Genero del personaje
    cout << "Genero: " << endl;
    cout << "1) Hombre." << endl;
    cout << "2) Mujer." << endl;
    cout << "Elije una opcion: ";
    do {
        getline(cin, auxStr);
        if(auxStr != "1" and auxStr != "2") {
            cout << endl << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(auxStr != "1" and auxStr != "2");
    if(auxStr == "1") {
        pers.setGenero("Hombre");
    } else {
        pers.setGenero("Mujer");
    }
    //raza del personaje.
    do {
        system("clear");
        cout << "*** Crear personaje ***" << endl << endl;
        cout << "Raza: " << endl;
        cout << "1) Dragonborn." << endl;
        cout << "2) Enano." << endl;
        cout << "3) Eladrin." << endl;
        cout << "4) Elfo." << endl;
        cout << "5) Mitad elfo." << endl;
        cout << "6) Humano." << endl;
        cout << "7) Halflings." << endl;
        cout << "8) Tieflings." << endl;
        cout << "Elije una opcion: ";
        getline(cin, auxStr);
        if(!validoOpcRazaRol(auxStr)) {
            cout << endl << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(!validoOpcRazaRol(auxStr));
    if(auxStr == "1") {
        pers.setRaza("Dragonborn");
    } else if(auxStr == "2") {
        pers.setRaza("Enano");
    } else if(auxStr == "3") {
        pers.setRaza("Eladrin");
    } else if(auxStr == "4") {
        pers.setRaza("Elfo");
    } else if(auxStr == "5") {
        pers.setRaza("Mitad elfo");
    } else if(auxStr == "6") {
        pers.setRaza("Humano");
    } else if(auxStr == "7") {
        pers.setRaza("Halflings");
    } else {
        pers.setRaza("Tieflings");
    }
    //Rol del personaje
    do {
        system("clear");
        cout << "*** Crear personaje ***" << endl << endl;
        cout << "Rol: " << endl;
        cout << "1) Clerigo." << endl;
        cout << "2) Luchador." << endl;
        cout << "3) Paladin." << endl;
        cout << "4) Explorador." << endl;
        cout << "5) Picaro." << endl;
        cout << "6) Chaman." << endl;
        cout << "7) Señor de la guerra." << endl;
        cout << "8) Mago." << endl;
        cout << "Elije una opcion: ";
        getline(cin, auxStr);
        if(!validoOpcRazaRol(auxStr)) {
            cout << endl << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(!validoOpcRazaRol(auxStr));
    if(auxStr == "1") {
        pers.setRol("Clerigo");
    } else if(auxStr == "2") {
        pers.setRol("Luchador");
    } else if(auxStr == "3") {
        pers.setRol("Paladin");
    } else if(auxStr == "4") {
        pers.setRol("Explorador");
    } else if(auxStr == "5") {
        pers.setRol("Picaro");
    } else if(auxStr == "6") {
        pers.setRol("Chaman");
    } else if(auxStr == "7") {
        pers.setRol("Señor de la guerra");
    } else {
        pers.setRol("Mago");
    }

    do {
        system("clear");
        cout << "*** Crear personaje ***" << endl << endl;
        cout << "Equipo: " << endl;
        cout << "1) Renegado." << endl;
        cout << "2) Circulo arcano." << endl;
        cout << "3) Legion roja." << endl;
        cout << "4) Guarda Gris." << endl;
        cout << "5) Qun." << endl;
        cout << "6) Berseker." << endl;
        cout << "8) Nazgul." << endl;
        cout << "7) Cuervo." << endl;
        cout << "Elije una opcion: ";
        getline(cin, auxStr);
        if(!validoOpcRazaRol(auxStr)) {
            cout << endl << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while(!validoOpcRazaRol(auxStr));
    if(auxStr == "1") {
        pers.setEquipo("Renegado");
    } else if(auxStr == "2") {
        pers.setEquipo("Circulo arcano");
    } else if(auxStr == "3") {
        pers.setEquipo("Legion roja");
    } else if(auxStr == "4") {
        pers.setEquipo("Guarda Gris");
    } else if(auxStr == "5") {
        pers.setEquipo("Qun");
    } else if(auxStr == "6") {
        pers.setEquipo("Berseker");
    } else if(auxStr == "7") {
        pers.setEquipo("Nazgul");
    } else {
        pers.setEquipo("Cuervo");
    }

    //Nombre de usuario
    pers.setUsernameOwner(listaCuentas[pos].getUserName());
    guardarPersonaje("Archivo_Personajes.bin", pers);
}

void Menu::eliminarPersonaje(const int &pos) {
    system("clear");
    string auxStr;
    string auxUser = listaCuentas[pos].getUserName();
    cout << "*** Eliminar personaje ***" << endl << endl;
    cout << "Ingrese el nombre del personaje a eliminar: ";
    getline(cin, auxStr);
    if(existePersonajeCuenta(auxStr, auxUser)) {
        string opc;
        do{
            cout << endl << "Seguro que desea eliminar a este personaje? (S/N): ";
            getline(cin, opc);
        }while(opc != "S" and opc != "s" and opc != "N" and opc != "n");
        if(opc == "S" or opc == "s"){
            ifstream file("Archivo_Personajes.bin");
            if(file.good()) {
                Personaje pers;
                while(!file.eof()) {
                    file.read((char*)&pers, sizeof(pers));
                    if(file.eof()) {
                        break;
                    }
                    string auxNom = pers.getNombre();
                    if(auxNom != auxStr) {
                        guardarPersonaje("Temporal.bin", pers);
                    }
                }
            }
            file.close();
            remove("Archivo_Personajes.bin");
            rename("Temporal.bin", "Archivo_Personajes.bin");
        }
        else{
            cout << endl << "Personaje conservado!" << endl;
        }
    } else {
        cout << endl << "No existe el personaje que desea eliminar. Intente de nuevo." << endl;
    }
}

void Menu::accederPersonaje(const int &pos) {
    system("clear");
    string auxStr;
    string auxUser = listaCuentas[pos].getUserName();
    cout << "*** Acceder a personaje ***" << endl << endl;
    ifstream file("Archivo_Personajes.bin");
    if(!file.good()){
        cout << endl << "No existe el archivo de personajes. Intente de nuevo." << endl;
        file.close();
        return;
    }
    file.close();
    cout << "Ingrese el nombre del personaje a acceder: ";
    getline(cin, auxStr);
    if(existePersonajeCuenta(auxStr, auxUser)) {
        Personaje personaje = regresaPersonaje(auxStr, auxUser);
        new MenuPersonajes(personaje);
    } else {
        cout << endl << "No existe el personaje al que desea acceder. Intente de nuevo." << endl;
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


bool Menu::existePersonaje(std::string& nomPersonaje) {
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    if(file.good()) {
        while(!file.eof()) {
            file.read((char*)&pers, sizeof(pers));
            if(file.eof()) {
                break;
            }
            string auxNom = pers.getNombre();
            if(auxNom == nomPersonaje) {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

bool Menu::existePersonajeCuenta(std::string& nomPersonaje, std::string& username) {
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    if(file.good()) {
        while(!file.eof()) {
            file.read((char*)&pers, sizeof(pers));
            if(file.eof()) {
                break;
            }
            string auxNom = pers.getNombre();
            string auxUser = pers.getUsernameOwner();
            if(auxNom == nomPersonaje and auxUser == username) {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}


bool Menu::validoOpcMod(std::string& opc) {
    regex rx("[1-7]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}

void Menu::guardarPersonaje(const std::string& archivo, Personaje pers) {
    ofstream file(archivo, ios::binary|ios::app);
    file.write((char*)&pers, sizeof(pers));
    file.close();
}

bool Menu::validoDato(std::string& dato) {
    regex rx("[a-zA-Z]*");
    if(regex_match(dato, rx) and dato.length() > 0 and dato.length() < 30) {
        return true;
    }
    return false;
}

Personaje Menu::regresaPersonaje(std::string& nomPersonaje, std::string &username) {
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    if(file.good()) {
        while(!file.eof()) {
            file.read((char*)&pers, sizeof(pers));
            if(file.eof()) {
                break;
            }
            string auxNom = pers.getNombre();
            string auxUserOwner = pers.getUsernameOwner();
            if(auxNom == nomPersonaje and auxUserOwner == username) {
                file.close();
                return pers;
            }
        }
    }
    file.close();
    return pers;
}


bool Menu::validoOpcRazaRol(std::string& opc) {
    regex rx("[1-8]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}


bool Menu::maxPersonajes(std::string& username) {
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    int i = 0;
    if(file.good()) {
        while(!file.eof()) {
            file.read((char*)&pers, sizeof(pers));
            if(file.eof()) {break;}
            string auxPers = pers.getUsernameOwner();
            if(auxPers == username) {
                i++;
            }
        }
    }
    file.close();
    if(i == 3) {
        return true;
    }
    return false;
}
