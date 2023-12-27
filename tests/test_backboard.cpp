#include <gtest/gtest.h>

#include "blackboard.h"

using namespace Homebrew_Behavior_Tree;

TEST(Blackboard_TestSuite, test_constructor) {
    Blackboard& bb = Blackboard::getInstance();
    EXPECT_TRUE(bb.empty());
    bb.setValue("test", 1);
    variant_t v = bb.getValue("test");
    EXPECT_EQ(std::get<int>(v), 1);
}

TEST(Blackboard_TestSuite, testEmpty) {
    // This instance is the same as bb in previous test case
    Blackboard& bb1 = Blackboard::getInstance();
    EXPECT_FALSE(bb1.empty());
}

TEST(Blackboard_TestSuite, testSize) {
    Blackboard& bb2 = Blackboard::getInstance();
    bb2.setValue("test2", 3.0);
    EXPECT_EQ(bb2.size(), 2);
}

TEST(Blackboard_TestSuite, test_bothInstancesAreTheSame) {
    Blackboard& bb3 = Blackboard::getInstance();
    Blackboard& bb4 = Blackboard::getInstance();
    bb3.setValue("test", 1);
    variant_t v = bb4.getValue("test");
    EXPECT_EQ(std::get<int>(v), 1);
}