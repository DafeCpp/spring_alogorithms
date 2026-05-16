#include "permutation_substring.h"

#include <array>

int FindPermutationSubstringStart(const std::string& text,
                                  const std::string& pattern) {
  if (pattern.size() > text.size()) {
    return -1;
  }

  std::array<int, 26> pattern_counts{};
  std::array<int, 26> window_counts{};

  for (const char ch : pattern) {
    ++pattern_counts[ch - 'a'];
  }

  for (size_t i = 0; i < pattern.size(); ++i) {
    ++window_counts[text[i] - 'a'];
  }

  if (window_counts == pattern_counts) {
    return 1;
  }

  for (size_t right = pattern.size(); right < text.size(); ++right) {
    --window_counts[text[right - pattern.size()] - 'a'];
    ++window_counts[text[right] - 'a'];
    if (window_counts == pattern_counts) {
      return static_cast<int>(right - pattern.size() + 2);
    }
  }

  return -1;
}
