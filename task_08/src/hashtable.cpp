#include "hashtable.hpp"

#include <random>
#include <vector>

Hashmap::Hashmap(int default_value)
    : size(0),
      cap(8),
      scale(3),
      step_b(13),
      default_value(default_value),
      buzy(cap),
      deleted(cap),
      data(cap) {}

void Hashmap::Double() {
  cap *= 2;
  size = 0;

  std::random_device dev;

  scale = dev() & (cap - 1) | 1;
  step_b = dev() & (cap - 1) | 1;

  std::vector<Entry> new_data(cap);
  std::vector<bool> new_buzy(cap);
  std::vector<bool> new_deleted(cap);

  for (uint i = 0; i < cap / 2; ++i) {
    if (!buzy[i]) continue;

    auto entry = data[i];
    int h = Hash(entry.k);
    while (new_buzy[h]) h = Step(h);

    new_data[h] = entry;
    new_buzy[h] = true;
    ++size;
  }

  data = std::move(new_data);
  buzy = std::move(new_buzy);
  deleted = std::move(new_deleted);
}

int& Hashmap::operator[](int k) {
  if (size * 2 > cap) Double();

  int h = Hash(k);
  while (deleted[h] || (buzy[h] && data[h].k != k)) h = Step(h);

  if (!buzy[h]) {
    data[h].k = k;
    data[h].v = default_value;
    buzy[h] = true;
    size += 1;
  }

  return data[h].v;
}

void Hashmap::Erase(int k) {
  int h = Hash(k);
  while (deleted[h] || (buzy[h] && data[h].k != k)) h = Step(h);

  if (buzy[h]) deleted[h] = true;
}
