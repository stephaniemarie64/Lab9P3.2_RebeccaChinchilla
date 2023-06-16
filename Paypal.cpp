#include "Paypal.h"

void Paypal::crearCuentaPaypal() {
    std::string usuario, identidad, contrasena;
    double saldoInicial;
    bool usuarioUnico = false;

    do {
        std::cout << "Ingrese el nombre de usuario: ";
        std::cin >> usuario;

        // Verificar si el usuario ya existe
        if (buscarCuentaPorUsuario(usuario) == nullptr) {
            usuarioUnico = true;
        }
        else {
            std::cout << "El nombre de usuario ya está en uso. Intente con otro." << std::endl;
        }
    } while (!usuarioUnico);

    std::cout << "Ingrese el número de identidad: ";
    std::cin >> identidad;

    std::cout << "Ingrese la contraseña: ";
    std::cin >> contrasena;

    std::cout << "Ingrese el saldo inicial: ";
    std::cin >> saldoInicial;

    UsuarioPaypal* nuevaCuenta = new UsuarioPaypal(usuario, identidad, contrasena, saldoInicial);
    cuentasPaypal.push_back(nuevaCuenta);

    std::cout << "Cuenta de Paypal creada exitosamente." << std::endl;
}

UsuarioPaypal* Paypal::buscarCuentaPorUsuario(const std::string& usuario) const {
    for (UsuarioPaypal* cuenta : cuentasPaypal) {
        if (cuenta->getUsuario() == usuario) {
            return cuenta;
        }
    }
    return nullptr;
}
