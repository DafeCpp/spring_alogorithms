#include "find_subsequence.hpp"

#include <unordered_map>

int FindSubsequence(const std::string& sequence,
                    const std::string& subsequence) {
  std::unordered_map<char, std::size_t> target;
  for (auto elem : subsequence) {
    target[elem] += 1;
  }
  std::unordered_map<char, std::size_t> current_window;
  for (std::size_t i{0}; i != sequence.size(); ++i) {
    current_window[sequence[i]] += 1;

    if (i >= subsequence.size()) {
      char removed_char = sequence[i - subsequence.size()];
      current_window[removed_char] -= 1;

      if (current_window[removed_char] == 0) current_window.erase(removed_char);
    }

    if (current_window == target) {
      return i + 2 - subsequence.size();
    }
  }
  return -1;
}