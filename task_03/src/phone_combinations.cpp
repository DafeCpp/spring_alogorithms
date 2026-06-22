#include "phone_combinations.hpp"

#include <array>

std::vector<std::string> BuildPhoneCombinations(const std::string& digits) {
  if (digits.empty()) {
    return {};
  }

  static const std::array<std::string, 10> letters = {
      "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
  };

  std::vector<std::string> combinations{""};
  for (char digit : digits) {
    std::vector<std::string> next;
    for (const std::string& prefix : combinations) {
      for (char letter : letters[digit - '0']) {
        next.push_back(prefix + letter);
      }
    }
    combinations = std::move(next);
  }

  return combinations;
}
