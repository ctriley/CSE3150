// range loops

#include <iostream>
#include <string>

using namespace std;

void range1() {
    string vals = {'h', 'e', 'l', 'l', 'o'};
    for(char v : vals) {
        cout << "v = " << v << endl;
    }
    cout << "old" << endl;
    for(int k = 0; k < vals.size(); k++) {
        cout << "v = " << vals[k] << endl;
    }
}

int main() {
    range1();
    return 0;
}