#include <iostream>

#ifndef SHAPES_HPP
#define SHAPES_HPP

// Template defined here to avoid linking error
template <typename Ta, typename Tb>
void compare_shapes(const Ta& a, const Tb& b) {
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
  bool operator==(Shape& s);

 private:
};

class Rectangle : public Shape {
 public:
  Rectangle(double h, double w) : height(h), width(w) {}
  double area() const;
  double perimeter() const;

 private:
  double height{};
  double width{};
};

class Circle : public Shape {
 public:
  Circle(double r) : radius(r) {}
  double area() const;
  double perimeter() const;

 private:
  double radius{};
};

class Triangle : public Shape {
 public:
  Triangle(double h, double w) : height(h), width(w) {}
  double area() const;
  double perimeter() const;

 private:
  double height{};
  double width{};
};

#endif /* SHAPES_HPP */
