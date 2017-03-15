#include <gtest/gtest.h>
#include "Path.hpp"
#include "Node.hpp"


TEST(NodeClass,map_grid)
{
    Node start(0,0);
    Node goal(4,4);
    Map map(5,5);
    
   // Path pathToGoal(start,goal,map);
    
    pathToGoal.Setdata();
    
    EXPECT_EQ(0,start.label);
    EXPECT_EQ(24,goal.label);



}

/*
TEST(dummy, should_pass)
{
    EXPECT_EQ(1, 1);
}
*/
