//student.cpp

#include <iostream>
#include "student.h"

void Student::read(std::istream& is) {
    is >> _name >> _mt >> _final;
    int nbH = 0;
    is >> nbH;
    for(int i = 0; i < nbH; i++) {
        int v;
        is >> v;
        _homeworks.push_back(v);
    }
}

void Student::print(std::ostream& os) {
    os << "Name: " << _name << '[' << _mt << ',' << _final << ']' << std::endl;
    for(int v : _homeworks) {
        os << "\t:" << v << std::endl;
    } 
}

int main() {
    using namespace std;
    Student s;  // creates a new object on the stack
    shared_ptr<Student> sp(new Student); // creates an object on the heap   s._name = "Joe";
    s._name = "Joe";
    s._mt = 80;
    s._final = 90;
    s._homeworks.push_back(65);
    s._homeworks.push_back(42);
    s._homeworks.push_back(96);

    *sp = s;  // copies the stack object to the heap

    cout << "S._name: " << s._name << endl;
    cout << "sp->_name: " << sp->_name << endl;

    cout << "&S._name: " << &s._name << endl;
    cout << "&sp->_name: " << &sp->_name << endl;

    s._name = "Bertie";
    cout << "S._name: " << s._name << endl;
    cout << "sp->_name: " << sp->_name << endl;
    return 0;
}
