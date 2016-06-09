#include <iostream>

using namespace std;

template<typename T>
T mymax(T a, T b) {
    return a > b ? a : b;
}

/*int main() {
    int x = 3;
    in y = mymax(3,5);
    cout << "ans: " << y << endl;
    return 0;
}*/


int main() {
    int x = 3;
    int y = mymax<int>(3,5);
    double w = mymax<double>(3.14,5.25);
    cout << "ans: " << y << endl;
    cout << "ans: " << w << endl;
    return 0;
}