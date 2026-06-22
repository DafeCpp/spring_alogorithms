
#include <string>
#include <vector>

int find_index(const std::string& S, const std::string& P) {
  int sl = S.length();
  int pl = P.length();

  if (pl > sl) {
    return -1;
  }

  std::vector<int> Sset(26, 0);
  std::vector<int> Pset(26, 0);

  for (int i = 0; i < pl; i++) {
    Sset[S[i] - 'a']++;
    Pset[P[i] - 'a']++;
  }

  for (int i = 0; i < sl - pl + 1; i++) {
    for (int t = 0; t < 26; t++) {
      if (Pset[t] != Sset[t]) {
        break;
      }
      if (t == 25) {
        return i;
      }
    }
    if (i < sl - pl) {
      Sset[S[i] - 'a']--;
      Sset[S[i + pl] - 'a']++;
    }
  }
  return -1;
}
