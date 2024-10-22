#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mutex_;

    // Конструктор приватный, чтобы предотвратить создание экземпляров.
    Singleton() {
        std::cout << "Singleton instance created!" << std::endl;
    }

public:
    // Запрещаем копирование и присваивание.
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something in Singleton instance!" << std::endl;
    }
};

// Инициализация статических членов
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex_;

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->doSomething();

    return 0;
}
