#include "AdministradoraArchivos.h"

void AdministradoraArchivos::guardarCuentasPaypal(const std::vector<UsuarioPaypal*>& cuentasPaypal) {
    for (UsuarioPaypal* cuenta : cuentasPaypal) {
        std::string nombreArchivo = cuenta->getIdentidad() + ".lab";
        std::ofstream archivo(nombreArchivo, std::ios::binary | std::ios::out);

        if (archivo.is_open()) {
            archivo.write(reinterpret_cast<const char*>(cuenta), sizeof(UsuarioPaypal));
            archivo.close();
            std::cout << "Cuenta guardada en archivo: " << nombreArchivo << std::endl;
        }
        else {
            std::cout << "Error al guardar la cuenta en el archivo: " << nombreArchivo << std::endl;
        }
    }
}

std::vector<UsuarioPaypal*> AdministradoraArchivos::cargarCuentasPaypal() {
    std::vector<UsuarioPaypal*> cuentasPaypal;

    std::ifstream archivo;
    archivo.open(".", std::ios::binary | std::ios::in);

    if (!archivo) {
        std::cout << "No se encontraron archivos para cargar." << std::endl;
        return cuentasPaypal;
    }

    std::string extension = ".lab";
    std::string nombreArchivo;
    while (archivo.peek() != EOF) {
        archivo >> nombreArchivo;

        if (nombreArchivo.substr(nombreArchivo.size() - extension.size()) == extension) {
            std::ifstream cuentaArchivo(nombreArchivo, std::ios::binary | std::ios::in);
            if (cuentaArchivo.is_open()) {
                UsuarioPaypal* cuenta = new UsuarioPaypal();
                cuentaArchivo.read(reinterpret_cast<char*>(cuenta), sizeof(UsuarioPaypal));
                cuentasPaypal.push_back(cuenta);
                cuentaArchivo.close();
            }
        }
    }

    archivo.close();
    return cuentasPaypal;
}
