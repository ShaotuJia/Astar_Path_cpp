/**
 * @author Shaotu Jia
 * @file Path.cpp
 * @brief This file to rum demo to check the functionality of each class and its fuctions
 * @copyright, Shaotu Jia, All rights reserved
 */

#include "Path.hpp"
#include "Node.hpp"

/**
 * This is the demo to check all classes and functions
 * Release one part and hide others as comments to check different circumstance
 */
int main() {


	/**
	 * Part 1: regular circumstance

	Node start(0,0); // Declare start Node and set coordinate (0,0)
	Node goal(3,4); // Declare goal Node and set coordinate (2,4)
	Map map(5,5); // Declare map and set up the map size 5 * 5
	Path pathtogoal(start,goal,map); //Declare class Path

	Node ob1 (1,4);
    pathtogoal.obstacles.push_back(ob1);
    pathtogoal.findPath(); //run findPath() function in Path class to find path for start(0,0) and goal(2,4)

    */

    /**
     * Part 2: If the user set obstacle same to goal
     *
    Node start(0,0); // Declare start Node and set coordinate (0,0)
	Node goal(3,4); // Declare goal Node and set coordinate (3,4)
	Map map(5,5); // Declare map and set up the map size 5 * 5
	Path pathtogoal(start,goal,map); //Declare class Path

	Node ob1 (3,4);
    pathtogoal.obstacles.push_back(ob1);
    pathtogoal.findPath(); //run findPath() function in Path class to find path for start(0,0) and goal(2,4)
	*/

    /**
     * Part 3: If the goal out of the map
     *
    Node start(0,0); // Declare start Node and set coordinate (0,0)
	Node goal(6,6); // Declare goal Node and set coordinate (6,6)
	Map map(5,5); // Declare map and set up the map size 5 * 5
	Path pathtogoal(start,goal,map); //Declare class Path

	Node ob1 (1,4);
    pathtogoal.obstacles.push_back(ob1);
    pathtogoal.findPath(); //run findPath() function in Path class to find path for start(0,0) and goal(2,4)
	*/

	return 0;
}
