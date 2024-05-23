#include <iostream>
#include <iterator>
using namespace std;

class Human {

public:
  string name;
  int age;
  int height;

public:
  int getAge() { return age; }
  int getHeight() { return height; }
  void setHeight(int h) { this->height = h; }
};

class Male : public Human {

public:
  int color;

  void sleep() { cout << "Human is sleeping" << endl; }
};

// int main() {

//   Male obj1;
//   obj1.setHeight(20);
//   cout << obj1.height << endl;
//   obj1.sleep();
// }

int main() {
  Male obj1;
  obj1.setHeight(20);
  cout << obj1.getHeight() << endl; // Access height through a getter function
  obj1.sleep();
}
