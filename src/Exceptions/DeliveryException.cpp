#include "../../include/Exceptions/DeliveryException.h"

DeliveryException::DeliveryException(const std::string& msg)
    : message(msg) {}

const char* DeliveryException::what() const noexcept {
    return message.c_str();
}