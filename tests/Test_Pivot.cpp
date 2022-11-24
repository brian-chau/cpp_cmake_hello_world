#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>

#include "Solution.h"

// The fixture for testing class Solution. From google test primer.
class SolutionTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    SolutionTest() {
        // You can do set-up work for each test here.
    }

    virtual ~SolutionTest() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    // Objects declared here can be used by all tests in the test case for Solution.
    Solution s;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)

TEST_F(SolutionTest, PivotIndex1) {
    std::vector<int> input{1, 7, 3, 6, 5, 6};
    int actualResult(s.pivotIndex(input));
    int expectedResult(3);
    EXPECT_EQ(actualResult, expectedResult);
}

TEST_F(SolutionTest, PivotIndex2) {
    std::vector<int> input{1, 2, 3};
    int actualResult(s.pivotIndex(input));
    int expectedResult(-1);
    EXPECT_EQ(actualResult, expectedResult);
}

TEST_F(SolutionTest, PivotIndex3) {
    std::vector<int> input{2, 1, -1};
    int actualResult(s.pivotIndex(input));
    int expectedResult(0);
    EXPECT_EQ(actualResult, expectedResult);
}

// }  // namespace - could surround SolutionTest in a namespace