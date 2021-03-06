#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Eater.h"


class balls {		//balls class
	

public:

	balls(int screenwidth, int screenheight, int circle_radius, std::random_device& rd);		//construct the balls radius
	

	void moveballs();	//move the balls (game logic)
	sf::CircleShape drawballs();		//fucntion to draw/rnder the ball
	bool Collided(eater &eat);				//checsk for collision


private:
	
	std::mt19937 rng;				//rng function
	std::uniform_real_distribution<float> xDist;	//rng function
	std::uniform_real_distribution<float> yDist;	//rng function
	std::uniform_real_distribution<float> yVel;	//rng function
	std::uniform_real_distribution<float> xVel;	//rng function
	
	
	
	int xpos;									//xposition of ball
	int ypos;									//y position of ball
	int yvel;									//y velocity of ball
	int xvel;									//x velocity of ball
	int ball_radius;							//ball radius
	sf::CircleShape drawcircle;					//draw circles
	int screenwidth, screenheight;				//screewidth adn screenheight parameters
	bool Collide = false;
};