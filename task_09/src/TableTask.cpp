#include "TableTask.hpp"

std::vector<std::string> TaskSolve(int n, int m, int k,
                                   std::vector<std::vector<int>>& table,
                                   std::vector<std::pair<int, int>>& queries) {
  std::vector<std::string> answer;
  std::vector<std::vector<bool>> IsGood(n - 1, std::vector<bool>(m));

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n - 1; ++i) {
      IsGood[i][j] = (table[i][j] <= table[i + 1][j]);
    }
  }

  std::vector<std::vector<int>> prefix(m, std::vector<int>(n));
  for (int j = 0; j < m; ++j) {
    prefix[j][0] = 0;
    for (int i = 1; i < n; ++i) {
      prefix[j][i] = prefix[j][i - 1] + (IsGood[i - 1][j] ? 1 : 0);
    }
  }

  for (auto& query : queries) {
    int l = query.first - 1;
    int r = query.second - 1;

    if (l == r) {
      answer.push_back("Yes");
      continue;
    }

    bool found = false;
    for (int j = 0; j < m; ++j) {
      int cnt = prefix[j][r] - prefix[j][l];
      if (cnt == r - l) {
        found = true;
        break;
      }
    }

    answer.push_back(found ? "Yes" : "No");
  }

  return answer;
}