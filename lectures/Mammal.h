#include <iostream>

class Mammal {
 public:
  Mammal() {}
  void print() {std::cout << "I (" << this << ")', a mammal!" << std::endl; }
};

class Human :public Mammal {
 public:
  Human() {}
  void print() { std::cout << "I (" << this << ")'m a human!" << std::endl; }
};

void foo(Mammal& m) {
  std::cout << "in foo! message:";
  m.print();
}
