#include "task14.hpp"

#include <string>
#include <vector>

std::vector<std::string> have_ordered(int n, int m, int k,
                                      std::vector<std::vector<int>>& Table,
                                      std::vector<std::vector<int>>& strings) {
  std::vector<std::vector<int>> up(n, std::vector<int>(m, 0));
  std::vector<std::string> result;

  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (Table[j][i] >= Table[j - 1][i]) {
        up[j][i] = up[j - 1][i];
      } else {
        up[j][i] = j;
      }
    }
  }

  int s = 0;

  for (int i = 0; i < k; i++) {
    s = 0;

    for (int j = 0; j < m; j++) {
      if (up[strings[i][0]][j] == up[strings[i][1]][j]) {
        result.push_back("YES");
        s = 1;
        break;
      }
    }

    if (s == 0) {
      result.push_back("NO");
    }
  }

  return result;
}
