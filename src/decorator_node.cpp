#include "decorator_node.h"

namespace Homebrew_Behavior_Tree {

DecoratorNode::DecoratorNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status DecoratorNode::tick() {
    if (children_.empty()) {
        throw std::runtime_error("ConditionNode::tick() - No child to tick");
    }
    if (children_.size() > 1) {
        throw std::runtime_error("ConditionNode::tick() - Only one child nnode is allowed.");
    }

    status_ = children_.front()->tick();

    return status_;
}

DecoratorNode::Ptr
DecoratorNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<DecoratorNode>(nodeName, status);
}

} /* namespace */