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

#include <iostream>

enum class Menu {
  kNew = 0,
  kList,
  kSearch,
  kBuy,
  kEdit,
  kExit,
};

class Book {
 public:
  std::string GetAuthor();
  std::string GetTitle();
  std::string GetPublisher();
  int GetYear();
  int GetPrice();
  int GetCurrentStock();
  void SetAuthor(std::string);
  void SetTitle(std::string);
  void SetPublisher(std::string);
  void SetYear(int);
  void SetPrice(int);
  void SetCurrentStock(int);

 private:
  std::string author{};
  std::string title{};
  std::string publisher{};
  int year{};
  int price{};
  int current_stock{};
};

std::string Book::GetAuthor() { return this->author; }

std::string Book::GetTitle() { return this->title; }

std::string Book::GetPublisher() { return this->publisher; }

int Book::GetYear() { return this->year; }

int Book::GetPrice() { return this->price; }

int Book::GetCurrentStock() { return this->current_stock; }

void Book::SetAuthor(std::string in) { this->author = in; }

void Book::SetTitle(std::string in) { this->title = in; }

void Book::SetPublisher(std::string in) { this->publisher = in; }

void Book::SetYear(int in) { this->year = in; }

void Book::SetPrice(int in) { this->price = in; }

void Book::SetCurrentStock(int in) { this->current_stock = in; }

void PrintMenu(int &choice) {
  std::cout << " ~~ Menu ~~\n"
            << "1) Enter new book\n"
            << "2) List books\n"
            << "3) Search books\n"
            << "4) By a book\n"
            << "5) Edit existing book\n"
            << "6) Exit\n"
            << " ~~ Choose: ";
  std::cin >> choice;
}

int main() {
  int user_input{};
  PrintMenu(user_input);
}