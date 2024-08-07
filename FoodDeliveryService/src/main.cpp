#include <iostream>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "Order.h"

int main() {
    User user1(1, "John Doe", "john@example.com", "123 Main St", "Credit Card");

    Restaurant restaurant1(1, "Pizza Place", "456 Elm St");
    MenuItem item1(1, "Margherita Pizza", 8.99);
    MenuItem item2(2, "Pepperoni Pizza", 9.99);
    restaurant1.addMenuItem(item1);
    restaurant1.addMenuItem(item2);

    std::vector<MenuItem> orderItems = { item1, item2 };
    Order order1(1, user1.getUserId(), restaurant1.getRestaurantId(), orderItems, "Pending");

    std::cout << "Order Details:" << std::endl;
    std::cout << "User: " << user1.getName() << std::endl;
    std::cout << "Restaurant: " << restaurant1.getName() << std::endl;
    std::cout << "Items:" << std::endl;
    for (const auto& item : order1.getItems()) {
        std::cout << "- " << item.getName() << " ($" << item.getPrice() << ")" << std::endl;
    }
    std::cout << "Status: " << order1.getStatus() << std::endl;

    return 0;
}
