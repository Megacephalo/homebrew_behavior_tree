#ifndef _HOMEBREW_BEHAVIOR_TREE_SEQUENCE_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_SEQUENCE_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

class SequenceNode : public TreeNode {
  public:
    typedef std::shared_ptr<SequenceNode> Ptr;
  public:
    SequenceNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~SequenceNode() = default;

    Status tick() override;
    static SequenceNode::Ptr create();
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_SEQUENCE_NODE_H_ */