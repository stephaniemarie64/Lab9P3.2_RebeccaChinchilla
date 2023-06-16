#include "UsuarioPaypal.h"

UsuarioPaypal::UsuarioPaypal(const std::string& usuario, const std::string& identidad, const std::string& contrasena, double saldoInicial)
    : usuario(usuario), identidad(identidad), contrasena(contrasena), saldo(saldoInicial) {}

std::string UsuarioPaypal::getUsuario() const {
    return usuario;
}

double UsuarioPaypal::getSaldo() const {
    return saldo;
}

void UsuarioPaypal::depositar(double cantidad) {
    saldo += cantidad;
    std::cout << "Se ha depositado $" << cantidad << " a su cuenta. Nuevo saldo: $" << saldo << std::endl;
    agregarTransaccion("Se ha depositado $" + std::to_string(cantidad) + " en su cuenta.");
}

bool UsuarioPaypal::retirar(double cantidad) {
    if (cantidad > saldo) {
        std::cout << "Saldo insuficiente." << std::endl;
        return false;
    }

    saldo -= cantidad;
    std::cout << "Se ha retirado $" << cantidad << " de su cuenta. Nuevo saldo: $" << saldo << std::endl;
    agregarTransaccion("Se ha retirado $" + std::to_string(cantidad) + " de su cuenta.");
    return true;
}

void UsuarioPaypal::agregarTransaccion(const std::string& transaccion) {
    historial.push_back(transaccion);
}