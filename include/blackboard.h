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

/**
 * @brief Blackboard is a thread-safe singleton class that stores the parameters for the behavior tree. You can imagine
 * blackboard as a global-wise database where you can leave your parameters in it and retrieve them fro
 * anywhere in the tree. 
*/
class Blackboard {
  private:
    /**
     * @brief The parameters are stored in a hash map with the key being the parameter name and the value
     * being the parameter value. The parameter value is stored in a variant type which can be int, double,
     * bool or string.
    */
    std::unordered_map<std::string, variant_t> parameterList_;
    
    /**
     * @brief The mutex is used to lock the blackboard when it is being accessed by multiple threads.
    */
    std::mutex mutex_;

    /**
     * @brief Construct a new Blackboard object
    */
    Blackboard() = default;
    ~Blackboard() = default;

    /**
     * @brief Copy constructor and assignment operator are deleted to prevent copying of the singleton object.
    */
    Blackboard(const Blackboard&) = delete;
    Blackboard& operator=(const Blackboard&) = delete;
  public:
    /**
     * @brief Get the instance of the singleton object
    */
    static Blackboard& getInstance() {
        static Blackboard instance;
        return instance;
    }

    /**
     * @brief Set the value of the parameter
     * @param key The name of the parameter
     * @param value The value of the parameter
    */
    void setValue(const std::string& key, const variant_t& value);

    /**
     * @brief Get the value of the parameter
     * @param key The name of the parameter
     * @return The value of the parameter
    */
    variant_t getValue(const std::string& key) const;

    /**
     * @brief Check if the parameter exists
     * @param key The name of the parameter
    */
    size_t size() const;

    /**
     * @brief Check if the parameter exists
     * @return A boolean value indicating if the blackboard is empty.
    */
    bool empty() const;
};

} /* namespace */

#endif /* _HOMEBREW_BEHAVIOR_TREE_BLACKBOARD_H_ */