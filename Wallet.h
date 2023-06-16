#ifndef WALLET_H
#define WALLET_H

#include <iostream>
#include <vector>
#include <string>
#include "Paypal.h"

class Wallet {
private:
    std::string usuario;
    Paypal* cuentaPaypal;
    std::string contrasena;

public:
    Wallet(const std::string& usuario, Paypal* cuentaPaypal);

    void iniciarSesion();
    void mostrarEstadoCuenta();
    void comprarCryptos();
    void venderCryptos();
    void mostrarMenu();
};

#endif  // WALLET_H
