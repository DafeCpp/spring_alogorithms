#ifndef HOMEWORKS_MERGESORT_H
#define HOMEWORKS_MERGESORT_H

#endif  // HOMEWORKS_MERGESORT_H

#pragma once

#include <cstdint>
#include <vector>

template <typename T>
void merge(std::vector<T>& data, std::uint64_t left, std::uint64_t mid,
           std::uint64_t right);

template <typename T>
void mergeSort(std::vector<T>& vec, std::uint64_t left, std::uint64_t right);
