
#include <vector>

std::vector<int> sum_of_two(int S, int N, const std::vector<int>& array) {
  int left_pointer = 0;
  int right_pointer = N - 1;

  while (left_pointer < right_pointer) {
    if (array[left_pointer] + array[right_pointer] == S) {
      std::vector<int> solution = {array[left_pointer], array[right_pointer]};
      return solution;
    }
    if (array[left_pointer] + array[right_pointer] < S) {
      left_pointer++;
    } else {
      right_pointer--;
    }
  }

  std::vector<int> no_solution = {-1};
  return no_solution;
}