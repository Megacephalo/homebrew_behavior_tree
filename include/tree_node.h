#ifndef _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_

#include <sstream>
#include <string>
#include <unordered_set>
#include <memory>

#include "status.h"

namespace Homebrew_Behavior_Tree {

class TreeNode {
  public:
    typedef std::shared_ptr<TreeNode> Ptr;
  protected:
    Status status_;
    std::unordered_set<TreeNode::Ptr> children_;
    std::string nodeName_;
  public:
    TreeNode(const std::string& nodeName, const Status& status);
    virtual ~TreeNode();
    virtual Status tick() = 0;
    virtual void reset() {};
    std::string getName() const;
    std::string getState() const;
};

} /* namespace */

#endif /*  _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_ */