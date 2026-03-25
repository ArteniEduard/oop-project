#include "Address.h"

Address::Address() : city(""), street(""), number(0) {}

Address::Address(std::string city, std::string street, int number)
    : city(city), street(street), number(number) {
}

Address::Address(const Address& other)
    : city(other.city), street(other.street), number(other.number) {
}

Address& Address::operator=(const Address& other) {
    if (this != &other) {
        city = other.city;
        street = other.street;
        number = other.number;
    }
    return *this;
}

Address::~Address() {}

std::string Address::getCity() const {
    return city;
}

std::ostream& operator<<(std::ostream& out, const Address& a) {
    out << a.city << ", " << a.street << " nr. " << a.number;
    return out;
}