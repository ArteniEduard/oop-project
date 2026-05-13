#include "Order.h"
#include "Exceptions/InvalidPriceException.h"

int Order::nextId = 1;

Order::Order() : id(nextId++), price(0) {
}

Order::Order(const Restaurant& restaurant, const Address& deliveryAddress, const double price)
    : id(nextId++), restaurant(restaurant), deliveryAddress(deliveryAddress),
      price(price) {
    if (price < 0)
        throw InvalidPriceException();
}

Order::Order(const Order &other) = default;

Order &Order::operator=(const Order &other) {
    if (this != &other) {
        id = other.id;
        restaurant = other.restaurant;
        deliveryAddress = other.deliveryAddress;
        price = other.price;
        courier = other.courier;
    }
    return *this;
}

Order::~Order() = default;

int Order::getCreatedOrders() {
    return nextId;
}

void Order::assignCourier(const std::shared_ptr<Courier>& c) {
    if (courier) {
        // poate fac exceptie
        std::cout << "Courier already assigned" << std::endl;
    } else {
        courier = c;
        c->assignOrder();
    }
}

void Order::applyDiscount(double percent) {
    if (percent > 0 && percent <= 100) {
        price -= price * (percent / 100.0);
    }
}

Restaurant Order::getRestaurant() {
    return restaurant;
}

std::ostream &operator<<(std::ostream &out, const Order &o) {
    out << "Order ID: " << o.id << "\n"
            << o.restaurant << "\n"
            << "Delivery: " << o.deliveryAddress << "\n"
            << "Price: " << o.price;


    if (o.courier != nullptr)
        out << "\n" << *o.courier;
    else
        out << "\nCourier: Not assigned";

    return out;
}
