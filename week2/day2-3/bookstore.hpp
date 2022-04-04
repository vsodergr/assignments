#include <string>

// enum class MenuChoice {
//   kNew = 1,
//   kList,
//   kSearch,
//   kBuy,
//   kEdit,
//   kExit,
// };

const int kNew{1};
const int kList{2};
const int kSearch{3};
const int kBuy{4};
const int kEdit{5};
const int kDelete{6};
const int kExit{7};

class Book {
 public:
  Book();
  ~Book();
  std::string GetAuthor();
  std::string GetTitle();
  std::string GetPublisher();
  int GetYear();
  int GetPrice();
  int GetCurrentStock();
  void SetAuthor(std::string&);
  void SetTitle(std::string&);
  void SetPublisher(std::string&);
  void SetYear(int&);
  void SetPrice(int&);
  void SetCurrentStock(int&);

 private:
  std::string author{};
  std::string title{};
  std::string publisher{};
  int year{};
  int price{};
  int current_stock{};
};
