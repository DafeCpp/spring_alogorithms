#pragma once
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> fun(int sum, const vector<int>& vec) {
  /* if (vec.size()<2) throw "Размер маленький!!!";*/
  if (vec.size() < 2) return make_pair(0, 0);
  int left = 0;
  int right = vec.size() - 1;
  while (left < right) {
    if ((vec[left] + vec[right]) == sum)
      return make_pair(vec[left], vec[right]);
    if ((vec[left] + vec[right]) > sum)
      right -= 1;
    else
      left += 1;
  }
  return make_pair(-1, -1);
}