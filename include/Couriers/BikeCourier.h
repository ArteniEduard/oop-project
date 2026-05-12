#ifndef BIKECOURIER_H
#define BIKECOURIER_H

#include "Courier.h"

class BikeCourier : public Courier {
public:
    BikeCourier();

    BikeCourier(const std::string &name, double rating);

    double calculateDeliveryTime(double distance) const override;

    std::string getVehicleType() const override;

    Courier *clone() const override;
};

#endif
