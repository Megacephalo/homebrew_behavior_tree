#ifndef _HOMEBREW_BEHAVIOR_TREE_FALLBACK_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_FALLBACK_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

/**
 * @brief FallbackNode is a composite node in the behavior tree that executes its child nodes in sequence until one of them succeeds.
 * If a child node fails, then the fallback node will start executing the next child node in sequence. In other words, 
 * if all child nodes fail, then the fallback node will return failure.
*/
class FallbackNode : public TreeNode {
  public:
    typedef std::shared_ptr<FallbackNode> Ptr;
  public:
    /**
     * @brief Construct a new Fallback Node object
     * @param nodeName The name of the node
     * @param status The status of the node
    */
    FallbackNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~FallbackNode() = default;

    /**
     * @brief The tick logic as described in the book "Behavior Trees in Robotics and AI" p.7
    */
    Status tick() override;

    /**
     * @brief Create a Fallback Node object pointer
     * @return a pointer instance of FallbackNode
    */
    static FallbackNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_FALLBACK_NODE_H_ */