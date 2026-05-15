#include <string>
#include <vector>

const std::vector<std::string> num_to_let{"abc", "def",  "ghi", "jkl",
                                          "mno", "pqrs", "tuv", "wxyz"};
constexpr int shift = 2;

void FillingArray(std::vector<int> nums, int index, std::string combination,
                  std::vector<std::string> &result) {
  if (index == nums.size()) {
    result.push_back(combination);
    return;
  }

  std::string new_combination;
  for (char c : num_to_let[nums[index] - shift]) {
    new_combination = combination + c;
    FillingArray(nums, index + 1, new_combination, result);
  }
}

std::vector<std::string> GetCombinations(std::string digits) {
  std::vector<int> nums;
  for (char c : digits) {
    if (c >= '2' && c <= '9') {
      nums.push_back(c - '0');
    }
  }
  std::vector<std::string> result;

  if (nums.empty()) return result;

  std::string combination;
  int index = 0;

  FillingArray(nums, index, combination, result);
  return result;
}