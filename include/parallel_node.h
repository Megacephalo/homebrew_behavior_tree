#ifndef _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

/**
 * @brief ParallelNode is a composite node in the behavior tree that executes all of its child nodes in parallel.
 * The parallel node will return success if all of its child nodes return success. If one or more child nodes fail,
 * then the parallel node will return failure. If one or more child nodes are running, then the parallel node will
 * return running.
*/
class ParallelNode : public TreeNode {
  public:
    typedef std::shared_ptr<ParallelNode> Ptr;
  public:
    /**
     * @brief Construct a new Parallel Node object
     * @param nodeName The name of the node
     * @param status The status of the node
    */
    ParallelNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~ParallelNode() = default;

    /**
     * @brief The algorithm is a direct implementation of the algorithm described in the book "Behavior Trees in Robotics and AI" by Michele Colledanchise and Luca Renda.
     * p. 8
    */
    Status tick() override;

    /**
     * @brief Create a Parallel Node object pointer
     * @return a pointer instance of ParallelNode
    */
    static ParallelNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_PARALLEL_NODE_H_ */