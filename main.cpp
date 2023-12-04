#include <iostream>
#include <string>
#include <vector>
// For std::exception
#include "product.h"
#include "ShoppingBasket.h"
#include "Person.h"

// Counter for the total number of Product instances
int Product::instanceCount = 0;

// Counter for the total number of items added by all clients
int Client::totalItemsAdded = 0;

int main() {
    // Creating instances of products
    Product product1("Football", 50.0, "L", "Football");
    Product product2("Sports shirt", 25.0, "M", "Fitness");
    Product product3("Tennis racket", 120.0, "M", "Tennis");
    Product product4("Boxing gloves", 35.0, "M", "Boxing");
    Product product5("Shorts", 15.0, "S", "Fitness");

    // Vector to store instances of clients
    std::vector<Client> clients;

    std::cout << "--------------------------------------------" << std::endl;
    // Displaying the total number of Product instances created
    std::cout << "Total Product instances: " << Product::getInstanceCount() << "\n";
    std::cout << "--------------------------------------------" << std::endl;

    // Creating instances of clients and adding products to their baskets
    Client client1("Ionescu Mihnea", "mihus22", "mihu234");
    client1.addProductToBasket(Product("Football", 50.0, "L", "Football"));
    client1.addProductToBasket(Product("Tennis racket", 120.0, "M", "Tennis"));
    client1.addProductToBasket(Product("Boxing gloves", 35.0, "M", "Boxing"));
    clients.push_back(client1);

    Client client2("Vlad Raluca", "raluca09", "2341");
    client2.addProductToBasket(Product("Sports shirt", 25.0, "M", "Fitness"));
    client2.addProductToBasket(Product("Boxing gloves", 35.0, "M", "Boxing"));
    clients.push_back(client2);

    Client client3("Patrascu Alexandru", "patrascu02", "121212");
    client3.addProductToBasket(Product("Football", 50.0, "L", "Football"));
    client3.addProductToBasket(Product("Shorts", 15.0, "S", "Fitness"));
    clients.push_back(client3);

    // Displaying information about each client
    for (const auto &client: clients) {
        std::cout << client.getrole() << std::endl << std::endl;
        std::cout << client.greeting() << std::endl;
        std::cout << "Information about the client" << ":\n";
        std::cout << client;
        client.performAction();
        std::cout << "------------------------------" << std::endl;
    }

    std::vector<site_Employee> site_employees;

    site_Employee s_e1("Popa Andrei", "123J", "3377k>..", "Website design");
    site_employees.push_back(s_e1);

    site_Employee s_e2("Trestioreanu Marius", "2334kl", "76:'[.,", "Website mentenance");
    site_employees.push_back(s_e2);

    site_Employee s_e3("Cristina Mihaela", "332Lo", "123789[]", "Website mentenance");
    site_employees.push_back(s_e3);

    for (const auto &site_employee: site_employees) {
        std::cout << site_employee.getrole() << std::endl << std::endl;
        std::cout << site_employee.greeting() << std::endl;
        std::cout << "Information about the site employee" << ":\n";
        std::cout << site_employee << std::endl;
        site_employee.performAction();
        std::cout << "------------------------------" << std::endl;
    }

    std::vector<shop_Employee> shop_employees;

    shop_Employee e1("Calin Mario", "Calin12", "12debdch", "Baneasa mall");
    shop_employees.push_back(e1);

    shop_Employee e2("Neagu Andrei", "Andrei76", "jedwd6dby6w", "AFI mall");
    shop_employees.push_back(e2);

    shop_Employee e3("Stancu Matei", "STancu", "1;[;dk", "Plaza Bucuresti mall");
    shop_employees.push_back(e3);

    for (const auto &shop_employee: shop_employees) {
        std::cout << shop_employee.getrole() << std::endl << std::endl;
        std::cout << shop_employee.greeting() << std::endl;
        std::cout << shop_employee << std::endl;
        shop_employee.performAction();
        std::cout << "------------------------------" << std::endl;
    }

    // Creating an instance of a Person (base class)
    std::vector<Person *> people;

    people.push_back(new Client("Banea Mario", "bmario123", "pa123"));
    people.push_back(new site_Employee("Danciu Alice", "alice001", "456", "Web Development"));
    people.push_back(new shop_Employee("Badea Elena", "ele007", "p123789", "Megamall"));


    for (const auto &person: people) {
        person->performAction();
    }

    for (const auto &person: people) {
        delete person;
    }

    std::cout << "--------------------------------------------" << std::endl;
    // Displaying the total number of items added by all clients
    std::cout << "Total items added by all clients today: " << Client::getTotalItemsAdded() << "\n";
    std::cout << "--------------------------------------------" << std::endl;

    try {
        // Example of creating a product with a negative price
        Product invalidPriceProduct("Invalid Price Product", -10.0, "M", "InvalidSport");
    } catch (const std::exception &ex) {
        // Handling the exception if product creation fails
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

    try {
        // Example of creating a product with an invalid sport type
        Product invalidSportProduct("Invalid Sport Product", 20.0, "L", "");
    } catch (const std::exception &ex) {
        // Handling the exception if product creation fails
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

    try {
        Client client("", "m123", "00000123");
        client.performAction();
    } catch (const EmptyNameException &ex) {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    } catch (const AbstractPersonException &ex) {
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

    return 0;
}
