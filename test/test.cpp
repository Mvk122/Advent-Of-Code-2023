#include <gtest/gtest.h>

#include "../src/solutions.h"

TEST(D1P2Test, parttwo1) {
    EXPECT_EQ(part_two("two1nine"), 29);
}

TEST(D1P2Test, parttwo2) {
    EXPECT_EQ(part_two("eightwothree"), 83);
}

TEST(D1P2Test, parttwo3) {
    EXPECT_EQ(part_two("abcone2threexyz"), 13);
}

TEST(D1P2Test, parttwo4) {
    EXPECT_EQ(part_two("xtwone3four"), 24);
}

TEST(D1P2Test, parttwo5) {
    EXPECT_EQ(part_two("4nineeightseven2"), 42);
}

TEST(D1P2Test, parttwo6) {
    EXPECT_EQ(part_two("zoneight234"), 14);
}

TEST(D1P2Test, parttwo7) {
    EXPECT_EQ(part_two("7pqrstsixteen"), 76);
}