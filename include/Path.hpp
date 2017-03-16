/**
 * @author Shaotu Jia
 * @file Path.hpp
 * @brief This file is create class Path which is find the optimal path from start to goal
 * @copyright, Shaotu Jia, All rights reserved
 */
#ifndef INCLUDE_PATH_HPP_
#define INCLUDE_PATH_HPP_

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include "Node.hpp"

using std::cout;
using std::endl;

/**
 * class Path is dependent to class Node and class Map;
 * It is to find the path from start to goal with minimum f value (f = g + h)
 */

class Path{
public:
	/**
	 * A public variable;
	 * The Node where the robot starts
	 */
	Node start; /**< start point */

	/**
	 * A public variable;
	 * The goal where the robot targets to
	 */
	Node goal;  /**< goal point */

	/**
	 * A public variable;
	 * Initialize label of current node as -1
	 */
	int current = -1; /**< Initialize label of current node as -1 */

	/**
	 * A public declaration;
	 * Declare class Map and it will be used inside class Path computation
	 */
	Map map; /**< Initialize map */

	/**
	 * A public vector;
	 * The vector contain all Nodes in the map
	 */
	vector <Node> dataSet; /**< grid map to blocks and save all blocks information into dataSet */

	/**
	 * A public vector;
	 * This contain all Nodes set as obstacles
	 */
	vector <Node> obstacles; /**< get obstacles */

	/**
	 * A public vector;
	 * The vector contain all Node's labels which have not checked
	 */
	vector<int> openSet; /**< Initialize openSet */

	/**
	 * A public vector;
	 * The vector contain all Node's labels which have checked
	 */
	vector<int> closedSet; /**< Initialize closedSet */

	/**
	 * A public vector;
	 * This vector contain the path that robot goes through from start to goal
	 */
	vector<int> path; /**< path from start to goal */

    /**
     * A constructor;
     * Initialize class Path with start, goal node and map
     */
    Path(Node start, Node goal, Map map):start(start),goal(goal),map(map) {}


    /**
     * obstacle function is to set obstacles on map
     * @param obs This the vector contains obstacles
     * @see closedSet
     */
    void setObstacle(vector<Node> obs);


    /**
     * @brief heuristic function taking two arguments and return integer
     * @param current the Node robot currently in
     * @param goal the goal robot targets to
     * @return the  Manhattan distance between two Nodes
     */
    int heuristic(Node current, Node goal);

    /**
     * @brief remove function taking two arguments, one pass by reference, one pass by value
     * @param Set This is the vector set wants to delete an element
     * @param current This the label of current Node
     */
	void remove(vector<int>& Set, int current);

	/**
	 * @brief Setdata() function is to grid map and save information of each Node to dataSet
	 */
	void Setdata(); // grid dataSet according to the map size

	/**
	 * @brief winner() function is to find the Node with minimum F-value in openSet
	 */
	void winner(); // this function is to find node with lowest f value in openSet

	/**
	 * reconstructionPath function taking one integer argument;
	 * This function is to track back path that robot goes through and output the path
	 * @param c This is the node label that robot currently in
	 */
	void reconstructPath(int c); // this function to track back the path once reaching goal point

	/**
	 * updateopenSet function;
	 * This function is to add current's neighbors to openSet which have not occurred in openSet and closeSet
	 */
	void updateopenSet(); // add neighbors which exist in openSet to openSet

	/**
	 * findPath function;
	 * This function is to find the optimal path from start to goal
	 * @see heuristic()
	 * @see remove()
	 * @see Setdata()
	 * @see winner()
	 * @see reconstructPath()
	 * @see updateopenSet()
	 *
	 */
	int findPath();

};


#endif  // INCLUDE_PATH_HPP_
