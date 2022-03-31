#include <chrono>
#include <iostream>
#include <string>
#include <vector>

// Constant exit command to compare
const std::string kExit{"exit"};

class Part {
 public:
  Part(std::string in_type, int in_cost);
  int get_cost();
  std::string get_part_type();

 private:
  std::string type{};
  int cost{};
};

class Service {
 public:
  Service();
  int get_cost();
  void add_part();
  std::string get_service_action();
  std::string get_date_string();
  std::vector<Part> get_parts();

 private:
  std::string action{};
  int cost{};
  std::time_t date{};
  std::vector<Part> part_list{};
};

class Vehicle {
 public:
  Vehicle(std::string in_make);
  void add_service();
  std::string get_make();
  std::vector<Service> get_service_list();

 private:
  std::string make{};
  std::vector<Service> service_list{};
};

class Payment {
 public:
  Payment();
  std::string get_method();
  int get_amount();

 private:
  std::string method{};
  int amount{};
};

class Customer {
 public:
  Customer(std::string in_name);
  void add_vehicle();
  void add_service(size_t vehicle_idx);
  std::string get_name();
  std::vector<Vehicle> get_vehicle_list();
  void make_payment();
  void adjust_balance(int adjustment);
  int get_balance();

 private:
  std::string name{};
  std::vector<Vehicle> vehicle_list{};
  std::vector<Payment> payment_record{};
  int balance{};
};

// Input helpers for strings and ints
void GetInput(std::string &str);
void GetInput(int &i);

// Printing the entire customer record
void PrintCustomerRecord(std::vector<Customer> &record);
