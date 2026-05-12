#include "../../include/Couriers/CarCourier.h"

CarCourier::CarCourier() : Courier() {
}

CarCourier::CarCourier(const std::string &name, const double rating)
    : Courier(name, rating) {
}

Courier *CarCourier::clone() const {
    return new CarCourier(*this);
}

double CarCourier::calculateDeliveryTime(double distance) const {
    return distance / 40.0;
}

std::string CarCourier::getVehicleType() const {
    return "Car";
}
