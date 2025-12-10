#include "HashTable.hpp"

#include <functional>
#include <stdexcept>

size_t HashTable::MyHash(const std::string& value) {
  return std::hash<std::string>{}(value) * 0xdeadbeef;
}

HashTable::HashTable() {
  std::vector<Elem> PreparedData(13, ZeroElem);
  data = std::move(PreparedData);
}

void HashTable::Resize() {
  std::vector<Elem> NewData(data.size() * 2, ZeroElem);
  std::vector<Elem> OldData = std::move(data);
  data = std::move(NewData);
  for (auto& elem : OldData) {
    if (elem.CurrentLabel == Label::Full) {
      add(elem.Key, elem.Value);
    }
  }
}

void HashTable::add(const std::string& key, int value) {
  int index = MyHash(key) % data.size();
  int BeginingIndex = index;
  while ((data[index].CurrentLabel != Label::Empty) &&
         (data[index].CurrentLabel != Label::Deleted)) {
    if (data[index].CurrentLabel == Label::Full && data[index].Key == key) {
      data[index].Value = value;
      return;
    }
    ++index;
    if (index >= data.size()) index = 0;
    if (index == BeginingIndex) break;
  }
  data[index].Value = value;
  data[index].Key = key;
  data[index].CurrentLabel = Label::Full;
  ++EngagedSpace;
  if (EngagedSpace > (data.size() / 2)) Resize();
}

void HashTable::remove(const std::string& key) {
  int index = MyHash(key) % data.size();
  int BeginingIndex = index;
  while (data[index].Key != key) {
    ++index;
    if (index >= data.size()) index = 0;
    if (index == BeginingIndex) throw std::runtime_error("ValueError");
  }
  data[index].CurrentLabel = Label::Deleted;
  --EngagedSpace;
}

int HashTable::get(const std::string& key) {
  int index = MyHash(key) % data.size();
  while ((data[index].Key != key) &&
         (data[index].CurrentLabel != Label::Empty)) {
    ++index;
    if (index >= data.size()) index = 0;
  }
  if (data[index].CurrentLabel == Label::Empty) {
    throw std::runtime_error("ValueError");
  } else {
    return data[index].Value;
  }
}