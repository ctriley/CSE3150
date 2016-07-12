#include "complex1.h"

void Complex::print(std::ostream& os) {
    if(_imag < 0)
        os << '(' << _real << ' ' << _imag << 'i' << ')';
    else if(_imag == 0) {
        os << '(' << _real << ')';
    } else {
        os << '(' << _real << " + " << _imag << 'i' << ')'; 
    }
}