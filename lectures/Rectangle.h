#ifndef __RECTANGLE_H
#define __RECTANGLE_H

#include "Point.h"

class Rectangle {
  Point _corner;
    double _w, _h;
public:
    Rectangle() : _w(0), _h(0) {}
    Rectangle(double x, double y, double w, double h) 
        : _corner(new Point(x,y), _w(w), _h(h)) {}
    Point getCorner() const { return _corner;}
    double getWidth() const { return _w; }
    double getHeight() const { return _h; }
    friend std::ostream& operator <<(std::ostream& os, const Rectangle& r) {
        return os << "rect(" << *r._corner << "," << r._w << "," << r._h << ")";
    }
};

#endif
