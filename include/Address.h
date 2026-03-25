#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int number;

public:
    Address();
    Address(std::string city, std::string street, int number);
    Address(const Address& other);
    Address& operator=(const Address& other);
    ~Address();

    const std::string& getCity() const;

    friend std::ostream& operator<<(std::ostream& out, const Address& a);
};

#endif