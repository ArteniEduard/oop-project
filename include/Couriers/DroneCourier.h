#ifndef OOP_DRONECOURIER_H
#define OOP_DRONECOURIER_H

#include "Courier.h"

class DroneCourier : public Courier {
public:
    DroneCourier();

    DroneCourier(const std::string &name, double rating);

    double calculateDeliveryTime(double distance) const override;

    std::string getVehicleType() const override;

    Courier *clone() const override;
};

#endif
