#ifndef _HOMEBREW_BEHAVIOR_TREE_DECORATOR_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_DECORATOR_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

class DecoratorNode : public TreeNode {
  public:
    typedef std::shared_ptr<DecoratorNode> Ptr;
  public:
    DecoratorNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~DecoratorNode() = default;

    Status tick() override;

    static DecoratorNode::Ptr create();
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_DECORATOR_NODE_H_ */