// referenes_args.cpp

#include <iostream>
#include <string>

using namespace std;
void sumOf(string a, int& ttl) {
    ttl = 0;
    for(int i = 0; i < a.size(); i++) {
        ttl += a[i];
    }
    a[0] = 100;
}

int main() {
    string x = {'H', 'e', 'l', 'l', 'o'};
    int s;
    sumOf(x,s);
    cout << "s = " << s << endl;
    cout << "x = " << x << endl;
    return 0;
}