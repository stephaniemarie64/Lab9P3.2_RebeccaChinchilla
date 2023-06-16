#include "Wallet.h"

Wallet::Wallet() {
    email = "";
    contrasena = "";
}

Wallet::Wallet(const std::string& email, const std::string& contrasena) {
    this->email = email;
    this->contrasena = contrasena;
}

std::string Wallet::getEmail() const {
    return email;
}

std::string Wallet::getContrasena() const {
    return contrasena;
}