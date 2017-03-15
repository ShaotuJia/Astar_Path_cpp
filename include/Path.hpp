//============================================================================
// Name        : Path.hpp
// Author      : SHAOTU JIA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#ifndef INCLUDE_PATH_HPP_
#define INCLUDE_PATH_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Node.hpp"

using std::cout;
using std::endl;

class Path{
public:

	Node start; // start point
	Node goal;  // goal point
	int current = -1; // current point
	Map map; // Initialize the map
	vector <Node> dataSet; // grid map to blocks and save all blocks information into dataSet
    vector<int> openSet;
    vector<int> closedSet;

    Path(Node start, Node goal, Map map):start(start),goal(goal),map(map) {}
    vector<int> path; // path from start to goal
	int heuristic(Node current, Node goal);
	void remove(vector<int>& Set, int current);
	void Setdata(); // grid dataSet according to the map size
	void winner(); // this function is to find node with lowest f value in openSet
	void reconstructPath(int); // this function to track back the path once reaching goal point
	void updateopenSet(); // add neighbors which exist in openSet to openSet
	int findPath();

};


#endif  // INCLUDE_PATH_HPP_
