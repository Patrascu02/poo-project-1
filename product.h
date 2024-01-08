/**
 * @file product.h
 * @brief Definition of the Product class and associated exception classes
 */
#ifndef OOP_PRODUCT_H
#define OOP_PRODUCT_H

/**
 * @class BasketException
 * @brief Exception class for shopping basket-related errors
 */
class BasketException : public std::exception {
private:
    const char *message;  // Erorr message

public:
    explicit BasketException(const char *msg) : message(msg) {}


    /**
     * @brief Returns the error message associated with the exception
     */
    [[nodiscard]] const char *what() const noexcept override {
        return message;
    }

};


/**
 * @class InvalidSportException
 * @brief Exception class for invalid sport type
 */
class InvalidSportException : public std::exception {
public:
    /**
     * @brief Returns a predefined message for an invalid sport type
     */
    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid sport type.";
    }
};

/**
 * @class Product
 * @brief Class representing a product available in the store
 */
template<typename T , typename P>
class Product {
private:
    const T id;
    const T name;
    const T size;
    const T sportType;
    P price;
    static int instanceCount;
    //Static atribute for counting objects of type Product

public:
    /**
     * @brief Constructor for the Product class
     * @param id Product ID
     * @param name Product name
     * @param price Product price
     * @param size Product size
     * @param sportType Sport type associated with the product
     * @throw BasketException if the product price is negative
     * @throw InvalidSportException if the sport type is empty
     */
    Product(const T &id,const T &name,const P price, const T &size, const T &sportType)
            : id(id),name(name),  price(price),size(size), sportType(sportType){

        if (price < 0) {
            throw BasketException("Price cannot be negative.");
        }
        if (sportType.empty()) {
            throw InvalidSportException();
        }
        this->price = price;
        //Incrementing instanceCount when a new object of type Product is created
        instanceCount++;
    }
    /**
     * @brief Assignment operator override
     */
    Product<T, P>& operator=(const Product<T, P> & other) {
        if (this != &other) {
            this->price = other.price;
        }
        return *this;
    }
    /**
    * @brief Copy constructor for the Product class
    */
    Product(const Product &other)
            :id(id) ,name(other.name), size(other.size), sportType(other.sportType), price(other.price) {}
    /**
     * @brief Output stream operator override
     */
    friend std::ostream &operator<<(std::ostream &os, const Product &product) {
        os << "Product: " << product.name <<", Id:" <<product.id<< ", Price: " << product.price
           << ", Size: " << product.size << ", Sport: " << product.sportType;
        return os;
    }
    /**
     * @brief Returns the ID of the product
     */
    const T GetID() const {return id;}

    /**
     * @brief Returns the price of the product
     */
    const P GetPrice() const {return price;}

    /**
    * @brief Sets the price of the product
    * @param p New price of the product
    */
    void SetPrice(double const p)
    {
        price = p;
    }
/**
     * @brief Applies a discount to the price of all products
     * @param discountPercentage The discount percentage
     * @param products Vector of products
     */
    static void applyDiscountToAll(double discountPercentage, std::vector<Product<T, P>*>& products) {
        for (auto& product : products) {
            double discountedPrice = product->GetPrice() * (1.0 - discountPercentage / 100.0);
            product->SetPrice(discountedPrice);
        }

    }


    /**
    * @brief Returns the current number of instances of Product
    */
    [[maybe_unused]] static int getInstanceCount() {
        return instanceCount;
    }
   static void decreaseInstanceCount() {
        if (instanceCount > 0) {
            instanceCount--;
        }
    }
};

// Counter for the total number of Product instances
template <typename T, typename P>
int Product<T, P>::instanceCount = 0;

template<typename T, typename P>
class ProductFactory {
public:
    static Product<T, P> createTShirt() {
        return Product<T, P>("122lk", "T-shirt", 129, "M", "Gym");
    }

    static Product<T, P> createShorts() {
        return Product<T, P>("122l", "Shorts", 129, "L", "Gym");
    }

    static Product<T, P> createBoxers() {
        return Product<T, P>("123k", "Boxers", 19, "M", "Running");
    }
};

#endif //OOP_PRODUCT_H