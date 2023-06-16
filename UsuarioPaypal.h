#ifndef USUARIOPAYPAL_H
#define USUARIOPAYPAL_H

#include <string>
#include <vector>

class UsuarioPaypal {
public:
    UsuarioPaypal(const std::string& username, const std::string& id, const std::string& password, double saldo);
    std::string getUsername() const;
    std::string getId() const;
    std::string getPassword() const;
    double getSaldo() const;
    void hacerDeposito(double amount, const std::string& descripcion);
    void hacerRetiro(double amount, const std::string& descripcion);
    void mostrarHistorialCuenta() const;
    void guardarEnArchivo() const;
    void cargarDesdeArchivo();

private:
    std::string username;
    std::string id;
    std::string password;
    double saldo;
    std::vector<std::string> historialCuenta;
};

#endif