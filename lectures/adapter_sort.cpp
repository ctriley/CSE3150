// adapter_sort

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<typename T, typename InputIterator, typename F>
void mergeSortAux(vector<T>& v, InputIterator from, InputIterator to, 
    const F& cmp) {
    if(next(from) == to) {
        return;
    } else {
        auto d = from + (to - from)/2;
        mergeSortAux(v, from, d, cmp);
        mergeSortAux(v, d, to, cmp);
        vector<T> a(from, d);
        vector<T> b(d,to);

        auto i = a.begin();
        auto j = b.begin();
        auto k = from;

        while(i != a.end() && j != b.end()) {
            if(cmp(*i, *j)) {
                *k++ = *i++;
            } else {
                *k++ = *j++;
            }
        }
        while(i != a.end()) {
            *k++ = *i++;
        }
        while(j != b.end()) {
            *k++ = *j++;
        } 
    }
}

template <typename T, typename F>
void mergeSort(vector<T>& v, const F& cmp) {
    return mergeSortAux(v,v.begin(), v.end(), cmp);
}

int main() {
    vector<int> uv = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    cout << "init:\t";
    std::copy(uv.begin(), uv.end(), 
        std::ostream_iterator<int>(std::cout, ", "));
    cout << endl;
    mergeSort(uv, [](int a, int b) {return a < b;});
    cout << "sort:\t";
    std::copy(uv.begin(), uv.end(), 
        std::ostream_iterator<int>(std::cout, ", "));
    cout << endl;
    // below is the printing code in the slides - why doesn't this work?
    //cout << "sort:\t" << uv << endl;
}