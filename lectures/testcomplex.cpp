#include "complex1.h"
#include <iostream>

int main() {
    using namespace std;
    Complex c1(1,2);
    Complex c2(3,-4);
    Complex c3 = c1 + c2;
    cout << "c1: "; c1.print(cout); cout << endl;
    cout << "c2: "; c2.print(cout); cout << endl;
    cout << "c3: "; c3.print(cout); cout << endl;
}