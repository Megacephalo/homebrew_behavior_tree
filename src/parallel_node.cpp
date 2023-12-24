#include "parallel_node.h"

namespace Homebrew_Behavior_Tree {

ParallelNode::ParallelNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status ParallelNode::tick() {
    if (children_.empty()) {
        return Status::FAILURE;
    }
    // TODO

    // DEBUG
    return Status::SUCCESS;
}

ParallelNode::Ptr
ParallelNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<ParallelNode>(nodeName, status);
}

} /* namespace */