#include "../../include/Couriers/DroneCourier.h"

DroneCourier::DroneCourier() : Courier() {
}

DroneCourier::DroneCourier(const std::string &name, double rating)
    : Courier(name, rating) {
}

Courier *DroneCourier::clone() const {
    return new DroneCourier(*this);
}

double DroneCourier::calculateDeliveryTime(double distance) const {
    return distance / 125.0;
}

std::string DroneCourier::getVehicleType() const {
    return "Drone";
}
