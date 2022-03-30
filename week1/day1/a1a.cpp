#include <iostream>

void PrintArray1D(int arr[], size_t size);
void BubbleSort(int *arr, size_t size);

int main() {
  int int_arr[] = {5, 16, -73, 1009, 36};
  // int int_arr[10000] = {0};

  size_t arr_size = sizeof(int_arr) / sizeof(int_arr[0]);

  // for (size_t i = 0; i < arr_size; i++) int_arr[i] = arr_size - (i * 2);

  std::cout << "Created array: ";
  PrintArray1D(int_arr, arr_size);
  std::cout << "\n";

  BubbleSort(int_arr, arr_size);

  std::cout << "Sorted array: ";
  PrintArray1D(int_arr, arr_size);
  std::cout << "\n";
}

void PrintArray1D(int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}

void BubbleSort(int *arr, size_t size) {
  int elem_a;
  int elem_b;
  for (size_t i = 0; i < size; i++) {
    elem_a = arr[i];
    for (int j = i; j < size; j++) {
      elem_b = arr[j];

      if (elem_a > elem_b) {
        arr[i] = elem_b;
        arr[j] = elem_a;
      }
    }
  }
}
