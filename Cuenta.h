#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include "Personaje.h"

class Cuenta {
public:
    Cuenta();
    Cuenta(std::string cuentaString);
    Cuenta(std::string username, std::string correo, std::string nombre, std::string passwd);
    void setUserName(std::string& user);
    void setCorreo(std::string& email);
    void setNombre(std::string& name);
    void setPasswd(std::string& pass);
    std::string getUserName();
    std::string getCorreo();
    std::string getNombre();
    std::string getPasswd();
    std::string toString();
    std::string toFile();
    virtual ~Cuenta();

private:
    std::string username;
    std::string correo;
    std::string nombre;
    std::string passwd;
};

#endif // CUENTA_H
