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