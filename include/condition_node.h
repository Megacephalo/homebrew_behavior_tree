#ifndef _HOMEBREW_BEHAVIOR_TREE_CONDITION_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_CONDITION_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

class ConditionNode : public TreeNode {
  public:
    typedef std::shared_ptr<ConditionNode> Ptr;
  public:
    ConditionNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~ConditionNode() = default;

    Status tick() override;
    static ConditionNode::Ptr create();
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_CONDITION_NODE_H_ */