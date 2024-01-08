/**
 * @file Person.cpp
 * @brief Implementation of classes representing persons in a store management system.
 */

#include "../Headers/Person.h"
#include "../Headers/product.h"

/**
 * @class Person
 * @brief Represents a generic person in the store management system.
 */
Person::Person(const std::string &name) : name(name) {
    if (name.empty()) {
        throw EmptyNameException();
    }
}

Person::Person(const Person &other) : name(other.name) {}

Person &Person::operator=(const Person &other) {
    if (this != &other) {
        name = other.name;
    }
    return *this;
}

std::string Person::greeting() const {
    return std::string("Sorry ") + name +
           ", we do not recognize you as a client or an employee, please create an account! ";
}

std::string Person::getrole() const {
    return "We do not recognize you as a client or an employee, please create an account! ";
}

/**
 * @class Client
 * @brief Represents a client in the store management system.
 */
Client::Client(const std::string &name, const std::string &username, const std::string &password)
        : Person(name), username(username), password(password) {
    if (name.empty()) {
        throw EmptyNameException();
    }
}

[[maybe_unused]] Client::Client(const Client &other)
        : Person(other), shoppingBasket(other.shoppingBasket), username(other.username), password(other.password) {}

Client &Client::operator=(const Client &other) {
    if (this != &other) {
        name = other.name;
        shoppingBasket = other.shoppingBasket;
        username = other.username;
        password = other.password;
    }
    return *this;
}


std::ostream &operator<<(std::ostream &os, const Client &client) {
    os << "Name: " << client.name << "\n";
    client.shoppingBasket.displayBasket();
    return os;
}

std::string Client::getrole() const {
    return std::string("CLIENT");
}

std::string Client::greeting() const {
    return std::string("Welcome ") + name + std::string("!");
}

void Client::performAction() const {
    std::cout << std::string("Client ") + name + std::string(" is making a purchase.") << std::endl;
}

/**
 * @class site_Employee
 * @brief Represents a site employee in the store management system.
 */
site_Employee::site_Employee(const std::string &name, const std::string &site_employee_id,
                             const std::string &site_employee_password, const std::string &role)
        : Person(name), site_employee_id(site_employee_id),
          site_employee_password(site_employee_password), role(role) {
    if (name.empty()) {
        throw EmptyNameException();
    }
}

[[maybe_unused]] site_Employee::site_Employee(const site_Employee &other)
        : Person(other), site_employee_id(other.site_employee_id),
          site_employee_password(other.site_employee_password), role(other.role) {}

site_Employee &site_Employee::operator=(const site_Employee &other) {
    if (this != &other) {
        Person::operator=(other);
        site_employee_id = other.site_employee_id;
        site_employee_password = other.site_employee_password;
        role = other.role;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const site_Employee &site_employee) {
    os << "Employee: " << site_employee.name << "\n";
    os << "ID: " << site_employee.site_employee_id << "\n";
    os << "Role: " << site_employee.role << "\n";
    return os;
}

std::string site_Employee::getrole() const {
    return std::string("SITE EMPLOYEE");
}

std::string site_Employee::greeting() const {
    return std::string("Welcome ") + name + std::string("!");
}

void site_Employee::performAction() const {
    std::cout << std::string("Site employee ") + name + std::string(" is working on the site.") << std::endl;
}

/**
 * @class shop_Employee.
 * @brief Represents a shop employee in the store management system.
 */
shop_Employee::shop_Employee(const std::string &name, const std::string &shop_Employee_username,
                             const std::string &password, const std::string &shop_location)
        : Person(name), shop_Employee_username(shop_Employee_username),
          password(password), shop_location(shop_location) {
    if (name.empty()) {
        throw EmptyNameException();
    }
}

[[maybe_unused]] shop_Employee::shop_Employee(const shop_Employee &other)
        : Person(other), shop_Employee_username(other.shop_Employee_username),
          password(other.password), shop_location(other.shop_location) {}

shop_Employee &shop_Employee::operator=(const shop_Employee &other) {
    if (this != &other) {
        Person::operator=(other);
        shop_Employee_username = other.shop_Employee_username;
        password = other.password;
        shop_location = other.shop_location;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const shop_Employee &shop_employee) {
    os << "Name: " << shop_employee.name << "\n";
    os << "Shop employee username: " << shop_employee.shop_Employee_username << "\n";
    os << "Shop location: " << shop_employee.shop_location << "\n";
    return os;
}

std::string shop_Employee::getrole() const {
    return std::string("SHOP EMPLOYEE");
}

std::string shop_Employee::greeting() const {
    return std::string("Welcome ") + name + std::string("!");
}

void shop_Employee::performAction() const {
    std::cout << std::string("Shop employee ") + name +
                 std::string(" is looking for a product availability in another shop.") << std::endl;
}
