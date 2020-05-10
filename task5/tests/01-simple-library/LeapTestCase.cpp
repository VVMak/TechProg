//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"
#include <Functions.h>
#include <gtest/gtest.h>

TEST(LeapTestCase, NegYear) {
    try{
        IsLeap(-1);
    } catch (const std::invalid_argument& e) {
        ASSERT_STREQ(e.what(), "Year must be greater than 0");
    } catch (...) {
        ASSERT_TRUE(false);
    }
}

TEST(LeapTestCase, PosYears) {
    ASSERT_FALSE(IsLeap(2019));
    ASSERT_TRUE(IsLeap(2020));
    ASSERT_FALSE(IsLeap(1500));
    ASSERT_TRUE(IsLeap(2000));
}


