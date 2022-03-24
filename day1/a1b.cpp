#include <iostream>

void PrintArray1D(int arr[], size_t size);
void SelectionSort(int *arr, size_t size);

int main() {
  int int_arr[] = {5, 16, -73, 1009, 36};
  // int int_arr[10000] = {0};

  size_t arr_size = sizeof(int_arr) / sizeof(int_arr[0]);

  // for (size_t i = 0; i < arr_size; i++) int_arr[i] = arr_size - (i * 2);

  std::cout << "Created array: ";
  PrintArray1D(int_arr, arr_size);
  std::cout << "\n";

  SelectionSort(int_arr, arr_size);

  std::cout << "Sorted array: ";
  PrintArray1D(int_arr, arr_size);
  std::cout << "\n";
}

void PrintArray1D(int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}

void SelectionSort(int *arr, size_t size) {
  int min_idx;
  for (size_t i = 0; i < size - 1; i++) {
    min_idx = i;
    for (size_t j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
      int tmp = arr[min_idx];
      arr[min_idx] = arr[i];
      arr[i] = tmp;
    }
  }
}
