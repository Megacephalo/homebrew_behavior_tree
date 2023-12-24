#include "fallback_node.h"

namespace Homebrew_Behavior_Tree {

FallbackNode::FallbackNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status FallbackNode::tick() {
    if (children_.empty()) {
        return Status::FAILURE;
    }
    // TODO

    // DEBUG
    return Status::SUCCESS;
}

FallbackNode::Ptr
FallbackNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<FallbackNode>(nodeName, status);
}

} /* namespace */