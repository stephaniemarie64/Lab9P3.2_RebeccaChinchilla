#ifndef WALLET_H
#define WALLET_H

#include <string>
#include <vector>
#include "UsuarioPaypal.h"

class Wallet {
private:
    std::string usuario;
    UsuarioPaypal* cuentaPaypal;
    std::string contrasena;
    std::vector<std::string> cryptos;

public:
    Wallet(const std::string& usuario, UsuarioPaypal* cuentaPaypal, const std::string& contrasena);

    std::string getUsuario() const;
    UsuarioPaypal* getCuentaPaypal() const;

    void mostrarEstadoCuenta() const;
    void comprarCrypto(const std::string& crypto);
    void venderCrypto(const std::string& crypto);
};

#endif  // WALLET_H