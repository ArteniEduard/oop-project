#ifndef DELIVERYEXCEPTION_H
#define DELIVERYEXCEPTION_H

#include <exception>
#include <string>

class DeliveryException : public std::exception {
protected:
    std::string message;

public:
    explicit DeliveryException(const std::string &msg);

    const char *what() const noexcept override;

    virtual ~DeliveryException() = default;
};

#endif
