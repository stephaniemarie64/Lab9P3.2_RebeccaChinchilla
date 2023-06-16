#ifndef USUARIOPAYPAL_H
#define USUARIOPAYPAL_H

#include <string>

class UsuarioPaypal {
public:
    UsuarioPaypal();
    UsuarioPaypal(const std::string& email, const std::string& contrasena);

    std::string getEmail() const;
    std::string getContrasena() const;

private:
    std::string email;
    std::string contrasena;
};

#endif