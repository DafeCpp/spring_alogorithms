#include "hash_table.hpp"

#include <stdexcept>
#include <utility>

const int HashTable::kDefaultCapacity = 8;
const double HashTable::kMaxLoadFactor = 0.75;
const unsigned int HashTable::kHashPrime = 2654435761u;

HashTable::HashTable() : HashTable(kDefaultCapacity) {}

HashTable::HashTable(int initial_capacity)
    : buckets_(initial_capacity > 0 ? initial_capacity : kDefaultCapacity),
      size_(0) {}

int HashTable::BucketIndex(int key, int capacity) const {
  unsigned int hashed = static_cast<unsigned int>(key);

  hashed *= kHashPrime;

  return static_cast<int>(hashed % capacity);
}

void HashTable::Rehash() {
  int new_capacity = static_cast<int>(buckets_.size()) * 2;
  std::vector<Bucket> new_buckets(new_capacity);

  for (std::size_t i = 0; i != buckets_.size(); ++i) {
    for (std::size_t j = 0; j != buckets_[i].size(); ++j) {
      int index{BucketIndex(buckets_[i][j].first, new_capacity)};
      new_buckets[index].push_back(buckets_[i][j]);
    }
  }

  buckets_ = std::move(new_buckets);
}

void HashTable::Insert(int key, int value) {
  int index = BucketIndex(key, buckets_.size());

  for (std::size_t i = 0; i != buckets_[index].size(); ++i) {
    if (buckets_[index][i].first == key) {
      buckets_[index][i].second = value;
      return;
    }
  }

  double load_factor =
      static_cast<double>(size_ + 1) / static_cast<double>(buckets_.size());

  if (load_factor > kMaxLoadFactor) {
    Rehash();
    index = BucketIndex(key, buckets_.size());
  }

  buckets_[index].push_back(std::pair<int, int>(key, value));
  ++size_;
}

int HashTable::Get(int key) const {
  int index = BucketIndex(key, buckets_.size());

  for (std::size_t i = 0; i != buckets_[index].size(); ++i) {
    if (buckets_[index][i].first == key) {
      return buckets_[index][i].second;
    }
  }

  throw std::out_of_range("Key not found");
}

void HashTable::Remove(int key) {
  int index = BucketIndex(key, buckets_.size());

  for (std::size_t i = 0; i != buckets_[index].size(); ++i) {
    if (buckets_[index][i].first == key) {
      buckets_[index].erase(buckets_[index].begin() + i);
      --size_;
      return;
    }
  }
}

bool HashTable::Contains(int key) const {
  int index = BucketIndex(key, buckets_.size());

  for (std::size_t i = 0; i != buckets_[index].size(); ++i) {
    if (buckets_[index][i].first == key) {
      return true;
    }
  }

  return false;
}

int HashTable::Size() const { return size_; }

bool HashTable::Empty() const { return size_ == 0; }