#include <iostream>
using namespace std;

class Hero {

private:
  char name[100];
  int health;
  int level;

public:
  int getLevel() { return level; }
  int getHealth() { return health; }

  void setHealth(int h) { health = h; }
  void setLevel(int l) { level = l; }
};

int main() {

  // dynamic allocation
  Hero *h2 = new Hero;
  cout << "size: " << sizeof(*h2) << endl;
  cout << "level: " << (*h2).getLevel() << endl;
  cout << "health: " << (*h2).getHealth() << endl;

  (*h2).setHealth(190); // or  h2->setHealth(190)
  (*h2).setLevel(790);
  cout << "level: " << (*h2).getLevel()
       << endl; // cout << "level: " << h2->getLevel() << endl;
  cout << "health: " << (*h2).getHealth() << endl;
  cout << "level: " << h2->getLevel() << endl;
}
