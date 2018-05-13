#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include "Personaje.h"

class Cuenta {
public:
    Cuenta();
    Cuenta(std::string cuentaString);
    Cuenta(std::string username, std::string correo, std::string nombre, std::string passwd, long int &posIndice, int &maxPersonajes);
    void setUserName(std::string& user);
    void setCorreo(std::string& email);
    void setNombre(std::string& name);
    void setPasswd(std::string& pass);
    void setPosIndice(const long int &posIndice);
    void setMaxPersonajes(const int &maxPersonajes);
    std::string getUserName();
    std::string getCorreo();
    std::string getNombre();
    std::string getPasswd();
    std::string toString();
    long int getPosIndice();
    int getMaxPersonajes();
    std::string toFile();
    virtual ~Cuenta();

private:
    std::string username;
    std::string correo;
    std::string nombre;
    std::string passwd;
    long int posIndice;
    int maxPersonajes;
};

#endif // CUENTA_H
