#pragma once

#include <cstdio>
#include <vector>
class Hashmap {
 private:
  struct Entry {
    int k;
    int v;
  };
  int size;
  int cap;
  int scale;
  const int step_a = 25;
  int step_b;
  const int default_value;
  std::vector<bool> buzy;
  std::vector<bool> deleted;
  std::vector<Entry> data;

  void Double();
  unsigned int Hash(unsigned int k) { return (scale * k) % cap; }
  unsigned int Step(unsigned int k) { return (step_a * k + step_b) % cap; }

 public:
  Hashmap(int default_value = 0);
  int& operator[](int k);
  void Erase(int k);
};
