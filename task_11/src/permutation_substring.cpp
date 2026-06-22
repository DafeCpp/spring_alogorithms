#include "permutation_substring.hpp"

#include <array>

int FindPermutationSubstring(const std::string& text,
                             const std::string& pattern) {
  if (pattern.empty()) {
    return 1;
  }
  if (pattern.size() > text.size()) {
    return -1;
  }

  std::array<int, 26> need{};
  std::array<int, 26> window{};
  for (char letter : pattern) {
    ++need[letter - 'a'];
  }

  for (int index = 0; index < static_cast<int>(text.size()); ++index) {
    ++window[text[index] - 'a'];
    if (index >= static_cast<int>(pattern.size())) {
      --window[text[index - pattern.size()] - 'a'];
    }
    if (index + 1 >= static_cast<int>(pattern.size()) && window == need) {
      return index - static_cast<int>(pattern.size()) + 2;
    }
  }

  return -1;
}
