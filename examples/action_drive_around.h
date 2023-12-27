#ifndef _ACTION_DRIVE_AROUND_H_
#define _ACTION_DRIVE_AROUND_H_

#include <iostream>

#include "action_node.h"

namespace Homebrew_Behavior_Tree {

class DriveAround : public ActionNode {
    public:
        typedef std::shared_ptr<DriveAround> Ptr;

        DriveAround(const std::string& name, Status status) : ActionNode(name, status) {}
        ~DriveAround() = default;

        Status tick() override {
            std::cout << "Driving around" << std::endl;
            status_ = Status::SUCCESS;
            return status_;
        }

        static DriveAround::Ptr create(const std::string& name, Status status) {
            return std::make_shared<DriveAround>(name, status);
        }
};

class SpendMoney : public ActionNode {
  public:
    typedef std::shared_ptr<SpendMoney> Ptr;

    SpendMoney(const std::string& name, Status status) : ActionNode(name, status) {}
    ~SpendMoney() = default;

    Status tick() override {
        std::cout << "Spending money" << std::endl;
        status_ = Status::SUCCESS;
        return status_;
    }

    static SpendMoney::Ptr create(const std::string& name, Status status) {
        return std::make_shared<SpendMoney>(name, status);
    }
};

class StealMoney : public ActionNode {
  public:
    typedef std::shared_ptr<StealMoney> Ptr;

    StealMoney(const std::string& name, Status status) : ActionNode(name, status) {}
    ~StealMoney() = default;

    Status tick() override {
        std::cout << "Stealing money" << std::endl;
        status_ = Status::SUCCESS;
        return status_;
    }

    static StealMoney::Ptr create(const std::string& name, Status status) {
        return std::make_shared<StealMoney>(name, status);
    }
};


class EnterHouse : public ActionNode {
  public:
    typedef std::shared_ptr<EnterHouse> Ptr;

    EnterHouse(const std::string& name, Status status) : ActionNode(name, status) {}
    ~EnterHouse() = default;

    Status tick() override {
        std::cout << "Breaking da house VIKING STYLE!!" << std::endl;
        Blackboard& blackboard = Blackboard::getInstance();
        blackboard.setValue("DoorIsOoened", true);
        status_ = Status::SUCCESS;
        return status_;
    }

    static EnterHouse::Ptr create(const std::string& name, Status status) {
        return std::make_shared<EnterHouse>(name, status);
    }
};


class Escape : public ActionNode {
  public:
    typedef std::shared_ptr<Escape> Ptr;

    Escape(const std::string& name, Status status) : ActionNode(name, status) {}
    ~Escape() = default;

    Status tick() override {
        std::cout << "Escaping" << std::endl;
        status_ = Status::SUCCESS;
        return status_;
    }

    static Escape::Ptr create(const std::string& name, Status status) {
        return std::make_shared<Escape>(name, status);
    }
};

class FightCops : public ActionNode {
  public:
    typedef std::shared_ptr<FightCops> Ptr;

    FightCops(const std::string& name, Status status) : ActionNode(name, status) {}
    ~FightCops() = default;

    Status tick() override {
        std::cout << "Fighting cops. Pew, pew! Go to hell, cops!!" << std::endl;
        status_ = Status::SUCCESS;
        return status_;
    }

    static FightCops::Ptr create(const std::string& name, Status status) {
        return std::make_shared<FightCops>(name, status);
    }
};

class StealStuff : public ActionNode {
  public:
    typedef std::shared_ptr<StealStuff> Ptr;

    StealStuff(const std::string& name, Status status) : ActionNode(name, status) {}
    ~StealStuff() = default;

    Status tick() override {
        std::cout << "Stealing stuff" << std::endl;
        status_ = Status::SUCCESS;
        return status_;
    }

    static StealStuff::Ptr create(const std::string& name, Status status) {
        return std::make_shared<StealStuff>(name, status);
    }
};

class OpenDoor : public ActionNode {
  public:
    typedef std::shared_ptr<OpenDoor> Ptr;

    OpenDoor(const std::string& name, Status status) : ActionNode(name, status) {}
    ~OpenDoor() = default;

    Status tick() override {
        std::cout << "Opening door" << std::endl;
        status_ = Status::SUCCESS;
        return status_;
    }

    static OpenDoor::Ptr create(const std::string& name, Status status) {
        return std::make_shared<OpenDoor>(name, status);
    }
};

class BreakDoorOpen : public ActionNode {
  public:
    typedef std::shared_ptr<BreakDoorOpen> Ptr;

    BreakDoorOpen(const std::string& name, Status status) : ActionNode(name, status) {}
    ~BreakDoorOpen() = default;

    Status tick() override {
        std::cout << "Breaking door open" << std::endl;
        Blackboard& blackboard = Blackboard::getInstance();
        blackboard.setValue("DoorIsOoened", true);
        status_ = Status::SUCCESS;
        return status_;
    }

    static BreakDoorOpen::Ptr create(const std::string& name, Status status) {
        return std::make_shared<BreakDoorOpen>(name, status);
    }
};

class GoInside : public ActionNode {
  public:
    typedef std::shared_ptr<GoInside> Ptr;

    GoInside(const std::string& name, Status status) : ActionNode(name, status) {}
    ~GoInside() = default;

    Status tick() override {
        std::cout << "Going inside" << std::endl;
        Blackboard& blackboard = Blackboard::getInstance();
        blackboard.setValue("AmInsideHouse", true);
        status_ = Status::SUCCESS;
        return status_;
    }

    static GoInside::Ptr create(const std::string& name, Status status) {
        return std::make_shared<GoInside>(name, status);
    }
};

} /* namespace */

#endif /* _ACTION_DRIVE_AROUND_H_ */