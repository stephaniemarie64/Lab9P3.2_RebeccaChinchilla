#include "AdministradoraArchivos.h"

AdministradoraArchivos::AdministradoraArchivos(const std::string& directorio) {
    for (const auto& archivo : fs::directory_iterator(directorio)) {
        if (archivo.path().extension() == ".lab") {
            std::ifstream file(archivo.path(), std::ios::binary);
            if (file) {

                std::cout << "Leyendo archivo binario: " << archivo.path() << std::endl;
            }
            else {
                std::cerr << "Error al abrir el archivo: " << archivo.path() << std::endl;
            }
        }
    }
}

void AdministradoraArchivos::guardarUsuarioPaypal(const UsuarioPaypal& usuario) {
    std::ofstream archivoUsuarios(rutaArchivoUsuarios, std::ios::app);
    if (archivoUsuarios.is_open()) {
        archivoUsuarios << usuario.getEmail() << "," << usuario.getContrasena() << std::endl;
        archivoUsuarios.close();
        std::cout << "Usuario de Paypal guardado correctamente." << std::endl;
    }
    else {
        std::cout << "No se pudo abrir el archivo de usuarios." << std::endl;
    }
}

void AdministradoraArchivos::guardarWallet(const Wallet& wallet) {
    std::ofstream archivoWallets(rutaArchivoWallets, std::ios::app);
    if (archivoWallets.is_open()) {
        archivoWallets << wallet.getEmail() << "," << wallet.getContrasena() << std::endl;
        archivoWallets.close();
        std::cout << "Wallet guardado correctamente." << std::endl;
    }
    else {
        std::cout << "No se pudo abrir el archivo de wallets." << std::endl;
    }
}

UsuarioPaypal AdministradoraArchivos::obtenerUsuarioPaypal(const std::string& email) {
    std::ifstream archivoUsuarios(rutaArchivoUsuarios);
    std::string linea;
    while (std::getline(archivoUsuarios, linea)) {
        std::string correo, contrasena;
        std::size_t pos = linea.find(',');
        if (pos != std::string::npos) {
            correo = linea.substr(0, pos);
            contrasena = linea.substr(pos + 1);
            if (correo == email) {
                return UsuarioPaypal(correo, contrasena);
            }
        }
    }
    return UsuarioPaypal("", "");
}

Wallet AdministradoraArchivos::obtenerWallet(const std::string& email) {
    std::ifstream archivoWallets(rutaArchivoWallets);
    std::string linea;
    while (std::getline(archivoWallets, linea)) {
        std::string correo, contrasena;
        std::size_t pos = linea.find(',');
        if (pos != std::string::npos) {
            correo = linea.substr(0, pos);
            contrasena = linea.substr(pos + 1);
            if (correo == email) {
                return Wallet(correo, contrasena);
            }
        }
    }
    return Wallet("", "");
}

bool AdministradoraArchivos::existeArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    return archivo.good();
}
