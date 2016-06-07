// lambdas and partials

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template<class T>
bool myfind(const vector<T>& x, const function<int(T)>& cmp) {
    int low = 0, up = x.size() - 1;
    while(low <= up) {
        int mid = (low + up) / 2;
        double c = cmp(x[mid]);
        if(c == 0) return true;
        else if (c > 0) up = mid - 1;
        else low = mid + 1;
    }
    return false;
}


int main() {
    using namespace std::placeholders;
    std::vector<double> x = {1, 5.0/3.0, 8, 11, 25, 30, 32, 47, 78, 99, 101};
    const double esp = .01;
    auto cmp = [esp](double a, double b) -> int {
        if(fabs(a-b) < .01) return 0;
        else if(a > b) return 1;
        else return -1;  
    };
    std::function<int(double)> f = std::bind(cmp, _1, 1.666666666);
    //bool foundIt = myfind(x, std::bind(cmp,_1,100));
    bool foundIt = myfind(x, f);
    cout << "Found it? " << (foundIt ? "true" : "false") << endl;
}