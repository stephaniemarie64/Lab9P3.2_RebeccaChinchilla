#include "Paypal.h"

Paypal::Paypal() {
    email = "";
    contrasena = "";
}

Paypal::Paypal(const std::string& email, const std::string& contrasena) {
    this->email = email;
    this->contrasena = contrasena;
}

std::string Paypal::getEmail() const {
    return email;
}

std::string Paypal::getContrasena() const {
    return contrasena;
}