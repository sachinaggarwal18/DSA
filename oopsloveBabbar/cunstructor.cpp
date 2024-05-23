#include <iostream>
using namespace std;

class Hero {

private:
  int health;
  int level;

public:
  // constructor
  // Hero() { cout << "this is a constructor " << endl; }

  // // parametrised constructor
  // Hero(int health) { this->health = health; }

  Hero(int health, int level) {
    this->health = health;
    this->level = level;
  }

  // user-defined  copy constructor
  Hero(Hero &temp) {
    this->health = temp.health;
    this->level = temp.level;
  }

  int getLevel() { return level; }
  int getHealth() { return health; }

  void setHealth(int h) { health = h; }
  void setLevel(int l) { level = l; }
};

int main() {
  Hero h1(30, 20);

  cout << h1.getHealth() << endl;
  cout << h1.getLevel() << endl;

  // copy constructor
  Hero h2(h1);
  cout << h2.getHealth() << endl;
  cout << h2.getLevel() << endl;
}
