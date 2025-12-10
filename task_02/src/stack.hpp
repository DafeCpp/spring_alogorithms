#include <concepts>
#include <stdexcept>
#include <vector>

template <typename T>
concept Comparable = requires(T a, T b) {
  { a < b } -> std::convertible_to<bool>;
};

template <Comparable T>
class Stack {
 public:
  void Push(T k);
  T Pop();

 private:
  std ::vector<T> _data;
};

template <Comparable T>
void Stack<T>::Push(T k) {
  _data.push_back(k);
}

template <Comparable T>
T Stack<T>::Pop() {
  if (_data.size() == 0) throw std::out_of_range("No data in stack");
  T pop_val{_data.back()};
  _data.pop_back();
  return pop_val;
}

template <Comparable T>
class MinStack {
 public:
  void Push(T k);
  T Pop();
  T GetMin();

 private:
  std ::vector<T> _data;
  std ::vector<T> _min_data;
};

template <Comparable T>
void MinStack<T>::Push(T k) {
  if (_min_data.size() == 0)
    _min_data.push_back(k);
  else if (_min_data.back() > k)
    _min_data.push_back(k);
  else
    _min_data.push_back(_min_data.back());
  _data.push_back(k);
}

template <Comparable T>
T MinStack<T>::Pop() {
  if ((_data.size() == 0) || (_min_data.size() == 0))
    throw std::out_of_range("No data in stack");
  T pop_val{_data.back()};
  _data.pop_back();
  _min_data.pop_back();
  return pop_val;
}

template <Comparable T>
T MinStack<T>::GetMin() {
  if (_min_data.size() == 0) throw std::out_of_range("No data in stack");
  return _min_data.back();
}
