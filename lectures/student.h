// class example

#ifndef __STUDENT_H
#define __STUDENT_H

#include <string>
#include <vector>

// using class makes everything private

class Student {
    std::string _name;
    double _mt, _final;
    std::vector<double> _homeworks;
public:
    Student();
    Student(const std::string& s);
    Student(const Student& s2);
    Student(Student&& s2);
    ~Student();
    Student& operator=(const Student& s);
    Student& operator=(Student&& s);
    void read(std::istream& is);
    void print(std::ostream& os);
    void setName(const std::string& n);
    String getName() {return _name;}
};


// structs are always public by default
/*struct Student {
    // constructors
    Student() { _mt = _final = 0; } // default
    Student(const std::string& s) {_name = s; _mt = _final = 0;}
    // copy constructor
    // what is shallow copy vs. deep copy?

    /*Student(const Student& s2) {
        _name = s2._name; _mt = s2._mt; _final = s2._final;
        for(double d : s2._homeworks) _homeworks.push_back(d);
    }
    // weird syntax for a copy constructor
    Student(const Student& s2)
        : _name(s2._name),
          _mt(s2._mt),
          _final(s2._final),
          _homeworks(s2._homeworks)
    {}
    // move constructor - similar to copy but deletes the original
    Student(Student&& s2)
        : _name(std::move(s2._name)),
          _mt(s2._mt), _final(s2._final),
          _homeworks(std::move(s2._homeworks))
    {}
    // copy operators - redefining "="
    Student& operator=(const Student& s) {
        if(this == &s) return *this;
        _name = s._name;
        _mt = s._mt;
        _final = s._final;
        _homeworks = s._homeworks;
        return *this;
    }
    // move operator
    Student& operator=(Student&& s) {
        _name = std::move(s._name);
        _mt = s._mt;
        _final = s._final;
        _homeworks = std::move(s._homeworks);
        return *this;
    }
    // one destructor
    ~Student() {
        std::cout << "destroy(" << this << ")" << std::endl;
    }
    void read(std::istream& is);
    void print(std::ostream& os);
    void setName(const std::string& n);
private:
    std::string _name;
    double _mt, _final;
    std::vector<double> _homeworks;
}; 
*/

#endif