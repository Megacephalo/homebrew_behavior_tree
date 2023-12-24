#ifndef _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

class ParallelNode : public TreeNode {
  public:
    typedef std::shared_ptr<ParallelNode> Ptr;
  public:
    ParallelNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~ParallelNode() = default;

    Status tick() override;
    static ParallelNode::Ptr create();
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_ */