#include "UsuarioPaypal.h"

UsuarioPaypal::UsuarioPaypal() {
    email = "";
    contrasena = "";
}

UsuarioPaypal::UsuarioPaypal(const std::string& email, const std::string& contrasena) {
    this->email = email;
    this->contrasena = contrasena;
}

std::string UsuarioPaypal::getEmail() const {
    return email;
}

std::string UsuarioPaypal::getContrasena() const {
    return contrasena;
}