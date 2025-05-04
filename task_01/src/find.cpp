#include "find.hpp"

std ::vector<int> FindNums(int k, std ::vector<int> sequence) {
  if (sequence.size() == 0) throw NoSumNum{};

  std ::vector<int> answer;
  unsigned long left_index{0};
  unsigned long right_index{sequence.size() - 1};
  while (left_index != right_index) {
    if ((sequence[left_index] + sequence[right_index]) == k) {
      answer.push_back(sequence[left_index]);
      answer.push_back(sequence[right_index]);
      return answer;
    } else if (sequence[left_index] + sequence[right_index] > k)
      --right_index;
    else
      ++left_index;
  }
  throw NoSumNum{};
}