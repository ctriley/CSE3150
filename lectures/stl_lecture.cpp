#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void stack_example() {
    stack<int> si;
    for(int i = 0; i < 5; i++) {
        si.push(i);
    }
    while(!si.empty()) {
        cout << "values: " << si.top() << endl;
        si.pop();
    }
}

vector<int> vector_example() {
    vector<int> vec;
    for(int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    for(int v : vec) {
        cout << v << " ";
    }
    cout << endl;
    return vec;
} 

void vector_iteration() {
    for(vector<int>::iterator k = vec.begin();
        k != vec.end();
        k++) {
        cout << *k << " ";
    }
}

template <class T>
void auto_iteration(vector<T> vec) {
    // iterators through the vector passed to it in reverse. 
    for(auto k = vec.rbegin(); k != vec.rend(); k++) {
        cout << *k << endl;
    }
}

template <class T>
T sum(vector<T> &vec) {
    T ttl = 0;
    for(T v : vec) {
        ttl += v;
    }
    return ttl;
}

// completely generic printer (prints in reverse)
template <class Container>
void rprint(Container& c) {
    for(auto k = c.rbegin(); k != c.rend(); k++) {
        cout << *k << " ";
    }
    cout << endl;
}

int main() {
    stack_example();
    vector<int> vec = vector_example();
    cout << sum(vec) << endl;
    return 0;
}