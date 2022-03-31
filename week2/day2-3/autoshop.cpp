#include "autoshop.hpp"

void GetInput(std::string &s) {
  std::cin >> std::ws;
  s = "";
  std::getline(std::cin, s, '\n');
}

void GetInput(int &i) { std::cin >> i; }

void PrintCustomerRecord() {
  std::cout << "Auto Shop Customer Record\n"
            << "\tRECORD PLACEHOLDER\n";
}

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

  std::string parts_changed{"no"};
  std::cout << "Did you change any parts (yes/no)? ";
  GetInput(parts_changed);

  while (0 != parts_changed.compare("no")) {
    if (parts_changed.compare("yes")) {
      std::cout << "Please enter \"yes\" or \"no\": ";
      GetInput(parts_changed);
      continue;
    }

    new_service.add_part();

    std::cout << "Did you change any other parts (yes/no)? ";
    GetInput(parts_changed);
  }

  this->service_list.push_back(new_service);
}

std::string Vehicle::get_make() { return this->make; }

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

std::string Customer::get_name() { return this->name; }

std::vector<Vehicle> Customer::get_vehicle_list() { return this->vehicle_list; }

int main() {
  // Creating master record of customers.
  std::vector<Customer> customer_record{};

  size_t customer_idx{};
  size_t vehicle_idx{};
  size_t service_idx{};
  std::string usr_input{};

  std::cout << "Hello customer! What is your name? ";
  GetInput(usr_input);

  while (0 != usr_input.compare(kExit)) {
    Customer new_customer{usr_input};
    customer_record.push_back(new_customer);

    while (0 != usr_input.compare(kExit)) {
      customer_record.at(customer_idx).add_vehicle();

      while (0 != usr_input.compare(kExit)) {
        customer_record.at(customer_idx).add_service(vehicle_idx);

        service_idx++;
        std::cout << "Enter a new service for "
                  << customer_record.at(customer_idx).get_name() << "'s "
                  << customer_record.at(customer_idx)
                         .get_vehicle_list()
                         .at(vehicle_idx)
                         .get_make()
                  << " (or type \"exit\" to exit): ";
        GetInput(usr_input);
      }

      vehicle_idx++;
      std::cout << "Enter a new vehicle for "
                << customer_record.at(customer_idx).get_name()
                << " (or type \"exit\" to exit): ";
      GetInput(usr_input);
    }

    customer_idx++;
    std::cout << "Enter a new customer's name (or type \"exit\" to exit): ";
    GetInput(usr_input);
  }

  PrintCustomerRecord();
  std::cout << "Exiting auto shop. All is forgotten.\n";
}