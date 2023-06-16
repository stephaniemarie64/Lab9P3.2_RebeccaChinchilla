#ifndef PAYPAL_H
#define PAYPAL_H

#include <string>
#include <vector>

class UsuarioPaypal;  // Declaración anticipada de la clase UsuarioPaypal

class Paypal {
public:
    Paypal(const std::string& username);
    void hacerDeposito(double amount, const std::string& descripcion);
    void hacerRetiro(double amount, const std::string& descripcion);
    double getSaldo() const;
    UsuarioPaypal* buscarUsuario(const std::string& username);

private:
    std::string username;
    std::vector<UsuarioPaypal*> usuarios;
};

#endif