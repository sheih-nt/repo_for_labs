#include <iostream>
#include <string>

// Продукт
class Product {
public:
    std::string partA;
    std::string partB;
    std::string partC;

    void showProduct() const {
        std::cout << "Product Parts: " << partA << ", " << partB << ", " << partC << std::endl;
    }
};

// Интерфейс строителя
class Builder {
public:
    virtual ~Builder() {}
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual Product* getResult() = 0;
};

// Конкретный строитель
class ConcreteBuilder : public Builder {
private:
    Product* product;
public:
    ConcreteBuilder() { product = new Product(); }
    ~ConcreteBuilder() { delete product; }

    void buildPartA() override {
        product->partA = "Part A";
    }

    void buildPartB() override {
        product->partB = "Part B";
    }

    void buildPartC() override {
        product->partC = "Part C";
    }

    Product* getResult() override {
        return product;
    }
};

// Директор
class Director {
private:
    Builder* builder;
public:
    void setBuilder(Builder* newBuilder) {
        builder = newBuilder;
    }

    void construct() {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }
};

int main() {
    Director director;
    ConcreteBuilder builder;
    
    director.setBuilder(&builder);
    director.construct();

    Product* product = builder.getResult();
    product->showProduct();

    return 0;
}
