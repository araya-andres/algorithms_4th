#include "gtest/gtest.h"
#include "lib/ch01/binary_search.hpp"

TEST(rank, ReturnsNotFoundIfTheVectorIsEmpty)
{
    EXPECT_EQ(binary_search::rank(-1, std::vector<int>{}), -1);
}

TEST(rank, WorksProperlyWithASingleValueArray)
{
    const auto v = std::vector{0};
    EXPECT_EQ(binary_search::rank(-1, v), -1);
    EXPECT_EQ(binary_search::rank( 0, v),  0);
    EXPECT_EQ(binary_search::rank( 1, v), -1);
}

TEST(rank, WorksProperlyWithAThreeValuesArray)
{
    const auto v = std::vector{0, 1, 2};
    EXPECT_EQ(binary_search::rank(-1, v), -1);
    EXPECT_EQ(binary_search::rank( 0, v),  0);
    EXPECT_EQ(binary_search::rank( 2, v),  2);
    EXPECT_EQ(binary_search::rank( 3, v), -1);
}

TEST(rank_r, ReturnsNotFoundIfTheVectorIsEmpty)
{
    EXPECT_EQ(binary_search::rank_r(-1, std::vector<int>{}), -1);
}

TEST(rank_r, WorksProperlyWithASingleValueArray)
{
    const auto v = std::vector{0};
    EXPECT_EQ(binary_search::rank_r(-1, v), -1);
    EXPECT_EQ(binary_search::rank_r( 0, v),  0);
    EXPECT_EQ(binary_search::rank_r( 1, v), -1);
}

TEST(rank_r, WorksProperlyWithAThreeValuesArray)
{
    const auto v = std::vector{0, 1, 2};
    EXPECT_EQ(binary_search::rank_r(-1, v), -1);
    EXPECT_EQ(binary_search::rank_r( 0, v),  0);
    EXPECT_EQ(binary_search::rank_r( 2, v),  2);
    EXPECT_EQ(binary_search::rank_r( 3, v), -1);
}