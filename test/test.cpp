#include <gtest/gtest.h>
#include <memory>
#include <algorithm>
#include "Path.hpp"
#include "Node.hpp"

Node start(0,0);
Node goal(4,4);
Map map(5,5);

std::shared_ptr<Path> pathToGoal = std::make_shared <Path> (start, goal, map);

TEST(NodeClass,map_grid) {
   
	 pathToGoal-> Setdata();
    
	 EXPECT_EQ(0,pathToGoal-> start.label);
	 EXPECT_EQ(24,pathToGoal-> goal.label);
	}

TEST (HeuristicTest, h_value) {
	
	Node current(2,2);
	EXPECT_EQ(8, pathToGoal-> heuristic(start, goal));
	EXPECT_EQ(4, pathToGoal-> heuristic(current,goal));

	}

TEST (finPathTest, reachGoal) {
	pathToGoal-> findPath();
	EXPECT_EQ(pathToGoal->goal.label, pathToGoal-> current);
	
	}

TEST (pathReconstruction, trackBack) {
	pathToGoal-> findPath();

	EXPECT_EQ(pathToGoal->goal.label, pathToGoal-> path[0]);

	int pathSize=pathToGoal->path.size();
	EXPECT_EQ(pathToGoal->start.label, pathToGoal-> path[pathSize-1]);
	
	}
