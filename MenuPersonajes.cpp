#include "MenuPersonajes.h"

MenuPersonajes::MenuPersonajes() {
    menuPrincipal();
}

MenuPersonajes::MenuPersonajes(Personaje& pers) {
    personaje = pers;
    menuPrincipal();
}

void MenuPersonajes::menuPrincipal() {
    string opc;
    do {
        system("clear");
        cout << "*** Opciones para el personaje " << personaje.getNombre() << " ***" << endl << endl;
        cout << "1) Modificar atributos." << endl;
        cout << "2) Mostrar." << endl;
        cout << "3) Completar mision." << endl;
        cout << "4) Abandonar." << endl;
        do {
            cout << "Elije una opcion: ";
            getline(cin, opc);
        } while(!validoOpcMenu(opc));
        if(opc == "1") {
            modificar();
        } else if(opc == "2") {
            mostrar();
        } else if(opc == "3") {
            completarMision();
        } else {
            abandonar();
        }
        if(opc != "4") {
            pausa();
        }
    } while(opc != "4");
}

void MenuPersonajes::modificar() {
    system("clear");
    string opc;
    cout << "*** Modificar atributos del personaje ***" << endl << endl;
    cout << "1) Genero." << endl;
    cout << "2) Rol." << endl;
    cout << "3) Raza." << endl;
    cout << "4) Arma." << endl;
    cout << "5) Equipo." << endl;
    cout << "6) Regresar al menu de personaje...." << endl;
    do {
        cout << "Elije una opcion: ";
        getline(cin, opc);
    } while(!validoOpcModificar(opc));
    if(opc == "1") {
        string auxStr;
        cout << endl << endl;
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
            personaje.setGenero("Hombre");
        } else {
            personaje.setGenero("Mujer");
        }
    } else if(opc == "2") {
        string auxStr;
        do {
            system("clear");
            cout << "*** Modificar atributos del personaje ***" << endl << endl;
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
            personaje.setRol("Clerigo");
        } else if(auxStr == "2") {
            personaje.setRol("Luchador");
        } else if(auxStr == "3") {
            personaje.setRol("Paladin");
        } else if(auxStr == "4") {
            personaje.setRol("Explorador");
        } else if(auxStr == "5") {
            personaje.setRol("Picaro");
        } else if(auxStr == "6") {
            personaje.setRol("Chaman");
        } else if(auxStr == "7") {
            personaje.setRol("Señor de la guerra");
        } else {
            personaje.setRol("Mago");
        }
    } else if(opc == "3") {
        string auxStr;
        do {
            system("clear");
            cout << "*** Modificar atributos del personaje ***" << endl << endl;
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
            personaje.setRaza("Dragonborn");
        } else if(auxStr == "2") {
            personaje.setRaza("Enano");
        } else if(auxStr == "3") {
            personaje.setRaza("Eladrin");
        } else if(auxStr == "4") {
            personaje.setRaza("Elfo");
        } else if(auxStr == "5") {
            personaje.setRaza("Mitad elfo");
        } else if(auxStr == "6") {
            personaje.setRaza("Humano");
        } else if(auxStr == "7") {
            personaje.setRaza("Halflings");
        } else {
            personaje.setRaza("Tieflings");
        }
    } else if(opc == "4") {
        string auxStr;
        cout << "Ingrese el arma: ";
        getline(cin, auxStr);
        personaje.setArma(auxStr);
    } else if(opc == "5") {
        string auxStr;
        do {
            system("clear");
            cout << "*** Modificar atributos del personaje ***" << endl << endl;
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
            personaje.setEquipo("Renegado");
        } else if(auxStr == "2") {
            personaje.setEquipo("Circulo arcano");
        } else if(auxStr == "3") {
            personaje.setEquipo("Legion roja");
        } else if(auxStr == "4") {
            personaje.setEquipo("Guarda Gris");
        } else if(auxStr == "5") {
            personaje.setEquipo("Qun");
        } else if(auxStr == "6") {
            personaje.setEquipo("Berseker");
        } else if(auxStr == "7") {
            personaje.setEquipo("Nazgul");
        } else {
            personaje.setEquipo("Cuervo");
        }
    } else {
        cout << endl << "Regresando al menu de personaje... " << endl;
    }
}

void MenuPersonajes::mostrar() {
    system("clear");
    cout << "*** Mostrar atributos del personaje ***" << endl << endl;
    cout << personaje.toString() << endl;
}

void MenuPersonajes::completarMision() {

}

void MenuPersonajes::abandonar() {
    string auxStr = personaje.getNombre();
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    while(!file.eof()){
        file.read((char*)&pers, sizeof(pers));
        if(file.eof()){break;}
        string auxNomPers = pers.getNombre();
        if(auxNomPers != auxStr){
            guardarPersonaje("Temporal.bin", pers);
        } else{
            guardarPersonaje("Temporal.bin", personaje);
        }
    }
    file.close();
    remove("Archivo_Personajes.bin");
    rename("Temporal.bin", "Archivo_Personajes.bin");
    cout << endl << "Regresando al menu de usuario..." << endl;
}

void MenuPersonajes::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.ignore();
}

MenuPersonajes::~MenuPersonajes() {
    //dtor
}

bool MenuPersonajes::validoOpcMenu(std::string& opc) {
    regex rx("[1-4]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}

bool MenuPersonajes::validoOpcModificar(std::string& opc) {
    regex rx("[1-6]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}

bool MenuPersonajes::validoOpcRazaRol(std::string& opc) {
    regex rx("[1-8]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}

void MenuPersonajes::guardarPersonaje(const std::string& archivo, Personaje& pers)
{
    ofstream file(archivo, ios::binary|ios::app);
    file.write((char*)&pers, sizeof(pers));
    file.close();
}

