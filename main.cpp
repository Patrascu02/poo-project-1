/**
 * @file main.cpp
 * @brief Entry point of the program, demonstrating an object-oriented store management system.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include "ShoppingBasket.h"
#include "product.h"
#include "Person.h"



/**
 * @brief Function to find a product in a vector based on its ID
 * @param ID ID of the product to find
 * @param products Vector of pointers to Product objects
 * @return Pointer to the found product or nullptr if not found
 */
template<typename T, typename P>
const Product<T, P>* verificare([[maybe_unused]] const std::string& ID, [[maybe_unused]] const std::vector<Product<T, P>*>& products) {
    for (const auto& product : products) {
        if (ID == product->GetID()) {
            return product;
        }
    }
    return nullptr;
}


void clientMenu(const Client* client, ShoppingBasket& basket, const std::vector<Product<std::string, double>*>& products) {
    int choice;
    do {
        std::cout << "\nChoose an action for the client:\n";
        std::cout << "1. Add product to basket\n";
        std::cout << "2. I finished shopping.\n";
        std::cin >> choice;
        std::string ID, NaMe, SIZE, SPORTtype;
        double PRICE;
        switch (choice) {
            case 1:
                for(const  Product<std::string,double>* product : products) {
                    std::cout << *product << std::endl;
                }
                client->performAction();
                std::cout << "ID:"; std::cin >> ID;
                std::cout << "Name:"; std::cin >> NaMe;
                std::cout << "PRICE:"; std::cin >> PRICE;
                std::cout << "SIZE:"; std::cin >> SIZE;
                std::cout << "SPORT:"; std::cin >> SPORTtype;
                basket.addProduct(Product<std::string, double>(ID, NaMe, PRICE, SIZE, SPORTtype));
                basket.displayBasket();
                break;
            case 2:
                std::cout << "Have a great day\n";
                break;
        }
    } while (choice != 2);
}

