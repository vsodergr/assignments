/*
 * Write a function template which receives two of any shapes from last week’s
 * assignment, compares them, and prints out the result.
 */

#include <iostream>

#include "shapes.hpp"

int main() {
  Rectangle r1{3, 4};
  Rectangle r2{4, 3};
  Circle c1{5};
  Circle c2{5};
  Triangle t1{3, 4};
  Triangle t2{4, 3};

  std::cout << "Rectangle/Rectangle: " << (r1 == r2) << "\n";
  std::cout << "Rectangle/Circle: " << (r1 == c1) << "\n";
  std::cout << "Rectangle/Triangle: " << (r1 == t1) << "\n";
  std::cout << "Circle/Circle: " << (c1 == c2) << "\n";
  std::cout << "Circle/Rectangle: " << (c1 == r2) << "\n";
  std::cout << "Circle/Triangle: " << (c1 == t1) << "\n";
  std::cout << "Triangle/Triangle: " << (t1 == t2) << "\n";
  std::cout << "Triangle/Circle: " << (t2 == c2) << "\n";
  std::cout << "Triangle/Rectangle: " << (t2 == r2) << "\n";

  // Comparison by template
  compare_shapes(r1, r2);
  compare_shapes(r1, c1);
  compare_shapes(r1, t1);
  compare_shapes(c1, c2);
  compare_shapes(c1, r2);
  compare_shapes(c1, t1);
  compare_shapes(t1, t2);
  compare_shapes(t2, c2);
  compare_shapes(t2, r2);

  return 0;
}