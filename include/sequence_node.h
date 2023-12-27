#ifndef _HOMEBREW_BEHAVIOR_TREE_SEQUENCE_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_SEQUENCE_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

/**
 * @brief SequenceNode is a composite node in the behavior tree that executes its child nodes in sequence until one of them fails.
 * If a child node succeeds, then the sequence node will start executing the next child node in sequence. In other words,
 * if all child nodes succeed, then the sequence node will return success.
*/
class SequenceNode : public TreeNode {
  public:
    typedef std::shared_ptr<SequenceNode> Ptr;
  public:
    /**
     * @brief Construct a new Sequence Node object
     * @param nodeName The name of the node
     * @param status The status of the node
    */
    SequenceNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~SequenceNode() = default;

    /**
     * @brief The tick logic as described in the book "Behavior Trees in Robotics and AI" p.7
    */
    Status tick() override;

    /**
     * @brief Create a Sequence Node object pointer
     * @return a pointer instance of SequenceNode
    */
    static SequenceNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_SEQUENCE_NODE_H_ */