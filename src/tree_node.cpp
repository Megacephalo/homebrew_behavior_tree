#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

TreeNode::TreeNode(const std::string& nodeName, const Status& status)
: status_(status)
, nodeName_(nodeName) 
{} /* ctor */

TreeNode::~TreeNode() {
    if (not children_.empty()) {
        children_.clear();
    }
} /* dtor */

std::string
TreeNode::getName() const {
    return nodeName_;
} /* getName */

std::string
TreeNode::getState() const {
    std::stringstream ss;
    ss << status_;
    return ss.str();
} /* getState */

} /* namespace */