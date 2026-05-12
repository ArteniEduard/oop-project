#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include "Address.h"

class Restaurant {
private:
    std::string name;
    Address address;
    double rating;

public:
    Restaurant();

    Restaurant(const std::string& name, const Address& address, double rating);

    Restaurant(const Restaurant &other);

    Restaurant &operator=(const Restaurant &other);

    ~Restaurant();

    bool isHighlyRated() const;

    friend std::ostream &operator<<(std::ostream &out, const Restaurant &r);
};

#endif
