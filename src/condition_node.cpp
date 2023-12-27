#include "condition_node.h"

namespace Homebrew_Behavior_Tree {

ConditionNode::ConditionNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status ConditionNode::tick() {
    if (children_.empty()) {
        throw std::runtime_error("ConditionNode::tick() - No child to tick");
    }
    if (children_.size() > 1) {
        throw std::runtime_error("ConditionNode::tick() - Only one child nnode is allowed.");
    }

    status_ = children_.front()->tick();

    return status_;
} /* tick */

ConditionNode::Ptr
ConditionNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<ConditionNode>(nodeName, status);
} /* create */

} /* namespace */