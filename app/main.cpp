//============================================================================
// Name        : main.cpp
// Author      : SHAOTU JIA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * This project is to use A star algorithm to find path
 * in a given map and without hit any obstacle
 */
#include "Path.hpp"
#include "Node.hpp"

int main() {

	Node start(0,0);
	Node goal(4,4);
	Map map(5,5);
	Path pathtogoal(start,goal,map);
	pathtogoal.Setdata();
	for (int i=0; i<pathtogoal.dataSet.size();i++) {

		cout<<"dataSet["<<i<<"].label: "<<pathtogoal.dataSet[i].label<<endl;
	}

	pathtogoal.findPath();

	return 0;
}
