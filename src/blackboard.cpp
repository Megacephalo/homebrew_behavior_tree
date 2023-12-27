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
    std::lock_guard<std::mutex> guard(mutex_);
    if (parameterList_.find(key) == parameterList_.end()) {
        parameterList_.insert(std::make_pair(key, value));
    } else {
        parameterList_[key] = value;
    }
} /* setValue */

size_t
Blackboard::size() const {
    return parameterList_.size();
}

bool
Blackboard::empty() const {
    return parameterList_.empty();
}

} /* namespace */