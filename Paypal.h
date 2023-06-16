#ifndef PAYPAL_H
#define PAYPAL_H

#include <vector>
#include <string>
#include "UsuarioPaypal.h"

class Paypal {
private:
    std::vector<UsuarioPaypal*> cuentasPaypal;

public:
    void crearCuentaPaypal();
    UsuarioPaypal* buscarCuentaPorUsuario(const std::string& usuario) const;
};

#endif  // PAYPAL_H