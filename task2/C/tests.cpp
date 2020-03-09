#include "A/index.h"
#include "B/lib.h"
#include "gtest/gtest.h"

class CTestA : public ::testing::Test{
public:
    CTestA() {}

    ~CTestA() {}

    void SetUp() { /* do nothing */ }

    void TearDown() { /* do nothing */ }
};

TEST_F(CTestA, TestA)
{
    A a;
    EXPECT_EQ( a.gcd( 168, 210 ), 42 );
}

class CTestB : public ::testing::Test{
public:
    CTestB() {}

    ~CTestB() {}

    void SetUp() { /* do nothing */ }

    void TearDown() { /* do nothing */ }
};

TEST_F(CTestB, TestB)
{
    B b;
    EXPECT_EQ( b.fib( 22 ), 17711 );
}
