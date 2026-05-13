#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <memory>

#include "Restaurant.h"
#include "Address.h"
#include "Couriers/Courier.h"

class Order {
private:
    static int nextId;
    int id;
    Restaurant restaurant;
    Address deliveryAddress;
    double price;

    std::shared_ptr<Courier> courier;

public:
    Order();

    Order(const Restaurant &restaurant, const Address &deliveryAddress, double price);

    Order(const Order &other);

    Order &operator=(const Order &other);

    ~Order();

    static int getCreatedOrders();

    void assignCourier(const std::shared_ptr<Courier> &c);

    void applyDiscount(double percent);

    Restaurant &getRestaurant();

    friend std::ostream &operator<<(std::ostream &out, const Order &o);
};

#endif
