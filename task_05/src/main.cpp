#include <algorithm>
#include <iostream>

#include "sorting.hpp"

// template <typename T>
// class Heap {
//  public:
//   Heap() {}
//   void push(T k) {
//     _data.push_back(k);
//     SiftUp(_data);
//   }
//   void print() {
//     for (int i{0}; i < _data.size(); ++i) std ::cout << _data[i] << " ";
//     std ::cout << std ::endl;
//   }
//   void pop() {
//     iter_swap(_data.begin(), _data.begin() + _data.size() - 1);
//     _data.pop_back();
//     SiftDown(_data);
//   }
//   Heap(std ::vector<T> dat) {
//     for (int i{0}; i < dat.size(); ++i) {
//       push(dat[i]);
//     }
//   }
//   int min() { return _data[0]; }

//  private:
//   std ::vector<T> _data;
//   void SiftUp(std ::vector<T>& data);
//   void SiftDown(std ::vector<T>& data);
//   int find_parent(int i) { return ((i - 1) / 2); }
//   int find_childL(int i) { return (2 * i + 1); }
//   int find_childR(int i) { return (2 * i + 2); }
// };

// template <typename T>
// void Heap<T>::SiftUp(std ::vector<T>& data) {  // снизу вверх
//   int index{static_cast<int>(data.size() - 1)};
//   int par_index{find_parent(index)};
//   while (data[index] < data[par_index]) {
//     iter_swap(data.begin() + index, data.begin() + par_index);
//     index = par_index;
//     par_index = find_parent(index);
//   }
// }

// template <typename T>
// void Heap<T>::SiftDown(std ::vector<T>& data) {
//   int index{0};
//   int child{std::min(find_childL(index), find_childR(index))};
//   while (data[child] < data[index]) {
//     iter_swap(data.begin() + index, data.begin() + child);
//     index = child;
//     child = std::min(find_childL(index), find_childR(index));
//   }
// }

int main() {
  // std ::vector<int> unsort{3, 2, 4, 5, 1, 9, 7};
  // std ::vector<int> sorted{1, 2, 3, 4, 5, 7, 9};
  // MergeSort(unsort);
}
