#pragma once
//goal class
#include <SFML\Graphics.hpp>
#include <random>
#include "Eater.h"

class Goal {

public:
	Goal(int screenwidth, int screenheight,int rectheight, int rectwidth, std::random_device& rd);
	sf::RectangleShape drawGoal();			//draws the goal spawn 
	bool ReachedGoal(eater &eat);				//checks if the goal is reached by the eater
	void respawn(eater& eat);							//generate new spawn for the goal


private:

	int screenwidth;			//screenwidth of game window
	int screenheight;			//screenwidth of height window
	int xpos;				//xpos for goal
	int ypos;				//ypos for goal
	int goalrectwidth;		//rectangle width for goal
	int goalrectheight;		//rectangle hight for goal
	bool reachedGoal = false;	//check if goal is reached
	sf::RectangleShape GoalRect;		//rectangleshape for goal
	std::mt19937 rng;		//rng
	std::uniform_int_distribution<int> GoalXPos;	//unit distribution for goal spawn
	std::uniform_int_distribution<int> GoalYPos;	//unit distributio for goal spawn
	


};
