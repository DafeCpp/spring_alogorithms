#include "tables.hpp"

TableAnalyzer::TableAnalyzer(const std::vector<std::vector<int>>& table) {
  std::size_t N{table.size()};
  std::size_t M{table[0].size()};

  best_.assign(N, 0);

  std::vector<int> reach(N);

  for (std::size_t col{0}; col != M; ++col) {
    reach[N - 1] = N - 1;

    for (long long row{static_cast<long long>(N - 2)}; row >= 0; --row) {
      if (table[row][col] <= table[row + 1][col]) {
        reach[row] = reach[row + 1];
      } else {
        reach[row] = row;
      }
    }

    for (std::size_t row{0}; row != N; ++row) {
      best_[row] = std::max(best_[row], reach[row]);
    }
  }
}

std::string TableAnalyzer::CheckRange(const Request& request) const {
  if (best_[request.l - 1] >= request.r - 1) return "Yes";
  return "No";
}

std::vector<std::string> TableAnalyzer::CheckRanges(
    const std::vector<Request>& requests) const {
  std::vector<std::string> result;
  result.reserve(requests.size());
  for (const auto& request : requests) {
    result.push_back(CheckRange(request));
  }
  return result;
}
