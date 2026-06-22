#include "hash_table.hpp"

#include <stdexcept>

void HashTable::Insert(int key, int value) {
  if ((size_ + 1.0) / table_.size() > kMaxLoadFactor) {
    Rehash(table_.size() * 2);
  }

  std::size_t first_deleted = table_.size();
  for (std::size_t attempt = 0; attempt < table_.size(); ++attempt) {
    const std::size_t slot = (Hash(key) + attempt) % table_.size();
    if (table_[slot].state == State::kOccupied && table_[slot].key == key) {
      table_[slot].value = value;
      return;
    }
    if (table_[slot].state == State::kDeleted &&
        first_deleted == table_.size()) {
      first_deleted = slot;
    }
    if (table_[slot].state == State::kEmpty) {
      const std::size_t target =
          first_deleted == table_.size() ? slot : first_deleted;
      table_[target] = Entry{key, value, State::kOccupied};
      ++size_;
      return;
    }
  }

  Rehash(table_.size() * 2);
  Insert(key, value);
}

int HashTable::Get(int key) const {
  const std::size_t slot = FindSlot(key);
  if (slot == table_.size()) {
    throw std::out_of_range("key is not found");
  }
  return table_[slot].value;
}

void HashTable::Remove(int key) {
  const std::size_t slot = FindSlot(key);
  if (slot != table_.size()) {
    table_[slot].state = State::kDeleted;
    --size_;
  }
}

bool HashTable::Contains(int key) const {
  return FindSlot(key) != table_.size();
}

std::size_t HashTable::Hash(int key) const {
  std::size_t value = static_cast<std::size_t>(key);
  value ^= value >> 16;
  value *= 0x9e3779b1U;
  value ^= value >> 13;
  return value;
}

std::size_t HashTable::FindSlot(int key) const {
  for (std::size_t attempt = 0; attempt < table_.size(); ++attempt) {
    const std::size_t slot = (Hash(key) + attempt) % table_.size();
    if (table_[slot].state == State::kEmpty) {
      return table_.size();
    }
    if (table_[slot].state == State::kOccupied && table_[slot].key == key) {
      return slot;
    }
  }
  return table_.size();
}

void HashTable::Rehash(std::size_t new_capacity) {
  std::vector<Entry> old_table = std::move(table_);
  table_ = std::vector<Entry>(new_capacity);
  size_ = 0;

  for (const Entry& entry : old_table) {
    if (entry.state == State::kOccupied) {
      Insert(entry.key, entry.value);
    }
  }
}
