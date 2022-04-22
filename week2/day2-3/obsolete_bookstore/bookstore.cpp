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

#include <algorithm>
#include <iostream>
#include <vector>

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
void Book::AdjustCurrentStock(int in) { this->current_stock += in; }

void PrintMenu() {
  std::cout << "\n"
            << "MAIN MENU:\n"
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
            << "\tCurr. stock: " << book.GetCurrentStock() << "\n";
}

bool Match(Book &book, const std::string &phrase) {
  if (book.GetAuthor().find(phrase) != book.GetAuthor().npos) {
    return true;
  } else if (book.GetTitle().find(phrase) != book.GetTitle().npos) {
    return true;
  } else if (book.GetPublisher().find(phrase) != book.GetPublisher().npos) {
    return true;
  } else {
    return false;
  }
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
          for (auto &book : inventory) {
            std::cout << "\n";
            PrintBook(book);
          }
        } else {
          std::cout << "Inventory empty. Nothing to list.\n";
        }
        break;
      }
      case kSearch: {
        std::string phrase{};
        int match_count{};

        std::cout << "\n"
                  << " ~~ Enter search phrase: ";
        std::cin >> std::ws;
        std::getline(std::cin, phrase, '\n');

        for (auto book : inventory) {
          if (Match(book, phrase)) {
            std::cout << "\n";
            PrintBook(book);
            match_count++;
          }
        }

        std::cout << "\n" << match_count << " entries found.\n";
        break;
      }
      case kBuy: {
        std::string phrase{};
        int match_count{};

        std::cout << "\n"
                  << " ~~ Enter search phrase for the book you want to buy: ";
        std::cin >> std::ws;
        std::getline(std::cin, phrase, '\n');

        for (auto &book : inventory) {
          if (Match(book, phrase)) {
            match_count++;
            std::cout << "\n";
            PrintBook(book);

            int confirmation{};

            std::cout << "\n"
                      << " Is this the book you want to buy? \n"
                      << "    1) Yes please.\n"
                      << "    2) No! Keep searching.\n"
                      << " ~~ User confirmation: ";
            std::cin >> confirmation;

            if (1 == confirmation) {
              int amount{};

              std::cout << "\n"
                        << " ~~ How many copies do you want to buy? ";
              std::cin >> amount;
              if (book.GetCurrentStock() - amount >= 0) {
                book.AdjustCurrentStock(-amount);
                std::cout << "\nYou are buying " << amount << " copies of \""
                          << book.GetTitle() << "\" by " << book.GetAuthor()
                          << ".\nTotal cost: " << amount * book.GetPrice()
                          << "\n";
              } else {
                std::cout << "\nThere are not enough copies in stock.\n";
              }

              // Abort the loop at this point
              break;
            }
          }
          if (0 == match_count) {
            std::cout << "\nNo book matched your search. Please review your "
                         "search phrase.\n";
          } else {
            std::cout
                << "\nNo more books match your search. Please consult the "
                   "current inventory.\n";
          }
        }
        break;
      }
      case kEdit: {
        std::string phrase{};

        std::cout << "\n"
                  << " ~~ Enter search phrase for the book you want to edit: ";
        std::cin >> std::ws;
        std::getline(std::cin, phrase, '\n');

        for (size_t i = 0; i < inventory.size(); i++) {
          if (Match(inventory.at(i), phrase)) {
            std::cout << "\n";
            PrintBook(inventory.at(i));

            int confirmation{};

            std::cout << "\n"
                      << " Is this the book you want to edit? \n"
                      << "    1) Yes.\n"
                      << "    2) No!\n"
                      << " ~~ User confirmation: ";
            std::cin >> confirmation;

            if (1 == confirmation) {
              int field_edit_choice{};
              while (7 != field_edit_choice) {
                std::cout << "\nSelect field to edit.\n"
                          << "    1) Author\n"
                          << "    2) Title\n"
                          << "    3) Publisher\n"
                          << "    4) Year\n"
                          << "    5) Price\n"
                          << "    6) Current Stock\n"
                          << "    7) Stop editing. Return to main menu.\n"
                          << " ~~ Field to edit: ";
                std::cin >> field_edit_choice;

                std::string edit_str{};
                int edit_int{};
                switch (field_edit_choice) {
                  case kAuthor:
                    std::cout << "\n"
                              << " ~~ Enter author: ";
                    std::cin >> std::ws;
                    std::getline(std::cin, edit_str, '\n');
                    inventory.at(i).SetAuthor(edit_str);
                    break;
                  case kTitle:
                    std::cout << "\n"
                              << " ~~ Enter title: ";
                    std::cin >> std::ws;
                    std::getline(std::cin, edit_str, '\n');
                    inventory.at(i).SetTitle(edit_str);
                    break;
                  case kPublisher:
                    std::cout << "\n"
                              << " ~~ Enter publisher: ";
                    std::cin >> std::ws;
                    std::getline(std::cin, edit_str, '\n');
                    inventory.at(i).SetPublisher(edit_str);
                    break;
                  case kYear:
                    std::cout << "\n"
                              << " ~~ Enter year: ";
                    std::cin >> edit_int;
                    inventory.at(i).SetYear(edit_int);
                    break;
                  case kPrice:
                    std::cout << "\n"
                              << " ~~ Enter price: ";
                    std::cin >> edit_int;
                    inventory.at(i).SetPrice(edit_int);
                    break;
                  case kCurrentStock:
                    std::cout << "\n"
                              << " ~~ Enter current stock: ";
                    std::cin >> edit_int;
                    inventory.at(i).SetCurrentStock(edit_int);
                    break;
                  default:
                    std::cout << "Invalid option.\n";
                    break;
                }

                std::cout << "\nBook entry after edit:\n";
                PrintBook(inventory.at(i));
              }

              // Abort the loop at this point
              break;
            }
          }
        }

        break;
      }
      case kDelete: {
        std::string phrase{};

        std::cout
            << "\n"
            << " ~~ Enter search phrase for the book you want to DELETE: ";
        std::cin >> std::ws;
        std::getline(std::cin, phrase, '\n');

        for (size_t i = 0; i < inventory.size(); i++) {
          if (Match(inventory.at(i), phrase)) {
            std::cout << "\n";
            PrintBook(inventory.at(i));

            int confirmation{};

            std::cout << "\n"
                      << " Is this the book you want to DELETE? \n"
                      << "    1) Yes.\n"
                      << "    2) No!\n"
                      << " ~~ User confirmation: ";
            std::cin >> confirmation;

            if (1 == confirmation) {
              std::cout << "\nDeleted \"" << inventory.at(i).GetTitle()
                        << "\" by " << inventory.at(i).GetAuthor()
                        << " from inventory.\n";
              inventory.erase(inventory.begin() + i);

              // Abort the loop at this point
              break;
            }
          }
        }

        break;
      }
      case kExit: {
        int confirmation{};

        std::cout << "\n"
                  << "Are you sure you want to exit? \n"
                  << "    1) Yes! Exit the book store.\n"
                  << "    2) No! Back to the menu.\n"
                  << " ~~ User confirmation: ";
        std::cin >> confirmation;

        if (1 == confirmation) running = false;
        break;
      }
    }
  }

  std::cout << "\nThank you for your visit! Good bye.\n";
}