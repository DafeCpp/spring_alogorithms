#include "task11.hpp"

#include <map>
#include <string>

int func(std::string S, std::string P) {
  int len_P = P.size();
  int len_S = S.size();

  if (len_P > len_S) return -1;

  std::map<char, int> lib;
  for (char c : P) {
    lib[c]--;
  }

  for (int j = 0; j < len_P; j++) {
    lib[S[j]]++;
    if (lib[S[j]] == 0) lib.erase(S[j]);
  }
  if (lib.size() == 0) return 1;

  for (int i = len_P; i < len_S; i++) {
    lib[S[i - len_P]]--;
    if (lib[S[i - len_P]] == 0) lib.erase(S[i - len_P]);

    lib[S[i]]++;
    if (lib[S[i]] == 0) lib.erase(S[i]);
    if (lib.size() == 0) return i - len_P + 2;
  }

  return -1;
}