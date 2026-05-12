#ifndef CARCOURIER_H
#define CARCOURIER_H

#include "Courier.h"

class CarCourier : public Courier {
public:
    CarCourier();

    CarCourier(const std::string &name, double rating);

    double calculateDeliveryTime(double distance) const override;

    std::string getVehicleType() const override;

    Courier *clone() const override;
};

#endif
