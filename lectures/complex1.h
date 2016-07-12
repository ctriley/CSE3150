#ifndef __COMPLEX1_H
#define __COMPLEX1_H

#include <ostream>

class Complex {
    double _real;
    double _imag;
    Complex add(const Complex& c2) const {
        const double r = _real + c2._real;
        const double i = _imag + c2._imag;
        return Complex(r,i);
    }
public:
    Complex() : _real(0), _imag(0) {}
    Complex(double a, double b) : _real(a),_imag(b) {}
    Complex(const Complex& c) : _real(c._real), _imag(c._imag) {}
    Complex& operator=(const Complex& c) { 
        _real = c._real; _imag = c._imag;
        return *this;
    }
    Complex conjugate() {
        return Complex(_real, - _imag);
    }
    void print(std::ostream& os);
    friend Complex operator+(const Complex& a, const Complex& b) {
        return a.add(b);
    }
};

#endif