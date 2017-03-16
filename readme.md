# Path_Astar_cpp
[![Build Status](https://travis-ci.org/ShaotuJia/Astar_Path_cpp.svg?branch=master)](https://travis-ci.org/ShaotuJia/Astar_Path_cpp)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/Find_Path_Astar/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/Find_Path_Astar?branch=master)
---

## Overview

This project is to design a component for robot motion planning. This component uses a given map and automatically find a path, which is able to reach the target point avoiding obstacles. This component will be implemented by programming language C++ with C++ 11 standard in Linux operation system. The compiler is GCC and the build system is CMake.

1. Algorithm Introduction:

	* A* search algorithm is the algorithm used to find a path. It is a very efficient algorithm to find a good path in 		static environment system. F value (good path) is computed by adding H value (heuristic value) and G value (move cost). 	In some cases, H value and G value are weighted before adding. Based on the minimal F value, a computer is able to find 	the good path for robots. During computation, the A* algorithm generates a Binary Search Tree (BST). The routine which 		can reach the target with minimal F value will be saved and others will be removed. This routine is the path that can 		drive the robot to target point.

2. Problem Simplification and Assumptions: 
	* For the convenience of computer programming the real world problem need to be simplified and some assumptions should 		  be made. More features can be added by removing simplification and assumptions in the future.  

    		1. Grid map is used in this project instead of a real map; Grid map separate map into a small unit block with 			   2-D coordinate. For example, (1,2) means the block in the second row and third column; row and column number 		   start from 0. 

    		2. Moving cost g-value from one block to adjacent block is 1.

    		3. The weight for heuristic distance is 1; F-value = g-value + weight * h-value; here weight = 1;

    		4. The robot can only go to its horizontal and vertical neighbor blocks; NO diagonal neighbor.

3. Instruction for users:

	* Component codes in include folder; a main.cpp in 'app' folder to check all functions; google test code in the 'test' 		  folder. 

    	* To run this program open app/main.cpp and set up start, goal, obstacles and map. Then, use the findPath function to 		  get a path. If the program can find the GOAL, every block coordinate that the robot passed will be output on the 		  screen. 

    	* In app/main.cpp there are several parts to check every circumstance. Each part is hidden as a comment. Users can 		  release one part to see the result in this circumstance. 

    	* To easily check every variable and function in classes. Temporally, all class members are public. That would be 		  changed later.      

## Project Backlog

- Product Backlog and Iteration Backlog; click [Backlog](https://docs.google.com/a/terpmail.umd.edu/spreadsheets/d/1_wuH_sjkEKzCIiHdhb8TNDC5xYZSNvnsnW_ek6CWaD0/edit?usp=sharing)

## UML Diagram

- Class Diagram: [here](https://www.lucidchart.com/invitations/accept/17cc5971-77db-40b6-a806-f4a2229acef4)
- Activity Diagram: [here](https://www.lucidchart.com/invitations/accept/bac51de0-591d-472c-8e74-b2e5685c2957)

## Run Program on Local Computer

* Checkout the repo (and submodules)
```
 git clone --recursive https://github.com/ShaotuJia/Astar_Path_cpp.git
```
* Build this Program 
```
 mkdir build
 cmake ..
 make ..
```
* Run Demo
```
 cd build/app/
 ./ Astar_Path-app
```
* Run test
```
 cd build/test/
 ./ cpp-test
```
* Genearate Doxygen Documentation

	*If you have not installed doxygen run following command before run Doxyfile
	```
	sudo apt-get install doxygen
	```
	*Run Doxyfile
	```
 	doxygen Doxyfile
 	cd docs
	```
