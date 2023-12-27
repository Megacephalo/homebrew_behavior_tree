#include <gtest/gtest.h>

#include "action_node.h"
#include "condition_node.h"

using namespace Homebrew_Behavior_Tree;

TEST(ConditionNode_TestSuite, test_constructor) {
    TreeNode::Ptr node = ConditionNode::create("ConditionNode");
    EXPECT_EQ(node->getName(), "ConditionNode");
    EXPECT_EQ(node->getStatus(), Status::IDLE);
}

TEST(ConditionNode_TestSuite, test_emptyChildPrevention) {
    TreeNode::Ptr node = ConditionNode::create("ConditionNode");
    EXPECT_THROW(node->tick(), std::runtime_error);
}

TEST(ConditionNode_TestSuite, test_MultipleChildrenPrevention) {
    TreeNode::Ptr condNode = ConditionNode::create("ConditionNode");
    TreeNode::Ptr actionNode1 = ActionNode::create("ActionNode1", Status::SUCCESS);
    TreeNode::Ptr actionNode2 = ActionNode::create("ActionNode2", Status::SUCCESS);
    condNode->addChild(actionNode1);
    condNode->addChild(actionNode2);
    EXPECT_THROW(condNode->tick(), std::runtime_error);
}

TEST(ConditionNode_TestSuite, test_Inverter_conditionNode) {
    // Implement an inherited conditional node
    class Inverter : public ConditionNode {
      public:
        typedef std::shared_ptr<Inverter> Ptr;

        Inverter(const std::string& nodeName = "", const Status& status = Status::IDLE)
        : ConditionNode(nodeName, status) 
        {} /* ctor */

        Status tick() override {
            if (children_.empty()) {
                throw std::runtime_error("Inverter::tick() - No child to tick");
            }
            if (children_.size() > 1) {
                throw std::runtime_error("Inverter::tick() - Only one child nnode is allowed.");
            }

            status_ = children_.front()->tick();
            if (status_ == Status::SUCCESS) {
                status_ = Status::FAILURE;
            } else if (status_ == Status::FAILURE) {
                status_ = Status::SUCCESS;
            }

            return status_;
        } /* tick */

        static Inverter::Ptr create(const std::string& nodeName = "", const Status& status = Status::IDLE) {
            return std::make_shared<Inverter>(nodeName, status);
        } /* create */
    };

    TreeNode::Ptr inverterNode1 = Inverter::create("Inverter");
    TreeNode::Ptr successActionNode = ActionNode::create("SuccessActionNode", Status::SUCCESS);
    inverterNode1->addChild(successActionNode);
    EXPECT_EQ(inverterNode1->tick(), Status::FAILURE);

    TreeNode::Ptr inverterNode2 = Inverter::create("Inverter");
    TreeNode::Ptr failureActionNode = ActionNode::create("SuccessActionNode", Status::FAILURE);
    inverterNode2->addChild(failureActionNode);
    EXPECT_EQ(inverterNode2->tick(), Status::SUCCESS);
}