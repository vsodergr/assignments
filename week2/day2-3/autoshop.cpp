#include "autoshop.hpp"

void GetInput(std::string &s) { std::getline(std::cin, s, '\n'); }
void GetInput(int &i) { std::cin >> i; }

Part::Part(std::string in_type, int in_cost) {
  this->type = in_type;
  this->cost = in_cost;
}

int Part::get_cost() { return this->cost; }

Service::Service() {
  std::string srv_action;
  std::cout << "Enter service action performed: ";
  GetInput(srv_action);

  int srv_cost;
  std::cout << "Enter work cost of service: ";
  GetInput(srv_cost);

  this->date = std::time(nullptr);
}

int Service::get_cost() {
  int total{this->cost};
  for (auto part : this->part_list) total += part.get_cost();
  return total;
}

void Service::add_part() {
  std::string part_type{};
  std::cout << "What part did you change? ";
  GetInput(part_type);

  int part_cost{};
  std::cout << "How much did the part cost? ";
  GetInput(part_cost);

  Part new_part{part_type, part_cost};
  this->part_list.push_back(new_part);
}

Vehicle::Vehicle(std::string in_make) { this->make = in_make; }

void Vehicle::add_service() {
  Service new_service{};

  std::string parts_changed{};
  std::cout << "Did you change any parts (yes/no)? ";
  GetInput(parts_changed);

  while (parts_changed.compare("no")) {
    // if (parts_changed.compare("yes")) {
    //   std::cout << "Please enter \"yes\" or \"no\": ";
    //   GetInput(parts_changed);
    //   continue;
    // }

    new_service.add_part();

    std::cout << "Did you change any other parts (yes/no)? ";
    GetInput(parts_changed);
  }

  this->service_list.push_back(new_service);
}

Payment::Payment() {
  std::cout << "By what method do you want to pay? ";
  GetInput(this->method);
  std::cout << "Enter the ammount to pay: ";
  GetInput(this->ammount);
}

Customer::Customer(std::string in_name) { this->name = in_name; }

void Customer::add_vehicle() {
  std::string vehicle_make;
  std::cout << "Enter the make of the customers vehicle: ";
  GetInput(vehicle_make);
  Vehicle new_vehicle{vehicle_make};
  this->vehicle_list.push_back(new_vehicle);
}

// Call add_service on the customers vehicle entry if it exists.
void Customer::add_service(size_t vehicle_idx) {
  if (this->vehicle_list.size() > 0) {
    this->vehicle_list.at(vehicle_idx).add_service();
  } else {
    std::cout << "The customer has no vehicles to service.\n";
  }
}

int main() {
  // Creating master record of customers.
  std::vector<Customer> customer_record{};

  std::cout << "Hello customer! What is your name? ";
  std::string usr_input{};
  GetInput(usr_input);

  while (usr_input.compare("exit")) {
    Customer new_customer{usr_input};
    customer_record.push_back(new_customer);

    customer_record.at(0).add_vehicle();
    customer_record.at(0).add_service(0);

    std::cout << "If you want to exit type \"exit\": ";
    GetInput(usr_input);
  }

  std::cout << "Exiting auto shop. All is forgotten.\n";
}