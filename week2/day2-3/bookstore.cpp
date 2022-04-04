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
  std::cin >> in_int;
  this->year = in_int;

  std::cout << "Enter retail price: ";
  std::cin >> in_int;
  this->price = in_int;

  std::cout << "Enter initial stock: ";
  std::cin >> in_int;
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

void PrintMenu() {
  std::cout << "\n"
            << " ~~ Menu ~~\n"
            << "    1) Enter new book\n"
            << "    2) List books\n"
            << "    3) Search books\n"
            << "    4) By a book\n"
            << "    5) Edit existing book\n"
            << "    6) Delete existing book\n"
            << "    7) Exit\n"
            << " ~~ User input: ";
}

void PrintBook(Book &book) {
  std::cout << "\tAuthor:      " << book.GetAuthor() << "\n"
            << "\tTitle:       " << book.GetTitle() << "\n"
            << "\tPublisher:   " << book.GetPublisher() << "\n"
            << "\tPubl. year:  " << book.GetYear() << "\n"
            << "\tPrice:       " << book.GetPrice() << "\n"
            << "\tCurr. stock: " << book.GetCurrentStock() << "\n"
            << "\n";
}

int main() {
  // Main regirtry of inventory.
  std::vector<Book> inventory{};

  // Running condition. Set false at exit option.
  bool running{true};

  while (running) {
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
        std::cout << "\n"
                  << "Listing books in registry: \n";

        if (inventory.size() > 0) {
          for (auto &book : inventory) PrintBook(book);
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
        std::cout << "\n";

        if (inventory.size() > 0) {
          std::cout << "Deleting last entry.\n";
          inventory.pop_back();
        } else {
          std::cout << "Inventory empty. Nothing to delete.\n";
        }
        break;
      }
      case kExit: {
        int confirmation{};

        std::cout << "\n"
                  << " ~~ Are you sure you want to exit? \n"
                  << "    1) No! Back to the menu.\n"
                  << "    2) Yes! Exit the book store.\n"
                  << " ~~ User confirmation: ";
        std::cin >> confirmation;

        if (2 == confirmation) running = false;
        break;
      }
    }
  }

  std::cout << "Thank you for your visit! Good bye.\n";
}