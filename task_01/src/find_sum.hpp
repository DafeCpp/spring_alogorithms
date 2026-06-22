#pragma once

#include <vector>

struct Result {
  int a{-1};
  int b{-1};
  bool find{false};
};

Result FindSumHash(int sum, std::size_t size, const std::vector<int>& vec);
