//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"
#include <gtest/gtest.h>

TEST(AddTestCase, AddTest) {
    for (int i = -7; i < 8; ++i) {
        for (int j = -7; j < 8; ++j) {
            ASSERT_EQ(i + j, Add(i, j));
        }
    }
}
