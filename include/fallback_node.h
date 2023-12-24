#ifndef _HOMEBREW_BEHAVIOR_TREE_FALLBACK_NODE_H_
#define _HOMEBREW_BEHAVIOR_TREE_FALLBACK_NODE_H_

#include "tree_node.h"

namespace Homebrew_Behavior_Tree {

class FallbackNode : public TreeNode {
  public:
    typedef std::shared_ptr<FallbackNode> Ptr;
  public:
    FallbackNode(const std::string& nodeName = "", const Status& status = Status::IDLE);
    ~FallbackNode() = default;

    Status tick() override;
    static FallbackNode::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE);
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_FALLBACK_NODE_H_ */