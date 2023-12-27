#include "fallback_node.h"

namespace Homebrew_Behavior_Tree {

FallbackNode::FallbackNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status FallbackNode::tick() {
    if (children_.empty()) {
        throw std::runtime_error("FallbackNode::tick() - No children to tick");
    }
    
    for (auto& child : children_) {
        status_ = child->tick();
        if (status_ == Status::FAILURE) {
            // move on to the next child
            if (*child == *(children_.back())) {
                // if this is the last child, return failure
                std::cerr << "FallbackNode::tick() WARNING - Try to run the next child after a failed one but found no subsequent node. Returning a FAILURE status" << std::endl;
                return status_;
            }
            else {
                continue;
            }
        }
        else {
            // either the child returns running or success
            return status_;
        }
    }
    status_ = Status::FAILURE;
    return status_;
}

FallbackNode::Ptr
FallbackNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<FallbackNode>(nodeName, status);
}

} /* namespace */