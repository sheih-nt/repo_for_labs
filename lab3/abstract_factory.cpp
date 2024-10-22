#include <iostream>

// Интерфейсы продуктов
class AbstractProductA {
public:
    virtual ~AbstractProductA() {}
    virtual void useProductA() const = 0;
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() {}
    virtual void useProductB() const = 0;
};

// Конкретные продукты
class ConcreteProductA1 : public AbstractProductA {
public:
    void useProductA() const override {
        std::cout << "Using Product A1" << std::endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void useProductA() const override {
        std::cout << "Using Product A2" << std::endl;
    }
};

class ConcreteProductB1 : public AbstractProductB {
public:
    void useProductB() const override {
        std::cout << "Using Product B1" << std::endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    void useProductB() const override {
        std::cout << "Using Product B2" << std::endl;
    }
};

// Интерфейс абстрактной фабрики
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};

// Конкретные фабрики
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB2();
    }
};

// Клиентский код
void clientCode(const AbstractFactory& factory) {
    AbstractProductA* productA = factory.createProductA();
    AbstractProductB* productB = factory.createProductB();
    productA->useProductA();
    productB->useProductB();
    delete productA;
    delete productB;
}

int main() {
    std::cout << "Client: Using ConcreteFactory1\n";
    ConcreteFactory1 factory1;
    clientCode(factory1);

    std::cout << "\nClient: Using ConcreteFactory2\n";
    ConcreteFactory2 factory2;
    clientCode(factory2);

    return 0;
}
