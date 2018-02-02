#ifndef CUENTA_H
#define CUENTA_H

#include <string>

using namespace std;

class Cuenta {
public:
    Cuenta();
    Cuenta(std::string cuentaString);
    Cuenta(string username, string correo, string nombre, string passwd);
    void setUserName(std::string& user);
    void setCorreo(std::string& email);
    void setNombre(std::string& name);
    void setPasswd(std::string& pass);
    std::string getUserName();
    std::string getCorreo();
    std::string getNombre();
    std::string getPasswd();
    string toString();
    string toFile();
    virtual ~Cuenta();
    /*bool operator ==(const Cuenta& cuenta);
    bool operator !=(const Cuenta& cuenta);
    bool operator <(const Cuenta& cuenta);
    bool operator <=(const Cuenta& Cuenta);
    bool operator >=(const Cuenta& Cuenta);
    bool operator >(const Cuenta& Cuenta);*/

private:
    string username;
    string correo;
    string nombre;
    string passwd;
};

#endif // CUENTA_H
