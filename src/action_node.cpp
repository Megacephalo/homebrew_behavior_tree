#include "action_node.h"

namespace Homebrew_Behavior_Tree {

ActionNode::ActionNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status ActionNode::tick() {
    return status_;
} /* tick */

ActionNode::Ptr
ActionNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<ActionNode>(nodeName, status);
} /* create */

} /* namespace */