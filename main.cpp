#include <iostream>
#include <memory>
#include <vector>

#include "Order.h"
#include "include/Couriers/BikeCourier.h"
#include "include/Couriers/CarCourier.h"
#include "include/Couriers/ScooterCourier.h"

int main() {
    auto address = std::make_shared<Address>(
        "Bucuresti",
        "Pache Protopopescu",
        1
    );

    auto address2 = std::make_shared<Address>(
        "Bucuresti",
        "Lizeanu",
        13
    );

    auto courier = std::make_shared<BikeCourier>(
        "Panjeet",
        4.95
    );

    auto restaurant = std::make_shared<Restaurant>(
        "Cuptorul cu lemne",
        *address,
        4.5
    );

    auto order = std::make_shared<Order>(
        *restaurant,
        *address2,
        100
    );

    order->assignCourier(courier);

    std::cout << *order << std::endl;

    return 0;
}
