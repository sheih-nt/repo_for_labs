#include <iostream>
#include <vector>

// Интерфейс итератора
template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual T next() = 0;
    virtual bool hasNext() const = 0;
};

// Конкретный итератор для вектора
template <typename T>
class VectorIterator : public Iterator<T> {
private:
    std::vector<T> collection;
    size_t index;
public:
    VectorIterator(const std::vector<T>& vec) : collection(vec), index(0) {}

    T next() override {
        return collection[index++];
    }

    bool hasNext() const override {
        return index < collection.size();
    }
};

// Коллекция с итератором
template <typename T>
class IterableCollection {
private:
    std::vector<T> collection;
public:
    void addItem(const T& item) {
        collection.push_back(item);
    }

    Iterator<T>* createIterator() const {
        return new VectorIterator<T>(collection);
    }
};

int main() {
    IterableCollection<int> numbers;
    numbers.addItem(1);
    numbers.addItem(2);
    numbers.addItem(3);

    Iterator<int>* iterator = numbers.createIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << std::endl;
    }

    delete iterator;

    return 0;
}
