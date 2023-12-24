#ifndef _HOMEBREW_BEHAVIOR_TREE_NODE_FACTORY_H_
#define _HOMEBREW_BEHAVIOR_TREE_NODE_FACTORY_H_

#include "tree_node.h"
#include "action_node.h"
#include "condition_node.h"
#include "decorator_node.h"
#include "fallback_node.h"
#include "parallel_node.h"
#include "sequence_node.h"

namespace Homebrew_Behavior_Tree {

class NodeFactory {
public:
    NodeFactory() = default;
    ~NodeFactory() = default;

    TreeNode::Ptr registerNode(const std::string& nodeName, const std::string& nodeType, const Status& nodeStatus = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_NODE_FACTORY_H_ */