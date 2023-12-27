#ifndef _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_

#include <sstream>
#include <string>
#include <list>
#include <memory>

#include "status.h"

namespace Homebrew_Behavior_Tree {

class TreeNode {
  public:
    typedef std::shared_ptr<TreeNode> Ptr;
  protected:
    Status status_;
    std::list<TreeNode::Ptr> children_;
    std::string nodeName_;
  public:
    TreeNode(const std::string& nodeName, const Status& status);
    virtual ~TreeNode();
    virtual Status tick() = 0;
    void addChild(const TreeNode::Ptr& child);
    // TODO: Still requires O(n) time to remove a child
    void removeChild(const TreeNode::Ptr& child);
    bool hasChildren() const;
    std::string getName() const;
    Status getStatus() const;
    bool operator == (const TreeNode& other) const;
};

} /* namespace */

#endif /*  _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_ */