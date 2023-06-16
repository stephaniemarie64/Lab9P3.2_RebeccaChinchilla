#include <iostream>
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
            cuentaPaypal->verEstadoCuenta();
            break;
        case 2:
            cuentaPaypal->hacerDeposito();
            break;
        case 3:
            cuentaPaypal->hacerRetiro();
            break;
        case 4:
            cuentaPaypal->verHistorial();
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
            wallet->verEstadoCuenta();
            break;
        case 2:
            wallet->comprarCryptos();
            break;
        case 3:
            wallet->venderCryptos();
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

void mostrarMenu() {
    AdministradoraDeArchivos administradora;

    int opcion;

    do {
        // Mostrar el menú principal
        cout << "-----Menu principal-----" << endl;
        cout << "1. Crear cuenta de Paypal" << endl;
        cout << "2. Crear cuenta de Wallet" << endl;
        cout << "3. Acceder a Paypal" << endl;
        cout << "4. Acceder a Wallet" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;
        cout << endl;

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
        case 1: {
            string usuario, contrasena;
            cout << "Ingrese un nombre de usuario para Paypal: ";
            cin >> usuario;
            cout << "Ingrese una contraseña para Paypal: ";
            cin >> contrasena;

            Paypal nuevaCuenta(usuario, contrasena);
            administradora.guardarCuentaPaypal(nuevaCuenta);
            cout << "Cuenta de Paypal creada exitosamente." << endl;
            break;
        }
        case 2: {
            string usuario, contrasena;
            cout << "Ingrese un nombre de usuario para Wallet: ";
            cin >> usuario;
            cout << "Ingrese una contraseña para Wallet: ";
            cin >> contrasena;

            Wallet nuevoWallet(usuario, contrasena);
            administradora.guardarWallet(nuevoWallet);
            cout << "Cuenta de Wallet creada exitosamente." << endl;
            break;
        }
        case 3: {
            Paypal* cuentaPaypal = administradora.cargarCuentaPaypal();
            if (cuentaPaypal != nullptr) {
                mostrarMenuPaypal(cuentaPaypal);
                delete cuentaPaypal;
            }
            else {
                cout << "No se pudo cargar la cuenta de Paypal." << endl;
            }
            break;
        }
        case 4: {
            Wallet* wallet = administradora.cargarWallet();
            if (wallet != nullptr) {
                mostrarMenuWallet(wallet);
                delete wallet;
            }
            else {
                cout << "No se pudo cargar la cuenta de Wallet." << endl;
            }
            break;
        }
        case 5:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intenta de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 5);

    return 0;
}

int main() {
    mostrarMenu();
    return 0;
}