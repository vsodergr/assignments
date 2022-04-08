/*
 * Implement a function that can read the information shown in the figure.
 *
 *           |Seat belts|Windows|Doors|Lights|
 * uint16_t: |     10111|   0100| 1011|   011|
 */

#include <iostream>

#define SEAT_DRIVER_MASK 0x8000
#define SEAT_PASSENGER_MASK 0x4000
#define SEAT_REAR_LEFT_MASK 0x2000
#define SEAT_REAR_MIDDLE_MASK 0x1000
#define SEAT_REAR_RIGHT_MASK 0x0800
#define WINDOW_FRONT_LEFT_MASK 0x0400
#define WINDOW_FRONT_RIGHT_MASK 0x0200
#define WINDOW_REAR_LEFT_MASK 0x0100
#define WINDOW_REAR_RIGHT_MASK 0x0080
#define DOOR_FRONT_LEFT_MASK 0x0040
#define DOOR_FRONT_RIGHT_MASK 0x0020
#define DOOR_REAR_LEFT_MASK 0x0010
#define DOOR_REAR_RIGHT_MASK 0x0008
#define LIGHT_HAZARD_MASK 0x0004
#define LIGHT_HEAD_MASK 0x0002
#define LIGHT_FULL_BEAM_MASK 0x0001

const uint16_t kBitfield{0b1011101001011011};

inline std::string StringifyFlagState(bool fs) { return fs ? "true" : "false"; }

// With masked brute force
void PrintVehicleState(uint16_t state) {
  std::cout << "Driver seat occupied: "
            << StringifyFlagState(state & SEAT_DRIVER_MASK) << "\n";
  std::cout << "Passenger seat occupied: "
            << StringifyFlagState(state & SEAT_PASSENGER_MASK) << "\n";
  std::cout << "Rear left seat occupied: "
            << StringifyFlagState(state & SEAT_REAR_LEFT_MASK) << "\n";
  std::cout << "Rear middle seat occupied: "
            << StringifyFlagState(state & SEAT_REAR_MIDDLE_MASK) << "\n";
  std::cout << "Rear right seat occupied: "
            << StringifyFlagState(state & SEAT_REAR_RIGHT_MASK) << "\n";

  std::cout << "Front left window closed: "
            << StringifyFlagState(state & WINDOW_FRONT_LEFT_MASK) << "\n";
  std::cout << "Front right window closed: "
            << StringifyFlagState(state & WINDOW_FRONT_RIGHT_MASK) << "\n";
  std::cout << "Rear left window closed: "
            << StringifyFlagState(state & WINDOW_REAR_LEFT_MASK) << "\n";
  std::cout << "Rear right window closed: "
            << StringifyFlagState(state & WINDOW_REAR_RIGHT_MASK) << "\n";

  std::cout << "Front left door closed: "
            << StringifyFlagState(state & DOOR_FRONT_LEFT_MASK) << "\n";
  std::cout << "Front right door closed: "
            << StringifyFlagState(state & DOOR_FRONT_RIGHT_MASK) << "\n";
  std::cout << "Rear left door closed: "
            << StringifyFlagState(state & DOOR_REAR_LEFT_MASK) << "\n";
  std::cout << "Rear right door closed: "
            << StringifyFlagState(state & DOOR_REAR_RIGHT_MASK) << "\n";

  std::cout << "Hazard light on: "
            << StringifyFlagState(state & LIGHT_HAZARD_MASK) << "\n";
  std::cout << "Headlights on: " << StringifyFlagState(state & LIGHT_HEAD_MASK)
            << "\n";
  std::cout << "Full beam lights on: "
            << StringifyFlagState(state & LIGHT_FULL_BEAM_MASK) << "\n";
}

int main() { PrintVehicleState(kBitfield); }