#ifndef WALLET_H
#define WALLET_H

#include <string>

class Paypal;

class Wallet {
public:
    Wallet(const std::string& username, const std::string& paypalUsername, const std::string& password);
    void mostrarEstadoCuenta();
    void comprarCrypto(const std::string& crypto, double amount);
    void venderCrypto(const std::string& crypto, double amount);
    void iniciarSesion();

private:
    std::string username;
    Paypal* paypal;
    std::string password;
    double dogeCoinBalance;
    double etheriumBalance;
    double walterCoinBalance;

    bool verificarSaldo(double amount);
};

#endif