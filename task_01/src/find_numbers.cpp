#include "find_numbers.hpp"

std::vector<int> FindNumberOfamount(std::vector<int> vec, int summa) {
  if (vec.empty()) {
    throw std::runtime_error("Vector is empty");
  }
  int start_iterator{0};
  int end_iterator{vec.size() - 1};
  std::vector<int> result;
  while (true) {
    if (vec[start_iterator] + vec[end_iterator] == summa) {
      result.push_back(vec[start_iterator]);
      result.push_back(vec[end_iterator]);
      return result;
    }
    if (vec[start_iterator] + vec[end_iterator] < summa) {
      start_iterator++;
    }
    if (vec[start_iterator] + vec[end_iterator] > summa) {
      end_iterator--;
    }
    if (start_iterator == end_iterator) {
      throw std::runtime_error("Sum not found");
    }
  }
}