#include "Paypal.h"
#include "UsuarioPaypal.h"
#include <iostream>

Paypal::Paypal(const std::string& username) : username(username) {}

void Paypal::hacerDeposito(double amount, const std::string& descripcion) {
    std::cout << "Se ha depositado $" << amount << " en tu cuenta de Paypal." << std::endl;
    // Realizar la lógica para hacer el depósito en la cuenta de Paypal
}

void Paypal::hacerRetiro(double amount, const std::string& descripcion) {
    std::cout << "Se ha retirado $" << amount << " de tu cuenta de Paypal." << std::endl;
    // Realizar la lógica para hacer el retiro de la cuenta de Paypal
}

double Paypal::getSaldo() const {
    // Obtener el saldo actual de la cuenta de Paypal
    return 0.0;
}

UsuarioPaypal* Paypal::buscarUsuario(const std::string& username) {
    for (UsuarioPaypal* usuario : usuarios) {
        if (usuario->getUsername() == username) {
            return usuario;
        }
    }
    return nullptr;
}