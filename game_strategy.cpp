
#include <iostream>
#include <string>
using namespace std;

class GameObject {
protected:
    int id;
    string name;
    int x, y;

public:
    GameObject(int id, string name, int x, int y) : id(id), name(name), x(x), y(y) {}
    int getId() { return id; }
    string getName() { return name; }
    int getX() { return x; }
    int getY() { return y; }
};

class Unit : public GameObject {
protected:
    float hp;
    bool alive;

public:
    Unit(int id, string name, int x, int y, float hp) : GameObject(id, name, x, y), hp(hp), alive(true) {}
    bool isAlive() { return alive; }
    float getHp() { return hp; }
    void receiveDamage(float damage) {
        hp -= damage;
        if (hp <= 0) {
            hp = 0;
            alive = false;
        }
    }
};

class Attacker {
public:
    virtual void attack(Unit& unit) = 0;
};

class Moveable {
public:
    virtual void move(int newX, int newY) = 0;
};

class Archer : public Unit, public Attacker, public Moveable {
public:
    Archer(int id, string name, int x, int y, float hp) : Unit(id, name, x, y, hp) {}
    
    void attack(Unit& unit) override {
        if (isAlive()) {
            unit.receiveDamage(10.0f); 
            cout << name << " атакует " << unit.getName() << " и наносит 10 урона!" << endl;
        }
    }

    void move(int newX, int newY) override {
        if (isAlive()) {
            x = newX;
            y = newY;
            cout << name << " перемещается в (" << x << ", " << y << ")" << endl;
        }
    }
};

class Building : public GameObject {
protected:
    bool built;

public:
    Building(int id, string name, int x, int y) : GameObject(id, name, x, y), built(false) {}
    bool isBuilt() { return built; }
    void construct() { built = true; }
};

class Fort : public Building, public Attacker {
public:
    Fort(int id, string name, int x, int y) : Building(id, name, x, y) {}

    void attack(Unit& unit) override {
        if (built) {
            unit.receiveDamage(20.0f); // Наносит 20 единиц урона
            cout << name << " стреляет из пушек по " << unit.getName() << " и наносит 20 урона!" << endl;
        }
    }
};

class MobileHouse : public Building, public Moveable {
public:
    MobileHouse(int id, string name, int x, int y) : Building(id, name, x, y) {}

    void move(int newX, int newY) override {
        x = newX;
        y = newY;
        cout << name << " перемещается в (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Archer archer1(1, "Archer1", 0, 0, 100);
    Archer archer2(2, "Archer2", 1, 1, 100);

    Fort fort(3, "Fort", 5, 5);
    fort.construct();

    MobileHouse mobileHouse(4, "Mobile House", 3, 3);

    archer1.attack(archer2);
    archer2.move(2, 2);

    fort.attack(archer1);
    mobileHouse.move(6, 6);

    return 0;
}
