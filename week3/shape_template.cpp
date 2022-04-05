/*
 * Write a function template which receives two of any shapes from last week’s
 * assignment, compares them, and prints out the result.
 */

#include <cmath>
#include <iostream>

template <typename Ta, typename Tb>
void compare_shapes(Ta const& a, Tb const& b) {
  if (a.area() > b.area()) {
    std::cout << "First shape has greater area.\n";
  } else if (a.area() < b.area()) {
    std::cout << "Second shape has the greater area.\n";
  } else {
    std::cout << "Both shapes have equal area.\n";
  }

  if (a.perimeter() > b.perimeter()) {
    std::cout << "First shape has greater perimeter.\n";
  } else if (a.perimeter() < b.perimeter()) {
    std::cout << "Second shape has the greater perimeter.\n";
  } else {
    std::cout << "Both shapes have equal perimeter.\n";
  }
}

class Shape {
 public:
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  bool operator==(Shape& s) {
    return (this->area() == s.area()) && (this->perimeter() == s.perimeter());
  }

 private:
};

class Rectangle : public Shape {
 public:
  Rectangle(double h, double w) : height(h), width(w) {}
  double area() const { return this->height * this->width; }
  double perimeter() const { return (2 * this->height) + (2 * this->width); }

 private:
  double height{};
  double width{};
};

class Circle : public Shape {
 public:
  Circle(double r) : radius(r) {}
  double area() const { return M_PI * this->radius * this->radius; }
  double perimeter() const { return 2 * M_PI * this->radius; }

 private:
  double radius{};
};

class Triangle : public Shape {
 public:
  Triangle(double h, double w) : height(h), width(w) {}
  double area() const { return (this->height * this->width) / 2; }
  double perimeter() const {
    return (this->height + this->width) +
           (sqrt(pow(this->height, 2) + pow(this->width, 2)));
  }

 private:
  double height{};
  double width{};
};

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