#ifndef _HOMEBREW_BEHAVIOR_TREE_ACTION_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_ACTION_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

class ActionNode : public TreeNode {
  public:
    typedef std::shared_ptr<ActionNode> Ptr;
  public:
    ActionNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~ActionNode() = default;

    Status tick() override;
    static ActionNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_ACTION_NODE_H_ */