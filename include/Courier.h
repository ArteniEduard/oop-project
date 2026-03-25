#ifndef COURIER_H
#define COURIER_H

#include <iostream>
#include <string>

class Courier {
private:
    std::string name;
    double rating;
    bool available;

public:
    Courier();
    Courier(std::string name, double rating, bool available);
    Courier(const Courier& other);
    Courier& operator=(const Courier& other);
    ~Courier();

    void assignOrder();
    void completeDelivery();
    bool isAvailable() const;

    friend std::ostream& operator<<(std::ostream& out, const Courier& c);
};

#endif