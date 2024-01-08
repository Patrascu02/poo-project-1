/**
 * @file person.h
 * @brief Definition of the Person, Client, site_Employee, and shop_Employee classes.
 */

#ifndef OOP_PERSON_H
#define OOP_PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include "ShoppingBasket.h"
#include "product.h"

/**
 * @class EmptyNameException
 * @brief Exception class for an empty name field.
 */
class EmptyNameException : public std::exception {
public:
    /**
     * @return Error message for an empty name field.
     */
    [[nodiscard]] const char *what() const noexcept override {
        return "You left the name section empty!!!.";
    }
};

/**
 * @class AbstractPersonException
 * @brief Exception class for attempting to instantiate an abstract person.
 */
class AbstractPersonException : public std::exception {
public:
    /**
     * @return Error message for attempting to instantiate an abstract person.
     */
    [[nodiscard]] const char *what() const noexcept override {
        return "Cannot instantiate an abstract person.";
    }
};

/**
 * @class Person
 * @brief Represents a generic person in the store management system.
 */
class Person {
private:
    std::string name;

public:
    /**
     * @brief Constructor for the Person class.
     * @param name The name of the person.
     */
    explicit Person(const std::string &name);

    /**
     * @brief Copy constructor for Person.
     * @param other The Person object to copy.
     */
    Person(const Person &other);

    /**
     * @brief Assignment operator for Person.
     * @param other The Person object to assign.
     * @return Reference to the assigned object.
     */
    Person &operator=(const Person &other);

    /**
     * @return Greeting message for the person.
     */
    [[nodiscard]] virtual std::string greeting() const;

    /**
     * @return Role of the person.
     */
    [[nodiscard]] virtual std::string getrole() const;

    /**
     * @brief Pure virtual function representing an action performed by the person.
     */
    virtual void performAction() const = 0;

    /**
     * @brief Destructor for Person.
     */
    virtual ~Person() = default;
};

/**
 * @class Client
 * @brief Represents a client in the store management system.
 */
class Client : public Person {
private:
    std::string name;
    ShoppingBasket shoppingBasket;
    std::string username;
    std::string password;
    std::vector<Product<std::string, double>> products;

public:
    /**
     * @brief Constructor for the Client class.
     * @param name The name of the client.
     * @param username The username of the client.
     * @param password The password of the client.
     */
    explicit Client(const std::string &name, const std::string &username, const std::string &password);

    /**
     * @brief Copy constructor for Client.
     * @param other The Client object to copy.
     */
    Client(const Client &other);

    /**
     * @brief Assignment operator for Client.
     * @param other The Client object to assign.
     * @return Reference to the assigned object.
     */
    Client &operator=(const Client &other);

    /**
     * @brief Adds a product to the client's shopping basket.
     * @param product The product to add to the basket.
     */
    [[maybe_unused]] void addProductToBasket(Product<std::string, double> product);

    /**
     * @brief Overloaded stream insertion operator for Client.
     * @param os The output stream.
     * @param client The Client object to display.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Client &client);

    /**
     * @return Role of the client.
     */
    [[nodiscard]] std::string getrole() const override;

    /**
     * @return Greeting message for the client.
     */
    [[nodiscard]] std::string greeting() const override;

    /**
     * @brief Performs a client-specific action.
     */
    void performAction() const override;

    /**
     * @brief Destructor for Client.
     */
    ~Client() override = default;
};

/**
 * @class site_Employee
 * @brief Represents a site employee in the store management system.
 */
class site_Employee : public Person {
private:
    std::string name;
    std::string site_employee_id;
    std::string site_employee_password;
    std::string role;

public:
    /**
     * @brief Constructor for the site_Employee class.
     * @param name The name of the site employee.
     * @param site_employee_id The ID of the site employee.
     * @param site_employee_password The password of the site employee.
     * @param role The role of the site employee.
     */
    explicit site_Employee(const std::string &name, const std::string &site_employee_id,
                           const std::string &site_employee_password, const std::string &role);

    /**
     * @brief Copy constructor for site_Employee.
     * @param other The site_Employee object to copy.
     */
    site_Employee(const site_Employee &other);

    /**
     * @brief Assignment operator for site_Employee.
     * @param other The site_Employee object to assign.
     * @return Reference to the assigned object.
     */
    site_Employee &operator=(const site_Employee &other);

    /**
     * @brief Overloaded stream insertion operator for site_Employee.
     * @param os The output stream.
     * @param site_employee The site_Employee object to display.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const site_Employee &site_employee);

    /**
     * @return Role of the site employee.
     */
    [[nodiscard]] std::string getrole() const override;

    /**
     * @return Greeting message for the site employee.
     */
    [[nodiscard]] std::string greeting() const override;

    /**
     * @brief Performs a site employee-specific action.
     */
    void performAction() const override;

    /**
     * @brief Destructor for site_Employee.
     */
    ~site_Employee() override = default;
};

/**
 * @class shop_Employee
 * @brief Represents a shop employee in the store management system.
 */
class shop_Employee : public Person {
private:
    std::string name;
    std::string shop_Employee_username;
    std::string password;
    std::string shop_location;

public:
    /**
     * @brief Constructor for the shop_Employee class.
     * @param name The name of the shop employee.
     * @param shop_Employee_username The username of the shop employee.
     * @param password The password of the shop employee.
     * @param shop_location The location of the shop where the employee works.
     */
    explicit shop_Employee(const std::string &name, const std::string &shop_Employee_username,
                           const std::string &password, const std::string &shop_location);

    /**
     * @brief Copy constructor for shop_Employee.
     * @param other The shop_Employee object to copy.
     */
    shop_Employee(const shop_Employee &other);

    /**
     * @brief Assignment operator for shop_Employee.
     * @param other The shop_Employee object to assign.
     * @return Reference to the assigned object.
     */
    shop_Employee &operator=(const shop_Employee &other);

    /**
     * @brief Overloaded stream insertion operator for shop_Employee.
     * @param os The output stream.
     * @param shop_employee The shop_Employee object to display.
     * @return Reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const shop_Employee &shop_employee);

    /**
     * @return Role of the shop employee.
     */
    [[nodiscard]] std::string getrole() const override;

    /**
     * @return Greeting message for the shop employee.
     */
    [[nodiscard]] std::string greeting() const override;

    /**
     * @brief Performs a shop employee-specific action.
     */
    void performAction() const override;

    /**
     * @brief Destructor for shop_Employee.
     */
    ~shop_Employee() override = default;
};

#endif //OOP_PERSON_H
