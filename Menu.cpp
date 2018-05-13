#include "Menu.h"

Menu::Menu() {
    system("mkdir Personajes");
    //Lee el grafo original
    string dirVertice = DIRGRAFO;
    dirVertice += "Archivo_Vertices.txt";
    string dirArista = DIRGRAFO;
    dirArista+= "Archivo_Aristas.txt";
    grafoGeneral.cargar(dirVertice, dirArista);
    listaInvertida.cargarDesdeDisco();
    menuPrincipal();
}

Menu::~Menu() {
    //dtor
}

void Menu::menuPrincipal() {
    string opc;
    do {
        system(CLEAR);
        cout << "***Menu de cuentas***" << endl << endl;
        cout << "1) Agregar usuario." << endl;
        cout << "2) Acceder." << endl;
        cout << "3) Lista Invertida." << endl;
        cout << "4) Salir" << endl;
        cout << "0) Mostrar todo(Super usuario)." << endl << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
            if(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "0") {
                cout << endl << "La opcion es invalida. Intente de nuevo." << endl << endl;
            }
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "0");
        if(opc == "1") {
            agregar();
        } else if(opc == "2") {
            acceder();
        } else if(opc == "3") {
            mostrarListaInvertida();
        } else if(opc == "0") {
            mostrarTodo();
        } else {
            listaInvertida.guardarEnDisco();
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
        system(CLEAR);
        cout << "***Menu para el usuario " << listaCuentas[pos].getUserName() << "***" << endl << endl;
        cout << "1) Mostrar Cuenta." << endl;
        cout << "2) Modificar Cuenta." << endl;
        cout << "3) Eliminar Cuenta." << endl;
        cout << "4) Crear personaje." << endl;
        cout << "5) Eliminar personaje (Físico)." << endl;
        cout << "6) Eliminar personaje (Lógico)." << endl;
        cout << "7) Activar personaje (Lógico)." << endl;
        cout << "8) Mostrar personajes disponibles." << endl;
        cout << "9) Acceder a personaje." << endl;
        cout << "0) Regresar al menu principal." << endl << endl;
        do {
            cout << ">> ";
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
            //eliminarPersonaje(pos);
        } else if(opc == "6") {
            eliminarLogico(pos);
        } else if(opc == "7") {
            activarLogico(pos);
        } else if(opc == "8") {
            mostrarPersonajes(pos);
        } else if(opc == "9") {
            accederPersonaje(pos);
        } else {
            cout << endl << "Regresando al menu principal..." << endl;
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void Menu::agregar() {
    system(CLEAR);
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
    system(CLEAR);
    string auxStr = listaCuentas[pos].getUserName();
    cout << "***Eliminar cuenta***" << endl << endl;
    string opc;
    do {
        cout << "Esta seguro de eliminar la cuenta?(S/N): ";
        getline(cin, opc);
    } while(opc != "S" and opc != "s" and
            opc != "N" and opc != "n");
    if(opc == "S" or opc == "s") {
        int posIndice = listaCuentas[pos].getPosIndice();
        listaCuentas.eliminarDato(auxStr);

        std::cout << "ASD " << std::endl;
        listaInvertida.eliminacionPersonajesLogica(posIndice);
        //Eliminar del archivo los personajes
        cout << "Dato eliminado exitosamente." << endl;
    } else {
        cout << "Dato conservado exitosamente." << endl;
    }
}

void Menu::modificarMenu(const int &pos) {
    string opc, auxStr;
    do {
        system(CLEAR);
        cout << "Modificar cuenta***" << endl;
        cout << listaCuentas[pos].toString() << endl << endl;
        cout << "Que desea modificar?" << endl;
        cout << "1) Nombre." << endl;
        cout << "2) Correo electronico." << endl;
        cout << "3) Password." << endl;
        cout << "0) Regresar al menu anterior..." << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "1" and opc != "2" and opc != "3" and opc != "0");

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
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void Menu::mostrar(const int &pos) {
    system(CLEAR);
    cout << "***Mostrar usuario***" << endl << endl;
    cout << endl << listaCuentas[pos].toString() << endl;
}

void Menu::mostrarPersonajes(const int& pos) {
    system(CLEAR);
    cout << "*** Personajes del jugador " << listaCuentas[pos].getUserName() << "***" << endl << endl;
    ifstream archivo("Archivo_Personajes.bin");
    if(!archivo.good()) {
        cout << "No hay archivo de personajes." << endl;
    } else {
        int posIndice = listaCuentas[pos].getPosIndice();
        //cout << posIndice;
        if(posIndice == -1){
            cout << "La cuenta no tiene personajes ingresados. Intente de nuevo.";
            return;
        }
        NodoInvertida* aux = listaInvertida[posIndice];
        while(aux != nullptr) {
            Personaje pers;
            archivo.seekg(aux->getDato().getPosArchivo(), ios::beg);
            archivo.read((char*)&pers, sizeof(Personaje));
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Nombre: " << left << setw(18) << "| Genero: " << left <<setw(18) << "| EXP: " << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << pers.getNombre() << "| " << left << setw(16)  << pers.getGenero() << "| "<< left << setw(16)  << pers.getExperiencia() << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Rol: " << left << setw(18) << "| Raza: " << left <<setw(18) << "| Equipo: " << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << pers.getRol() << "| " << left << setw(16)  << pers.getRaza() << "| "<< left << setw(16)  << pers.getEquipo() << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Arma: " << left << setw(18) << "| Ataque: " << left <<setw(18) << "| Ubicacion: " << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << pers.getArma().getNombre() << "| " << left << setw(16)  << to_string(pers.getArma().getAtaque()) << "| "<< left << setw(16)  << pers.getUbicacionActual() << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Descripcion: " << left << setw(18) << "" << left <<setw(18) << "" << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << pers.getArma().getDescripcion() << "" << left << setw(11)  << "" << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n\n";
            aux = aux->getSigPers();
        }
    }
    archivo.close();
}


void Menu::mostrarTodo() {
    system(CLEAR);
    cout << "***Mostrar cuentas***" << endl << endl;
    for(int i = 0; i < listaCuentas.getCont(); i++) {
        cout << "Usuario #" << i + 1 << endl;
        cout << listaCuentas[i].toString() << endl << endl;
    }
}

void Menu::crearPersonaje(const int &pos) {
    system(CLEAR);
    cout << "*** Crear personaje ***" << endl << endl;
    string usnm = listaCuentas[pos].getUserName();
    if(maxPersonajes(usnm, pos)) {
        cout << "Esta cuenta ya cuenta con el maximo de personajes a ingresar. \n"
             "¿Desea poder ingresar un nuevo personaje?. (S/N)" << endl << endl;
        string opc;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(opc != "s" and opc != "S" and opc != "n" and opc != "N");
        if(opc == "s" or opc == "S") {
            int maximo = listaCuentas[pos].getMaxPersonajes();
            if(maximo == 10) {
                cout << endl << "No se puede actualizar a mas de 10 personajes.";
                return;
            } else {
                listaCuentas[pos].setMaxPersonajes(++maximo);
                cout << endl << "Se ha actualizado el maximo de personajes. Ahora procedera a ingresar el nuevo personaje....";
                pausa();
            }
        } else {
            cout << "No se actualizo el maximo de personajes.";
            return;
        }
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
        system(CLEAR);
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
        system(CLEAR);
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
    Arma arm;
    if(auxStr == "1") {
        pers.setRol("Clerigo");
        arm.setNombre("Mazo de Milil");
        arm.setAtaque(50);
        arm.setDescripcion("Mazo del dios de la luz");
        arm.setPrecio(10);
    } else if(auxStr == "2") {
        pers.setRol("Luchador");
        arm.setNombre("Mazo de Akadi");
        arm.setAtaque(50);
        arm.setDescripcion("Mazo del dios del aire");
        arm.setPrecio(10);
    } else if(auxStr == "3") {
        pers.setRol("Paladin");
        arm.setNombre("Espada de Ilmater");
        arm.setAtaque(50);
        arm.setDescripcion("Espada del dios de la rectitud");
        arm.setPrecio(10);
    } else if(auxStr == "4") {
        pers.setRol("Explorador");
        arm.setNombre("Daga de Beshaba");
        arm.setAtaque(50);
        arm.setDescripcion("Daga de la diosa del engaño");
        arm.setPrecio(10);
    } else if(auxStr == "5") {
        pers.setRol("Picaro");
        arm.setNombre("Arco de Savras");
        arm.setAtaque(50);
        arm.setDescripcion("Arco del dios del destino");
        arm.setPrecio(10);
    } else if(auxStr == "6") {
        pers.setRol("Chaman");
        arm.setNombre("Baston de Elune");
        arm.setAtaque(50);
        arm.setDescripcion("Baston de la diosa de la luna");
        arm.setPrecio(10);
    } else if(auxStr == "7") {
        pers.setRol("Señor de la guerra");
        arm.setNombre("Espada de Tyr");
        arm.setAtaque(50);
        arm.setDescripcion("Espada del dios de la justicia");
        arm.setPrecio(10);
    } else {
        pers.setRol("Mago");
        arm.setNombre("Bastón de Gregoir");
        arm.setAtaque(50);
        arm.setDescripcion("Baston del dios de la sabiduria");
        arm.setPrecio(10);
    }

    do {
        system(CLEAR);
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
    string auxNombreOrigen;
    if(auxStr == "1") {
        pers.setEquipo("Renegado");
        auxNombreOrigen = grafoGeneral[0]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else if(auxStr == "2") {
        pers.setEquipo("Circulo arcano");
        auxNombreOrigen = grafoGeneral[1]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else if(auxStr == "3") {
        pers.setEquipo("Legion roja");
        auxNombreOrigen = grafoGeneral[3]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else if(auxStr == "4") {
        pers.setEquipo("Guarda Gris");
        auxNombreOrigen = grafoGeneral[2]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else if(auxStr == "5") {
        pers.setEquipo("Qun");
        auxNombreOrigen = grafoGeneral[4]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else if(auxStr == "6") {
        pers.setEquipo("Berseker");
        auxNombreOrigen = grafoGeneral[5]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else if(auxStr == "7") {
        pers.setEquipo("Nazgul");
        auxNombreOrigen = grafoGeneral[6]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    } else {
        pers.setEquipo("Cuervo");
        auxNombreOrigen = grafoGeneral[7]->getNombre();
        pers.setUbicacionActual(auxNombreOrigen);
    }

    //Nombre de usuario
    pers.setUsernameOwner(listaCuentas[pos].getUserName());

    //Crea directorio del personaje
    string mkdir = MKDIR + string(pers.getNombre());
    system(mkdir.c_str());

    //Crea el arma con la que inicia el personaje
    ListaInventario l;
    l.insertar(l.ultimaPos(), arm);
    string dirLista = DIR + string(pers.getNombre()) + SLASH + string(pers.getNombre()) + "_Inventario.txt";
    l.escribirAlDisco(dirLista);

    //Crea su posicion inicial en el grafo
    Grafo grafoPersonaje;
    Vertice* auxOrigen(grafoGeneral.regresaVertice(auxNombreOrigen));
    string tip = auxOrigen->getTipoClima();
    string dif = auxOrigen->getDificultad();
    Arma rec = auxOrigen->getRecompensa();
    grafoPersonaje.insertarVertice(grafoPersonaje.verticeUltimaPos(), auxNombreOrigen, tip, dif, rec);

    Vertice* auxVerticeOri(grafoPersonaje.regresaVertice(auxNombreOrigen));
    Arista* auxDestino(auxOrigen->getSigArista());
    while(auxDestino != nullptr) {
        string auxNomDestino = auxDestino->getDestino()->getNombre();
        tip = auxVerticeOri->getTipoClima();
        dif = auxVerticeOri->getDificultad();
        rec = auxVerticeOri->getRecompensa();
        grafoPersonaje.insertarVertice(grafoPersonaje.verticeUltimaPos(), auxNomDestino, tip, dif, rec);
        grafoPersonaje.insertaAdyacencia(auxVerticeOri, grafoPersonaje.regresaVertice(auxNomDestino), auxDestino->getReferencia().getNivelNecesario());
        auxDestino = auxDestino->getSiguiente();
    }

    string mkVertices, mkAristas;
    mkVertices = DIR + string(pers.getNombre()) + SLASH + string(pers.getNombre()) + "_Vertices.txt";
    mkAristas = DIR + string(pers.getNombre()) + SLASH + string(pers.getNombre()) + "_Aristas.txt";
    grafoPersonaje.guardar(mkVertices, mkAristas);
    grafoPersonaje.borrarTodo();

    //Guarda el personaje en archivo binario
    guardarPersonaje("Archivo_Personajes.bin", pers, pos);
}

void Menu::eliminarLogico(const int& pos) {
    system(CLEAR);
    string nomPersonaje;
    cout << "*** Eliminar personaje (Lógico) ***" << endl << endl;
    cout << "Ingrese el nombre del personaje a eliminar: ";
    getline(cin, nomPersonaje);
    int posIndice = listaCuentas[pos].getPosIndice();
    if(existePersonajeCuenta(nomPersonaje, posIndice)){
        listaCuentas[pos].setPosIndice(listaInvertida.eliminarLogico(posIndice, nomPersonaje));
        cout << endl << "¡Eliminación exitosa!";
    }
    else{
        cout << endl << "No existe el personaje en la cuenta.";
    }
}


void Menu::activarLogico(const int& pos) {
    system(CLEAR);
    string nomPersonaje;
    cout << "*** Activación de personaje (Lógico) ***" << endl << endl;
    cout << "Ingrese el nombre del personaje a activar: ";
    getline(cin, nomPersonaje);
    int posIndice = listaCuentas[pos].getPosIndice();
    if(existePersonaje(nomPersonaje)){
        if(existePersonajeCuenta(nomPersonaje, posIndice)){
            cout << "El personaje se encuentra activo.";
        }
        else{
            string username = listaCuentas[pos].getUserName();
            if(listaInvertida.cuentaPersonajeLineal(nomPersonaje, username)){
                listaCuentas[pos].setPosIndice(listaInvertida.activacionLogica(nomPersonaje, username, posIndice));
                cout << endl << "¡Activación exitosa!";
            }
            else{
                cout << endl << "El personaje no pertenece a esta cuenta.";
            }
        }
    }
    else{
        cout << endl << "No existe el nombre de personaje.";
    }
}


void Menu::eliminarPersonaje(const int &pos) {
    system(CLEAR);
    cout << "*** Eliminar personaje (Física) ***" << endl << endl;
    cout << "Esta opcion se encuentra en mantenimiento";
    /*string auxUser = listaCuentas[pos].getUserName();
    cout << "*** Eliminar personaje ***" << endl << endl;
    cout << "Ingrese el nombre del personaje a eliminar: ";
    getline(cin, auxStr);
    if(existePersonajeCuenta(auxStr, auxUser)) {
        string opc;
        do {
            cout << endl << "Seguro que desea eliminar a este personaje? (S/N): ";
            getline(cin, opc);
        } while(opc != "S" and opc != "s" and opc != "N" and opc != "n");
        if(opc == "S" or opc == "s") {
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
                        guardarPersonaje("Temporal.bin", pers, pos);
                    }
                }
            }
            file.close();
            remove("Archivo_Personajes.bin");
            rename("Temporal.bin", "Archivo_Personajes.bin");
            string rmdir = "rm -rf Personajes/" + auxStr;
            system(rmdir.c_str());
        } else {
            cout << endl << "Personaje conservado!" << endl;
        }
    } else {
        cout << endl << "No existe el personaje que desea eliminar. Intente de nuevo." << endl;
    }*/
}

void Menu::accederPersonaje(const int &pos) {
    system(CLEAR);
    string auxStr;
    string auxUser = listaCuentas[pos].getUserName();
    cout << "*** Acceder a personaje ***" << endl << endl;
    ifstream file("Archivo_Personajes.bin");
    if(!file.good()) {
        cout << endl << "No existe el archivo de personajes. Intente de nuevo." << endl;
        file.close();
        return;
    }
    file.close();
    cout << "Ingrese el nombre del personaje a acceder: ";
    getline(cin, auxStr);
    int posIndice = listaCuentas[pos].getPosIndice();
    if(existePersonajeCuenta(auxStr, posIndice)) {
        Personaje personaje = regresaPersonaje(auxStr, posIndice);
        new MenuPersonajes(personaje, grafoGeneral);
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
    return listaInvertida.existePersonaje(nomPersonaje);
}

bool Menu::existePersonajeCuenta(std::string& nomPersonaje, const int &posIndice) {
    if(posIndice == -1){
        return false;
    }
    NodoInvertida* aux = listaInvertida[posIndice];
    while(aux != nullptr) {
        if(string(aux->getDato().getNombrePersonaje()) == nomPersonaje){
            return true;
        }
        aux = aux->getSigPers();
    }
    return false;
}


bool Menu::validoOpcMod(std::string& opc) {
    regex rx("[0-9]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}

void Menu::guardarPersonaje(const std::string& archivo, Personaje pers, const int &pos) {
    ofstream file(archivo, ios::binary|ios::app);
    file.write((char*)&pers, sizeof(pers));
    long int posArchivo = file.tellp();
    file.close();

    posArchivo -= sizeof(Personaje);
    DatosInvertida datos;
    datos.setNombrePersonaje(string(pers.getNombre()));
    datos.setUsernameOwner(string(pers.getUsernameOwner()));
    datos.setPosArchivo(posArchivo);

    int posIndice = listaCuentas[pos].getPosIndice();

    listaCuentas[pos].setPosIndice(listaInvertida.inserta(datos, listaInvertida.ultimaPos(), posIndice));
}


bool Menu::validoDato(std::string& dato) {
    regex rx("[a-zA-Z]*");
    if(regex_match(dato, rx) and dato.length() > 0 and dato.length() < 30) {
        return true;
    }
    return false;
}

Personaje Menu::regresaPersonaje(std::string& nomPersonaje, const int &posIndice) {
    Personaje pers;
    ifstream file("Archivo_Personajes.bin");
    NodoInvertida* aux = listaInvertida[posIndice];
    while(aux != nullptr) {
        if(string(aux->getDato().getNombrePersonaje()) == nomPersonaje){
            long int posArchivo = aux->getDato().getPosArchivo();
            file.seekg(posArchivo, ios::beg);
            file.read((char*)&pers, sizeof(Personaje));
            file.close();
            return pers;
        }
        aux = aux->getSigPers();
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


bool Menu::maxPersonajes(std::string& username, const int &pos) {
    int maximo = listaCuentas[pos].getMaxPersonajes();
    int posIndice = listaCuentas[pos].getPosIndice();
    NodoInvertida* aux = listaInvertida[posIndice];
    int i = 0;
    while(aux != nullptr) {
        i++;
        aux = aux->getSigPers();
    }
    if(i == maximo){
        return true;
    }
    return false;
}

void Menu::mostrarListaInvertida() {
    system(CLEAR);
    cout << "*** Lista invertida *** " << endl << endl;
    cout << listaInvertida.toString();
}
