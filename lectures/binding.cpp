#include <iostream>
#include <functional>

using namespace std;

void f(int& n1, int& n2,const int& n3) {
    cout << "In function : " << n1 << ' ' << n2 << ' ' << n3 << endl;
    ++n1;
    ++n2;
}

int main() {
    int n1 = 1, n2 = 2, n3 = 3;
    function<void()> bound_f = std::bind(f, n1, std::ref(n2), std::cref(n3));
    n1 = 10;
    n2 = 11;
    n3 = 12;
    cout << "Before function : " << n1 << ' ' << n2 << ' ' << n3 << endl;
    bound_f();
    cout << "After function(1) : " << n1 << ' ' << n2 << ' ' << n3 << endl;
    bound_f();
    cout << "After function(2) : " << n1 << ' ' << n2 << ' ' << n3 << endl;
    bound_f();
    cout << "After function(3) : " << n1 << ' ' << n2 << ' ' << n3 << endl;

}