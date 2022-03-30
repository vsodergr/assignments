#include <chrono>
#include <iostream>
#include <string>
#include <vector>

void GetInput(std::string &str);
void GetInput(int &i);

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

 private:
  std::string name{};
  std::vector<Vehicle> vehicle_list{};
};
