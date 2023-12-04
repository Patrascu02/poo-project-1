//
// Created by alexp on 27/11/2023.
//

#ifndef OOP_PERSON_H
#define OOP_PERSON_H

class EmptyNameException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "You left the name section empty!!!.";
    }
};

class AbstractPersonException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Cannot instantiate an abstract person.";
    }
};

class Person {
private :
    std::string name;
public :
    explicit Person(const std:: string& name) : name (name)  {
        if (name.empty()) {
            throw EmptyNameException();
        }
        this->name = name;
    }
    Person() = default;

    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }


    [[nodiscard]] virtual std::string greeting() const {return  std::string("Sorry ") + this->name + ",we do not recognise you as a client or an employee,please create an account! ";}
    [[nodiscard]] virtual std::string getrole() const {return "We do not recognise you as a client or an employee,please create an account! ";}

    // pure virtual function
    virtual void performAction() const = 0;

    virtual ~Person() = default;
};

class Client : public Person {
private:
    std::string name;
    ShoppingBasket shoppingBasket;
    std::string username;
    std::string password;

    //Static atribute for counting the total of products added in the basket by all of the clients
    static int totalItemsAdded;

public:
    explicit Client(const std::string& name,const std:: string& username,const std:: string& password) : name(name), username (username) ,password (password) {
        if (name.empty()) {
            throw EmptyNameException();
        }
        this->name = name;
    }

    Client() = default;

    Client& operator=(const Client& other) {
        if (this != &other) {
            name = other.name;
            shoppingBasket = other.shoppingBasket;
            username = other.username;
            password= other.password;
        }
        return *this;
    }

     ~Client() override = default;

    void addProductToBasket(const Product& product) {
        shoppingBasket.addProduct(product);

        //Increment totalItemsAdded when a new object is added to the basket
        totalItemsAdded++;
    }


    //Static function for obtaining the number of added objects in the basket by all clients
    static int getTotalItemsAdded() {
        return totalItemsAdded;
    }

    friend std::ostream& operator<<(std::ostream& os, const Client& client) {
        os << "Name: " << client.name << "\n";
        client.shoppingBasket.displayBasket();
        return os;
    }

    [[nodiscard]] std::string  getrole()const override {return std::string ("CLIENT");} // NOLINT(*-return-braced-init-list)
    [[nodiscard]] std::string greeting()const override{ return std::string ("Welcome ")  + this->name + std::string ("!");};
    void performAction() const override {
        std::cout <<std::string("Client ") + this->name + std::string(" is making a purchase.")<<std::endl;
    }
};


class site_Employee : public Person{

private :

std::string name;
std::string site_employee_id;
std::string site_employee_password;
std::string role;

public:

    explicit site_Employee(const std::string& name,const std:: string& site_employee_id,const std:: string& site_employee_password , const std::string& role) : name(name), site_employee_id (site_employee_id) ,site_employee_password (site_employee_password) ,role(role) {
        if (name.empty()) {
            throw EmptyNameException();
        }
        this->name = name;
    }
    site_Employee() = default;

    ~site_Employee() override=default;

    site_Employee& operator=(const site_Employee& other) {
        if (this != &other) {
            name = other.name;
            site_employee_id = other.site_employee_id;
            site_employee_password= other.site_employee_password;
            role=other.role;
        }
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const site_Employee& site_employee) {
        os << "Employee: " << site_employee.name << "\n";
        os << "ID: " << site_employee.site_employee_id << "\n";
        os << "Role: " << site_employee.role<< "\n";
        return os;
    }

    [[nodiscard]] std::string getrole()const override{return std::string ("SITE EMPLOYEE");} // NOLINT(*-return-braced-init-list)
    [[nodiscard]] std::string greeting()const override{ return std::string ("Welcome ")  + this->name + std::string("!") ;};
    void performAction() const override {
        std::cout <<std::string("Site employee ") + this->name + std::string(" is making a purchase.")<<std::endl;
    }
};

class shop_Employee : public Person
{

private :
    std :: string name;
    std :: string shop_Employee_username;
    std :: string password;
    std :: string shop_location;

public :

    explicit shop_Employee (const std :: string &name,const std :: string &shop_Employee_username ,const std :: string &password ,const std :: string &shoplocation) : name(name) , shop_Employee_username(shop_Employee_username) , password(password) ,shop_location(shoplocation) {
        if (name.empty()) {
            throw EmptyNameException();
        }
        this->name = name;
    }
    shop_Employee()=default;

    ~shop_Employee() override=default;

    shop_Employee &operator =(shop_Employee &other) // NOLINT(*-unconventional-assign-operator)
    {
        if(this != &other)
        {
            name=other.name;
            shop_Employee_username=other.shop_Employee_username;
            password=other.password;
            shop_location=other.shop_location;
        }
        return *this;
    }

    friend std:: ostream& operator << (std ::ostream& os ,const shop_Employee& shop_employee)
    {
        os <<  "Name: " << shop_employee.name <<"\n";
        os << "Shop employee username :" << shop_employee.shop_Employee_username <<"\n";
        os << "Shop location :" <<shop_employee.shop_location << "\n";
        return os;
    }

    [[nodiscard]] std::string getrole()const override{return std::string ("SHOP EMPLOYEE");} // NOLINT(*-return-braced-init-list)
    [[nodiscard]] std::string greeting()const override{ return std::string ("Welcome ")  + this->name + std::string("!") ;};
    void performAction() const override {
        std::cout <<std::string("Shop employee ") + this->name + std::string(" is making a purchase.")<<std::endl;
    }

};
#endif //OOP_PERSON_H
