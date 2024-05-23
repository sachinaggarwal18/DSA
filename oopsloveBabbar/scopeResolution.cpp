// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class A {
public:
  void func() { cout << "A" << endl; }
};
class B {
public:
  void func() { cout << "B" << endl; }
};

class C : public A, public B {
public:
  void func1() { cout << "C" << endl; }
};

int main() {
  // Write C++ code here
  C obj;
  // obj.func();
  obj.A::func();
  obj.B::func();

  return 0;
}
