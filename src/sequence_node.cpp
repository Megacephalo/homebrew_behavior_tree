#include "sequence_node.h"

namespace Homebrew_Behavior_Tree {

SequenceNode::SequenceNode(const std::string& nodeName, const Status& status) 
: TreeNode(nodeName, status) 
{} /* ctor */

Status SequenceNode::tick() {
    if (children_.empty()) {
        throw std::runtime_error("SequenceNode::tick() - No children to tick");
    }

    for (auto& child : children_) {
        status_ = child->tick();
        if (status_ == Status::FAILURE or status_ == Status::RUNNING) {
            return status_;
        }
        else {
            continue;
        }
    } /* for */
    // Expect to return SUCCESS status
    return status_;
} /* tick */

SequenceNode::Ptr
SequenceNode::create(const std::string& nodeName, const Status& status) {
    return std::make_shared<SequenceNode>(nodeName, status);
} /* create */

} /* namespace */