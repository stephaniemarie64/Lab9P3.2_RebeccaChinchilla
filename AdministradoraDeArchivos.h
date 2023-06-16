#ifndef ADMINISTRADORA_ARCHIVOS_H
#define ADMINISTRADORA_ARCHIVOS_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "UsuarioPaypal.h"

class AdministradoraArchivos {
public:
    void guardarCuentasPaypal(const std::vector<UsuarioPaypal*>& cuentasPaypal);
    std::vector<UsuarioPaypal*> cargarCuentasPaypal();
};

#endif  // ADMINISTRADORA_ARCHIVOS_H