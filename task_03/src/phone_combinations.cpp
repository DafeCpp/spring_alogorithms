#include "./phone_combinations.h"

#include <array>

namespace {

constexpr std::array<const char*, 10> kDigitToLetters = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void BuildCombinations(
    const std::string& digits,
    const size_t index,
    std::string& current,
    std::vector<std::string>& combinations) {
  if (index == digits.size()) {
    combinations.push_back(current);
    return;
  }

  for (const std::string letters = kDigitToLetters[digits[index] - '0'];
       const char letter : letters) {
    current.push_back(letter);
    BuildCombinations(digits, index + 1, current, combinations);
    current.pop_back();
  }
}

}  // namespace

std::vector<std::string> GetPhoneCombinations(const std::string& digits) {
  if (digits.empty()) {
    return {};
  }

  std::vector<std::string> combinations;
  std::string current;
  current.reserve(digits.size());

  BuildCombinations(digits, 0, current, combinations);
  return combinations;
}
