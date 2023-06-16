#ifndef PAYPAL_H
#define PAYPAL_H

#include <string>

class Paypal {
public:
    Paypal();
    Paypal(const std::string& email, const std::string& contrasena);

    std::string getEmail() const;
    std::string getContrasena() const;

private:
    std::string email;
    std::string contrasena;
};

#endif