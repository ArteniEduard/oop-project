#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include "Restaurant.h"
#include "Address.h"
#include "Courier.h"

class Order {
private:
    int id;
    Restaurant restaurant;
    Address deliveryAddress;
    double price;

    Courier courier;
    bool hasCourier;

public:
    Order();
    Order(int id, Restaurant restaurant, Address deliveryAddress, double price);
    Order(const Order& other);
    Order& operator=(const Order& other);
    ~Order();

    void assignCourier(const Courier& c);
    void applyDiscount(double percent);
    bool isExpensive() const;

    friend std::ostream& operator<<(std::ostream& out, const Order& o);
};

#endif