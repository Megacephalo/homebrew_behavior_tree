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

void
TreeNode::addChild(const TreeNode::Ptr& child) {
    children_.push_back(child);
} /* addChild */

void
TreeNode::removeChild(const TreeNode::Ptr& child) {
    for (auto it = children_.begin(); it != children_.end(); ++it) {
        if (**it == *child) {
            children_.erase(it);
            break;
        }
    }
} /* removeChild */\

bool
TreeNode::hasChildren() const {
    return not children_.empty();
} /* hasChildren */

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