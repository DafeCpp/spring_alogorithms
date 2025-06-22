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
  void Push(T value) { data_.push_back(value); }
  T Pop() {
    T result = data_.back();
    data_.pop_back();
    return result;
  }

  int Size() { return data_.size(); }

  bool IsEmpty() { return data_.empty(); }

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
  void Push(T value) {
    data_.push_back(value);
    if (data_mins_.size() == 0 || value <= data_mins_.back()) {
      data_mins_.push_back(value);
    } else {
      data_mins_.push_back(data_mins_.back());
    }
  }
  T Pop() {
    T result = data_.back();
    data_.pop_back();
    data_mins_.pop_back();
    return result;
  }

  T GetMin() {
    if (data_mins_.size() == 0) {
      throw std::runtime_error("Пустой стек - нет минимума");
    }
    return data_mins_.back();
  }

  int Size() { return data_.size(); }

  bool IsEmpty() { return data_.empty(); }

 private:
  std::vector<T> data_;
  std::vector<T> data_mins_;
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
  void Push(T value) {
    data_.push_back(value);
    if (data_maxs.size() == 0 || value >= data_maxs.back()) {
      data_maxs.push_back(value);
    } else {
      data_maxs.push_back(data_maxs.back());
    }
  }
  T Pop() {
    T result = data_.back();
    data_.pop_back();
    data_maxs.pop_back();
    return result;
  }

  T GetMax() {
    if (data_maxs.size() == 0) {
      throw std::runtime_error("Пустой стек - нет минимума");
    }
    return data_maxs.back();
  }

  int Size() { return data_.size(); }

  bool IsEmpty() { return data_.empty(); }

 private:
  std::vector<T> data_;
  std::vector<T> data_maxs;
};