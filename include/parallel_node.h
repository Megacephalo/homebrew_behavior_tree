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

    /**
     * @brief The algorithm is a direct implementation of the algorithm described in the book "Behavior Trees in Robotics and AI" by Michele Colledanchise and Luca Renda.
     * p. 8
    */
    Status tick() override;
    static ParallelNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_ */