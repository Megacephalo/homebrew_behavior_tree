#include "parallel_node.h"

namespace Homebrew_Behavior_Tree {

ParallelNode::ParallelNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status ParallelNode::tick() {
    if (children_.empty()) {
        throw std::runtime_error("ParallelNode::tick() - No children to tick");
    }

    uint successCount{0};
    uint failureCount{0};
    for (auto& child : children_) {
        Status childStatus = child->tick();
        if (childStatus == Status::SUCCESS) {
            ++successCount;
        }
        else if (childStatus == Status::FAILURE) {
            ++failureCount;
        }
    } /* for */
    if (successCount == children_.size()) {
        status_ = Status::SUCCESS;
    }
    else if (failureCount > 0) {
        status_ = Status::FAILURE;
    }
    else {
        status_ = Status::RUNNING;
    }

    return status_;
}

ParallelNode::Ptr
ParallelNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<ParallelNode>(nodeName, status);
}

} /* namespace */