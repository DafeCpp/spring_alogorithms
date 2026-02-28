#include <gtest/gtest.h>

#include <findeq.hpp>
#include <vector>

TEST(SumOfTwo, Simple) {
  std::vector<int> v ={ 2,7,11,15};
  ASSERT_EQ(findeq(9,4,v),std::make_pair(2,7));  // Stack []
}


TEST(SumOfTwo, WrongAns) {
  ASSERT_EQ(findeq(1000,4,{0,4,5,9}),std::make_pair(-1,-1));
}
TEST(SumOfTwo, EmptyCont){
  ASSERT_EQ(findeq(10,0,{}),std::make_pair(-1,-1));
}

TEST(SumOfTwo,Hard){
  ASSERT_EQ(findeq(100,10,{0,10,15,20,25,30,40,50,75,95}),std::make_pair(25,75));
}