#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <ctime>

#include "Order.h"
#include "Couriers/DroneCourier.h"
#include "include/Couriers/BikeCourier.h"
#include "include/Couriers/CarCourier.h"
#include "include/Couriers/ScooterCourier.h"

double randomDistance() {
    return 1 + rand() % 20;
}

std::shared_ptr<Courier>
findBestCourier(const std::vector<std::shared_ptr<Courier> > &couriers, const double distance) {
    std::shared_ptr<Courier> bestCourier = nullptr;
    double bestScore = std::numeric_limits<double>::max();

    for (const auto &courier: couriers) {
        if (!courier->isAvailable())
            continue;

        double estimatedTime = courier.get()->calculateDeliveryTime(distance);

        //TODO de adaugat in ecuatie rating-ul curierului

        if (estimatedTime < bestScore) {
            bestScore = estimatedTime;
            bestCourier = courier;
        }
    }


    return bestCourier;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // ADDRESSES

    const auto a1 = std::make_shared<Address>(
        "Bucuresti", "Victoriei", 10);

    const auto a2 = std::make_shared<Address>(
        "Bucuresti", "Lizeanu", 22);

    const auto a3 = std::make_shared<Address>(
        "Bucuresti", "Mosilor", 15);

    const auto a4 = std::make_shared<Address>(
        "Bucuresti", "Unirii", 99);

    // RESTAURANTS

    const std::vector restaurants = {

        std::make_shared<Restaurant>(
            "Pizza Napoli",
            *a1,
            4.8
        ),

        std::make_shared<Restaurant>(
            "Burger House",
            *a2,
            4.3
        ),

        std::make_shared<Restaurant>(
            "Sushi Master",
            *a3,
            4.9
        )
    };

    // COURIERS

    const std::vector<std::shared_ptr<Courier> > couriers = {

        std::make_shared<BikeCourier>(
            "Ion",
            4.9
        ),

        std::make_shared<ScooterCourier>(
            "Andrei",
            4.7
        ),

        std::make_shared<CarCourier>(
            "Mihai",
            4.5
        ),

        std::make_shared<BikeCourier>(
            "Cristi",
            4.6
        ),

        std::make_shared<DroneCourier>(
            "Drone",
            5.0
        )
    };

    // ORDERS

    std::vector<std::shared_ptr<Order> > orders;

    orders.push_back(
        std::make_shared<Order>(
            *restaurants[0],
            *a4,
            75
        )
    );

    orders.push_back(
        std::make_shared<Order>(
            *restaurants[1],
            *a3,
            120
        )
    );

    orders.push_back(
        std::make_shared<Order>(
            *restaurants[2],
            *a2,
            150
        )
    );

    // ASSIGN COURIERS

    for (auto &order: orders) {
        double distance = randomDistance();

        std::cout << "\n=============================\n";
        std::cout << "Processing order:\n";
        std::cout << *order << "\n";

        std::cout << "Distance: "
                << distance
                << " km\n";

        const std::shared_ptr<Courier> bestCourier =
                findBestCourier(couriers, distance);

        if (bestCourier) {
            order->assignCourier(bestCourier);
            std::cout << "\nAssigned courier:\n";
            std::cout << *bestCourier << "\n";
        } else {
            std::cout
                    << "\nNo available courier!\n";
        }
    }

    std::cout << "\n=============================\n";
    std::cout << "\nFINAL STATE:\n";

    for (const auto &order: orders) {
        std::cout << "\n-------------------\n";
        if (order->getRestaurant().isHighlyRated()) {
            order->applyDiscount(10);
        }
        std::cout << *order << "\n";
    }
    std::cout << "\n-------------------\n";

    int completedDeliveries = 0;
    for (const auto &courier: couriers) {
        courier->completeDelivery();
        completedDeliveries++;
    }

    if (completedDeliveries == Order::getCreatedOrders()) {
        std::cout << "\nAll couriers have been completed!\n";
    }else {

    }


    return 0;
}
