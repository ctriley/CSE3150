#include "Rectangle.h"
#include <iostream>

int main() {
  Rectangle r1(10,20,100,100);
  std::cout << "Before: " << r1 << std::endl;
  Point p1(42,42);
  *r1.getCorner() = p1;
  std::cout << "After: " << r1 << std::endl;
  return 0;
}

/*
 * Could also write
 * int main() {
 *   Rectangle* p = new Rectangle(10,10,100,200);
 *   *p->getConrner() = p1;
 */
