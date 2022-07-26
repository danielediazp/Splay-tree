# Splay-Tree
CSC 212 Final Project


By Cameron Castillo, Carl Kakisis, Daniel Diaz, and Vincent Zhuang.

This repository houses all of the necessary files for our implementation of the Splay Tree data structure, including a visualization using SFML.

Compiling this project requires all .cpp and .h files, as well as several libraries from the SFML parent library.

Dependencies:

- SFML 2.5
- SFML/Graphics
- SFML/System
- SFML/Window
- Standard C++11

The easiest way to compile is to use the CMakeLists.txt file included in this repo. Steps for compiling are below:

1. Download all files inside of the Splay-tree/Progress directory
2. Create a new project using your IDE of choice. This project was built primarily using JetBrains CLion.
3. UPDATE YOUR CMAKELIST PROJECT TARGETS
  3a. Line 1: Update the cmake_minimum_required field to your version of CMake.
    - This project was built using both v3.22 and 3.21. It should not have a significant bearing on compilation.
  3b. Line 2: Update project(xxxxx) to project(YOUR-PROJECT-DIRECTORY-NAME)
  3c. Line 18: Update the first item in add_executable, xxxxx, to YOUR-PROJECT-DIRECTORY-NAME.
  3d. Line 102: Update the first item in target_link_libraries, xxxxx, to YOUR-PROJECT-DIRECTORY-NAME
4. Make sure that SFML is installed. The best way to install the library is using Homebrew, and executing "brew install sfml" through your terminal.
  4a. There are SFML files in the Splay-tree/Progress/External folder. BE AWARE THAT THESE FILES WILL NOT COMPILE. Our implementation utilizes the include path directory "/usr/local/include" on MacOS for linking.
  4b. Manual SFML download: https://www.sfml-dev.org/download.php
    - If you install SFML in any location aside from the include path, update the CMake list target directories
      -> Line 6

