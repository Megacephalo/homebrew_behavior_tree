#ifndef _HOMEBREW_BEHAVIOR_TREE_CONDITION_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_CONDITION_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

/**
 * @brief ConditionNode is a leaf node in the behavior tree that performs a condition check.
 * Note, to use a condition node, you must inherit your own class from it and implement the tick() function.
 * The default tick() is simply to return the the returned status from its only child node.
*/
class ConditionNode : public TreeNode {
  public:
    typedef std::shared_ptr<ConditionNode> Ptr;
  public:
    /**
     * @brief Construct a new Condition Node object
     * @param nodeName The name of the node
     * @param status The initial status of the node
    */
    ConditionNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~ConditionNode() = default;

    /**
     * @brief Run the underlying condition logic of the node. However in order to specify your own condition
     * you must implement your own condition node class by inheritic from this class and implement this function.
     * The default tick() is simply to return the status from its only child node.
    */
    virtual Status tick();

    /**
     * @brief Create a Condition Node object pointer.
     * @param nodeName The name of the node
     * @param status The initial status of the node. Please refer to the Status class for the list of status.
     * @return a pointer instance of ConditionNode
    */
    static ConditionNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_CONDITION_NODE_H_ */