#ifndef USUARIO_PAYPAL_H
#define USUARIO_PAYPAL_H

#include <string>
#include <vector>

class UsuarioPaypal {
private:
    std::string usuario;
    std::string identidad;
    std::string contrasena;
    double saldo;
    std::vector<std::string> historial;

public:
    UsuarioPaypal(const std::string& usuario, const std::string& identidad, const std::string& contrasena, double saldoInicial);

    std::string getUsuario() const;
    double getSaldo() const;

    void depositar(double cantidad);
    bool retirar(double cantidad);
    void agregarTransaccion(const std::string& transaccion);
};

#endif  // USUARIO_PAYPAL_H