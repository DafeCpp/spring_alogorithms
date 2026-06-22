#include <iostream>
#include <string>

#include "FindAnagramIndex.h"

int main() {
  std::string s, p;
  if (!(std::cin >> s)) return 0;
  if (!(std::cin >> p)) return 0;
  int res = FindAnagramIndex(s, p);
  std::cout << res << '\n';
  return 0;
}
