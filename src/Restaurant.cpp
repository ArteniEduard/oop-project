#include "Restaurant.h"

Restaurant::Restaurant() : name(""), address(), rating(0) {}

Restaurant::Restaurant(std::string name, Address address, double rating)
    : name(name), address(address), rating(rating) {
}

Restaurant::Restaurant(const Restaurant& other)
    : name(other.name), address(other.address), rating(other.rating) {
}

Restaurant& Restaurant::operator=(const Restaurant& other) {
    if (this != &other) {
        name = other.name;
        address = other.address;
        rating = other.rating;
    }
    return *this;
}

Restaurant::~Restaurant() {}

bool Restaurant::isHighlyRated() const {
    return rating >= 4.5;
}

std::ostream& operator<<(std::ostream& out, const Restaurant& r) {
    out << "Restaurant: " << r.name
        << " | Rating: " << r.rating
        << " | Address: " << r.address;
    return out;
}