# Homebrew Behavior Tree

Even though Davide Faconti, one of the few robotics experts in the industry who I deeply admired, had developed and released the [BehaviorTree.CPP](https://www.behaviortree.dev/) open-sourced project, I still want to "reinvent the wheel" in order to fully understand how Behavior Tree really is, how does it work, and get down to the nitty-gritty that one may encounter when implementing this relatively new concept with real codes. Throughout this process, I trully enjoy designing and implementing the behavior tree based on what I've learned going through the book ["Behavior Trees in Robotics and AI: An Introduction" by Colledanchise M, Ögren P.](https://www.amazon.com/Behavior-Trees-Robotics-Introduction-Intelligence/dp/1138593737). I focus on simply sticking to the concepts stated in the book and using the most essential C++ syntax such that even my future self can understand. I hope this project helps you if you are also gathering resources to embark on the journey to understand a behavior tree and how to make it one of your most lethal battle vegetation / plants in your AI arsenal!

## Description

This project consists of the impleemntation of all types of nodes used to build up a behavior tree and the blackboard shared among all nodes. In addtion, I have attached an example code under the directory __examples__ to get a sensor of how to build a BT and make it run.
Currently this project is still under heavy development so if you are thinking to use the codes for any commercial purpose...Please let me know and use it at your own discretion.

## Getting started

### Dependencies

- Ubuntu 22.04 +
- C++ 20
- CMake FetchContent (I suppose you don't need to do anything to acquire it)

The CMake compiler will handle the rest, which is barely any dependency at all.

### Installing and Executing the program

Once you clone the project to your local end, under the project's root directory, build the project as such:

```bash
mkdir build
cd build
cmake .. # For the first time building the project
make
```
There will be a `bin/` directory created under the project root directory. **cd** into it, execute the binary `Burglar_bot` as follows,

```bash
./Burglar_bot
```

I will update how to use this project's library in your project soon.

### Generate documentation

In case Doxygen is not yet installed in your system, the CMake will handle this dependency on its own. And if you need to generate a Doxyfile to start with, you can use the following command under __documentation__:

```bash
doxygen -g
```
to generate Doxyfile. Once the Doxyfile is generate, assign the following parameters to the corresponding values

- PROJECT_NAME           = "Homebrew_behavior_tree"
- INPUT                  = {your/path/to/this/project/documentation/directory/}
- OUTPUT_DIRECTORY       = .
- RECURSIVE              = YES
- GENERATE_LATEX         = NO

Update the INPUT path to your's project documentaion directory. Save the new setup, and generate the documentation manually with the command:

```bash
doxygen Doxyfile
```

You should see a `html` directory appearing under the `documentation/` directory holding all the generated HTML files and their inventories.

## Help

Please let me know if you encounter any issue via GitHub's issues or email to [Charly Huang](mailto:charly.charlongo@gmail.com). And please do leave any advice I am more than happy to hear from you.

## Authors

- [Charly Huang](mailto:charly.charlongo@gmail.com)

