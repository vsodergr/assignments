#include "bookstore.hpp"

#include <iostream>

void IntInput(int& in_int) {
  std::cin >> in_int;
  while(std::cin.fail()) {
    std::cout << "Input must be an integer. Try again.\n";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cin >> in_int;
  }
}

Book::Book() {
  std::string in_string{};

  std::cout << "\nEnter book author: ";
  std::cin >> std::ws;
  std::getline(std::cin, in_string, '\n');
  this->author = in_string;

  std::cout << "Enter book title: ";
  std::cin >> std::ws;
  std::getline(std::cin, in_string, '\n');
  this->title = in_string;

  std::cout << "Enter book publisher: ";
  std::cin >> std::ws;
  std::getline(std::cin, in_string, '\n');
  this->publisher = in_string;

  int in_int{};

  std::cout << "Enter publishing year: ";
  IntInput(in_int);
  this->year = in_int;

  std::cout << "Enter retail price: ";
  IntInput(in_int);
  this->price = in_int;

  std::cout << "Enter initial stock: ";
  IntInput(in_int);
  this->current_stock = in_int;
}

Book::~Book() {}
std::string Book::GetAuthor() { return this->author; }
std::string Book::GetTitle() { return this->title; }
std::string Book::GetPublisher() { return this->publisher; }
int Book::GetYear() { return this->year; }
int Book::GetPrice() { return this->price; }
int Book::GetCurrentStock() { return this->current_stock; }
void Book::SetAuthor(std::string &in) { this->author = in; }
void Book::SetTitle(std::string &in) { this->title = in; }
void Book::SetPublisher(std::string &in) { this->publisher = in; }
void Book::SetYear(int &in) { this->year = in; }
void Book::SetPrice(int &in) { this->price = in; }
void Book::SetCurrentStock(int &in) { this->current_stock = in; }
void Book::AdjustCurrentStock(int in) { this->current_stock += in; }
