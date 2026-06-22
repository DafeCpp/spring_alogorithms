

#include <vector>

int find_index(int N, std::vector<int>& array) {
  int left_pointer = 0;
  int right_pointer = N - 1;
  int mid_pointer = 0;

  while (right_pointer - left_pointer > 1) {
    mid_pointer = (right_pointer + left_pointer) / 2;
    if (array[mid_pointer] == 0) {
      left_pointer = mid_pointer;
    }
    if (array[mid_pointer] == 1) {
      right_pointer = mid_pointer;
    }
  }

  return left_pointer;
}
