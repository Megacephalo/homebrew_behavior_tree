#include <gtest/gtest.h>

#include "fallback_node.h"
#include "action_node.h"

using namespace Homebrew_Behavior_Tree;

TEST(FallbackNodeTestSuite, test_emptyChildren) {
    TreeNode::Ptr fallbackNode = FallbackNode::create("FallbackNode", Status::RUNNING);
    ASSERT_THROW(fallbackNode->tick(), std::runtime_error);
}

TEST(FallbackNodeTestSuite, test_tick) {
    TreeNode::Ptr fallbackNode = FallbackNode::create("FallbackNode", Status::RUNNING);
    fallbackNode->addChild(ActionNode::create("Child1", Status::FAILURE));
    fallbackNode->addChild(ActionNode::create("Child2", Status::SUCCESS));
    ASSERT_EQ(fallbackNode->tick(), Status::SUCCESS);
}

/**
 * When the failure back encounters a failed child but find no other subsequent child to tick,
 * the fallback node should return failure with a warning message.
*/
TEST(FallbackNodeTestSuite, test_tick_edgecase) {
    TreeNode::Ptr fallbackNode = FallbackNode::create("FallbackNode", Status::RUNNING);
    fallbackNode->addChild(ActionNode::create("Child1", Status::FAILURE));
    ASSERT_EQ(fallbackNode->tick(), Status::FAILURE); // expect to get a warning message here 
}
