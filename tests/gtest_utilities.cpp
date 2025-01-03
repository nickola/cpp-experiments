// GoogleTest
#include <gtest/gtest.h>

// Library
#include "utilities.h"

TEST(gtest_utilities, wait1) {
  EXPECT_EQ(wait(5), 5);
}

TEST(gtest_utilities, wait2) {
  EXPECT_EQ(wait(5), 5);
}

TEST(gtest_utilities, wait3) {
  EXPECT_EQ(wait(5), 5);
}
