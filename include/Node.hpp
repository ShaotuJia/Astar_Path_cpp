/*
 * Node.hpp
 *
 *  Created on: Mar 12, 2017
 *      Author: viki
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include<iostream>
#include <vector>
using namespace std;

class Map{
public:
	int rowSize;
	int colSize;

	Map(int rowSize, int colSize): rowSize(rowSize), colSize(colSize){}

};



class Node
{
public:

    int row;
    int col;
    Node(int x, int y):row(x),col(y){}
	double g=0;
	double h=0;
	double f=0;
	vector<int> neighborlabels;
	int previouslabel=0;
	vector<Node> neighbors;
	vector<Node> previous;
    int label=0; //initialize label with 0
	//overload operator == for node comparison
	friend bool operator == (Node a, Node b) throw(){

		if (a.row==b.row && a.col==b.col)
			return true;
		else return false;
	}



};





#endif /* NODE_HPP_ */
