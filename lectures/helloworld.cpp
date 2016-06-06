#include <iostream>

using namespace std;

namespace CSE3150 {
  int foo(int n) {
    return n+1;
  }
}

int main() {
  cout << "Hello world!" << CSE3150::foo(10) << endl;
  return 0;
}
