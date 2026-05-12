#include "../../include/Couriers/BikeCourier.h"

BikeCourier::BikeCourier() : Courier() {
}

BikeCourier::BikeCourier(const std::string &name, const double rating)
    : Courier(name, rating) {
}

Courier *BikeCourier::clone() const {
    return new BikeCourier(*this);
}

double BikeCourier::calculateDeliveryTime(double distance) const {
    return distance / 15.0;
}

std::string BikeCourier::getVehicleType() const {
    return "Bike";
}
