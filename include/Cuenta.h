#ifndef CUENTA_H
#define CUENTA_H

#include <string>
using namespace std;

class Cuenta {
public:
    Cuenta();
    Cuenta(string username, string correo, string nombre, string passwd);
    string toString();
    virtual ~Cuenta();

protected:

private:
    string username;
    string correo;
    string nombre;
    string passwd;
};

#endif // CUENTA_H
