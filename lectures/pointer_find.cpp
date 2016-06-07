// motivation for lambdas
// find algorithm - does the value belong to a container

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

// just a binary search (generic)
template<class T>
bool find_tranditional(const vector<T>& x, const T& v) {
    int low = 0, up = x.size() - 1;
    while(low <= up) {
        int mid = (low + up) / 2;
        const int c = compare(v,x[mid]);
        if(c == 0) { return true; }
        else if(c < 0) { up = mid - 1; }
        else { low = mid + 1; }
    }
    return false;
}

// with pointers - now we pass the compare funciton to the function
template<class T>
bool myfind(const vector<T>& x, const T& v, int (*cmp)(const T&, const T&)) {
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
    bool foundIt = myfind(x, 1.6666, compare);
    cout << "Found it? " << (foundIt ? "true" : "false") << endl;
}