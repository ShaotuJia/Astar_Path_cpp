# Path_Astar_cpp
[![Build Status](https://travis-ci.org/ShaotuJia/Astar_Path_cpp.svg?branch=master)](https://travis-ci.org/ShaotuJia/Astar_Path_cpp)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/Find_Path_Astar/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/Find_Path_Astar?branch=master)
---

## Overview

This program is to find path in a grid map when given start, goal, and mapSize;

## Project Backlog

- Product Backlog and Iteration Backlog
```
https://docs.google.com/a/terpmail.umd.edu/spreadsheets/d/1_wuH_sjkEKzCIiHdhb8TNDC5xYZSNvnsnW_ek6CWaD0/edit?usp=sharing
```

## Run Program on Local Computer

- Checkout the repo (and submodules)
```
$ git clone --recursive https://github.com/ShaotuJia/Astar_Path_cpp.git
```
- Build this Program 
```
$ mkdir build
$ cmake ..
$ make ..
```
- Run Demo
```
$ cd build/app/
$ ./ Astar_Path-app
```
- Run test
```
$ cd build/test/
$ ./ cpp-test
```
- Run Doxygen
```
$ doxygen Doxyfile
$ cd docs
```
