#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template <class Container, class InputIterator>
void insertInto(Container& b, InputIterator from, InputIterator to) {
    while(from != to) {
        b.push_back(*from);
        ++from;
    }
}


template <typename InputIterator, typename OutputIterator>
OutputIterator mycopy(InputIterator from, InputIterator to, 
    OutputIterator into) {
    while(from != to) {
        *into = *from;
        ++from;
        ++into;
    }
    return into;
}

int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {10,11,12,13};
    mycopy(a.begin(), a.end(), back_inserter(b));
    for(int v : b) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
/*int main() {
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {10,11,12,13};
    insertInto(b,a.begin(),a.end());
    for(int v : b) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}*/