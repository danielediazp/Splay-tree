# Splay-Tree
CSC 212 Final Project


By Cameron Castillo, Carl Kakisis, Daniel Diaz, and Vincent Zhuang.

![splay-tree](https://user-images.githubusercontent.com/38219103/181115192-408beb8a-cc8c-49b1-bce6-b0b101403ca9.png)

This repository houses all of the necessary files for our implementation of the Splay Tree data structure, including a visualization using SFML.

Compiling this project requires all .cpp and .h files, as well as several libraries from the SFML parent library.

Dependencies:

- SFML 2.5
- SFML/Graphics
- SFML/System
- SFML/Window
- Standard C++11

The easiest way to compile is to use the CMakeLists.txt file included in this repo. In these steps, YOUR-PROJECT-DIRECTORY-NAME should be replaced with the actual name of the project directory that will house the downloaded files. Steps for compiling are below:

1. Download all files inside of the Splay-tree/Progress directory
2. Create a new project using your IDE of choice. This project was built primarily using JetBrains CLion.
3. UPDATE YOUR CMAKELIST PROJECT TARGETS:
	- Line 1: Update the cmake_minimum_required field to your version of CMake.
    	- This project was built using both v3.22 and 3.21. It should not have a significant bearing on compilation.
	- Line 2: Update the parameter of project(YOUR-PROJECT-DIRECTORY-NAME) to the name of your project directory
	- Line 18: Update the first item in add_executable, YOUR-PROJECT-DIRECTORY-NAME to the name of your project directory
	- Line 102: Update the first item in target_link_libraries, YOUR-PROJECT-DIRECTORY-NAME to the name of your project directory
4. Because we have bundled the SFML library in this project, you should not need to manually install SFML. If you already have it installed and would not like to use the bundled files, you will need to update the directory paths throughout the CMakeList (Lines 8-13, 19-96). I would not suggest this route.

5. Ensure that you have also downloaded the font file for the visualization, "coolvetica.otf"
	- This file should be in your project directory, NOT the Splay-tree directory
    
An example of what your project directory should look like is below:

![Screen Shot 2022-07-26 at 6 48 50 PM](https://user-images.githubusercontent.com/38219103/181125365-cfbf4d9a-058c-4f4d-b2d4-93ec5a723763.png)

The purpose of utilizing a CMakeList for this project was to avoid needing to manually compile. The project should be run using an automatic compile-and-run button in your IDE that accepts a CMakeList.txt file for linking.
