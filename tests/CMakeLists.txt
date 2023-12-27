include(FetchContent)

# Install Google Test
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/unit_tests)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(build_tree_unit_test
  test_build_tree.cpp
)
target_link_libraries(build_tree_unit_test
  homebrew_bt
  gtest_main
)

add_executable(testActionNode
  test_action_node.cpp
)
target_link_libraries(testActionNode
  homebrew_bt
  gtest_main
)

add_executable(testFallbackNode
  test_fallbackNode.cpp
)
target_link_libraries(testFallbackNode
  homebrew_bt
  gtest_main
)

add_executable(testSequenceNode
  test_sequenceNode.cpp
)
target_link_libraries(testSequenceNode
  homebrew_bt
  gtest_main
)

add_executable(testParallelNode
  test_parallelNode.cpp
)
target_link_libraries(testParallelNode
  homebrew_bt
  gtest_main
)

add_executable(testDecoratorNode
  test_conditionNode.cpp
)
target_link_libraries(testDecoratorNode
  homebrew_bt
  gtest_main
)

add_executable(testBlackboard
  test_backboard.cpp
)
target_link_libraries(testBlackboard
  homebrew_bt
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(
  build_tree_unit_test
  testActionNode
  testFallbackNode
  testSequenceNode
  testParallelNode
  testDecoratorNode
  testBlackboard
)