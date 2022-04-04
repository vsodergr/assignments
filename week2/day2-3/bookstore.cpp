/*
 * A book shop maintains the inventory of books that are being sold at the shop.
 * The list includes details such as author, title, price, publisher and stock
 * position. Whenever a customer wants a book, the sales person inputs the title
 * and author and the system searches the list and displays whether it is
 * available or not. If it is not, an appropriate message is displayed. If it
 * is, then the system displays the book details and requests for the number of
 * copies required. If the requested copies book details and requests for the
 * number of copies required. If the requested copies are available, the total
 * cost of the requested copies is displayed; otherwise the message “Required
 * copies not in stock” is displayed.
 *
 * Design a system using a class called books with suitable member functions and
 * Constructors. Use new operator in constructors to allocate memory space
 * required. Implement C++ program for the system.
 *
 * Example Menu
 * 1. Entry of New Book
 * 2. Buy Book
 * 3. Search For Book
 * 4. Edit Details Of Book
 * 5. Exit
 */

#include "bookstore.hpp"

#include <iostream>
#include <vector>

Book::Book() {
  std::string in_string{};

  std::cout << "Enter book author: ";
  std::cin >> std::ws;
  std::getline(std::cin, in_string, '\n');
  this->author;

  std::cout << "Enter book title: ";
  std::cin >> std::ws;
  std::getline(std::cin, in_string, '\n');
  this->title;

  std::cout << "Enter book publisher: ";
  std::cin >> std::ws;
  std::getline(std::cin, in_string, '\n');
  this->publisher;

  int in_int{};

  std::cout << "Enter publishing year: ";
  std::cin >> in_int;
  this->year;

  std::cout << "Enter retail price: ";
  std::cin >> in_int;
  this->price;

  std::cout << "Enter initial stock: ";
  std::cin >> in_int;
  this->current_stock;
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

void PrintMenu() {
  std::cout << " ~~ Menu ~~\n"
            << "1) Enter new book\n"
            << "2) List books\n"
            << "3) Search books\n"
            << "4) By a book\n"
            << "5) Edit existing book\n"
            << "5) Delete existing book\n"
            << "7) Exit\n"
            << " ~~ Choose: ";
}

int main() {
  std::vector<Book> inventory{};

  int menu_input{};
  PrintMenu();
  std::cin >> menu_input;

  switch (menu_input) {
    case kNew: {
      Book b{};
      inventory.push_back(b);
      break;
    }
    case kList: {
      if (inventory.size() > 0) {
        for (auto book : inventory) {
          std::cout << "Author:\t" << book.GetAuthor() << "\n"
                    << "Title:\t" << book.GetTitle() << "\n"
                    << "Publicher:\t" << book.GetPublisher() << "\n"
                    << "Publ. year:\t" << book.GetYear() << "\n"
                    << "Price:\t" << book.GetPrice() << "\n"
                    << "Curr. stock:\t" << book.GetCurrentStock() << "\n";
        }
      } else {
        std::cout << "Inventory empty. Nothing to list.\n";
      }
      break;
    }
    case kSearch: {
      std::cout << "Search\n";
      break;
    }
    case kBuy: {
      std::cout << "Buy\n";
      break;
    }
    case kEdit: {
      std::cout << "Edit\n";
      break;
    }
    case kDelete: {
      if (inventory.size() > 0) {
        std::cout << "Deleting last entry.\n";
        inventory.pop_back();
      } else {
        std::cout << "Inventory empty. Nothing to delete.\n";
      }
      break;
    }
    case kExit: {
      std::cout << "Exit\n";
      break;
    }
  }
}