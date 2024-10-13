#include "gtest/gtest.h"
#include "lib/ch01/binary_search.hpp"

TEST(rank, ReturnsNotFoundIfTheVectorIsEmpty)
{
    EXPECT_EQ(binary_search::rank(-1, {}), -1);
}

TEST(rank, WorksProperlyWithASingleValueArray)
{
    EXPECT_EQ(binary_search::rank(-1, {0}), -1);
    EXPECT_EQ(binary_search::rank( 0, {0}),  0);
    EXPECT_EQ(binary_search::rank( 1, {0}), -1);
}

TEST(rank, WorksProperlyWithAThreeValuesArray)
{
    const auto a = std::vector{0, 1, 2};
    EXPECT_EQ(binary_search::rank(-1, a), -1);
    EXPECT_EQ(binary_search::rank( 0, a),  0);
    EXPECT_EQ(binary_search::rank( 2, a),  2);
    EXPECT_EQ(binary_search::rank( 3, a), -1);
}

TEST(rank_r, ReturnsNotFoundIfTheVectorIsEmpty)
{
    EXPECT_EQ(binary_search::rank_r(-1, {}), -1);
}

TEST(rank_r, WorksProperlyWithASingleValueArray)
{
    EXPECT_EQ(binary_search::rank_r(-1, {0}), -1);
    EXPECT_EQ(binary_search::rank_r( 0, {0}),  0);
    EXPECT_EQ(binary_search::rank_r( 1, {0}), -1);
}

TEST(rank_r, WorksProperlyWithAThreeValuesArray)
{
    const auto a = std::vector{0, 1, 2};
    EXPECT_EQ(binary_search::rank_r(-1, a), -1);
    EXPECT_EQ(binary_search::rank_r( 0, a),  0);
    EXPECT_EQ(binary_search::rank_r( 2, a),  2);
    EXPECT_EQ(binary_search::rank_r( 3, a), -1);
}