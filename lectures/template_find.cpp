// template_find
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

const double epsilon = 0.01;

// works for doubles, to make find work for other values would need to 
// change compare.
int compare(const double& x, const double& y) {
    double v = fabs(x - y);
    if(v < epsilon) {
        return 0;       // a and b are equal
    } else if(x < y) {
        return -1;      // x < y
    } else {
        return 1; // x > y
    }
}

// with template - now we pass the compare funciton to the template
// instead of an argument it is a template parameter
template<class T, int (*cmp)(const T&, const T&)>
bool myfind(const vector<T>& x, const T& v) {
        int low = 0, up = x.size() - 1;
    while(low <= up) {
        int mid = (low + up) / 2;
        const int c = cmp(v,x[mid]);
        if(c == 0) { return true; }
        else if(c < 0) { up = mid - 1; }
        else { low = mid + 1; }
    }
    return false;
}

int main() {
    vector<double> x =  {1, 5.0/3.0, 8, 11, 25, 30, 32, 47, 78, 99, 101};
    bool foundIt = myfind<double, compare>(x, 1.6666);
    cout << "Found it? " << (foundIt ? "true" : "false") << endl;
}