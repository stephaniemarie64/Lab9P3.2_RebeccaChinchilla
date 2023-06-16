#include "Wallet.h"
#include <iostream>
#include <fstream>

Wallet::Wallet(const std::string& username, const std::string& paypalUsername, Paypal* paypal)
    : username(username), paypalUsername(paypalUsername), paypal(paypal), balance(0.0) {}

Wallet::~Wallet() {}

void Wallet::login() {
    std::string enteredUsername, enteredPassword;
    std::cout << "----- Iniciar sesi�n Wallet -----\n";
    std::cout << "Ingrese su Usuario: ";
    std::cin >> enteredUsername;
    std::cout << "Ingrese su Contrase�a: ";
    std::cin >> enteredPassword;

    if (enteredUsername == username && enteredPassword == password) {
        std::cout << "---- Bienvenido! ----\n";
        showMainMenu();
    }
    else {
        std::cout << "Credenciales inv�lidas. Saliendo del programa...\n";
    }
}

void Wallet::showMainMenu() {
    int opcion;
    do {
        std::cout << "1. Ver Estado de cuenta\n";
        std::cout << "2. Comprar Cryptos\n";
        std::cout << "3. Vender Cryptos\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opci�n: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            showAccountInfo();
            break;
        case 2:
            buyCryptos();
            break;
        case 3:
            sellCryptos();
            break;
        case 4:
            saveWallet();
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opci�n inv�lida. Intente nuevamente.\n";
            break;
        }
    } while (opcion != 4);
}

bool Wallet::validatePassword(const std::string& password) {
    // Validar que la contrase�a cumple con los requisitos (alfanum�rica, m�nimo 8 caracteres, car�cter especial)
    // Retorna true si la contrase�a es v�lida, false en caso contrario
    // Implementa la l�gica necesaria
}

void Wallet::deposit(double amount) {
    balance += amount;
    std::string transaction = "Se ha depositado " + std::to_string(amount) + " desde su wallet";
    transactionHistory.push_back(transaction);
    std::cout << "Se ha depositado " << amount << " d�lares. Nuevo saldo: " << balance << " d�lares\n";
}

void Wallet::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::string transaction = "Se ha retirado " + std::to_string(amount) + " desde su wallet";
        transactionHistory.push_back(transaction);
        std::cout << "Se ha retirado " << amount << " d�lares. Nuevo saldo: " << balance << " d�lares\n";
    }
    else {
        std::cout << "Saldo insuficiente\n";
    }
}

void Wallet::showAccountInfo() {
    std::cout << "Usuario: " << username << "\n";
    std::cout << "Saldo: " << balance << " d�lares\n";
    std::cout << "Historial de cuenta:\n";
    for (const auto& transaction : transactionHistory) {
        std::cout << "- " << transaction << "\n";
    }
}

void Wallet::buyCryptos() {
    // Implementa la l�gica para comprar cryptos
}

void Wallet::sellCryptos() {
    // Implementa la l�gica para vender cryptos
}

void Wallet::saveWallet() {
    std::string filename = username + ".lab";
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.write(reinterpret_cast<char*>(this), sizeof(Wallet));
        file.close();
        std::cout << "La billetera se ha guardado correctamente en el archivo " << filename << "\n";
    }
    else {
        std::cout << "No se pudo guardar la billetera en el archivo " << filename << "\n";
    }
}