#include "solution.hpp"
const std::vector<std::string> Keypad = {"",    "",    "abc",  "def", "ghi",
                                         "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(const std::string &digits, int index, std::string &current,
               std::vector<std::string> &result) {
  if (index == digits.length()) {
    result.push_back(current);
    return;
  }
  int digit = digits[index] - '0';
  const std::string &letters = Keypad[digit];
  for (char c : letters) {
    current.push_back(c);
    backtrack(digits, index + 1, current, result);
    current.pop_back();
  }
}

std::vector<std::string> LetterCombinations(const std::string &digits) {
  std::vector<std::string> result;
  std::string current = "";
  backtrack(digits, 0, current, result);
  return result;
}
