# Path_Astar_cpp
[![Build Status](https://travis-ci.org/ShaotuJia/Astar_Path_cpp.svg?branch=master)](https://travis-ci.org/ShaotuJia/Astar_Path_cpp)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/Find_Path_Astar/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/Find_Path_Astar?branch=master)
---

## Overview

This program is to find path in a grid map when given start, goal, and mapSize;

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
