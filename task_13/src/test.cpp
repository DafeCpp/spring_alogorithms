#include <gtest/gtest.h>
#include "schedule.hpp"

TEST(ScheduleTest, Example1) {
    std::vector<Lesson> lessons = {
        {9.0, 10.0},
        {9.3, 10.3},
        {10.0, 11.0},
        {10.3, 11.3},
        {11.0, 12.0}
    };
    
    std::vector<Lesson> expected = {
        {9.0, 10.0},
        {10.0, 11.0},
        {11.0, 12.0}
    };
    
    std::vector<Lesson> result = selectLessons(lessons);
    
    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_DOUBLE_EQ(result[i].start, expected[i].start);
        ASSERT_DOUBLE_EQ(result[i].end, expected[i].end);
    }
}

TEST(ScheduleTest, NoOverlap) {
    std::vector<Lesson> lessons = {
        {1.0, 2.0},
        {2.0, 3.0},
        {3.0, 4.0}
    };
    
    std::vector<Lesson> result = selectLessons(lessons);
    ASSERT_EQ(result.size(), 3);
}


TEST(ScheduleTest, EmptyInput) {
    std::vector<Lesson> lessons = {};
    std::vector<Lesson> result = selectLessons(lessons);
    ASSERT_EQ(result.size(), 0);
}

TEST(ScheduleTest, ComplexSchedule) {
    std::vector<Lesson> lessons = {
        {1.0, 3.0},
        {2.0, 4.0},
        {3.0, 5.0},
        {4.0, 6.0},
        {5.0, 7.0}
    };
    
    std::vector<Lesson> result = selectLessons(lessons);
    ASSERT_EQ(result.size(), 3);
    ASSERT_DOUBLE_EQ(result[0].start, 1.0);
    ASSERT_DOUBLE_EQ(result[0].end, 3.0);
    ASSERT_DOUBLE_EQ(result[1].start, 3.0);
    ASSERT_DOUBLE_EQ(result[1].end, 5.0);
    ASSERT_DOUBLE_EQ(result[2].start, 5.0);
    ASSERT_DOUBLE_EQ(result[2].end, 7.0);
}

TEST(ScheduleTest, EqualEnds) {
    std::vector<Lesson> lessons = {
        {1.0, 5.0},
        {2.0, 5.0},
        {3.0, 5.0}
    };
    
    std::vector<Lesson> result = selectLessons(lessons);
    ASSERT_EQ(result.size(), 1);
    ASSERT_DOUBLE_EQ(result[0].start, 1.0);
    ASSERT_DOUBLE_EQ(result[0].end, 5.0);
}

TEST(ScheduleTest, ZeroDuration) {
    std::vector<Lesson> lessons = {
        {1.0, 1.0},
        {1.0, 2.0},
        {2.0, 2.0}
    };
    
    std::vector<Lesson> result = selectLessons(lessons);
    ASSERT_EQ(result.size(), 3);
}
