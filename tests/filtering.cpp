#include <list>

#include "gtest/gtest.h"
#include "lib/ch01/filtering.hpp"

TEST(max, EmptyContainer) {
    EXPECT_EQ(filtering::max(std::vector<int>{}), std::nullopt);
}

TEST(max, ContainerWithASingleValue) {
    auto val = filtering::max(std::vector{0});
    EXPECT_TRUE(val.has_value());
    EXPECT_EQ(val.value(), 0);
}

TEST(max, ContainerWithSeveralValues) {
    EXPECT_EQ(filtering::max(std::vector{0, 1, 2}).value(), 2);
}

TEST(min, EmptyContainer) {
    EXPECT_EQ(filtering::min(std::vector<int>{}), std::nullopt);
}

TEST(min, ContainerWithASingleValue) {
    auto val = filtering::min(std::vector{0});
    EXPECT_TRUE(val.has_value());
    EXPECT_EQ(val.value(), 0);
}

TEST(min, ContainerWithSeveralValues) {
    EXPECT_EQ(filtering::min(std::vector{0, 1, 2}).value(), 0);
}

TEST(minmax, ReturnsAPairWithTheMinAndMax) {
    EXPECT_EQ(filtering::minmax(std::vector{0, 1, 2}).value(), std::make_pair(0, 2));
}

TEST(median, EmptyContainer) {
    EXPECT_FALSE(filtering::median(std::list<int>{}).has_value());
}

TEST(median, OddNumberOfObservations)
{
    EXPECT_DOUBLE_EQ(filtering::median(std::list{1, 3, 3, 6, 7, 8, 9}).value(), 6.0);
}

TEST(median, EvenNumberOfObservations)
{
    EXPECT_DOUBLE_EQ(filtering::median(std::list{1, 2, 3, 4, 5, 6, 8, 9}).value(), 4.5);
}

TEST(average, Average)
{
    EXPECT_DOUBLE_EQ(filtering::average(std::vector{1, 2, 3, 4}).value(), 2.5);
}