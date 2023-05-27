/* Proj: CppHighProgramming
 * File: DemoTest.cpp
 * Created Date: 2023/5/27
 * Author: YangYangYang (yangyangyang0110@outlook.com)
 * Description:
 * -----
 * Last Modified: 2023/5/27 10:20:54
 * Modified By: YangYangYang (yangyangyang0110@outlook.com)
 * -----
 * Copyright (c) 2023  . All rights reserved.
 */

#include <gtest/gtest.h>

TEST(AAA, BBBB) {
    ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
