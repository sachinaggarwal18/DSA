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

  // static allocation
  Hero h1;
  // strcpy(h1.name, "l");
  // h1.health = 20;
  // h1.level = 10;

  // cout << "size: " << sizeof(h1) << endl;
  // cout << "name: " << h1.name << endl;
  cout << "values before setter:" << endl;
  cout << "health: " << h1.getHealth() << endl;
  cout << "level: " << h1.getLevel() << endl;

  // using setters
  h1.setLevel(300);
  h1.setHealth(100);

  cout << "values after setter:" << endl;
  cout << "health: " << h1.getHealth() << endl;
  cout << "level: " << h1.getLevel() << endl;

  Hero *h2 = new Hero;
  cout << "size: " << sizeof(*h2) << endl;
  cout << "size: " << sizeof(*h2) << endl;
}
