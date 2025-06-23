#pragma once

#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
 public:
  Stack(){};
  Stack(std::vector<T> vec) {
    for (auto val : vec) {
      push(val);
    }
  }
  void push(T value) { data_.push_back(value); }
  T pop() {
    T result = data_.back();
    data_.pop_back();
    return result;
  }

 private:
  std::vector<T> data_;
};

template <typename T>
class MinStack {
 public:
  MinStack(){};
  MinStack(std::vector<T> vec) {
    for (auto val : vec) {
      push(val);
    }
  }
  void push(T value) {
    data_.push_back(value);
    if (data_mins.size() == 0 || value <= data_mins.back()) {
      data_mins.push_back(value);
    } else {
      data_mins.push_back(data_mins.back());
    }
  }
  T pop() {
    T result = data_.back();
    data_.pop_back();
    data_mins.pop_back();
    return result;
  }

  T getmin() {
    if (data_mins.size() == 0) {
      throw std::runtime_error("Пустой стек - нет минимума");
    }
    return data_mins.back();
  }

 private:
  std::vector<T> data_;
  std::vector<T> data_mins;
};

template <typename T>
class MaxStack {
 public:
  MaxStack(){};
  MaxStack(std::vector<T> vec) {
    for (auto val : vec) {
      push(val);
    }
  }
  void push(T value) {
    data_.push_back(value);
    if (data_maxs.size() == 0 || value >= data_maxs.back()) {
      data_maxs.push_back(value);
    } else {
      data_maxs.push_back(data_maxs.back());
    }
  }
  T pop() {
    T result = data_.back();
    data_.pop_back();
    data_maxs.pop_back();
    return result;
  }

  T getmax() {
    if (data_maxs.size() == 0) {
      throw std::runtime_error("Пустой стек - нет минимума");
    }
    return data_maxs.back();
  }

 private:
  std::vector<T> data_;
  std::vector<T> data_maxs;
};