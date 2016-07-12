#ifndef __POINT_H
#define __POINT_H

class Point {
    double _x, _y;
public:
    Point() { _x = _y = 0;}
    Point(double x, double y) { _x = x; _y = y;}
    Point(const Point& p) : _x(p._x), _y(p._y) {}
    double getX() const {return _x;}
    double getY() const {return _y;}
    void set(double x, double y) { _x = x; _y = y;}
    Point& operator=(const Point& p) { _x = p._x; _y = p._y; return *this;}
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator*(const Point& p1, double s);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

#endif
