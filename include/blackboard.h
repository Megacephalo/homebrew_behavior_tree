#ifndef _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_
#define _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_

#include <string>
#include <unordered_map>
#include <variant>
#include <stdexcept>

using variant_t = std::variant<int, double, bool, std::string>;

namespace Homebrew_Behavior_Tree {

class Blackboard {
    std::unordered_map<std::string, variant_t> parameterList_;
  public:
    Blackboard() = default;
    ~Blackboard() = delete;
    Blackboard(const Blackboard&) = delete;
    Blackboard& operator = (const Blackboard&) = delete;

    void setValue(const std::string& key, const variant_t& value);
    variant_t getValue(const std::string& key) const;
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_ */