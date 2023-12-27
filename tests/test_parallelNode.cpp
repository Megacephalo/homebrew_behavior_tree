#include <gtest/gtest.h>

#include "parallel_node.h"
#include "action_node.h"

using namespace Homebrew_Behavior_Tree;

TEST(ParallelNode_TestSuite, test_constructor) {
    TreeNode::Ptr node = ParallelNode::create("ParallelNode");
    EXPECT_EQ(node->getName(), "ParallelNode");
    EXPECT_EQ(node->getStatus(), Status::IDLE);
}

TEST(ParallelNode_TestSuite, test_emptyChildren) {
    TreeNode::Ptr node = ParallelNode::create("ParallelNode");
    EXPECT_THROW(node->tick(), std::runtime_error);
}

TEST(ParallelNode_TestSuite, test_oneChildSuccess) {
    TreeNode::Ptr parallelNode = ParallelNode::create("ParallelNode");
    TreeNode::Ptr child = ActionNode::create("SuccessNode", Status::SUCCESS);
    parallelNode->addChild(child);
    EXPECT_EQ(parallelNode->tick(), Status::SUCCESS);
}

TEST(ParallelNode_TestSuite, test_oneChildFailure) {
    TreeNode::Ptr parallelNode = ParallelNode::create("ParallelNode");
    TreeNode::Ptr successChild = ActionNode::create("SuccessNode", Status::SUCCESS);
    TreeNode::Ptr failedChild = ActionNode::create("FailureNode", Status::FAILURE);
    
    parallelNode->addChild(successChild);
    parallelNode->addChild(failedChild);
    EXPECT_EQ(parallelNode->tick(), Status::FAILURE);

    TreeNode::Ptr runningChild = ActionNode::create("RunningNode", Status::RUNNING);
    parallelNode->addChild(runningChild);
    EXPECT_EQ(parallelNode->tick(), Status::FAILURE);
}