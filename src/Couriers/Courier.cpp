#include "../../include/Couriers/Courier.h"

#include "Exceptions/CourierUnavailableException.h"

Courier::Courier() : rating(0), available(true) {
}

Courier::Courier(const std::string &name, const double rating)
    : name(name), rating(rating), available(true) {
}

Courier::Courier(const Courier &other)
    : name(other.name), rating(other.rating), available(other.available) {
}


Courier &Courier::operator=(const Courier &other) {
    if (this != &other) {
        name = other.name;
        rating = other.rating;
        available = other.available;
    }
    return *this;
}

Courier::~Courier() = default;

void Courier::assignOrder() {
    if (!available)
        throw CourierUnavailableException();

    available = false;
}

void Courier::completeDelivery() {
    available = true;
}

bool Courier::isAvailable() const {
    return available;
}

std::ostream &operator<<(std::ostream &out, const Courier &c) {
    out << "Courier: " << c.name
            << " | Rating: " << c.rating
            << " | Available: " << (c.available ? "Yes" : "No")
            << " | Vehicle: " << c.getVehicleType();
    return out;
}
