#include <cstring>
#include <iostream>

void PrintArray1D(int arr[], size_t size);
int RemoveDuplicateValues(int in_arr[], size_t in_arr_len, int out_arr[],
                          size_t* out_arr_len);

int main() {
  int arr1[] = {1, 2, 3, 3, 3, 4, 4, 5, 5, 5};
  size_t arr1_len = sizeof(arr1) / sizeof(arr1[0]);
  int tmp_arr[arr1_len] = {0};
  size_t new_arr_size = 0;

  int result = RemoveDuplicateValues(arr1, arr1_len, tmp_arr, &new_arr_size);

  int new_arr[new_arr_size] = {0};
  memcpy(new_arr, tmp_arr, new_arr_size * sizeof(int));

  PrintArray1D(new_arr, new_arr_size);
  std::cout << "\n";
}

void PrintArray1D(int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
}

int RemoveDuplicateValues(int in_arr[], size_t in_arr_len, int out_arr[],
                          size_t* out_arr_len) {
  if (0 == in_arr_len) {
    std::cout << "Error! Zero size input array.\n";
    return -1;
  }

  int tmp_arr[in_arr_len] = {0};
  size_t tmp_arr_iter = 0;

  for (size_t i = 0; i < in_arr_len; i++) {
    if (0 == i) {
      tmp_arr[tmp_arr_iter] = in_arr[i];
      tmp_arr_iter++;
    } else {
      if (in_arr[i] == in_arr[i - 1]) {
        continue;
      } else {
        tmp_arr[tmp_arr_iter] = in_arr[i];
        tmp_arr_iter++;
      }
    }
  }

  memcpy(out_arr, tmp_arr, tmp_arr_iter * sizeof(int));
  *out_arr_len = tmp_arr_iter;
  return 0;
}
