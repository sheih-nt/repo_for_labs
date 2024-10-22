#include <iostream>

// Интерфейс продукта
class Product {
public:
    virtual ~Product() {}
    virtual void useProduct() const = 0;
};

// Конкретные продукты
class ConcreteProductA : public Product {
public:
    void useProduct() const override {
        std::cout << "Using Product A" << std::endl;
    }
};

class ConcreteProductB : public Product {
public:
    void useProduct() const override {
        std::cout << "Using Product B" << std::endl;
    }
};

// Интерфейс создателя
class Creator {
public:
    virtual ~Creator() {}
    virtual Product* factoryMethod() const = 0;
    void someOperation() const {
        Product* product = this->factoryMethod();
        product->useProduct();
        delete product;
    }
};

// Конкретные создатели
class ConcreteCreatorA : public Creator {
public:
    Product* factoryMethod() const override {
        return new ConcreteProductA();
    }
};

class ConcreteCreatorB : public Creator {
public:
    Product* factoryMethod() const override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creatorA = new ConcreteCreatorA();
    creatorA->someOperation();

    Creator* creatorB = new ConcreteCreatorB();
    creatorB->someOperation();

    delete creatorA;
    delete creatorB;

    return 0;
}
