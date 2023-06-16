#include <iostream>
#include "AdministradoraArchivos.h"
#include "Wallet.h"
#include "Paypal.h
#include "UsuarioPaypal.h"

void mostrarMenuPrincipal(AdministradoraArchivos& administradora) {
    int opcion;

    do {
        std::cout << "Menú principal:" << std::endl;
        std::cout << "1. Crear cuenta de PayPal" << std::endl;
        std::cout << "2. Crear Wallet" << std::endl;
        std::cout << "3. Cargar información" << std::endl;
        std::cout << "4. Acceder a PayPal" << std::endl;
        std::cout << "5. Acceder a Wallet" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            std::string email, contrasena;
            std::cout << "Ingrese su email: ";
            std::cin >> email;
            std::cout << "Ingrese su contraseña: ";
            std::cin >> contrasena;

            UsuarioPaypal usuario(email, contrasena);
            administradora.guardarUsuarioPaypal(usuario);
            std::cout << "Cuenta de PayPal creada exitosamente." << std::endl;
            break;
        }
        case 2: {
            std::string email, contrasena;
            std::cout << "Ingrese su email: ";
            std::cin >> email;
            std::cout << "Ingrese su contraseña: ";
            std::cin >> contrasena;

            Wallet wallet(email, contrasena);
            administradora.guardarWallet(wallet);
            std::cout << "Wallet creado exitosamente." << std::endl;
            break;
        }
        case 3: {
            std::cout << "Ingrese su email: ";
            std::string email;
            std::cin >> email;

            UsuarioPaypal usuario = administradora.obtenerUsuarioPaypal(email);
            if (usuario.getEmail() != "") {
                std::cout << "Información de PayPal:" << std::endl;
                std::cout << "Email: " << usuario.getEmail() << std::endl;
                std::cout << "Contraseña: " << usuario.getContrasena() << std::endl;
            }
            else {
                std::cout << "No se encontró información de PayPal para el email ingresado." << std::endl;
            }

            Wallet wallet = administradora.obtenerWallet(email);
            if (wallet.getEmail() != "") {
                std::cout << "Información de Wallet:" << std::endl;
                std::cout << "Email: " << wallet.getEmail() << std::endl;
                std::cout << "Contraseña: " << wallet.getContrasena() << std::endl;
            }
            else {
                std::cout << "No se encontró información de Wallet para el email ingresado." << std::endl;
            }
            break;
        }
        case 4:
            // Acceder a PayPal
            std::cout << "Acceder a PayPal" << std::endl;
            break;
        case 5:
            // Acceder a Wallet
            std::cout << "Acceder a Wallet" << std::endl;
            break;
        case 6:
            std::cout << "¡Hasta luego!" << std::endl;
            break;
        default:
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (opcion != 6);
}

int main() {
    AdministradoraArchivos administradora;

    mostrarMenuPrincipal(administradora);

    return 0;
}