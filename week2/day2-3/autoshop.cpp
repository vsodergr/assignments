#include "autoshop.hpp"

#include <sstream>
#include <cassert>

void GetInput(std::string &s) {
  std::cin >> std::ws;
  s = "";
  std::getline(std::cin, s, '\n');
}

void GetInput(int &i) { std::cin >> i; }

void PrintCustomerRecord(std::vector<Customer> &record) {
  int total_cost{};

  std::cout << "Auto Shop Customer Record\n";

  for (auto customer : record) {
    std::cout << "\tCustomer: " << customer.get_name() << "\n";

    for (auto vehicle : customer.get_vehicle_list()) {
      std::cout << "\t\tVehicle: " << vehicle.get_make() << "\n";

      for (auto service : vehicle.get_service_list()) {
        std::cout << "\t\t\tService: " << service.get_service_action()
                  << "\tService cost: " << service.get_cost() << "\n";
        total_cost += service.get_cost();

        for (auto part : service.get_parts()) {
          std::cout << "\t\t\t\tParts: " << part.get_part_type()
                    << "\tPart cost: " << part.get_cost() << "\n";
          total_cost += part.get_cost();
        }
      }
    }

    std::cout << "\tTotal cost of services and parts: " << total_cost << "\n";
    std::cout << "\tCustomer balance: " << customer.get_balance() << "\n";
  }
}

Part::Part(std::string in_type, int in_cost) {
  this->type = in_type;
  this->cost = in_cost;
}

int Part::get_cost() { return this->cost; }

std::string Part::get_part_type() { return this->type; }

Service::Service() {
  std::string srv_action;
  std::cout << "Enter service action performed: ";
  GetInput(srv_action);
  this->action = srv_action;

  int srv_cost;
  std::cout << "Enter work cost of service: ";
  GetInput(srv_cost);
  this->cost = srv_cost;

  this->date = std::time(nullptr);
}

int Service::get_cost() {
  int total{this->cost};
  for (auto part : this->part_list) total += part.get_cost();
  return total;
}

std::string Service::get_service_action() { return this->action; }

std::string Service::get_date_string() {
  tm *t = localtime(&this->date);
  std::stringstream s;
  s << t->tm_year << "-" << t->tm_mon << "-" << t->tm_mday << " " << t->tm_hour
    << ":" << t->tm_min;
  return s.str();
}

std::vector<Part> Service::get_parts() { return this->part_list; }

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
    if (0 != parts_changed.compare("yes")) {
      std::cout << "Please enter \"yes\" or \"no\": ";
      GetInput(parts_changed);
      continue;
    }

    new_service.add_part();
    assert(!new_service.get_parts().empty());

    std::cout << "Did you change any other parts (yes/no)? ";
    GetInput(parts_changed);
  }

  this->service_list.push_back(new_service);
  assert(!this->service_list.empty());
}

std::string Vehicle::get_make() { return this->make; }

std::vector<Service> Vehicle::get_service_list() { return this->service_list; }

Payment::Payment() {
  std::cout << "By what method do you want to pay? ";
  GetInput(this->method);
  std::cout << "Enter the amount to pay: ";
  GetInput(this->amount);
}

std::string Payment::get_method() { return this->method; }

int Payment::get_amount() { return this->amount; }

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
    this->adjust_balance(
        vehicle_list.at(vehicle_idx).get_service_list().back().get_cost() * -1);
  } else {
    std::cout << "The customer has no vehicles to service.\n";
  }
}

std::string Customer::get_name() { return this->name; }

std::vector<Vehicle> Customer::get_vehicle_list() { return this->vehicle_list; }

void Customer::make_payment() {
  Payment new_payment{};
  this->payment_record.push_back(new_payment);

  this->adjust_balance(new_payment.get_amount());

  std::cout << "Balance: " << this->get_balance() << "\n";
  if (this->get_balance() > 0) {
    std::cout << "Thanks for the tip!\n";
  } else if (this->get_balance() < 0) {
    std::cout << "You still owe us money!\n";
  } else {
    std::cout << "Thank you.\n";
  }
}

void Customer::adjust_balance(int adjustment) { this->balance += adjustment; }

int Customer::get_balance() { return this->balance; }

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
      assert(!customer_record.at(customer_idx).get_vehicle_list().empty());

      while (0 != usr_input.compare(kExit)) {
        customer_record.at(customer_idx).add_service(vehicle_idx);

        service_idx++;
        std::cout << "Enter another service for "
                  << customer_record.at(customer_idx).get_name() << "'s "
                  << customer_record.at(customer_idx)
                         .get_vehicle_list()
                         .at(vehicle_idx)
                         .get_make()
                  << " (or type \"exit\" to exit): ";
        GetInput(usr_input);
      }

      service_idx = 0;
      vehicle_idx++;
      std::cout << "Enter another vehicle for "
                << customer_record.at(customer_idx).get_name()
                << " (or type \"exit\" to exit): ";
      GetInput(usr_input);
    }

    std::cout << "Time to pay " << customer_record.at(customer_idx).get_name() << "\n";
    customer_record.at(customer_idx).make_payment();

    vehicle_idx = 0;
    customer_idx++;
    std::cout << "Enter a new customer's name (or type \"exit\" to exit): ";
    GetInput(usr_input);
  }

  PrintCustomerRecord(customer_record);

  /* TODO: Make Payment */

  // delete &usr_input;
  // delete &service_idx;
  // delete &vehicle_idx;
  // delete &customer_idx;
  // delete &customer_record;
  std::cout << "Exiting auto shop. All is forgotten.\n";
}