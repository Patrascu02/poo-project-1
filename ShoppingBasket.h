// shoppingbasket.h
#ifndef OOP_SHOPPINGBASKET_H
#define OOP_SHOPPINGBASKET_H

#include <iostream>
#include <vector>
#include "product.h"

/**
 * @class ShoppingBasket
 * @brief Class representing a shopping basket containing products
 */
class ShoppingBasket {
private:
    std::vector<Product<std::string, double>> products;

public:
    /**
     * @brief Default constructor for the ShoppingBasket class
     */
    ShoppingBasket() = default;

    /**
     * @brief Copy constructor for the ShoppingBasket class
     * @param other Another ShoppingBasket object to copy from
     */
    ShoppingBasket(const ShoppingBasket &other);

    /**
     * @brief Destructor for the ShoppingBasket class
     */
    ~ShoppingBasket() = default;



    /**
     * @brief Displays the contents of the shopping basket
     */
    void displayBasket() const;
    ShoppingBasket& operator=(const ShoppingBasket &other);

};

#endif //OOP_SHOPPINGBASKET_H
