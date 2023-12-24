#include "node_factory.h"

namespace Homebrew_Behavior_Tree {

TreeNode::Ptr registerNode(const std::string& nodeName, const std::string& nodeType, const Status& nodeStatus) {
    if (nodeType == "Action") {
        return ActionNode::create(nodeName, nodeStatus);
    } else if (nodeType == "Condition") {
        return ConditionNode::create(nodeName, nodeStatus);
    } else if (nodeType == "Decorator") {
        return DecoratorNode::create(nodeName, nodeStatus);
    } else if (nodeType == "Fallback") {
        return FallbackNode::create(nodeName, nodeStatus);
    } else if (nodeType == "Parallel") {
        return ParallelNode::create(nodeName, nodeStatus);
    } else if (nodeType == "Sequence") {
        return SequenceNode::create(nodeName, nodeStatus);
    } else {
        return nullptr;
    }
}

} /* namespace */