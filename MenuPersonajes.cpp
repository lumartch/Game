#include "MenuPersonajes.h"

MenuPersonajes::MenuPersonajes() {
    menuPrincipal();
}

MenuPersonajes::MenuPersonajes(Personaje& pers, Grafo & graf) {
    this->personaje = pers;
    this->grafoGeneral = graf;
    string nombre = this->personaje.getNombre();
    this->mkVertices = string(DIR) + nombre + string(SLASH) + nombre + "_Vertices.txt";
    this->mkAristas = string(DIR) + nombre + string(SLASH) + nombre + "_Aristas.txt";

    //Lee del directorio el inventario
    this->listaInventario.leerDelDisco(string(DIR) + nombre + string(SLASH) + nombre + "_Inventario.txt");

    //Lee el grafo del Personaje
    this->grafoPersonaje.cargar(this->mkVertices, this->mkAristas);
    menuPrincipal();
}

void MenuPersonajes::menuPrincipal() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Opciones para el personaje " << this->personaje.getNombre() << " ***" << endl << endl;
        cout << "1) Modificar atributos." << endl;
        cout << "2) Mostrar." << endl;
        cout << "3) Completar mision." << endl;
        cout << "4) Mapas." << endl;
        cout << "0) Abandonar." << endl;
        do {
            cout << ">> ";
            getline(cin, opc);
        } while(!validoOpcMenu(opc));
        if(opc == "1") {
            modificar();
        } else if(opc == "2") {
            mostrar();
        } else if(opc == "3") {
            completarMision();
        } else if(opc == "4"){
            mostrarMapa();
        }
        else{
            abandonar();
        }
        if(opc != "0") {
            pausa();
        }
    } while(opc != "0");
}

void MenuPersonajes::modificar() {
    system(CLEAR);
    string opc;
    cout << "*** Modificar atributos del personaje ***" << endl << endl;
    cout << "1) Arma." << endl;
    cout << "2) Equipo." << endl;
    cout << "0) Regresar al menu de personaje...." << endl;
    do {
        cout << "Elije una opcion: ";
        getline(cin, opc);
    } while(!validoOpcModificar(opc));
    if(opc == "1") {
        cout << this->listaInventario.toString();
        //string auxStr;
        //cout << "Ingrese el arma: ";
        //getline(cin, auxStr);
        //personaje.setArma(auxStr);
    } else if(opc == "2") {
        string auxStr;
        do {
            system(CLEAR);
            cout << "*** Modificar atributos del personaje ***" << endl << endl;
            cout << "Equipo: " << endl;
            cout << "1) Renegado." << endl;
            cout << "2) Circulo arcano." << endl;
            cout << "3) Legion roja." << endl;
            cout << "4) Guarda Gris." << endl;
            cout << "5) Qun." << endl;
            cout << "6) Berseker." << endl;
            cout << "7) Nazgul." << endl;
            cout << "8) Cuervo." << endl;
            cout << ">> ";
            getline(cin, auxStr);
            if(!validoOpcRazaRol(auxStr)) {
                cout << endl << "Opcion invalida. Intente de nuevo." << endl;
            }
        } while(!validoOpcRazaRol(auxStr));
        if(auxStr == "1") {
            this->personaje.setEquipo("Renegado");
        } else if(auxStr == "2") {
            this->personaje.setEquipo("Circulo arcano");
        } else if(auxStr == "3") {
            this->personaje.setEquipo("Legion roja");
        } else if(auxStr == "4") {
            this->personaje.setEquipo("Guarda Gris");
        } else if(auxStr == "5") {
            this->personaje.setEquipo("Qun");
        } else if(auxStr == "6") {
            this->personaje.setEquipo("Berseker");
        } else if(auxStr == "7") {
            this->personaje.setEquipo("Nazgul");
        } else {
            this->personaje.setEquipo("Cuervo");
        }
    } else {
        cout << endl << "Regresando al menu de personaje... " << endl;
    }
}

