#include "MenuPersonajes.h"

MenuPersonajes::MenuPersonajes() {
    menuPrincipal();
}

MenuPersonajes::MenuPersonajes(Personaje& pers, Grafo & graf) {
    personaje = pers;
    grafoGeneral = graf;
    //Lee del directorio el inventario
    listaInventario.leerDelDisco(DIR + string(personaje.getNombre()) + SLASH + string(personaje.getNombre()) + "_Inventario.txt");

    //Lee el grafo del Personaje
    grafoPersonaje.cargar(DIR + string(personaje.getNombre()) + SLASH + string(personaje.getNombre()) + "_Vertices.txt", DIR + string(personaje.getNombre()) + SLASH + string(personaje.getNombre()) + "_Aristas.txt");
    menuPrincipal();
}

void MenuPersonajes::menuPrincipal() {
    string opc;
    do {
        system(CLEAR);
        cout << "*** Opciones para el personaje " << personaje.getNombre() << " ***" << endl << endl;
        cout << "1) Modificar atributos." << endl;
        cout << "2) Mostrar." << endl;
        cout << "3) Completar mision." << endl;
        cout << "4) Ver mapa." << endl;
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
        cout << listaInventario.toString();
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
    system(CLEAR);
    cout << "*** Mostrar atributos del personaje ***" << endl << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Nombre: " << left << setw(18) << "| Genero: " << left <<setw(18) << "| EXP: " << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << personaje.getNombre() << "| " << left << setw(16)  << personaje.getGenero() << "| "<< left << setw(16)  << personaje.getExperiencia() << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Rol: " << left << setw(18) << "| Raza: " << left <<setw(18) << "| Equipo: " << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << personaje.getRol() << "| " << left << setw(16)  << personaje.getRaza() << "| "<< left << setw(16)  << personaje.getEquipo() << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Arma: " << left << setw(18) << "| Ataque: " << left <<setw(18) << "| Ubicacion: " << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << personaje.getArma().getNombre() << "| " << left << setw(16)  << to_string(personaje.getArma().getAtaque()) << "| "<< left << setw(16)  << personaje.getUbicacionActual() << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n";
    cout << left << setw(18) << "| Descripcion: " << left << setw(18) << "" << left <<setw(18) << "" << left <<setw(16) << "|" << endl;
    cout << "| " << left << setw(16) << personaje.getArma().getDescripcion() << "" << left << setw(11)  << "" << left << setw(16)  << "|" << endl;
    cout << "+-----------------+-----------------+-----------------+\n\n";

    cout << "Inventario: " << endl;
    cout << listaInventario.toString();
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
        if(personaje.getMisiones()[0]) {
            cout <<  "Mision ya hecha." << endl;
        } else {
            personaje.setExperiencia(100);
            personaje.setMision(0);
        }
    } else if(opc == "2") {

        if(personaje.getMisiones()[1]) {
            cout <<  "Mision ya hecha." << endl;
        } else {
            personaje.setExperiencia(200);
            personaje.setMision(1);
        }
    } else {

        if(personaje.getMisiones()[2]) {
            cout <<  "Mision ya hecha." << endl;
        } else {
            personaje.setExperiencia(300);
            personaje.setMision(2);
        }
    }
}

void MenuPersonajes::mostrarMapa() {
    system(CLEAR);
    cout << "*** Ver mapa ***" << endl << endl;
    string opc;
    cout << "Mapa general: " << endl << grafoGeneral.toListaAdyacencia() << endl;
    cout << "Mapa conocido: " << endl << grafoPersonaje.toListaAdyacencia() << endl;
    do{
        cout << "Desea viajar?(S/N): ";
        getline(cin, opc);
    }while(opc != "S" and opc != "s" and opc != "N" and opc != "n");
    if(opc == "S" or opc == "s"){
        system(CLEAR);
        Vertice* origen(grafoPersonaje.regresaVertice(string(personaje.getUbicacionActual())));
        cout << "*** Viajar ***" << endl << endl;
        cout << "Ubicacion actual: " << personaje.getUbicacionActual() << endl;
        cout << "Posibles destinos -> " << grafoPersonaje.toStringAdyacencias(origen) << endl;
        cout << "Elije un destino o presione 0 para no viajar." << endl;
        string strDestino;
        Vertice* destino;
        bool bandera = false;
        do{
            cout << ">> ";
            getline(cin, strDestino);
            if(!grafoPersonaje.existeVertice(strDestino) and strDestino != "0"){
                cout << endl << "No existe el destino. Intente de nuevo." << endl;
            }
            else{
                destino = grafoPersonaje.regresaVertice(strDestino);
                if(!grafoPersonaje.existeAdyacencia(origen, destino)){
                    cout << endl << "No existe una ruta entre " << personaje.getUbicacionActual() << " y " << strDestino << ". Intente de nuevo." << endl;
                }
                else{
                    personaje.setUbicacionActual(strDestino);
                    bandera = true;
                }
            }
        }while(!bandera and strDestino != "0");
        if(strDestino == "0"){
            cout << personaje.getNombre() <<" se ha quedado en el pueblo actual." << endl;
            return;
        }
        grafoPersonaje.insertarVertice(grafoPersonaje.verticeUltimaPos(), strDestino);

        Vertice* auxOrigen(grafoGeneral.regresaVertice(strDestino));
        Vertice* auxVerticeOri(grafoPersonaje.regresaVertice(strDestino));
        Arista* auxDestino(auxOrigen->getSigArista());
        while(auxDestino != nullptr){
            string auxNomDestino = auxDestino->getDestino()->getNombre();
            grafoPersonaje.insertarVertice(grafoPersonaje.verticeUltimaPos(), auxNomDestino);
            grafoPersonaje.insertaAdyacencia(auxVerticeOri, grafoPersonaje.regresaVertice(auxNomDestino), auxDestino->getReferencia().getPeso());
            auxDestino = auxDestino->getSiguiente();
        }
        cout << personaje.getNombre() << " ha viajadoo exitosamente a " << strDestino << "." << endl;
    }
    else{
        cout << personaje.getNombre() <<" se ha quedado en el pueblo actual." << endl;
    }
}


void MenuPersonajes::abandonar() {
    //Guarda lo modificado en el personaje
    string auxStr = personaje.getNombre();
    ifstream file("Archivo_Personajes.bin");
    Personaje pers;
    while(!file.eof()) {
        file.read((char*)&pers, sizeof(pers));
        if(file.eof()) {
            break;
        }
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
    string mkVertices, mkAristas;
    mkVertices = DIR + string(pers.getNombre()) + SLASH + string(pers.getNombre()) + "_Vertices.txt";
    mkAristas = DIR + string(pers.getNombre()) + SLASH + string(pers.getNombre()) + "_Aristas.txt";
    grafoPersonaje.guardar(mkVertices, mkAristas);
    grafoPersonaje.borrarTodo();

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

