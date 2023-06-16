#ifndef ADMINISTRADORARCHIVOS_H
#define ADMINISTRADORARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "UsuarioPaypal.h"
#include "Wallet.h"

class AdministradoraArchivos {
public:
    AdministradoraArchivos();

    void guardarUsuarioPaypal(const UsuarioPaypal& usuario);
    void guardarWallet(const Wallet& wallet);

    UsuarioPaypal obtenerUsuarioPaypal(const std::string& email);
    Wallet obtenerWallet(const std::string& email);

private:
    std::string rutaArchivoUsuarios;
    std::string rutaArchivoWallets;

    bool existeArchivo(const std::string& rutaArchivo);
};

#endif