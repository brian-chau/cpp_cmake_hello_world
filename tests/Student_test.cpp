#include "Student.h"

#include <gtest/gtest.h>

#include <iostream>

// The fixture for testing class Student. From google test primer.
class StudentTest : public ::testing::Test {
protected:
    // You can remove any or all of the following functions if its body
    // is empty.

    StudentTest() {
        // You can do set-up work for each test here.
    }

    virtual ~StudentTest() {
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

    // Objects declared here can be used by all tests in the test case for Student.
    Student s;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)
TEST_F(StudentTest, Returns1) {
    int result = s.ReturnOne();  // we have access to s, declared in the fixture
    EXPECT_EQ(1, result);
}

TEST_F(StudentTest, DoesntReturn2) {
    int result = s.ReturnOne();  // we have access to s, declared in the fixture
    EXPECT_NE(2, result);
}

TEST_F(StudentTest, DoesntReturn3) {
    int result = s.ReturnOne();  // we have access to s, declared in the fixture
    EXPECT_NE(3, result);
}
// }  // namespace - could surround StudentTest in a namespace