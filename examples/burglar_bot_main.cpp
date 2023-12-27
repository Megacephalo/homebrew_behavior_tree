#include <iostream>

#include "status.h"
#include "tree_node.h"
#include "action_node.h"
#include "condition_node.h"
#include "sequence_node.h"
#include "fallback_node.h"
#include "decorator_node.h"
#include "parallel_node.h"
#include "blackboard.h"

#include "action_drive_around.h"
#include "sealing_conditions.h"

/**
 * In this simple program, I implement the burglar behavior as a behavior tree described in the 
 * book "Behavior Tree in Robotics and AI: An Introduction" by Michele Colledanchise and Petter Ogren.
 * on page 55 Figure 3.18 
*/
using namespace Homebrew_Behavior_Tree;

int main(int argc, char** argv) {
    std::cout << "Launching Burglar_bot_simulation" << std::endl;

    Blackboard& blackboard = Blackboard::getInstance();

    blackboard.setValue("HasMoney", false);
    blackboard.setValue("MoneyNearby", false);
    blackboard.setValue("HouseNearby", false);
    blackboard.setValue("noCopsNearby", false);
    blackboard.setValue("DoorIsUnlocked", false);
    blackboard.setValue("HasCrowbar", true);
    blackboard.setValue("DoorIsWeak", true);
    blackboard.setValue("DoorIsOoened", false);
    blackboard.setValue("AmInsideHouse", false);


    // Create the tree
    TreeNode::Ptr root = SequenceNode::create("root", Status::RUNNING);
    // TreeNode::Ptr whatToDoIfCops = FallbackNode::create("whatToDoIfCops", Status::RUNNING);
    
    /* Figure 3.15: Sub-tree: Get the money!  */
    TreeNode::Ptr getTheMoney = FallbackNode::create("getTheMoney", Status::RUNNING);
    
    TreeNode::Ptr SpendTheMoneySequence = SequenceNode::create("SpendTheMoneySequence", Status::RUNNING);
    TreeNode::Ptr isthereMoney = HasMoney::create("isthereMoney", Status::RUNNING);
    TreeNode::Ptr spendMoneyAction = SpendMoney::create("spendMoneyAction", Status::RUNNING);
    SpendTheMoneySequence->addChild(isthereMoney);
    SpendTheMoneySequence->addChild(spendMoneyAction);

    getTheMoney->addChild(SpendTheMoneySequence);


    TreeNode::Ptr StealMoneySequence = SequenceNode::create("StealMoneySequence", Status::RUNNING);
    TreeNode::Ptr isMoneyNearby = MoneyNearby::create("isMoneyNearby", Status::RUNNING);
    TreeNode::Ptr stealMoneyAction = StealMoney::create("stealMoneyAction", Status::RUNNING);
    StealMoneySequence->addChild(isMoneyNearby);
    StealMoneySequence->addChild(stealMoneyAction);

    getTheMoney->addChild(StealMoneySequence);

    TreeNode::Ptr BreakInHouseSequence = SequenceNode::create("BreakInHouseSequence", Status::RUNNING);
    TreeNode::Ptr isHouseNearby = HouseNearby::create("isThereHouseNearby", Status::RUNNING);
    TreeNode::Ptr enterHouseAction = EnterHouse::create("enterHouseAction", Status::RUNNING);
    BreakInHouseSequence->addChild(isHouseNearby);
    // BreakInHouseSequence->addChild(enterHouseAction);

    getTheMoney->addChild(BreakInHouseSequence);

    TreeNode::Ptr driveAroundAction = DriveAround::create("driveAroundAction", Status::RUNNING);
    getTheMoney->addChild(driveAroundAction);

    /* Figure 3.16: Fight the cop or flight behavior */
    TreeNode::Ptr DealWithCopsSequence = SequenceNode::create("DealWithCopsSequence", Status::RUNNING);

    TreeNode::Ptr fightCopsOrFlySequnece = FallbackNode::create("fightCopsOrFlySequnece", Status::RUNNING);
    TreeNode::Ptr noCopsNearby = noCopsNearby::create("noCopsNearby", Status::RUNNING);
    TreeNode::Ptr escapeAction = Escape::create("escapeAction", Status::RUNNING);
    TreeNode::Ptr fightCopsAction = FightCops::create("fightCopsAction", Status::RUNNING);
    fightCopsOrFlySequnece->addChild(noCopsNearby);
    fightCopsOrFlySequnece->addChild(escapeAction);
    fightCopsOrFlySequnece->addChild(fightCopsAction);

    DealWithCopsSequence->addChild(fightCopsOrFlySequnece);

    TreeNode::Ptr stealStuffAction = StealStuff::create("stealStuffAction", Status::RUNNING);
    DealWithCopsSequence->addChild(stealStuffAction);

    /* Figure 3.17: Get a burglar into house */
    TreeNode::Ptr openDoorSequence = SequenceNode::create("openDoorSequence", Status::RUNNING);
    TreeNode::Ptr isDoorUnlocked = DoorIsUnlocked::create("isDoorUnlocked", Status::RUNNING);
    TreeNode::Ptr openDoorAction = OpenDoor::create("openDoorAction", Status::RUNNING);
    openDoorSequence->addChild(isDoorUnlocked);
    openDoorSequence->addChild(openDoorAction);

    TreeNode::Ptr breakDownDoorSequence = SequenceNode::create("breakDownDoorSequence", Status::RUNNING);
    TreeNode::Ptr hasCrowbar = HasCrowbar::create("hasCrowbar", Status::RUNNING);
    TreeNode::Ptr isDoorWeak = DoorIsWeak::create("isDoorWeak", Status::RUNNING);
    TreeNode::Ptr breakDoorOpenAction = BreakDoorOpen::create("breakDoorOpenAction", Status::RUNNING);
    breakDownDoorSequence->addChild(hasCrowbar);
    breakDownDoorSequence->addChild(isDoorWeak);
    breakDownDoorSequence->addChild(breakDoorOpenAction);

    TreeNode::Ptr isDoorOpened = DoorIsOoened::create("isDoorOpened", Status::RUNNING);

    TreeNode::Ptr evaluateWhetherToBreakInSequence = SequenceNode::create("evaluateWhetherToBreakInSequence", Status::RUNNING);
    evaluateWhetherToBreakInSequence->addChild(isDoorOpened);
    evaluateWhetherToBreakInSequence->addChild(openDoorSequence);
    evaluateWhetherToBreakInSequence->addChild(breakDownDoorSequence);

    TreeNode::Ptr GoInsideAction = GoInside::create("GoInsideAction", Status::RUNNING);

    TreeNode::Ptr evaluateHowToOpenDoorSequence = SequenceNode::create("evaluateHowToOpenDoorSequence", Status::RUNNING);
    evaluateHowToOpenDoorSequence->addChild(evaluateWhetherToBreakInSequence);
    evaluateHowToOpenDoorSequence->addChild(GoInsideAction);

    TreeNode::Ptr amIInsdeHouse = AmInsideHouse::create("amIInsdeHouse", Status::RUNNING);

    TreeNode::Ptr ensureBurglarBreakinSequence = SequenceNode::create("ensureBurglarBreakinSequence", Status::RUNNING);
    ensureBurglarBreakinSequence->addChild(amIInsdeHouse);
    ensureBurglarBreakinSequence->addChild(evaluateHowToOpenDoorSequence);

    /* Figure 3.18 : Combination 3.15, 3.16, and 3.17 */
    TreeNode::Ptr overallBreakingAndStealSequence = SequenceNode::create("overallBreakingAndStealSequence", Status::RUNNING);
    overallBreakingAndStealSequence->addChild(DealWithCopsSequence);
    overallBreakingAndStealSequence->addChild(getTheMoney);
    BreakInHouseSequence->addChild(ensureBurglarBreakinSequence);


    /* Run the BT */
    overallBreakingAndStealSequence->tick();

    return EXIT_SUCCESS;
}