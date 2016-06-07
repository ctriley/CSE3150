#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*template<class T, typename F>
bool find(const vector<T>& x, const T& v, const F& cmp) {
        int low = 0, up = x.size() - 1;
    while(low <= up) {
        int mid = (low + up) / 2;
        double c = cmp(v,x[mid]);
        if(c==0) return true;
        else if (c > 0) up = mid - 1;
        else low = mid + 1;
    }
    return false;
}*/

// could use a call by reference on the function if I make it const
// if you want to call function<int(T,T) you need to break out the 
// definition of lambda in the main class such that it is an l-value.
template<class T>
bool myfind(const vector<T>& x, const T& v, function<int(T, T)> cmp) {
    int low = 0, up = x.size() - 1;
    while(low <= up) {
        int mid = (low + up) / 2;
        double c = cmp(v,x[mid]);
        if(c == 0) return true;
        else if (c > 0) up = mid - 1;
        else low = mid + 1;
    }
    return false;
}

/*int main() {
    const double eps = 0.01;
    vector<double> x = {1, 5.0/3.0, 8, 11, 25, 30, 32, 47, 78, 99, 101};
    auto cmp = [](double a, double b) {
        if(fabs(a-b) < .01) return 0;
        else if(a < b) return 1;
        else return -1;
    };
    //bool foundIt = myfind(x, 1.666666666, function<int (double, double)> 
    //    (cmp));
    function<int (double, double)> f = cmp; // or f(cmp)
    bool foundIt = myfind(x, 1.6666666, f);
    cout << "Found it? " << (foundIt ? "true" : "false") << endl;
}*/

// better way to write main function

int main() {
    vector<double> x = {1, 5.0/3.0, 8, 11, 25, 30, 32, 47, 78, 99, 101};
    bool foundIt = myfind(x, 1.666666, 
        function<int(double, double)>([](double a, double b) {
            if(fabs(a-b) < .01) return 0;
            else if(a < b) return 1;
            else return -1;        
        }));
    cout << "Found it? " << (foundIt ? "true" : "false") << endl;

}