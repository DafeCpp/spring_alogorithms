#include "hash_table.h"

#include <ranges>
#include <stdexcept>

HashTable::HashTable() : buckets_(16) {}

size_t HashTable::GetBucketIndex(const int key) const {
  return static_cast<size_t>(key >= 0 ? key : -static_cast<long long>(key)) %
         buckets_.size();
}

void HashTable::RehashIfNeeded() {
  if (size_ * 4 < static_cast<int>(buckets_.size()) * 3) {
    return;
  }

  std::vector<std::vector<std::pair<int, int>>> new_buckets(buckets_.size() *
                                                            2);
  for (const auto& bucket : buckets_) {
    for (const auto& [key, value] : bucket) {
      const size_t index =
          static_cast<size_t>(key >= 0 ? key : -static_cast<long long>(key)) %
          new_buckets.size();
      new_buckets[index].push_back({key, value});
    }
  }
  buckets_.swap(new_buckets);
}

void HashTable::Insert(int key, int value) {
  const size_t index = GetBucketIndex(key);
  for (auto& [stored_key, stored_value] : buckets_[index]) {
    if (stored_key == key) {
      stored_value = value;
      return;
    }
  }

  buckets_[index].push_back({key, value});
  ++size_;
  RehashIfNeeded();
}

int HashTable::Get(const int key) const {
  for (const size_t index = GetBucketIndex(key);
       const auto& [stored_key, stored_value] : buckets_[index]) {
    if (stored_key == key) {
      return stored_value;
    }
  }
  throw std::out_of_range("Key not found");
}

void HashTable::Remove(const int key) {
  const size_t index = GetBucketIndex(key);
  auto& bucket = buckets_[index];
  for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    if (it->first == key) {
      bucket.erase(it);
      --size_;
      return;
    }
  }
}

bool HashTable::Contains(const int key) const {
  for (const size_t index = GetBucketIndex(key);
       const auto& stored_key : buckets_[index] | std::views::keys) {
    if (stored_key == key) {
      return true;
    }
  }
  return false;
}
