#include "AdministradoraDeArchivos.h"
#include <iostream>
#include <fstream>

const std::string AdministradoraDeArchivos::nombreArchivo = "cuentas_paypal.bin";

void AdministradoraDeArchivos::guardarCuentaPaypal(const Paypal& cuentaPaypal) {
    std::ofstream archivo(nombreArchivo, std::ios::binary | std::ios::out);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&cuentaPaypal), sizeof(cuentaPaypal));
        archivo.close();
        std::cout << "Cuenta de Paypal guardada exitosamente." << std::endl;
    }
    else {
        std::cerr << "Error al abrir el archivo para guardar la cuenta de Paypal." << std::endl;
    }
}

Paypal* AdministradoraDeArchivos::cargarCuentaPaypal() {
    std::ifstream archivo(nombreArchivo, std::ios::binary | std::ios::in);
    if (archivo.is_open()) {
        Paypal* cuentaPaypal = new Paypal("");
        archivo.read(reinterpret_cast<char*>(cuentaPaypal), sizeof(*cuentaPaypal));
        archivo.close();
        std::cout << "Cuenta de Paypal cargada exitosamente." << std::endl;
        return cuentaPaypal;
    }
    else {
        std::cerr << "Error al abrir el archivo para cargar la cuenta de Paypal." << std::endl;
        return nullptr;
    }
}