void MenuPersonajes::mostrar() {
    system(CLEAR);
    cout << "*** Mostrar atributos del personaje ***" << endl << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Nombre: " << left << setw(18) << "| Genero: " << left <<setw(18) << "| EXP: " << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << this->personaje.getNombre() << "| " << left << setw(16)  << this->personaje.getGenero() << "| "<< left << setw(16)  << this->personaje.getExperiencia() << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Rol: " << left << setw(18) << "| Raza: " << left <<setw(18) << "| Equipo: " << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << this->personaje.getRol() << "| " << left << setw(16)  << this->personaje.getRaza() << "| "<< left << setw(16)  << this->personaje.getEquipo() << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Arma: " << left << setw(18) << "| Ataque: " << left <<setw(18) << "| Ubicacion: " << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << this->personaje.getArma().getNombre() << "| " << left << setw(16)  << to_string(this->personaje.getArma().getAtaque()) << "| "<< left << setw(16)  << this->personaje.getUbicacionActual() << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Descripcion: " << left << setw(18) << "" << left <<setw(18) << "" << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << this->personaje.getArma().getDescripcion() << "" << left << setw(11)  << "" << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n\n";

    cout << "Inventario: " << endl;
    cout << this->listaInventario.toString();
}

void MenuPersonajes::completarMision() {
    system(CLEAR);
    string opc;
    cout << "*** Completar mision ***" << endl << endl;
    cout << "1) Tutorial." << endl;
    cout << "2) Entrenamiento mano a mano." << endl;
    cout << "3) Primer enfrentamiento." << endl;
    do {
        cout << "Elije una opcion: ";
        getline(cin, opc);
    } while(opc != "1" and opc!= "2" and opc != "3");
    if(opc == "1") {
        if(this->personaje.getMisiones()[0]) {
            cout <<  "Mision ya hecha." << endl;
        } else {
            this->personaje.setExperiencia(100);
            this->personaje.setMision(0);
        }
    } else if(opc == "2") {

        if(this->personaje.getMisiones()[1]) {
            cout <<  "Mision ya hecha." << endl;
        } else {
            this->personaje.setExperiencia(200);
            this->personaje.setMision(1);
        }
    } else {

        if(this->personaje.getMisiones()[2]) {
            cout <<  "Mision ya hecha." << endl;
        } else {
            this->personaje.setExperiencia(300);
            this->personaje.setMision(2);
        }
    }
}

