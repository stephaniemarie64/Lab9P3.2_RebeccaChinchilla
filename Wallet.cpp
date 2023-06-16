#include "Wallet.h"

Wallet::Wallet(const std::string& usuario, UsuarioPaypal* cuentaPaypal, const std::string& contrasena)
    : usuario(usuario), cuentaPaypal(cuentaPaypal), contrasena(contrasena) {}

std::string Wallet::getUsuario() const {
    return usuario;
}

UsuarioPaypal* Wallet::getCuentaPaypal() const {
    return cuentaPaypal;
}

void Wallet::mostrarEstadoCuenta() const {
    std::cout << "Estado de cuenta de Wallet de " << usuario << ":" << std::endl;
    std::cout << "Criptomonedas:";
    if (cryptos.empty()) {
        std::cout << " No tienes ninguna criptomoneda." << std::endl;
    }
    else {
        for (const auto& crypto : cryptos) {
            std::cout << " " << crypto;
        }
        std::cout << std::endl;
    }
}

void Wallet::comprarCrypto(const std::string& crypto) {
    double monto;
    if (crypto == "Doge coin") {
        monto = 0.6;
    }
    else if (crypto == "Etherium") {
        monto = 1000.0;
    }
    else if (crypto == "WalterCoin") {
        monto = 5.0;
    }
    else {
        std::cout << "Criptomoneda inválida." << std::endl;
        return;
    }

    if (cuentaPaypal->getSaldo() < monto) {
        std::cout << "Saldo insuficiente en la cuenta de Paypal." << std::endl;
        return;
    }

    cuentaPaypal->retirar(monto);
    cryptos.push_back(crypto);
    std::cout << "Se ha comprado " << crypto << " por $" << monto << " desde tu Wallet." << std::endl;
}

void Wallet::venderCrypto(const std::string& crypto) {
    double monto;
    if (crypto == "Doge coin") {
        monto = 0.6;
    }
    else if (crypto == "Etherium") {
        monto = 1000.0;
    }
    else if (crypto == "WalterCoin") {
        monto = 5.0;
    }
    else {
        std::cout << "Criptomoneda inválida." << std::endl;
        return;
    }

    auto it = std::find(cryptos.begin(), cryptos.end(), crypto);
    if (it == cryptos.end()) {
        std::cout << "No tienes " << crypto << " en tu Wallet." << std::endl;
        return;
    }

    cuentaPaypal->depositar(monto);
    cryptos.erase(it);
    std::cout << "Se ha vendido " << crypto << " por $" << monto << " desde tu Wallet." << std::endl;
}
