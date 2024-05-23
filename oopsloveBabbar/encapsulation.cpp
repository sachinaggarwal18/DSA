#include <iostream>
using namespace std;

class Student {

private:
  string name;
  int age;
  int height;

public:
  int getAge() { return age; }
};

int main() {

  Student obj1;
  cout << obj1.getAge() << endl;
}
