#include <gtest/gtest.h>

#include "tree_node.h"
#include "sequence_node.h"

using namespace Homebrew_Behavior_Tree;

TEST(SequenceNode_TestSuite, test_emptyChildren) {
    TreeNode::Ptr sequenceNode = SequenceNode::create("SequenceNode");
    ASSERT_THROW(sequenceNode->tick(), std::runtime_error);
}