#include <iostream>
#include "Order.h"

int main() {
    std::cout << "=== QuickDeliver Simulation ===\n\n";

    // Creare obiecte de baza
    Address restaurantAddr("Bucuresti", "Victoriei", 10);
    Address deliveryAddr("Bucuresti", "Unirii", 25);

    Restaurant restaurant("BurgerHouse", restaurantAddr, 4.7);
    Courier courier("Andrei", 4.8, true);

    // Afisare initiala
    std::cout << restaurant << "\n\n";
    std::cout << courier << "\n\n";

    // Utilizare functii nefolosite previously
    std::cout << "Restaurant highly rated? " << (restaurant.isHighlyRated() ? "Yes" : "No") << "\n";
    std::cout << "City: " << restaurantAddr.getCity() << "\n\n";

    // Creare comanda
    Order order(1, restaurant, deliveryAddr, 120);

    std::cout << "Initial Order:\n";
    std::cout << order << "\n\n";

    // Aplicare discount
    std::cout << "Applying 20% discount...\n";
    order.applyDiscount(20);
    std::cout << order << "\n\n";

    // Verificare comanda scumpa
    if (order.isExpensive()) {
        std::cout << "Order is still expensive.\n\n";
    }
    else {
        std::cout << "Order is now affordable.\n\n";
    }

    // Assign courier
    if (courier.isAvailable()) {
        std::cout << "Assigning courier...\n";
        order.assignCourier(courier);
        courier.assignOrder();
    }

    std::cout << "\nAfter assigning courier:\n";
    std::cout << order << "\n\n";

    // Finalizare livrare
    std::cout << "Completing delivery...\n";
    courier.completeDelivery();

    std::cout << "\nFinal Courier Status:\n";
    std::cout << courier << "\n";

    std::cout << "\n=== Simulation Finished ===\n";

    return 0;
}