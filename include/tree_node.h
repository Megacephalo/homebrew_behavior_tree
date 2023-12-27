#ifndef _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_

#include <string>
#include <list>
#include <memory>

#include "status.h"

namespace Homebrew_Behavior_Tree {
/**
 * @brief TreeNode is the base class for all nodes in the behavior tree.
 * Note, to use a tree node, you must inherit your own class from it and implement the tick() function.
*/
class TreeNode {
  public:
    typedef std::shared_ptr<TreeNode> Ptr;
  protected:
    /**
     * @brief The status of the node
    */
    Status status_;

    /**
     * @brief The children nodes originating from the current node
    */
    std::list<TreeNode::Ptr> children_;

    /**
     * @brief The name of the node
    */
    std::string nodeName_;
  public:

    /**
     * @brief Construct a new Tree Node object
     * @param nodeName The name of the node
     * @param status The status of the node
    */
    TreeNode(const std::string& nodeName, const Status& status);
    virtual ~TreeNode();

    /**
     * @brief Run the underlying logic of the node. However in order to specify your own node
     * you must implement your own node class by inheritic from this class and implement this function.
    */
    virtual Status tick() = 0;

    /**
     * @brief Add a child node under the current node
    */
    void addChild(const TreeNode::Ptr& child);
    /**
     * @brief Remove a child node from the current node
     * @param child The child node to be removed
    */
    // TODO: Still requires O(n) time to remove a child
    void removeChild(const TreeNode::Ptr& child);
    /**
     * @brief Check if the current node has children nodes under it
     * @return true if the current node has children nodes under it and false otherwise.
    */
    bool hasChildren() const;

    /**
     * @brief Get the name of the node
     * @return The name of the node as a string
    */
    std::string getName() const;

    /**
     * @brief Get the status of the node
     * @return The status of the node as a Status enum class
    */
    Status getStatus() const;

    /**
     * @brief Equal operataor overloading to facilitate the comparison of two nodes
     * @return true if the two nodes are equal and false otherwise
    */
    bool operator == (const TreeNode& other) const;
};

} /* namespace */

#endif /*  _HOMEBREW_BEHAVIOR_TREE_TREE_NODE_H_ */