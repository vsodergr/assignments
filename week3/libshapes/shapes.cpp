
#include "shapes.hpp"

#include <cmath>

bool Shape::operator==(Shape& s) {
  return (this->area() == s.area()) && (this->perimeter() == s.perimeter());
}

double Rectangle::area() const { return this->height * this->width; }
double Rectangle::perimeter() const {
  return (2 * this->height) + (2 * this->width);
}

double Circle::area() const { return M_PI * this->radius * this->radius; }
double Circle::perimeter() const { return 2 * M_PI * this->radius; }

double Triangle::area() const { return (this->height * this->width) / 2; }
double Triangle::perimeter() const {
  return (this->height + this->width) +
         (sqrt(pow(this->height, 2) + pow(this->width, 2)));
}
