#include "blackboard.h"

namespace Homebrew_Behavior_Tree {

variant_t
Blackboard::getValue(const std::string& key) const {
    if (parameterList_.find(key) == parameterList_.end()) {
        throw std::runtime_error("Key: " + key + " not found in blackboard");
    }
    return parameterList_.find(key)->second;
} /* getValue */

void
Blackboard::setValue(const std::string& key, const variant_t& value) {
    if (parameterList_.find(key) == parameterList_.end()) {
        parameterList_.insert(std::make_pair(key, value));
    } else {
        parameterList_[key] = value;
    }
} /* setValue */

} /* namespace */