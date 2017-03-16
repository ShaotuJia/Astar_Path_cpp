/**
 * @author Shaotu Jia
 * @file Node.hpp
 * @brief This file is create class Path which is find the optimal path from start to goal
 * @copyright, Shaotu Jia, All rights reserved
 */
#ifndef INCLUDE_NODE_HPP_
#define INCLUDE_NODE_HPP_

#include<iostream>
#include <vector>

using std::vector;

/*
 * class Map
 * This class is to define the size of map
 */
class Map {
public:
	/*
	 * A public variable
	 * The number of row in map
	 */
	int rowSize; /**< The total number of row in map */

	/*
	 * A public variable
	 * The number of column in map
	 */
	int colSize; /**< The total number of col in map */

	/*
	 * class constructor
	 * Initialize class member rowSize and colSize
	 */
	Map(int rowSize, int colSize): rowSize(rowSize), colSize(colSize){}

};

/*
 * class Node
 * This class is to save all necessary information for each unit Node in map
 */
class Node {
public:

	/*
	 * A public variable
	 * row is the row number of Node in map
	 */
    int row; /**< row number of Node in map */

    /*
     * A public variable
     * col is the col number of Node in map
     */
    int col; /**< col number of Node in map */

    /*
     * A class constructor
     * Initialize class member row and col
     */
    Node(int x, int y):row(x),col(y) {}

    /*
     * A public variable
     * g is the moving cost from one Node to another
     * Initially set to 0
     */
	double g = 0; /**< moving cost from one Node to another */

	/*
	 * A public variable
	 * h is the heuristic distance; Manhattan distance between current Node to goal
	 */
	double h = 0; /**< heuristic distance; Manhattan distance between current Node to goal */

	/*
	 * A public varibale
	 * f = g + h; Initially set to 0
	 */
	double f = 0; /**< f = g + h */

	/*
	 * A public vector
	 * Save all labels of neighbor nodes
	 */
	vector<int> neighborlabels; /**< Save all labels of neighbor nodes */

	/*
	 * A public variable
	 * The label of parent Node; for later path reconstruction
	 */
	int previouslabel = 0; /**< The label of parent Node; for later path reconstruction */

	/*
	 * A public vector
	 * Save all neighbor Nodes
	 */
	vector<Node> neighbors; /**< Save all neighbor Nodes */

	/*
	 * A public vector
	 * Save all parent Node
	 */
	vector<Node> previous; /**< Save all parent Node */

	/*
	 * A public variable
	 * label is a integer that computed by row and col to ease the operation in openSet and closedSet
	 */
    int label = 0; /**< label is a integer that computed by row and col to ease the operation in openSet and closedSet */

	/*
	 * operator overload
	 * Comparison between two Nodes; if they have same row and col they are same Node
	 */
	friend bool operator == (Node a, Node b) throw() {

		if (a.row==b.row && a.col==b.col)
			return true;
		else
			return false;
	}

};


#endif  // INCLUDE_NODE_HPP_
