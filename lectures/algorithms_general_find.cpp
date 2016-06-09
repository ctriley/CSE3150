#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <class InputIterator, class T> 
InputIterator myfind(InputIterator from, InputIterator to, const T& v) {
    while(from != to) {
        if(*from == v) {
            return from;
        }
        ++from;
    }
    return from;
}

template <class InputIterator, typename Predicate>
InputIterator myfind_if(InputIterator from, InputIterator to, Predicate p) {
    while(from != to) {
        if(p(*from)) {
            return from;
        }
        ++from;
    }
    return from;
}



int main() {
    list<int> x = {1,20,5,12,34,17,51,43,99,2,0,23};
    auto at = myfind_if(x.begin(), x.end(), [](int v) -> bool {
        return v == 51;});
    cout << "found? " << (at != x.end()) << endl;
        if(at != x.end()) {
            cout << "value: " << *at << endl;
        }
    return 0;
}