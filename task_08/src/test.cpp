
#include <gtest/gtest.h>

#include <random>

#include "hashtable.hpp"

TEST(Hashtable, Simple) {
  Hashmap map;

  map[0] = 0;

  ASSERT_EQ(map[0], 0);

  map[1] = 1;
  map[2] = 2;

  ASSERT_EQ(map[1], 1);
  ASSERT_EQ(map[2], 2);
}

TEST(Hashtable, SimpleOverwrite) {
  Hashmap map;

  map[0] = 0;

  ASSERT_EQ(map[0], 0);

  map[1] = 1;
  map[2] = 2;

  ASSERT_EQ(map[1], 1);
  ASSERT_EQ(map[2], 2);

  map[0] = -1;

  ASSERT_EQ(map[0], -1);

  map[1] = -2;
  map[2] = -3;

  ASSERT_EQ(map[1], -2);
  ASSERT_EQ(map[2], -3);
}

TEST(Hashtable, SimpleNegative) {
  Hashmap map;

  map[-15] = -15;

  ASSERT_EQ(map[-15], -15);
}

TEST(Hashtable, Longer) {
  Hashmap map;

  for (uint i = 0; i < 100; ++i) map[i] = i;

  for (uint i = 0; i < 100; ++i) ASSERT_EQ(map[i], i) << "Wrong at i=" << i;
}

TEST(Hashtable, SimpleErase) {
  Hashmap map;

  map[0] = 0;
  map[1] = 1;
  map[2] = 2;

  ASSERT_EQ(map[2], 2);

  map.Erase(2);

  ASSERT_EQ(map[2], 0);
}

TEST(Hashtable, EraseDefaultValue) {
  Hashmap map(13);

  map[0] = 0;

  ASSERT_EQ(map[0], 0);

  map[1] = 1;
  map[2] = 2;

  ASSERT_EQ(map[1], 1);
  ASSERT_EQ(map[2], 2);

  map.Erase(2);

  ASSERT_EQ(map[2], 13);
}

TEST(Hashtable, RandomDense) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist(-100, 100);

  Hashmap map;
  std::vector<int> samples;

  for (uint i = 0; i < 100000; ++i) {
    int val = dist(rng);
    map[i] = val;
    samples.push_back(val);
  }
  for (uint i = 0; i < 100000; ++i)
    ASSERT_EQ(map[i], samples[i]) << "wrong value at i=" << i;
}

TEST(Hashtable, RandomSparce) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist(-1000000, 1000000);

  Hashmap map;
  std::vector<int> samples;

  for (uint i = 0; i < 100000; ++i) {
    int val = dist(rng);
    map[i] = val;
    samples.push_back(val);
  }
  for (uint i = 0; i < 100000; ++i)
    ASSERT_EQ(map[i], samples[i]) << "wrong value at i=" << i;
}

TEST(Hashtable, RandomRandom) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist(-1000000, 1000000);
  std::uniform_int_distribution<int> dist_sample(0, 10000 - 1);

  Hashmap map;
  std::vector<int> samples(10000);

  for (uint i = 0; i < 100000; ++i) {
    int val = dist(rng);
    int sample = dist_sample(rng);
    map[sample] = val;
    samples[sample] = (val);
  }
  for (uint i = 0; i < 10000; ++i)
    ASSERT_EQ(map[i], samples[i]) << "wrong value at i=" << i;
}
