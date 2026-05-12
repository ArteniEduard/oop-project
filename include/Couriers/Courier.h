#ifndef COURIER_H
#define COURIER_H

#include <iostream>
#include <string>

class Courier {
protected:
    std::string name;
    double rating;
    bool available;

public:
    Courier();

    Courier(const std::string& name, double rating);

    Courier(const Courier &other);

    Courier &operator=(const Courier &other);

    virtual ~Courier();

    void assignOrder();

    void completeDelivery();

    bool isAvailable() const;

    virtual Courier *clone() const = 0;

    virtual double calculateDeliveryTime(double distance) const = 0;

    virtual std::string getVehicleType() const = 0;

    friend std::ostream &operator<<(std::ostream &out, const Courier &c);
};

#endif
