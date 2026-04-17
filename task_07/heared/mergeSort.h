#ifndef HOMEWORKS_MERGESORT_H
#define HOMEWORKS_MERGESORT_H

#endif  // HOMEWORKS_MERGESORT_H

#pragma once
#include <iostream>
#include <vector>

template <typename T>
void merge(
  std::vector<int>& data,
  uint64_t left,
  uint64_t mid,
  uint64_t right
  );

template <typename T>
void mergeSort(
  std::vector<T>& vec,
  uint64_t left,
  uint64_t right
  );