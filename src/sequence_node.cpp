#include "sequence_node.h"

namespace Homebrew_Behavior_Tree {

SequenceNode::SequenceNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status SequenceNode::tick() {
    if (children_.empty()) {
        return Status::FAILURE;
    }
    // TODO

    // DEBUG
    return Status::SUCCESS;
}

SequenceNode::Ptr
SequenceNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<SequenceNode>(nodeName, status);
}

} /* namespace */