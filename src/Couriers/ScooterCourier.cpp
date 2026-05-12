#include "../../include/Couriers/ScooterCourier.h"

ScooterCourier::ScooterCourier() : Courier() {
}

ScooterCourier::ScooterCourier(const std::string &name, double rating)
    : Courier(name, rating) {
}

Courier *ScooterCourier::clone() const {
    return new ScooterCourier(*this);
}

double ScooterCourier::calculateDeliveryTime(double distance) const {
    return distance / 25.0;
}

std::string ScooterCourier::getVehicleType() const {
    return "Scooter";
}
