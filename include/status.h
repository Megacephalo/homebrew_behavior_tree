#ifndef _HOMEBREW_BEHAVIOR_TREE_STATUS_H_
#define _HOMEBREW_BEHAVIOR_TREE_STATUS_H_

#include <iostream>

namespace Homebrew_Behavior_Tree {

enum class Status {
    IDLE,
    SUCCESS,
    FAILURE,
    RUNNING
};

inline
std::ostream& operator << (std::ostream& os, const Status& status) {
    switch (status) {
        case Status::IDLE:
            os << "IDLE";
            break;
        case Status::SUCCESS:
            os << "SUCCESS";
            break;
        case Status::FAILURE:
            os << "FAILURE";
            break;
        case Status::RUNNING:
            os << "RUNNING";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

} /* namespace */

#endif  /*  _HOMEBREW_BEHAVIOR_TREE_STATUS_H_ */