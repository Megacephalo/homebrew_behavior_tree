#ifndef _HOMEBREW_BEHAVIOR_TREE_DECORATOR_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_DECORATOR_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

/**
 * @brief DecoratorNode is a node in the behavior tree that decorates a child node.
 * Note, to use a decorator node, you must inherit your own class from it and implement the tick() function.
 * The default tick() is simply to return the status from its only child node.
*/
class DecoratorNode : public TreeNode {
  public:
    typedef std::shared_ptr<DecoratorNode> Ptr;
  public:
    DecoratorNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~DecoratorNode() = default;

    /**
     * @brief Run the underlying decorator logic of the node. However in order to specify your own decorator
     * you must implement your own decorator node class by inheritic from this class and implement this function.
     * The default tick() is simply to return the status from its only child node.
    */
    virtual Status tick();

    /**
     * @brief Create a Decorator Node object pointer.
     * @return a pointer instance of DecoratorNode
    */
    static DecoratorNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_DECORATOR_NODE_H_ */