void siteEmployeeMenu(const site_Employee* siteEmployee, std::vector<Product<std::string, double>*>& products) {
    int choice;
    do {
        // Displaying menu for site employee actions
        std::string ID, NaMe, SIZE, SPORTtype;
        double PRICE;
        int number;
        int i;
        const Product<std::string, double>* foundProduct;
        std::cout << "Choose an action for the site employee:\n";
        std::cout << "1. Work on the site problems\n";
        std::cout << "2. Remove a product that isn't available until restocking the shop\n";
        std::cout << "3. Apply price reductions to all products\n";
        std::cout << "4. Add new products.\n";
        std::cout << "5. I finished maintenance.\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                siteEmployee->performAction();
                break;
            case 2:
                // Displaying available products and prompting for user input

                for(const  Product<std::string,double>* product : products)
                {
                    std::cout << *product << std::endl;
                }
                std::cout<<"Product's id  that isn't available anymore:";
                std::cin >> ID;
                foundProduct = verificare(ID, products);
                if (foundProduct != nullptr) {
                    products.erase(std::remove(products.begin(),products.end(),foundProduct));
                    Product<std::string, double>::decreaseInstanceCount();

                } else {
                    std::cout << "No matching ID's\n";
                }
                break;
            case 3:
                // Displaying available products and prompting for user input

                for(const  Product<std::string,double>* product : products)
                {
                    std::cout << *product << std::endl;
                }
                double discountPercentage;
                std::cout << "Reduction percentage for all products: ";
                std::cin >> discountPercentage;

                Product<std::string, double>::applyDiscountToAll(discountPercentage, products);

                break;
            case 4:
                // Displaying available products and prompting for user input

                for(const  Product<std::string,double>* product : products)
                {
                    std::cout << *product << std::endl;
                }
                std::cout<<"How many products you want to add?";
                std::cin >> number;
                for(i=1;i<=number;i++)
                {
                    std :: cout <<"ID:";std::cin>>ID;
                    std :: cout <<"PRODUCT:";std::cin>>NaMe;
                    std :: cout <<"PRICE:";std::cin>>PRICE;
                    std :: cout <<"SIZE:";std::cin>>SIZE;
                    std :: cout <<"SPORT:";std::cin>>SPORTtype;
                    products.push_back(new Product(ID,NaMe,PRICE,SIZE,SPORTtype));
                }
                break;
            case 5:
                std::cout << "Thanks for helping us!\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 5);
}

void shopEmployeeMenu(const shop_Employee *shopEmployee) {
    int choice;
    do {
        // Displaying menu for shop employee actions

        std::cout << "Choose an action for the shop employee:\n";
        std::cout << "1. Perform shop employee-specific action\n";
        std::cout << "2. I finished looking for a product availability.\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                shopEmployee->performAction();
                break;
            case 2:
                std::cout << "Have a nice day!\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 2);
}
/**
 * @brief Main function demonstrating the store management system
 * @return Exit code
 */
int main() {


    ShoppingBasket basket;

    std::vector<Product<std::string, double>*> products;

    products.push_back(new Product<std::string, double>(ProductFactory<std::string, double>::createTShirt()));
    products.push_back(new Product<std::string, double>(ProductFactory<std::string, double>::createShorts()));
    products.push_back(new Product<std::string, double>(ProductFactory<std::string, double>::createBoxers()));
    products.push_back(new Product<std::string, double>(ProductFactory<std::string, double>::createTee()));
    products.push_back(new Product<std::string, double>(ProductFactory<std::string, double>::createFootballShoes()));
    products.push_back(new Product<std::string, double>(ProductFactory<std::string, double>::createBasketballShoes()));



    // Creating an instance of a Person (base class)
    std::vector<Person *> people;

    people.push_back(new Client("Banea Mario", "bmario123", "pa123"));
    people.push_back(new site_Employee("Danciu Alice", "alice001", "456", "Web Development"));
    people.push_back(new shop_Employee("Badea Elena", "ele007", "p123789", "Megamall"));

    int roleChoice;
    do {
        std::cout << "Choose a role (1 for Client, 2 for Site Employee, 3 for Shop Employee, 0 to Exit): ";
        std::cin >> roleChoice;

        switch (roleChoice) {
            case 1: {
                const Client* client = dynamic_cast<const Client*>(people[0]);  // Assume the first person is a client
                clientMenu(client, basket, products);
                break;
            }
            case 2: {
                const site_Employee* siteEmployee = dynamic_cast<const site_Employee*>(people[1]);  // Assume the second person is a site employee
                siteEmployeeMenu(siteEmployee, products);
                break;
            }
            case 3: {
                const shop_Employee* shopEmployee = dynamic_cast<const shop_Employee*>(people[2]);  // Assume the third person is a shop employee
                shopEmployeeMenu(shopEmployee);
                break;
            }
            case 0:
                // Exit the program
                break;
        }

    } while (roleChoice != 0);
    // Deleting allocated memory for dynamically created objects

    for (const auto* const person: people) {
        delete person;
    }
    for (const auto* const product : products) {
        delete product;
    }

    std::cout << "--------------------------------------------" << std::endl;
    // Displaying the total number of items added by all clients
    std::cout << "Total items in the shop: " << Product<std::string, double>::getInstanceCount() << "\n";

    std::cout << "--------------------------------------------" << std::endl;

    try {
        // Example of creating a product with a negative price
        Product<std::string, double> invalidPriceProduct("111", "Invalid Price Product", -10.0, "M", "InvalidSport");
    } catch (const std::exception &ex) {
        // Handling the exception if product creation fails
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }

    try {
        // Example of creating a product with an invalid sport type
        Product<std::string, double> invalidSportProduct("112op", "Invalid Sport Product", 20.0, "L", "");
    } catch (const std::exception &ex) {
        // Handling the exception if product creation fails
        std::cerr << "Exception caught: " << ex.what() << '\n';
    }
    // Handling exceptions during client creation.

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

