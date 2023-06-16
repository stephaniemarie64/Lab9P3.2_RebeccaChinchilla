#ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
public:
    Wallet();
    Wallet(const std::string& email, const std::string& contrasena);

    std::string getEmail() const;
    std::string getContrasena() const;

private:
    std::string email;
    std::string contrasena;
};

#endif