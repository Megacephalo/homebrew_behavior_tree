#include <gtest/gtest.h>

#include "status.h"
#include "tree_node.h"
#include "fallback_node.h"
#include "action_node.h"
#include "sequence_node.h"

using namespace Homebrew_Behavior_Tree;

TEST(BuildTreeTestSuite, test_build_simple_tree) {
    TreeNode::Ptr root = FallbackNode::create("root", Status::RUNNING);
    ASSERT_TRUE(root != nullptr);
}

