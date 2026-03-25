#include "Order.h"

Order::Order() : id(0), restaurant(), deliveryAddress(), price(0), courier(), hasCourier(false) {}

Order::Order(int id, Restaurant restaurant, Address deliveryAddress, double price)
    : id(id), restaurant(restaurant), deliveryAddress(deliveryAddress),
    price(price), courier(), hasCourier(false) {
}

Order::Order(const Order& other)
    : id(other.id), restaurant(other.restaurant),
    deliveryAddress(other.deliveryAddress), price(other.price),
    courier(other.courier), hasCourier(other.hasCourier) {
}

Order& Order::operator=(const Order& other) {
    if (this != &other) {
        id = other.id;
        restaurant = other.restaurant;
        deliveryAddress = other.deliveryAddress;
        price = other.price;
        courier = other.courier;
        hasCourier = other.hasCourier;
    }
    return *this;
}

Order::~Order() {}

void Order::assignCourier(const Courier& c) {
    courier = c;
    hasCourier = true;
}

void Order::applyDiscount(double percent) {
    if (percent > 0 && percent <= 100) {
        price -= price * (percent / 100.0);
    }
}

bool Order::isExpensive() const {
    return price > 100;
}

std::ostream& operator<<(std::ostream& out, const Order& o) {
    out << "Order ID: " << o.id << "\n"
        << o.restaurant << "\n"
        << "Delivery: " << o.deliveryAddress << "\n"
        << "Price: " << o.price;

    if (o.hasCourier)
        out << "\n" << o.courier;
    else
        out << "\nCourier: Not assigned";

    return out;
}