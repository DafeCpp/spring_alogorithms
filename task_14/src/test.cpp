#include <gtest/gtest.h>
#include "table.hpp"

TEST(TableTest, Example1) {
    std::vector<std::vector<int>> table = {
        {1, 2, 3, 5},
        {3, 1, 3, 2},
        {4, 5, 2, 3},
        {5, 5, 3, 2},
        {4, 4, 3, 4}
    };
    
    std::vector<std::pair<int, int>> queries = {
        {1, 1},
        {2, 5},
        {4, 5},
        {3, 5},
        {1, 3},
        {1, 5}
    };
    
    std::vector<std::string> expected = {
        "Yes", "No", "Yes", "Yes", "Yes", "No"
    };
    
    std::vector<std::string> result = processQueries(table, queries);
    
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(TableTest, SingleRow) {
    std::vector<std::vector<int>> table = {
        {1, 2, 3}
    };
    
    std::vector<std::pair<int, int>> queries = {
        {1, 1}
    };
    
    std::vector<std::string> result = processQueries(table, queries);
    ASSERT_EQ(result[0], "Yes");
}

TEST(TableTest, SingleColumn) {
    std::vector<std::vector<int>> table = {
        {1},
        {2},
        {3},
        {2},
        {1}
    };
    
    std::vector<std::pair<int, int>> queries = {
        {1, 3},
        {1, 5},
        {3, 4}
    };
    
    std::vector<std::string> expected = {"Yes", "No", "No"};
    std::vector<std::string> result = processQueries(table, queries);
    
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_EQ(result[i], expected[i]);
    }
}

TEST(TableTest, AllSorted) {
    std::vector<std::vector<int>> table = {
        {1, 5},
        {2, 6},
        {3, 7},
        {4, 8}
    };
    
    std::vector<std::pair<int, int>> queries = {
        {1, 4},
        {2, 3}
    };
    
    std::vector<std::string> expected = {"Yes", "Yes"};
    std::vector<std::string> result = processQueries(table, queries);
    
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_EQ(result[i], expected[i]);
    }
}