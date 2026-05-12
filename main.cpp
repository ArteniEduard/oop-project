#include <iostream>
#include <memory>

#include "Order.h"
#include "Restaurant.h"
#include "Address.h"

#include "Exceptions/DeliveryException.h"

int main()
{
    Address addr("Bucharest", "Victoriei", 10);
    Restaurant r("Pizza House", addr, 4.8);
    std::unique_ptr<Order> o;

    try {
        o = std::make_unique<Order>(1, r, addr, 50);
    }
    catch (const DeliveryException& e) {
        std::cout << "Error: " << e.what() << std::endl;
        o = nullptr;
    }

    std::cout << *o;

    return 0;
}