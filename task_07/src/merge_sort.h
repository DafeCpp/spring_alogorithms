#pragma once

#include <cstdint>
#include <vector>

template <typename T>
void Merge(std::vector<T>& data, std::uint64_t left, std::uint64_t mid,
           std::uint64_t right);

template <typename T>
void MergeSort(std::vector<T>& vec, std::uint64_t left, std::uint64_t right);
