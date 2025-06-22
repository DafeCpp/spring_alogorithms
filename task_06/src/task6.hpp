#ifndef TASK6_HPP
#define TASK6_HPP

#include <vector>

int SearchNstat(std::vector<int> vec, int N) 
{
  int pivot{vec.back()};
  std::vector<int> left_arr;
  std::vector<int> right_arr;
  for (int i{0}; i < vec.size()-1; ++i){
    if (vec[i] <= pivot){
      left_arr.push_back(vec[i]);
    } else {
      right_arr.push_back(vec[i]);
    }
  }
  int pivot_index{left_arr.size()};
  if (pivot_index == N){
    return pivot;
  }
  if (pivot_index > N){
    return SearchNstat(left_arr, N);
  } else {
    return SearchNstat(right_arr, N - pivot_index - 1);
  }
}

#endif // TASK6_HPP