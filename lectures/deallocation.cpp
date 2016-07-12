#include "grad.cpp"

int main() {
  UGrad s1("bernard",78);
  UGrad* s2 = new Grad("Billy", 67);
  std::cout << s1 << std::endl;
  std::cout << *s2 << std::endl;
  delete s2;
  return 0;
}
