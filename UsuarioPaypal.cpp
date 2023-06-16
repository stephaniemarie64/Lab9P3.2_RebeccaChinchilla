#include "UsuarioPaypal.h"
#include <iostream>

UsuarioPaypal::UsuarioPaypal(const std::string& username, const std::string& id, const std::string& password, double saldo)
    : username(username), id(id), password(password), saldo(saldo) {}

std::string UsuarioPaypal::getUsername() const {
    return username;
}

std::string UsuarioPaypal::getId() const {
    return id;
}

std::string UsuarioPaypal::getPassword() const {
    return password;
}

double UsuarioPaypal::getSaldo() const {
    return saldo;
}

void UsuarioPaypal::hacerDeposito(double amount, const std::string& descripcion) {
    saldo += amount;
    std::cout << "Se ha realizado un depósito de $" << amount << " en tu cuenta." << std::endl;
    historialCuenta.push_back(descripcion);
    // Realizar la lógica para guardar el depósito en el historial de la cuenta
}

void UsuarioPaypal::hacerRetiro(double amount, const std::string& descripcion) {
    if (saldo >= amount) {
        saldo -= amount;
        std::cout << "Se ha realizado un retiro de $" << amount << " de tu cuenta." << std::endl;
        historialCuenta.push_back(descripcion);
        // Realizar la lógica para guardar el retiro en el historial de la cuenta
    }
    else {
        std::cout << "Saldo insuficiente en tu cuenta." << std::endl;
    }
}

void UsuarioPaypal::mostrarHistorialCuenta() const {
    std::cout << "Historial de cuenta de " << username << ":" << std::endl;
    for (const std::string& transaccion : historialCuenta) {
        std::cout << transaccion << std::endl;
    }
}

void UsuarioPaypal::guardarEnArchivo() const {
    // Guardar los datos del usuario en un archivo
}

void UsuarioPaypal::cargarDesdeArchivo() {
    // Cargar los datos del usuario desde un archivo
}