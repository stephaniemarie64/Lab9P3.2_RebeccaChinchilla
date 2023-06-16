#include "Wallet.h"
#include "Paypal.h"
#include <iostream>

Wallet::Wallet(const std::string& username, const std::string& paypalUsername, const std::string& password)
    : username(username), paypal(nullptr), password(password), dogeCoinBalance(0.0),
    etheriumBalance(0.0), walterCoinBalance(0.0) {
    paypal = new Paypal(paypalUsername);
}

void Wallet::mostrarEstadoCuenta() {
    std::cout << "Estado de cuenta de " << username << ":" << std::endl;
    std::cout << "Doge Coin: " << dogeCoinBalance << std::endl;
    std::cout << "Etherium: " << etheriumBalance << std::endl;
    std::cout << "WalterCoin: " << walterCoinBalance << std::endl;
}

void Wallet::comprarCrypto(const std::string& crypto, double amount) {
    if (paypal == nullptr) {
        std::cout << "No se puede realizar la transacci�n. Cuenta de Paypal no configurada." << std::endl;
        return;
    }

    double totalAmount = 0.0;
    if (crypto == "DogeCoin") {
        totalAmount = amount * 0.6;
        if (verificarSaldo(totalAmount)) {
            dogeCoinBalance += amount;
            paypal->hacerRetiro(totalAmount, "Compra de DogeCoin desde Wallet");
        }
    }
    else if (crypto == "Etherium") {
        totalAmount = amount * 1000;
        if (verificarSaldo(totalAmount)) {
            etheriumBalance += amount;
            paypal->hacerRetiro(totalAmount, "Compra de Etherium desde Wallet");
        }
    }
    else if (crypto == "WalterCoin") {
        totalAmount = amount * 5;
        if (verificarSaldo(totalAmount)) {
            walterCoinBalance += amount;
            paypal->hacerRetiro(totalAmount, "Compra de WalterCoin desde Wallet");
        }
    }
    else {
        std::cout << "La criptomoneda especificada no es v�lida." << std::endl;
    }
}

void Wallet::venderCrypto(const std::string& crypto, double amount) {
    if (paypal == nullptr) {
        std::cout << "No se puede realizar la transacci�n. Cuenta de Paypal no configurada." << std::endl;
        return;
    }

    double totalAmount = 0.0;
    if (crypto == "DogeCoin") {
        if (amount <= dogeCoinBalance) {
            totalAmount = amount * 0.6;
            dogeCoinBalance -= amount;
            paypal->hacerDeposito(totalAmount, "Venta de DogeCoin desde Wallet");
        }
        else {
            std::cout << "No tienes suficiente DogeCoin para vender." << std::endl;
        }
    }
    else if (crypto == "Etherium") {
        if (amount <= etheriumBalance) {
            totalAmount = amount * 1000;
            etheriumBalance -= amount;
            paypal->hacerDeposito(totalAmount, "Venta de Etherium desde Wallet");
        }
        else {
            std::cout << "No tienes suficiente Etherium para vender." << std::endl;
        }
    }
    else if (crypto == "WalterCoin") {
        if (amount <= walterCoinBalance) {
            totalAmount = amount * 5;
            walterCoinBalance -= amount;
            paypal->hacerDeposito(totalAmount, "Venta de WalterCoin desde Wallet");
        }
        else {
            std::cout << "No tienes suficiente WalterCoin para vender." << std::endl;
        }
    }
    else {
        std::cout << "La criptomoneda especificada no es v�lida." << std::endl;
    }
}

void Wallet::iniciarSesion() {
    std::cout << "Iniciar sesi�n en Wallet" << std::endl;
    // Realizar la l�gica para iniciar sesi�n en Wallet
}

bool Wallet::verificarSaldo(double amount) {
    if (paypal != nullptr && amount <= paypal->getSaldo()) {
        return true;
    }
    else {
        std::cout << "Saldo insuficiente en tu cuenta de Paypal." << std::endl;
        return false;
    }
}