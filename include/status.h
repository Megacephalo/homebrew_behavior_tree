#ifndef _HOMEBREW_BEHAVIOR_TREE_STATUS_H_
#define _HOMEBREW_BEHAVIOR_TREE_STATUS_H_

namespace Homebrew_Behavior_Tree {

enum class Status {
    IDLE,
    SUCCESS,
    FAILURE,
    RUNNING
};

} /* namespace */

#endif  /*  _HOMEBREW_BEHAVIOR_TREE_STATUS_H_ */