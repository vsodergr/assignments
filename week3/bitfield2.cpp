/* Write a function which can encode the information in the given figure:
 * • Speed / 20 (So 1=20km/h, 2=40km/h,...)
 * • Distance / 150 (So 1=150mm, 2=300mm,...)
 * It is a trade off between memory usage and accuracy.
 *
 *           |Speed|Front|Rear|Right|Left|
 * uint16_t: | 1011|  101| 001|  011| 011|
 */

#include <iostream>
#include <vector>

const uint16_t kBitField{0b1011101001011011};

struct FieldMap {
  std::string field_name{};
  uint16_t conversion_factor{};
  uint16_t field_mask{};
  uint8_t n_bits{};
  uint8_t lsb_pos{};
};

/* Apply the data field map to the bit field and print the info. */
void PrintVehicleState(const uint16_t& bit_field,
                       const std::vector<FieldMap>& field_map) {
  /* For each field print its name. Then mask out its bits and shift them to the
   * least significant position, then apply the conversion and print it as an
   * uint16. */
  for (const auto& field : field_map) {
    std::cout << field.field_name << ":\t"
              << (uint16_t)(((bit_field & field.field_mask) >> field.lsb_pos) *
                            field.conversion_factor)
              << "\n";
  }
}

uint16_t SetBitField(const std::vector<int32_t>& values,
                     const std::vector<FieldMap>& field_map) {
  uint16_t bit_field{};

  for (size_t i = 0; i < values.size(); i++) {
    /* Convert the value. */
    uint32_t value{
        (uint32_t)(values.at(i) / field_map.at(i).conversion_factor)};

    /* Shift converted value to position and mask it to fit. */
    uint16_t shifted_bit_value{(uint16_t)((value << field_map.at(i).lsb_pos) &
                                          field_map.at(i).field_mask)};

    /* Or the shifted and masked value into the bit field. */
    bit_field |= shifted_bit_value;
  }

  return bit_field;
}

int main() {
  const std::vector<FieldMap> field_map{{"Vehicle Speed", 20, 0xF000, 4, 12},
                                        {"Front Distance", 150, 0x0E00, 3, 9},
                                        {"Rear Distance", 150, 0x01C0, 3, 6},
                                        {"Right Distance", 150, 0x0038, 3, 3},
                                        {"Left Distance", 150, 0x0007, 3, 0}};

  // std::vector<int32_t> input_values{200, 1050, 150, 300, 600};
  std::vector<int32_t> input_values{120, 400, 610, 30, 120};

  PrintVehicleState(kBitField, field_map);
  std::cout << "\n";

  PrintVehicleState(SetBitField(input_values, field_map), field_map);
}