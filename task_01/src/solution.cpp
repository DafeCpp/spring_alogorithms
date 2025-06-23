#include "solution.hpp"

#include <stdexcept>

// Binary search for greater-or-equal element
// Explicitly requires <left> and <right> bounds to support searching in
// subarray
int BinarySearchGEQ(const std::vector<int>& arr, int target, int left,
                    int right) {
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return left;
}

// Custom error code
struct PairNotFound {};

/*
 *  Algorithm description:
 *  run <left> index over array
 *  search for <right> that is greater or equal to <target - arr[left]>
 *  ! seach range is (<left>, <right>]
 */
std::pair<int, int> FindPairMatchSum(const std::vector<int>& arr, int target) {
  unsigned int left = 0;
  unsigned int right =
      BinarySearchGEQ(arr, target - arr[left], 0, arr.size() - 1);
  while (left < arr.size() - 1 && arr[left] + arr[left + 1] <= target) {
    if (arr[left] + arr[right] == target) return {arr[left], arr[right]};
    left += 1;
    right = BinarySearchGEQ(arr, target - arr[left], left, right);
  }
  throw std::runtime_error("Failed to find suiable pair");
}
