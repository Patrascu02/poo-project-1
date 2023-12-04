//
// Created by alexp on 27/11/2023.
//

#ifndef OOP_SHOPPINGBASKET_H
#define OOP_SHOPPINGBASKET_H

class ShoppingBasket {
private:
    std::vector<Product> products;

public:
    ShoppingBasket() = default;

    ShoppingBasket& operator=(const ShoppingBasket& other) {
        if (this != &other) {
            products = other.products;
        }
        return *this;
    }

    ~ShoppingBasket() = default;

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void displayBasket() const {
        std::cout << "Shopping basket:\n";
        for (const Product& product : products) {
            std::cout << "  -" << product << "\n";
        }
    }
};

#endif //OOP_SHOPPINGBASKET_H
