#include "decorator_node.h"

namespace Homebrew_Behavior_Tree {

DecoratorNode::DecoratorNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status DecoratorNode::tick() {
    if (children_.empty()) {
        return Status::FAILURE;
    }
    // TODO

    // DEBUG
    return Status::SUCCESS;
}

DecoratorNode::Ptr
DecoratorNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<DecoratorNode>(nodeName, status);
}

} /* namespace */