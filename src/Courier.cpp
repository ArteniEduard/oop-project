#include "Courier.h"

Courier::Courier() : name(""), rating(0), available(true) {}

Courier::Courier(std::string name, double rating, bool available)
    : name(name), rating(rating), available(available) {
}

Courier::Courier(const Courier& other)
    : name(other.name), rating(other.rating), available(other.available) {
}

Courier& Courier::operator=(const Courier& other) {
    if (this != &other) {
        name = other.name;
        rating = other.rating;
        available = other.available;
    }
    return *this;
}

Courier::~Courier() {}

void Courier::assignOrder() {
    available = false;
}

void Courier::completeDelivery() {
    available = true;
}

bool Courier::isAvailable() const {
    return available;
}

std::ostream& operator<<(std::ostream& out, const Courier& c) {
    out << "Courier: " << c.name
        << " | Rating: " << c.rating
        << " | Available: " << (c.available ? "Yes" : "No");
    return out;
}