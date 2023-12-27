#ifndef _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_
#define _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_

#include <string>
#include <unordered_map>
#include <variant>
#include <stdexcept>
#include <memory>
#include <mutex>
#include <thread>

using variant_t = std::variant<int, double, bool, std::string>;

namespace Homebrew_Behavior_Tree {

class Blackboard {
  private:
    std::unordered_map<std::string, variant_t> parameterList_;
    std::mutex mutex_;
    Blackboard() = default;
    ~Blackboard() = default;
    Blackboard(const Blackboard&) = delete;
    Blackboard& operator=(const Blackboard&) = delete;
  public:
    static Blackboard& getInstance() {
        static Blackboard instance;
        return instance;
    }
    void setValue(const std::string& key, const variant_t& value);
    variant_t getValue(const std::string& key) const;
    size_t size() const;
    bool empty() const;
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_ */