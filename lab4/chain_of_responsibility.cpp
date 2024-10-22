#include <iostream>
#include <string>

// Интерфейс обработчика
class Handler {
protected:
    Handler* next;
public:
    Handler() : next(nullptr) {}
    virtual ~Handler() {}

    void setNext(Handler* nextHandler) {
        next = nextHandler;
    }

    virtual void handleRequest(const std::string& request) {
        if (next) {
            next->handleRequest(request);
        }
    }
};

// Конкретные обработчики
class ConcreteHandlerA : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "Handler A processed the request." << std::endl;
        } else {
            std::cout << "Handler A passed the request." << std::endl;
            Handler::handleRequest(request);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "Handler B processed the request." << std::endl;
        } else {
            std::cout << "Handler B passed the request." << std::endl;
            Handler::handleRequest(request);
        }
    }
};

int main() {
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;

    handlerA.setNext(&handlerB);

    std::cout << "Sending request A:" << std::endl;
    handlerA.handleRequest("A");

    std::cout << "\nSending request B:" << std::endl;
    handlerA.handleRequest("B");

    std::cout << "\nSending request C:" << std::endl;
    handlerA.handleRequest("C");

    return 0;
}
