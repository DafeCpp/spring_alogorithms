#include "solution.hpp"

#include <vector>

int FindSubstring(const std::string &s, const std::string &p) {
  int lenS = s.length();
  int lenP = p.length();
  if (lenP > lenS) return -1;

  std::vector<int> countP(26, 0);
  std::vector<int> windowCount(26, 0);

  for (int i = 0; i < lenP; i++) {
    countP[p[i] - 'a']++;
    windowCount[s[i] - 'a']++;
  }
  if (countP == windowCount) {
    return 1;
  }
  for (int i = lenP; i < lenS; i++) {
    windowCount[s[i] - 'a']++;
    windowCount[s[i - lenP] - 'a']--;
    if (countP == windowCount) {
      return i - lenP + 2;
    }
  }
  return -1;
}