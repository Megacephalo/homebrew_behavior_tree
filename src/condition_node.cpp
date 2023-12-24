#include "condition_node.h"

namespace Homebrew_Behavior_Tree {

ConditionNode::ConditionNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status ConditionNode::tick() {
    if (children_.empty()) {
        return Status::FAILURE;
    }
    // TODO

    // DEBUG
    return Status::SUCCESS;
}

ConditionNode::Ptr
ConditionNode::create() {
    return std::make_shared<ConditionNode>();
}

} /* namespace */