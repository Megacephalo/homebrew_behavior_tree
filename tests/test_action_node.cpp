#include <gtest/gtest.h>

#include "tree_node.h"
#include "action_node.h"

using namespace Homebrew_Behavior_Tree;

TEST(ActionNodeTestSuite, test_action_node) {
    TreeNode::Ptr node1 = ActionNode::create("node1", Status::RUNNING);
    ASSERT_TRUE(node1 != nullptr);
}
#if 0
TEST(ActionNodeTestSuite, test_action_node_tick) {
    TreeNode::Ptr node1 = ActionNode::create("node1", Status::RUNNING);
    ASSERT_EQ(node1->tick(), Status::SUCCESS);
}

TEST(ActionNodeTestSuite, test_action_node_tick_with_child) {
    /*
    Actually we should treat Actionnode as the leaf node and no more children could be added.
    */
    TreeNode::Ptr node1 = ActionNode::create("node1", Status::RUNNING);
    TreeNode::Ptr node2 = ActionNode::create("node2", Status::RUNNING);
    node1->addChild(node2);
    ASSERT_TRUE(node1->hasChildren());
    ASSERT_EQ(node1->tick(), Status::SUCCESS);
    ASSERT_EQ(node2->tick(), Status::SUCCESS);
}
#endif