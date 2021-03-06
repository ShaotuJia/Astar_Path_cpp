/**
 * @author Shaotu Jia
 * @file Path.cpp
 * @brief This file implement function that declared in "Path.hpp"
 * @copyright, Shaotu Jia, All rights reserved
 */
#include "Path.hpp"


void Path::setObstacle(vector <Node> obs) {

	if (obs.empty()) {
		cout << "No obstacles in this map" << endl;
	} else {
		for (auto x : obs) {

			// Node in obstacles cannot be start or goal node
			if ( x == start || x == goal) {
				cout << " !! the obstacle ("<< x.row <<","<< x.col <<")"<< " is start or goal !!\n";
				std::exit(EXIT_FAILURE);
			} else {

			x.label = x.row * map.colSize + x.col;
			closedSet.push_back(x.label);
			}
		}
	}

}


int Path::heuristic(Node current, Node goal) {
	return abs(current.col-goal.col) + abs(current.row-goal.row);
}

void Path::Setdata() {

	// initilize the label of start and goal
	start.label = start.row * map.colSize + start.col;
	goal.label = goal.row * map.colSize + goal.col;

	// Set up each Node information and push them into vector dataSet
	for (int j=0; j < map.rowSize; ++j) {

		for (int i=0; i < map.colSize; ++i) {

		  Node temp(j,i); //declare Node temp

		  //compute Node.label
		  temp.label = temp.row*map.colSize + temp.col;

		  // set neighborlabels empty
		  temp.neighborlabels = {};

		  //compute heuristic distance
		  temp.h = heuristic(temp, goal);

		  // find Node Neighbors
		  if (j != 0)
			  temp.neighborlabels.push_back(temp.label - map.rowSize);

		  if (j != map.rowSize-1)
		      temp.neighborlabels.push_back(temp.label + map.rowSize);

		  if (i != 0)
		  	  temp.neighborlabels.push_back(temp.label - 1);

		  if (i != map.colSize-1)
			  temp.neighborlabels.push_back(temp.label + 1);

		  //push temp Node to dataSet
		  dataSet.push_back(temp);

		}
	}

}

//find the member with minimum f value and set it to current
void Path::winner() {

	int winner = openSet[0];

				for (unsigned int i = 0; i < openSet.size(); i++) {

					if (dataSet[openSet[i]].f < dataSet[winner].f)
						winner = openSet[i];
				}

				current = winner;

}

void Path::reconstructPath(int current) {


		int temp = current;
		path.push_back(temp);


		//"previouslabel = -1" means no previous Node; it is start Node
		while (dataSet[temp].previouslabel != -1) {

			path.push_back(dataSet[temp].previouslabel);
			temp = dataSet[temp].previouslabel;
		}

		// reverse print out since the node label in path is from goal to start
		cout<<"path: \n"<<"start from:";
		for (vector<int>::reverse_iterator riter = path.rbegin(); riter != path.rend(); riter++) {
			int row = static_cast<int> ((*riter) / map.colSize);
			int col = (*riter) % map.colSize;
			cout<<"("<<row<<","<< col<<")"<<endl;
		}
		cout<<"to goal"<<endl;

}

void Path::remove(vector<int>& Set, int current) {
	vector<int>::iterator it;
	it = find(Set.begin(),Set.end(),current);
	if (it != Set.end())
	Set.erase(it);
}

void Path::updateopenSet() {

	vector<int> neighbors = dataSet[current].neighborlabels;

	for (unsigned int j=0; j< neighbors.size(); j++) {
		int neighbor = neighbors[j];

		vector<int>::iterator iterClose;
    	 iterClose = find(closedSet.begin(),closedSet.end(),neighbor);

		 if (iterClose == closedSet.end()) {

			 //assume moving cost between two adjacent node is 1
			 double tempG = dataSet[current].g+1;

			 vector<int>::iterator iterOpen;
			 iterOpen = find(openSet.begin(),openSet.end(),neighbor);

			 if (iterOpen != openSet.end()) {

				 if (tempG < dataSet[neighbor].g) {

					   dataSet[neighbor].g = tempG;
					 }
			 } else {

				 dataSet[neighbor].g = tempG;

				 openSet.push_back(neighbor);

			 }

			 dataSet[neighbor].f = dataSet[neighbor].g + dataSet[neighbor].h;

			 dataSet[neighbor].previouslabel = current;

		 }

	}

}


int Path::findPath() {

	Setdata();

	// set the previouslabel of start point as -1. It is the end condition of path reconstruction
	dataSet[start.label].previouslabel = -1;

    current = start.label; // set the current point is start point

	openSet = {current}; // add current point label into openSet;

	// Initialize g and f value for current point
	dataSet[current].g = 0;
	dataSet[current].f = dataSet[current].g + dataSet[current].h;

	// set obstacles in map
	setObstacle(obstacles);


	while (!openSet.empty()) {

	// find the node with lowest f value and update current
	winner();

	if (current==goal.label) {
		cout<<"reach the  goal!!"<<endl;
		reconstructPath(current);
		return 0;
	}


    if (openSet.size()>1)
	remove(openSet,current);
    else
    	openSet.clear();

    closedSet.push_back(current);

    updateopenSet();
  }

	cout<<"cannot find goal"<<endl;
	return 1;

}



