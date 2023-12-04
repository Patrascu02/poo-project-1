//
// Created by alexp on 26/11/2023.
//

#ifndef OOP_PRODUCT_H
#define OOP_PRODUCT_H

// Clasa de excepții pentru coșul de cumpărături
class BasketException : public std::exception {
private:
    const char *message;  // Erorr message

public:
    explicit BasketException(const char *msg) : message(msg) {}


    // Overwrite function what for returning the error message
    [[nodiscard]] const char *what() const noexcept override {
        return message;
    }
};


// Exception class for invalid sport
class InvalidSportException : public std::exception {
public:
    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid sport type.";
    }
};

class Product {
private:
    std::string name;
    std::string size;
    std::string sportType;
    double price{};
    static int instanceCount;
    //Static atribute for counting objects of type Product

public:
    Product(const std::string &name, double price, const std::string &size, const std::string &sportType)
            : name(name), size(size), sportType(sportType), price(price) {
        if (price < 0) {
            throw BasketException("Price cannot be negative.");
        }
        if (sportType.empty()) {
            throw InvalidSportException();
        }
        this->price = price;
        // Incrementăm instanceCount la crearea unui nou obiect Product
        //Incrementing instanceCount when a new object of type Product is created
        instanceCount++;
    }

    Product& operator=(const Product& other) = default;
    Product(const Product &other)
           : name(other.name), size(other.size), sportType(other.sportType), price(other.price) {}

    friend std::ostream &operator<<(std::ostream &os, const Product &product) {
        os << "Product: " << product.name << ", Price: " << product.price
           << ", Size: " << product.size << ", Sport: " << product.sportType;
        return os;
    }

    // Funcție statică pentru a obține numărul curent de instanțe de Product
    static int getInstanceCount() {
        return instanceCount;
    }
};

#endif //OOP_PRODUCT_H
