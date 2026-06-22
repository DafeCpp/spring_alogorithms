#include <vector>

std::pair<int, int> find_pair_with_sum(int target_sum, std::vector<int> arr) {
  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    int current_sum = arr[left] + arr[right];

    if (current_sum == target_sum) {
      return std::make_pair(arr[left], arr[right]);
    }

    if (current_sum < target_sum) {
      left++;
    } else {
      right--;
    }
  }

  return {-1, -1};
}