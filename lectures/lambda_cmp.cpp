//lambdas

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


// [] - capture nothing
// [=] - capture everything (by copy [value]) (like a functional language)
// [&] - capture everyting (by reference)
// [captureList] - only capture the entries in the list 


//    exmaple 1
/*int main() {
    auto cmp = [](int a, int b) -> int {
        if (a == b) return 0;
        else if (a < b) return -1;
        else return 1;
    };
    cout << "cmp(1,2) : " << cmp(1,2) << endl;
    return 0; 
}*/


// comparing doubles - example 2
int main() {
    double epsilon = 0.01;
    auto cmp = [&epsilon](double a, double b) -> int {
        if (fabs(a - b) <= epsilon) return 0;
        else if (a < b) return -1;
        else return 1;
    };
    cout << "cmp(1,x) : " << cmp(1,1.00001) << endl;
    epsilon = 0.0000000001;
    cout << "cmp(1,x) : " << cmp(1,1.00001) << endl;
    return 0; 
}