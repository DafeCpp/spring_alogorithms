#include <string>

int SubstringSearch(const std::string& string, const std::string& substring) {
  if (substring.size() > string.size()) return -1;

  int letters[256] = {0};
  for (char c : substring) ++letters[c];

  int need = substring.length();

  for (int i = 0; i < string.length(); ++i) {
    --letters[string[i]];
    if (letters[string[i]] >= 0) --need;
    if (letters[string[i]] < 0 && need + 1 <= substring.length()) {
      ++need;
      ++letters[string[i]];
    }

    if (need == 0) return i - substring.length() + 2;
  }

  return -1;
}