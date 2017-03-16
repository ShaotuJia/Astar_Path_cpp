/**
 * @author Shaotu Jia
 * @file Path.cpp
 * @brief This file to rum demo to check the functionality of each class and its fuctions
 * @copyright, Shaotu Jia, All rights reserved
 */

#include "Path.hpp"
#include "Node.hpp"

/*
 * This is the demo to check all classes and functions
 */
int main() {

    /*
     * Declare start Node and set coordinate (0,0);
     */
	Node start(0,0); /**< Declare start Node and set coordinate (0,0) */

	/*
	 * Declare goal Node and set coordinate (2,4)
	 */
	Node goal(2,4); /**< Declare goal Node and set coordinate (2,4) */

	/*
	 * Declare map and set up the map size 5 * 5
	 */
	Map map(5,5); /**< Declare map and set up the map size 5 * 5 */

	/*
	 * Declare class Path
	 */
	Path pathtogoal(start,goal,map); /**< Declare class Path */

	/*
	 * input obstacles
	 */
	Node ob1 (1,4);
    pathtogoal.obstacles.push_back(ob1);

   // pathtogoal.setObstacle(pathtogoal.obstacles);

	/*
	 * run Setdata() function in Path class
	 */
	//pathtogoal.Setdata(); /**< Setdata() function in Path class*/

	/*
	 * run findPath() function in Path class to find path for start(0,0) and goal(2,4)
	 */
	pathtogoal.findPath(); /**< run findPath() function in Path class to find path for start(0,0) and goal(2,4) */

	return 0;
}