void MenuPersonajes::mostrarMapa() {
    string opc;
    do{
        system(CLEAR);
        cout << "*** Mapas ***" << endl << endl;
        cout << "Ubicacion actual: " << this->personaje.getUbicacionActual() << endl  << endl;
        cout << "1) Ver informacion de la ubicacion actual." << endl;
        cout << "2) Ver mapa global." << endl;
        cout << "3) Ver mapa conocido." << endl;
        cout << "4) Viajar." << endl;
        cout << "0) Regresar..." << endl;
        do{
            cout << ">> ";
            getline(cin, opc);
        }while(opc != "1" and opc != "2" and opc != "3" and opc != "4" and opc != "0");
        if(opc == "1"){
            system(CLEAR);
            cout << "*** Informacion ***" << endl << endl;
            Vertice* origen(this->grafoPersonaje.regresaVertice(string(this->personaje.getUbicacionActual())));
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Ubicacion: " << left << setw(18) << "| Tipo clima: " << left <<setw(18) << "| Dificultad: " << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << origen->getNombre() << "| " << left << setw(16)  << origen->getTipoClima() << "| "<< left << setw(16)  << origen->getDificultad() << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Recompensa: " << left << setw(18) << "| Ataque: " << left <<setw(18) << "| Precio: " << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << origen->getRecompensa().getNombre() << "| " << left << setw(16)  << to_string(origen->getRecompensa().getAtaque()) << "| "<< left << setw(16)  << to_string(origen->getRecompensa().getPrecio()) << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n";
            cout << left << setw(18) << "| Descripcion: " << left << setw(18) << "" << left <<setw(18) << "" << left <<setw(16) << "|" << endl;
            cout << "| " << left << setw(16) << origen->getRecompensa().getDescripcion() << "" << left << setw(11)  << "" << left << setw(16)  << "|" << endl;
            cout << "+-----------------+-----------------+-----------------+\n\n";
            cout << "Posibles rutas " << this->grafoPersonaje.toStringAdyacencias(origen) << endl;
        }
        else if(opc == "2"){
            system(CLEAR);
            cout << "*** Mapa general ***" << endl << endl;
            cout << grafoGeneral.toListaAdyacencia() << endl;
        }
        else if(opc == "3"){
            system(CLEAR);
            cout << "*** Mapa conocido ***" << endl << endl;
            cout << this->grafoPersonaje.toListaAdyacencia() << endl;
        }
        else if(opc == "4"){
            cout << "*** Viajar ***" << endl << endl;
            system(CLEAR);
            Vertice* origen(this->grafoPersonaje.regresaVertice(string(this->personaje.getUbicacionActual())));
            cout << "*** Viajar ***" << endl << endl;
            cout << "Ubicacion actual: " << this->personaje.getUbicacionActual() << endl;
            cout << "Posibles destinos " << this->grafoPersonaje.toStringAdyacencias(origen) << endl;
            cout << "Elije un destino o presione 0 para no viajar." << endl;
            string strDestino;
            Vertice* destino;
            bool bandera = false;
            do{
                cout << ">> ";
                getline(cin, strDestino);
                if(!this->grafoPersonaje.existeVertice(strDestino) and strDestino != "0"){
                    cout << endl << "No existe el destino. Intente de nuevo." << endl;
                }
                else{
                    destino = this->grafoPersonaje.regresaVertice(strDestino);
                    if(!this->grafoPersonaje.existeAdyacencia(origen, destino)){
                        cout << endl << "No existe una ruta entre " << this->personaje.getUbicacionActual() << " y " << strDestino << ". Intente de nuevo." << endl;
                    }
                    else{
                        this->personaje.setUbicacionActual(strDestino);
                        bandera = true;
                    }
                }
            }while(!bandera and strDestino != "0");
            if(strDestino == "0"){
                cout << this->personaje.getNombre() <<" se ha quedado en el pueblo actual." << endl;
                return;
            }

            Vertice* auxOrigen(grafoGeneral.regresaVertice(strDestino));
            string tip = auxOrigen->getTipoClima();
            string dif = auxOrigen->getDificultad();
            Arma rec = auxOrigen->getRecompensa();
            this->grafoPersonaje.insertarVertice(this->grafoPersonaje.verticeUltimaPos(), strDestino, tip, dif, rec);

            Vertice* auxVerticeOri(this->grafoPersonaje.regresaVertice(strDestino));
            Arista* auxDestino(auxOrigen->getSigArista());
            while(auxDestino != nullptr){
                string auxNomDestino = auxDestino->getDestino()->getNombre();
                tip = auxVerticeOri->getTipoClima();
                dif = auxVerticeOri->getDificultad();
                rec = auxVerticeOri->getRecompensa();
                this->grafoPersonaje.insertarVertice(this->grafoPersonaje.verticeUltimaPos(), auxNomDestino, tip, dif, rec);
                this->grafoPersonaje.insertaAdyacencia(auxVerticeOri, this->grafoPersonaje.regresaVertice(auxNomDestino), auxDestino->getReferencia().getNivelNecesario());
                auxDestino = auxDestino->getSiguiente();
            }
            cout << this->personaje.getNombre() << " ha viajadoo exitosamente a " << strDestino << "." << endl;
        }
        else{
            cout << endl <<"Regresando al menu de personaje..." << endl;
        }
        if(opc != "0"){
            pausa();
        }
    }while(opc != "0");
}


void MenuPersonajes::abandonar() {
    //Guarda lo modificado en el personaje
    string auxStr = this->personaje.getNombre();
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    while(!file.eof()) {
        file.read((char*)&pers, sizeof(pers));
        if(file.eof()) { break; }
        string auxNomPers = pers.getNombre();
        if(auxNomPers != auxStr) {
            guardarPersonaje("Temporal.bin", pers);
        } else {
            guardarPersonaje("Temporal.bin", personaje);
        }
    }
    file.close();
    remove("Archivo_Personajes.bin");
    rename("Temporal.bin", "Archivo_Personajes.bin");

    //Guarda el grafo
    remove(this->mkVertices.c_str());
    remove(this->mkAristas.c_str());
    this->grafoPersonaje.guardar(this->mkVertices, this->mkAristas);

    cout << endl << "Regresando al menu de usuario..." << endl;
}

void MenuPersonajes::pausa() {
    cout << endl << "Presione [enter] para continuar..." << endl;
    cin.ignore();
}

MenuPersonajes::~MenuPersonajes() {
}

bool MenuPersonajes::validoOpcMenu(std::string& opc) {
    regex rx("[0-4]");
    if(regex_match(opc, rx) and opc.length() > 0) {
        return true;
    }
    return false;
}

bool MenuPersonajes::validoOpcModificar(std::string& opc) {
    regex rx("[0-2]");
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

void MenuPersonajes::guardarPersonaje(const std::string& archivo, Personaje& pers) {
    ofstream file(archivo, ios::binary|ios::app);
    file.write((char*)&pers, sizeof(pers));
    file.close();
}

