#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


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
    vector<int> b;

    mycopy(a.begin(), a.end(), back_inserter(b));

    for(int v : b) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}