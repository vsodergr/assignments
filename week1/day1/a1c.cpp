#include <iostream>

void PrintArray1D(int arr[], size_t size);
void SwapValues(int* a, int* b);

int main() {
  int lower_value = 0;
  int upper_value = 0;

  std::cout << "Enter two integers between 0-255.\n";
  std::cin >> lower_value;
  std::cin >> upper_value;

  // Safety check on the values.
  if ((-1 < lower_value && lower_value < 256) && (-1 < upper_value && upper_value < 256)) {
    if (lower_value > upper_value) {
      SwapValues(&lower_value, &upper_value);
    }
    std::cout << "You entered " << lower_value << " and " << upper_value << ".\n";
  } else {
    std::cout << "The values you entered are out of range. Exiting.\n";
    return -1;
  }

  // Creating and populating the array of intermediate values.
  size_t arr_size = upper_value - lower_value - 1;
  int arr[arr_size] = {0};
  for (size_t i = 0; i < arr_size; i++) {
    arr[i] = (upper_value - 1 - i);
  }

  std::cout << "Output array: ";
  PrintArray1D(arr, arr_size);
  std::cout << "\n";
  std::cout << "Output array size: " << arr_size << "\n";

  return 0;
}

void PrintArray1D(int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}

void SwapValues(int* a, int* b) {
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}