#ifndef _STEALING_CONDITIONS_H_
#define _STEALING_CONDITIONS_H_

#include "condition_node.h"
#include "blackboard.h"

namespace Homebrew_Behavior_Tree {

class HasMoney : public ConditionNode {
  public:
    typedef std::shared_ptr<HasMoney> Ptr;

    HasMoney(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~HasMoney() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool hasMoney = std::get<bool>(blackboard.getValue("HasMoney"));
        if (not hasMoney) {
            std::cout << "Does not have money" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Has money" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static HasMoney::Ptr create(const std::string& name, Status status) {
        return std::make_shared<HasMoney>(name, status);
    }
};


class MoneyNearby : public ConditionNode {
  public:
    typedef std::shared_ptr<MoneyNearby> Ptr;

    MoneyNearby(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~MoneyNearby() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool moneyNearby = std::get<bool>(blackboard.getValue("MoneyNearby"));
        if (not moneyNearby) {
            std::cout << "Does not have money nearby" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Has money nearby" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static MoneyNearby::Ptr create(const std::string& name, Status status) {
        return std::make_shared<MoneyNearby>(name, status);
    }
};

class HouseNearby : public ConditionNode {
  public:
    typedef std::shared_ptr<HouseNearby> Ptr;

    HouseNearby(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~HouseNearby() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool houseNearby = std::get<bool>(blackboard.getValue("HouseNearby"));
        if (not houseNearby) {
            std::cout << "Does not have house nearby" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Has house nearby" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static HouseNearby::Ptr create(const std::string& name, Status status) {
        return std::make_shared<HouseNearby>(name, status);
    }
};


class noCopsNearby : public ConditionNode {
  public:
    typedef std::shared_ptr<noCopsNearby> Ptr;

    noCopsNearby(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~noCopsNearby() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool noCopsNearby = std::get<bool>(blackboard.getValue("noCopsNearby"));
        if (not noCopsNearby) {
            std::cout << "Does not have cops nearby" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Has cops nearby" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static noCopsNearby::Ptr create(const std::string& name, Status status) {
        return std::make_shared<noCopsNearby>(name, status);
    }
};


class DoorIsUnlocked : public ConditionNode {
  public:
    typedef std::shared_ptr<DoorIsUnlocked> Ptr;

    DoorIsUnlocked(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~DoorIsUnlocked() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool doorIsUnlocked = std::get<bool>(blackboard.getValue("DoorIsUnlocked"));
        if (not doorIsUnlocked) {
            std::cout << "Door is locked" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Door is unlocked" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static DoorIsUnlocked::Ptr create(const std::string& name, Status status) {
        return std::make_shared<DoorIsUnlocked>(name, status);
    }
};


class HasCrowbar : public ConditionNode {
  public:
    typedef std::shared_ptr<HasCrowbar> Ptr;

    HasCrowbar(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~HasCrowbar() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool hasCrowbar = std::get<bool>(blackboard.getValue("HasCrowbar"));
        if (not hasCrowbar) {
            std::cout << "Does not have crowbar" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Has crowbar" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static HasCrowbar::Ptr create(const std::string& name, Status status) {
        return std::make_shared<HasCrowbar>(name, status);
    }
};

class DoorIsWeak : public ConditionNode {
  public:
    typedef std::shared_ptr<DoorIsWeak> Ptr;

    DoorIsWeak(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~DoorIsWeak() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool doorIsWeak = std::get<bool>(blackboard.getValue("DoorIsWeak"));
        if (not doorIsWeak) {
            std::cout << "Door is not weak" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Door is weak" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static DoorIsWeak::Ptr create(const std::string& name, Status status) {
        return std::make_shared<DoorIsWeak>(name, status);
    }
};

class DoorIsOoened : public ConditionNode {
  public:
    typedef std::shared_ptr<DoorIsOoened> Ptr;

    DoorIsOoened(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~DoorIsOoened() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool doorIsOoened = std::get<bool>(blackboard.getValue("DoorIsOoened"));
        if (not doorIsOoened) {
            std::cout << "Door is not opened" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Door is opened" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static DoorIsOoened::Ptr create(const std::string& name, Status status) {
        return std::make_shared<DoorIsOoened>(name, status);
    }
};

class AmInsideHouse : public ConditionNode {
  public:
    typedef std::shared_ptr<AmInsideHouse> Ptr;

    AmInsideHouse(const std::string& name, Status status) : ConditionNode(name, status) {}
    ~AmInsideHouse() = default;

    Status tick() override {
        Blackboard& blackboard = Blackboard::getInstance();
        bool amInsideHouse = std::get<bool>(blackboard.getValue("AmInsideHouse"));
        if (not amInsideHouse) {
            std::cout << "Not inside house" << std::endl;
            status_ = Status::FAILURE;
        }
        else {
            std::cout << "Inside house" << std::endl;
            status_ = Status::SUCCESS;
        }

        return status_;
    }

    static AmInsideHouse::Ptr create(const std::string& name, Status status) {
        return std::make_shared<AmInsideHouse>(name, status);
    }
};

} /* namespace */

#endif /* _STEALING_CONDITIONS_H_ */