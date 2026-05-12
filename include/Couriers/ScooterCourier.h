#ifndef SCOOTERCOURIER_H
#define SCOOTERCOURIER_H

#include "Courier.h"

class ScooterCourier : public Courier {
public:
    ScooterCourier();

    ScooterCourier(const std::string &name, double rating);

    double calculateDeliveryTime(double distance) const override;

    std::string getVehicleType() const override;

    Courier *clone() const override;
};

#endif
