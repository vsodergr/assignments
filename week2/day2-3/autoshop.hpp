#include <chrono>
#include <iostream>
#include <string>
#include <vector>

// Constant exit command to compare
const std::string kExit{"exit"};

// Input helpers for strings and ints
void GetInput(std::string &str);
void GetInput(int &i);

// Printing the entire customer record
void PrintCustomerRecord();

class Part {
 public:
  Part(std::string in_type, int in_cost);
  int get_cost();

 private:
  std::string type{};
  int cost{};
};

class Service {
 public:
  Service();
  int get_cost();
  void add_part();

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

 private:
  std::string make{};
  std::vector<Service> service_list{};
};

class Payment {
 public:
  Payment();

 private:
  std::string method{};
  int ammount{};
};

class Customer {
 public:
  Customer(std::string in_name);
  void add_vehicle();
  void add_service(size_t vehicle_idx);
  std::string get_name();
  std::vector<Vehicle> get_vehicle_list();

 private:
  std::string name{};
  std::vector<Vehicle> vehicle_list{};
  std::vector<Payment> payment_record{};
};
