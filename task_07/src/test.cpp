
#include <gtest/gtest.h>

#include <chrono>
#include <random>
#include <vector>

#include "KDtree.hpp"

std::vector<Point> GenerateRandomPoints(size_t count, double min = 0.0,
                                          double max = 1000.0) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(min, max);

  std::vector<Point> points;
  points.reserve(count);
  for (size_t i = 0; i < count; ++i) {
    points.emplace_back(dist(gen), dist(gen));
  }
  return points;
}

TEST(KD3, Simple) {
  std::vector<Point> cloud = {
      Point(1.0, 2.0), Point(3.0, 4.0),  Point(5.0, 6.0),
      Point(7.0, 8.0), Point(9.0, 10.0),
  };

  KDTree tree(cloud);

  Point k = tree.NearestPoint(Point(4.8, 5.9));
  ASSERT_EQ(k, Point(5.0, 6.0));
}

TEST(KD3, SameDistanse) {
  std::vector<Point> cloud = {
      Point(0.0, 0.0),  Point(1.0, 0.0),  Point(0.0, 1.0),
      Point(-1.0, 0.0), Point(0.0, -1.0),
  };

  KDTree tree(cloud);

  Point k = tree.NearestPoint(Point(0.0, 0.0));
  ASSERT_EQ(k, Point(0.0, 0.0));
}

TEST(KD3, OneLine) {
  std::vector<Point> cloud = {
      Point(1.0, 1.0), Point(1.0, 2.0), Point(1.0, 3.0),
      Point(1.0, 4.0), Point(1.0, 5.0),
  };

  KDTree tree(cloud);

  Point k = tree.NearestPoint(Point(1.2, 3.1));
  ASSERT_EQ(k, Point(1.0, 3.0));
}

TEST(KD3, Dublicates) {
  std::vector<Point> cloud = {
      Point(2.0, 2.0), Point(2.0, 2.0), Point(3.0, 3.0),
      Point(2.0, 2.0), Point(4.0, 4.0),
  };

  KDTree tree(cloud);

  Point k = tree.NearestPoint(Point(2.1, 2.1));
  ASSERT_EQ(k, Point(2.0, 2.0));
}

TEST(KD3, Error) {
  std::vector<Point> cloud(0);
  EXPECT_THROW(KDTree tree(cloud), std::invalid_argument);
}

TEST(KD3, TimeTest_1000) {
  auto cloud = GenerateRandomPoints(1000);

  auto start = std::chrono::high_resolution_clock::now();
  KDTree tree(cloud);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  EXPECT_TRUE(duration.count() < 500);
}

TEST(KD3, TimeTest_10000) {
  auto cloud = GenerateRandomPoints(10000);

  auto start = std::chrono::high_resolution_clock::now();
  KDTree tree(cloud);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  EXPECT_TRUE(duration.count() < 500);
}

TEST(KD3, TimeTest_1M) {
  auto cloud = GenerateRandomPoints(1000000);

  auto start = std::chrono::high_resolution_clock::now();
  KDTree tree(cloud);
  auto end = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  EXPECT_TRUE(duration.count() < 5000);
}

TEST(KD3, TimeTest_10M) {
  auto cloud = GenerateRandomPoints(10'000'000);

  KDTree tree(cloud);
  auto start = std::chrono::high_resolution_clock::now();

  tree.NearestPoint(Point(3.75, 2.1));
  auto end = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  EXPECT_TRUE(duration.count() < 20000);
}