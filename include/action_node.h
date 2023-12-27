#ifndef _HOMEBREW_BEHAVIOR_TREE_ACTION_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_ACTION_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

/**
 * @brief ActionNode is a leaf node in the behavior tree that performs an action.
 * Note, to use a action node, you must inherit your own class from it and implement the tick() function.
 * The default tick() is simply to return the specified or default status with which this node is instantiated.
*/
class ActionNode : public TreeNode {
  public:
    typedef std::shared_ptr<ActionNode> Ptr;
  public:
    /**
     * @brief Construct a new Action Node object
     * @param nodeName The name of the node
     * @param status The status of the node
    */
    ActionNode(const std::string& nodeName = "", const Status& status = Status::RUNNING);
    ~ActionNode() = default;

    /**
     * @brief Run the underlying action logic of the node. However in order to specify your own action
     * you must implement your own action node class by inheritic from this class and implement this function.
     * The default tick() is simply to return the specified or default status with which this node is instantiated.
    */
    virtual Status tick();

    /**
     * @brief Create a Action Node object pointer
     * @param nodeName The name of the node
     * @param status The status of the node. Please refer to the Status class for the list of status.
    */
    static ActionNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_ACTION_NODE_H_ */