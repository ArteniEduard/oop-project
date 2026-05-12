#include <iostream>
#include <vector>

#include "Order.h"
#include "include/Couriers/BikeCourier.h"
#include "include/Couriers/CarCourier.h"
#include "include/Couriers/ScooterCourier.h"

int main() {

    Address* address = new Address("Bucuresti", "Pache Protopopescu", 1);
    Address* address2 = new Address("Bucuresti", "Lizeanu", 13);
    std::cout << *address << std::endl;
    std::cout << *address2 << std::endl;

    Courier* courier = new BikeCourier("Panjeet", 4.95);
    std::cout << *courier << std::endl;

    Restaurant* restaurant = new Restaurant("Cuptorul cu lemne", *address, 4.5);
    std::cout << *restaurant<< std::endl;

    Order* order = new Order(*restaurant, *address2, 100);
    std::cout << *order << std::endl;

    order->assignCourier(courier);
    std::cout << *order << std::endl;
    std::cout << *courier << std::endl;
    return 0;
}