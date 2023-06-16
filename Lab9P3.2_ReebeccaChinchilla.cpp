#include <iostream>
#include <fstream>
#include <vector>
#include "Paypal.h"
#include "UsuarioPaypal.h"
#include "AdministradoraDeArchivos.h"
#include "Wallet.h"

using namespace std;

void mostrarMenuPaypal(Paypal* cuentaPaypal) {
    int opcion;

    do {
        // Mostrar el menú de Paypal
        cout << "-----Iniciar sesión-----" << endl;
        cout << "Ingrese su Usuario: ";
        string usuario;
        cin >> usuario;
        cout << "Ingrese su Contraseña: ";
        string contrasena;
        cin >> contrasena;
        cout << "------Bienvenido!------" << endl;
        cout << "1. Ver Estado de cuenta" << endl;
        cout << "2. Hacer depósito a mi propia cuenta" << endl;
        cout << "3. Hacer retiro de mi cuenta" << endl;
        cout << "4. Ver historial de cuenta" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cout << endl;

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
        case 1:
            cuentaPaypal->verEstadoCuenta(usuario); // Llamar a verEstadoCuenta con el argumento usuario
            break;
        case 2:
            cuentaPaypal->hacerDeposito(usuario); // Llamar a hacerDeposito con el argumento usuario
            break;
        case 3:
            cuentaPaypal->hacerRetiro(usuario); // Llamar a hacerRetiro con el argumento usuario
            break;
        case 4:
            cuentaPaypal->verHistorial(usuario); // Llamar a verHistorial con el argumento usuario
            break;
        case 5:
            cout << "Cerrando sesión de Paypal..." << endl;
            break;
        default:
            cout << "Opción inválida. Intenta de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 5);
}

void mostrarMenuWallet(Wallet* wallet) {
    int opcion;

    do {
        // Mostrar el menú de Wallet
        cout << "-----Iniciar sesión Wallet-----" << endl;
        cout << "Ingrese su Usuario: ";
        string usuario;
        cin >> usuario;
        cout << "Ingrese su Contraseña: ";
        string contrasena;
        cin >> contrasena;
        cout << "----Bienvenido!----" << endl;
        cout << "1. Ver Estado de cuenta" << endl;
        cout << "2. Comprar Cryptos" << endl;
        cout << "3. Vender Cryptos" << endl;
        cout << "4. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cout << endl;

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
        case 1:
            wallet->mostrarEstadoCuenta(usuario); // Llamar a mostrarEstadoCuenta con el argumento usuario
            break;
        case 2:
            wallet->comprarCrypto(usuario); // Llamar a comprarCrypto con el argumento usuario
            break;
        case 3:
            wallet->venderCrypto(usuario); // Llamar a venderCrypto con el argumento usuario
            break;
        case 4:
            cout << "Cerrando sesión de Wallet..." << endl;
            break;
        default:
            cout << "Opción inválida. Intenta de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 4);
}

int main() {
    int opcion;

    do {
        // Mostrar el menú principal
        cout << "-----Bienvenido al sistema de pagos-----" << endl;
        cout << "1. Crear cuenta Paypal" << endl;
        cout << "2. Crear cuenta Wallet" << endl;
        cout << "3. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1: {
            string usuario, contrasena;
            cout << "Ingrese un nombre de usuario: ";
            cin >> usuario;
            cout << "Ingrese una contraseña: ";
            cin >> contrasena;

            Paypal* cuentaPaypal = new Paypal(usuario, contrasena);
            AdministradoraDeArchivos::guardarPaypal(*cuentaPaypal);

            cout << "Cuenta Paypal creada exitosamente." << endl;

            mostrarMenuPaypal(cuentaPaypal);

            delete cuentaPaypal;
            break;
        }
        case 2: {
            string usuario, contrasena;
            cout << "Ingrese un nombre de usuario: ";
            cin >> usuario;
            cout << "Ingrese una contraseña: ";
            cin >> contrasena;

            Wallet* wallet = new Wallet(usuario, contrasena);
            AdministradoraDeArchivos::guardarWallet(*wallet);

            cout << "Cuenta Wallet creada exitosamente." << endl;

            mostrarMenuWallet(wallet);

            delete wallet;
            break;
        }
        case 3:
            cout << "Saliendo del sistema de pagos..." << endl;
            break;
        default:
            cout << "Opción inválida. Intenta de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 3);

    return 0;
}