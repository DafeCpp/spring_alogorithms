#include "FindAnagramIndex.h"

#include <string>
#include <vector>

int FindAnagramIndex(const std::string& s, const std::string& p) {
  int s_len = s.length();
  int p_len = p.length();

  if (p_len > s_len) {
    return -1;
  }

  std::vector<int> p_count(26, 0);
  std::vector<int> window_count(26, 0);

  for (int i = 0; i < p_len; ++i) {
    p_count[p[i] - 'a']++;
    window_count[s[i] - 'a']++;
  }

  if (p_count == window_count) return 1;

  for (int i = p_len; i < s_len; ++i) {
    window_count[s[i] - 'a']++;
    window_count[s[i - p_len] - 'a']--;

    if (p_count == window_count) return (i - p_len + 2);
  }
  return -1;
}