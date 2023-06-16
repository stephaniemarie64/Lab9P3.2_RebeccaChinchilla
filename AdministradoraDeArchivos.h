#ifndef ADMINISTRADORADEARCHIVOS_H
#define ADMINISTRADORADEARCHIVOS_H

#include "Paypal.h"

class AdministradoraDeArchivos {
public:
    static void guardarCuentaPaypal(const Paypal& cuentaPaypal);
    static Paypal* cargarCuentaPaypal();

private:
    static const std::string nombreArchivo;
};

#endif
