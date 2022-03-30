#include <cmath>
#include <iostream>

class Shape {
 public:
  virtual double area() = 0;
  virtual double perimeter() = 0;
  bool operator==(Shape &s) {
    return (this->area() == s.area()) && (this->perimeter() == s.perimeter());
  }

 private:
};

class Rectangle : public Shape {
 public:
  Rectangle(double h, double w) : height(h), width(w) {}
  double area() { return this->height * this->width; }
  double perimeter() { return (2 * this->height) + (2 * this->width); }

 private:
  double height{};
  double width{};
};

class Circle : public Shape {
 public:
  Circle(double r) : radius(r) {}
  double area() { return M_PI * this->radius * this->radius; }
  double perimeter() { return 2 * M_PI * this->radius; }

 private:
  double radius{};
};

class Triangle : public Shape {
 public:
  Triangle(double h, double w) : height(h), width(w) {}
  double area() { return (this->height * this->width) / 2; }
  double perimeter() {
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

  return 0;
}