#pragma once

#include <string>
#include <vector>

struct Request {
  std::size_t l;
  std::size_t r;
};

class TableAnalyzer {
 public:
  TableAnalyzer(const std::vector<std::vector<int>>& table);

  std::string CheckRange(const Request& request) const;

  std::vector<std::string> CheckRanges(
      const std::vector<Request>& requests) const;

 private:
  std::vector<int> best_;
};