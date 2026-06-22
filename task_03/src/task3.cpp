#include "task3.hpp"

#include <string>
#include <vector>

std::vector<std::string> letterCombinations(const std::string& digits) {
  if (digits.empty()) return {};

  const std::string phone[10] = {"",    "",    "abc",  "def", "ghi",
                                 "jkl", "mno", "pqrs", "tuv", "wxyz"};

  std::vector<std::string> result = {""};

  for (char digit : digits) {
    std::vector<std::string> temp;
    int num = digit - '0';
    for (const std::string& prefix : result) {
      for (char letter : phone[num]) {
        temp.push_back(prefix + letter);
      }
    }
    result = temp;
  }

  return result;
}